#include "BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

ABaseCharacter::ABaseCharacter() : ID(0) {}

const void ABaseCharacter::SetId(int32 NewId)
{
    UE_LOG(LogTemp, Display, TEXT("Set new ID in %s from %i to %i"), *UKismetSystemLibrary::GetDisplayName(this), ID, NewId);
    ID = NewId;
}
