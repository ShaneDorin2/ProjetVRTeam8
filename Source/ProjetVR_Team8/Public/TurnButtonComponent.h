// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnapGrabComponent.h"
#include "TurnButtonComponent.generated.h"
struct FMotionControllerInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnTurn, bool, IsOn);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJETVR_TEAM8_API UTurnButtonComponent : public USnapGrabComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTurnButtonComponent();
	UPROPERTY(BlueprintReadWrite)
	bool IsOn;

	UPROPERTY(BlueprintAssignable, Category="Clickable")
	FOnTurn OnTurn;

protected: 
	virtual void BeginPlay() override;
	virtual void UpdateObject(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite)
	bool CanBeUsed; 
	UPROPERTY()
	FRotator StartTargetRotation;	
	UPROPERTY()
	FRotator StartControllerRotation;
	UPROPERTY()
	bool CanTurn; //temp
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Grab(USceneComponent* Controller, USceneComponent* Hand) override;
	virtual void Ungrab(USceneComponent* Controller, USceneComponent* Hand) override;
};
