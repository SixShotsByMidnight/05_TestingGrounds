// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "GrassComponent.h"


UGrassComponent::UGrassComponent()
{

}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnGrass(NumberToSpawn);
}

void UGrassComponent::SpawnGrass(int SpawnCount)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	for (int i = 0; i < SpawnCount; i++)
	{
		FTransform InstanceTransform = FTransform::Identity;
		InstanceTransform.SetLocation(FMath::RandPointInBox(Bounds));
		this->AddInstance(InstanceTransform);
	}
}