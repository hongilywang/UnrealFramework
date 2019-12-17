// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DGTypes.generated.h"

#pragma region GamePart

/*****************************************************************/
/* ��������Ϸ���ݷ�����			Begin			��������Ϸ���ݷ�����*/
/*****************************************************************/

//ģ��Լ�������Ҫʹ��DataDriven�����UI��ܣ���һ��Ҫ��HUDģ����ڵڶ�λ��UIFrame��ܹ�����ʼ����HUDģ����
UENUM()
enum class EGameModule : uint8
{
	Center = 0,		//����ģ��
	HUD,			//HUDԼ�����ڵڶ�λ��UI��ܻ�ֱ��ʹ�����1����ȡHUDģ�飬�����ʹ��UI��ܣ�����Ҫǿ���ڵڶ�λ
	Player,			//���ģ��
};

/*****************************************************************/
/* ��������Ϸ���ݷ�����			End				��������Ϸ���ݷ�����*/
/*****************************************************************/

#pragma endregion

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDGTypes : public UObject
{
	GENERATED_BODY()
	
};
