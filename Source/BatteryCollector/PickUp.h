// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	/** Return the mesh for the Pickup */
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	/** Return whether or not pickup is active */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	bool IsActive() const;

	/** Allows other classes to safely change whether or not the pickup is active */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	/** Function to call when the pickup is collected */
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();
	// This way calling WasCollected() will call both functions
	// (being WasCollected possibly defined by blueprints and _Implementation defined in code
	// by every child class.

protected:
	/** True when the pickup can be used, and false when pickup is deactivated */
	bool bIsActive;

private:
	/** Static mesh to represent the pickUp in the level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* PickupMesh;
	
};
