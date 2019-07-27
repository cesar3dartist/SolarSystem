// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CPLUSPLUS_MAKEACTOR_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void MoveActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* MySceneComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MySMComponent;
		
	FVector currentRelativeLoc;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
