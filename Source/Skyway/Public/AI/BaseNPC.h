
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "BaseCharacter.h"
#include "BaseNPC.generated.h"


class UBehaviorTree;



UCLASS()
class SKYWAY_API ABaseNPC : public ABaseCharacter
{
	GENERATED_BODY()
	
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;
	ABaseNPC(const FObjectInitializer& ObjInit);

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
	FName TargetBone = "Head";
protected:
	FGenericTeamId TeamId;

	virtual bool CanBeSeenFrom(const FVector& ObserverLocation,FVector& OutSeenLocation,
								int32& NumberOfLoSChecksPerformed, float& OutSightStrength,
								const AActor* IgnoreActor = nullptr,
								const bool* bWasVisible = nullptr, int32* UserData = nullptr) const;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
	TArray<FName> ViewTargets;

	UFUNCTION(BlueprintCallable)
	void NextViewTarget();
	int32 Index = 0;

};