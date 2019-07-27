// Fill out your copyright notice in the Description page of Project Settings.


#include "CelestialBody.h"
#include "Engine.h"
#include <string>
using std::string;

// Sets default values
ACelestialBody::ACelestialBody()
{
	SpeedBaseLine = 100.f;
	PrimaryActorTick.bCanEverTick = true;
	
	//Set Mesh
	MySceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = MySceneComponent;
	MySMComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MySMComponent->SetMobility(EComponentMobility::Movable);
	MySMComponent->SetupAttachment(MySceneComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Meshes/Sphere.Sphere"));
	UStaticMesh* Asset = MeshAsset.Object;
	MySMComponent->SetStaticMesh(Asset);
	Parent = this;
	
	//ADDING MATERIAL
	SetMaterialInstance();
}


void ACelestialBody::BeginPlay()
{
	Super::BeginPlay();
}


void ACelestialBody::ChangeTexture(FName fname, FString myFString)
{	
	UTexture2D* MyTexture = LoadObject<UTexture2D>(NULL, *myFString, NULL, LOAD_None, NULL);
	MyMaterialInstanceDynamic->SetTextureParameterValue(fname, MyTexture);
}

void ACelestialBody::MakeSun(FName fname)
{
	MyMaterialInstanceDynamic->SetScalarParameterValue(fname, 1);
}

float ACelestialBody::GetSpeed(float planetOrbitInDays)
{
	float planetSpeed = 0.0;
	planetSpeed = (planetOrbitInDays * ACelestialBody::SpeedBaseLine) / 365;
	return planetSpeed;
}


void ACelestialBody::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACelestialBody::RotateAroundParent();
	RotateAroundAxis(DeltaTime);
}

void ACelestialBody::RotateAroundParent()
{
	//Get Parent Location
	ParentXYZ = Parent->GetActorLocation();

	//Store Local Translation 
	RelativeXYZ = MySMComponent->GetRelativeTransform().GetLocation();
	MeshXYZ = RelativeXYZ;

	//Set XYZ
	MeshXYZ.X = (sin(GetWorld()->GetRealTimeSeconds() / Speed) * Width) + ParentXYZ.X;
	MeshXYZ.Y = (cos(GetWorld()->GetRealTimeSeconds() / Speed) * Height) + ParentXYZ.Y;
	MeshXYZ.Z = 0.f;

	//Assign New Location
	this->SetActorLocation(MeshXYZ);
}

void ACelestialBody::RotateAroundAxis(float DeltaTime)
{
	NewAxisRotation.Pitch = 0;
	NewAxisRotation.Roll = 0;
	this->NewAxisRotation.Yaw = (DeltaTime) * (10000/(this->RotationsPerOrbit)) * (this->AxisRotationDirection);
	this->AddActorLocalRotation(NewAxisRotation);
}





void ACelestialBody::SetMaterialInstance()
{
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialB(TEXT("/Game/Materials/CelestialBodyMaterial.CelestialBodyMaterial"));
		if (MaterialB.Succeeded())
		{
			MyMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(MaterialB.Object, MaterialB.Object);
			MySMComponent->SetMaterial(0, MyMaterialInstanceDynamic);
		}
}

FString ACelestialBody::MakeFString(string givenString)
{
	return givenString.c_str();
}

void ACelestialBody::Debug()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage
		(
			-1,
			50.f,
			FColor::Red,
			FString::Printf(TEXT("Debug: %s"), *FS_Message)
		);
	}
}

void ACelestialBody::Debug(FString givenFString)
{
	//Convert string to FString first
	FString tempFString = givenFString;
	if (GEngine)
	{
		//UE_LOG(LogActor, Warning, TEXT("CurrentRelativeLoc: %s"), *currentRelativeLoc.ToString());
		GEngine->AddOnScreenDebugMessage
		(
			-1,
			5.f,
			FColor::Red,
			FString::Printf(TEXT("Debug: %s"), *tempFString)
		);
	}
}

