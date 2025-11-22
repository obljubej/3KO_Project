/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov 21 18:59:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define untitle_IN_Define_Reaction_Rate (2U)
#define untitle_IN_Define_Recovery_Rate (3U)
#define untitled_IN_Decrease_HR        (1U)
#define untitled_IN_Entry_State        (4U)
#define untitled_IN_Increase_HR        (5U)
#define untitled_IN_Maintain_Lower_Rate (6U)
#define untitled_IN_Maintain_Upper_Rate (7U)

/* Named constants for Chart: '<Root>/Pacemaker_States' */
#define untitled_IN_AAI                (1U)
#define untitled_IN_AAIR               (2U)
#define untitled_IN_AOO                (3U)
#define untitled_IN_AOOR               (4U)
#define untitled_IN_Charge_AAI         (1U)
#define untitled_IN_Charge_AAIR        (1U)
#define untitled_IN_Charge_AOO         (1U)
#define untitled_IN_Charge_AOOR        (1U)
#define untitled_IN_Charge_VOO         (1U)
#define untitled_IN_Charge_VOOR        (1U)
#define untitled_IN_Charge_VVI         (1U)
#define untitled_IN_Charge_VVIR        (1U)
#define untitled_IN_Discharge_AAI      (2U)
#define untitled_IN_Discharge_AAIR     (2U)
#define untitled_IN_Discharge_AOO      (2U)
#define untitled_IN_Discharge_AOOR     (2U)
#define untitled_IN_Discharge_VOO      (2U)
#define untitled_IN_Discharge_VOOR     (2U)
#define untitled_IN_Discharge_VVI      (2U)
#define untitled_IN_Initial_AAI        (3U)
#define untitled_IN_Initial_AAIR       (3U)
#define untitled_IN_Initial_AOO        (3U)
#define untitled_IN_Initial_AOOR       (3U)
#define untitled_IN_Initial_State      (5U)
#define untitled_IN_Initial_VOO        (3U)
#define untitled_IN_Initial_VOOR       (3U)
#define untitled_IN_Initial_VVI        (3U)
#define untitled_IN_Initial_VVIR       (3U)
#define untitled_IN_VOO                (6U)
#define untitled_IN_VOOR               (7U)
#define untitled_IN_VVI                (8U)
#define untitled_IN_VVIR               (9U)

/* Named constants for Chart: '<Root>/Parameter_Definitions' */
#define untitl_IN_Parameter_Definitions (1U)

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_AAI(void);
static void untitled_AAIR(void);
static void untitled_AOO(void);
static void untitled_AOOR(void);
static void untitled_Initial_State(void);
static void untitled_VOO(void);
static void SystemCore_relea_b5oh5otl251gqo(const
  freedomk64f_fxos8700_untitled_T *obj);
static void SystemCore_delet_b5oh5otl251gqo(const
  freedomk64f_fxos8700_untitled_T *obj);
static void matlabCodegenHan_b5oh5otl251gqo(freedomk64f_fxos8700_untitled_T *obj);
static void SystemCore_rele_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj);
static void SystemCore_dele_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHa_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj);
static void untitled_SystemCore_release_b(const freedomk64f_DigitalRead_untit_T *
  obj);
static void untitled_SystemCore_delete_b(const freedomk64f_DigitalRead_untit_T
  *obj);
static void matlabCodegenHandle_matlabCod_b(freedomk64f_DigitalRead_untit_T *obj);
static void untitled_SystemCore_release(const freedomk64f_DigitalWrite_unti_T
  *obj);
static void untitled_SystemCore_delete(const freedomk64f_DigitalWrite_unti_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_unti_T *obj);
static void un_SystemCore_release_b5oh5otl2(const
  freedomk64f_PWMOutput_untitle_T *obj);
static void unt_SystemCore_delete_b5oh5otl2(const
  freedomk64f_PWMOutput_untitle_T *obj);
static void matlabCodegenHandle_m_b5oh5otl2(freedomk64f_PWMOutput_untitle_T *obj);
static void untitled_SystemCore_setup(freedomk64f_fxos8700_untitled_T *obj);

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_AAI(void)
{
  if (untitled_B.PACING_MODE != 3.0) {
    untitled_DW.is_AAI = 0U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_AAI) {
     case untitled_IN_Charge_AAI:
      untitled_B.PACE_CHARGE_CTRL = 0.0;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.ATR_PACE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_B.ATRIAL_PULSE_WIDTH)) {
        untitled_DW.is_AAI = untitled_IN_Discharge_AAI;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_PACE_CTRL = 0.0;
        untitled_B.ATR_GND_CTRL = 1.0;
        untitled_B.PACING_REF_PWM = untitled_DW.AAI_amp;
        untitled_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case untitled_IN_Discharge_AAI:
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      if ((untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
           (untitled_DW.discharge_time)) && (!untitled_B.DigitalRead2)) {
        untitled_DW.is_AAI = untitled_IN_Charge_AAI;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = 0.0;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_GND_CTRL = 0.0;
        untitled_B.ATR_PACE_CTRL = 1.0;
      } else {
        if (untitled_B.DigitalRead2) {
          untitled_DW.is_AAI = untitled_IN_Discharge_AAI;
          untitled_DW.temporalCounter_i1 = 0U;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.ATR_PACE_CTRL = 0.0;
          untitled_B.ATR_GND_CTRL = 1.0;
          untitled_B.PACING_REF_PWM = untitled_DW.AAI_amp;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Initial_AAI: */
      untitled_B.Z_VENT_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 0.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_DW.is_AAI = untitled_IN_Discharge_AAI;
      untitled_DW.temporalCounter_i1 = 0U;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACING_REF_PWM = untitled_DW.AAI_amp;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_AAIR(void)
{
  if (untitled_B.PACING_MODE != 7.0) {
    untitled_DW.is_AAIR = 0U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_AAIR) {
     case untitled_IN_Charge_AAIR:
      untitled_B.PACE_CHARGE_CTRL = 0.0;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.ATR_PACE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_B.ATRIAL_PULSE_WIDTH)) {
        untitled_DW.is_AAIR = untitled_IN_Discharge_AAIR;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_PACE_CTRL = 0.0;
        untitled_B.ATR_GND_CTRL = 1.0;
        untitled_B.PACING_REF_PWM = untitled_DW.AAIR_amp;
        untitled_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case untitled_IN_Discharge_AAIR:
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      if ((untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
           (untitled_DW.discharge_time)) && (!untitled_B.DigitalRead2)) {
        untitled_DW.is_AAIR = untitled_IN_Charge_AAIR;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = 0.0;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_GND_CTRL = 0.0;
        untitled_B.ATR_PACE_CTRL = 1.0;
      } else {
        if (untitled_B.DigitalRead2) {
          untitled_DW.is_AAIR = untitled_IN_Discharge_AAIR;
          untitled_DW.temporalCounter_i1 = 0U;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.ATR_PACE_CTRL = 0.0;
          untitled_B.ATR_GND_CTRL = 1.0;
          untitled_B.PACING_REF_PWM = untitled_DW.AAIR_amp;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Initial_AAIR: */
      untitled_B.Z_VENT_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 0.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_DW.is_AAIR = untitled_IN_Discharge_AAIR;
      untitled_DW.temporalCounter_i1 = 0U;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACING_REF_PWM = untitled_DW.AAIR_amp;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_AOO(void)
{
  if (untitled_B.PACING_MODE != 2.0) {
    untitled_DW.is_AOO = 0U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_AOO) {
     case untitled_IN_Charge_AOO:
      untitled_B.PACE_CHARGE_CTRL = 0.0;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.ATR_PACE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_B.ATRIAL_PULSE_WIDTH)) {
        untitled_DW.is_AOO = untitled_IN_Discharge_AOO;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_PACE_CTRL = 0.0;
        untitled_B.ATR_GND_CTRL = 1.0;
        untitled_B.PACING_REF_PWM = untitled_DW.AOO_amp;
        untitled_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case untitled_IN_Discharge_AOO:
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_DW.discharge_time)) {
        untitled_DW.is_AOO = untitled_IN_Charge_AOO;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = 0.0;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_GND_CTRL = 0.0;
        untitled_B.ATR_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_AOO: */
      untitled_B.Z_VENT_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 0.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_DW.is_AOO = untitled_IN_Discharge_AOO;
      untitled_DW.temporalCounter_i1 = 0U;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACING_REF_PWM = untitled_DW.AOO_amp;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_AOOR(void)
{
  if (untitled_B.PACING_MODE != 6.0) {
    untitled_DW.is_AOOR = 0U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_AOOR) {
     case untitled_IN_Charge_AOOR:
      untitled_B.PACE_CHARGE_CTRL = 0.0;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.ATR_PACE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_B.ATRIAL_PULSE_WIDTH)) {
        untitled_DW.is_AOOR = untitled_IN_Discharge_AOOR;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_PACE_CTRL = 0.0;
        untitled_B.ATR_GND_CTRL = 1.0;
        untitled_B.PACING_REF_PWM = untitled_DW.AOOR_amp;
        untitled_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case untitled_IN_Discharge_AOOR:
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_DW.discharge_time)) {
        untitled_DW.is_AOOR = untitled_IN_Charge_AOOR;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = 0.0;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.ATR_GND_CTRL = 0.0;
        untitled_B.ATR_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_AOOR: */
      untitled_B.Z_VENT_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 0.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_DW.is_AOOR = untitled_IN_Discharge_AOOR;
      untitled_DW.temporalCounter_i1 = 0U;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 1.0;
      untitled_B.PACING_REF_PWM = untitled_DW.AOOR_amp;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_Initial_State(void)
{
  untitled_B.VENT_CMP_REF_PWM = 52.0;
  untitled_B.ATR_CMP_REF_PWM = 51.0;
  if (untitled_B.PACING_MODE == 1.0) {
    untitled_DW.is_c3_untitled = untitled_IN_VOO;
    untitled_DW.is_VOO = untitled_IN_Initial_VOO;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.VENTRICULAR_PULSE_WIDTH;
    untitled_DW.VOO_amp = untitled_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.ATR_PACE_CTRL = 0.0;
    untitled_B.ATR_GND_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
    untitled_B.Z_VENT_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 5.0) {
    untitled_DW.is_c3_untitled = untitled_IN_VOOR;
    untitled_DW.is_VOOR = untitled_IN_Initial_VOOR;
    untitled_DW.VOOR_amp = untitled_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.ATR_PACE_CTRL = 0.0;
    untitled_B.ATR_GND_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
    untitled_B.Z_VENT_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 8.0) {
    untitled_DW.is_c3_untitled = untitled_IN_VVIR;
    untitled_DW.is_VVIR = untitled_IN_Initial_VVIR;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.VENTRICULAR_PULSE_WIDTH;
    untitled_DW.VVIR_amp = untitled_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.ATR_PACE_CTRL = 0.0;
    untitled_B.ATR_GND_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
    untitled_B.Z_VENT_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 7.0) {
    untitled_DW.is_c3_untitled = untitled_IN_AAIR;
    untitled_DW.is_AAIR = untitled_IN_Initial_AAIR;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.ATRIAL_PULSE_WIDTH;
    untitled_DW.AAIR_amp = untitled_B.ATRIAL_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.Z_VENT_CTRL = 0.0;
    untitled_B.VENT_GND_CTRL = 0.0;
    untitled_B.VENT_PACE_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 6.0) {
    untitled_DW.is_c3_untitled = untitled_IN_AOOR;
    untitled_DW.is_AOOR = untitled_IN_Initial_AOOR;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.ATRIAL_PULSE_WIDTH;
    untitled_DW.AOOR_amp = untitled_B.ATRIAL_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.Z_VENT_CTRL = 0.0;
    untitled_B.VENT_GND_CTRL = 0.0;
    untitled_B.VENT_PACE_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 2.0) {
    untitled_DW.is_c3_untitled = untitled_IN_AOO;
    untitled_DW.is_AOO = untitled_IN_Initial_AOO;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.ATRIAL_PULSE_WIDTH;
    untitled_DW.AOO_amp = untitled_B.ATRIAL_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.Z_VENT_CTRL = 0.0;
    untitled_B.VENT_GND_CTRL = 0.0;
    untitled_B.VENT_PACE_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
  } else if (untitled_B.PACING_MODE == 3.0) {
    untitled_DW.is_c3_untitled = untitled_IN_AAI;
    untitled_DW.is_AAI = untitled_IN_Initial_AAI;
    untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
      untitled_B.ATRIAL_PULSE_WIDTH;
    untitled_DW.AAI_amp = untitled_B.ATRIAL_AMPLITUDE / 5000.0 * 100.0;
    untitled_B.Z_VENT_CTRL = 0.0;
    untitled_B.VENT_GND_CTRL = 0.0;
    untitled_B.VENT_PACE_CTRL = 0.0;
    untitled_B.Z_ATR_CTRL = 0.0;
  } else {
    if (untitled_B.PACING_MODE == 4.0) {
      untitled_DW.is_c3_untitled = untitled_IN_VVI;
      untitled_DW.is_VVI = untitled_IN_Initial_VVI;
      untitled_DW.discharge_time = 60.0 / untitled_B.LOWER_RATE_LIMIT * 1000.0 -
        untitled_B.VENTRICULAR_PULSE_WIDTH;
      untitled_DW.VVI_amp = untitled_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_B.Z_VENT_CTRL = 0.0;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void untitled_VOO(void)
{
  if (untitled_B.PACING_MODE != 1.0) {
    untitled_DW.is_VOO = 0U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_VOO) {
     case untitled_IN_Charge_VOO:
      untitled_B.PACE_CHARGE_CTRL = 0.0;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.VENT_GND_CTRL = 0.0;
      untitled_B.VENT_PACE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_B.VENTRICULAR_PULSE_WIDTH)) {
        untitled_DW.is_VOO = untitled_IN_Discharge_VOO;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.VENT_PACE_CTRL = 0.0;
        untitled_B.VENT_GND_CTRL = 1.0;
        untitled_B.PACING_REF_PWM = untitled_DW.VOO_amp;
        untitled_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case untitled_IN_Discharge_VOO:
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 1.0;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_DW.discharge_time)) {
        untitled_DW.is_VOO = untitled_IN_Charge_VOO;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = 0.0;
        untitled_B.PACE_GND_CTRL = 1.0;
        untitled_B.VENT_GND_CTRL = 0.0;
        untitled_B.VENT_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_VOO: */
      untitled_B.ATR_PACE_CTRL = 0.0;
      untitled_B.ATR_GND_CTRL = 0.0;
      untitled_B.Z_ATR_CTRL = 0.0;
      untitled_B.Z_VENT_CTRL = 0.0;
      untitled_DW.is_VOO = untitled_IN_Discharge_VOO;
      untitled_DW.temporalCounter_i1 = 0U;
      untitled_B.PACE_GND_CTRL = 1.0;
      untitled_B.VENT_PACE_CTRL = 0.0;
      untitled_B.VENT_GND_CTRL = 1.0;
      untitled_B.PACING_REF_PWM = untitled_DW.VOO_amp;
      untitled_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

static void SystemCore_relea_b5oh5otl251gqo(const
  freedomk64f_fxos8700_untitled_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void SystemCore_delet_b5oh5otl251gqo(const
  freedomk64f_fxos8700_untitled_T *obj)
{
  SystemCore_relea_b5oh5otl251gqo(obj);
}

static void matlabCodegenHan_b5oh5otl251gqo(freedomk64f_fxos8700_untitled_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_b5oh5otl251gqo(obj);
  }
}

static void SystemCore_rele_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void SystemCore_dele_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj)
{
  SystemCore_rele_b5oh5otl251gqos(obj);
}

static void matlabCodegenHa_b5oh5otl251gqos(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_dele_b5oh5otl251gqos(obj);
  }
}

static void untitled_SystemCore_release_b(const freedomk64f_DigitalRead_untit_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void untitled_SystemCore_delete_b(const freedomk64f_DigitalRead_untit_T
  *obj)
{
  untitled_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(freedomk64f_DigitalRead_untit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete_b(obj);
  }
}

static void untitled_SystemCore_release(const freedomk64f_DigitalWrite_unti_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void untitled_SystemCore_delete(const freedomk64f_DigitalWrite_unti_T
  *obj)
{
  untitled_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_unti_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete(obj);
  }
}

static void un_SystemCore_release_b5oh5otl2(const
  freedomk64f_PWMOutput_untitle_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void unt_SystemCore_delete_b5oh5otl2(const
  freedomk64f_PWMOutput_untitle_T *obj)
{
  un_SystemCore_release_b5oh5otl2(obj);
}

static void matlabCodegenHandle_m_b5oh5otl2(freedomk64f_PWMOutput_untitle_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    unt_SystemCore_delete_b5oh5otl2(obj);
  }
}

static void untitled_SystemCore_setup(freedomk64f_fxos8700_untitled_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_RegisterValue;
  uint8_T b_SwappedDataBytes[2];
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void untitled_step(void)
{
  int16_T b_output[3];
  uint8_T status;
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x[2];
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;

  /* MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  if (untitled_DW.obj.SampleTime != untitled_P.FXOS87006AxesSensor_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(untitled_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, &status,
    1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(untitled_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, output_raw, 6U,
                      false, true);
    memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[0], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[1], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[2], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    b_output[0] = 0;
    b_output[1] = 0;
    b_output[2] = 0;
  }

  rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_output[0] >> 2) * 2.0 *
    0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_output[1] >> 2) * 2.0 *
    0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_output[2] >> 2) * 2.0 *
    0.244 / 1000.0;

  /* End of MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */

  /* Gain: '<S6>/Multiply' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/Constant'
   *  Math: '<S6>/Square'
   *  Math: '<S6>/Square1'
   *  Math: '<S6>/Square2'
   *  Sqrt: '<S6>/Square Root'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add2'
   */
  untitled_B.Multiply = fabs(sqrt((rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) + rtb_FXOS87006AxesSensor_idx_2 *
    rtb_FXOS87006AxesSensor_idx_2) - untitled_P.Constant_Value) *
    untitled_P.Multiply_Gain;

  /* Chart: '<Root>/Parameter_Definitions' */
  if (untitled_DW.is_active_c1_untitled == 0U) {
    untitled_DW.is_active_c1_untitled = 1U;
    untitled_DW.is_c1_untitled = untitl_IN_Parameter_Definitions;
    untitled_B.PACING_MODE = 4.0;
    untitled_B.LOWER_RATE_LIMIT = 120.0;
    untitled_B.UPPER_RATE_LIMIT = 180.0;
    untitled_B.ATRIAL_AMPLITUDE = 3500.0;
    untitled_B.VENTRICULAR_AMPLITUDE = 5000.0;
    untitled_B.ATRIAL_PULSE_WIDTH = 0.4;
    untitled_B.VENTRICULAR_PULSE_WIDTH = 0.4;
    untitled_B.ATRIAL_SENSITIVITY = 2.75;
    untitled_B.VENTRICULAR_SENSITIVITY = 2.5;
    untitled_B.ARP = 500.0;
    untitled_B.VRP = 320.0;
    untitled_B.PVARP = 250.0;
    untitled_B.HYSTERESIS = false;
    untitled_B.RATE_SMOOTHING = false;
    untitled_B.MAX_SENSOR_RATE = 120.0;
    untitled_B.ACTIVITY_THRESHOLD = 4.0;
    untitled_B.RESPONSE_FACTOR = 16.0;
    untitled_B.REACTION_TIME = 25.0;
    untitled_B.RECOVERY_TIME = 8.0;
  } else {
    untitled_B.PACING_MODE = 4.0;
    untitled_B.LOWER_RATE_LIMIT = 120.0;
    untitled_B.UPPER_RATE_LIMIT = 180.0;
    untitled_B.ATRIAL_AMPLITUDE = 3500.0;
    untitled_B.VENTRICULAR_AMPLITUDE = 5000.0;
    untitled_B.ATRIAL_PULSE_WIDTH = 0.4;
    untitled_B.VENTRICULAR_PULSE_WIDTH = 0.4;
    untitled_B.ATRIAL_SENSITIVITY = 2.75;
    untitled_B.VENTRICULAR_SENSITIVITY = 2.5;
    untitled_B.ARP = 500.0;
    untitled_B.VRP = 320.0;
    untitled_B.PVARP = 250.0;
    untitled_B.HYSTERESIS = false;
    untitled_B.RATE_SMOOTHING = false;
    untitled_B.MAX_SENSOR_RATE = 120.0;
    untitled_B.ACTIVITY_THRESHOLD = 4.0;
    untitled_B.RESPONSE_FACTOR = 16.0;
    untitled_B.REACTION_TIME = 25.0;
    untitled_B.RECOVERY_TIME = 8.0;
  }

  /* End of Chart: '<Root>/Parameter_Definitions' */

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product'
   */
  untitled_B.Min = untitled_B.Multiply * untitled_B.RESPONSE_FACTOR +
    untitled_B.LOWER_RATE_LIMIT;

  /* MinMax: '<S6>/Min' */
  if ((!(untitled_B.Min < untitled_B.MAX_SENSOR_RATE)) && (!rtIsNaN
       (untitled_B.MAX_SENSOR_RATE))) {
    /* Sum: '<S7>/Sum' */
    untitled_B.Min = untitled_B.MAX_SENSOR_RATE;
  }

  if ((!(untitled_B.Min < untitled_B.UPPER_RATE_LIMIT)) && (!rtIsNaN
       (untitled_B.UPPER_RATE_LIMIT))) {
    /* Sum: '<S7>/Sum' */
    untitled_B.Min = untitled_B.UPPER_RATE_LIMIT;
  }

  /* End of MinMax: '<S6>/Min' */

  /* Gain: '<S6>/Gain' */
  untitled_B.Gain = untitled_P.Gain_Gain * untitled_B.RECOVERY_TIME;

  /* Gain: '<S6>/Gain1' */
  untitled_B.Gain1 = untitled_P.Gain1_Gain * untitled_B.REACTION_TIME;

  /* Sum: '<S6>/Add1' */
  untitled_B.Add1 = untitled_B.ACTIVITY_THRESHOLD - untitled_B.Multiply;

  /* Chart: '<Root>/Chart1' */
  if (untitled_DW.temporalCounter_i1_a < MAX_uint32_T) {
    untitled_DW.temporalCounter_i1_a++;
  }

  if (untitled_DW.is_active_c6_untitled == 0U) {
    untitled_DW.is_active_c6_untitled = 1U;
    untitled_DW.is_c6_untitled = untitled_IN_Entry_State;
    untitled_DW.temporalCounter_i1_a = 0U;
    untitled_B.curr_HR = untitled_B.LOWER_RATE_LIMIT;
    untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.LOWER_RATE_LIMIT) /
      untitled_B.Gain1;
    untitled_DW.recovery_Rate = (untitled_B.LOWER_RATE_LIMIT - untitled_B.Min) /
      untitled_B.Gain;
  } else {
    switch (untitled_DW.is_c6_untitled) {
     case untitled_IN_Decrease_HR:
      if ((untitled_B.Add1 <= 0.0) && (untitled_DW.temporalCounter_i1_a >=
           (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Recovery_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.LOWER_RATE_LIMIT -
          untitled_B.curr_HR) / untitled_B.Gain1;
      } else if ((untitled_B.Add1 > 0.0) && (untitled_DW.temporalCounter_i1_a >=
                  (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Reaction_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.curr_HR) /
          untitled_B.Gain1;
      } else {
        if ((untitled_B.Add1 == untitled_DW.curr_Level) &&
            (untitled_DW.temporalCounter_i1_a >= (uint32_T)ceil(60.0 /
              untitled_B.curr_HR * 1000.0))) {
          if (untitled_B.curr_HR <= untitled_B.LOWER_RATE_LIMIT) {
            untitled_DW.is_c6_untitled = untitled_IN_Maintain_Lower_Rate;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR = untitled_B.LOWER_RATE_LIMIT;
          } else {
            untitled_DW.is_c6_untitled = untitled_IN_Decrease_HR;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
              untitled_DW.recovery_Rate * 1000.0;
          }
        }
      }
      break;

     case untitle_IN_Define_Reaction_Rate:
      if (untitled_B.curr_HR >= untitled_B.Min) {
        untitled_DW.is_c6_untitled = untitled_IN_Maintain_Upper_Rate;
        untitled_DW.temporalCounter_i1_a = 0U;
        untitled_B.curr_HR = untitled_B.Min;
      } else {
        untitled_DW.is_c6_untitled = untitled_IN_Increase_HR;
        untitled_DW.temporalCounter_i1_a = 0U;
        untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
          untitled_DW.reaction_Rate * 1000.0;
      }
      break;

     case untitle_IN_Define_Recovery_Rate:
      if (untitled_B.curr_HR <= untitled_B.LOWER_RATE_LIMIT) {
        untitled_DW.is_c6_untitled = untitled_IN_Maintain_Lower_Rate;
        untitled_DW.temporalCounter_i1_a = 0U;
        untitled_B.curr_HR = untitled_B.LOWER_RATE_LIMIT;
      } else {
        untitled_DW.is_c6_untitled = untitled_IN_Decrease_HR;
        untitled_DW.temporalCounter_i1_a = 0U;
        untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
          untitled_DW.recovery_Rate * 1000.0;
      }
      break;

     case untitled_IN_Entry_State:
      if ((untitled_B.Add1 <= 0.0) && (untitled_DW.temporalCounter_i1_a >=
           (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Recovery_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.LOWER_RATE_LIMIT -
          untitled_B.curr_HR) / untitled_B.Gain1;
      } else {
        if ((untitled_B.Add1 > 0.0) && (untitled_DW.temporalCounter_i1_a >=
             (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
          untitled_DW.is_c6_untitled = untitle_IN_Define_Reaction_Rate;
          untitled_DW.curr_Level = untitled_B.Add1;
          untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.curr_HR) /
            untitled_B.Gain1;
        }
      }
      break;

     case untitled_IN_Increase_HR:
      if ((untitled_B.Add1 <= 0.0) && (untitled_DW.temporalCounter_i1_a >=
           (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Recovery_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.LOWER_RATE_LIMIT -
          untitled_B.curr_HR) / untitled_B.Gain1;
      } else if ((untitled_B.Add1 > 0.0) && (untitled_DW.temporalCounter_i1_a >=
                  (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Reaction_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.curr_HR) /
          untitled_B.Gain1;
      } else {
        if ((untitled_B.Add1 == untitled_DW.curr_Level) &&
            (untitled_DW.temporalCounter_i1_a >= (uint32_T)ceil(60.0 /
              untitled_B.curr_HR * 1000.0))) {
          if (untitled_B.curr_HR >= untitled_B.Min) {
            untitled_DW.is_c6_untitled = untitled_IN_Maintain_Upper_Rate;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR = untitled_B.Min;
          } else {
            untitled_DW.is_c6_untitled = untitled_IN_Increase_HR;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
              untitled_DW.reaction_Rate * 1000.0;
          }
        }
      }
      break;

     case untitled_IN_Maintain_Lower_Rate:
      if ((untitled_B.Add1 <= 0.0) && (untitled_DW.temporalCounter_i1_a >=
           (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Recovery_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.LOWER_RATE_LIMIT -
          untitled_B.curr_HR) / untitled_B.Gain1;
      } else if ((untitled_B.Add1 > 0.0) && (untitled_DW.temporalCounter_i1_a >=
                  (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Reaction_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.curr_HR) /
          untitled_B.Gain1;
      } else {
        if ((untitled_B.Add1 == untitled_DW.curr_Level) &&
            (untitled_DW.temporalCounter_i1_a >= (uint32_T)ceil(60.0 /
              untitled_B.curr_HR * 1000.0))) {
          if (untitled_B.curr_HR <= untitled_B.LOWER_RATE_LIMIT) {
            untitled_DW.is_c6_untitled = untitled_IN_Maintain_Lower_Rate;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR = untitled_B.LOWER_RATE_LIMIT;
          } else {
            untitled_DW.is_c6_untitled = untitled_IN_Decrease_HR;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
              untitled_DW.recovery_Rate * 1000.0;
          }
        }
      }
      break;

     default:
      /* case IN_Maintain_Upper_Rate: */
      if ((untitled_B.Add1 <= 0.0) && (untitled_DW.temporalCounter_i1_a >=
           (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Recovery_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.LOWER_RATE_LIMIT -
          untitled_B.curr_HR) / untitled_B.Gain1;
      } else if ((untitled_B.Add1 > 0.0) && (untitled_DW.temporalCounter_i1_a >=
                  (uint32_T)ceil(60.0 / untitled_B.curr_HR * 1000.0))) {
        untitled_DW.is_c6_untitled = untitle_IN_Define_Reaction_Rate;
        untitled_DW.curr_Level = untitled_B.Add1;
        untitled_DW.reaction_Rate = (untitled_B.Min - untitled_B.curr_HR) /
          untitled_B.Gain1;
      } else {
        if ((untitled_B.Add1 == untitled_DW.curr_Level) &&
            (untitled_DW.temporalCounter_i1_a >= (uint32_T)ceil(60.0 /
              untitled_B.curr_HR * 1000.0))) {
          if (untitled_B.curr_HR >= untitled_B.Min) {
            untitled_DW.is_c6_untitled = untitled_IN_Maintain_Upper_Rate;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR = untitled_B.Min;
          } else {
            untitled_DW.is_c6_untitled = untitled_IN_Increase_HR;
            untitled_DW.temporalCounter_i1_a = 0U;
            untitled_B.curr_HR += 60.0 / untitled_B.curr_HR *
              untitled_DW.reaction_Rate * 1000.0;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Gain: '<S6>/Gain2' */
  untitled_B.Gain2 = untitled_P.Gain2_Gain * untitled_B.curr_HR;

  /* MATLABSystem: '<S2>/Digital Read3' */
  if (untitled_DW.obj_j.SampleTime != untitled_P.DigitalRead3_SampleTime) {
    untitled_DW.obj_j.SampleTime = untitled_P.DigitalRead3_SampleTime;
  }

  untitled_B.DigitalRead3 = MW_digitalIO_read
    (untitled_DW.obj_j.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read3' */

  /* MATLABSystem: '<S2>/Digital Read2' */
  if (untitled_DW.obj_h.SampleTime != untitled_P.DigitalRead2_SampleTime) {
    untitled_DW.obj_h.SampleTime = untitled_P.DigitalRead2_SampleTime;
  }

  untitled_B.DigitalRead2 = MW_digitalIO_read
    (untitled_DW.obj_h.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read2' */

  /* Chart: '<Root>/Pacemaker_States' */
  if (untitled_DW.temporalCounter_i1 < MAX_uint32_T) {
    untitled_DW.temporalCounter_i1++;
  }

  if (untitled_DW.is_active_c3_untitled == 0U) {
    untitled_DW.is_active_c3_untitled = 1U;
    untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
    untitled_B.VENT_CMP_REF_PWM = 52.0;
    untitled_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (untitled_DW.is_c3_untitled) {
     case untitled_IN_AAI:
      untitled_AAI();
      break;

     case untitled_IN_AAIR:
      untitled_AAIR();
      break;

     case untitled_IN_AOO:
      untitled_AOO();
      break;

     case untitled_IN_AOOR:
      untitled_AOOR();
      break;

     case untitled_IN_Initial_State:
      untitled_Initial_State();
      break;

     case untitled_IN_VOO:
      untitled_VOO();
      break;

     case untitled_IN_VOOR:
      if (untitled_B.PACING_MODE != 5.0) {
        untitled_DW.is_VOOR = 0U;
        untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
        untitled_B.VENT_CMP_REF_PWM = 52.0;
        untitled_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (untitled_DW.is_VOOR) {
         case untitled_IN_Charge_VOOR:
          untitled_B.PACE_CHARGE_CTRL = 0.0;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_GND_CTRL = 0.0;
          untitled_B.VENT_PACE_CTRL = 1.0;
          if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
              (untitled_B.VENTRICULAR_PULSE_WIDTH)) {
            untitled_DW.is_VOOR = untitled_IN_Discharge_VOOR;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_PACE_CTRL = 0.0;
            untitled_B.VENT_GND_CTRL = 1.0;
            untitled_B.PACING_REF_PWM = untitled_DW.VOOR_amp;
            untitled_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case untitled_IN_Discharge_VOOR:
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil(untitled_B.Gain2
               - untitled_B.VENTRICULAR_PULSE_WIDTH)) {
            untitled_DW.is_VOOR = untitled_IN_Charge_VOOR;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_CHARGE_CTRL = 0.0;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_GND_CTRL = 0.0;
            untitled_B.VENT_PACE_CTRL = 1.0;
          }
          break;

         default:
          /* case IN_Initial_VOOR: */
          untitled_B.ATR_PACE_CTRL = 0.0;
          untitled_B.ATR_GND_CTRL = 0.0;
          untitled_B.Z_ATR_CTRL = 0.0;
          untitled_B.Z_VENT_CTRL = 0.0;
          untitled_DW.is_VOOR = untitled_IN_Discharge_VOOR;
          untitled_DW.temporalCounter_i1 = 0U;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACING_REF_PWM = untitled_DW.VOOR_amp;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;

     case untitled_IN_VVI:
      if (untitled_B.PACING_MODE != 4.0) {
        untitled_DW.is_VVI = 0U;
        untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
        untitled_B.VENT_CMP_REF_PWM = 52.0;
        untitled_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (untitled_DW.is_VVI) {
         case untitled_IN_Charge_VVI:
          untitled_B.PACE_CHARGE_CTRL = 0.0;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_GND_CTRL = 0.0;
          untitled_B.VENT_PACE_CTRL = 1.0;
          if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
              (untitled_B.VENTRICULAR_PULSE_WIDTH)) {
            untitled_DW.is_VVI = untitled_IN_Discharge_VVI;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_PACE_CTRL = 0.0;
            untitled_B.VENT_GND_CTRL = 1.0;
            untitled_B.PACING_REF_PWM = untitled_DW.VVI_amp;
            untitled_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case untitled_IN_Discharge_VVI:
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          if ((untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
               (untitled_DW.discharge_time)) && (!untitled_B.DigitalRead3)) {
            untitled_DW.is_VVI = untitled_IN_Charge_VVI;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_CHARGE_CTRL = 0.0;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_GND_CTRL = 0.0;
            untitled_B.VENT_PACE_CTRL = 1.0;
          } else {
            if (untitled_B.DigitalRead3) {
              untitled_DW.is_VVI = untitled_IN_Discharge_VVI;
              untitled_DW.temporalCounter_i1 = 0U;
              untitled_B.PACE_GND_CTRL = 1.0;
              untitled_B.VENT_PACE_CTRL = 0.0;
              untitled_B.VENT_GND_CTRL = 1.0;
              untitled_B.PACING_REF_PWM = untitled_DW.VVI_amp;
              untitled_B.PACE_CHARGE_CTRL = 1.0;
            }
          }
          break;

         default:
          /* case IN_Initial_VVI: */
          untitled_B.ATR_PACE_CTRL = 0.0;
          untitled_B.ATR_GND_CTRL = 0.0;
          untitled_B.Z_ATR_CTRL = 0.0;
          untitled_B.Z_VENT_CTRL = 0.0;
          untitled_DW.is_VVI = untitled_IN_Discharge_VVI;
          untitled_DW.temporalCounter_i1 = 0U;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACING_REF_PWM = untitled_DW.VVI_amp;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;

     default:
      /* case IN_VVIR: */
      if (untitled_B.PACING_MODE != 8.0) {
        untitled_DW.is_VVIR = 0U;
        untitled_DW.is_c3_untitled = untitled_IN_Initial_State;
        untitled_B.VENT_CMP_REF_PWM = 52.0;
        untitled_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (untitled_DW.is_VVIR) {
         case untitled_IN_Charge_VVIR:
          untitled_B.PACE_CHARGE_CTRL = 0.0;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_GND_CTRL = 0.0;
          untitled_B.VENT_PACE_CTRL = 1.0;
          if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
              (untitled_B.VENTRICULAR_PULSE_WIDTH)) {
            untitled_DW.is_VVIR = untitled_IN_Discharge_VVI;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_PACE_CTRL = 0.0;
            untitled_B.VENT_GND_CTRL = 1.0;
            untitled_B.PACING_REF_PWM = untitled_DW.VVIR_amp;
            untitled_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case untitled_IN_Discharge_VVI:
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          if ((untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
               (untitled_DW.discharge_time)) && (!untitled_B.DigitalRead3)) {
            untitled_DW.is_VVIR = untitled_IN_Charge_VVIR;
            untitled_DW.temporalCounter_i1 = 0U;
            untitled_B.PACE_CHARGE_CTRL = 0.0;
            untitled_B.PACE_GND_CTRL = 1.0;
            untitled_B.VENT_GND_CTRL = 0.0;
            untitled_B.VENT_PACE_CTRL = 1.0;
          } else {
            if (untitled_B.DigitalRead3) {
              untitled_DW.is_VVIR = untitled_IN_Discharge_VVI;
              untitled_DW.temporalCounter_i1 = 0U;
              untitled_B.PACE_GND_CTRL = 1.0;
              untitled_B.VENT_PACE_CTRL = 0.0;
              untitled_B.VENT_GND_CTRL = 1.0;
              untitled_B.PACING_REF_PWM = untitled_DW.VVIR_amp;
              untitled_B.PACE_CHARGE_CTRL = 1.0;
            }
          }
          break;

         default:
          /* case IN_Initial_VVIR: */
          untitled_B.ATR_PACE_CTRL = 0.0;
          untitled_B.ATR_GND_CTRL = 0.0;
          untitled_B.Z_ATR_CTRL = 0.0;
          untitled_B.Z_VENT_CTRL = 0.0;
          untitled_DW.is_VVIR = untitled_IN_Discharge_VVI;
          untitled_DW.temporalCounter_i1 = 0U;
          untitled_B.PACE_GND_CTRL = 1.0;
          untitled_B.VENT_PACE_CTRL = 0.0;
          untitled_B.VENT_GND_CTRL = 1.0;
          untitled_B.PACING_REF_PWM = untitled_DW.VVIR_amp;
          untitled_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Pacemaker_States' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(untitled_DW.obj_l.MW_DIGITALIO_HANDLE,
                     untitled_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_m.MW_PWM_HANDLE,
                      untitled_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(untitled_DW.obj_b.MW_DIGITALIO_HANDLE,
                     untitled_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output1' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_c.MW_PWM_HANDLE, untitled_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(untitled_DW.obj_k.MW_PWM_HANDLE,
                      untitled_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(untitled_DW.obj_o.MW_DIGITALIO_HANDLE,
                     untitled_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(untitled_DW.obj_hb.MW_DIGITALIO_HANDLE,
                     untitled_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(untitled_DW.obj_g.MW_DIGITALIO_HANDLE,
                     untitled_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(untitled_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     untitled_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write9' */
  MW_digitalIO_write(untitled_DW.obj_oh.MW_DIGITALIO_HANDLE,
                     untitled_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write10' */
  MW_digitalIO_write(untitled_DW.obj_h0.MW_DIGITALIO_HANDLE,
                     untitled_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write' incorporates:
   *  Constant: '<S2>/Constant'
   */
  MW_digitalIO_write(untitled_DW.obj_bo.MW_DIGITALIO_HANDLE,
                     untitled_P.Constant_Value_a != 0.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (3187950145U);
  untitled_M->Sizes.checksums[1] = (4220979939U);
  untitled_M->Sizes.checksums[2] = (876549005U);
  untitled_M->Sizes.checksums[3] = (2467262817U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_fxos8700_untitled_T *obj;
    freedomk64f_DigitalRead_untit_T *obj_0;
    freedomk64f_DigitalWrite_unti_T *obj_1;
    freedomk64f_PWMOutput_untitle_T *obj_2;

    /* Start for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
    untitled_DW.obj.i2cobj.matlabCodegenIsDeleted = true;
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    obj = &untitled_DW.obj;
    untitled_DW.obj.isInitialized = 0;
    untitled_DW.obj.SampleTime = -1.0;
    obj->i2cobj.isInitialized = 0;
    obj->i2cobj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.SampleTime = untitled_P.FXOS87006AxesSensor_SampleTime;
    untitled_SystemCore_setup(&untitled_DW.obj);

    /* Start for MATLABSystem: '<S2>/Digital Read3' */
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
    untitled_DW.obj_j.isInitialized = 0;
    untitled_DW.obj_j.SampleTime = -1.0;
    untitled_DW.obj_j.matlabCodegenIsDeleted = false;
    untitled_DW.obj_j.SampleTime = untitled_P.DigitalRead3_SampleTime;
    obj_0 = &untitled_DW.obj_j;
    untitled_DW.obj_j.isSetupComplete = false;
    untitled_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    untitled_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read2' */
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    untitled_DW.obj_h.isInitialized = 0;
    untitled_DW.obj_h.SampleTime = -1.0;
    untitled_DW.obj_h.matlabCodegenIsDeleted = false;
    untitled_DW.obj_h.SampleTime = untitled_P.DigitalRead2_SampleTime;
    obj_0 = &untitled_DW.obj_h;
    untitled_DW.obj_h.isSetupComplete = false;
    untitled_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    untitled_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    untitled_DW.obj_l.matlabCodegenIsDeleted = true;
    untitled_DW.obj_l.isInitialized = 0;
    untitled_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_l;
    untitled_DW.obj_l.isSetupComplete = false;
    untitled_DW.obj_l.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    untitled_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    untitled_DW.obj_m.matlabCodegenIsDeleted = true;
    untitled_DW.obj_m.isInitialized = 0;
    untitled_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_2 = &untitled_DW.obj_m;
    untitled_DW.obj_m.isSetupComplete = false;
    untitled_DW.obj_m.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(untitled_DW.obj_m.MW_PWM_HANDLE);
    untitled_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    untitled_DW.obj_b.isInitialized = 0;
    untitled_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_b;
    untitled_DW.obj_b.isSetupComplete = false;
    untitled_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    untitled_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    untitled_DW.obj_c.matlabCodegenIsDeleted = true;
    untitled_DW.obj_c.isInitialized = 0;
    untitled_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_2 = &untitled_DW.obj_c;
    untitled_DW.obj_c.isSetupComplete = false;
    untitled_DW.obj_c.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(untitled_DW.obj_c.MW_PWM_HANDLE);
    untitled_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    untitled_DW.obj_k.matlabCodegenIsDeleted = true;
    untitled_DW.obj_k.isInitialized = 0;
    untitled_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_2 = &untitled_DW.obj_k;
    untitled_DW.obj_k.isSetupComplete = false;
    untitled_DW.obj_k.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(untitled_DW.obj_k.MW_PWM_HANDLE);
    untitled_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    untitled_DW.obj_o.isInitialized = 0;
    untitled_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_o;
    untitled_DW.obj_o.isSetupComplete = false;
    untitled_DW.obj_o.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    untitled_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    untitled_DW.obj_hb.matlabCodegenIsDeleted = true;
    untitled_DW.obj_hb.isInitialized = 0;
    untitled_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_hb;
    untitled_DW.obj_hb.isSetupComplete = false;
    untitled_DW.obj_hb.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    untitled_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
    untitled_DW.obj_g.isInitialized = 0;
    untitled_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_g;
    untitled_DW.obj_g.isSetupComplete = false;
    untitled_DW.obj_g.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    untitled_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    untitled_DW.obj_lh.matlabCodegenIsDeleted = true;
    untitled_DW.obj_lh.isInitialized = 0;
    untitled_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_lh;
    untitled_DW.obj_lh.isSetupComplete = false;
    untitled_DW.obj_lh.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    untitled_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write9' */
    untitled_DW.obj_oh.matlabCodegenIsDeleted = true;
    untitled_DW.obj_oh.isInitialized = 0;
    untitled_DW.obj_oh.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_oh;
    untitled_DW.obj_oh.isSetupComplete = false;
    untitled_DW.obj_oh.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    untitled_DW.obj_oh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write10' */
    untitled_DW.obj_h0.matlabCodegenIsDeleted = true;
    untitled_DW.obj_h0.isInitialized = 0;
    untitled_DW.obj_h0.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_h0;
    untitled_DW.obj_h0.isSetupComplete = false;
    untitled_DW.obj_h0.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    untitled_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    untitled_DW.obj_bo.matlabCodegenIsDeleted = true;
    untitled_DW.obj_bo.isInitialized = 0;
    untitled_DW.obj_bo.matlabCodegenIsDeleted = false;
    obj_1 = &untitled_DW.obj_bo;
    untitled_DW.obj_bo.isSetupComplete = false;
    untitled_DW.obj_bo.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    untitled_DW.obj_bo.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  matlabCodegenHan_b5oh5otl251gqo(&untitled_DW.obj);
  matlabCodegenHa_b5oh5otl251gqos(&untitled_DW.obj.i2cobj);

  /* Terminate for MATLABSystem: '<S2>/Digital Read3' */
  matlabCodegenHandle_matlabCod_b(&untitled_DW.obj_j);

  /* Terminate for MATLABSystem: '<S2>/Digital Read2' */
  matlabCodegenHandle_matlabCod_b(&untitled_DW.obj_h);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandle_m_b5oh5otl2(&untitled_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  matlabCodegenHandle_m_b5oh5otl2(&untitled_DW.obj_c);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHandle_m_b5oh5otl2(&untitled_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_hb);

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_g);

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S3>/Digital Write9' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_oh);

  /* Terminate for MATLABSystem: '<S3>/Digital Write10' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_h0);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_bo);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
