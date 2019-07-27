// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
using std::string;
#include "CelestialBody.generated.h"


UCLASS()
class CPLUSPLUS_MAKEACTOR_API ACelestialBody : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame

	virtual void Tick(float DeltaTime) override;

	//CONSTRUCTOR
	ACelestialBody();

	void MakeSun(FName);

	//TIME
	UPROPERTY(EditAnywhere)
		float SpeedBaseLine;

	//DEBUG
	FString MakeFString(string);
	void Debug();
	void Debug(FString);
	string S_Message;
	FString FS_Message;

	//NAMES
	string CelestialName;
	FString FS_CelestialName;
	string PathColorMap;

	//MATERIALS & TEXTURES
	void SetMaterialInstance();
	void ChangeTexture(FName, FString);
	UMaterialInstanceDynamic* MyMaterialInstanceDynamic;
	UPROPERTY(EditAnywhere)
		UMaterialInterface* ParentMaterial;
	FString Path_ColorMap;
	FVector Color;

	//TRANSLATION
	float GetSpeed(float);
	FVector Origin;
	FVector Location;
	FVector RelativeXYZ;
	FVector ParentXYZ;
	FVector MeshXYZ;
	UPROPERTY(EditAnywhere)
		float Speed;

	//ORBIT
	void RotateAroundParent();
	float RotationsPerOrbit;

	//ROTATION
	void RotateAroundAxis(float);
	float AxisRotationDirection;

	FRotator CurrentAxisRotation;
	FRotator NewAxisRotation;

	//SCALE
	float Diameter;
	UPROPERTY(EditAnywhere)
		float Radius;

	//ORBIT
	float OrbitInDays;
	UPROPERTY(EditAnywhere)
		float Width;
	UPROPERTY(EditAnywhere)
		float Height;

	//RELATIONS
	UPROPERTY()
		USceneComponent* MySceneComponent;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MySMComponent;
	UPROPERTY(EditAnywhere)
		AActor* Parent;




};
