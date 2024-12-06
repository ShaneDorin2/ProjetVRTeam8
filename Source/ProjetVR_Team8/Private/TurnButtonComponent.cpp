// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnButtonComponent.h"


// Sets default values for this component's properties
UTurnButtonComponent::UTurnButtonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTurnButtonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTurnButtonComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTurnButtonComponent::Grab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Grab(Controller, Hand);
}

void UTurnButtonComponent::Ungrab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Ungrab(Controller, Hand);
}


void UTurnButtonComponent::UpdateObject(float DeltaTime)
{
	Super::UpdateObject(DeltaTime);
}

