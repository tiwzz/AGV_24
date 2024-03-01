#include "cap.h"

#include "CRC8_CRC16.h"
#include "main.h"
#include "usart.h"
#include "cmsis_os.h"

void cap_task(void const *pvParameters)
{
	com_control_typedef cap_para = {0};
	cap_para.head = CTRL_FREAM_HEAD;
	cap_para.p_set = 40;
	cap_para.freq_feedback = 100;
	cap_para.wireless_en = 0;
	cap_para.power_source = CAPACITY;
	
	append_CRC8_check_sum((unsigned char *)&cap_para,sizeof(cap_para));
	
	while(1)
	{
		HAL_UART_Transmit(&huart1,(uint8_t *)&cap_para,sizeof(cap_para),100); 
		osDelay(200);
	}
}