// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UAimingComponent>(TEXT("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	AimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetTankParts(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;

	AimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFired) > ReloadTime;

	if (bIsReloaded)
	{
		if (Barrel && bIsReloaded)
		{
			AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation("FiringPoint"), Barrel->GetSocketRotation("FiringPoint"));

			Projectile->LaunchProjectile(LaunchSpeed);

			LastFired = FPlatformTime::Seconds();
		}
	}
}