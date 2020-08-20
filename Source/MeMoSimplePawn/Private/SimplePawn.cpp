// Fill out your copyright notice in the Description page of Project Settings.


#include "SimplePawn.h"

#include "SimplePawnMovementComponent.h"

// Sets default values
ASimplePawn::ASimplePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> MeepleMesh;
		FConstructorStatics()
            : MeepleMesh(TEXT("/MeMoSimplePawn/Meeple.Meeple")) {}
	};
	static FConstructorStatics ConstructorStatics;

	MeepleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Meeple"));
	MeepleComponent->SetStaticMesh(ConstructorStatics.MeepleMesh.Get());
	RootComponent = MeepleComponent;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);

	const FVector SpringArmLocation = FVector(-550.f,0.f,440.f);
	const FRotator SpringArmRotation = FRotator(-30, 0, 0);

	SpringArm->SetRelativeLocation(SpringArmLocation);
	SpringArm->SetRelativeRotation(SpringArmRotation);
	SpringArm->TargetArmLength = .0f;	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);	
	Camera->bUsePawnControlRotation = false;

	SimplePawnMovementComponent = CreateDefaultSubobject<USimplePawnMovementComponent>(TEXT("CustomMovementComponent"));
	SimplePawnMovementComponent->UpdatedComponent = RootComponent;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
}

// Called when the game starts or when spawned
void ASimplePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimplePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASimplePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASimplePawn::MoveForward);
}

void ASimplePawn::MoveForward(float AxisValue)
{
	if (SimplePawnMovementComponent && (SimplePawnMovementComponent->UpdatedComponent == RootComponent))
	{
		SimplePawnMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}	
}
