
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseNPC.generated.h"



class UBehaviorTree;



UCLASS()
class SKYWAY_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseNPC(const FObjectInitializer& ObjInit);
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset; 
};