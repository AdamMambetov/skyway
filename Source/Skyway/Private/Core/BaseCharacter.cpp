#include "BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"

ABaseCharacter::ABaseCharacter() : ID(0) {}

const void ABaseCharacter::SetId(int32 NewId)
{
    UE_LOG(LogTemp, Display, TEXT("Set new ID in %s from %i to %i"), *UKismetSystemLibrary::GetDisplayName(this), ID, NewId);
    ID = NewId;
}

const void ABaseCharacter::SetCharacterState(ECharacterState NewCharacterState)
{
    CharacterState = NewCharacterState;
}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ABaseCharacter, CharacterState);
}
