/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: project_model_UPDATE.c
 *
 * Code generated for Simulink model 'project_model_UPDATE'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov 21 16:25:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "project_model_UPDATE.h"
#include "project_model_UPDATE_private.h"
#include "project_model_UPDATE_dt.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define project_IN_Define_Reaction_Rate (2U)
#define project_IN_Define_Recovery_Rate (3U)
#define project__IN_Maintain_Lower_Rate (6U)
#define project__IN_Maintain_Upper_Rate (7U)
#define project_model_UP_IN_Decrease_HR (1U)
#define project_model_UP_IN_Entry_State (4U)
#define project_model_UP_IN_Increase_HR (5U)

/* Named constants for Chart: '<Root>/Pacemaker_States' */
#define project_model_IN_Discharge_AAIR (2U)
#define project_model_IN_Discharge_AOOR (2U)
#define project_model_IN_Discharge_VOOR (2U)
#define project_model_UPDATE_IN_AAI    (1U)
#define project_model_UPDATE_IN_AAIR   (2U)
#define project_model_UPDATE_IN_AOO    (3U)
#define project_model_UPDATE_IN_AOOR   (4U)
#define project_model_UPDATE_IN_VOO    (6U)
#define project_model_UPDATE_IN_VOOR   (7U)
#define project_model_UPDATE_IN_VVI    (8U)
#define project_model_UPDATE_IN_VVIR   (9U)
#define project_model_UPD_IN_Charge_AAI (1U)
#define project_model_UPD_IN_Charge_AOO (1U)
#define project_model_UPD_IN_Charge_VOO (1U)
#define project_model_UPD_IN_Charge_VVI (1U)
#define project_model_UP_IN_Charge_AAIR (1U)
#define project_model_UP_IN_Charge_AOOR (1U)
#define project_model_UP_IN_Charge_VOOR (1U)
#define project_model_UP_IN_Charge_VVIR (1U)
#define project_model_UP_IN_Initial_AAI (3U)
#define project_model_UP_IN_Initial_AOO (3U)
#define project_model_UP_IN_Initial_VOO (3U)
#define project_model_UP_IN_Initial_VVI (3U)
#define project_model_U_IN_Initial_AAIR (3U)
#define project_model_U_IN_Initial_AOOR (3U)
#define project_model_U_IN_Initial_VOOR (3U)
#define project_model_U_IN_Initial_VVIR (3U)
#define project_model__IN_Discharge_AAI (2U)
#define project_model__IN_Discharge_AOO (2U)
#define project_model__IN_Discharge_VOO (2U)
#define project_model__IN_Discharge_VVI (2U)
#define project_model__IN_Initial_State (5U)

/* Named constants for Chart: '<Root>/Parameter_Definitions' */
#define projec_IN_Parameter_Definitions (1U)

/* Block signals (default storage) */
B_project_model_UPDATE_T project_model_UPDATE_B;

/* Block states (default storage) */
DW_project_model_UPDATE_T project_model_UPDATE_DW;

/* Real-time model */
RT_MODEL_project_model_UPDATE_T project_model_UPDATE_M_;
RT_MODEL_project_model_UPDATE_T *const project_model_UPDATE_M =
  &project_model_UPDATE_M_;

/* Forward declaration for local functions */
static void project_model_UPDATE_AAI(void);
static void project_model_UPDATE_AAIR(void);
static void project_model_UPDATE_AOO(void);
static void project_model_UPDATE_AOOR(void);
static void project_model_UPD_Initial_State(void);
static void project_model_UPDATE_VOO(void);
static void SystemCore_relea_bmtrs1t3xldjeg(const
  freedomk64f_fxos8700_project__T *obj);
static void SystemCore_delet_bmtrs1t3xldjeg(const
  freedomk64f_fxos8700_project__T *obj);
static void matlabCodegenHan_bmtrs1t3xldjeg(freedomk64f_fxos8700_project__T *obj);
static void SystemCore_rele_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj);
static void SystemCore_dele_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHa_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj);
static void project_mo_SystemCore_release_b(const
  freedomk64f_DigitalRead_proje_T *obj);
static void project_mod_SystemCore_delete_b(const
  freedomk64f_DigitalRead_proje_T *obj);
static void matlabCodegenHandle_matlabCod_b(freedomk64f_DigitalRead_proje_T *obj);
static void project_mode_SystemCore_release(const
  freedomk64f_DigitalWrite_proj_T *obj);
static void project_model_SystemCore_delete(const
  freedomk64f_DigitalWrite_proj_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_proj_T *obj);
static void pr_SystemCore_release_bmtrs1t3x(const
  freedomk64f_PWMOutput_project_T *obj);
static void pro_SystemCore_delete_bmtrs1t3x(const
  freedomk64f_PWMOutput_project_T *obj);
static void matlabCodegenHandle_m_bmtrs1t3x(freedomk64f_PWMOutput_project_T *obj);
static void project_model__SystemCore_setup(freedomk64f_fxos8700_project__T *obj);

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPDATE_AAI(void)
{
  if (project_model_UPDATE_B.PACING_MODE != 3.0) {
    project_model_UPDATE_DW.is_AAI = 0U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_AAI) {
     case project_model_UPD_IN_Charge_AAI:
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_B.ATRIAL_PULSE_WIDTH)) {
        project_model_UPDATE_DW.is_AAI = project_model__IN_Discharge_AAI;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
        project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AAI_amp;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case project_model__IN_Discharge_AAI:
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      if ((project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
           (project_model_UPDATE_DW.discharge_time)) &&
          (!project_model_UPDATE_B.DigitalRead2)) {
        project_model_UPDATE_DW.is_AAI = project_model_UPD_IN_Charge_AAI;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      } else {
        if (project_model_UPDATE_B.DigitalRead2) {
          project_model_UPDATE_DW.is_AAI = project_model__IN_Discharge_AAI;
          project_model_UPDATE_DW.temporalCounter_i1 = 0U;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
          project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACING_REF_PWM =
            project_model_UPDATE_DW.AAI_amp;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Initial_AAI: */
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_DW.is_AAI = project_model__IN_Discharge_AAI;
      project_model_UPDATE_DW.temporalCounter_i1 = 0U;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AAI_amp;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPDATE_AAIR(void)
{
  if (project_model_UPDATE_B.PACING_MODE != 7.0) {
    project_model_UPDATE_DW.is_AAIR = 0U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_AAIR) {
     case project_model_UP_IN_Charge_AAIR:
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_B.ATRIAL_PULSE_WIDTH)) {
        project_model_UPDATE_DW.is_AAIR = project_model_IN_Discharge_AAIR;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
        project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AAIR_amp;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case project_model_IN_Discharge_AAIR:
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      if ((project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
           (project_model_UPDATE_DW.discharge_time)) &&
          (!project_model_UPDATE_B.DigitalRead2)) {
        project_model_UPDATE_DW.is_AAIR = project_model_UP_IN_Charge_AAIR;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      } else {
        if (project_model_UPDATE_B.DigitalRead2) {
          project_model_UPDATE_DW.is_AAIR = project_model_IN_Discharge_AAIR;
          project_model_UPDATE_DW.temporalCounter_i1 = 0U;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
          project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACING_REF_PWM =
            project_model_UPDATE_DW.AAIR_amp;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Initial_AAIR: */
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_DW.is_AAIR = project_model_IN_Discharge_AAIR;
      project_model_UPDATE_DW.temporalCounter_i1 = 0U;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AAIR_amp;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPDATE_AOO(void)
{
  if (project_model_UPDATE_B.PACING_MODE != 2.0) {
    project_model_UPDATE_DW.is_AOO = 0U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_AOO) {
     case project_model_UPD_IN_Charge_AOO:
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_B.ATRIAL_PULSE_WIDTH)) {
        project_model_UPDATE_DW.is_AOO = project_model__IN_Discharge_AOO;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
        project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AOO_amp;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case project_model__IN_Discharge_AOO:
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_DW.discharge_time)) {
        project_model_UPDATE_DW.is_AOO = project_model_UPD_IN_Charge_AOO;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_AOO: */
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_DW.is_AOO = project_model__IN_Discharge_AOO;
      project_model_UPDATE_DW.temporalCounter_i1 = 0U;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AOO_amp;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPDATE_AOOR(void)
{
  if (project_model_UPDATE_B.PACING_MODE != 6.0) {
    project_model_UPDATE_DW.is_AOOR = 0U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_AOOR) {
     case project_model_UP_IN_Charge_AOOR:
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_B.ATRIAL_PULSE_WIDTH)) {
        project_model_UPDATE_DW.is_AOOR = project_model_IN_Discharge_AOOR;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
        project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AOOR_amp;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case project_model_IN_Discharge_AOOR:
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_DW.discharge_time)) {
        project_model_UPDATE_DW.is_AOOR = project_model_UP_IN_Charge_AOOR;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
        project_model_UPDATE_B.ATR_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_AOOR: */
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_DW.is_AOOR = project_model_IN_Discharge_AOOR;
      project_model_UPDATE_DW.temporalCounter_i1 = 0U;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.AOOR_amp;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPD_Initial_State(void)
{
  project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
  project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  if (project_model_UPDATE_B.PACING_MODE == 1.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_VOO;
    project_model_UPDATE_DW.is_VOO = project_model_UP_IN_Initial_VOO;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH;
    project_model_UPDATE_DW.VOO_amp =
      project_model_UPDATE_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
    project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 5.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_VOOR;
    project_model_UPDATE_DW.is_VOOR = project_model_U_IN_Initial_VOOR;
    project_model_UPDATE_DW.VOOR_amp =
      project_model_UPDATE_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
    project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 8.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_VVIR;
    project_model_UPDATE_DW.is_VVIR = project_model_U_IN_Initial_VVIR;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH;
    project_model_UPDATE_DW.VVIR_amp =
      project_model_UPDATE_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
    project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
    project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 7.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_AAIR;
    project_model_UPDATE_DW.is_AAIR = project_model_U_IN_Initial_AAIR;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.ATRIAL_PULSE_WIDTH;
    project_model_UPDATE_DW.AAIR_amp = project_model_UPDATE_B.ATRIAL_AMPLITUDE /
      5000.0 * 100.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
    project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
    project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 6.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_AOOR;
    project_model_UPDATE_DW.is_AOOR = project_model_U_IN_Initial_AOOR;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.ATRIAL_PULSE_WIDTH;
    project_model_UPDATE_DW.AOOR_amp = project_model_UPDATE_B.ATRIAL_AMPLITUDE /
      5000.0 * 100.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
    project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
    project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 2.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_AOO;
    project_model_UPDATE_DW.is_AOO = project_model_UP_IN_Initial_AOO;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.ATRIAL_PULSE_WIDTH;
    project_model_UPDATE_DW.AOO_amp = project_model_UPDATE_B.ATRIAL_AMPLITUDE /
      5000.0 * 100.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
    project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
    project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
  } else if (project_model_UPDATE_B.PACING_MODE == 3.0) {
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model_UPDATE_IN_AAI;
    project_model_UPDATE_DW.is_AAI = project_model_UP_IN_Initial_AAI;
    project_model_UPDATE_DW.discharge_time = 60.0 /
      project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
      project_model_UPDATE_B.ATRIAL_PULSE_WIDTH;
    project_model_UPDATE_DW.AAI_amp = project_model_UPDATE_B.ATRIAL_AMPLITUDE /
      5000.0 * 100.0;
    project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
    project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
    project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
    project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
  } else {
    if (project_model_UPDATE_B.PACING_MODE == 4.0) {
      project_model_UPDATE_DW.is_c3_project_model_UPDATE =
        project_model_UPDATE_IN_VVI;
      project_model_UPDATE_DW.is_VVI = project_model_UP_IN_Initial_VVI;
      project_model_UPDATE_DW.discharge_time = 60.0 /
        project_model_UPDATE_B.LOWER_RATE_LIMIT * 1000.0 -
        project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH;
      project_model_UPDATE_DW.VVI_amp =
        project_model_UPDATE_B.VENTRICULAR_AMPLITUDE / 5000.0 * 100.0;
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
    }
  }
}

/* Function for Chart: '<Root>/Pacemaker_States' */
static void project_model_UPDATE_VOO(void)
{
  if (project_model_UPDATE_B.PACING_MODE != 1.0) {
    project_model_UPDATE_DW.is_VOO = 0U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_VOO) {
     case project_model_UPD_IN_Charge_VOO:
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH)) {
        project_model_UPDATE_DW.is_VOO = project_model__IN_Discharge_VOO;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
        project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
        project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.VOO_amp;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      }
      break;

     case project_model__IN_Discharge_VOO:
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
          (project_model_UPDATE_DW.discharge_time)) {
        project_model_UPDATE_DW.is_VOO = project_model_UPD_IN_Charge_VOO;
        project_model_UPDATE_DW.temporalCounter_i1 = 0U;
        project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
        project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
        project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
        project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_Initial_VOO: */
      project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
      project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
      project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
      project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
      project_model_UPDATE_DW.is_VOO = project_model__IN_Discharge_VOO;
      project_model_UPDATE_DW.temporalCounter_i1 = 0U;
      project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
      project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
      project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
      project_model_UPDATE_B.PACING_REF_PWM = project_model_UPDATE_DW.VOO_amp;
      project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
      break;
    }
  }
}

static void SystemCore_relea_bmtrs1t3xldjeg(const
  freedomk64f_fxos8700_project__T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void SystemCore_delet_bmtrs1t3xldjeg(const
  freedomk64f_fxos8700_project__T *obj)
{
  SystemCore_relea_bmtrs1t3xldjeg(obj);
}

static void matlabCodegenHan_bmtrs1t3xldjeg(freedomk64f_fxos8700_project__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_bmtrs1t3xldjeg(obj);
  }
}

static void SystemCore_rele_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void SystemCore_dele_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj)
{
  SystemCore_rele_bmtrs1t3xldjegj(obj);
}

static void matlabCodegenHa_bmtrs1t3xldjegj(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_dele_bmtrs1t3xldjegj(obj);
  }
}

static void project_mo_SystemCore_release_b(const
  freedomk64f_DigitalRead_proje_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void project_mod_SystemCore_delete_b(const
  freedomk64f_DigitalRead_proje_T *obj)
{
  project_mo_SystemCore_release_b(obj);
}

static void matlabCodegenHandle_matlabCod_b(freedomk64f_DigitalRead_proje_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    project_mod_SystemCore_delete_b(obj);
  }
}

static void project_mode_SystemCore_release(const
  freedomk64f_DigitalWrite_proj_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void project_model_SystemCore_delete(const
  freedomk64f_DigitalWrite_proj_T *obj)
{
  project_mode_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_proj_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    project_model_SystemCore_delete(obj);
  }
}

static void pr_SystemCore_release_bmtrs1t3x(const
  freedomk64f_PWMOutput_project_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void pro_SystemCore_delete_bmtrs1t3x(const
  freedomk64f_PWMOutput_project_T *obj)
{
  pr_SystemCore_release_bmtrs1t3x(obj);
}

static void matlabCodegenHandle_m_bmtrs1t3x(freedomk64f_PWMOutput_project_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pro_SystemCore_delete_bmtrs1t3x(obj);
  }
}

static void project_model__SystemCore_setup(freedomk64f_fxos8700_project__T *obj)
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
void project_model_UPDATE_step(void)
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
  if (project_model_UPDATE_DW.obj.SampleTime !=
      project_model_UPDATE_P.FXOS87006AxesSensor_SampleTime) {
    project_model_UPDATE_DW.obj.SampleTime =
      project_model_UPDATE_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(project_model_UPDATE_DW.obj.i2cobj.MW_I2C_HANDLE,
    29U, &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(project_model_UPDATE_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                      output_raw, 6U, false, true);
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

  /* Gain: '<S6>/Gain3' incorporates:
   *  Math: '<S6>/Square'
   *  Math: '<S6>/Square1'
   *  Math: '<S6>/Square2'
   *  Sqrt: '<S6>/Square Root'
   *  Sum: '<S6>/Add'
   */
  rtb_FXOS87006AxesSensor_idx_0 = sqrt((rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) + rtb_FXOS87006AxesSensor_idx_2 *
    rtb_FXOS87006AxesSensor_idx_2) * project_model_UPDATE_P.Gain3_Gain;

  /* Chart: '<Root>/Parameter_Definitions' */
  if (project_model_UPDATE_DW.is_active_c1_project_model_UPDA == 0U) {
    project_model_UPDATE_DW.is_active_c1_project_model_UPDA = 1U;
    project_model_UPDATE_DW.is_c1_project_model_UPDATE =
      projec_IN_Parameter_Definitions;
    project_model_UPDATE_B.PACING_MODE = 4.0;
    project_model_UPDATE_B.LOWER_RATE_LIMIT = 120.0;
    project_model_UPDATE_B.UPPER_RATE_LIMIT = 180.0;
    project_model_UPDATE_B.ATRIAL_AMPLITUDE = 3500.0;
    project_model_UPDATE_B.VENTRICULAR_AMPLITUDE = 5000.0;
    project_model_UPDATE_B.ATRIAL_PULSE_WIDTH = 0.4;
    project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH = 0.4;
    project_model_UPDATE_B.ATRIAL_SENSITIVITY = 2.75;
    project_model_UPDATE_B.VENTRICULAR_SENSITIVITY = 2.5;
    project_model_UPDATE_B.ARP = 500.0;
    project_model_UPDATE_B.VRP = 320.0;
    project_model_UPDATE_B.PVARP = 250.0;
    project_model_UPDATE_B.HYSTERESIS = false;
    project_model_UPDATE_B.RATE_SMOOTHING = false;
    project_model_UPDATE_B.MAX_SENSOR_RATE = 120.0;
    project_model_UPDATE_B.ACTIVITY_THRESHOLD = 4.0;
    project_model_UPDATE_B.RESPONSE_FACTOR = 16.0;
    project_model_UPDATE_B.REACTION_TIME = 25.0;
    project_model_UPDATE_B.RECOVERY_TIME = 8.0;
  } else {
    project_model_UPDATE_B.PACING_MODE = 4.0;
    project_model_UPDATE_B.LOWER_RATE_LIMIT = 120.0;
    project_model_UPDATE_B.UPPER_RATE_LIMIT = 180.0;
    project_model_UPDATE_B.ATRIAL_AMPLITUDE = 3500.0;
    project_model_UPDATE_B.VENTRICULAR_AMPLITUDE = 5000.0;
    project_model_UPDATE_B.ATRIAL_PULSE_WIDTH = 0.4;
    project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH = 0.4;
    project_model_UPDATE_B.ATRIAL_SENSITIVITY = 2.75;
    project_model_UPDATE_B.VENTRICULAR_SENSITIVITY = 2.5;
    project_model_UPDATE_B.ARP = 500.0;
    project_model_UPDATE_B.VRP = 320.0;
    project_model_UPDATE_B.PVARP = 250.0;
    project_model_UPDATE_B.HYSTERESIS = false;
    project_model_UPDATE_B.RATE_SMOOTHING = false;
    project_model_UPDATE_B.MAX_SENSOR_RATE = 120.0;
    project_model_UPDATE_B.ACTIVITY_THRESHOLD = 4.0;
    project_model_UPDATE_B.RESPONSE_FACTOR = 16.0;
    project_model_UPDATE_B.REACTION_TIME = 25.0;
    project_model_UPDATE_B.RECOVERY_TIME = 8.0;
  }

  /* End of Chart: '<Root>/Parameter_Definitions' */

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product'
   */
  project_model_UPDATE_B.Min = rtb_FXOS87006AxesSensor_idx_0 *
    project_model_UPDATE_B.RESPONSE_FACTOR +
    project_model_UPDATE_B.LOWER_RATE_LIMIT;

  /* MinMax: '<S6>/Min' */
  if ((!(project_model_UPDATE_B.Min < project_model_UPDATE_B.MAX_SENSOR_RATE)) &&
      (!rtIsNaN(project_model_UPDATE_B.MAX_SENSOR_RATE))) {
    /* Sum: '<S7>/Sum' */
    project_model_UPDATE_B.Min = project_model_UPDATE_B.MAX_SENSOR_RATE;
  }

  /* End of MinMax: '<S6>/Min' */

  /* Gain: '<S6>/Gain' */
  project_model_UPDATE_B.Gain = project_model_UPDATE_P.Gain_Gain *
    project_model_UPDATE_B.RECOVERY_TIME;

  /* Gain: '<S6>/Gain1' */
  project_model_UPDATE_B.Gain1 = project_model_UPDATE_P.Gain1_Gain *
    project_model_UPDATE_B.REACTION_TIME;

  /* Sum: '<S6>/Add1' */
  project_model_UPDATE_B.Add1 = project_model_UPDATE_B.ACTIVITY_THRESHOLD +
    rtb_FXOS87006AxesSensor_idx_0;

  /* Chart: '<Root>/Chart1' */
  if (project_model_UPDATE_DW.temporalCounter_i1_g < MAX_uint32_T) {
    project_model_UPDATE_DW.temporalCounter_i1_g++;
  }

  if (project_model_UPDATE_DW.is_active_c6_project_model_UPDA == 0U) {
    project_model_UPDATE_DW.is_active_c6_project_model_UPDA = 1U;
    project_model_UPDATE_DW.is_c6_project_model_UPDATE =
      project_model_UP_IN_Entry_State;
    project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
    project_model_UPDATE_B.curr_HR = project_model_UPDATE_B.LOWER_RATE_LIMIT;
    project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
      project_model_UPDATE_B.LOWER_RATE_LIMIT) / project_model_UPDATE_B.Gain1;
    project_model_UPDATE_DW.recovery_Rate =
      (project_model_UPDATE_B.LOWER_RATE_LIMIT - project_model_UPDATE_B.Min) /
      project_model_UPDATE_B.Gain;
  } else {
    switch (project_model_UPDATE_DW.is_c6_project_model_UPDATE) {
     case project_model_UP_IN_Decrease_HR:
      if ((project_model_UPDATE_B.Add1 <= 0.0) &&
          (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0 /
            project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Recovery_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate =
          (project_model_UPDATE_B.LOWER_RATE_LIMIT -
           project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else if ((project_model_UPDATE_B.Add1 > 0.0) &&
                 (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil
                  (60.0 / project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Reaction_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
          project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else {
        if ((project_model_UPDATE_B.Add1 == project_model_UPDATE_DW.curr_Level) &&
            (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0
              / project_model_UPDATE_B.curr_HR * 1000.0))) {
          if (project_model_UPDATE_B.curr_HR <=
              project_model_UPDATE_B.LOWER_RATE_LIMIT) {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project__IN_Maintain_Lower_Rate;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR =
              project_model_UPDATE_B.LOWER_RATE_LIMIT;
          } else {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project_model_UP_IN_Decrease_HR;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR += 60.0 /
              project_model_UPDATE_B.curr_HR *
              project_model_UPDATE_DW.recovery_Rate * 1000.0;
          }
        }
      }
      break;

     case project_IN_Define_Reaction_Rate:
      if (project_model_UPDATE_B.curr_HR >= project_model_UPDATE_B.Min) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project__IN_Maintain_Upper_Rate;
        project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
        project_model_UPDATE_B.curr_HR = project_model_UPDATE_B.Min;
      } else {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_model_UP_IN_Increase_HR;
        project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
        project_model_UPDATE_B.curr_HR += 60.0 / project_model_UPDATE_B.curr_HR *
          project_model_UPDATE_DW.reaction_Rate * 1000.0;
      }
      break;

     case project_IN_Define_Recovery_Rate:
      if (project_model_UPDATE_B.curr_HR <=
          project_model_UPDATE_B.LOWER_RATE_LIMIT) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project__IN_Maintain_Lower_Rate;
        project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
        project_model_UPDATE_B.curr_HR = project_model_UPDATE_B.LOWER_RATE_LIMIT;
      } else {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_model_UP_IN_Decrease_HR;
        project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
        project_model_UPDATE_B.curr_HR += 60.0 / project_model_UPDATE_B.curr_HR *
          project_model_UPDATE_DW.recovery_Rate * 1000.0;
      }
      break;

     case project_model_UP_IN_Entry_State:
      if ((project_model_UPDATE_B.Add1 <= 0.0) &&
          (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0 /
            project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Recovery_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate =
          (project_model_UPDATE_B.LOWER_RATE_LIMIT -
           project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else {
        if ((project_model_UPDATE_B.Add1 > 0.0) &&
            (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0
              / project_model_UPDATE_B.curr_HR * 1000.0))) {
          project_model_UPDATE_DW.is_c6_project_model_UPDATE =
            project_IN_Define_Reaction_Rate;
          project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
          project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
            project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
        }
      }
      break;

     case project_model_UP_IN_Increase_HR:
      if ((project_model_UPDATE_B.Add1 <= 0.0) &&
          (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0 /
            project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Recovery_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate =
          (project_model_UPDATE_B.LOWER_RATE_LIMIT -
           project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else if ((project_model_UPDATE_B.Add1 > 0.0) &&
                 (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil
                  (60.0 / project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Reaction_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
          project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else {
        if ((project_model_UPDATE_B.Add1 == project_model_UPDATE_DW.curr_Level) &&
            (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0
              / project_model_UPDATE_B.curr_HR * 1000.0))) {
          if (project_model_UPDATE_B.curr_HR >= project_model_UPDATE_B.Min) {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project__IN_Maintain_Upper_Rate;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR = project_model_UPDATE_B.Min;
          } else {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project_model_UP_IN_Increase_HR;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR += 60.0 /
              project_model_UPDATE_B.curr_HR *
              project_model_UPDATE_DW.reaction_Rate * 1000.0;
          }
        }
      }
      break;

     case project__IN_Maintain_Lower_Rate:
      if ((project_model_UPDATE_B.Add1 <= 0.0) &&
          (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0 /
            project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Recovery_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate =
          (project_model_UPDATE_B.LOWER_RATE_LIMIT -
           project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else if ((project_model_UPDATE_B.Add1 > 0.0) &&
                 (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil
                  (60.0 / project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Reaction_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
          project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else {
        if ((project_model_UPDATE_B.Add1 == project_model_UPDATE_DW.curr_Level) &&
            (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0
              / project_model_UPDATE_B.curr_HR * 1000.0))) {
          if (project_model_UPDATE_B.curr_HR <=
              project_model_UPDATE_B.LOWER_RATE_LIMIT) {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project__IN_Maintain_Lower_Rate;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR =
              project_model_UPDATE_B.LOWER_RATE_LIMIT;
          } else {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project_model_UP_IN_Decrease_HR;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR += 60.0 /
              project_model_UPDATE_B.curr_HR *
              project_model_UPDATE_DW.recovery_Rate * 1000.0;
          }
        }
      }
      break;

     default:
      /* case IN_Maintain_Upper_Rate: */
      if ((project_model_UPDATE_B.Add1 <= 0.0) &&
          (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0 /
            project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Recovery_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate =
          (project_model_UPDATE_B.LOWER_RATE_LIMIT -
           project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else if ((project_model_UPDATE_B.Add1 > 0.0) &&
                 (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil
                  (60.0 / project_model_UPDATE_B.curr_HR * 1000.0))) {
        project_model_UPDATE_DW.is_c6_project_model_UPDATE =
          project_IN_Define_Reaction_Rate;
        project_model_UPDATE_DW.curr_Level = project_model_UPDATE_B.Add1;
        project_model_UPDATE_DW.reaction_Rate = (project_model_UPDATE_B.Min -
          project_model_UPDATE_B.curr_HR) / project_model_UPDATE_B.Gain1;
      } else {
        if ((project_model_UPDATE_B.Add1 == project_model_UPDATE_DW.curr_Level) &&
            (project_model_UPDATE_DW.temporalCounter_i1_g >= (uint32_T)ceil(60.0
              / project_model_UPDATE_B.curr_HR * 1000.0))) {
          if (project_model_UPDATE_B.curr_HR >= project_model_UPDATE_B.Min) {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project__IN_Maintain_Upper_Rate;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR = project_model_UPDATE_B.Min;
          } else {
            project_model_UPDATE_DW.is_c6_project_model_UPDATE =
              project_model_UP_IN_Increase_HR;
            project_model_UPDATE_DW.temporalCounter_i1_g = 0U;
            project_model_UPDATE_B.curr_HR += 60.0 /
              project_model_UPDATE_B.curr_HR *
              project_model_UPDATE_DW.reaction_Rate * 1000.0;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Gain: '<S6>/Gain2' */
  project_model_UPDATE_B.Gain2 = project_model_UPDATE_P.Gain2_Gain *
    project_model_UPDATE_B.curr_HR;

  /* MATLABSystem: '<S2>/Digital Read3' */
  if (project_model_UPDATE_DW.obj_c.SampleTime !=
      project_model_UPDATE_P.DigitalRead3_SampleTime) {
    project_model_UPDATE_DW.obj_c.SampleTime =
      project_model_UPDATE_P.DigitalRead3_SampleTime;
  }

  project_model_UPDATE_B.DigitalRead3 = MW_digitalIO_read
    (project_model_UPDATE_DW.obj_c.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read3' */

  /* MATLABSystem: '<S2>/Digital Read2' */
  if (project_model_UPDATE_DW.obj_g.SampleTime !=
      project_model_UPDATE_P.DigitalRead2_SampleTime) {
    project_model_UPDATE_DW.obj_g.SampleTime =
      project_model_UPDATE_P.DigitalRead2_SampleTime;
  }

  project_model_UPDATE_B.DigitalRead2 = MW_digitalIO_read
    (project_model_UPDATE_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read2' */

  /* Chart: '<Root>/Pacemaker_States' */
  if (project_model_UPDATE_DW.temporalCounter_i1 < MAX_uint32_T) {
    project_model_UPDATE_DW.temporalCounter_i1++;
  }

  if (project_model_UPDATE_DW.is_active_c3_project_model_UPDA == 0U) {
    project_model_UPDATE_DW.is_active_c3_project_model_UPDA = 1U;
    project_model_UPDATE_DW.is_c3_project_model_UPDATE =
      project_model__IN_Initial_State;
    project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
    project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
  } else {
    switch (project_model_UPDATE_DW.is_c3_project_model_UPDATE) {
     case project_model_UPDATE_IN_AAI:
      project_model_UPDATE_AAI();
      break;

     case project_model_UPDATE_IN_AAIR:
      project_model_UPDATE_AAIR();
      break;

     case project_model_UPDATE_IN_AOO:
      project_model_UPDATE_AOO();
      break;

     case project_model_UPDATE_IN_AOOR:
      project_model_UPDATE_AOOR();
      break;

     case project_model__IN_Initial_State:
      project_model_UPD_Initial_State();
      break;

     case project_model_UPDATE_IN_VOO:
      project_model_UPDATE_VOO();
      break;

     case project_model_UPDATE_IN_VOOR:
      if (project_model_UPDATE_B.PACING_MODE != 5.0) {
        project_model_UPDATE_DW.is_VOOR = 0U;
        project_model_UPDATE_DW.is_c3_project_model_UPDATE =
          project_model__IN_Initial_State;
        project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
        project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (project_model_UPDATE_DW.is_VOOR) {
         case project_model_UP_IN_Charge_VOOR:
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
              (project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH)) {
            project_model_UPDATE_DW.is_VOOR = project_model_IN_Discharge_VOOR;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
            project_model_UPDATE_B.PACING_REF_PWM =
              project_model_UPDATE_DW.VOOR_amp;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case project_model_IN_Discharge_VOOR:
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
              (project_model_UPDATE_B.Gain2 -
               project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH)) {
            project_model_UPDATE_DW.is_VOOR = project_model_UP_IN_Charge_VOOR;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          }
          break;

         default:
          /* case IN_Initial_VOOR: */
          project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
          project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
          project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
          project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
          project_model_UPDATE_DW.is_VOOR = project_model_IN_Discharge_VOOR;
          project_model_UPDATE_DW.temporalCounter_i1 = 0U;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACING_REF_PWM =
            project_model_UPDATE_DW.VOOR_amp;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;

     case project_model_UPDATE_IN_VVI:
      if (project_model_UPDATE_B.PACING_MODE != 4.0) {
        project_model_UPDATE_DW.is_VVI = 0U;
        project_model_UPDATE_DW.is_c3_project_model_UPDATE =
          project_model__IN_Initial_State;
        project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
        project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (project_model_UPDATE_DW.is_VVI) {
         case project_model_UPD_IN_Charge_VVI:
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
              (project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH)) {
            project_model_UPDATE_DW.is_VVI = project_model__IN_Discharge_VVI;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
            project_model_UPDATE_B.PACING_REF_PWM =
              project_model_UPDATE_DW.VVI_amp;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case project_model__IN_Discharge_VVI:
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          if ((project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
               (project_model_UPDATE_DW.discharge_time)) &&
              (!project_model_UPDATE_B.DigitalRead3)) {
            project_model_UPDATE_DW.is_VVI = project_model_UPD_IN_Charge_VVI;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          } else {
            if (project_model_UPDATE_B.DigitalRead3) {
              project_model_UPDATE_DW.is_VVI = project_model__IN_Discharge_VVI;
              project_model_UPDATE_DW.temporalCounter_i1 = 0U;
              project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
              project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
              project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
              project_model_UPDATE_B.PACING_REF_PWM =
                project_model_UPDATE_DW.VVI_amp;
              project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
            }
          }
          break;

         default:
          /* case IN_Initial_VVI: */
          project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
          project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
          project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
          project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
          project_model_UPDATE_DW.is_VVI = project_model__IN_Discharge_VVI;
          project_model_UPDATE_DW.temporalCounter_i1 = 0U;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACING_REF_PWM =
            project_model_UPDATE_DW.VVI_amp;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;

     default:
      /* case IN_VVIR: */
      if (project_model_UPDATE_B.PACING_MODE != 8.0) {
        project_model_UPDATE_DW.is_VVIR = 0U;
        project_model_UPDATE_DW.is_c3_project_model_UPDATE =
          project_model__IN_Initial_State;
        project_model_UPDATE_B.VENT_CMP_REF_PWM = 52.0;
        project_model_UPDATE_B.ATR_CMP_REF_PWM = 51.0;
      } else {
        switch (project_model_UPDATE_DW.is_VVIR) {
         case project_model_UP_IN_Charge_VVIR:
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          if (project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
              (project_model_UPDATE_B.VENTRICULAR_PULSE_WIDTH)) {
            project_model_UPDATE_DW.is_VVIR = project_model__IN_Discharge_VVI;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
            project_model_UPDATE_B.PACING_REF_PWM =
              project_model_UPDATE_DW.VVIR_amp;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          }
          break;

         case project_model__IN_Discharge_VVI:
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          if ((project_model_UPDATE_DW.temporalCounter_i1 >= (uint32_T)ceil
               (project_model_UPDATE_DW.discharge_time)) &&
              (!project_model_UPDATE_B.DigitalRead3)) {
            project_model_UPDATE_DW.is_VVIR = project_model_UP_IN_Charge_VVIR;
            project_model_UPDATE_DW.temporalCounter_i1 = 0U;
            project_model_UPDATE_B.PACE_CHARGE_CTRL = 0.0;
            project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
            project_model_UPDATE_B.VENT_GND_CTRL = 0.0;
            project_model_UPDATE_B.VENT_PACE_CTRL = 1.0;
          } else {
            if (project_model_UPDATE_B.DigitalRead3) {
              project_model_UPDATE_DW.is_VVIR = project_model__IN_Discharge_VVI;
              project_model_UPDATE_DW.temporalCounter_i1 = 0U;
              project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
              project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
              project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
              project_model_UPDATE_B.PACING_REF_PWM =
                project_model_UPDATE_DW.VVIR_amp;
              project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
            }
          }
          break;

         default:
          /* case IN_Initial_VVIR: */
          project_model_UPDATE_B.ATR_PACE_CTRL = 0.0;
          project_model_UPDATE_B.ATR_GND_CTRL = 0.0;
          project_model_UPDATE_B.Z_ATR_CTRL = 0.0;
          project_model_UPDATE_B.Z_VENT_CTRL = 0.0;
          project_model_UPDATE_DW.is_VVIR = project_model__IN_Discharge_VVI;
          project_model_UPDATE_DW.temporalCounter_i1 = 0U;
          project_model_UPDATE_B.PACE_GND_CTRL = 1.0;
          project_model_UPDATE_B.VENT_PACE_CTRL = 0.0;
          project_model_UPDATE_B.VENT_GND_CTRL = 1.0;
          project_model_UPDATE_B.PACING_REF_PWM =
            project_model_UPDATE_DW.VVIR_amp;
          project_model_UPDATE_B.PACE_CHARGE_CTRL = 1.0;
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Pacemaker_States' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_b.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(project_model_UPDATE_DW.obj_o.MW_PWM_HANDLE,
                      project_model_UPDATE_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_n.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output1' */
  MW_PWM_SetDutyCycle(project_model_UPDATE_DW.obj_em.MW_PWM_HANDLE,
                      project_model_UPDATE_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(project_model_UPDATE_DW.obj_ne.MW_PWM_HANDLE,
                      project_model_UPDATE_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_k.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_m.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_e.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_d.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write9' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_bs.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write10' */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_a.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write' incorporates:
   *  Constant: '<S2>/Constant'
   */
  MW_digitalIO_write(project_model_UPDATE_DW.obj_by.MW_DIGITALIO_HANDLE,
                     project_model_UPDATE_P.Constant_Value != 0.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)project_model_UPDATE_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(project_model_UPDATE_M)!=-1) &&
        !((rtmGetTFinal(project_model_UPDATE_M)-
           project_model_UPDATE_M->Timing.taskTime0) >
          project_model_UPDATE_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(project_model_UPDATE_M, "Simulation finished");
    }

    if (rtmGetStopRequested(project_model_UPDATE_M)) {
      rtmSetErrorStatus(project_model_UPDATE_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  project_model_UPDATE_M->Timing.taskTime0 =
    ((time_T)(++project_model_UPDATE_M->Timing.clockTick0)) *
    project_model_UPDATE_M->Timing.stepSize0;
}

/* Model initialize function */
void project_model_UPDATE_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(project_model_UPDATE_M, 10.0);
  project_model_UPDATE_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  project_model_UPDATE_M->Sizes.checksums[0] = (524095096U);
  project_model_UPDATE_M->Sizes.checksums[1] = (102668594U);
  project_model_UPDATE_M->Sizes.checksums[2] = (3153253415U);
  project_model_UPDATE_M->Sizes.checksums[3] = (1284367820U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    project_model_UPDATE_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(project_model_UPDATE_M->extModeInfo,
      &project_model_UPDATE_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(project_model_UPDATE_M->extModeInfo,
                        project_model_UPDATE_M->Sizes.checksums);
    rteiSetTPtr(project_model_UPDATE_M->extModeInfo, rtmGetTPtr
                (project_model_UPDATE_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    project_model_UPDATE_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_fxos8700_project__T *obj;
    freedomk64f_DigitalRead_proje_T *obj_0;
    freedomk64f_DigitalWrite_proj_T *obj_1;
    freedomk64f_PWMOutput_project_T *obj_2;

    /* Start for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
    project_model_UPDATE_DW.obj.i2cobj.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj.matlabCodegenIsDeleted = true;
    obj = &project_model_UPDATE_DW.obj;
    project_model_UPDATE_DW.obj.isInitialized = 0;
    project_model_UPDATE_DW.obj.SampleTime = -1.0;
    obj->i2cobj.isInitialized = 0;
    obj->i2cobj.matlabCodegenIsDeleted = false;
    project_model_UPDATE_DW.obj.matlabCodegenIsDeleted = false;
    project_model_UPDATE_DW.obj.SampleTime =
      project_model_UPDATE_P.FXOS87006AxesSensor_SampleTime;
    project_model__SystemCore_setup(&project_model_UPDATE_DW.obj);

    /* Start for MATLABSystem: '<S2>/Digital Read3' */
    project_model_UPDATE_DW.obj_c.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_c.isInitialized = 0;
    project_model_UPDATE_DW.obj_c.SampleTime = -1.0;
    project_model_UPDATE_DW.obj_c.matlabCodegenIsDeleted = false;
    project_model_UPDATE_DW.obj_c.SampleTime =
      project_model_UPDATE_P.DigitalRead3_SampleTime;
    obj_0 = &project_model_UPDATE_DW.obj_c;
    project_model_UPDATE_DW.obj_c.isSetupComplete = false;
    project_model_UPDATE_DW.obj_c.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    project_model_UPDATE_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read2' */
    project_model_UPDATE_DW.obj_g.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_g.isInitialized = 0;
    project_model_UPDATE_DW.obj_g.SampleTime = -1.0;
    project_model_UPDATE_DW.obj_g.matlabCodegenIsDeleted = false;
    project_model_UPDATE_DW.obj_g.SampleTime =
      project_model_UPDATE_P.DigitalRead2_SampleTime;
    obj_0 = &project_model_UPDATE_DW.obj_g;
    project_model_UPDATE_DW.obj_g.isSetupComplete = false;
    project_model_UPDATE_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    project_model_UPDATE_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    project_model_UPDATE_DW.obj_b.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_b.isInitialized = 0;
    project_model_UPDATE_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_b;
    project_model_UPDATE_DW.obj_b.isSetupComplete = false;
    project_model_UPDATE_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    project_model_UPDATE_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    project_model_UPDATE_DW.obj_o.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_o.isInitialized = 0;
    project_model_UPDATE_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_2 = &project_model_UPDATE_DW.obj_o;
    project_model_UPDATE_DW.obj_o.isSetupComplete = false;
    project_model_UPDATE_DW.obj_o.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(project_model_UPDATE_DW.obj_o.MW_PWM_HANDLE);
    project_model_UPDATE_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    project_model_UPDATE_DW.obj_n.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_n.isInitialized = 0;
    project_model_UPDATE_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_n;
    project_model_UPDATE_DW.obj_n.isSetupComplete = false;
    project_model_UPDATE_DW.obj_n.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    project_model_UPDATE_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    project_model_UPDATE_DW.obj_em.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_em.isInitialized = 0;
    project_model_UPDATE_DW.obj_em.matlabCodegenIsDeleted = false;
    obj_2 = &project_model_UPDATE_DW.obj_em;
    project_model_UPDATE_DW.obj_em.isSetupComplete = false;
    project_model_UPDATE_DW.obj_em.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(project_model_UPDATE_DW.obj_em.MW_PWM_HANDLE);
    project_model_UPDATE_DW.obj_em.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    project_model_UPDATE_DW.obj_ne.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_ne.isInitialized = 0;
    project_model_UPDATE_DW.obj_ne.matlabCodegenIsDeleted = false;
    obj_2 = &project_model_UPDATE_DW.obj_ne;
    project_model_UPDATE_DW.obj_ne.isSetupComplete = false;
    project_model_UPDATE_DW.obj_ne.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(project_model_UPDATE_DW.obj_ne.MW_PWM_HANDLE);
    project_model_UPDATE_DW.obj_ne.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    project_model_UPDATE_DW.obj_k.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_k.isInitialized = 0;
    project_model_UPDATE_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_k;
    project_model_UPDATE_DW.obj_k.isSetupComplete = false;
    project_model_UPDATE_DW.obj_k.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    project_model_UPDATE_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    project_model_UPDATE_DW.obj_m.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_m.isInitialized = 0;
    project_model_UPDATE_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_m;
    project_model_UPDATE_DW.obj_m.isSetupComplete = false;
    project_model_UPDATE_DW.obj_m.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    project_model_UPDATE_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    project_model_UPDATE_DW.obj_e.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_e.isInitialized = 0;
    project_model_UPDATE_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_e;
    project_model_UPDATE_DW.obj_e.isSetupComplete = false;
    project_model_UPDATE_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    project_model_UPDATE_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    project_model_UPDATE_DW.obj_d.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_d.isInitialized = 0;
    project_model_UPDATE_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_d;
    project_model_UPDATE_DW.obj_d.isSetupComplete = false;
    project_model_UPDATE_DW.obj_d.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    project_model_UPDATE_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write9' */
    project_model_UPDATE_DW.obj_bs.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_bs.isInitialized = 0;
    project_model_UPDATE_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_bs;
    project_model_UPDATE_DW.obj_bs.isSetupComplete = false;
    project_model_UPDATE_DW.obj_bs.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    project_model_UPDATE_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write10' */
    project_model_UPDATE_DW.obj_a.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_a.isInitialized = 0;
    project_model_UPDATE_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_a;
    project_model_UPDATE_DW.obj_a.isSetupComplete = false;
    project_model_UPDATE_DW.obj_a.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    project_model_UPDATE_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    project_model_UPDATE_DW.obj_by.matlabCodegenIsDeleted = true;
    project_model_UPDATE_DW.obj_by.isInitialized = 0;
    project_model_UPDATE_DW.obj_by.matlabCodegenIsDeleted = false;
    obj_1 = &project_model_UPDATE_DW.obj_by;
    project_model_UPDATE_DW.obj_by.isSetupComplete = false;
    project_model_UPDATE_DW.obj_by.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    project_model_UPDATE_DW.obj_by.isSetupComplete = true;
  }
}

/* Model terminate function */
void project_model_UPDATE_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/FXOS8700 6-Axes Sensor' */
  matlabCodegenHan_bmtrs1t3xldjeg(&project_model_UPDATE_DW.obj);
  matlabCodegenHa_bmtrs1t3xldjegj(&project_model_UPDATE_DW.obj.i2cobj);

  /* Terminate for MATLABSystem: '<S2>/Digital Read3' */
  matlabCodegenHandle_matlabCod_b(&project_model_UPDATE_DW.obj_c);

  /* Terminate for MATLABSystem: '<S2>/Digital Read2' */
  matlabCodegenHandle_matlabCod_b(&project_model_UPDATE_DW.obj_g);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandle_m_bmtrs1t3x(&project_model_UPDATE_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  matlabCodegenHandle_m_bmtrs1t3x(&project_model_UPDATE_DW.obj_em);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHandle_m_bmtrs1t3x(&project_model_UPDATE_DW.obj_ne);

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_d);

  /* Terminate for MATLABSystem: '<S3>/Digital Write9' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_bs);

  /* Terminate for MATLABSystem: '<S3>/Digital Write10' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_a);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&project_model_UPDATE_DW.obj_by);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
