


#define TRUE   1
#define FALSE  0

bool Want_to_modify = TRUE;				// 提主动修改
bool Want_to_advance_announce = TRUE;	// 提前公布申请
bool Want_to_Second_Trail = TRUE;		// 提实审
bool Has_prioriy = TRUE;				// 有优先权

#define FAILED_WITHDRAW			0	// 撤回
#define FAILED_TERMIATION		0	// 终止
#define FAILED_REJECT			0	// 驳回

// All date 
#define Priority_date			// 优先权日

#define Application_date		// 实际申请日 	A28  A42

#define RECEIVED_A_NOTICE		// 收到通知书之日

#define DATE2APP_SECOND_TRAIL 	// 提出实审之日

#define YEARS_3
#define YEARS_10
#define YEARS_20

#define MONTH_2
#define MONTH_3
#define MONTH_6
#define MONTH_12
#define MONTH_18

#define DAYS_15


#define Novelty_Grace_period				MONTH_6			// 不丧失新颖性的宽限期
#define Priority_Grace_period_Design		MONTH_6			// 外观设计优先权期限 6个月内
#define Priority_Grace_period_Inovention	MONTH_12		// 实用新型优先权期限 12个月内
#define Priority_Grace_period_Unity			MONTH_12		// 发明优先权期限 12个月内



// Fees
// 以下四种可减缓
#define FEES_APP			// 申请费
#define FEES_SECOND_TRAIL	// 实审费
#define FEES_REVIEW		// 复审费
#define FEES_ANNUAL		// 年费  (授权起三年年费)


#define FEES_APP_PLUS		// 申请附加费 (权利要求超过10项，说明书超过30页)
#define FEES_ANNOUNCE_PRINT		// 公布印刷费
#define FEES_WANT_PRIORIY  // 优先权请求费
#define FEES_RECOVER_RIGHT	// 恢复权利请求费
#define FEES_EXTEND_TIME	// 延长期限请求费
#define FEES_REGISTER		// 专利登记费
#define FEES_WANT_INVALID	// 无效宣告请求费
#define FEES_PATENT_EVALUATION_REPORT	// 专利权评价报告请求费
#define FEES_RECORD_ITEM_CHANGE			// 著录事项变更费

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
		
		FEES_APP + (FEES_APP_PLUS) + (FEES_WANT_PRIORIY) + FEES_ANNOUNCE_PRINT

		}

	if(Has_prioriy)
	{
		FEES_WANT_PRIORIY
	}
}

int CheckForm()
{}

int CheckLegal()
{}

int CheckObviousDefect()
{}
	
int Fisrt_trail() // 初审 A3 A40
{

	if(Want_to_modify) 	// R51	主动修改时机
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


	if(FALSE==CheckFees())  // 费用
	{
		return FALSE;
	}

	if(FALSE==CheckForm())	// 申请文件的形式审查
	{
		return FALSE;
	}

	if(FALSE==CheckLegal())  // 申请文件的法律手续
	{
		return FALSE;
	}

	if(FALSE==CheckObviousDefect())		// 明显实质性缺陷 A5  A25
	{
		return FALSE;
	}
	
	return TRUE;
}

int Second_Trail() // 实审
{
	if(Want_to_Second_Trail)
	{
		if(Priority_date + YEARS_3)  //A35
		{
		
			if(Check3Attrib())	// 三性等
					{
						return TRUE;
					}

		}else{
			return FAILED_WITHDRAW;
		}
	}

	

	return FALSE;
}

int Authorization() // 授权程序
{

}

int Announced()		// 国家公布  A34 
{


}


int PatentApplication(PATENT_APPLICATION_ENUM Obj_app)			// 申请流程
{

	if(FALSE == CheckPepole())   // 申请主体
	{
		return FALSE;
	}

	if(FALSE == CheckObj())		// 保护客体  A25
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
			 		Announced()												// 国家公布
			 
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


int ProtectPatent()   // 保护程序
{



}
