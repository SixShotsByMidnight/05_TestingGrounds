// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "ActorPool.h"


AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(TEXT("NavMeshBoundsVolumePool"));
}

void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume* NavMesh)
{
	UE_LOG(LogTemp, Warning, TEXT("NavMesh Name: %s"), *NavMesh->GetName())
}

void AInfiniteTerrainGameMode::PolulateBoundsVolumePool()
{
	TActorIterator<ANavMeshBoundsVolume> ActorIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (ActorIterator)
	{
		ANavMeshBoundsVolume* NavMeshVolume = *ActorIterator;
		AddToPool(NavMeshVolume);
		++ActorIterator;
	}
}

