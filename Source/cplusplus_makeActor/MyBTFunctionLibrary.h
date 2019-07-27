// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Engine/World.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
#include "CoreMinimal.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "MyBTFunctionLibrary.generated.h"

UCLASS()
class CPLUSPLUS_MAKEACTOR_API UMyBTFunctionLibrary : public UBTFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Celestial Bodies")
			static void PrintFunction(FString somestring);

		UFUNCTION(BlueprintCallable, Category = "Celestial Bodies")
			static void SpawnCelestial(AActor* creator);

		UFUNCTION(BlueprintCallable, Category = "Celestial Bodies")
			static void MakeSolarSystem(AActor* creator);

		UFUNCTION(BlueprintCallable, Category = "Celestial Bodies")
			static void InitPlanet(ACelestialBody* Planet, ACelestialBody* Parent, TArray<float> Stats, FString FS_Name, FString FS_ColorMap);

		UPROPERTY(EditAnywhere)
			TSubclassOf<class ACelestialBody> ClassToSpawn;
};
