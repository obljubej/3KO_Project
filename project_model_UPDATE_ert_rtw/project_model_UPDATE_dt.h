/*
 * project_model_UPDATE_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "project_model_UPDATE".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Nov 21 16:25:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(freedomk64f_DigitalRead_proje_T),
  sizeof(freedomk64f_DigitalWrite_proj_T),
  sizeof(freedomk64f_PWMOutput_project_T),
  sizeof(freedomk64f_fxos8700_project__T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "freedomk64f_DigitalRead_proje_T",
  "freedomk64f_DigitalWrite_proj_T",
  "freedomk64f_PWMOutput_project_T",
  "freedomk64f_fxos8700_project__T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&project_model_UPDATE_B.Min), 0, 0, 34 },

  { (char_T *)(&project_model_UPDATE_B.RATE_SMOOTHING), 8, 0, 4 }
  ,

  { (char_T *)(&project_model_UPDATE_DW.obj), 17, 0, 1 },

  { (char_T *)(&project_model_UPDATE_DW.obj_c), 14, 0, 2 },

  { (char_T *)(&project_model_UPDATE_DW.obj_b), 15, 0, 9 },

  { (char_T *)(&project_model_UPDATE_DW.obj_o), 16, 0, 3 },

  { (char_T *)(&project_model_UPDATE_DW.discharge_time), 0, 0, 17 },

  { (char_T *)(&project_model_UPDATE_DW.is_c1_project_model_UPDATE), 7, 0, 13 },

  { (char_T *)(&project_model_UPDATE_DW.is_active_c1_project_model_UPDA), 3, 0,
    3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&project_model_UPDATE_P.DigitalRead2_SampleTime), 0, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] project_model_UPDATE_dt.h */
