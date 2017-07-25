// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
class APatrollingGuard;

UCLASS()
class S05_TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointKey;

private:
	TArray<AActor*> GetPatrolPoints(APatrollingGuard* Guard);

	void SetNextWaypoint(int32 Index, TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackboardComp);

	void CycleIndex(int32 Index, TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackboardComp);

};
