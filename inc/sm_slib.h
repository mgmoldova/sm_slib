/*
 * sm_slib.h
 *
 * Created: 10/15/2018 5:28:55 PM
 *  Author: capn-wiggles
 */ 


#ifndef SD_SLIB_H_
#define SD_SLIB_H_

#define F_CPU 16000000UL // 16 MHz
#define BAUD 9600
#define BRC ((F_CPU/16/BAUD)-1)

typedef unsigned char _BYTE;
typedef unsigned int _UI;

_UI set_baud_9600();

_BYTE config_ddr(_BYTE port, _BYTE port_conf);
_BYTE config_ddr_out(_BYTE port, _BYTE port_nr[8]);

/* MATH FUNCTIONS */
int pow(int x, int y);

#endif /* SD_SLIB_H_ */