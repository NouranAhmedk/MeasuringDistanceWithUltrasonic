/******************************************************************************
 * Module: Atmega32 Library
 * File Name: atmega_32.h
 * Description: illustrate the idea of bit-fields with Memory Mapped Registers.
 * Author: Nouran Ahmed
 *******************************************************************************/

#ifndef LIBRARY_ATMEGA_32_H_
#define LIBRARY_ATMEGA_32_H_

#include "../LIBRARY/std_types.h"

/*Register data types*/
/*******************************************************************************/

/*Status Register - SREG*/
typedef union {
	uint8 byte; /*1 bytes -> 8 bits*/
	struct {
		uint8 C_BIT :1; /*1-bit in Size*/
		uint8 Z_BIT :1;
		uint8 N_BIT :1;
		uint8 V_BIT :1;
		uint8 S_BIT :1;
		uint8 H_BIT :1;
		uint8 T_BIT :1;
		uint8 I_BIT :1;
	} bits;
} SREG_REG_8BIT;

/*Status Register - SPH and SPL*/
typedef union {
	uint16 Short; /*2 bytes -> 2 bytes -> 16 bits*/
	struct {
		uint8 high;
		uint8 low;

	} bytes;
	struct {
		uint8 SP0 :1; /*1-bit in Size*/
		uint8 SP1 :1;
		uint8 SP2 :1;
		uint8 SP3 :1;
		uint8 SP4 :1;
		uint8 SP5 :1;
		uint8 SP6 :1;
		uint8 SP7 :1;
		uint8 SP8 :1;
		uint8 SP9 :1;
		uint8 SP10 :1;
		uint8 SP11 :1;
		uint8 :4;
	} bits;
} SP_REG_16BIT;

/*Output Compare Register - OCR0*/
typedef union {
	uint8 byte;

} OCR0_REG_8BIT;

/*General Interrupt Control Register - GICR */
typedef union {
	uint8 byte; /*1 bytes -> 8 bits*/
	struct {
		uint8 IVCE :1; /*1-bit in Size*/
		uint8 IVSEL :1;
		uint8 :3;
		uint8 INT2 :1;
		uint8 INT0 :1;
		uint8 INT1 :1;
	} bits;
} GICR_REG_8BIT;

/*General Interrupt Flag Register – GIFR*/
typedef union {
	uint8 byte;
	struct {
		uint8 :5;
		uint8 INTF2 :1;
		uint8 INTF0 :1;
		uint8 INTF1 :1;
	} bits;
} GIFR_REG_8BIT;

/*Timer/Counter Interrupt Mask Register – TIMSK*/
typedef union {
	uint8 byte;
	struct {
		uint8 TOIE0 :1;
		uint8 OCIE0 :1;
		uint8 TOIE1 :1;
		uint8 OCIE1B :1;
		uint8 OCIE1A :1;
		uint8 TICIE1 :1;
		uint8 TOIE2 :1;
		uint8 OCIE2 :1;
	} bits;
} TIMSK_REG_8BIT;

/*Timer/Counter Interrupt Flag Register – TIFR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TOV0 :1;
		uint8 OCF0 :1;
		uint8 TOV1 :1;
		uint8 OCF1B :1;
		uint8 OCF1A :1;
		uint8 ICF1 :1;
		uint8 TOV2 :1;
		uint8 OCF2 :1;
	} bits;
} TIFR_REG_8BIT;

/*Store Program Memory Control Register – SPMCR*/
typedef union {
	uint8 byte;
	struct {
		uint8 SPMEN :1;
		uint8 PGERS :1;
		uint8 PGWRT :1;
		uint8 BLBSET :1;
		uint8 RWWSRE :1;
		uint8 :1;
		uint8 RWWSB :1;
		uint8 SPMIE :1;
	} bits;
} SPMCR_REG_8BIT;

/*TWI Control Register – TWCR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TWIE :1;
		uint8 :1;
		uint8 TWEN :1;
		uint8 TWWC :1;
		uint8 TWSTO :1;
		uint8 TWSTA :1;
		uint8 TWEA :1;
		uint8 TWINT :1;
	} bits;
} TWCR_REG_8BIT;

/* MCU Control Register – MCUCR*/
typedef union {
	uint8 byte;
	struct {
		uint8 ISC00 :1;
		uint8 ISC01 :1;
		uint8 ISC10 :1;
		uint8 ISC11 :1;
		uint8 SM0 :1;
		uint8 SM1 :1;
		uint8 SM2 :1;
		uint8 SE :1;
	} bits;
} MCUCR_REG_8BIT;

/*MCU Control and Status Register – MCUCSR*/
typedef union {
	uint8 byte;
	struct {
		uint8 PORF :1;
		uint8 EXTRF :1;
		uint8 BORF :1;
		uint8 WDRF :1;
		uint8 JTRF :1;
		uint8 :1;
		uint8 ISC2 :1;
		uint8 JTD :1;
	} bits;
} MCUCSR_REG_8BIT;

/*Timer/Counter Control Register – TCCR0 */
typedef union {
	uint8 byte;
	struct {
		uint8 CS00 :1;
		uint8 CS01 :1;
		uint8 CS02 :1;
		uint8 WGM01 :1;
		uint8 COM00 :1;
		uint8 COM01 :1;
		uint8 WGM00 :1;
		uint8 FOC0 :1;
	} bits;
} TCCR0_REG_8BIT;

/*Timer/Counter Register – TCNT0*/
typedef union {
	uint8 byte;

} TCNT0_REG_8BIT;

/*Oscillator Calibration Register – OSCCAL*/
typedef union {
	uint8 byte;

} OSCCAL_REG_8BIT;

/*On-chip Debug Register – OCDR*/
typedef union {
	uint8 byte;

} OCDR_REG_8BIT;

/*Special Function I/O Register – SFIOR */
typedef union {
	uint8 byte;
	struct {
		uint8 PSR10 :1;
		uint8 PSR2 :1;
		uint8 PUD :1;
		uint8 ACME :1;
		uint8 :1;
		uint8 ADTS0 :1;
		uint8 ADTS1 :1;
		uint8 ADTS2 :1;
	} bits;
} SFIOR_REG_8BIT;

/*Timer/Counter1 Control Register A – TCCR1A */
typedef union {
	uint8 byte;
	struct {
		uint8 WGM10 :1;
		uint8 WGM11 :1;
		uint8 FOC1B :1;
		uint8 FOC1A :1;
		uint8 COM1B0 :1;
		uint8 COM1B1 :1;
		uint8 COM1A0 :1;
		uint8 COM1A1 :1;
	} bits;
} TCCR1A_REG_8BIT;

/* Timer/Counter1 Control Register B – TCCR1B*/
typedef union {
	uint8 byte;
	struct {
		uint8 CS10 :1;
		uint8 CS11 :1;
		uint8 CS12 :1;
		uint8 WGM12 :1;
		uint8 WGM13 :1;
		uint8 :1;
		uint8 ICES1 :1;
		uint8 ICNC1 :1;
	} bits;
} TCCR1B_REG_8BIT;

/*Timer/Counter1 – TCNT1H and TCNT1L*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;
	} bytes;
} TCNT1_REG_16BIT;

/*Output Compare Register 1 A – OCR1AH and OCR1AL*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;

	} bytes;
} OCR1A_REG_16BIT;

/*Output Compare Register 1 B – OCR1BH and OCR1BL*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;

	} bytes;
} OCR1B_REG_16BIT;

/*Input Capture Register 1 – ICR1H and ICR1L*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;

	} bytes;
} ICR1_REG_16BIT;

/*Timer/Counter Control Register – TCCR2*/
typedef union {
	uint8 byte;
	struct {
		uint8 CS20 :1;
		uint8 CS21 :1;
		uint8 CS22 :1;
		uint8 WGM21 :1;
		uint8 COM20 :1;
		uint8 COM21 :1;
		uint8 WGM20 :1;
		uint8 FOC2 :1;
	} bits;
} TCCR2_REG_8BIT;

/*Timer/Counter Register – TCNT2*/
typedef union {
	uint8 byte;
} TCNT2_REG_8BIT;

/*Output Compare Register – OCR2*/
typedef union {
	uint8 byte;

} OCR2_REG_8BIT;

/*Asynchronous Status Register – ASSR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TCR2UB :1;
		uint8 OCR2UB :1;
		uint8 TCN2UB :1;
		uint8 AS2 :1;
		uint8 :4;
	} bits;
} ASSR_REG_8BIT;

/*Watchdog Timer Control Register – WDTCR*/
typedef union {
	uint8 byte;
	struct {
		uint8 WDP0 :1;
		uint8 WDP1 :1;
		uint8 WDP2 :1;
		uint8 WDE :1;
		uint8 WDTOE :1;
		uint8 :3;
	} bits;
} WDTCR_REG_8BIT;

/*USART Baud Rate Registers – UBRRH*/
typedef union {
	uint8 byte;
	struct {
		uint8 UBRR8 :1;
		uint8 UBRR9 :1;
		uint8 UBRR10 :1;
		uint8 UBRR11 :1;
		uint8 :3;
		uint8 URSEL :1;
	} bits;
} UBRRH_REG_8BIT;

/*USART Control and Status Register C – UCSRC*/
typedef union {
	uint8 byte;
	struct {
		uint8 UCPOL :1;
		uint8 UCSZ0 :1;
		uint8 UCSZ1 :1;
		uint8 USBS :1;
		uint8 UPM0 :1;
		uint8 UPM1 :1;
		uint8 UMSEL :1;
		uint8 URSEL :1;
	} bits;
} UCSRC_REG_8BIT;

/*The EEPROM Address Register – EEARH and EEARL*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;

	} byte;
	struct {
		uint8 EEAR0 :1;
		uint8 EEAR1 :1;
		uint8 EEAR2 :1;
		uint8 EEAR3 :1;
		uint8 EEAR4 :1;
		uint8 EEAR5 :1;
		uint8 EEAR6 :1;
		uint8 EEAR7 :1;
		uint8 EEAR8 :1;
		uint8 EEAR9 :1;
		uint8 :6;
	} bits;
} EEAR_REG_16BIT;

/*The EEPROM Data Register – EEDR*/
typedef union {
	uint8 byte;

} EEDR_REG_8BIT;

/*The EEPROM Control Register – EECR*/
typedef union {
	uint8 byte;
	struct {
		uint8 EERE :1;
		uint8 EEWE :1;
		uint8 EEMWE :1;
		uint8 EERIE :1;
		uint8 :4;
	} bits;
} EECR_REG_8BIT;

/*Port A Data Register – PORTA*/
typedef union {
	uint8 byte;
	struct {
		uint8 PORTA0 :1;
		uint8 PORTA1 :1;
		uint8 PORTA2 :1;
		uint8 PORTA3 :1;
		uint8 PORTA4 :1;
		uint8 PORTA5 :1;
		uint8 PORTA6 :1;
		uint8 PORTA7 :1;
	} bits;
} PORTA_REG_8BIT;

/*Port A Data Direction Register – DDRA*/
typedef union {
	uint8 byte;
	struct {
		uint8 DDA0 :1;
		uint8 DDA1 :1;
		uint8 DDA2 :1;
		uint8 DDA3 :1;
		uint8 DDA4 :1;
		uint8 DDA5 :1;
		uint8 DDA6 :1;
		uint8 DDA7 :1;
	} bits;
} DDRA_REG_8BIT;

/*Port A Input Pins Address – PINA */
typedef union {
	uint8 byte;
	struct {
		uint8 PINA0 :1;
		uint8 PINA1 :1;
		uint8 PINA2 :1;
		uint8 PINA3 :1;
		uint8 PINA4 :1;
		uint8 PINA5 :1;
		uint8 PINA6 :1;
		uint8 PINA7 :1;
	} bits;
} PINA_REG_8BIT;

/*Port B Data Register – PORTB*/
typedef union {
	uint8 byte;
	struct {
		uint8 PORTB0 :1;
		uint8 PORTB1 :1;
		uint8 PORTB2 :1;
		uint8 PORTB3 :1;
		uint8 PORTB4 :1;
		uint8 PORTB5 :1;
		uint8 PORTB6 :1;
		uint8 PORTB7 :1;
	} bits;
} PORTB_REG_8BIT;

/*Port B Data Direction Register – DDRB*/
typedef union {
	uint8 byte;
	struct {
		uint8 DDB0 :1;
		uint8 DDB1 :1;
		uint8 DDB2 :1;
		uint8 DDB3 :1;
		uint8 DDB4 :1;
		uint8 DDB5 :1;
		uint8 DDB6 :1;
		uint8 DDB7 :1;
	} bits;
} DDRB_REG_8BIT;

/*Port B Input Pins Address – PINB */
typedef union {
	uint8 byte;
	struct {
		uint8 PINB0 :1;
		uint8 PINB1 :1;
		uint8 PINB2 :1;
		uint8 PINB3 :1;
		uint8 PINB4 :1;
		uint8 PINB5 :1;
		uint8 PINB6 :1;
		uint8 PINB7 :1;
	} bits;
} PINB_REG_8BIT;

/*Port C Data Register – PORTC*/
typedef union {
	uint8 byte;
	struct {
		uint8 PORTC0 :1;
		uint8 PORTC1 :1;
		uint8 PORTC2 :1;
		uint8 PORTC3 :1;
		uint8 PORTC4 :1;
		uint8 PORTC5 :1;
		uint8 PORTC6 :1;
		uint8 PORTC7 :1;
	} bits;
} PORTC_REG_8BIT;

/*Port C Data Direction Register – DDRC*/
typedef union {
	uint8 byte;
	struct {
		uint8 DDC0 :1;
		uint8 DDC1 :1;
		uint8 DDC2 :1;
		uint8 DDC3 :1;
		uint8 DDC4 :1;
		uint8 DDC5 :1;
		uint8 DDC6 :1;
		uint8 DDC7 :1;
	} bits;
} DDRC_REG_8BIT;

/*Port C Input Pins Address – PINC */
typedef union {
	uint8 byte;
	struct {
		uint8 PINC0 :1;
		uint8 PINC1 :1;
		uint8 PINC2 :1;
		uint8 PINC3 :1;
		uint8 PINC4 :1;
		uint8 PINC5 :1;
		uint8 PINC6 :1;
		uint8 PINC7 :1;
	} bits;
} PINC_REG_8BIT;

/*Port D Data Register – PORTD*/
typedef union {
	uint8 byte;
	struct {
		uint8 PORTD0 :1;
		uint8 PORTD1 :1;
		uint8 PORTD2 :1;
		uint8 PORTD3 :1;
		uint8 PORTD4 :1;
		uint8 PORTD5 :1;
		uint8 PORTD6 :1;
		uint8 PORTD7 :1;
	} bits;
} PORTD_REG_8BIT;

/*Port D Data Direction Register – DDRD*/
typedef union {
	uint8 byte;
	struct {
		uint8 DDD0 :1;
		uint8 DDD1 :1;
		uint8 DDD2 :1;
		uint8 DDD3 :1;
		uint8 DDD4 :1;
		uint8 DDD5 :1;
		uint8 DDD6 :1;
		uint8 DDD7 :1;
	} bits;
} DDRD_REG_8BIT;

/*Port D Input Pins Address – PIND */
typedef union {
	uint8 byte;
	struct {
		uint8 PIND0 :1;
		uint8 PIND1 :1;
		uint8 PIND2 :1;
		uint8 PIND3 :1;
		uint8 PIND4 :1;
		uint8 PIND5 :1;
		uint8 PIND6 :1;
		uint8 PIND7 :1;
	} bits;
} PIND_REG_8BIT;

/*SPI Data Register – SPDR*/
typedef union {
	uint8 byte;

} SPDR_REG_8BIT;

/*SPI Status Register – SPSR*/
typedef union {
	uint8 byte;
	struct {
		uint8 SPI2X :1;
		uint8 :5;
		uint8 WCOL :1;
		uint8 SPIF :1;
	} bits;
} SPSR_REG_8BIT;

/*SPI Control Register – SPCR*/
typedef union {
	uint8 byte;
	struct {
		uint8 SPR0 :1;
		uint8 SPR1 :1;
		uint8 CPHA :1;
		uint8 CPOL :1;
		uint8 MSTR :1;
		uint8 DORD :1;
		uint8 SPE :1;
		uint8 SPIE :1;
	} bits;
} SPCR_REG_8BIT;

/*USART I/O Data Register – UDR*/
typedef union {
	uint8 byte;
} UDR_REG_8BIT;

/*USART Control and Status Register A – UCSRA*/
typedef union {
	uint8 byte;
	struct {
		uint8 MPCM :1;
		uint8 U2X :1;
		uint8 PE :1;
		uint8 DOR :1;
		uint8 FE :1;
		uint8 UDRE :1;
		uint8 TXC :1;
		uint8 RXC :1;
	} bits;
} UCSRA_REG_8BIT;

/*USART Control and Status Register B – UCSRB*/
typedef union {
	uint8 byte;
	struct {
		uint8 TXB8 :1;
		uint8 RXB8 :1;
		uint8 UCSZ2 :1;
		uint8 TXEN :1;
		uint8 RXEN :1;
		uint8 UDRIE :1;
		uint8 TXCIE :1;
		uint8 RXCIE :1;
	} bits;
} UCSRB_REG_8BIT;

/*USART Baud Rate Registers – UBRRL*/
typedef union {
	uint8 byte;
} UBRRL_REG_8BIT;

/*Analog Comparator Control and Status Register – ACSR*/
typedef union {
	uint8 byte;
	struct {
		uint8 ACIS0 :1;
		uint8 ACIS1 :1;
		uint8 ACIC :1;
		uint8 ACIE :1;
		uint8 ACI :1;
		uint8 ACO :1;
		uint8 ACBG :1;
		uint8 ACD :1;
	} bits;
} ACSR_REG_8BIT;

/*ADC Multiplexer Selection Register – ADMUX*/
typedef union {
	uint8 byte;
	struct {
		uint8 MUX0 :1;
		uint8 MUX1 :1;
		uint8 MUX2 :1;
		uint8 MUX3 :1;
		uint8 MUX4 :1;
		uint8 ADLAR :1;
		uint8 REFS0 :1;
		uint8 REFS1 :1;
	} bits;
} ADMUX_REG_8BIT;

/*ADC Control and Status Register A – ADCSRA*/
typedef union {
	uint8 byte;
	struct {
		uint8 ADPS0 :1;
		uint8 ADPS1 :1;
		uint8 ADPS2 :1;
		uint8 ADIE :1;
		uint8 ADIF :1;
		uint8 ADATE :1;
		uint8 ADSC :1;
		uint8 ADEN :1;
	} bits;
} ADCSRA_REG_8BIT;

/*The ADC Data Register – ADCL and ADCH*/
typedef union {
	uint16 Short;
	struct {
		uint8 high;
		uint8 low;

	} byte;
} ADC_REG_16BIT;

/*TWI Data Register – TWDR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TWD0 :1;
		uint8 TWD1 :1;
		uint8 TWD2 :1;
		uint8 TWD3 :1;
		uint8 TWD4 :1;
		uint8 TWD5 :1;
		uint8 TWD6 :1;
		uint8 TWD7 :1;
	} bits;
} TWDR_REG_8BIT;

/*TWI (Slave) Address Register – TWAR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TWGCE :1;
		uint8 TWA0 :1;
		uint8 TWA1 :1;
		uint8 TWA2 :1;
		uint8 TWA3 :1;
		uint8 TWA4 :1;
		uint8 TWA5 :1;
		uint8 TWA6 :1;
	} bits;
} TWAR_REG_8BIT;

/*TWI Status Register – TWSR*/
typedef union {
	uint8 byte;
	struct {
		uint8 TWPS0 :1;
		uint8 TWPS1 :1;
		uint8 :1;
		uint8 TWS3 :1;
		uint8 TWS4 :1;
		uint8 TWS5 :1;
		uint8 TWS6 :1;
		uint8 TWS7 :1;
	} bits;
} TWSR_REG_8BIT;

/*TWI Bit Rate Register – TWBR*/
typedef union {
	uint8 byte;
} TWBR_REG_8BIT;

/*Register Addresses*/
#define SREG_REG    (*(volatile SREG_REG_8BIT*)0x5F)
#define SP_REG      (*(volatile SP_REG_16BIT*)0x5D)
#define OCR0_REG    (*(volatile OCR0_REG_8BIT*)0x5C)
#define GICR_REG    (*(volatile GICR_REG_8BIT*)0x5B)
#define GIFR_REG    (*(volatile GIFR_REG_8BIT*)0x5A)
#define TIMSK_REG   (*(volatile TIMSK_REG_8BIT*)0x59)
#define TIFR_REG    (*(volatile TIFR_REG_8BIT*)0x58)
#define SPMCR_REG   (*(volatile SPMCR_REG_8BIT*)0x57)
#define TWCR_REG    (*(volatile TWCR_REG_8BIT*)0x56)
#define MCUCR_REG   (*(volatile MCUCR_REG_8BIT*)0x55)
#define MCUCSR_REG  (*(volatile MCUCSR_REG_8BIT*)0x54)
#define TCCR0_REG   (*(volatile TCCR0_REG_8BIT*)0x53)
#define TCNT0_REG   (*(volatile TCNT0_REG_8BIT*)0x52)
#define OSCCAL_REG  (*(volatile OSCCAL_REG_8BIT*)0x51)
#define OCDR_REG    (*(volatile OCDR_REG_8BIT*)0x51)
#define SFIOR_REG   (*(volatile SFIOR_REG_8BIT*)0x50)
#define TCCR1A_REG  (*(volatile TCCR1A_REG_8BIT*)0x4F)
#define TCCR1B_REG  (*(volatile TCCR1B_REG_8BIT*)0x4E)
#define TCNT1_REG   (*(volatile TCNT1_REG_16BIT*)0x4C)
#define OCR1A_REG   (*(volatile OCR1A_REG_16BIT*)0x4A)
#define OCR1B_REG   (*(volatile OCR1B_REG_16BIT*)0x48)
#define ICR1_REG    (*(volatile ICR1_REG_16BIT*)0x46)
#define TCCR2_REG   (*(volatile TCCR2_REG_8BIT*)0x45)
#define TCNT2_REG   (*(volatile TCNT2_REG_8BIT*)0x44)
#define OCR2_REG    (*(volatile OCR2_REG_8BIT*)0x43)
#define ASSR_REG    (*(volatile ASSR_REG_8BIT*)0x42)
#define WDTCR_REG   (*(volatile WDTCR_REG_8BIT*)0x41)
#define UBRRH_REG   (*(volatile UBRRH_REG_8BIT*)0x40)
#define UCSRC_REG   (*(volatile UCSRC_REG_8BIT*)0x40)
#define EEAR_REG    (*(volatile EEAR_REG_16BIT*)0x3E)
#define EEDR_REG    (*(volatile EEDR_REG_8BIT*)0x3D)
#define EECR_REG    (*(volatile EECR_REG_8BIT*)0x3C)
#define PORTA_REG   (*(volatile PORTA_REG_8BIT*)0x3B)
#define DDRA_REG    (*(volatile DDRA_REG_8BIT*)0x3A)
#define PINA_REG    (*(volatile PINA_REG_8BIT*)0x39)
#define PORTB_REG   (*(volatile PORTB_REG_8BIT*)0x38)
#define DDRB_REG    (*(volatile DDRB_REG_8BIT*)0x37)
#define PINB_REG    (*(volatile PINB_REG_8BIT*)0x36)
#define PORTC_REG   (*(volatile PORTC_REG_8BIT*)0x35)
#define DDRC_REG    (*(volatile DDRC_REG_8BIT*)0x34)
#define PINC_REG    (*(volatile PINC_REG_8BIT*)0x33)
#define PORTD_REG   (*(volatile PORTD_REG_8BIT*)0x32)
#define DDRD_REG    (*(volatile DDRD_REG_8BIT*)0x31)
#define PIND_REG    (*(volatile PIND_REG_8BIT*)0x30)
#define SPDR_REG    (*(volatile SPDR_REG_8BIT*)0x2F)
#define SPSR_REG    (*(volatile SPSR_REG_8BIT*)0x2E)
#define SPCR_REG    (*(volatile SPCR_REG_8BIT*)0x2D)
#define UDR_REG     (*(volatile UDR_REG_8BIT*)0x2C)
#define UCSRA_REG   (*(volatile UCSRA_REG_8BIT*)0x2B)
#define UCSRB_REG   (*(volatile UCSRB_REG_8BIT*)0x2A)
#define UBRRL_REG   (*(volatile UBRRL_REG_8BIT*)0x29)
#define ACSR_REG    (*(volatile ACSR_REG_8BIT*)0x28)
#define ADMUX_REG   (*(volatile ADMUX_REG_8BIT*)0x27)
#define ADCSRA_REG  (*(volatile ADCSRA_REG_8BIT*)0x26)
#define ADC_REG     (*(volatile ADC_REG_16BIT*)0x24)
#define TWDR_REG    (*(volatile TWDR_REG_8BIT*)0x23)
#define TWAR_REG    (*(volatile TWAR_REG_8BIT*)0x22)
#define TWSR_REG    (*(volatile TWSR_REG_8BIT*)0x21)
#define TWBR_REG    (*(volatile TWBR_REG_8BIT*)0x20)

#endif /* LIBRARY_ATMEGA_32_H_ */
