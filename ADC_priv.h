//register
#ifndef _ADC_PRIV_H_
#define _ADC_PRIV_H_
#define ADCH *((volatile u8 *)ox25)
#define ADCL  *((volatile u8 *)ox24)
#define ADCSRA *((volatile u8 *)ox26)
#define ADMUX  *((volatile u8 *)ox27)
#define SFIOR  *((volatile u8 *)ox50)
//pins
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
//ADMUX
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4  4
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0
//ADCSRA
#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
//SFIOR
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5
#define ACME  3
#define PUD   2
#define PSR2  1
#define PSR10  0
//enabling
#define enable 1
#define disable 0
#define AVCC                                                  ADMUX|=(1<<REFS0)
#define AREF                                                  ADMUX&=~(1<<REFS0)|(1<<REFS1)
#define INTERNAL                                              ADMUX|=(1<<REFS0)| (1<<REFS1)
#define LEFT_ADJUSTED                                         ADMUX|=(1<<ADLAR)
#define RIGHT_ADJUSTED                                        ADMUX&=~(1<<ADLAR)
#define ENABLE_ADC                                            ADCSRA|=(1<<ADEN)
#define DISBALE_ADC                                           ADCSRA&=~(1<<ADEN)
#define ADC_START_CONV                                        ADCSRA|=(1<<ADATE)
#define ADC_AUTO_TRIGGER_ENABLE                               ADCSRA|=(1<<ADIF)
#define ADC_INTERRUPT_FLAG_ENABLE                             ADCSRA|=(1<<ADIE)
#define ADC_INTERRUPT_ENBALE                                  ADCSRA|=(1<<ADPS2)
#define ADC_PRESCALER_ENABLE                                  ADCSRA|=(1<<ADPS1)
#define ADC_CK2                                               (ADCSRA|=(1<<ADPS0))&&(ADCSRA&=~(1<<ADPS1))&&((ADCSRA&=~(1<<ADPS2)))
#define ADC_CK4                                               (ADCSRA&=~(1<<ADPS0))&&(ADCSRA|=(1<<ADPS1))&&((ADCSRA&=~(1<<ADPS2)))
#define ADC_CK8                                               (ADCSRA|=(1<<ADPS0))&&(ADCSRA|=(1<<ADPS1))&&((ADCSRA&=~(1<<ADPS2)))
#define ADC_CK16                                              (ADCSRA&=~(1<<ADPS0))&&(ADCSRA&=~(1<<ADPS1))&&((ADCSRA|=(1<<ADPS2)))
#define ADC_CK32                                              (ADCSRA|=(1<<ADPS0))&&(ADCSRA&=~(1<<ADPS1))&&((ADCSRA|=(1<<ADPS2)))
#define ADC_CK64                                              (ADCSRA&=~(1<<ADPS0))&&(ADCSRA|=(1<<ADPS1))&&((ADCSRA|=(1<<ADPS2)))
#define ADC_CK128                                             (ADCSRA|=(1<<ADPS0))&&(ADCSRA|=(1<<ADPS1))&&((ADCSRA|=(1<<ADPS2)))

#endif