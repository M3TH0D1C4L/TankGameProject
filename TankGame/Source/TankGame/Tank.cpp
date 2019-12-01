// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "AimingComponent.h"
#include "Components/StaticMeshComponent.h"

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
	AimingComponent->SetTurretReference(TurretToSet);
}