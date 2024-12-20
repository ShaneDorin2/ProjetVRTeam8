// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClickButton.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnClick );
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJETVR_TEAM8_API UClickButton : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UClickButton();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintAssignable, Category="Clickable")
	FOnClick OnClick;
	
	UFUNCTION(BlueprintCallable)
    void Click();
};
