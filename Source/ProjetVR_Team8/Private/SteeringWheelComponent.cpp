#include "SteeringWheelComponent.h"
#include "HandGrabState.h"
#include "MotionControllerInfo.h"
#include "EventManager/GameManager.h"


USteeringWheelComponent::USteeringWheelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USteeringWheelComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USteeringWheelComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USteeringWheelComponent::Grab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Grab(Controller, Hand);

	StartLookAt =  FindAverageLookAt();

	StartTargetRotation =  TargetObject->GetComponentRotation();
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Magenta,
		FString::Printf(TEXT("Grab Wheel"))
	);
}

void USteeringWheelComponent::Ungrab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Ungrab(Controller, Hand);
}

void USteeringWheelComponent::UpdateHandGrabState()
{
	UGameManager* gm = GetWorld()->GetSubsystem<UGameManager>();
	if(gm == nullptr)
		return;
	
	if(IsGrabbedLeft && IsGrabbedRight)
		gm->CurrentHandState = EHandGrabState::TWO_HANDS;
	else if(IsGrabbedLeft || IsGrabbedRight)
		gm->CurrentHandState = EHandGrabState::ONE_HAND;
	else
		gm->CurrentHandState = EHandGrabState::NO_HAND;
}

void USteeringWheelComponent::UpdateObject(float DeltaTime)
{
	Super::UpdateObject(DeltaTime);

	if(MotionControllerComponents.Num() == 0)
		return;
	
	FVector LookAt = FindAverageLookAt();
 
	float InPitch = FMath::Clamp(StartTargetRotation.Pitch - (LookAt.X - StartLookAt.X) * TurnSensibility, -89, 89);

	DriveInputXValue = -(InPitch/89);
	TargetObject->SetWorldRotation(FRotator(InPitch, StartTargetRotation.Yaw, StartTargetRotation.Roll));
}

FVector USteeringWheelComponent::FindLookAt(USceneComponent* controller)
{
	FVector LeadControllerPosition =  controller->GetComponentLocation();

	return (TargetObject->GetOwner()->GetTransform().InverseTransformPosition(LeadControllerPosition) * FVector(1, 0, 1)) -
					(LeadControllerPosition * FVector(1, 0, 1));
}

FVector USteeringWheelComponent::FindAverageLookAt()
{
	FVector LookAt;
	for (auto controller : MotionControllerComponents)
	{
		LookAt +=  FindLookAt(controller);
	}
	LookAt /= MotionControllerComponents.Num();
	return LookAt;
}
