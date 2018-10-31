#ifndef _ADC_INT_H_
#define _ADC_INT_H_
void init();
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidConfig(void);
void ADC_voidReadSingleShot(u16 *Copy_ptrToVal);
void ADC_voidReadMulShot(u16 *Copy_ptrToVal);
void ADC_voidReadGrp(u8 *Copy_ptrToVal);