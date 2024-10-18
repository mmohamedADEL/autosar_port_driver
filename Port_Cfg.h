 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file
 *              for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohamed Adel
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION                    (1U)
#define PORT_CFG_SW_MINOR_VERSION                    (0U)
#define PORT_CFG_SW_PATCH_VERSION                    (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION            (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION            (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION            (3U)

/*
 * Switches the Development Error Detection and Notification on or off.
 * STD_ON: Enabled.
 * STD_OFF: Disabled.
 */
#define PORT_DEV_ERROR_DETECT                        (STD_ON)

/*
 * Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
 * STD_ON: Enabled - Function Port_SetPinDirection() is available.
 * STD_OFF: Disabled - Function Port_SetPinDirection() is not available.
 */
#define PORT_SET_PIN_DIRECTION_API                   (STD_ON)

/*
 * Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 * STD_ON: Enabled - Function Port_SetPinMode() is available.
 * STD_OFF: Disabled - Function Port_SetPinMode() is not available.
 */
#define PORT_SET_PIN_MODE_API                        (STD_ON)

/*
 * Pre-processor switch to enable / disable the API to read out the modules version information.
 * STD_ON: Version info API enabled.
 * STD_OFF: Version info API disabled.
 */
#define PORT_VERSION_INFO_API                        (STD_ON)

/* The number of Port pins configurations */
#define PORT_CONFIGURED_PORT_PINS                    (39U)

#define GPIO_ACCESS_CODE                             (0x4C4F434BU)

#define PORT_A                                       (0U)
#define PORT_B                                       (1U)
#define PORT_C                                       (2U)
#define PORT_D                                       (3U)
#define PORT_E                                       (4U)
#define PORT_F                                       (5U)

#define PIN_0                                        (0U)
#define PIN_1                                        (1U)
#define PIN_2                                        (2U)
#define PIN_3                                        (3U)
#define PIN_4                                        (4U)
#define PIN_5                                        (5U)
#define PIN_6                                        (6U)
#define PIN_7                                        (7U)

#define PortConf_PORT_A_PIN_0_ID_INDEX               ((uint8)0x00)
#define PortConf_PORT_A_PIN_1_ID_INDEX               ((uint8)0x01)
#define PortConf_PORT_A_PIN_2_ID_INDEX               ((uint8)0x02)
#define PortConf_PORT_A_PIN_3_ID_INDEX               ((uint8)0x03)
#define PortConf_PORT_A_PIN_4_ID_INDEX               ((uint8)0x04)
#define PortConf_PORT_A_PIN_5_ID_INDEX               ((uint8)0x05)
#define PortConf_PORT_A_PIN_6_ID_INDEX               ((uint8)0x06)
#define PortConf_PORT_A_PIN_7_ID_INDEX               ((uint8)0x07)

#define PortConf_PORT_B_PIN_0_ID_INDEX               ((uint8)0x08)
#define PortConf_PORT_B_PIN_1_ID_INDEX               ((uint8)0x09)
#define PortConf_PORT_B_PIN_2_ID_INDEX               ((uint8)0x0A)
#define PortConf_PORT_B_PIN_3_ID_INDEX               ((uint8)0x0B)
#define PortConf_PORT_B_PIN_4_ID_INDEX               ((uint8)0x0C)
#define PortConf_PORT_B_PIN_5_ID_INDEX               ((uint8)0x0D)
#define PortConf_PORT_B_PIN_6_ID_INDEX               ((uint8)0x0E)
#define PortConf_PORT_B_PIN_7_ID_INDEX               ((uint8)0x0F)

#define PortConf_PORT_C_PIN_0_ID_INDEX               ((uint8)0x10)
#define PortConf_PORT_C_PIN_1_ID_INDEX               ((uint8)0x11)
#define PortConf_PORT_C_PIN_2_ID_INDEX               ((uint8)0x12)
#define PortConf_PORT_C_PIN_3_ID_INDEX               ((uint8)0x13)
#define PortConf_PORT_C_PIN_4_ID_INDEX               ((uint8)0x14)
#define PortConf_PORT_C_PIN_5_ID_INDEX               ((uint8)0x15)
#define PortConf_PORT_C_PIN_6_ID_INDEX               ((uint8)0x16)
#define PortConf_PORT_C_PIN_7_ID_INDEX               ((uint8)0x17)

#define PortConf_PORT_D_PIN_0_ID_INDEX               ((uint8)0x18)
#define PortConf_PORT_D_PIN_1_ID_INDEX               ((uint8)0x19)
#define PortConf_PORT_D_PIN_2_ID_INDEX               ((uint8)0x1A)
#define PortConf_PORT_D_PIN_3_ID_INDEX               ((uint8)0x1B)
#define PortConf_PORT_D_PIN_4_ID_INDEX               ((uint8)0x1C)
#define PortConf_PORT_D_PIN_5_ID_INDEX               ((uint8)0x1D)
#define PortConf_PORT_D_PIN_6_ID_INDEX               ((uint8)0x1E)
#define PortConf_PORT_D_PIN_7_ID_INDEX               ((uint8)0x1F)

#define PortConf_PORT_E_PIN_0_ID_INDEX               ((uint8)0x20)
#define PortConf_PORT_E_PIN_1_ID_INDEX               ((uint8)0x21)
#define PortConf_PORT_E_PIN_2_ID_INDEX               ((uint8)0x22)
#define PortConf_PORT_E_PIN_3_ID_INDEX               ((uint8)0x23)
#define PortConf_PORT_E_PIN_4_ID_INDEX               ((uint8)0x24)
#define PortConf_PORT_E_PIN_5_ID_INDEX               ((uint8)0x25)

#define PortConf_PORT_F_PIN_0_ID_INDEX               ((uint8)0x26)
#define PortConf_PORT_F_PIN_1_ID_INDEX               ((uint8)0x27)
#define PortConf_PORT_F_PIN_2_ID_INDEX               ((uint8)0x28)
#define PortConf_PORT_F_PIN_3_ID_INDEX               ((uint8)0x29)
#define PortConf_PORT_F_PIN_4_ID_INDEX               ((uint8)0x2A)

#define PortConf_PORT_A0                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A1                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A2                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A3                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A4                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A5                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A6                             ((uint8)0)                                         /* PORT A */
#define PortConf_PORT_A7                             ((uint8)0)                                         /* PORT A */

#define PortConf_PORT_B0                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B1                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B2                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B3                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B4                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B5                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B6                             ((uint8)1)                                         /* PORT B */
#define PortConf_PORT_B7                             ((uint8)1)                                         /* PORT B */

#define PortConf_PORT_C0                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C1                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C2                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C3                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C4                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C5                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C6                             ((uint8)2)                                         /* PORT C */
#define PortConf_PORT_C7                             ((uint8)2)                                         /* PORT C */

#define PortConf_PORT_D0                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D1                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D2                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D3                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D4                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D5                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D6                             ((uint8)3)                                         /* PORT D */
#define PortConf_PORT_D7                             ((uint8)3)                                         /* PORT D */

#define PortConf_PORT_E0                             ((uint8)4)                                         /* PORT E */
#define PortConf_PORT_E1                             ((uint8)4)                                         /* PORT E */
#define PortConf_PORT_E2                             ((uint8)4)                                         /* PORT E */
#define PortConf_PORT_E3                             ((uint8)4)                                         /* PORT E */
#define PortConf_PORT_E4                             ((uint8)4)                                         /* PORT E */
#define PortConf_PORT_E5                             ((uint8)4)                                         /* PORT E */

#define PortConf_PORT_F0                             ((uint8)5)                                         /* PORT F */
#define PortConf_LED1_PORT_NUM                       ((uint8)5)                                         /* PORT F */
#define PortConf_PORT_F2                             ((uint8)5)                                         /* PORT F */
#define PortConf_PORT_F3                             ((uint8)5)                                         /* PORT F */
#define PortConf_SW1_PORT_NUM                        ((uint8)5)                                         /* PORT F */

#define PortConf_PORTPIN_A0                          ((uint8)0)                                         /* Port Pin 0 in PORT A */
#define PortConf_PORTPIN_A1                          ((uint8)1)                                         /* Port Pin 1 in PORT A */
#define PortConf_PORTPIN_A2                          ((uint8)2)                                         /* Port Pin 2 in PORT A */
#define PortConf_PORTPIN_A3                          ((uint8)3)                                         /* Port Pin 3 in PORT A */
#define PortConf_PORTPIN_A4                          ((uint8)4)                                         /* Port Pin 4 in PORT A */
#define PortConf_PORTPIN_A5                          ((uint8)5)                                         /* Port Pin 5 in PORT A */
#define PortConf_PORTPIN_A6                          ((uint8)6)                                         /* Port Pin 6 in PORT A */
#define PortConf_PORTPIN_A7                          ((uint8)7)                                         /* Port Pin 7 in PORT A */

#define PortConf_PORTPIN_B0                          ((uint8)0)                                         /* Port Pin 0 in PORT B */
#define PortConf_PORTPIN_B1                          ((uint8)1)                                         /* Port Pin 1 in PORT B */
#define PortConf_PORTPIN_B2                          ((uint8)2)                                         /* Port Pin 2 in PORT B */
#define PortConf_PORTPIN_B3                          ((uint8)3)                                         /* Port Pin 3 in PORT B */
#define PortConf_PORTPIN_B4                          ((uint8)4)                                         /* Port Pin 4 in PORT B */
#define PortConf_PORTPIN_B5                          ((uint8)5)                                         /* Port Pin 5 in PORT B */
#define PortConf_PORTPIN_B6                          ((uint8)6)                                         /* Port Pin 6 in PORT B */
#define PortConf_PORTPIN_B7                          ((uint8)7)                                         /* Port Pin 7 in PORT B */

#define PortConf_PORTPIN_C0                          ((uint8)0)                                         /* Port Pin 0 in PORT C */
#define PortConf_PORTPIN_C1                          ((uint8)1)                                         /* Port Pin 1 in PORT C */
#define PortConf_PORTPIN_C2                          ((uint8)2)                                         /* Port Pin 2 in PORT C */
#define PortConf_PORTPIN_C3                          ((uint8)3)                                         /* Port Pin 3 in PORT C */
#define PortConf_PORTPIN_C4                          ((uint8)4)                                         /* Port Pin 4 in PORT C */
#define PortConf_PORTPIN_C5                          ((uint8)5)                                         /* Port Pin 5 in PORT C */
#define PortConf_PORTPIN_C6                          ((uint8)6)                                         /* Port Pin 6 in PORT C */
#define PortConf_PORTPIN_C7                          ((uint8)7)                                         /* Port Pin 7 in PORT C */

#define PortConf_PORTPIN_D0                          ((uint8)0)                                         /* Port Pin 0 in PORT D */
#define PortConf_PORTPIN_D1                          ((uint8)1)                                         /* Port Pin 1 in PORT D */
#define PortConf_PORTPIN_D2                          ((uint8)2)                                         /* Port Pin 2 in PORT D */
#define PortConf_PORTPIN_D3                          ((uint8)3)                                         /* Port Pin 3 in PORT D */
#define PortConf_PORTPIN_D4                          ((uint8)4)                                         /* Port Pin 4 in PORT D */
#define PortConf_PORTPIN_D5                          ((uint8)5)                                         /* Port Pin 5 in PORT D */
#define PortConf_PORTPIN_D6                          ((uint8)6)                                         /* Port Pin 6 in PORT D */
#define PortConf_PORTPIN_D7                          ((uint8)7)                                         /* Port Pin 7 in PORT D */

#define PortConf_PORTPIN_E0                          ((uint8)0)                                         /* Port Pin 0 in PORT E */
#define PortConf_PORTPIN_E1                          ((uint8)1)                                         /* Port Pin 1 in PORT E */
#define PortConf_PORTPIN_E2                          ((uint8)2)                                         /* Port Pin 2 in PORT E */
#define PortConf_PORTPIN_E3                          ((uint8)3)                                         /* Port Pin 3 in PORT E */
#define PortConf_PORTPIN_E4                          ((uint8)4)                                         /* Port Pin 4 in PORT E */
#define PortConf_PORTPIN_E5                          ((uint8)5)                                         /* Port Pin 5 in PORT E */

#define PortConf_PORTPIN_F0                          ((uint8)0)                                         /* Port Pin 0 in PORT F */
#define PortConf_LED1_PORTPIN_NUM                    ((uint8)1)                                         /* Port Pin 1 in PORT F */
#define PortConf_PORTPIN_F2                          ((uint8)2)                                         /* Port Pin 2 in PORT F */
#define PortConf_PORTPIN_F3                          ((uint8)3)                                         /* Port Pin 3 in PORT F */
#define PortConf_SW1_PORTPIN_NUM                     ((uint8)4)                                         /* Port Pin 4 in PORT F */

#define PortConf_PORTPIN_A0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT A MODE */
#define PortConf_PORTPIN_A1_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT A MODE */
#define PortConf_PORTPIN_A2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT A MODE */
#define PortConf_PORTPIN_A3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT A MODE */
#define PortConf_PORTPIN_A4_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT A MODE */
#define PortConf_PORTPIN_A5_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 5 in PORT A MODE */
#define PortConf_PORTPIN_A6_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 6 in PORT A MODE */
#define PortConf_PORTPIN_A7_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 7 in PORT A MODE */

#define PortConf_PORTPIN_B0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT B MODE */
#define PortConf_PORTPIN_B1_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT B MODE */
#define PortConf_PORTPIN_B2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT B MODE */
#define PortConf_PORTPIN_B3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT B MODE */
#define PortConf_PORTPIN_B4_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT B MODE */
#define PortConf_PORTPIN_B5_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 5 in PORT B MODE */
#define PortConf_PORTPIN_B6_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 6 in PORT B MODE */
#define PortConf_PORTPIN_B7_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 7 in PORT B MODE */

#define PortConf_PORTPIN_C0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT C MODE */
#define PortConf_PORTPIN_C1_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT C MODE */
#define PortConf_PORTPIN_C2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT C MODE */
#define PortConf_PORTPIN_C3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT C MODE */
#define PortConf_PORTPIN_C4_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT C MODE */
#define PortConf_PORTPIN_C5_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 5 in PORT C MODE */
#define PortConf_PORTPIN_C6_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 6 in PORT C MODE */
#define PortConf_PORTPIN_C7_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 7 in PORT C MODE */

#define PortConf_PORTPIN_D0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT D MODE */
#define PortConf_PORTPIN_D1_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT D MODE */
#define PortConf_PORTPIN_D2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT D MODE */
#define PortConf_PORTPIN_D3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT D MODE */
#define PortConf_PORTPIN_D4_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT D MODE */
#define PortConf_PORTPIN_D5_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 5 in PORT D MODE */
#define PortConf_PORTPIN_D6_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 6 in PORT D MODE */
#define PortConf_PORTPIN_D7_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 7 in PORT D MODE */

#define PortConf_PORTPIN_E0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT E MODE */
#define PortConf_PORTPIN_E1_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT E MODE */
#define PortConf_PORTPIN_E2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT E MODE */
#define PortConf_PORTPIN_E3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT E MODE */
#define PortConf_PORTPIN_E4_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT E MODE */
#define PortConf_PORTPIN_E5_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 5 in PORT E MODE */

#define PortConf_PORTPIN_F0_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 0 in PORT F MODE */
#define PortConf_LED1_PORTPIN_MODE                   ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 1 in PORT F MODE */
#define PortConf_PORTPIN_F2_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 2 in PORT F MODE */
#define PortConf_PORTPIN_F3_MODE                     ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 3 in PORT F MODE */
#define PortConf_SW1_PORTPIN_MODE                    ((Port_PortPinInitialModeType)PORT_PIN_MODE_DIO)   /* Port Pin 4 in PORT F MODE */

#define PortConf_PORTPIN_A0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT A DIRECTION */
#define PortConf_PORTPIN_A1_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 1 in PORT A DIRECTION */
#define PortConf_PORTPIN_A2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT A DIRECTION */
#define PortConf_PORTPIN_A3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT A DIRECTION */
#define PortConf_PORTPIN_A4_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT A DIRECTION */
#define PortConf_PORTPIN_A5_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 5 in PORT A DIRECTION */
#define PortConf_PORTPIN_A6_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 6 in PORT A DIRECTION */
#define PortConf_PORTPIN_A7_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 7 in PORT A DIRECTION */

#define PortConf_PORTPIN_B0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT B DIRECTION */
#define PortConf_PORTPIN_B1_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 1 in PORT B DIRECTION */
#define PortConf_PORTPIN_B2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT B DIRECTION */
#define PortConf_PORTPIN_B3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT B DIRECTION */
#define PortConf_PORTPIN_B4_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT B DIRECTION */
#define PortConf_PORTPIN_B5_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 5 in PORT B DIRECTION */
#define PortConf_PORTPIN_B6_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 6 in PORT B DIRECTION */
#define PortConf_PORTPIN_B7_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 7 in PORT B DIRECTION */

#define PortConf_PORTPIN_C0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT C DIRECTION */
#define PortConf_PORTPIN_C1_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 1 in PORT C DIRECTION */
#define PortConf_PORTPIN_C2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT C DIRECTION */
#define PortConf_PORTPIN_C3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT C DIRECTION */
#define PortConf_PORTPIN_C4_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT C DIRECTION */
#define PortConf_PORTPIN_C5_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 5 in PORT C DIRECTION */
#define PortConf_PORTPIN_C6_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 6 in PORT C DIRECTION */
#define PortConf_PORTPIN_C7_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 7 in PORT C DIRECTION */

#define PortConf_PORTPIN_D0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT D DIRECTION */
#define PortConf_PORTPIN_D1_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 1 in PORT D DIRECTION */
#define PortConf_PORTPIN_D2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT D DIRECTION */
#define PortConf_PORTPIN_D3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT D DIRECTION */
#define PortConf_PORTPIN_D4_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT D DIRECTION */
#define PortConf_PORTPIN_D5_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 5 in PORT D DIRECTION */
#define PortConf_PORTPIN_D6_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 6 in PORT D DIRECTION */
#define PortConf_PORTPIN_D7_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 7 in PORT D DIRECTION */

#define PortConf_PORTPIN_E0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT E DIRECTION */
#define PortConf_PORTPIN_E1_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 1 in PORT E DIRECTION */
#define PortConf_PORTPIN_E2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT E DIRECTION */
#define PortConf_PORTPIN_E3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT E DIRECTION */
#define PortConf_PORTPIN_E4_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT E DIRECTION */
#define PortConf_PORTPIN_E5_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 5 in PORT E DIRECTION */

#define PortConf_PORTPIN_F0_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 0 in PORT F DIRECTION */
#define PortConf_LED1_PORTPIN_DIRECTION              ((Port_PinDirectionType)PORT_PIN_OUT)              /* Port Pin 1 in PORT F DIRECTION */
#define PortConf_PORTPIN_F2_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 2 in PORT F DIRECTION */
#define PortConf_PORTPIN_F3_DIRECTION                ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 3 in PORT F DIRECTION */
#define PortConf_SW1_PORTPIN_DIRECTION               ((Port_PinDirectionType)PORT_PIN_IN)               /* Port Pin 4 in PORT F DIRECTION */

#define PortConf_PORTPIN_A0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A1_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A4_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 4 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A5_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 5 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A6_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 6 in PORT A INITIAL VALUE */
#define PortConf_PORTPIN_A7_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 7 in PORT A INITIAL VALUE */

#define PortConf_PORTPIN_B0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B1_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B4_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 4 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B5_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 5 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B6_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 6 in PORT B INITIAL VALUE */
#define PortConf_PORTPIN_B7_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 7 in PORT B INITIAL VALUE */

#define PortConf_PORTPIN_C0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C1_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C4_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 4 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C5_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 5 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C6_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 6 in PORT C INITIAL VALUE */
#define PortConf_PORTPIN_C7_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 7 in PORT C INITIAL VALUE */

#define PortConf_PORTPIN_D0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D1_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D4_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 4 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D5_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 5 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D6_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 6 in PORT D INITIAL VALUE */
#define PortConf_PORTPIN_D7_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 7 in PORT D INITIAL VALUE */

#define PortConf_PORTPIN_E0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT E INITIAL VALUE */
#define PortConf_PORTPIN_E1_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT E INITIAL VALUE */
#define PortConf_PORTPIN_E2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT E INITIAL VALUE */
#define PortConf_PORTPIN_E3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT E INITIAL VALUE */
#define PortConf_PORTPIN_E4_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 4 in PORT E INITIAL VALUE */
#define PortConf_PORTPIN_E5_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 5 in PORT E INITIAL VALUE */

#define PortConf_PORTPIN_F0_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 0 in PORT F INITIAL VALUE */
#define PortConf_LED1_PORTPIN_INITIAL_VALUE          ((uint8)STD_LOW)                                   /* Port Pin 1 in PORT F INITIAL VALUE */
#define PortConf_PORTPIN_F2_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 2 in PORT F INITIAL VALUE */
#define PortConf_PORTPIN_F3_INITIAL_VALUE            ((uint8)STD_LOW)                                   /* Port Pin 3 in PORT F INITIAL VALUE */
#define PortConf_SW1_PORTPIN_INITIAL_VALUE           ((uint8)STD_HIGH)                                  /* Port Pin 4 in PORT F INITIAL VALUE */

#define PortConf_PORTPIN_A0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A1_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 1 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A4_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 4 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A5_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 5 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A6_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 6 in PORT A CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_A7_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 7 in PORT A CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_B0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B1_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 1 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B4_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 4 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B5_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 5 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B6_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 6 in PORT B CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_B7_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 7 in PORT B CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_C0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C1_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 1 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C4_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 4 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C5_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 5 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C6_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 6 in PORT C CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_C7_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 7 in PORT C CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_D0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D1_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 1 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D4_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 4 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D5_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 5 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D6_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 6 in PORT D CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_D7_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 7 in PORT D CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_E0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT E CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_E1_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 1 in PORT E CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_E2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT E CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_E3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT E CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_E4_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 4 in PORT E CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_E5_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 5 in PORT E CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_F0_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 0 in PORT F CHANGE DIRECTION RUNTIME */
#define PortConf_LED1_PORTPIN_CHANGE_DIR_RT          ((uint8)STD_ON)                                    /* Port Pin 1 in PORT F CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_F2_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 2 in PORT F CHANGE DIRECTION RUNTIME */
#define PortConf_PORTPIN_F3_CHANGE_DIR_RT            ((uint8)STD_ON)                                    /* Port Pin 3 in PORT F CHANGE DIRECTION RUNTIME */
#define PortConf_SW1_PORTPIN_CHANGE_DIR_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT F CHANGE DIRECTION RUNTIME */

#define PortConf_PORTPIN_A0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A1_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 1 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A4_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A5_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 5 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A6_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 6 in PORT A CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_A7_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 7 in PORT A CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_B0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B1_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 1 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B4_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B5_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 5 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B6_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 6 in PORT B CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_B7_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 7 in PORT B CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_C0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C1_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 1 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C4_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C5_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 5 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C6_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 6 in PORT C CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_C7_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 7 in PORT C CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_D0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D1_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 1 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D4_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D5_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 5 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D6_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 6 in PORT D CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_D7_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 7 in PORT D CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_E0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT E CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_E1_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 1 in PORT E CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_E2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT E CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_E3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT E CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_E4_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 4 in PORT E CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_E5_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 5 in PORT E CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_F0_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 0 in PORT F CHANGE MODE RUNTIME */
#define PortConf_LED1_PORTPIN_CHANGE_MODE_RT         ((uint8)STD_ON)                                    /* Port Pin 1 in PORT F CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_F2_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 2 in PORT F CHANGE MODE RUNTIME */
#define PortConf_PORTPIN_F3_CHANGE_MODE_RT           ((uint8)STD_ON)                                    /* Port Pin 3 in PORT F CHANGE MODE RUNTIME */
#define PortConf_SW1_PORTPIN_CHANGE_MODE_RT          ((uint8)STD_ON)                                    /* Port Pin 4 in PORT F CHANGE MODE RUNTIME */

#define PortConf_PORTPIN_A0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A1_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A4_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 4 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A5_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 5 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A6_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 6 in PORT A INTERNAL RESISTANCE */
#define PortConf_PORTPIN_A7_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 7 in PORT A INTERNAL RESISTANCE */

#define PortConf_PORTPIN_B0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B1_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B4_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 4 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B5_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 5 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B6_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 6 in PORT B INTERNAL RESISTANCE */
#define PortConf_PORTPIN_B7_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 7 in PORT B INTERNAL RESISTANCE */

#define PortConf_PORTPIN_C0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C1_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C4_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 4 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C5_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 5 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C6_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 6 in PORT C INTERNAL RESISTANCE */
#define PortConf_PORTPIN_C7_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 7 in PORT C INTERNAL RESISTANCE */

#define PortConf_PORTPIN_D0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D1_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D4_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 4 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D5_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 5 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D6_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 6 in PORT D INTERNAL RESISTANCE */
#define PortConf_PORTPIN_D7_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 7 in PORT D INTERNAL RESISTANCE */

#define PortConf_PORTPIN_E0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT E INTERNAL RESISTANCE */
#define PortConf_PORTPIN_E1_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT E INTERNAL RESISTANCE */
#define PortConf_PORTPIN_E2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT E INTERNAL RESISTANCE */
#define PortConf_PORTPIN_E3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT E INTERNAL RESISTANCE */
#define PortConf_PORTPIN_E4_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 4 in PORT E INTERNAL RESISTANCE */
#define PortConf_PORTPIN_E5_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 5 in PORT E INTERNAL RESISTANCE */

#define PortConf_PORTPIN_F0_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 0 in PORT F INTERNAL RESISTANCE */
#define PortConf_LED1_PORTPIN_INTERNAL_RESISTANCE    ((Port_InternalResistorType)OFF)                   /* Port Pin 1 in PORT F INTERNAL RESISTANCE */
#define PortConf_PORTPIN_F2_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 2 in PORT F INTERNAL RESISTANCE */
#define PortConf_PORTPIN_F3_INTERNAL_RESISTANCE      ((Port_InternalResistorType)OFF)                   /* Port Pin 3 in PORT F INTERNAL RESISTANCE */
#define PortConf_SW1_PORTPIN_INTERNAL_RESISTANCE     ((Port_InternalResistorType)PULL_UP)               /* Port Pin 4 in PORT F INTERNAL RESISTANCE */


#endif /* PORT_CFG_H_ */
