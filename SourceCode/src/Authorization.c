


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

	if(false == CheckPepole())   // ��������
	{
		return false;
	}

	if(false == CheckObj())		// ��������  A25
	{
		return false;
	}

	if(false == Check3Attrib())	// ���Ե�
	{
		return false;
	}

	return true;
}
