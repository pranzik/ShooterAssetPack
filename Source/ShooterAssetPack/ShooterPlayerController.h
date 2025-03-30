// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false)override;

protected:
	 virtual void BeginPlay() override;

private:
	UPROPERTY();
	UUserWidget* HUD;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDScreenClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WinScreenClass;


	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LossScreenClass;

	UPROPERTY(EditAnywhere)
	float RestartDelay = 5 ;

	FTimerHandle RestartTimer;
};
