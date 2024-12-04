// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoadTile.generated.h"

UCLASS()
class PROJETVR_TEAM8_API ARoadTile : public APawn
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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma endregion
	
private:
	void ApplyMovementInputToPawn(float DeltaTime);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 10;
};
