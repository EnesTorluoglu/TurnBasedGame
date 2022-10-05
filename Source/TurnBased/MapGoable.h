// Temp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGoable.generated.h"

UCLASS()
class TURNBASED_API AMapGoable : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPriivateAccess = "true"))
	class USceneComponent* RootSceneComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPriivateAccess = "true"))
	class UBoxComponent* TriggerBox = nullptr;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Sets default values for this actor's properties
	AMapGoable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
