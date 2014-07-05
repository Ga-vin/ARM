#include "uart.h"

void init_uart(uint32 baud_rate)
{
	// set baud rate, data bits, stop bits, parity and flow
	// control bits
	// here it need to be set data bits only, other bits can
	// use default bits values
	// 禁止红外模式
	ULCON0 &= ~(0x1<<6);
	
	// 设置为无校验
	ULCON0 &= ~(0x7<<3);
	
	// 使用1位停止位
	ULCON0 &= (0x1<<2);
	
	// 使用8位数据位
	UCON0 &= ~(0x3<<0);
	UCON0 |= (0x3<<0);
	
	// 禁止接收超时功能
	UCON0 &= ~(0x1<<7);
	
	// 不产生接收错误状态
	UCON0 &= ~(0x1<<6);
	
	// 不进行回环测试模式
	UCON0 &= ~(0x1<<5);
	
	// 发送模式为DMA0
	UCON0 &= ~(0x3<<2);
	UCON0 |= (0x1<<3);
	
	// 接收模式为DMA0
	UCON0 &= ~(0x3<<0);
	UCON0 |= (0x1<<1);
	
	// 接收时钟选为PCLK
	UCON0 &= ~(0x3<<10);
	
	// 设置波特率:57600
	UBRDIV0 &= ~(0xFFFF);
	UBRDIV0 |= ((int)(PCLK / (BAUD * 16) - 1));
}