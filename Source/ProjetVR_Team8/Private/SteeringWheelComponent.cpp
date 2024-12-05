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

	UpdateWheelValues(DeltaTime);
}

void USteeringWheelComponent::GrabWheel(USceneComponent* Controller, USceneComponent* Hand)
{
	if(!MotionControllerComponents.Contains(Controller))
		MotionControllerComponents.Add(Controller);

	if(!HandsComponents.Contains(Hand))
		HandsComponents.Add(Hand);
  
	Hand->AttachToComponent(SteeringWheelMesh, FAttachmentTransformRules::KeepWorldTransform);
	//Controller->setow
	//SteeringWheelMesh
	//add to parent
}

void USteeringWheelComponent::UngrabWheel(USceneComponent* Controller, USceneComponent* Hand)
{
	if(MotionControllerComponents.Contains(Controller))
		MotionControllerComponents.Remove(Controller);

	if(HandsComponents.Contains(Hand))
		HandsComponents.Remove(Hand);
		
	Hand->AttachToComponent(Controller, FAttachmentTransformRules::KeepRelativeTransform);
	//remove parent
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

void USteeringWheelComponent::UpdateWheelValues(float DeltaTime)
{
	if(MotionControllerComponents.Num() == 0)
		return;

	FVector LeadControllerPosition =  MotionControllerComponents[0]->GetComponentLocation();
	SteeringWheelMesh->SetWorldRotation(FRotator(90, SteeringWheelMesh->GetComponentTransform().GetRotation().Y + 1, 0));
	for (auto hand : HandsComponents)
	{
		//hand->SetWorldLocation(LeadControllerPosition);
		// GEngine->AddOnScreenDebugMessage(
		// 	-1,
		// 	3.f,
		// 	FColor::Magenta,
		// 	FString::Printf(TEXT("Hand Grab State %s"), *hand->GetAttachParent()->GetName())
		// );
	}
	
	/// OVERRIDE DIRECT LE MOUVEMENT ??
	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Magenta,
	// 	FString::Printf(TEXT("Hand Grab State %d"), CurrentHandState)
	// );
	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Magenta,
	// 	FString::Printf(TEXT("Hand Grab State %f"), LeadControllerPosition.X)
	// );
}

