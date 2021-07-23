//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: velocityramp.h
//
// Code generated for Simulink model 'velocityramp'.
//
// Model version                  : 1.49
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Jul 22 18:07:47 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_velocityramp_h_
#define RTW_HEADER_velocityramp_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "velocityramp_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_velocityramp_T {
  SL_Bus_velocityramp_geometry_msgs_Twist In1;// '<S5>/In1'
  real_T vel_setpoint;                 // '<Root>/Chart'
};

// Block states (default storage) for system '<Root>'
struct DW_velocityramp_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S4>/SourceBlock'
  uint16_T temporalCounter_i1;         // '<Root>/Chart'
  uint8_T is_active_c3_velocityramp;   // '<Root>/Chart'
  uint8_T is_c3_velocityramp;          // '<Root>/Chart'
};

// Parameters (default storage)
struct P_velocityramp_T_ {
  SL_Bus_velocityramp_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S1>/Constant'

  SL_Bus_velocityramp_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                     //  Referenced by: '<S5>/Out1'

  SL_Bus_velocityramp_geometry_msgs_Twist Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                              //  Referenced by: '<S4>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_velocityramp_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_velocityramp_T velocityramp_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_velocityramp_T velocityramp_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_velocityramp_T velocityramp_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void velocityramp_initialize(void);
  extern void velocityramp_step(void);
  extern void velocityramp_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_velocityramp_T *const velocityramp_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'velocityramp'
//  '<S1>'   : 'velocityramp/Blank Message'
//  '<S2>'   : 'velocityramp/Chart'
//  '<S3>'   : 'velocityramp/Publish'
//  '<S4>'   : 'velocityramp/Subscribe'
//  '<S5>'   : 'velocityramp/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_velocityramp_h_

//
// File trailer for generated code.
//
// [EOF]
//
