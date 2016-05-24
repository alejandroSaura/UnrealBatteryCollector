// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickUp.h"

// Set default values
ABatteryPickUp::ABatteryPickUp()
{
	GetMesh()->SetSimulatePhysics(true);

	// the base level of the battery
	batteryPower = 150.0f;

}

void ABatteryPickUp::WasCollected_Implementation()
{
	// Use the base pickup class behavior
	Super::WasCollected_Implementation();

	// Destroy the battery
	Destroy();
}

// report the power level of the battery
float ABatteryPickUp::GetPower()
{
	return batteryPower;
}