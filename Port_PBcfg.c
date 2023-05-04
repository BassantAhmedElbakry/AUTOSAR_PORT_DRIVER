 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Bassant Ahmed
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
 	 /*******************************************************PORT A****************************************************************************/
     PORTA_ID,     PIN_0_ID,     INPUT_PIN,     U0Rx    ,      OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_1_ID,     OUTPUT_PIN,    U0Tx    ,      OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_2_ID,     INPUT_PIN,     ADC_MODE,      PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTA_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT B****************************************************************************/
     PORTB_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_4_ID,     INPUT_PIN,     AIN10    ,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTB_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT C****************************************************************************/
     PORTC_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTC_ID,     PIN_7_ID,     INPUT_PIN,     WT1CCP1  ,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT D****************************************************************************/
     PORTD_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_6_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTD_ID,     PIN_7_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT E****************************************************************************/
     PORTE_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTE_ID,     PIN_1_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTE_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTE_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTE_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTE_ID,     PIN_5_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
	 /*******************************************************PORT F****************************************************************************/
     PORTF_ID,     PIN_0_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTF_ID,     PIN_1_ID,     OUTPUT_PIN,    GPIO_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTF_ID,     PIN_2_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTF_ID,     PIN_3_ID,     INPUT_PIN,     GPIO_MODE,     OFF,         STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE ,
     PORTF_ID,     PIN_4_ID,     INPUT_PIN,     GPIO_MODE,     PULL_UP,     STD_HIGH,     NON_CHANGEABLE_DIRECTION,     NON_CHANGEABLE_MODE 
                                           
				         };