 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Bassant Ahmed
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"
#include "tm4c123gh6pm_registers.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif


/*Hold the pointer of port_configtype*/
STATIC const Port_ConfigPin * Port_Pins = NULL_PTR;

/*Check the status of the port if initialized or not */
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

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
void Port_Init(const Port_ConfigType* ConfigPtr){
  
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
	}
	else
#endif
        {
          /*Initialize the port driver*/
          Port_Status  = PORT_INITIALIZED;
          /*Address of the first pin structure */
          Port_Pins = ConfigPtr->Port_Pins;
                
         /* for loop for looping on all pins */
           for (Port_PinType pin_id = 0 ; pin_id < PORT_CONFIGURED_PINS ; pin_id++){
              volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
              volatile uint32 delay = 0;
              
   /*PORT NUMBER*/ 
    switch(Port_Pins[pin_id].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<Port_Pins[pin_id].port_num);
    delay = SYSCTL_REGCGC2_REG;
    
    if( ((Port_Pins[pin_id].port_num == PORTD_ID) && (Port_Pins[pin_id].pin_num == PIN_7_ID)) || ((Port_Pins[pin_id].port_num == PORTF_ID) && (Port_Pins[pin_id].pin_num == PIN_0_ID)) ) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = UNLOCKING_MAGIC_NUMBER;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[pin_id].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (Port_Pins[pin_id].port_num == PORTC_ID) && (Port_Pins[pin_id].pin_num <= PIN_3_ID) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[pin_id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[pin_id].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[pin_id].pin_num * LOCATIONS_VALUE));     /* Clear the PMCx bits for this pin */
    
    if(Port_Pins[pin_id].direction == OUTPUT_PIN)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[pin_id].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(Port_Pins[pin_id].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[pin_id].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[pin_id].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(Port_Pins[pin_id].direction == INPUT_PIN)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[pin_id].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(Port_Pins[pin_id].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[pin_id].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(Port_Pins[pin_id].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[pin_id].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[pin_id].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[pin_id].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    else
    {
        /* Do Nothing */
    }
    
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[pin_id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
   }
       }
}

#if (PORT_PIN_DIRECTION_CHANGEABLE_API == STD_ON)
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
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Check if the Driver is initialized before using this function */
		if(Port_Status == PORT_NOT_INITIALIZED)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		}
		else
		{	
                  /* Do Nothing */	
                }

		/* check if incorrect Port Pin ID passed */
		if(Pin >= PORT_CONFIGURED_PINS)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		}
		else
		{	/* Do Nothing */	}

		/* check if Port Pin not configured as changeable */
		if(Port_Pins[Pin].Port_PinChangeableDirection == STD_OFF)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
		}
		else
		{	
                  /* Do Nothing */	
                }
#endif
	/* point to the required Port Registers base address */
    volatile uint32 * PortGpio_Ptr = NULL_PTR;
    
    switch(Port_Pins[Pin].port_num)
    {
        case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    if(!((Port_Pins[Pin].port_num == PORTC_ID) && (Pin <= PIN_3_ID)) ) /* PC0 to PC3 */
    {

      if(Direction == OUTPUT_PIN)
      {
    	 /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
      }
      else if(Direction == INPUT_PIN)
      {
    	/* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[Pin].pin_num);
        
      }
      else 
      {
         /* Do Nothing */
      }
    }
    else
    {
        /* Do Nothing */
    }
    
}
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
void Port_RefreshPortDirection( void ){
  /* point to the required Port Registers base address */
  volatile uint32 *PortGpio_Ptr = NULL_PTR;
  
    /*Det Error */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* check if the input configuration pointer is not a NULL_PTR */
  if (Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
  }
  else 
  {
     /* Do Nothing */
  }
  
#endif

  for(Port_PinType pin_id = 0; pin_id < PORT_CONFIGURED_PINS; pin_id++)
  {

    switch(Port_Pins[pin_id].port_num )
    {
    	case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
    	break;
    	case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
    	break;
    	case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
    	break;
    	case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
    	break;
    	case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
    	break;
    	case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
    	break;
    }



    if( !((Port_Pins[pin_id].port_num == PORTC_ID) && (Port_Pins[pin_id].pin_num <= PIN_3_ID)) ) /* PC0 to PC3 */
    {
       if (Port_Pins[pin_id].Port_PinChangeableDirection == NON_CHANGEABLE_DIRECTION)
       {
        if(Port_Pins[pin_id].direction== OUTPUT_PIN)
        {
          /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[pin_id].pin_num);
         }
        else if(Port_Pins[pin_id].direction== INPUT_PIN)
        {
          /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[pin_id].pin_num);
        }
      else
      {
        /* Do Nothing */
      }
    }
    }
    else
    {
      /* Do Nothing ... JTAG Pins */
    }
   
  }
}

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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
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
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode ){
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Check if the Driver is initialized before using this function */
		if(Port_Status == PORT_NOT_INITIALIZED)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		}
		else
		{	
                    /* Do Nothing */	
                }

		/* check if incorrect Port Pin ID passed */
		if(Pin >= PORT_CONFIGURED_PINS)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		}
		else
		{	
                    /* Do Nothing */
                }
                
		/* check if the API called when the mode is unchangeable */
		if(Port_Pins[Pin].Port_PinChangeableMode == NON_CHANGEABLE_MODE)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		}
		else
		{	
                    /* Do Nothing */	
                }
                if (!(Mode<=GROUP_12_ID || Mode==GROUP_14_ID))
                {
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
                }
                else 
                {
                  /* Do Nothing */
                }
	#endif
                /* point to the required Port Registers base address */
		 volatile uint32 * PortGpio_Ptr = NULL_PTR; 
                
		 switch(Port_Pins[Pin].port_num)
		 	{
		 		case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 		 break;
		 		case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 		 break;
		 		case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 		 break;
		 		case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 		 break;
		 		case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 		 break;
		 		case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 		 break;
		 	}
                            /*Condition for JTAG pins to protection from changeing their mode */
                  if( !((Port_Pins[Pin].port_num == PORTC_ID) && (Port_Pins[Pin].pin_num <= PIN_3_ID)) ) /* PC0 to PC3 */
			   {
                             
		       if (Mode== GPIO_MODE)
			    {
                                   
                      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) ,Port_Pins[Pin].pin_num);
			 
                        /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
		      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
			  
                      /* Clear the PMCx bits for this pin */
		       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
		     
                       /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
		      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
                      
			   }
                       
		    else if ((Mode == ADC_MODE) || (Mode==ANALOG_COMPARATOR_MODE) || (Mode==ANALOG_MODE))
                      {
                        
		     /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
		   SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                   /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,Port_Pins[Pin].pin_num);
		
                  /* Clear the PMCx bits for this pin */
                   *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(MASK << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE)); 
		
                  /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Port_Pins[Pin].pin_num);
                       }
                       
		  else
		       {
                         
		 /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
		  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                  /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[Pin].pin_num);
			
                    /* Set the PMCx bits for this pin */
		    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)Port_Pins[Pin].Port_PinMode << (Port_Pins[Pin].pin_num * LOCATIONS_VALUE));
			
                     /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
		    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[Pin].pin_num);
		
                       }

                      }
                 else
              {
	         /* Do Nothing ... No need to unlock the commit register for this pin */
               }
	
}
#endif