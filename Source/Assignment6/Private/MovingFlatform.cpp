#include "MovingFlatform.h"

AMovingFlatform::AMovingFlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	MoveSpeed = 50.f;
	MaxRange = 5000.f;
	RotationSpeed = 70.f;
	SetActorLocation(FVector(0.f, 0.f, 0.f));
}

void AMovingFlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MoveDirection = GetActorForwardVector();
}

void AMovingFlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	SetActorLocation(NewLocation);
	
	float Distance = FVector::Dist(StartLocation, NewLocation);

	if (Distance >= MaxRange)
	{
		NewLocation = StartLocation + MoveDirection * MaxRange; // 정확한 위치 조정

		MoveDirection *= -1.f; // 마이너스로 반대로 방향으로 힘을 줌

		StartLocation = NewLocation; // 정확한 기준점 조정
	}

	float Rotation = RotationSpeed * DeltaTime;

	FRotator ActorRotation(0.f, Rotation, 0.f);

	AddActorLocalRotation(ActorRotation);
}

