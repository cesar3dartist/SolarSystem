// Fill out your copyright notice in the Description page of Project Settings.


#include "TutActor.h"

// Sets default values
ATutActor::ATutActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ATutActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

