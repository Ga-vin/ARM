#include "uart.h"

void init_uart(uint32 baud_rate)
{
	// set baud rate, data bits, stop bits, parity and flow
	// control bits
	// here it need to be set data bits only, other bits can
	// use default bits values
	// ��ֹ����ģʽ
	ULCON0 &= ~(0x1<<6);
	
	// ����Ϊ��У��
	ULCON0 &= ~(0x7<<3);
	
	// ʹ��1λֹͣλ
	ULCON0 &= (0x1<<2);
	
	// ʹ��8λ����λ
	UCON0 &= ~(0x3<<0);
	UCON0 |= (0x3<<0);
	
	// ��ֹ���ճ�ʱ����
	UCON0 &= ~(0x1<<7);
	
	// ���������մ���״̬
	UCON0 &= ~(0x1<<6);
	
	// �����лػ�����ģʽ
	UCON0 &= ~(0x1<<5);
	
	// ����ģʽΪDMA0
	UCON0 &= ~(0x3<<2);
	UCON0 |= (0x1<<3);
	
	// ����ģʽΪDMA0
	UCON0 &= ~(0x3<<0);
	UCON0 |= (0x1<<1);
	
	// ����ʱ��ѡΪPCLK
	UCON0 &= ~(0x3<<10);
	
	// ���ò�����:57600
	UBRDIV0 &= ~(0xFFFF);
	UBRDIV0 |= ((int)(PCLK / (BAUD * 16) - 1));
}