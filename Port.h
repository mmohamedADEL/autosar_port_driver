 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Adel
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in AUTOSAR */
#define PORT_VENDOR_ID                           (1997U)

/* Id for the module in AUTOSAR */
#define PORT_MODULE_ID                           (124U)

/* Module Instance Id */
#define PORT_INSTANCE_ID                         (0U)

/*
 * Module Version  1.0.0
 */
#define PORT_SW_MAJOR_VERSION                    (1U)
#define PORT_SW_MINOR_VERSION                    (0U)
#define PORT_SW_PATCH_VERSION                    (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION            (4U)
#define PORT_AR_RELEASE_MINOR_VERSION            (0U)
#define PORT_AR_RELEASE_PATCH_VERSION            (3U)

/*
 * Definitions for Port Status
 */
#define PORT_INITIALIZED                         (1U)
#define PORT_NOT_INITIALIZED                     (0U)

/* AUTOSAR Standard Types header file */
#include "Std_Types.h"
/* AUTOSAR version compliance check statement between Port & Standard_Types header files */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of the Std_Types.h header source file does not comply with the current module version"
#endif

/* AUTOSAR Port Pre-compile Configuration header file */
#include "Port_Cfg.h"
/* AUTOSAR version compliance check statement between Port & Port_Cfg header files */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of the Port_Cfg.h header source file does not comply with the current module version"
#endif

/* Software version compliance check statement between Port & Port_Cfg header files */
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
 ||  (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
 ||  (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
  #error "The SW version of the Port_Cfg.h header source file does not comply with the current module version"
#endif

/* Non AUTOSAR file */
#include "Common_Macros.h"

/******************************************************************************
 *                          API Service Id Macros                             *
 ******************************************************************************/

/* Service Id for Port Init */
#define PORT_INIT_SID                            ((uint8)0x00)

/* Service Id for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID               ((uint8)0x01)

/* Service Id for Port Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID          ((uint8)0x02)

/* Service Id for Port Get Version Info */
#define PORT_GET_VERSION_INFO_SID                ((uint8)0x03)

/* Service Id for Port Set Pin Mode */
#define PORT_SET_PIN_MODE_SID                    ((uint8)0x04)

/*******************************************************************************
 *                             DET Error Codes                                 *
 *******************************************************************************/

/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                         ((uint8)0x0A)

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE            ((uint8)0x0B)

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                      ((uint8)0x0C)

/* API Port_SetPinMode service called with an invalid mode */
#define PORT_E_PARAM_INVALID_MODE                ((uint8)0x0D)

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE                 ((uint8)0x0E)

/* API service called without module initialization */
#define PORT_E_UNINIT                            ((uint8)0x0F)

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                     ((uint8)0x10)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*
 * Data type for the symbolic name of a port pin.
 * Shall cover all available port pins. 0 - <number of port pins:>
 */
typedef uint8 Port_PinType;

/*
 * Data type of enum responsible for the possible directions of a port pin.
 */
typedef enum{
    PORT_PIN_IN,
    PORT_PIN_OUT
}Port_PinDirectionType;

/*
 * Data type for the symbolic name of different port pin modes.
 * It shall be used with the function call Port_SetPinMode
 */
typedef uint8 Port_PinModeType;

/*
 *  Data type of enum responsible for the activation of internal pull-ups.
 */
typedef enum{
    OFF,
    PULL_UP,
    PULL_DOWN
}Port_InternalResistorType;

typedef enum{
    PORT_PIN_MODE_ADC,
    PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_M0PWM,
    PORT_PIN_MODE_M1PWM,
    PORT_PIN_MODE_GPT,
    PORT_PIN_MODE_ICU,
    PORT_PIN_MODE_UART,
    PORT_PIN_MODE_SSI0,
    PORT_PIN_MODE_SSI1,
    PORT_PIN_MODE_SSI2,
    PORT_PIN_MODE_SSI3,
    PORT_PIN_MODE_TWI,
    PORT_PIN_MODE_ANALOG_COMP,
    PORT_PIN_MODE_NMI,
    PORT_PIN_MODE_QEI,
    PORT_PIN_MODE_CORE
}Port_PortPinInitialModeType;

/*
 * Description: Structure to configure each individual Port Pin:
 *	1. The PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5.
 *	2. The number of the pin in the PORT.
 *	3. Pin mode (e.g. DIO, ADC, SPI …) – this port pin configuration is mandatory unless the port pin is configured for DIO.
 *	4. Pin direction (input, output) – this port pin configuration is mandatory when the port pin is to be used for DIO.
 *	5. Pin level init value – this port pin configuration is mandatory when the port pin is used for DIO.
 *	6. Pin direction changeable during runtime (STD_ON/STD_OFF) – this port pin configuration is MCU dependent.
 *	7. Pin mode changeable during runtime (STD_ON/STD_OFF) – configuration is MCU dependent.
 *  8. The internal resistor --> Disable, Pull up or Pull down.
 *
 */
typedef struct 
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PortPinInitialModeType mode;
    Port_PinDirectionType direction;
    uint8 initial_value;
    uint8 change_port_pin_direction_runtime;
    uint8 change_port_pin_mode_runtime;
    Port_InternalResistorType resistor;
}Port_ConfigPortPin;

/*
 * Data structure which handles the initialization of the Port Driver
 */
typedef struct
{
    Port_ConfigPortPin PortPin[PORT_CONFIGURED_PORT_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/

/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
********************************************************************************/
void Port_Init(
        const Port_ConfigType * ConfigPtr
);

/*******************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction.
********************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(
        Port_PinType          Pin,
        Port_PinDirectionType Direction
);
#endif

/*******************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
********************************************************************************/
void Port_RefreshPortDirection(
        void
);

/*******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version
*                                 information of this module.
* Return value: None
* Description: Returns the version information of this module.
********************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(
        Std_VersionInfoType * versioninfo
);
#endif

/*******************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
********************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(
        Port_PinType     Pin,
        Port_PinModeType Mode
);
#endif

/*******************************************************************************
 *                            External Variables                               *
 *******************************************************************************/

/*
 * External Post build array of type Port_ConfigType structure necessary
 * to handle Port module initialization for itself & other modules
 */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
