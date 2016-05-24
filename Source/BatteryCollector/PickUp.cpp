// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "PickUp.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// All pickups start active
	bIsActive = true;

	// Create the mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	// Collision primitive that defines the transform (location, rotation, scale) of this Actor.
	RootComponent = PickupMesh;

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Returns active state
bool APickUp::IsActive() const
{
	return bIsActive;
}

// Changes active state
void APickUp::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}


void APickUp::WasCollected_Implementation()
{
	// Log a debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}

