// Temp


#include "MapGoable.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MapGroups.h"

// Sets default values
AMapGoable::AMapGoable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates the root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene Component"));
	SetRootComponent(RootSceneComponent);

	// Creates the box component
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(RootSceneComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AMapGoable::OnOverlapBegin);
	TriggerBox->OnBeginCursorOver.AddDynamic(this, &AMapGoable::BeginCursorOver);
	TriggerBox->OnEndCursorOver.AddDynamic(this, &AMapGoable::EndCursorOver);

	// Creates the mesh component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	Mesh->SetupAttachment(RootSceneComponent);

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

	AMapGroups* mapGroup = Cast<AMapGroups>(OtherActor);

	if (mapGroup != nullptr)
	{
		if (mapGroup->GetIsGoingToGoable() && mapGroup->GetNameOfGoable() == this->goableName)
		{
			groupBeginOverlap(mapGroup);
		}

	}

}

void AMapGoable::BeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	Mesh->SetRenderCustomDepth(true);
}

void AMapGoable::EndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	Mesh->SetRenderCustomDepth(false);
}