// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank())
	{
		FString Name = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI %s found."), *Name);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetTankPlayer())
	{
		GetControlledTank()->AimAt(GetTankPlayer()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetTankPlayer() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimAtPlayer()
{
	/*if (GetTankPlayer())
	{
		FString PlayerName = GetTankPlayer()->GetName();
		FVector PlayerLocation = GetTankPlayer()->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("AI found Player %s, aiming at %s."), *PlayerName, *PlayerLocation.ToString());
	}*/
}