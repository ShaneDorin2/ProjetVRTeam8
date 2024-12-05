#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteeringWheelComponent.generated.h"
enum class EHandGrabState : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJETVR_TEAM8_API USteeringWheelComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USteeringWheelComponent();
	
	UPROPERTY(EditAnywhere)
	float SteeringSpeed;
	UPROPERTY(BlueprintReadWrite)
	USceneComponent* SteeringWheelMesh;

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

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void GrabWheel(USceneComponent* Controller, USceneComponent* Hand);
	UFUNCTION(BlueprintCallable)
	void UngrabWheel(USceneComponent* Controller, USceneComponent* Hand);
	UFUNCTION(BlueprintCallable)
	void UpdateHandGrabState();
	
private:
	void UpdateWheelValues(float DeltaTime);
};
