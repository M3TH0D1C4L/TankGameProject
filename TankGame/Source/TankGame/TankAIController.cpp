// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* AITank = Cast<ATank>(GetPawn());
	ATank* TankPlayer = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (TankPlayer)
	{
		AITank->AimAt(TankPlayer->GetActorLocation());

		AITank->Fire();
	}
}

void ATankAIController::AimAtPlayer()
{
	/* if (GetTankPlayer())
	{
		FString PlayerName = GetTankPlayer()->GetName();
		FVector PlayerLocation = GetTankPlayer()->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("AI found Player %s, aiming at %s."), *PlayerName, *PlayerLocation.ToString());
	}*/
}