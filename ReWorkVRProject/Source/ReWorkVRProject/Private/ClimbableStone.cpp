// ClimbableStone.cpp
#include "ClimbableStone.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

AClimbableStone::AClimbableStone()
{
    PrimaryActorTick.bCanEverTick = true;

    RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    RootComponent = RootScene;

}

void AClimbableStone::BeginPlay()
{
    Super::BeginPlay();

    if (ClimbMesh)
    {
        ClimbMesh->OnComponentBeginOverlap.AddDynamic(this, &AClimbableStone::OnClimbMeshOverlap);
    }
}

void AClimbableStone::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AClimbableStone::DisableClimbable()
{
    bCanBeGrabbed = false;
    bHasBeenUsed = true;

    SetActorEnableCollision(false);
}



void AClimbableStone::OnClimbMeshOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherComp) return;

    if (OtherComp->ComponentHasTag("GrabLeft") || OtherComp->ComponentHasTag("GrabRight"))
    {
        DisableClimbable();
    }
}
