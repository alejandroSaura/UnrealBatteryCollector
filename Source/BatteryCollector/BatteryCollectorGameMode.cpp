// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// base decay rate
	decayRate = 0.07f;
}


void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EBatteryPlayState::EPlaying);

	// Set the scrore to beat
	ABatteryCollectorCharacter* myCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (myCharacter)
	{
		powerToWin = (myCharacter->GetInitialPower()) * 1.25f;
	}

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}

}


void ABatteryCollectorGameMode::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	// Check that we are using the battery collector character
	ABatteryCollectorCharacter* myCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (myCharacter)
	{
		// if our power is greater than needed to win, set the game's state to won
		if (myCharacter->GetCurrentPower() > powerToWin)
		{
			SetCurrentState(EBatteryPlayState::EWon);
		}
		// decrease character's power if its positive
		else if (myCharacter->GetCurrentPower() > 0)
		{
			myCharacter->UpdatePower(-deltaTime*decayRate*(myCharacter->GetInitialPower()));
		}
		else
		{
			SetCurrentState(EBatteryPlayState::EGameOver);
		}
	}
}

float ABatteryCollectorGameMode::GetPowerToWin() const
{
	return powerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrentState()
{
	return CurrentState;
}

void ABatteryCollectorGameMode::SetCurrentState(EBatteryPlayState NewState)
{
	CurrentState = NewState;
}