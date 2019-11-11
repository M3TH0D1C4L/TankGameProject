// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank())
	{
		FString Name = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player %s found."), *Name);
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}