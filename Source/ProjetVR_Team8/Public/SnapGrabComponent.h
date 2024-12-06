// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SnapGrabComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJETVR_TEAM8_API USnapGrabComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USnapGrabComponent();
	UPROPERTY(BlueprintReadWrite)
	USceneComponent* TargetObject;
protected:
	TArray<USceneComponent*> MotionControllerComponents;
	TArray<USceneComponent*> HandsComponents;
	virtual void BeginPlay() override;
	void virtual UpdateObject(float DeltaTime);

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	virtual void Grab(USceneComponent* Controller, USceneComponent* Hand);
	UFUNCTION(BlueprintCallable)
	virtual void Ungrab(USceneComponent* Controller, USceneComponent* Hand);
	
};
