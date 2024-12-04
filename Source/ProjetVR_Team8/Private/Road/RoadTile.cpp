﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Road/RoadTile.h"

#include "MaterialHLSLTree.h"
#include "GameFramework/PawnMovementComponent.h"


// Sets default values
ARoadTile::ARoadTile()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoadTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoadTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AddMovementInput(FVector(1, 0, 0), 10);
	ApplyMovementInputToPawn(DeltaTime);
}

// Called to bind functionality to input
void ARoadTile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARoadTile::ApplyMovementInputToPawn(float DeltaTime)
{
	FVector AddToLocation = this->GetLastMovementInputVector() * MovementSpeed * DeltaTime;

	FVector NewLocation = AddToLocation;
	
	this->SetActorLocation(this->GetActorLocation() + NewLocation);
}

