


#define true   1
#define false  0

int CheckPepole()
{

	return true;
}

int CheckObj()
{
	return true;

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
				return true;
			}
		}
	}
	
	return false;
}

int Authorization()
{

	if(false == CheckPepole())   // 申请主体
	{
		return false;
	}

	if(false == CheckObj())		// 保护客体  A25
	{
		return false;
	}

	if(false == Check3Attrib())	// 三性等
	{
		return false;
	}

	return true;
}
