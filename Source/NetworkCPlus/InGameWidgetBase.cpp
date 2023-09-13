// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidgetBase.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "LobbyController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();


	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));

	InputBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("InputBox")));
	if (InputBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("InputBox init"));

		InputBox->OnTextChanged.AddDynamic(this, &UInGameWidgetBase::OnChangedText);
		InputBox->OnTextCommitted.AddDynamic(this, &UInGameWidgetBase::OnCommitedText);
	}

	StartGameButton = Cast<UButton>(GetWidgetFromName(TEXT("StartGame")));
	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UInGameWidgetBase::StartGame);
	}

	ChatScroll = Cast<UScrollBox>(GetWidgetFromName(TEXT("ChatScroll")));
}

void UInGameWidgetBase::OnChangedText(const FText& Text)
{
}

void UInGameWidgetBase::OnCommitedText(const FText& Text, ETextCommit::Type CommitMethod)
{
	UE_LOG(LogTemp, Warning, TEXT("Send Message"));

	switch (CommitMethod)
	{
		case ETextCommit::OnEnter:
		{
			//메세지 만들어서 서버로 전송
			ALobbyController* PC = Cast<ALobbyController>(GetOwningPlayer());
			if (PC)
			{
				UMyGameInstance* GI = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
				if (GI)
				{
					FString Temp = FString::Printf(TEXT("%s : %s"), *GI->Username, *Text.ToString());
					//Client -> Server로 전송
					PC->C2S_SendMessage(FText::FromString(Temp));
				}
			}
		}

	}
}

void UInGameWidgetBase::StartGame()
{
	//다함께 맵 이동
	GetWorld()->ServerTravel(TEXT("InGame"));
}
