#pragma once

#include "CoreMinimal.h"
#include "SnapGrabComponent.h"
#include "Components/ActorComponent.h"
#include "SteeringWheelComponent.generated.h"
enum class EHandGrabState : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJETVR_TEAM8_API USteeringWheelComponent : public USnapGrabComponent
{
	GENERATED_BODY()

public:
	USteeringWheelComponent();
	
	UPROPERTY(EditAnywhere)
	float SteeringSpeed;

	UPROPERTY(BlueprintReadWrite)
	bool IsGrabbedLeft;
	UPROPERTY(BlueprintReadWrite)
	bool IsGrabbedRight;

protected:
	UPROPERTY(BlueprintReadOnly)
	EHandGrabState CurrentHandState;
	TArray<USceneComponent*> MotionControllerComponents;
	TArray<USceneComponent*> HandsComponents;
	virtual void BeginPlay() override;
	virtual void UpdateObject(float DeltaTime) override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Grab(USceneComponent* Controller, USceneComponent* Hand) override;
	virtual void Ungrab(USceneComponent* Controller, USceneComponent* Hand) override;
	UFUNCTION(BlueprintCallable)
	void UpdateHandGrabState();

};