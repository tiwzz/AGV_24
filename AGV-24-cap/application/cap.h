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
    uint8_t     head;               //帧头
    uint8_t     p_set;              //设定功率
    uint16_t    input_voltage;      //输入电压
    uint16_t    current;            //输入电流
    uint16_t    cap_voltage;        //电容电压
    uint16_t    output_voltage;     //输出电压
    uint8_t     power_source;       //电源来源-1前级电源  2电容组  3输出关闭
    uint8_t     crc_checksum;
}com_feedback_typedef;  //反馈数据

typedef struct 
{
    uint8_t     head;                   //帧头
    uint8_t     p_set;                  //设定功率
    uint16_t    freq_feedback:14;       //反馈频率，默认100
    uint16_t    nc:1;           //该位保留
    uint16_t    wireless_en:1;          //无线开关
    uint8_t     power_source;           //控制电源来源-1前级电源  2电容组  3输出关闭
    uint8_t     crc_checksum;
}com_control_typedef;  //控制数据

void cap_task(void const *pvParameters);
