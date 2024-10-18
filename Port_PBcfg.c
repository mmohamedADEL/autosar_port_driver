 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file
 *              for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohamed Adel
 ******************************************************************************/

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION                    (1U)
#define PORT_PBCFG_SW_MINOR_VERSION                    (0U)
#define PORT_PBCFG_SW_PATCH_VERSION                    (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_MAJOR_VERSION                    (4U)
#define PORT_PBCFG_AR_MINOR_VERSION                    (0U)
#define PORT_PBCFG_AR_PATCH_VERSION                    (3U)

/* AUTOSAR Port header file */
#include "Port.h"
/* Software version compliance check statement between Port header file & Port_PBcfg source file */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of the Port.h header source file does not comply with the current module version"
#endif

/* AUTOSAR version compliance check statement between Port header file & Port_PBcfg source file */
#if ((PORT_PBCFG_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of the Port.h header source file does not comply with the current module version"
#endif

/*
 * Post build array of type Port_ConfigType structure necessary
 * to handle Port module initialization for Port_Init API.
 */

const Port_ConfigType Port_Configuration = {
                                            PortConf_PORT_A0, PortConf_PORTPIN_A0, PortConf_PORTPIN_A0_MODE, PortConf_PORTPIN_A0_DIRECTION, PortConf_PORTPIN_A0_INITIAL_VALUE, PortConf_PORTPIN_A0_CHANGE_DIR_RT, PortConf_PORTPIN_A0_CHANGE_MODE_RT, PortConf_PORTPIN_A0_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A1, PortConf_PORTPIN_A1, PortConf_PORTPIN_A1_MODE, PortConf_PORTPIN_A1_DIRECTION, PortConf_PORTPIN_A1_INITIAL_VALUE, PortConf_PORTPIN_A1_CHANGE_DIR_RT, PortConf_PORTPIN_A1_CHANGE_MODE_RT, PortConf_PORTPIN_A1_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A2, PortConf_PORTPIN_A2, PortConf_PORTPIN_A2_MODE, PortConf_PORTPIN_A2_DIRECTION, PortConf_PORTPIN_A2_INITIAL_VALUE, PortConf_PORTPIN_A2_CHANGE_DIR_RT, PortConf_PORTPIN_A2_CHANGE_MODE_RT, PortConf_PORTPIN_A2_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A3, PortConf_PORTPIN_A3, PortConf_PORTPIN_A3_MODE, PortConf_PORTPIN_A3_DIRECTION, PortConf_PORTPIN_A3_INITIAL_VALUE, PortConf_PORTPIN_A3_CHANGE_DIR_RT, PortConf_PORTPIN_A3_CHANGE_MODE_RT, PortConf_PORTPIN_A3_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A4, PortConf_PORTPIN_A4, PortConf_PORTPIN_A4_MODE, PortConf_PORTPIN_A4_DIRECTION, PortConf_PORTPIN_A4_INITIAL_VALUE, PortConf_PORTPIN_A4_CHANGE_DIR_RT, PortConf_PORTPIN_A4_CHANGE_MODE_RT, PortConf_PORTPIN_A4_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A5, PortConf_PORTPIN_A5, PortConf_PORTPIN_A5_MODE, PortConf_PORTPIN_A5_DIRECTION, PortConf_PORTPIN_A5_INITIAL_VALUE, PortConf_PORTPIN_A5_CHANGE_DIR_RT, PortConf_PORTPIN_A5_CHANGE_MODE_RT, PortConf_PORTPIN_A5_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A6, PortConf_PORTPIN_A6, PortConf_PORTPIN_A6_MODE, PortConf_PORTPIN_A6_DIRECTION, PortConf_PORTPIN_A6_INITIAL_VALUE, PortConf_PORTPIN_A6_CHANGE_DIR_RT, PortConf_PORTPIN_A6_CHANGE_MODE_RT, PortConf_PORTPIN_A6_INTERNAL_RESISTANCE,
                                            PortConf_PORT_A7, PortConf_PORTPIN_A7, PortConf_PORTPIN_A7_MODE, PortConf_PORTPIN_A7_DIRECTION, PortConf_PORTPIN_A7_INITIAL_VALUE, PortConf_PORTPIN_A7_CHANGE_DIR_RT, PortConf_PORTPIN_A7_CHANGE_MODE_RT, PortConf_PORTPIN_A7_INTERNAL_RESISTANCE,

                                            PortConf_PORT_B0, PortConf_PORTPIN_B0, PortConf_PORTPIN_B0_MODE, PortConf_PORTPIN_B0_DIRECTION, PortConf_PORTPIN_B0_INITIAL_VALUE, PortConf_PORTPIN_B0_CHANGE_DIR_RT, PortConf_PORTPIN_B0_CHANGE_MODE_RT, PortConf_PORTPIN_B0_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B1, PortConf_PORTPIN_B1, PortConf_PORTPIN_B1_MODE, PortConf_PORTPIN_B1_DIRECTION, PortConf_PORTPIN_B1_INITIAL_VALUE, PortConf_PORTPIN_B1_CHANGE_DIR_RT, PortConf_PORTPIN_B1_CHANGE_MODE_RT, PortConf_PORTPIN_B1_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B2, PortConf_PORTPIN_B2, PortConf_PORTPIN_B2_MODE, PortConf_PORTPIN_B2_DIRECTION, PortConf_PORTPIN_B2_INITIAL_VALUE, PortConf_PORTPIN_B2_CHANGE_DIR_RT, PortConf_PORTPIN_B2_CHANGE_MODE_RT, PortConf_PORTPIN_B2_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B3, PortConf_PORTPIN_B3, PortConf_PORTPIN_B3_MODE, PortConf_PORTPIN_B3_DIRECTION, PortConf_PORTPIN_B3_INITIAL_VALUE, PortConf_PORTPIN_B3_CHANGE_DIR_RT, PortConf_PORTPIN_B3_CHANGE_MODE_RT, PortConf_PORTPIN_B3_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B4, PortConf_PORTPIN_B4, PortConf_PORTPIN_B4_MODE, PortConf_PORTPIN_B4_DIRECTION, PortConf_PORTPIN_B4_INITIAL_VALUE, PortConf_PORTPIN_B4_CHANGE_DIR_RT, PortConf_PORTPIN_B4_CHANGE_MODE_RT, PortConf_PORTPIN_B4_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B5, PortConf_PORTPIN_B5, PortConf_PORTPIN_B5_MODE, PortConf_PORTPIN_B5_DIRECTION, PortConf_PORTPIN_B5_INITIAL_VALUE, PortConf_PORTPIN_B5_CHANGE_DIR_RT, PortConf_PORTPIN_B5_CHANGE_MODE_RT, PortConf_PORTPIN_B5_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B6, PortConf_PORTPIN_B6, PortConf_PORTPIN_B6_MODE, PortConf_PORTPIN_B6_DIRECTION, PortConf_PORTPIN_B6_INITIAL_VALUE, PortConf_PORTPIN_B6_CHANGE_DIR_RT, PortConf_PORTPIN_B6_CHANGE_MODE_RT, PortConf_PORTPIN_B6_INTERNAL_RESISTANCE,
                                            PortConf_PORT_B7, PortConf_PORTPIN_B7, PortConf_PORTPIN_B7_MODE, PortConf_PORTPIN_B7_DIRECTION, PortConf_PORTPIN_B7_INITIAL_VALUE, PortConf_PORTPIN_B7_CHANGE_DIR_RT, PortConf_PORTPIN_B7_CHANGE_MODE_RT, PortConf_PORTPIN_B7_INTERNAL_RESISTANCE,

                                            PortConf_PORT_C4, PortConf_PORTPIN_C4, PortConf_PORTPIN_C4_MODE, PortConf_PORTPIN_C4_DIRECTION, PortConf_PORTPIN_C4_INITIAL_VALUE, PortConf_PORTPIN_C4_CHANGE_DIR_RT, PortConf_PORTPIN_C4_CHANGE_MODE_RT, PortConf_PORTPIN_C4_INTERNAL_RESISTANCE,
                                            PortConf_PORT_C5, PortConf_PORTPIN_C5, PortConf_PORTPIN_C5_MODE, PortConf_PORTPIN_C5_DIRECTION, PortConf_PORTPIN_C5_INITIAL_VALUE, PortConf_PORTPIN_C5_CHANGE_DIR_RT, PortConf_PORTPIN_C5_CHANGE_MODE_RT, PortConf_PORTPIN_C5_INTERNAL_RESISTANCE,
                                            PortConf_PORT_C6, PortConf_PORTPIN_C6, PortConf_PORTPIN_C6_MODE, PortConf_PORTPIN_C6_DIRECTION, PortConf_PORTPIN_C6_INITIAL_VALUE, PortConf_PORTPIN_C6_CHANGE_DIR_RT, PortConf_PORTPIN_C6_CHANGE_MODE_RT, PortConf_PORTPIN_C6_INTERNAL_RESISTANCE,
                                            PortConf_PORT_C7, PortConf_PORTPIN_C7, PortConf_PORTPIN_C7_MODE, PortConf_PORTPIN_C7_DIRECTION, PortConf_PORTPIN_C7_INITIAL_VALUE, PortConf_PORTPIN_C7_CHANGE_DIR_RT, PortConf_PORTPIN_C7_CHANGE_MODE_RT, PortConf_PORTPIN_C7_INTERNAL_RESISTANCE,

                                            PortConf_PORT_D0, PortConf_PORTPIN_D0, PortConf_PORTPIN_D0_MODE, PortConf_PORTPIN_D0_DIRECTION, PortConf_PORTPIN_D0_INITIAL_VALUE, PortConf_PORTPIN_D0_CHANGE_DIR_RT, PortConf_PORTPIN_D0_CHANGE_MODE_RT, PortConf_PORTPIN_D0_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D1, PortConf_PORTPIN_D1, PortConf_PORTPIN_D1_MODE, PortConf_PORTPIN_D1_DIRECTION, PortConf_PORTPIN_D1_INITIAL_VALUE, PortConf_PORTPIN_D1_CHANGE_DIR_RT, PortConf_PORTPIN_D1_CHANGE_MODE_RT, PortConf_PORTPIN_D1_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D2, PortConf_PORTPIN_D2, PortConf_PORTPIN_D2_MODE, PortConf_PORTPIN_D2_DIRECTION, PortConf_PORTPIN_D2_INITIAL_VALUE, PortConf_PORTPIN_D2_CHANGE_DIR_RT, PortConf_PORTPIN_D2_CHANGE_MODE_RT, PortConf_PORTPIN_D2_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D3, PortConf_PORTPIN_D3, PortConf_PORTPIN_D3_MODE, PortConf_PORTPIN_D3_DIRECTION, PortConf_PORTPIN_D3_INITIAL_VALUE, PortConf_PORTPIN_D3_CHANGE_DIR_RT, PortConf_PORTPIN_D3_CHANGE_MODE_RT, PortConf_PORTPIN_D3_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D4, PortConf_PORTPIN_D4, PortConf_PORTPIN_D4_MODE, PortConf_PORTPIN_D4_DIRECTION, PortConf_PORTPIN_D4_INITIAL_VALUE, PortConf_PORTPIN_D4_CHANGE_DIR_RT, PortConf_PORTPIN_D4_CHANGE_MODE_RT, PortConf_PORTPIN_D4_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D5, PortConf_PORTPIN_D5, PortConf_PORTPIN_D5_MODE, PortConf_PORTPIN_D5_DIRECTION, PortConf_PORTPIN_D5_INITIAL_VALUE, PortConf_PORTPIN_D5_CHANGE_DIR_RT, PortConf_PORTPIN_D5_CHANGE_MODE_RT, PortConf_PORTPIN_D5_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D6, PortConf_PORTPIN_D6, PortConf_PORTPIN_D6_MODE, PortConf_PORTPIN_D6_DIRECTION, PortConf_PORTPIN_D6_INITIAL_VALUE, PortConf_PORTPIN_D6_CHANGE_DIR_RT, PortConf_PORTPIN_D6_CHANGE_MODE_RT, PortConf_PORTPIN_D6_INTERNAL_RESISTANCE,
                                            PortConf_PORT_D7, PortConf_PORTPIN_D7, PortConf_PORTPIN_D7_MODE, PortConf_PORTPIN_D7_DIRECTION, PortConf_PORTPIN_D7_INITIAL_VALUE, PortConf_PORTPIN_D7_CHANGE_DIR_RT, PortConf_PORTPIN_D7_CHANGE_MODE_RT, PortConf_PORTPIN_D7_INTERNAL_RESISTANCE,

                                            PortConf_PORT_E0, PortConf_PORTPIN_E0, PortConf_PORTPIN_E0_MODE, PortConf_PORTPIN_E0_DIRECTION, PortConf_PORTPIN_E0_INITIAL_VALUE, PortConf_PORTPIN_E0_CHANGE_DIR_RT, PortConf_PORTPIN_E0_CHANGE_MODE_RT, PortConf_PORTPIN_E0_INTERNAL_RESISTANCE,
                                            PortConf_PORT_E1, PortConf_PORTPIN_E1, PortConf_PORTPIN_E1_MODE, PortConf_PORTPIN_E1_DIRECTION, PortConf_PORTPIN_E1_INITIAL_VALUE, PortConf_PORTPIN_E1_CHANGE_DIR_RT, PortConf_PORTPIN_E1_CHANGE_MODE_RT, PortConf_PORTPIN_E1_INTERNAL_RESISTANCE,
                                            PortConf_PORT_E2, PortConf_PORTPIN_E2, PortConf_PORTPIN_E2_MODE, PortConf_PORTPIN_E2_DIRECTION, PortConf_PORTPIN_E2_INITIAL_VALUE, PortConf_PORTPIN_E2_CHANGE_DIR_RT, PortConf_PORTPIN_E2_CHANGE_MODE_RT, PortConf_PORTPIN_E2_INTERNAL_RESISTANCE,
                                            PortConf_PORT_E3, PortConf_PORTPIN_E3, PortConf_PORTPIN_E3_MODE, PortConf_PORTPIN_E3_DIRECTION, PortConf_PORTPIN_E3_INITIAL_VALUE, PortConf_PORTPIN_E3_CHANGE_DIR_RT, PortConf_PORTPIN_E3_CHANGE_MODE_RT, PortConf_PORTPIN_E3_INTERNAL_RESISTANCE,
                                            PortConf_PORT_E4, PortConf_PORTPIN_E4, PortConf_PORTPIN_E4_MODE, PortConf_PORTPIN_E4_DIRECTION, PortConf_PORTPIN_E4_INITIAL_VALUE, PortConf_PORTPIN_E4_CHANGE_DIR_RT, PortConf_PORTPIN_E4_CHANGE_MODE_RT, PortConf_PORTPIN_E4_INTERNAL_RESISTANCE,
                                            PortConf_PORT_E5, PortConf_PORTPIN_E5, PortConf_PORTPIN_E5_MODE, PortConf_PORTPIN_E5_DIRECTION, PortConf_PORTPIN_E5_INITIAL_VALUE, PortConf_PORTPIN_E5_CHANGE_DIR_RT, PortConf_PORTPIN_E5_CHANGE_MODE_RT, PortConf_PORTPIN_E5_INTERNAL_RESISTANCE,

                                            PortConf_PORT_F0, PortConf_PORTPIN_F0, PortConf_PORTPIN_F0_MODE, PortConf_PORTPIN_F0_DIRECTION, PortConf_PORTPIN_F0_INITIAL_VALUE, PortConf_PORTPIN_F0_CHANGE_DIR_RT, PortConf_PORTPIN_F0_CHANGE_MODE_RT, PortConf_PORTPIN_F0_INTERNAL_RESISTANCE,
                                            PortConf_LED1_PORT_NUM, PortConf_LED1_PORTPIN_NUM, PortConf_LED1_PORTPIN_MODE, PortConf_LED1_PORTPIN_DIRECTION, PortConf_LED1_PORTPIN_INITIAL_VALUE, PortConf_LED1_PORTPIN_CHANGE_DIR_RT, PortConf_LED1_PORTPIN_CHANGE_MODE_RT, PortConf_LED1_PORTPIN_INTERNAL_RESISTANCE,
                                            PortConf_PORT_F2, PortConf_PORTPIN_F2, PortConf_PORTPIN_F2_MODE, PortConf_PORTPIN_F2_DIRECTION, PortConf_PORTPIN_F2_INITIAL_VALUE, PortConf_PORTPIN_F2_CHANGE_DIR_RT, PortConf_PORTPIN_F2_CHANGE_MODE_RT, PortConf_PORTPIN_F2_INTERNAL_RESISTANCE,
                                            PortConf_PORT_F3, PortConf_PORTPIN_F3, PortConf_PORTPIN_F3_MODE, PortConf_PORTPIN_F3_DIRECTION, PortConf_PORTPIN_F3_INITIAL_VALUE, PortConf_PORTPIN_F3_CHANGE_DIR_RT, PortConf_PORTPIN_F3_CHANGE_MODE_RT, PortConf_PORTPIN_F3_INTERNAL_RESISTANCE,
                                            PortConf_SW1_PORT_NUM, PortConf_SW1_PORTPIN_NUM, PortConf_SW1_PORTPIN_MODE, PortConf_SW1_PORTPIN_DIRECTION, PortConf_SW1_PORTPIN_INITIAL_VALUE, PortConf_SW1_PORTPIN_CHANGE_DIR_RT, PortConf_SW1_PORTPIN_CHANGE_MODE_RT, PortConf_SW1_PORTPIN_INTERNAL_RESISTANCE
};







