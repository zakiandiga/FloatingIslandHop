// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UStaticMesh;

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Platform Movement")
	bool bIsMoving = true;

	UPROPERTY(EditAnywhere, Category="Platform Rotation")
	bool bIsRotating = false;

private:
	//Movement properties
	UPROPERTY(EditAnywhere, Category="Platform Movement")
	float MovementSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category="Platform Movement")
	FVector PlatformVelocity = FVector(1,0,0);

	UPROPERTY(EditAnywhere, Category="Platform Movement")
	float MaxDistanceMove = 200;

	//Rotation properties
	UPROPERTY(EditAnywhere, Category="Platform Rotation")
	float RotationSpeed; //degree per sec

	UPROPERTY(EditAnywhere, Category="Platform Rotation")
	FRotator RotationAxis;

	FVector OriginLocation;
	FString PlatformName;

	float GetDistanceMoved() const;
	bool ReverseMovement() const;
	
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	
};