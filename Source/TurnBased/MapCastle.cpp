// Temp


#include "MapCastle.h"
#include "Components/BoxComponent.h"

// Sets default values
AMapCastle::AMapCastle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;  
 
}

// Called when the game starts or when spawned
void AMapCastle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapCastle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapCastle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}	