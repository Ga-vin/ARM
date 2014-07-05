#ifndef REG_H_
#define REG_H_
#include "values.h"

#define ULCON0		*(volatile uint32 *)0x50000000
#define UCON0  	 	*(volatile uint32 *)0x50000004
#define UFIFOCON0	*(volatile uint32 *)0x50000008
#define UMCON0		*(volatile uint32 *)0x5000000C
#define UTRSTAT0	*(volatile uint32 *)0x50000010
#define UERSTAT0	*(volatile uint32 *)0x50000014
#define UFIFOSTAT0	*(volatile uint32 *)0x50000018
#define UMSTAT0		*(volatile uint32 *)0x5000001C
#define UTXH0		*(volatile uint32 *)0x50000020
#define URXH0		*(volatile uint32 *)0x50000024
#define UBRDIV0		*(volatile uint32 *)0x50000028

#endif