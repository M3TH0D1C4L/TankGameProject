// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank())
	{
		FString Name = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player %s found."), *Name);
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& RayHitLocation) const
{
	/** Reflects the crosshairs on screen pixel location */
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((ViewportSizeX * CrosshairLocationX), (ViewportSizeY * CrosshairLocationY));
	/**/

	/** Take the crosshair on screen pixel location and line trace through it from the camera */
	FVector CrosshairDirection;
	if (GetLookDirection(ScreenLocation, CrosshairDirection))
	{
		if (CrosshairLineTraceHitLocation(CrosshairDirection, RayHitLocation))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	/**/
}

// Converts the crosshair on screen pixel location to a direction vector in the 3D Viewport
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& CrosshairDirection) const
{
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, CrosshairDirection));
}

// Line trace from the camera through the crosshair on screen and return the location of the line trace hit
bool ATankPlayerController::CrosshairLineTraceHitLocation(FVector CrosshairDirection, FVector& RayHitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (CrosshairDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		RayHitLocation = HitResult.Location;
		return true;
	}
	else
	{ 
		RayHitLocation = FVector(0.f);
		return false;
	}
}