// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "CelestialBody.h"
#include "MyPlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPLUSPLUS_MAKEACTOR_API UMyPlatformGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()



	//void CreateCelestialBody();
	void BigBang();
};
