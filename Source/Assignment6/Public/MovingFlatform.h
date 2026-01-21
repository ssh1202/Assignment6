#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFlatform.generated.h"

UCLASS()
class ASSIGNMENT6_API AMovingFlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingFlatform();

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float RotationSpeed;

	FVector StartLocation;
	FVector MoveDirection;

	

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
