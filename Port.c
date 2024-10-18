 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Adel
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR version compliance check statement between Det & Port header files */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of the Det.h header source file does not comply with the current module version"
#endif

/* Software version compliance check statement between Det & Port header files */
#if ((DET_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (DET_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (DET_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of the Det.h header source file does not comply with the current module version"
#endif

#endif /* PORT_DEV_ERROR_DETECT Check */

STATIC const Port_ConfigPortPin * g_ConfPortPin = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

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
){
    /* Point to the required Port Registers base address */
    volatile uint32 * Port_Ptr = NULL_PTR;
    uint8 PortPinIndex = 0;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the input configuration pointer is not a NULL_PTR */
    if(ConfigPtr == NULL_PTR)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_INIT_SID,
                        PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {
        g_ConfPortPin = ConfigPtr->PortPin;
        for(PortPinIndex = 0; PortPinIndex < PORT_CONFIGURED_PORT_PINS; PortPinIndex++)
        {
            switch(g_ConfPortPin[PortPinIndex].port_num)
            {
                case PORT_A:
                    /* PORTA Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTA_BASE_ADDRESS);
                    break;
                case PORT_B:
                    /* PORTB Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTB_BASE_ADDRESS);
                    break;
                case PORT_C:
                    /* PORTC Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTC_BASE_ADDRESS);
                    break;
                case PORT_D:
                    /* PORTD Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTD_BASE_ADDRESS);
                    break;
                case PORT_E:
                    /* PORTE Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTE_BASE_ADDRESS);
                    break;
                case PORT_F:
                    /* PORTF Base Address */
                    Port_Ptr = ((volatile uint32 *)GPIO_PORTF_BASE_ADDRESS);
                    break;
            }
            /* PD7 or PF0 */
            if(   ((g_ConfPortPin[PortPinIndex].port_num == PORT_D) && (g_ConfPortPin[PortPinIndex].pin_num == PIN_7 ))
            ||    ((g_ConfPortPin[PortPinIndex].port_num == PORT_F) && (g_ConfPortPin[PortPinIndex].pin_num == PIN_0 )))
            {
                /* Unlock the GPIOCR register */
                (*((volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET))) = GPIO_ACCESS_CODE;
                /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
            }
            else if((g_ConfPortPin[PortPinIndex].port_num == PORT_C) && (g_ConfPortPin[PortPinIndex].pin_num <= PIN_3))
            {
                /* Do Nothing ...  this is the JTAG pins */
            }
            else
            {
                /* Do Nothing ... No need to unlock the commit register for this pin */
            }

            if(g_ConfPortPin[PortPinIndex].direction == PORT_PIN_OUT)
            {
                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                if(g_ConfPortPin[PortPinIndex].initial_value == STD_HIGH)
                {
                    /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                }
                else
                {
                    /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                }
            }
            else if(g_ConfPortPin[PortPinIndex].direction == PORT_PIN_IN)
            {
                /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                CLEAR_BIT((*(volatile uint32*)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                if(g_ConfPortPin[PortPinIndex].resistor == PULL_UP)
                {
                    /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                }
                else if(g_ConfPortPin[PortPinIndex].resistor == PULL_DOWN)
                {
                    /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                }
                else
                {
                    /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                }
            }
            else
            {
                /* Do Nothing */
            }

            switch(g_ConfPortPin[PortPinIndex].mode)
            {
                /* Setup the pin mode as ADC */
                case PORT_PIN_MODE_ADC:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as CAN */
                case PORT_PIN_MODE_CAN:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Determine the corresponding Port Index assignment */
                    if((g_ConfPortPin[PortPinIndex].port_num == PORT_A)
                     ||(g_ConfPortPin[PortPinIndex].port_num == PORT_B)
                     ||(g_ConfPortPin[PortPinIndex].port_num == PORT_E))
                    {
                        /* Set the PMCx bits for this pin with the CAN functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x08) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    }
                    /* Determine the corresponding Port Index assignment */
                    else if(g_ConfPortPin[PortPinIndex].port_num == PORT_F)
                    {
                        /* Set the PMCx bits for this pin with the CAN functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x03) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    }else { /* Invalid PORT Index assignment */ }
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as GPIO */
                case PORT_PIN_MODE_DIO:
                    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~(0x0000000F << (g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as M0PWM */
                case PORT_PIN_MODE_M0PWM:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the M0PWM functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x04) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as M1PWM */
                case PORT_PIN_MODE_M1PWM:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the M1PWM functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x05) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as GPT or ICU */
                case PORT_PIN_MODE_GPT:
                case PORT_PIN_MODE_ICU:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the GPT or ICU functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x07) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as UART or SSI3 */
                case PORT_PIN_MODE_UART:
                case PORT_PIN_MODE_SSI3:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x00000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the UART or SSI3 functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x01) << ((g_ConfPortPin[PortPinIndex].pin_num ) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as SSI0 or SSI1 or SSI2 */
                case PORT_PIN_MODE_SSI0:
                case PORT_PIN_MODE_SSI1:
                case PORT_PIN_MODE_SSI2:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the SSI0 or SSI1 or SSI2 functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x02) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as TWI */
                case PORT_PIN_MODE_TWI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the TWI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x03) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as Analog comparator */
                case PORT_PIN_MODE_ANALOG_COMP:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Determine the corresponding Port Index assignment */
                    if(g_ConfPortPin[PortPinIndex].port_num == PORT_F)
                    {
                        /* Set the PMCx bits for this pin with the Analog comparator functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x09) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    }else { /* Do Nothing */ }
                    /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as NMI */
                case PORT_PIN_MODE_NMI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the NMI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x08) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as QEI */
                case PORT_PIN_MODE_QEI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the QEI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x06) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
                /* Setup the pin mode as CORE */
                case PORT_PIN_MODE_CORE:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the CORE functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x0E) << ((g_ConfPortPin[PortPinIndex].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    break;
            }
        }
        Port_Status = PORT_INITIALIZED;
    }
}

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
* Description: Sets the port pin direction during runtime.
********************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(
        Port_PinType          Pin,
        Port_PinDirectionType Direction
){
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Port Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID,
                        PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    /* Check if the used port pin is within the valid range */
    if(Pin >= PORT_CONFIGURED_PORT_PINS)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID,
                        PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    /* Check if the used port pin direction is configurable during runtime */
    if(g_ConfPortPin[Pin].change_port_pin_direction_runtime == STD_ON)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID,
                        PORT_E_DIRECTION_UNCHANGEABLE);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
#endif
    /* In-case there are no errors */
    if(error == FALSE)
    {
        /* Safety check on the JTAG pins to avoid interfering with the JTAG interface */
        if(!((g_ConfPortPin[Pin].port_num == PORT_C) && (g_ConfPortPin[Pin].pin_num <= PIN_3)))
        {
            /* Point to the correct PORT base register address according to the Port Id stored in the port_num member */
            switch(g_ConfPortPin[Pin].port_num)
            {
                case PORT_A:
                    /* PORTA Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
                    break;
                case PORT_B:
                    /* PORTB Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
                    break;
                case PORT_C:
                    /* PORTC Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
                    break;
                case PORT_D:
                    /* PORTD Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
                    break;
                case PORT_E:
                    /* PORTE Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
                    break;
                case PORT_F:
                    /* PORTF Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
                    break;
            }
            if(Direction == PORT_PIN_IN)
            {
                /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
            }
            else if(Direction == PORT_PIN_OUT)
            {
                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* JTAG Pins access and modification is strictly prohibited, previous API request is nullified */
        }
    }
    else
    {
        /* Do Nothing */
    }
}
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
){
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error = FALSE;
    uint8 PortPinIndex = 0;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Port Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_REFRESH_PORT_DIRECTION_SID,
                        PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
#endif
    /* In-case there are no errors */
    if(error == FALSE)
    {
        for(PortPinIndex = 0; PortPinIndex <= PORT_CONFIGURED_PORT_PINS; PortPinIndex++)
        {
            /* Safety check on the JTAG pins to avoid interfering with the JTAG interface */
            if(!((PortPinIndex >= PortConf_PORT_C_PIN_0_ID_INDEX) && (PortPinIndex <= PortConf_PORT_C_PIN_3_ID_INDEX)))
            {
                /* Check if runtime direction configuration is permitted or not */
                if(g_ConfPortPin[PortPinIndex].change_port_pin_direction_runtime == STD_OFF)
                {
                    /* Point to the correct PORT base register address according to the Port Id stored in the port_num member */
                    switch(g_ConfPortPin[PortPinIndex].port_num)
                    {
                        case PORT_A:
                            /* PORTA Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
                            break;
                        case PORT_B:
                            /* PORTB Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
                            break;
                        case PORT_C:
                            /* PORTC Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
                            break;
                        case PORT_D:
                            /* PORTD Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
                            break;
                        case PORT_E:
                            /* PORTE Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
                            break;
                        case PORT_F:
                            /* PORTF Base Address */
                            Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
                            break;
                    }
                    /* Check if the port pin index is configured as input within the post build configuration array of structures */
                    if(g_ConfPortPin[PortPinIndex].direction == PORT_PIN_IN)
                    {
                        /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                        CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    }
                    /* Check if the port pin index is configured as output within the post build configuration array of structures */
                    else if(g_ConfPortPin[PortPinIndex].direction == PORT_PIN_OUT)
                    {
                        /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                        SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET)), g_ConfPortPin[PortPinIndex].pin_num);
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
                else
                {
                    /* Do Nothing, the corresponding port pin directional runtime configuration is changeable */
                }
            }
            else
            {
                /* JTAG Pins access and modification is strictly prohibited, previous loop iteration is skipped */
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
}

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
){
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(versioninfo == NULL_PTR)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_GET_VERSION_INFO_SID,
                        PORT_E_PARAM_POINTER);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    if(error == FALSE)
#endif
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = ((uint16)PORT_VENDOR_ID);
        /* Copy the module Id */
        versioninfo->moduleID = ((uint16)PORT_MODULE_ID);
        /* Copy Software Major Version */
        versioninfo->sw_major_version = ((uint8)PORT_SW_MAJOR_VERSION);
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = ((uint8)PORT_SW_MINOR_VERSION);
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = ((uint8)PORT_SW_PATCH_VERSION);
    }
}
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
){
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error = FALSE;

#if(PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Port Driver is initialized before using this function */
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID,
                        PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    /* Check if the argument Pin is within the valid range */
    if(Pin >= PORT_CONFIGURED_PORT_PINS)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID,
                        PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    /* Check if the argument Mode is within the valid range */
    if(Mode > PORT_PIN_MODE_CORE)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID,
                        PORT_E_PARAM_INVALID_MODE);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    /* Check if the used port pin mode is configurable during runtime */
    if(g_ConfPortPin[Pin].change_port_pin_mode_runtime == STD_OFF)
    {
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID,
                        PORT_E_MODE_UNCHANGEABLE);
        error = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
#endif
    if(error == FALSE)
    {
        /* Safety check on the JTAG pins to avoid interfering with the JTAG interface */
        if(!((g_ConfPortPin[Pin].port_num == PORT_C) && (g_ConfPortPin[Pin].pin_num <= PIN_3)))
        {
            /* Point to the correct PORT base register address according to the Port Id stored in the port_num member */
            switch(g_ConfPortPin[Pin].port_num)
            {
                case PORT_A:
                    /* PORTA Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
                    break;
                case PORT_B:
                    /* PORTB Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
                    break;
                case PORT_C:
                    /* PORTC Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
                    break;
                case PORT_D:
                    /* PORTD Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
                    break;
                case PORT_E:
                    /* PORTE Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
                    break;
                case PORT_F:
                    /* PORTF Base Address */
                    Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
                    break;
            }
            /* Select the correct mode to be assigned to port pin */
            switch(Mode)
            {
                /* Setup the pin mode as ADC */
                case PORT_PIN_MODE_ADC:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as CAN */
                case PORT_PIN_MODE_CAN:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Determine the corresponding Port Index assignment */
                    if((g_ConfPortPin[Pin].port_num == PORT_A)
                     ||(g_ConfPortPin[Pin].port_num == PORT_B)
                     ||(g_ConfPortPin[Pin].port_num == PORT_E))
                    {
                        /* Set the PMCx bits for this pin with the CAN functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x08) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    }
                    /* Determine the corresponding Port Index assignment */
                    else if(g_ConfPortPin[Pin].port_num == PORT_F)
                    {
                        /* Set the PMCx bits for this pin with the CAN functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x03) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    }else { /* Invalid PORT Index assignment */ }
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as GPIO */
                case PORT_PIN_MODE_DIO:
                    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~(0x0000000F << (g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as M0PWM */
                case PORT_PIN_MODE_M0PWM:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the M0PWM functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x04) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as M1PWM */
                case PORT_PIN_MODE_M1PWM:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the M1PWM functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x05) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as GPT or ICU */
                case PORT_PIN_MODE_GPT:
                case PORT_PIN_MODE_ICU:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the GPT or ICU functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x07) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as UART or SSI3 */
                case PORT_PIN_MODE_UART:
                case PORT_PIN_MODE_SSI3:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x00000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the UART or SSI3 functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x01) << ((g_ConfPortPin[Pin].pin_num ) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as SSI0 or SSI1 or SSI2 */
                case PORT_PIN_MODE_SSI0:
                case PORT_PIN_MODE_SSI1:
                case PORT_PIN_MODE_SSI2:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the SSI0 or SSI1 or SSI2 functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x02) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as TWI */
                case PORT_PIN_MODE_TWI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the TWI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x03) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as Analog comparator */
                case PORT_PIN_MODE_ANALOG_COMP:
                    /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Determine the corresponding Port Index assignment */
                    if(g_ConfPortPin[Pin].port_num == PORT_F)
                    {
                        /* Set the PMCx bits for this pin with the Analog comparator functionality */
                        (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x09) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    }else { /* Do Nothing */ }
                    /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as NMI */
                case PORT_PIN_MODE_NMI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the NMI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x08) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as QEI */
                case PORT_PIN_MODE_QEI:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the QEI functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x06) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
                /* Setup the pin mode as CORE */
                case PORT_PIN_MODE_CORE:
                    /* Set Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    /* Clear the PMCx bits for this pin */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= (~((0x0000000F) << ((g_ConfPortPin[Pin].pin_num) * 4)));
                    /* Set the PMCx bits for this pin with the CORE functionality */
                    (*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) |= ((0x0E) << ((g_ConfPortPin[Pin].pin_num) * 4));
                    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET)), g_ConfPortPin[Pin].pin_num);
                    break;
            }
        }
        else
        {
            /* JTAG Pins access and modification is strictly prohibited, previous API request is nullified */
        }
    }
    else
    {
        /* Do Nothing */
    }
}
#endif
