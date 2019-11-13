// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	class ATank* GetControlledTank() const;
	void AimAtCrosshair();

	/** Used for line trace */
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& CrosshairDirection) const;
	bool CrosshairLineTraceHitLocation(FVector CrosshairDirection, FVector& HitLocation) const;
	/**/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair")
	float CrosshairLocationX = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair")
	float CrosshairLocationY = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crosshair")
	float LineTraceRange = 100000;

private:
	FVector HitLocation;
};
