/*
 * SM_SLIB.c
 *
 * Created: 10/15/2018 5:27:52 PM
 * Author : capn-wiggles
 */ 

#include <avr/io.h>
#include "inc/sd_slib.h"

_UI set_baud_9600() {
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;
}

_BYTE config_ddr(_BYTE port, _BYTE port_conf) {
	if(port == 'b' || port == 'B') DDRB=port_conf;
	else if(port == 'c' || port == 'C') DDRC=port_conf;
	else if(port == 'd' || port == 'D') DDRD=port_conf;
	else return 1;
	
	return 0;
}

_BYTE config_ddr_out(_BYTE port, _BYTE port_nr[8]) {
	unsigned short i = 0;
	if(port=='b' || port=='B') {
		DDRB=0b00000000;
		for(;i<8;i++) DDRB |= pow(2, port_nr[i]);
	} else if(port == 'c' || port == 'C') {
		DDRC=0b00000000;
		for(;i<8;i++) DDRC |= pow(2, port_nr[i]);
	} else if(port == 'd' || port == 'D') {
		DDRD=0b00000000;
		for(;i<8;i++) DDRD |= pow(2, port_nr[i]);
	} else return 1;
	
	return 0;
}

/* MATH FUNCTIONS */
int pow(int x, int y) {
	unsigned short i=0;
	if(y>0) {
		for(;i<y;y++) x*=x;
	} else if(y<0) {
		for(;i<y;y++) x*=x;
		x=1/x;
	} else x=1;
	return x;
}