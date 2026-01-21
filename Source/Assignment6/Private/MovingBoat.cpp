#include "MovingBoat.h"

AMovingBoat::AMovingBoat()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 100.f;
	MaxRange = 1000.f;
    RotationSpeed = 100.f;

	SetActorLocation(FVector(0.f));	
}

void AMovingBoat::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirection = -GetActorForwardVector();
}

void AMovingBoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	SetActorLocation(NewLocation);

	float Distance = FVector::Dist(StartLocation, NewLocation);

	if (Distance >= MaxRange)
	{
		NewLocation = StartLocation + MoveDirection * MaxRange;

		MoveDirection *= -1.f;

		StartLocation = NewLocation;
	}

	float Rotation = RotationSpeed * DeltaTime;

	FRotator ActorRotation(0.f, Rotation, 0.f);

	AddActorLocalRotation(ActorRotation);
}

