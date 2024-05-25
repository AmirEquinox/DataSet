 
#include "ArchVizFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Engine/World.h"


void UArchVizFunctionLibrary::TransitionToLevel(const FString& LevelName)
{
    if (UWorld* World = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World())
    {
        if ( LevelName.IsEmpty() )
        {
            UE_LOG(LogTemp, Error, TEXT("TransitionToLevel: Level name is not specified."));
            return;
        }

        UGameplayStatics::OpenLevel(World, FName(*LevelName));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("TransitionToLevel: Unable to get valid game world."));
    }
}
 

void UArchVizFunctionLibrary::PlayAudio(USoundBase* Sound, UAudioComponent* AudioComponent)
{
    if (!AudioComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("AudioComponent is null!"));
        return;
    }

    if (Sound)
    {
        AudioComponent->SetSound(Sound);
        AudioComponent->Play();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Sound is null!"));
    }
}

void UArchVizFunctionLibrary::StopAllAudio(UAudioComponent* AudioComponent)
{
    if (AudioComponent)
    {
        AudioComponent->Stop();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AudioComponent is null!"));
    }
}

/*
void UArchVizFunctionLibrary::StopAllAudio(UAudioComponent* AudioComponent)
{
    ensure(AudioComponent != nullptr);

    AudioComponent->Stop();
}

 */

//////////////////////////

/*
void UArchVizFunctionLibrary::StartTypewriterEffect(UTextBlock* TextBlock, const FString& Text, float TypeSpeed, USoundBase* TypeSound)
{
    if (!TextBlock) return;

    TextBlock->SetText(FText::GetEmpty());
    if (Text.IsEmpty()) return;

    TextBlock->GetWorld()->GetTimerManager().ClearAllTimersForObject(TextBlock);

    // Use a lambda to call the TypewriterCallback
    FTimerDelegate TimerCallback;
    TimerCallback.BindLambda([=]()
    {
        TypewriterCallback(TextBlock, Text, 0, TypeSpeed, TypeSound);
    });

    TextBlock->GetWorld()->GetTimerManager().SetTimerForNextTick(TimerCallback);
}

void UArchVizFunctionLibrary::ChangeTextContent(UTextBlock* TextBlock, const FString& NewText, float TypeSpeed, USoundBase* TypeSound)
{
    StartTypewriterEffect(TextBlock, NewText, TypeSpeed, TypeSound);
}

void UArchVizFunctionLibrary::TypewriterCallback(UTextBlock* TextBlock, const FString& Text, int32 Index, float TypeSpeed, USoundBase* TypeSound)
{
    if (Index >= Text.Len())
    {
        TextBlock->GetWorld()->GetTimerManager().ClearAllTimersForObject(TextBlock);
        return;
    }

    FString CurrentText = TextBlock->GetText().ToString();
    CurrentText.AppendChar(Text[Index]);
    TextBlock->SetText(FText::FromString(CurrentText));

    if (TypeSound)
    {
        UGameplayStatics::PlaySound2D(TextBlock->GetWorld(), TypeSound);
    }

    FTimerDelegate TimerCallback;
    TimerCallback.BindLambda([=]()
    {
        TypewriterCallback(TextBlock, Text, Index + 1, TypeSpeed, TypeSound);
    });

    // Make sure to pass the timer handle, delegate, time, and loop boolean
    FTimerHandle TimerHandle;
    TextBlock->GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerCallback, TypeSpeed, false);
}

*/


//          Function which work and erase previous code. but flickering effect.
/*
void UArchVizFunctionLibrary::StartTypewriterEffect(UTextBlock* TextBlock, const FString& Text, float TypeSpeed, USoundBase* TypeSound)
{
    if (!TextBlock || Text.IsEmpty()) return;

    // Clear any existing timers for this TextBlock
    TextBlock->GetWorld()->GetTimerManager().ClearAllTimersForObject(TextBlock);

    // Start with an empty text block
    TextBlock->SetText(FText::GetEmpty());

    // Start the typewriter effect
    TypewriterCallback(TextBlock, Text, 0, TypeSpeed, TypeSound);
}

void UArchVizFunctionLibrary::TypewriterCallback(UTextBlock* TextBlock, const FString& Text, int32 Index, float TypeSpeed, USoundBase* TypeSound)
{
    // Check if the index is out of bounds
    if (Index >= Text.Len())
    {
        // Stop the typing effect when the end of the text is reached
        TextBlock->GetWorld()->GetTimerManager().ClearAllTimersForObject(TextBlock);
        return;
    }

    // Set the text to the current index of the provided text
    FString CurrentText = Text.Mid(0, Index + 1);
    TextBlock->SetText(FText::FromString(CurrentText));

    // Play typing sound if available
    if (TypeSound)
    {
        UGameplayStatics::PlaySound2D(TextBlock->GetWorld(), TypeSound);
    }

    // Set a timer for the next character
    FTimerHandle TimerHandle;
    TextBlock->GetWorld()->GetTimerManager().SetTimer(TimerHandle, [=]() {
        TypewriterCallback(TextBlock, Text, Index + 1, TypeSpeed, TypeSound);
    }, TypeSpeed, false);
}

*/


/* // Working but not level transition from blueprint during ftimer setting for text

// Define a struct to hold typewriter effect state for each text block
struct FTypewriterState
{
    bool bIsTyping; // Whether a typewriter effect is currently in progress
    FString Text;   // The text being typed
    float TypeSpeed;
    USoundBase* TypeSound;

    FTypewriterState() : bIsTyping(false), TypeSpeed(0.05f), TypeSound(nullptr) {}
};

// Define a map to store typewriter effect states for each text block
static TMap<UTextBlock*, FTypewriterState> TypewriterStates;

void UArchVizFunctionLibrary::StartTypewriterEffect(UTextBlock* TextBlock, const FString& Text, float TypeSpeed, USoundBase* TypeSound)
{
    if (!TextBlock || Text.IsEmpty() || TypewriterStates.Contains(TextBlock) && TypewriterStates[TextBlock].bIsTyping)
        return;

    // Store the typewriter effect state for this text block
    FTypewriterState TypewriterState;
    TypewriterState.bIsTyping = true;
    TypewriterState.Text = Text;
    TypewriterState.TypeSpeed = TypeSpeed;
    TypewriterState.TypeSound = TypeSound;
    TypewriterStates.Add(TextBlock, TypewriterState);

    // Start with an empty text block
    TextBlock->SetText(FText::GetEmpty());

    // Start the typewriter effect
    TypewriterCallback(TextBlock, Text, 0, TypeSpeed, TypeSound);
}

void UArchVizFunctionLibrary::TypewriterCallback(UTextBlock* TextBlock, const FString& Text, int32 Index, float TypeSpeed, USoundBase* TypeSound)
{
    // Check if the text block is registered and if a typewriter effect is in progress
    if (TypewriterStates.Contains(TextBlock) && TypewriterStates[TextBlock].bIsTyping)
    {
        // Check if the index is out of bounds
        if (Index >= Text.Len())
        {
            // Stop the typing effect when the end of the text is reached
            TypewriterStates[TextBlock].bIsTyping = false;
            return;
        }

        // Set the text to the current index of the provided text
        FString CurrentText = Text.Mid(0, Index + 1);
        TextBlock->SetText(FText::FromString(CurrentText));

        // Play typing sound if available
        if (TypeSound)
        {
            UGameplayStatics::PlaySound2D(TextBlock->GetWorld(), TypeSound);
        }

        // Set a timer for the next character
        FTimerHandle TimerHandle;
        TextBlock->GetWorld()->GetTimerManager().SetTimer(TimerHandle, [TextBlock, Text, Index, TypeSpeed, TypeSound]() {
            TypewriterCallback(TextBlock, Text, Index + 1, TypeSpeed, TypeSound);
        }, TypeSpeed, false);
    }
}

*/


//
struct FTypewriterState
{
    bool bIsTyping;
    FString Text;
    float TypeSpeed;
    USoundBase* TypeSound;

    FTypewriterState() : bIsTyping(false), TypeSpeed(0.05f), TypeSound(nullptr) {}
};
//
static TMap<UTextBlock*, FTypewriterState> TypewriterStates;

void UArchVizFunctionLibrary::StartTypewriterEffect(UTextBlock* TextBlock, const FString& Text, float TypeSpeed, USoundBase* TypeSound)
{
    if (!TextBlock || Text.IsEmpty())
        return;

    if (TypewriterStates.Contains(TextBlock) && TypewriterStates[TextBlock].bIsTyping)
        return;

    FTypewriterState TypewriterState;
    TypewriterState.bIsTyping = true;
    TypewriterState.Text = Text;
    TypewriterState.TypeSpeed = TypeSpeed;
    TypewriterState.TypeSound = TypeSound;
    TypewriterStates.Add(TextBlock, TypewriterState);

    TextBlock->SetText(FText::GetEmpty());

    TypewriterCallback(TextBlock, Text, 0, TypeSpeed, TypeSound);
}

void UArchVizFunctionLibrary::TypewriterCallback(UTextBlock* TextBlock, const FString& Text, int32 Index, float TypeSpeed, USoundBase* TypeSound)
{
    if (TypewriterStates.Contains(TextBlock) && TypewriterStates[TextBlock].bIsTyping)
    {
        if (Index >= Text.Len())
        {
            TypewriterStates[TextBlock].bIsTyping = false;
            return;
        }

        FString CurrentText = Text.Mid(0, Index + 1);
        TextBlock->SetText(FText::FromString(CurrentText));

        if (TypeSound)
        {
            UGameplayStatics::PlaySound2D(TextBlock->GetWorld(), TypeSound);
        }

        FTimerHandle TimerHandle;
        UWorld* World = TextBlock->GetWorld();
        if (World)
        {
            World->GetTimerManager().SetTimer(TimerHandle, [TextBlock, Text, Index, TypeSpeed, TypeSound]() {
                TypewriterCallback(TextBlock, Text, Index + 1, TypeSpeed, TypeSound);
            }, TypeSpeed, false);
        }
    }
}

void UArchVizFunctionLibrary::TransitionToLevelHandledNullRef(FName LevelName, bool bAbsolute)
{
    // Clear all typewriter timers and associated text block references
    ClearAllTypewriterTimers();

    UWorld* World = UGameplayStatics::GetPlayerController(nullptr, 0)->GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("UArchVizFunctionLibrary::TransitionToLevelHandledNullRef - Invalid World"));
        return;
    }

    FString LevelNameString = LevelName.ToString();
    UGameplayStatics::OpenLevel(World, *LevelNameString, bAbsolute);
}

void UArchVizFunctionLibrary::ClearAllTypewriterTimers()
{
    for (auto& Pair : TypewriterStates)
    {
        UTextBlock* TextBlock = Pair.Key;
        if (TextBlock && TextBlock->IsValidLowLevel())
        {
            UWorld* World = TextBlock->GetWorld();
            if (World)
            {
                World->GetTimerManager().ClearAllTimersForObject(TextBlock);
            }
        }
    }

    // Clear the map
    TypewriterStates.Empty();
}

