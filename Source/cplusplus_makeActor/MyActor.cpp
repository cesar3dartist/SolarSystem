// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//MySceneComponent exists as part of the AMyActor class. 
	//We create it and
	MySceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("My Scene Component"));

	//AActor has by default a "RootComponent"
	// The component defines the transform of the actor in the world
	//RootComponent = MySceneComponent;

	//Attach the mesh component to the Scene component
	MySMComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	
	//Make the component movable
	MySMComponent->SetMobility(EComponentMobility::Movable);

	//We attach the mesh component to the scene component.
	//https://answers.unrealengine.com/questions/665668/c-attachtocomponent-syntax.html
	//This seems to be a better way to do it:
	//http://api.unrealengine.com/INT/API/Runtime/Engine/Components/USceneComponent/SetupAttachment/
	//MySMComponent->AttachToComponent(MySceneComponent, FAttachmentTransformRules::KeepWorldTransform);
	MySMComponent->SetupAttachment(MySceneComponent);
	//Load a defined mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	UStaticMesh* Asset = MeshAsset.Object;
	MySMComponent->SetStaticMesh(Asset);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	int myNumber = 999;

	//Create FString with the name of the object
	FString sText = FString::Printf(TEXT("Via FString Variable %s"), *this->GetName());

	//Pass FString to the output log
	UE_LOG(LogActor, Warning, TEXT("Hello from my actor %s"), *sText);

	//Pass on a string and int directly
	UE_LOG(LogActor, Warning, TEXT("Hello from my actor %s : %d"), *this->GetName(), myNumber);

	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Change the mesh location by 1
	currentRelativeLoc = MySMComponent->GetRelativeTransform().GetLocation();
	FVector meshLocation = currentRelativeLoc;
	meshLocation.X += 1;
	meshLocation.Y += 1;
	meshLocation.Z += 1;
	
	MySMComponent->SetRelativeLocation(meshLocation);

	//Print to console
	//UE_LOG(LogActor, Warning, TEXT("CurrentRelativeLoc: %s"), *currentRelativeLoc.ToString());

	//Print to screen
	if (GEngine)
		{
			//UE_LOG(LogActor, Warning, TEXT("CurrentRelativeLoc: %s"), *currentRelativeLoc.ToString());
			GEngine->AddOnScreenDebugMessage
				(
					-1,
					5.f,
					FColor::Red,
					FString::Printf(TEXT("CurrentRelativeLoc: %s"), *currentRelativeLoc.ToString())
				);
		}
}

void AMyActor::MoveActor()
{

}
