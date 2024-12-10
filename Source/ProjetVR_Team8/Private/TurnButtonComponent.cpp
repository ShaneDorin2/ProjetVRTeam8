// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnButtonComponent.h"

#include "MotionControllerInfo.h"
#include "DynamicMesh/DynamicMesh3.h"


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

	IsOn = false;
	
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
	if(MotionControllerComponents.Num() == 0)
		return;
	StartTargetRotation = TargetObject->GetComponentRotation();
	StartControllerRotation = MotionControllerComponents[0]->GetComponentRotation();
	CanTurn = true;
}

void UTurnButtonComponent::Ungrab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Ungrab(Controller, Hand);
}


void UTurnButtonComponent::UpdateObject(float DeltaTime)
{
	Super::UpdateObject(DeltaTime);
	
	if(!CanTurn)
		return;

	if(MotionControllerComponents.Num() == 0)
		return;

	FRotator ControllerRotation = MotionControllerComponents[0]->GetComponentRotation();

	FRotator CurrentTargetRotation = TargetObject->GetComponentRotation();

	float DeltaYaw = (ControllerRotation.Yaw - StartControllerRotation.Yaw) - (CurrentTargetRotation.Pitch - StartTargetRotation.Pitch);

	float InPitch = FMath::Clamp(StartTargetRotation.Pitch - DeltaYaw * TurnSensibility, -89, 0);

	TargetObject->SetWorldRotation(FRotator(InPitch, StartTargetRotation.Yaw, StartTargetRotation.Roll));


	if((!IsOn && InPitch <= -85) || (IsOn && InPitch >= -5))
	{
		CanTurn = false;
		IsOn = !IsOn;
		GEngine->AddOnScreenDebugMessage(
			-1,
			3.f,
			FColor::Magenta,
			FString::Printf(TEXT("Turn Button : %s"), IsOn? TEXT("ON") : TEXT("OFF"))
		);
	}
}

