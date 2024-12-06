#include "SteeringWheelComponent.h"
#include "HandGrabState.h"


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
}

void USteeringWheelComponent::Ungrab(USceneComponent* Controller, USceneComponent* Hand)
{
	Super::Ungrab(Controller, Hand);
}

void USteeringWheelComponent::UpdateHandGrabState()
{
	if(IsGrabbedLeft && IsGrabbedRight)
		CurrentHandState = EHandGrabState::TWO_HANDS;
	else if(IsGrabbedLeft || IsGrabbedRight)
		CurrentHandState = EHandGrabState::ONE_HAND;
	else
		CurrentHandState = EHandGrabState::NO_HAND;
}

void USteeringWheelComponent::UpdateObject(float DeltaTime)
{
	Super::UpdateObject(DeltaTime);

	//FVector LeadControllerPosition =  MotionControllerComponents[0]->GetComponentLocation();
	//TargetObject->SetWorldRotation(FRotator(90, TargetObject->GetComponentTransform().GetRotation().Y + 1, 0));
	for (auto hand : HandsComponents)
	{
	}
	
}
