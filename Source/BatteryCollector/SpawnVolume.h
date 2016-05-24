// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** returns the whereToSpawn sub-object */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return whereToSpawn; };

	/** FInd a random point within the*/
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

protected:
	/** The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickUp> whatToSpawn;

	FTimerHandle spawnTimer;
	/** Minimun spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float spawnDelayRangeLow;
	/** Maximun spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float spawnDelayRangeHigh;


private:
	/** Box component to specify where pickups should be spawned */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* whereToSpawn;
	
	/** Handle spawning a new pickup */
	void SpawnPickup();

	/** The current spawn delay */
	float spawnDelay;
};
