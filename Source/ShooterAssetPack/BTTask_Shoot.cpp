// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
    if (Result == EBTNodeResult::Failed)
    {
        return EBTNodeResult::Failed;
    }

    // Check if the AI owner is valid
    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    // Cast the pawn to ShooterCharacter
    AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    // Execute the shoot behavior
    Character->Shoot();

    return EBTNodeResult::Succeeded;
}
