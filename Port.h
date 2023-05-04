 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Bassant Ahmed
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (120U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != POTR_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for PORT Init */
#define PORT_INIT_SID                        (uint8)0x00

/* Service ID for PORT Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID           (uint8)0x01 
   
/* Service ID for Port Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID      (uint8)0x02
   
/* Service ID for PORT Get Version Info */
#define PORT_GET_VERSION_INFO_SID            (uint8)0x03
   
/* Service ID for PORT Set Pin Mode  */
#define PORT_SET_PIN_MODE_SID                (uint8)0x04
   
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
   
/* DET code to report Invalid Port Pin */
#define PORT_E_PARAM_PIN                     (uint8)0x0A  
   
/* DET code to report that Port Pin not configured as changeable  */
#define PORT_E_DIRECTION_UNCHANGEABLE        (uint8)0x0B
   
/* DET code to report that API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                  (uint8)0x0C
 
/* DET code to report Invalid Mode */
#define PORT_E_PARAM_INVALID_MODE            (uint8)0x0D   

/* DET code to report Invalid Unchangeable Mode */
#define PORT_E_MODE_UNCHANGEABLE             (uint8)0x0E
   
/* API service called without module initialization */
#define PORT_E_UNINIT                        (uint8)0x0F
   
/* DET code to report that APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                 (uint8)0x10
  
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Data type for the symbolic name of a port pin*/   
typedef uint8 Port_PinType;

/*Different port pin modes*/
typedef uint8 Port_PinModeType;

/*Type definition for port_pinlevelType used by the port APIs*/
typedef uint8 Port_PinLevelType;

/*Type definition for Port_PortType used by the port APIs*/
typedef uint8 Port_PortType;

/*Pin direction changeable during runtime(STD_ON/STD_OFF) – this port pin configuration is MCU dependent*/
typedef enum {
	NON_CHANGEABLE_DIRECTION,CHANGEABLE_DIRECTION
}Port_PinChangeableDirection;
/*Pin mode changeable during runtime (STD_ON/STD_OFF)– configuration is MCU dependent*/
typedef enum {
	NON_CHANGEABLE_MODE,CHANGEABLE_MODE
}Port_PinChangeableMode;

/*Possible directions of a port pin*/
typedef enum
{
    INPUT_PIN,OUTPUT_PIN
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the pin mode.
 *      5. the internal resistor --> Disable, Pull up or Pull down
 *      6. the initial value of the port pin.
 *      7. Pin direction changeable during runtime (STD_ON/STD_OFF)  
 *      8. Pin mode changeable during runtime (STD_ON/STD_OFF) 
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirectionType direction;
    Port_PinModeType Port_PinMode;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinChangeableDirection Port_PinChangeableDirection;
    Port_PinChangeableMode  Port_PinChangeableMode;
}Port_ConfigPin;

/*Structure required for initializing the port driver */
typedef struct 
{
	Port_ConfigPin Port_Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/*****************************************************************************************
 *                                External Variables                                    *
 *****************************************************************************************/

/*Extern Pos-build structures to be used by port.c and other modules*/
extern const Port_ConfigType Port_Configuration;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

#if (PORT_PIN_DIRECTION_CHANGEABLE_SID == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin: Port Pin ID number
*                  Direction: Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction 
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction); 
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void );

#if (PORT_VERSION_INFO_API  == STD_ON)
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo: Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module. 
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ); 
#endif

#if (PORT_PIN_MODE_CHANGEABLE_API == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin: Port Pin ID number
*                Mode: New Port Pin mode to be set on port pin. 
* Parameters (inout): None
* Parameters (out): versioninfo: Pointer to where to store the version information of this module.
* Return value: None
* Description: New Port Pin mode to be set on port pin. 
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode ); 
#endif

#endif /* PORT_H */
