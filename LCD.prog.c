

#include "types.h"
#include "util.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "DELAY.h"


extern void LCD_voidInit(void) {
	delay_ms(15);
	LCD_voidWriteCommand(SQUECNE);
	delay_ms(5);
	LCD_voidWriteCommand(SQUECNE);
	delay_ms(1);
	

}

extern void LCD_voidWriteCommand(u8 Copy_u8Data) {

	DIO_u8WritePinVal(LCD_D0, GET_BIT(Copy_u8Data, 0));
	DIO_u8WritePinVal(LCD_D1, GET_BIT(Copy_u8Data, 1));
	DIO_u8WritePinVal(LCD_D2, GET_BIT(Copy_u8Data, 2));
	DIO_u8WritePinVal(LCD_D3, GET_BIT(Copy_u8Data, 3));
	DIO_u8WritePinVal(LCD_D4, GET_BIT(Copy_u8Data, 4));
	DIO_u8WritePinVal(LCD_D5, GET_BIT(Copy_u8Data, 5));
	DIO_u8WritePinVal(LCD_D6, GET_BIT(Copy_u8Data, 6));
	DIO_u8WritePinVal(LCD_D7, GET_BIT(Copy_u8Data, 7));

	DIO_u8WritePinVal(LCD_RS, 0);
	DIO_u8WritePinVal(LCD_RW, 0);
	DIO_u8WritePinVal(LCD_Enable, 1);
	delay_ms(1);
	DIO_u8WritePinVal(LCD_Enable, 0);

	return;

}

extern void LCD_voidWriteData(u8 Copy_u8Data) {

	DIO_u8WritePinVal(LCD_D0, GET_BIT(Copy_u8Data, 0));
	DIO_u8WritePinVal(LCD_D1, GET_BIT(Copy_u8Data, 1));
	DIO_u8WritePinVal(LCD_D2, GET_BIT(Copy_u8Data, 2));
	DIO_u8WritePinVal(LCD_D3, GET_BIT(Copy_u8Data, 3));
	DIO_u8WritePinVal(LCD_D4, GET_BIT(Copy_u8Data, 4));
	DIO_u8WritePinVal(LCD_D5, GET_BIT(Copy_u8Data, 5));
	DIO_u8WritePinVal(LCD_D6, GET_BIT(Copy_u8Data, 6));
	DIO_u8WritePinVal(LCD_D7, GET_BIT(Copy_u8Data, 7));

	DIO_u8WritePinVal(LCD_RS, 1);
	DIO_u8WritePinVal(LCD_RW, 0);
	DIO_u8WritePinVal(LCD_Enable, 1);
	//delay_ms(1);
	DIO_u8WritePinVal(LCD_Enable, 0);

	return;

}
extern void LCD_voidWriteString(u8* STRING) {
	u8 Counter;

	for (Counter = 0; STRING[Counter] != '\0';
			Counter++) {
		LCD_voidWriteData(STRING[Counter]);
		delay_ms(20);
	}
	return;
}

extern void LCD_voidClearSceen(void){

	LCD_voidWriteCommand(0x01);

	return ;
}

