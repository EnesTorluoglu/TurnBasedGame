// Temp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MapGoable.h"

#include "MapGroups.generated.h"

UCLASS()
class TURNBASED_API AMapGroups : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AMapGroups();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "MapGroups")
	bool isGoingToGoable = false;

	UPROPERTY(BlueprintReadWrite, Category = "MapGroups")
	AMapGoable* goableToGo = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "MapGroups")
	FName nameOfGoable;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool GetIsGoingToGoable() const { return isGoingToGoable; }

	AMapGoable* GetGoableToGo() const { return goableToGo; }

	FName GetNameOfGoable() const { return nameOfGoable; }
};
