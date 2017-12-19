// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float Rotation;
	float RandomScale;
};

class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Spawning")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, 	int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MaxScale = 1.f, float MinScale = 1.f);
	UFUNCTION(BlueprintCallable, Category = "Spawning")
		void PlaceAIPawns(TSubclassOf<APawn> ToSpawn,	int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		FVector MinExtent;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		FVector MaxExtent;
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
		FVector NavigationBoundsOffset;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
		void SetPool(UActorPool* Pool);

private:
	AActor* NavMeshBoundsVolume;

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	template<class T>
	void RandomlyPlaceActors(TSubclassOf<T> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MaxScale = 1.f, float MinScale = 1.f);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition);

	void PlaceActor(TSubclassOf<APawn> ToSpawn, FSpawnPosition SpawnPosition);

	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;

	void PositionNavMeshBoundsVolume();

	TArray<FSpawnPosition> RandomSpawnPosition(int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MaxScale = 1.f, float MinScale = 1.f);
};