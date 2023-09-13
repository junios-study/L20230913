// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyController.h"
#include "InGameWidgetBase.h"

void ALobbyController::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());

    if (PC)
    {
        PC->SetInputMode(FInputModeGameAndUI());
        PC->bShowMouseCursor = true;
    }
}

bool ALobbyController::C2S_SendMessage_Validate(FText const& Message)
{
    //메세지 검증
    return true;
}

void ALobbyController::C2S_SendMessage_Implementation(FText const& Message)
{
    UE_LOG(LogTemp, Warning, TEXT("server : %s"), *Message.ToString());
    //Find All PC
    for (auto Iter = GetWorld()->GetPlayerControllerIterator(); Iter; ++Iter)
    {
        ALobbyController* PC = Cast<ALobbyController>(*Iter);
        if (PC)
        {
            PC->S2C_SendMessage(Message);
        }
    }

}

void ALobbyController::S2C_SendMessage_Implementation(FText const& Message)
{
    //UI 메세지 추가
    UInGameWidgetBase* Widget = Cast<UInGameWidgetBase>(InGameWidget);
    if (Widget)
    {
        Widget->AddMessage(Message);
    }
}
