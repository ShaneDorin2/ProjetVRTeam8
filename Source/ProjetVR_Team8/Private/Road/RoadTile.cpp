﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Road/RoadTile.h"

#include "AsyncDetailViewDiff.h"
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
	TSet<UActorComponent*> Components = this->GetComponents();
	for (UActorComponent* Component : Components)
	{
		if (Component->GetName() == "RoadsideObjectStaticMesh")
		{
			RoadsideSlot = Cast<UStaticMeshComponent>(Component);
		}
	}
}

// Called every frame
void ARoadTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoadTile::ApplyMovement(FVector direction, float Speed, float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += direction * Speed * DeltaTime;
	SetActorLocation(CurrentLocation);
}

void ARoadTile::SpawnSignToRoadsideSlot()
{
	if (RoadsideSlot == nullptr)
	{
		return;
	}
	RoadsideSlot->SetStaticMesh(SignMesh);
}

void ARoadTile::ClearRoadsideSlot()
{
	if (RoadsideSlot == nullptr)
	{
		return;
	}
	RoadsideSlot->SetStaticMesh(nullptr);
}

