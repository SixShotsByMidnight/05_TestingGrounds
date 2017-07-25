// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "PatrollingGuard.h" //TODO Remove dependency
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto ControlledPawn = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto 	Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	auto PatrolPoints = GetPatrolPoints(ControlledPawn);

	SetNextWaypoint(Index, PatrolPoints, BlackboardComp);

	CycleIndex(Index, PatrolPoints, BlackboardComp);

	return EBTNodeResult::Succeeded;
}

TArray<AActor*> UChooseNextWaypoint::GetPatrolPoints(APatrollingGuard* Guard)
{
	return Guard->PatrolPointsCPP;
}

void UChooseNextWaypoint::SetNextWaypoint(int32 Index, TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackboardComp)
{
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]); 
	//TODO Protect against empty waypoints
}

void UChooseNextWaypoint::CycleIndex(int32 Index, TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackboardComp)
{
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
}