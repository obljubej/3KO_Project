/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: project_model_UPDATE.h
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

#ifndef RTW_HEADER_project_model_UPDATE_h_
#define RTW_HEADER_project_model_UPDATE_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef project_model_UPDATE_COMMON_INCLUDES_
# define project_model_UPDATE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                               /* project_model_UPDATE_COMMON_INCLUDES_ */

#include "project_model_UPDATE_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Min;                          /* '<S6>/Min' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T Gain1;                        /* '<S6>/Gain1' */
  real_T Add1;                         /* '<S6>/Add1' */
  real_T Gain2;                        /* '<S6>/Gain2' */
  real_T PACING_MODE;                  /* '<Root>/Parameter_Definitions' */
  real_T LOWER_RATE_LIMIT;             /* '<Root>/Parameter_Definitions' */
  real_T UPPER_RATE_LIMIT;             /* '<Root>/Parameter_Definitions' */
  real_T ATRIAL_AMPLITUDE;             /* '<Root>/Parameter_Definitions' */
  real_T ATRIAL_PULSE_WIDTH;           /* '<Root>/Parameter_Definitions' */
  real_T VENTRICULAR_SENSITIVITY;      /* '<Root>/Parameter_Definitions' */
  real_T VENTRICULAR_AMPLITUDE;        /* '<Root>/Parameter_Definitions' */
  real_T ATRIAL_SENSITIVITY;           /* '<Root>/Parameter_Definitions' */
  real_T VENTRICULAR_PULSE_WIDTH;      /* '<Root>/Parameter_Definitions' */
  real_T PVARP;                        /* '<Root>/Parameter_Definitions' */
  real_T VRP;                          /* '<Root>/Parameter_Definitions' */
  real_T ARP;                          /* '<Root>/Parameter_Definitions' */
  real_T RESPONSE_FACTOR;              /* '<Root>/Parameter_Definitions' */
  real_T MAX_SENSOR_RATE;              /* '<Root>/Parameter_Definitions' */
  real_T REACTION_TIME;                /* '<Root>/Parameter_Definitions' */
  real_T RECOVERY_TIME;                /* '<Root>/Parameter_Definitions' */
  real_T ACTIVITY_THRESHOLD;           /* '<Root>/Parameter_Definitions' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Pacemaker_States' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Pacemaker_States' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Pacemaker_States' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Pacemaker_States' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Pacemaker_States' */
  real_T VENT_GND_CTRL;                /* '<Root>/Pacemaker_States' */
  real_T PACING_REF_PWM;               /* '<Root>/Pacemaker_States' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Pacemaker_States' */
  real_T PACE_GND_CTRL;                /* '<Root>/Pacemaker_States' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Pacemaker_States' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Pacemaker_States' */
  real_T curr_HR;                      /* '<Root>/Chart1' */
  boolean_T RATE_SMOOTHING;            /* '<Root>/Parameter_Definitions' */
  boolean_T HYSTERESIS;                /* '<Root>/Parameter_Definitions' */
  boolean_T DigitalRead3;              /* '<S2>/Digital Read3' */
  boolean_T DigitalRead2;              /* '<S2>/Digital Read2' */
} B_project_model_UPDATE_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_project__T obj; /* '<S6>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_proje_T obj_c;/* '<S2>/Digital Read3' */
  freedomk64f_DigitalRead_proje_T obj_g;/* '<S2>/Digital Read2' */
  freedomk64f_DigitalWrite_proj_T obj_b;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_proj_T obj_n;/* '<S3>/Digital Write2' */
  freedomk64f_DigitalWrite_proj_T obj_k;/* '<S3>/Digital Write5' */
  freedomk64f_DigitalWrite_proj_T obj_m;/* '<S3>/Digital Write6' */
  freedomk64f_DigitalWrite_proj_T obj_e;/* '<S3>/Digital Write7' */
  freedomk64f_DigitalWrite_proj_T obj_d;/* '<S3>/Digital Write8' */
  freedomk64f_DigitalWrite_proj_T obj_bs;/* '<S3>/Digital Write9' */
  freedomk64f_DigitalWrite_proj_T obj_a;/* '<S3>/Digital Write10' */
  freedomk64f_DigitalWrite_proj_T obj_by;/* '<S2>/Digital Write' */
  freedomk64f_PWMOutput_project_T obj_o;/* '<S3>/PWM Output' */
  freedomk64f_PWMOutput_project_T obj_em;/* '<S3>/PWM Output1' */
  freedomk64f_PWMOutput_project_T obj_ne;/* '<S3>/PWM Output2' */
  real_T discharge_time;               /* '<Root>/Pacemaker_States' */
  real_T VOO_amp;                      /* '<Root>/Pacemaker_States' */
  real_T AOO_amp;                      /* '<Root>/Pacemaker_States' */
  real_T VVI_amp;                      /* '<Root>/Pacemaker_States' */
  real_T AAI_amp;                      /* '<Root>/Pacemaker_States' */
  real_T AOOR_amp;                     /* '<Root>/Pacemaker_States' */
  real_T AAIR_amp;                     /* '<Root>/Pacemaker_States' */
  real_T VVIR_amp;                     /* '<Root>/Pacemaker_States' */
  real_T p_rp;                         /* '<Root>/Pacemaker_States' */
  real_T curr_HR;                      /* '<Root>/Pacemaker_States' */
  real_T rate_slope;                   /* '<Root>/Pacemaker_States' */
  real_T p_curr_HR;                    /* '<Root>/Pacemaker_States' */
  real_T p_rs;                         /* '<Root>/Pacemaker_States' */
  real_T VOOR_amp;                     /* '<Root>/Pacemaker_States' */
  real_T recovery_Rate;                /* '<Root>/Chart1' */
  real_T reaction_Rate;                /* '<Root>/Chart1' */
  real_T curr_Level;                   /* '<Root>/Chart1' */
  uint32_T is_c1_project_model_UPDATE; /* '<Root>/Parameter_Definitions' */
  uint32_T is_c3_project_model_UPDATE; /* '<Root>/Pacemaker_States' */
  uint32_T is_VOOR;                    /* '<Root>/Pacemaker_States' */
  uint32_T is_VOO;                     /* '<Root>/Pacemaker_States' */
  uint32_T is_AOO;                     /* '<Root>/Pacemaker_States' */
  uint32_T is_VVIR;                    /* '<Root>/Pacemaker_States' */
  uint32_T is_AOOR;                    /* '<Root>/Pacemaker_States' */
  uint32_T is_VVI;                     /* '<Root>/Pacemaker_States' */
  uint32_T is_AAI;                     /* '<Root>/Pacemaker_States' */
  uint32_T is_AAIR;                    /* '<Root>/Pacemaker_States' */
  uint32_T temporalCounter_i1;         /* '<Root>/Pacemaker_States' */
  uint32_T is_c6_project_model_UPDATE; /* '<Root>/Chart1' */
  uint32_T temporalCounter_i1_g;       /* '<Root>/Chart1' */
  uint8_T is_active_c1_project_model_UPDA;/* '<Root>/Parameter_Definitions' */
  uint8_T is_active_c3_project_model_UPDA;/* '<Root>/Pacemaker_States' */
  uint8_T is_active_c6_project_model_UPDA;/* '<Root>/Chart1' */
} DW_project_model_UPDATE_T;

/* Parameters (default storage) */
struct P_project_model_UPDATE_T_ {
  real_T DigitalRead2_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read2'
                                        */
  real_T DigitalRead3_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read3'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S6>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Gain3_Gain;                   /* Expression: 10
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1000/60
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000/60
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_project_model_UPDATE_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_project_model_UPDATE_T project_model_UPDATE_P;

/* Block signals (default storage) */
extern B_project_model_UPDATE_T project_model_UPDATE_B;

/* Block states (default storage) */
extern DW_project_model_UPDATE_T project_model_UPDATE_DW;

/* Model entry point functions */
extern void project_model_UPDATE_initialize(void);
extern void project_model_UPDATE_step(void);
extern void project_model_UPDATE_terminate(void);

/* Real-time Model object */
extern RT_MODEL_project_model_UPDATE_T *const project_model_UPDATE_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'project_model_UPDATE'
 * '<S1>'   : 'project_model_UPDATE/Chart1'
 * '<S2>'   : 'project_model_UPDATE/Input_Subsystem'
 * '<S3>'   : 'project_model_UPDATE/Output_Subsystem'
 * '<S4>'   : 'project_model_UPDATE/Pacemaker_States'
 * '<S5>'   : 'project_model_UPDATE/Parameter_Definitions'
 * '<S6>'   : 'project_model_UPDATE/Rate_Adaptive_Subsystem1'
 * '<S7>'   : 'project_model_UPDATE/Rate_Adaptive_Subsystem1/Multiply-Add'
 */
#endif                                 /* RTW_HEADER_project_model_UPDATE_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
