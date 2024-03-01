#ifndef CAP_H
#define CAP_H

#endif

#include "stdio.h"
#include "string.h"
#include "stdint.h"

#define FEEDBACK_FREAM_HEAD     0x11
#define CTRL_FREAM_HEAD         0x21

typedef enum
{
    BATTERY = 1,
    CAPACITY,
    OUT_OFF,
}power_source_enum; 

typedef struct 
{
    uint8_t     head;               //֡ͷ
    uint8_t     p_set;              //�趨����
    uint16_t    input_voltage;      //�����ѹ
    uint16_t    current;            //�������
    uint16_t    cap_voltage;        //���ݵ�ѹ
    uint16_t    output_voltage;     //�����ѹ
    uint8_t     power_source;       //��Դ��Դ-1ǰ����Դ  2������  3����ر�
    uint8_t     crc_checksum;
}com_feedback_typedef;  //��������

typedef struct 
{
    uint8_t     head;                   //֡ͷ
    uint8_t     p_set;                  //�趨����
    uint16_t    freq_feedback:14;       //����Ƶ�ʣ�Ĭ��100
    uint16_t    nc:1;           //��λ����
    uint16_t    wireless_en:1;          //���߿���
    uint8_t     power_source;           //���Ƶ�Դ��Դ-1ǰ����Դ  2������  3����ر�
    uint8_t     crc_checksum;
}com_control_typedef;  //��������

void cap_task(void const *pvParameters);
