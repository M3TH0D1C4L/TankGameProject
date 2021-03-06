// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere, Category = "Aim")
	float LaunchSpeed = 4000.f;
	
	float ReloadTime = 3.f;
	double LastFired = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	class UAimingComponent* AimingComponent = nullptr;
	class UTankBarrel* TankBarrel = nullptr;
	class UTankTurret* TankTurret = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<class AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTankParts(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Aim")
	void Fire();
};
