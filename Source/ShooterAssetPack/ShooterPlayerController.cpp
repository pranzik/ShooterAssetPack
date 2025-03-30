// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if (HUD != nullptr)
	{
		HUD->RemoveFromViewport();
		HUD = nullptr; // Set to nullptr to avoid dangling pointer
	}
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LossScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("We have finished"));
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel,RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDScreenClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}
