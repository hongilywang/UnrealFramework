// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDTypes.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDTypes : public UObject
{
	GENERATED_BODY()
	
};

//����Զ���Debug�����
#pragma region LogDebug

class DATADRIVEN_API DDRecord
{
private:
	//������
	static TSharedPtr<DDRecord> RecordInst;

public:

	//���캯��

};

#pragma endregion
