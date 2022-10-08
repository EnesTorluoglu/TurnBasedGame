// Temp


#include "MapGoable.h"
#include "Components/BoxComponent.h"
#include "MapGroups.h"

// Sets default values
AMapGoable::AMapGoable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates the root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	// Creates the box component
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(RootSceneComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AMapGoable::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AMapGoable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapGoable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapGoable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("heleleyle"));
	
	AMapGroups* mapGroup = Cast<AMapGroups>(OtherActor);
	
	if (mapGroup != nullptr)
	{
		if (mapGroup->GetIsGoingToGoable() && mapGroup->GetNameOfGoable() == this->goableName)
		{
			UE_LOG(LogTemp, Warning, TEXT("ifififfif"));
			groupBeginOverlap(mapGroup);

		}

	}
	
}