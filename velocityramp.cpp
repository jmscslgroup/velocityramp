//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: velocityramp.cpp
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
#include "velocityramp.h"
#include "velocityramp_private.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T velocityramp_IN_DropBy10 = 1U;
const uint8_T velocityramp_IN_HoldAtPeak = 2U;
const uint8_T velocityramp_IN_HoldAtPeak1 = 3U;
const uint8_T velocityramp_IN_HoldAtValley = 4U;
const uint8_T velocityramp_IN_RaiseBy10 = 5U;
const uint8_T velocityramp_IN_reset = 6U;

// Block signals (default storage)
B_velocityramp_T velocityramp_B;

// Block states (default storage)
DW_velocityramp_T velocityramp_DW;

// Real-time model
RT_MODEL_velocityramp_T velocityramp_M_ = RT_MODEL_velocityramp_T();
RT_MODEL_velocityramp_T *const velocityramp_M = &velocityramp_M_;

// Model step function
void velocityramp_step(void)
{
  SL_Bus_velocityramp_geometry_msgs_Twist rtb_BusAssignment;
  real_T tmp;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S5>/In1'

  b_varargout_1 = Sub_velocityramp_10.getLatestMessage(&rtb_BusAssignment);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    velocityramp_B.In1 = rtb_BusAssignment;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Chart: '<Root>/Chart'
  if (velocityramp_DW.temporalCounter_i1 < 511U) {
    velocityramp_DW.temporalCounter_i1 = static_cast<uint16_T>
      (velocityramp_DW.temporalCounter_i1 + 1U);
  }

  if (velocityramp_DW.is_active_c3_velocityramp == 0U) {
    velocityramp_DW.is_active_c3_velocityramp = 1U;
    velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
    if (velocityramp_B.In1.Linear.X > 8.0) {
      velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
    } else {
      velocityramp_B.vel_setpoint = 8.0;
    }
  } else {
    switch (velocityramp_DW.is_c3_velocityramp) {
     case velocityramp_IN_DropBy10:
      tmp = fabs(velocityramp_B.In1.Linear.X - velocityramp_B.vel_setpoint);
      if (tmp < 0.1) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_HoldAtValley;
        velocityramp_DW.temporalCounter_i1 = 0U;
      } else if (tmp > 3.0) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
        if (velocityramp_B.In1.Linear.X > 8.0) {
          velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
        } else {
          velocityramp_B.vel_setpoint = 8.0;
        }
      }
      break;

     case velocityramp_IN_HoldAtPeak:
      if (velocityramp_DW.temporalCounter_i1 >= 500U) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_DropBy10;
        velocityramp_B.vel_setpoint -= 3.0;
      } else if (fabs(velocityramp_B.In1.Linear.X - velocityramp_B.vel_setpoint)
                 > 5.0) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
        if (velocityramp_B.In1.Linear.X > 8.0) {
          velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
        } else {
          velocityramp_B.vel_setpoint = 8.0;
        }
      }
      break;

     case velocityramp_IN_HoldAtPeak1:
      if ((velocityramp_DW.temporalCounter_i1 >= 500U) || (fabs
           (velocityramp_B.In1.Linear.X - velocityramp_B.vel_setpoint) > 5.0)) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
        if (velocityramp_B.In1.Linear.X > 8.0) {
          velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
        } else {
          velocityramp_B.vel_setpoint = 8.0;
        }
      }
      break;

     case velocityramp_IN_HoldAtValley:
      if (velocityramp_DW.temporalCounter_i1 >= 500U) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_RaiseBy10;
        velocityramp_B.vel_setpoint += 3.0;
      } else if (fabs(velocityramp_B.In1.Linear.X - velocityramp_B.vel_setpoint)
                 > 3.0) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
        if (velocityramp_B.In1.Linear.X > 8.0) {
          velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
        } else {
          velocityramp_B.vel_setpoint = 8.0;
        }
      }
      break;

     case velocityramp_IN_RaiseBy10:
      tmp = fabs(velocityramp_B.In1.Linear.X - velocityramp_B.vel_setpoint);
      if (tmp < 0.1) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_HoldAtPeak1;
        velocityramp_DW.temporalCounter_i1 = 0U;
      } else if (tmp > 5.0) {
        velocityramp_DW.is_c3_velocityramp = velocityramp_IN_reset;
        if (velocityramp_B.In1.Linear.X > 8.0) {
          velocityramp_B.vel_setpoint = velocityramp_B.In1.Linear.X;
        } else {
          velocityramp_B.vel_setpoint = 8.0;
        }
      }
      break;

     default:
      // case IN_reset:
      velocityramp_DW.is_c3_velocityramp = velocityramp_IN_HoldAtPeak;
      velocityramp_DW.temporalCounter_i1 = 0U;
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  rtb_BusAssignment = velocityramp_P.Constant_Value;
  rtb_BusAssignment.Linear.X = velocityramp_B.vel_setpoint;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_velocityramp_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void velocityramp_initialize(void)
{
  {
    int32_T i;
    char_T b_zeroDelimTopic_0[13];
    char_T b_zeroDelimTopic[4];
    static const char_T tmp[12] = { 'v', 'e', 'l', '_', 's', 'e', 't', 'p', 'o',
      'i', 'n', 't' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1' incorporates:
    //   Inport: '<S5>/In1'

    velocityramp_B.In1 = velocityramp_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    velocityramp_DW.obj_n.matlabCodegenIsDeleted = false;
    velocityramp_DW.obj_n.isInitialized = 1;
    b_zeroDelimTopic[0] = 'v';
    b_zeroDelimTopic[1] = 'e';
    b_zeroDelimTopic[2] = 'l';
    b_zeroDelimTopic[3] = '\x00';
    Sub_velocityramp_10.createSubscriber(&b_zeroDelimTopic[0], 1);
    velocityramp_DW.obj_n.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    velocityramp_DW.obj.matlabCodegenIsDeleted = false;
    velocityramp_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_velocityramp_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    velocityramp_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void velocityramp_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!velocityramp_DW.obj_n.matlabCodegenIsDeleted) {
    velocityramp_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!velocityramp_DW.obj.matlabCodegenIsDeleted) {
    velocityramp_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
