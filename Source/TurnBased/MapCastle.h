// Temp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGoable.h"
#include "MapCastle.generated.h"

UCLASS()
class TURNBASED_API AMapCastle : public AMapGoable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapCastle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
