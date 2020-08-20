// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "SimplePawn.generated.h"

UCLASS()
class MEMOSIMPLEPAWN_API ASimplePawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(Category=Mesh, VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent *MeepleComponent;

	UPROPERTY(Category=Mesh, VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMesh *MeepleMesh;

	UPROPERTY(Category=Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	class USpringArmComponent* SpringArm;

	UPROPERTY(Category=Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	class UCameraComponent* Camera;

	UPROPERTY()
	class USimplePawnMovementComponent* SimplePawnMovementComponent;

	// Sets default values for this pawn's properties
	ASimplePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
};
