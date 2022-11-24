// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//Set original position
	OriginLocation = GetActorLocation();
	PlatformName = GetName();


}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsMoving)
	{
		MovePlatform(DeltaTime);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is NOT moving"), *PlatformName);
	}

	if(bIsRotating)
	{
		RotatePlatform(DeltaTime);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is NOT rotating"), *PlatformName);
	}

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{	
	if(ReverseMovement())
	{
		FVector MoveDirection;
		MoveDirection = PlatformVelocity.GetSafeNormal();
		OriginLocation += MoveDirection * MaxDistanceMove;
		SetActorLocation(OriginLocation); //make sure the actor start at new OriginLocation
		PlatformVelocity *= -1;
	}

	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += (PlatformVelocity * MovementSpeed) * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("%s is rotating"), *PlatformName);
	AddActorLocalRotation((RotationAxis * RotationSpeed) * DeltaTime);	
}

bool AMovingPlatform::ReverseMovement() const
{
	return GetDistanceMoved() >= MaxDistanceMove;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), OriginLocation);
}

