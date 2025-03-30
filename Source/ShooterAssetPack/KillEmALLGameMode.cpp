// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmALLGameMode.h"
#include"EngineUtils.h"
#include"GameFramework/Controller.h"
#include "ShooterAIController.h"


void AKillEmALLGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled); 
	UE_LOG(LogTemp, Warning, TEXT("Pawn was killed "));

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController!= nullptr)
 	{
		//PlayerController->GameHasEnded(nullptr, false);
		EndGame(false);
	}
	for (AShooterAIController* Controller :TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	}
	EndGame(true);
}

void AKillEmALLGameMode::EndGame(bool bisPlayerWinner)
{
	for (AController* Controller:TActorRange<AController>(GetWorld()))
	{

		bool bisWinner = Controller->IsPlayerController() == bisPlayerWinner;

		Controller->GameHasEnded(Controller->GetPawn(), bisWinner);

	}
}
