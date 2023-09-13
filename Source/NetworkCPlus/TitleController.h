// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitleController.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKCPLUS_API ATitleController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> TitleWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* TitleWidget;
};
