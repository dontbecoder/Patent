


#define TRUE   1
#define FALSE  0

bool Want_to_modify = TRUE;				// �������޸�
bool Want_to_advance_announce = TRUE;	// ��ǰ��������
bool Want_to_Second_Trail = TRUE;		// ��ʵ��
bool Want_to_Review_BasedOn_ChangedAtInternationalStage = TRUE;		// �Թ��ʽ׶������޸���Ϊ��������
bool Want_Priority = TRUE;				// Ҫ������Ȩ
bool Has_priority = TRUE;				// ������Ȩ

#define FAILED_WITHDRAW				0	// ����
#define FAILED_TERMIATION			0	// ��ֹ
#define FAILED_REJECT				0	// ����
#define FAILED_EFFECT_TERMINAT		0	// Ч����ֹ
#define FAILED_NOT_REQUIRED			0	// δҪ��

#define FAILED_WITHDRAW_FOR_PCT			0	// PCT����
#define FAILED_WITHDRAWED_FOR_PCT		0	// PCT����Ϊ����
#define FAILED_WITHDRAW_CHINA_FOR_PCT	0	// PCTָ���й������ص�


// All date 
#define Priority_date			// ����Ȩ��

#define Application_date		// ʵ�������� 	A28  A42

#define RECEIVED_A_NOTICE		// �յ�֪ͨ��֮��

#define DATE2APP_SECOND_TRAIL 	// ���ʵ��֮��

#define PCT_EnterNational_date	// PCT������ҽ׶�֮��(��������)

#define YEARS_3
#define YEARS_10
#define YEARS_20

#define MONTH_2
#define MONTH_3
#define MONTH_6
#define MONTH_12
#define MONTH_18
#define MONTH_30

#define DAYS_15


#define Novelty_Grace_period				MONTH_6			// ��ɥʧ��ӱ�ԵĿ�����
#define Priority_Grace_period_Design		MONTH_6			// ����������Ȩ���� 6������
#define Priority_Grace_period_Inovention	MONTH_12		// ʵ����������Ȩ���� 12������
#define Priority_Grace_period_Unity			MONTH_12		// ��������Ȩ���� 12������



// Fees
// �������ֿɼ���
#define FEES_APP			// �����
#define FEES_SECOND_TRAIL	// ʵ���
#define FEES_REVIEW		// �����
#define FEES_ANNUAL		// ���  (��Ȩ���������)


#define FEES_APP_PLUS		// ���븽�ӷ� (Ȩ��Ҫ�󳬹�10�˵���鳬��30ҳ)
#define FEES_ANNOUNCE_PRINT		// ����ӡˢ��
#define FEES_WANT_PRIORITY  // ����Ȩ�����
#define FEES_RECOVER_RIGHT	// �ָ�Ȩ�������
#define FEES_EXTEND_TIME	// �ӳ����������
#define FEES_REGISTER		// ר���ǼǷ�
#define FEES_WANT_INVALID	// ��Ч���������
#define FEES_PATENT_EVALUATION_REPORT	// ר��Ȩ���۱��������
#define FEES_RECORD_ITEM_CHANGE			// ��¼��������

// Patent

#define PATENT_DESIGH_LIMIT				(Application_date + YEARS_10)
#define PATENT_UNITY_LIMIT				(Application_date + YEARS_10)
#define PATENT_INOVENTION_LIMIT			(Application_date + YEARS_20)	


/*************************************/
typedef enum
{
	INIT,
	
    INOVENTION,

	UNITY,

	DESIGN,
    
} PATENT_APPLICATION_ENUM;

PATENT_APPLICATION_ENUM Obj_app = 0;




/***********************/
int Recover_right()  // �ָ�Ȩ������
{

}


int CheckPepole()
{

	return TRUE;
}

int CheckObj()
{
	return TRUE;

}

int CheckShiYongXing()
{

}

int CheckXinYingXing()
{

}

int CheckChuangZaoXing()
{

}

int Check3Attrib()
{
	if(CheckShiYongXing())
	{
		if(CheckXinYingXing())
		{
			if(CheckChuangZaoXing())
			{
				return TRUE;
			}
		}
	}
	
	return FALSE;
}
int CheckFees()
{
	if( 
		(Application_date + MONTH_2)
			||
			(RECEIVED_A_NOTICE + DAYS_15)
	)														// R95
		{
		
		FEES_APP + (FEES_APP_PLUS) + (FEES_WANT_PRIORITY) + FEES_ANNOUNCE_PRINT

		}

	if(Has_priority)
	{
		FEES_WANT_PRIORITY
	}
}

int CheckForm()
{}

int CheckLegal()
{}

int CheckObviousDefect()
{}
	
int Fisrt_trail() // ���� A3 A40
{

	if(Want_to_modify) 	// R51	�����޸�ʱ��
		{
			switch(Obj_app)
				{
				case DESIGN:
				case UNITY:				
					(Application_date + MONTH_2)
					break;
					
				case INOVENTION:
					(DATE2APP_SECOND_TRAIL) || (RECEIVED_A_NOTICE + MONTH_3)	
						
					break;
					
					default:
						break;
				}
		}


	if(FALSE==CheckFees())  // ����
	{
		return FALSE;
	}

	if(FALSE==CheckForm())	// �����ļ�����ʽ���
	{
		return FALSE;
	}

	if(FALSE==CheckLegal())  // �����ļ��ķ�������
	{
		return FALSE;
	}

	if(FALSE==CheckObviousDefect())		// ����ʵ����ȱ�� A5  A25
	{
		return FALSE;
	}
	
	return TRUE;
}

int Second_Trail() // ʵ��
{
	if(Want_to_Second_Trail)
	{
		if(Priority_date + YEARS_3)  //A35
		{
		
			if(Check3Attrib())	// ���Ե�
					{
						return TRUE;
					}

		}else{
			return FAILED_WITHDRAW;
		}
	}

	

	return FALSE;
}

int Authorization() // ��Ȩ����
{

}

int Announced()		// ���ҹ���  A34 
{


}


int PatentApplication(PATENT_APPLICATION_ENUM Obj_app)			// ��������
{

	if(FALSE == CheckPepole())   // ��������
	{
		return FALSE;
	}

	if(FALSE == CheckObj())		// ��������  A25
	{
		return FALSE;
	}

	switch(Obj_app)
	{
	case DESIGN:
		if(Fisrt_trail())		
		{
			Authorization()		
		}
		else
		{						// reject				
			return FALSE;
		}
			
		break;
		
	case UNITY:
		if(Fisrt_trail())		
			{
				Authorization()		
			}
			else
			{									
				return FALSE;
			}

		break;
		
	case INOVENTION:
		if(Fisrt_trail())		
			{
				if((Priority_date + MONTH_18)||(Want_to_advance_announce))
			 		Announced()												// ���ҹ���
			 
				if(Second_Trail())
					{
					
					Authorization()

					}
			}
			else
			{									
				return FALSE;
			}
		
		break;	

	default:
		break;
	}

	

	return TRUE;
}


/************************		PCT ����						**********************************/

int Check_written_statement()
{
	// ������ʾ� ����������� �������ר������
	// (�Ŵ���Դ��¶��)	R109 (if necessary)
	
	// written in Chinese
}
int CheckFees_For_PCT() // R93 && R103
{
	if(Want_Priority)
	{	
		if(PCT_EnterNational_date + MONTH_2)	// R110
		{
		FEES_WANT_PRIORITY
			}
		else
			return FAILED_NOT_REQUIRED;
	}
	
	
}
int CheckFiles_in_Chinese()
{
	// ˵���顢Ȩ��Ҫ�������������
}
int Give_prove_for_EnterNationalStage() // R104
{
	int date;
	
	date = PCT_EnterNational_date;	// ������ҽ����� �� ���������
}

int CheckOther4Condition_For_PCT() // R104 PCT ������ҽ׶�ʱ����4������Ҫ��
{
}
int CorrectFlow_For_PCT()
{

}

int Enter_National_Stage() // ������ҽ׶�
{
	if(FALSE == Check_written_statement())
		return FAILED_EFFECT_TERMINAT;

	if(FALSE == CheckFees_For_PCT())
		return FAILED_EFFECT_TERMINAT;

	if(FALSE == CheckFiles_in_Chinese())
		return FAILED_EFFECT_TERMINAT;

	Give_prove_for_EnterNationalStage();	

	if(TRUE == CheckOther4Condition_For_PCT())
		return TRUE;
	else
		{
		if(TRUE == CorrectFlow_For_PCT())
		  return TRUE;
		else
		{
			if(Recover_right())  // FAILED_WITHDRAW
				return FAILED_EFFECT_TERMINAT;
			else
				return TRUE;			
		}
	}

	if(Want_to_Review_BasedOn_ChangedAtInternationalStage)		// R106
		{	(PCT_EnterNational_date + MONTH_2)	}


}


int PatentApplication_For_PCT(PATENT_APPLICATION_ENUM Obj_app)
{
	if(FAILED_WITHDRAW_FOR_PCT || FAILED_WITHDRAWED_FOR_PCT || FAILED_WITHDRAW_CHINA_FOR_PCT)  // ���ʽ׶�   R105
		return FAILED_EFFECT_TERMINAT;
	
	if(Priority_date + MONTH_30)
	{
		Enter_National_Stage();
	}
	else if (Priority_date + MONTH_30 + MONTH_2)
	{
	  
		if(Recover_right())
			Enter_National_Stage();

	}else{
		
		return FAILED_EFFECT_TERMINAT;  // R105
	}
}


/***********************		ר��Ȩ�ı���								********************************************/

int ProtectPatent()   // ��������
{



}
