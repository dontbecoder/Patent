



#define TheSummaryOf_Instruction // 说明书摘要

#define Claims								// 权利要求书

#define Instructions					// 说明书

#define Instructions_TechnicalField  // 技术领域

#define Instructions_BackgroundTech  // 背景技术

#define Instructions_Invention			// 发明内容

#define Instructions_DescriptionOfTheDrawings  // 附图说明

#define Instructions_ImplementationMethod		// 实施方式

#define ManualDrawing					// 说明书附图	



#define Methond_Invention		// 方法发明

void DocOfApplication()
{

    TheSummaryOf_Instruction
   		// 300字以内

	Claims

		if(Methond_Invention){

				// 权1-权5，方法权利要求
				// 权6-权x，与方法权利要求对应的装置权利要求
				// 权x+1 ,权x+2, 终端设备 + 计算机可读存储介质 权利要求
		}
		
    Instructions
	{
		Instructions_TechnicalField		// 最接近的领域

		Instructions_BackgroundTech		// 引出技术问题

		Instructions_Invention

			if(Methond_Invention){
				// 第一方面  独权方法		抄独权1
				// 第二方面  独权装置		抄独权6
				// 第三方面  终端设备
				// 第四方面  计算机可读存储介质


			}

		Instructions_DescriptionOfTheDrawings
			
		Instructions_ImplementationMethod	

			if(Methond_Invention){
				// 实施例1(方法)   步骤S1...对应独权1
				//                 步骤S21,S22,...对应从权2-5

				// 实施例2(装置)   模块与步骤一一对应

				// 实施例3(计算机可读存储介质)

				// 实施例4(终端设备)

			}
	}

	ManualDrawing
		// 图1 对应 实施例1中独权部分

	    // 图2.. 对应 实施例1中从权部分

  		// 图x 对应 实施例2(装置)

		// 图x 对应 实施例4(终端设备)
	

}



