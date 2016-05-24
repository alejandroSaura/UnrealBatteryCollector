// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BatteryPickUp.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickUp : public APickUp
{
	GENERATED_BODY()

protected:
	/** Set the amount of power the battery gives to the character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected))
	float batteryPower;
	
public:
	// Set default values for this actor's properties
	ABatteryPickUp();
	
	/** Override the WasCollected function - use Implementation because it's a Blueprint Native Event */
	void WasCollected_Implementation() override;

	/** Public way to access the battery power level */
	float GetPower();

};
