﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuadtreeMeshComponent.h"
#include "QuadtreeMeshActor.generated.h"






UCLASS()
class QUADTREEMESH_API AQuadtreeMeshActor : public AActor
{
	GENERATED_BODY()

public:
	
	AQuadtreeMeshActor();

	
	TObjectPtr<UQuadtreeMeshComponent> QuadtreeMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuadtreeMesh")
	TObjectPtr<UMaterialInterface> MeshMaterial;

private:
	bool bNeedInfoRebuild = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	virtual void OnConstruction(const FTransform& Transform) override;
	
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	void Update()const;

	void UpdateComponentVisibility();

	void MarkForRebuild(EQuadtreeMeshRebuildFlags Flags);

#if WITH_EDITOR
	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditUndo() override;
	virtual void PostEditImport() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};