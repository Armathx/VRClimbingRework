// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClimbableStone.generated.h"


UCLASS()
class REWORKVRPROJECT_API AClimbableStone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClimbableStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    // Root scene component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* RootScene;

    #pragma once

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* ClimbMesh = nullptr;

    // === Climb Control ===

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Climb")
    bool bCanBeGrabbed = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Climb")
    bool bHasBeenUsed = false;

    UFUNCTION(BlueprintCallable, Category = "Climb")
    void DisableClimbable();

    UFUNCTION()
    void OnClimbMeshOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );


};
