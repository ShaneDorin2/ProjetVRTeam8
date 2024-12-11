// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoadTile.generated.h"

UCLASS()
class PROJETVR_TEAM8_API ARoadTile : public AActor
{
	GENERATED_BODY()
	
#pragma region Unreal Default
	
public:
	// Sets default values for this pawn's properties
	ARoadTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


#pragma endregion
	
private:
	void ApplyMovement(FVector direction, float Speed, float DeltaTime);
	
	UStaticMeshComponent* RoadsideSlot;
	UStaticMeshComponent* ShadowSlot;
	UStaticMeshComponent* DeerSlot;
	
public:
	UFUNCTION()
	void SpawnSignToRoadsideSlot();

	//UFUNCTION()
	//void SpawnShadowToShadowSlot();

	//UFUNCTION()
	//void SpawnDeetToDeerSlot();

	UFUNCTION()
	void ClearAllRoadSlots();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* SignMesh;
};


