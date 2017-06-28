


#define TRUE   1
#define FALSE  0

bool Want_to_modify = TRUE;			// ?????
bool Want_to_Second_Trail = TRUE;	// ???
bool Has_prioriy = TRUE;			// ????

#define FAILED_WITHDRAW			0	// ??
#define FAILED_TERMIATION		0	// ??


// All date 
#define Priority_date			// ????

#define Application_date		// ????? 	A28  A42

#define RECEIVED_A_NOTICE		// ???????

#define DATE2APP_SECOND_TRAIL 	// ??????

#define YEARS_3
#define YEARS_10
#define YEARS_20

#define MONTH_2
#define MONTH_3
#define MONTH_6
#define MONTH_12

#define DAYS_15


#define Novelty_Grace_period				MONTH_6			// ??????????
#define Priority_Grace_period_Design		MONTH_6			// ????????? 6???
#define Priority_Grace_period_Inovention	MONTH_12		// ????????? 12???
#define Priority_Grace_period_Unity			MONTH_12		// ??????? 12???



// Fees
// ???????
#define FEES_APP			// ???
#define FEES_SECOND_TRAIL	// ???
#define FEES_REVIEW		// ???
#define FEES_ANNUAL		// ??  (???????)


#define FEES_APP_PLUS		// ????? (??????10?,?????30?)
#define FEES_ANNOUNCE_PRINT		// ?????
#define FEES_WANT_PRIORIY  // ??????
#define FEES_RECOVER_RIGHT	// ???????
#define FEES_EXTEND_TIME	// ???????
#define FEES_REGISTER		// ?????
#define FEES_WANT_INVALID	// ???????
#define FEES_PATENT_EVALUATION_REPORT	// ??????????
#define FEES_RECORD_ITEM_CHANGE			// ???????

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
	
int Fisrt_trail() // ?? A3 A40
{

	if(Want_to_modify) 	// R51	??????
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


	if(FALSE==CheckFees())  // ??
	{
		return FALSE;
	}

	if(FALSE==CheckForm())	// ?????????
	{
		return FALSE;
	}

	if(FALSE==CheckLegal())  // ?????????
	{
		return FALSE;
	}

	if(FALSE==CheckObviousDefect())		// ??????? A5  A25
	{
		return FALSE;
	}
	
	return TRUE;
}

int Second_Trail() // ??
{
	if(Want_to_Second_Trail)
	{
		if(Priority_date + YEARS_3)  //A35
		{
		
			if(Check3Attrib())	// ???
					{
						return TRUE;
					}

		}else{
			return FAILED_WITHDRAW;
		}
	}

	

	return FALSE;
}

int Authorization() // ????
{

}

int Announced()		// ????  A34 
{


}


int PatentApplication(PATENT_APPLICATION_ENUM Obj_app)			// ????
{

	if(FALSE == CheckPepole())   // ????
	{
		return FALSE;
	}

	if(FALSE == CheckObj())		// ????  A25
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
		{						// turn down				
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
			 	Announced()		// ????
			 
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


int ProtectPatent()   // ????
{



}
