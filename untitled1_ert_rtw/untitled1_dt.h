/*
 * untitled1_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled1".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Nov 21 16:23:56 2025
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
  sizeof(freedomk64f_DigitalRead_untit_T),
  sizeof(freedomk64f_DigitalWrite_unti_T),
  sizeof(freedomk64f_PWMOutput_untitle_T),
  sizeof(freedomk64f_fxos8700_untitled_T)
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
  "freedomk64f_DigitalRead_untit_T",
  "freedomk64f_DigitalWrite_unti_T",
  "freedomk64f_PWMOutput_untitle_T",
  "freedomk64f_fxos8700_untitled_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled1_B.Abs), 0, 0, 35 },

  { (char_T *)(&untitled1_B.RATE_SMOOTHING), 8, 0, 4 }
  ,

  { (char_T *)(&untitled1_DW.obj), 17, 0, 1 },

  { (char_T *)(&untitled1_DW.obj_j), 14, 0, 2 },

  { (char_T *)(&untitled1_DW.obj_l), 15, 0, 9 },

  { (char_T *)(&untitled1_DW.obj_m), 16, 0, 3 },

  { (char_T *)(&untitled1_DW.discharge_time), 0, 0, 17 },

  { (char_T *)(&untitled1_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&untitled1_DW.is_c1_untitled1), 7, 0, 13 },

  { (char_T *)(&untitled1_DW.is_active_c1_untitled1), 3, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled1_P.DigitalRead2_SampleTime), 0, 0, 9 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] untitled1_dt.h */
