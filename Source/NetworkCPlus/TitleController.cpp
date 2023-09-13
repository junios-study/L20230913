// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleController.h"
#include "Blueprint/UserWidget.h"

void ATitleController::BeginPlay()
{
    Super::BeginPlay();

    TitleWidget = CreateWidget<UUserWidget>(GetWorld(), TitleWidgetClass);
    TitleWidget->AddToViewport();

    APlayerController* player0 = GetWorld()->GetFirstPlayerController();
    if (IsValid(player0))
    {
        player0->SetInputMode(FInputModeUIOnly());
        player0->bShowMouseCursor = true;
    }
}
