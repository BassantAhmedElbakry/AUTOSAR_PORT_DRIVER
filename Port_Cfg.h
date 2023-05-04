/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Bassant Ahmed
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                  (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                   (STD_ON)

/* Pre-compile option for Pin Direction Changeable API */
#define PORT_PIN_DIRECTION_CHANGEABLE_API       (STD_ON)

/* Pre-compile option for Pin Mode Changeable API */
#define PORT_PIN_MODE_CHANGEABLE_API            (STD_ON)
   
/*Number of ports*/
#define NUMBER_OF_PORTS           (6U)

/*Number of pins*/
#define PORT_CONFIGURED_PINS            (43U)
 
/*TivaC Ports*/
#define PORTA_ID       (0U)
#define PORTB_ID       (1U)
#define PORTC_ID       (2U)
#define PORTD_ID       (3U)
#define PORTE_ID       (4U)
#define PORTF_ID       (5U)

/*TivaC Pins*/
#define PIN_0_ID          (0U)
#define PIN_1_ID          (1U)
#define PIN_2_ID          (2U)
#define PIN_3_ID          (3U)
#define PIN_4_ID          (4U)
#define PIN_5_ID          (5U)
#define PIN_6_ID          (6U)
#define PIN_7_ID          (7U)
   
/*Unlock the GPIOCR register*/
#define UNLOCKING_MAGIC_NUMBER 0x4C4F434B 
   
/*****************************GROUP_1***********************************/
#define GROUP_1_ID     (1U)
#define U0Rx           (Port_PinModeType)1
#define U0Tx           (Port_PinModeType)1
#define U1RX           (Port_PinModeType)1
#define U1Tx           (Port_PinModeType)1
#define U4Rx           (Port_PinModeType)1
#define U4Tx           (Port_PinModeType)1
#define U3Rx           (Port_PinModeType)1
#define U3Tx           (Port_PinModeType)1
#define SSI3Clk        (Port_PinModeType)1
#define SSI3Fss        (Port_PinModeType)1
#define SSI3Rx         (Port_PinModeType)1
#define SSI3Tx         (Port_PinModeType)1
#define U6Rx           (Port_PinModeType)1
#define U6Tx           (Port_PinModeType)1
#define U2Rx           (Port_PinModeType)1
#define U2Tx           (Port_PinModeType)1
#define U7Rx           (Port_PinModeType)1
#define U7Tx           (Port_PinModeType)1
#define U5Rx           (Port_PinModeType)1
#define U5Tx           (Port_PinModeType)1
#define U1RTS          (Port_PinModeType)1
#define U1CTS          (Port_PinModeType)1

/*****************************GROUP_2***********************************/
#define GROUP_2_ID     (2U)
#define SSI0Clk        (Port_PinModeType)2
#define SSI0Fss        (Port_PinModeType)2
#define SSI0Rx         (Port_PinModeType)2
#define SSI0Tx         (Port_PinModeType)2
#define SSI2Clk        (Port_PinModeType)2
#define SSI2Fss        (Port_PinModeType)2
#define SSI2Rx         (Port_PinModeType)2
#define SSI2Tx         (Port_PinModeType)2
#define U1Rx_PC4       (Port_PinModeType)2
#define U1Tx_PC5       (Port_PinModeType)2
#define SSI1Clk        (Port_PinModeType)2
#define SSI1Fss        (Port_PinModeType)2
#define SSI1Rx         (Port_PinModeType)2
#define SSI1Tx         (Port_PinModeType)2
#define SSI1Rx         (Port_PinModeType)2
#define SSI1Tx         (Port_PinModeType)2
#define SSI1Clk        (Port_PinModeType)2
#define SSI1Fss        (Port_PinModeType)2

/*****************************GROUP_3***********************************/
#define GROUP_3_ID     (3U)
#define I2C1SCL        (Port_PinModeType)3
#define I2C1SDA        (Port_PinModeType)3
#define I2C0SCL        (Port_PinModeType)3
#define I2C0SDA        (Port_PinModeType)3
#define I2C3SCL        (Port_PinModeType)3
#define I2C3SDA        (Port_PinModeType)3
#define I2C2SCL        (Port_PinModeType)3
#define I2C2SDA        (Port_PinModeType)3
#define CAN0Rx         (Port_PinModeType)3
#define CAN0Tx         (Port_PinModeType)3

/*****************************GROUP_4***********************************/
#define GROUP_4_ID                              (4U)
#define M0PWM3                             (Port_PinModeType)4
#define M0PWM0                             (Port_PinModeType)4
#define M0PWM1                             (Port_PinModeType)4
#define M0PWM6                             (Port_PinModeType)4
#define M0PWM7                             (Port_PinModeType)4
#define M0PWM6                             (Port_PinModeType)4
#define M0PWM7                             (Port_PinModeType)4
#define M0FAULT0                           (Port_PinModeType)4
#define M0FAULT0                           (Port_PinModeType)4
#define M0PWM4                             (Port_PinModeType)4
#define M0PWM5                             (Port_PinModeType)4
#define M0FAULT0                           (Port_PinModeType)4

/*****************************GROUP_5***********************************/
#define GROUP_5_ID                              (5U)
#define M1PWM2                             (Port_PinModeType)5
#define M1PWM3                             (Port_PinModeType)5
#define M1PWM0                             (Port_PinModeType)5
#define M1PWM1                             (Port_PinModeType)5
#define M1PWM2                             (Port_PinModeType)5
#define M1PWM3                             (Port_PinModeType)5
#define M1PWM4                             (Port_PinModeType)5
#define M1PWM5                             (Port_PinModeType)5
#define M1PWM6                             (Port_PinModeType)5
#define M1PWM7                             (Port_PinModeType)5
#define M1FAULT0                           (Port_PinModeType)5

/*****************************GROUP_6***********************************/
#define GROUP_6_ID                              (6U)
#define IDX1                               (Port_PinModeType)6
#define PhA1                               (Port_PinModeType)6
#define PhB1                               (Port_PinModeType)6
#define IDX0                               (Port_PinModeType)6
#define PhA0                               (Port_PinModeType)6
#define PhB0                               (Port_PinModeType)6

/****************************GROUP_7***********************************/
#define GROUP_7_ID                              (7U)
#define T2CCP1                             (Port_PinModeType)7
#define T3CCP0                             (Port_PinModeType)7
#define T3CCP1                             (Port_PinModeType)7
#define T1CCP0                             (Port_PinModeType)7
#define T1CCP1                             (Port_PinModeType)7
#define T0CCP0                             (Port_PinModeType)7
#define T0CCP1                             (Port_PinModeType)7
#define WT0CCP0                            (Port_PinModeType)7
#define WT0CCP1                            (Port_PinModeType)7
#define WT1CCP0                            (Port_PinModeType)7
#define WT1CCP1                            (Port_PinModeType)7
#define WT2CCP0                            (Port_PinModeType)7
#define WT2CCP1                            (Port_PinModeType)7
#define WT3CCP0                            (Port_PinModeType)7
#define WT3CCP1                            (Port_PinModeType)7
#define WT4CCP0                            (Port_PinModeType)7
#define WT4CCP1                            (Port_PinModeType)7
#define WT5CCP0                            (Port_PinModeType)7
#define WT5CCP1                            (Port_PinModeType)7
#define T0CCP0                             (Port_PinModeType)7
#define T0CCP1                             (Port_PinModeType)7
#define T1CCP0                             (Port_PinModeType)7
#define T1CCP1                             (Port_PinModeType)7
#define T2CCP0                             (Port_PinModeType)7

/****************************GROUP_8***********************************/
#define GROUP_8_ID                              (8U)
#define CAN1Rx_MODE                             (Port_PinModeType)8
#define CAN1Tx_MODE                             (Port_PinModeType)8
#define CAN0Rx_PB4_MODE                         (Port_PinModeType)8
#define CAN0Tx_PB5_MODE                         (Port_PinModeType)8
#define U1RTS_PC4_MODE                          (Port_PinModeType)8
#define U1CTS_PC5_MODE                          (Port_PinModeType)8
#define USB0EPEN_MODE                           (Port_PinModeType)8
#define USB0PFLT_MODE                           (Port_PinModeType)8
#define NMI_MODE                                (Port_PinModeType)8
#define CAN0Rx_PE4_MODE                         (Port_PinModeType)8
#define CAN0Tx_PE5_MODE                         (Port_PinModeType)8
#define USB0EPEN_MODE                           (Port_PinModeType)8

/****************************GROUP_9***********************************/
#define GROUP_9_ID                              (9U)
#define C0o                                     (Port_PinModeType)9
#define C1o                                     (Port_PinModeType)9

/****************************GROUP_10***********************************/
#define GROUP_10_ID                             (10U)                                                                                                              
#define TRD1                              (Port_PinModeType)10                                                                                                    
#define AIN10                             (Port_PinModeType)10                                                                                                    
#define AIN11                             (Port_PinModeType)10                                                                                                    
#define AIN7                              (Port_PinModeType)10                                                                                                     
#define AIN6                              (Port_PinModeType)10                                                                                                     
#define AIN5                              (Port_PinModeType)10                                                                                                     
#define AIN4                              (Port_PinModeType)10                                                                                                     
#define AIN3                              (Port_PinModeType)10                                                                                                     
#define AIN2                              (Port_PinModeType)10                                                                                                     
#define AIN1                              (Port_PinModeType)10                                                                                                     
#define AIN0                              (Port_PinModeType)10                                                                                                     
#define AIN9                              (Port_PinModeType)10                                                                                                     
#define AIN8                              (Port_PinModeType)10                                                                                                     
                                                                                                                                                                   

/****************************GROUP_11***********************************/
#define GROUP_11_ID                        (11U)
#define C1_NEGATIVE                        (Port_PinModeType)11
#define C1_POSITIVE                        (Port_PinModeType)11
#define C0_POSITIVE                        (Port_PinModeType)11
#define C0_NEGATIVE                        (Port_PinModeType)11
/****************************GROUP_12***********************************/
#define GROUP_12_ID                        (12U)
#define USB0DM                             (Port_PinModeType)12
#define USB0DP                             (Port_PinModeType)12
#define USB0ID                             (Port_PinModeType)12
#define USB0VBUS                           (Port_PinModeType)12

/****************************GROUP_14***********************************/
#define GROUP_14_ID                        (14U)
#define TRD1_PF1                           (Port_PinModeType)14
#define TRD0                               (Port_PinModeType)14
#define TRCLK                              (Port_PinModeType)14

/****************************SPECIAL GROUPS****************************/
#define GPIO_MODE 		 		(Port_PinModeType)0
#define ADC_MODE 		 		(Port_PinModeType)10
#define ANALOG_COMPARATOR_MODE 		 	(Port_PinModeType)11
#define ANALOG_MODE 		 		(Port_PinModeType)12

#endif /* PORT_CFG_H */