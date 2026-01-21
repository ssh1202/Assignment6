#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingBoat.generated.h"

UCLASS()
class ASSIGNMENT6_API AMovingBoat : public AActor
{
	GENERATED_BODY()
	
public:
	AMovingBoat();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SceneRoot")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Move")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Move")
	float RotationSpeed;

	FVector StartLocation;
	FVector MoveDirection;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
