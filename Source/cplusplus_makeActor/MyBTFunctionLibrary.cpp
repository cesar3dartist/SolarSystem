// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTFunctionLibrary.h"
#include "Engine/World.h"
#include "CelestialBody.h"


void UMyBTFunctionLibrary::PrintFunction(FString somestring)
{
	UE_LOG(LogTemp, Log, TEXT("You wanted to say %s"), *somestring);
}


void UMyBTFunctionLibrary::SpawnCelestial(AActor *creator)
{
	//Check that the class type to spawn is not null
			
			UWorld* world = creator->GetWorld();
			//Make sure that there is a world
			if (world)
				{
					FVector spawnLocation(0.f, 0.f, 0.f);
					FRotator spawnRotation(0.f, 0.f, 0.f);
					const FTransform SpawnLocAndRot;
					FActorSpawnParameters spawnParams;
					//world->SpawnActor<ACelestialBody>(ClassToSpawn, spawnLocation, spawnRotation);
					ACelestialBody* CB = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
					
					//Asign values
					CB->Speed = 1.f;
					CB->Width = 400.f;
					CB->Height = 400.f;
					CB->FinishSpawning(SpawnLocAndRot);
				}
		
}

void UMyBTFunctionLibrary::MakeSolarSystem(AActor* creator)
{

	UWorld* world = creator->GetWorld();
	//Make sure that there is a world
	if (world)
	{

		FVector spawnLocation(0.f, 0.f, 0.f);
		FRotator spawnRotation(0.f, 0.f, 0.f);
		const FTransform SpawnLocAndRot;
		FActorSpawnParameters spawnParams;

		ACelestialBody* Sun = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Mercury = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Venus = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Earth = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Moon = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Mars = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Jupiter = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Saturn = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Uranus = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Neptune = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);
		ACelestialBody* Pluto = world->SpawnActorDeferred<ACelestialBody>(ACelestialBody::StaticClass(), SpawnLocAndRot);

		//Scale multiplier to make planets a size that can fit within the editor.
		float ScaleMultiplier = 0.0001;
		float SunScaleAdjustment = 0.1;
		//This is the relative speed, most likely set to Earth so that we can see things moving and not static
		//float SpeedBaseLine = 100;
		string path = "";

		//SUN
		Sun->CelestialName = "Sun";
		Sun->Diameter = 1391000.0f;
		Sun->Parent = creator;
		Sun->Speed = 0.f;
		Sun->SetActorScale3D(FVector((Sun->Diameter) * ScaleMultiplier * SunScaleAdjustment));
		Sun->Width = 0.f;
		Sun->Height = 0.f;
		Sun->FinishSpawning(SpawnLocAndRot);
		Sun->SetActorLabel(Sun->CelestialName.c_str());
		Sun->MakeSun(FName("IsSun"));


		//Planet Name, Parent, {Diameter, Orbit In Days, Width, Height, RotationPerOrbit, AxisRotation}, Label Name, Color Map
		//MERCURY
		TArray<float> Mercury_stats{ 4879.0, 88.0f, 1000.f, 1000.f, 87.97f, -1.f};
		InitPlanet(Mercury, Sun, Mercury_stats, FString("Mercury"), FString("/Game/Textures/Mercury/color.color"));
		
		//VENUS
		TArray<float> Venus_stats{ 12104.f, 224.7f, 2000.f, 2000.f, 224.7f,1.f };
		InitPlanet(Venus, Sun, Venus_stats, FString("Venus"), FString("/Game/Textures/Venus/color.color"));

		//EARTH
		TArray<float> Earth_stats{ 12742.f, 365.f, 3000.f, 3000.f, 365.26f, -1.f };
		InitPlanet(Earth, Sun, Earth_stats, FString("Earth"), FString("/Game/Textures/Earth/color.color"));

		//MOON
		TArray<float> Moon_stats{ 3472.f, 27.322f, 300.f, 300.f, 365.26f, -1.f };
		InitPlanet(Moon, Earth, Moon_stats, FString("Moon"), FString("/Game/Textures/Moon/color.color"));

		//MARS
		TArray<float> Mars_stats{ 6792.f, 689.98f, 4000.f, 4000.f, 686.2f, -1.f };
		InitPlanet(Mars, Sun, Mars_stats, FString("Mars"), FString("/Game/Textures/Mars/color.color"));

		//JUPITER
		TArray<float> Jupiter_stats{ 142984.f, 4332.82f, 10000.f, 10000.f, 4328.9, -1.f };
		InitPlanet(Jupiter, Sun, Jupiter_stats, FString("Jupiter"), FString("/Game/Textures/Jupiter/color.color"));

		//SATURN
		TArray<float> Saturn_stats{ 120536.f, 10755.7f, 15000.f, 15000.f, 10752.9f, -1.f };
		InitPlanet(Saturn, Sun, Saturn_stats, FString("Saturn"), FString("/Game/Textures/Saturn/color.color"));

		//URANUS
		TArray<float> Uranus_stats{ 51118.f, 30687.15f, 17500.f, 17500.f, 30663.65f, 1.f };
		InitPlanet(Uranus, Sun, Uranus_stats, FString("Uranus"), FString("/Game/Textures/Uranus/color.color"));

		//NEPTUNE
		TArray<float> Neptune_stats{ 49528.f, 60190.03f, 20000.f, 20000.f, 60148.35f, -1.f };
		InitPlanet(Neptune,Sun, Neptune_stats, FString("Neptune"), FString("/Game/Textures/Neptune/color.color"));

	}

}

void UMyBTFunctionLibrary::InitPlanet(ACelestialBody* Planet, ACelestialBody* Parent, TArray<float> Stats, FString FS_Name, FString FS_ColorMap)
{
	const FTransform SpawnLocAndRot;
	float ScaleMultiplier = 0.0001;
	Planet->Path_ColorMap = FS_ColorMap;
	Planet->FS_CelestialName = FS_Name;
	Planet->Diameter = Stats[0];
	Planet->OrbitInDays = Stats[1];
	Planet->Parent = Parent;
	Planet->Speed = Planet->GetSpeed(Planet->OrbitInDays);
	Planet->SetActorScale3D(FVector((Planet->Diameter) * ScaleMultiplier));
	Planet->Width = Stats[2];
	Planet->Height = Stats[3];
	Planet->RotationsPerOrbit = Stats[4];
	Planet->AxisRotationDirection = Stats[5];
	Planet->FinishSpawning(SpawnLocAndRot);
	Planet->SetActorLabel(Planet->FS_CelestialName);
	Planet->ChangeTexture(FName("BaseColor"), Planet->Path_ColorMap);
}


