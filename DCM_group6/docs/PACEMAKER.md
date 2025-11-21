### Copyright©c2007 Boston Scientific

### January 3, 2007

DISCLAIMER: This document is provided for academic purposes only,
specifically demonstration of formal methodologies and engineering education.
Boston Scientific disclaims any use of information contained herein for any
product whatsoever, disclaims safety, disclaims efficacy, and disclaims fitness for
purpose. Any person or entity who uses this document for anything assumes
complete responsibility for its use.
Permission to copy is granted, provided the copyright declaration and this
disclaimer are included.

```
Please direct any comments or questions to:PACEMAKER@sqrl.mcmaster.ca
```

##### 1

## Contents

- 1 Introduction
  - 1.1 Scope
  - 1.2 Acronyms
- 2 System Definition
  - 2.1 System Overview
  - 2.2 System Components
    - 2.2.1 Device Overview
    - 2.2.2 Device Controller-Monitor (DCM) Overview
    - 2.2.3 Lead System Overview
  - 2.3 Indications and Contraindications
  - 2.4 User Characteristics and Operational Environment
    - 2.4.1 Hospitals/Physician Users
    - 2.4.2 Device Usage with Other Equipment
  - 2.5 System Operational Life Phases
    - 2.5.1 Pre-Implant Phase
    - 2.5.2 Implant
    - 2.5.3 Predischarge Follow-up
    - 2.5.4 Routine Follow-up
    - 2.5.5 Ambulatory
    - 2.5.6 Explant
    - 2.5.7 Disposal
- 3 System Requirements
  - 3.1 Model Type
  - 3.2 Device Controller-Monitor (DCM)
    - 3.2.1 DCM User Languages
    - 3.2.2 DCM User Interface
    - 3.2.3 DCM Utility Functions
    - 3.2.4 Printed Reports
    - 3.2.5 Strip Chart Recording Support
    - 3.2.6 DCM-PG Telemetry
  - 3.3 Lead Support
  - 3.4 Pacing Pulse
    - 3.4.1 Pulse Amplitude
    - 3.4.2 Pulse Width
    - 3.4.3 Rate Sensing
    - 3.4.4 Sensitivity Adjustment
  - 3.5 Bradycardia Operating Modes
    - 3.5.1 No Response To Sensing (O)
    - 3.5.2 Triggered Response To Sensing (T)
    - 3.5.3 Inhibited Response To Sensing (I)
    - 3.5.4 Tracked Response To Sensing (D)
  - 3.6 Bradycardia States
    - 3.6.1 Permanent State
    - 3.6.2 Temporary Bradycardia Pacing
    - 3.6.3 Pace-Now State
    - 3.6.4 Magnet State
    - 3.6.5 Power-On Reset (POR) State
  - 3.7 Magnet Test
  - 3.8 Implant Data
- 4 Diagnostics
  - 4.1 Measured Data
  - 4.2 P and R Wave Measurements
  - 4.3 Lead Impedance Measurement
  - 4.4 Battery Status
  - 4.5 Threshold Test
  - 4.6 Bradycardia History
    - 4.6.1 Rate Histograms
    - 4.6.2 Rate Trending
    - 4.6.3 Recording Duration and Time Stamp
    - 4.6.4 Sensor Trending
  - 4.7 Real-time Electrograms
    - 4.7.1 Electrogram Viewing
  - 4.8 Real-time Electrogram Event Marker Annotations
    - 4.8.1 Atrial Markers: AS AP AT TN
    - 4.8.2 Ventricular Markers: VS VP PVC TN
    - 4.8.3 Marker Modifiers: () -Hy -Sr↑ ↓
    - 4.8.4 Augmentation Markers: ATR-Dur ATR-FB ATR-End PVP→
  - 4.9 Faults and Error Handling
    - 4.9.1 Faults
    - 4.9.2 Errors
- 5 Bradycardia Therapy
  - 5.1 Lower Rate Limit (LRL)
  - 5.2 Upper Rate Limit (URL)
  - 5.3 Atrial-Ventricular (AV) Delay
    - 5.3.1 Paced AV Delay
    - 5.3.2 Sensed AV Delay
    - 5.3.3 Dynamic AV Delay
    - 5.3.4 Sensed AV Delay Offset
  - 5.4 Refractory Periods
    - 5.4.1 Ventricular Refractory Period (VRP)
    - 5.4.2 Atrial Refractory Period (ARP)
    - 5.4.3 Post Ventricular Atrial Refractory Period (PVARP)
    - 5.4.4 Extended PVARP
    - 5.4.5 Refractory During AV Interval
  - 5.5 Noise Response
  - 5.6 Atrial Tachycardia Response (ATR)
    - 5.6.1 Atrial Tachycardia Detection
    - 5.6.2 ATR Duration
    - 5.6.3 ATR Fallback
  - 5.7 Rate-Adaptive Pacing
    - 5.7.1 Maximum Sensor Rate (MSR)
    - 5.7.2 Activity Threshold
    - 5.7.3 Response Factor
    - 5.7.4 Reaction Time
    - 5.7.5 Recovery Time
  - 5.8 Hysteresis Pacing
  - 5.9 Rate Smoothing
- A Programmable Parameters
- B Measured Parameters
  - 1 Model Type and Lead Port List of Tables
  - 2 Bradycardia Operating Modes
  - 3 Battery Status and Therapy Availability
  - 4 Intervals Associated with Histogrammed Events
  - 5 Event Marker Annotations
  - 6 Programmable Parameters for Bradycardia Therapy Modes
  - 7 Programmable Parameters
  - 8 Measured Parameters

## 1 Introduction

This System Specification for PACEMAKER defines the functions and operat-
ing characteristics, identifies the system environmental performance parameters,
and characterizes anticipated uses of the system.

### 1.1 Scope

This document identifies the functions that the system must perform and pro-
vides a description of these functions and their primary interactions.

### 1.2 Acronyms

AP Atrial Pace
AS Atrial Sense
ARP Atrial Refractory Period
ATR Atrial Tachycardia Response
AV Atrial-to-Ventricular
BOL Beginning Of (battery) Life
BPM Beats Per Minute
cc Cardiac Cycle(s)
CCI Cardiac Cycle Interval
DCM Device Controller-Monitor
ECG Electrocardiogram, external heart signals
EGM Electrogram, internal heart signals
EOL End Of (battery) Life
EP Electrophysiology, electrophysiologist
ERN Elective Replacement Near
ERT Elective Replacement Time
HRL Hysteresis Rate Limit
ICD Implantable Cardio-Defibrillator
IS-1 Industry Standard lead type 1
LRL Lower Rate Limit
MSR Maximum Sensor Rate
NSR Normal Sinus Rhythm
OR Operating Room
PG Pulse Generator
POR Power-On Reset
PMT Pacemaker-Mediated Tachycardia
ppm Pulses Per Minute
PVARP Post-Ventricular Atrial Refractory Period
PVC Premature Ventricular Contraction
SIR Sensor Indicated Rate
SRD Sustained Rate Duration
URL Upper Rate Limit
VP Ventricular Pace

VS Ventricular Sense
VRP Ventricular Refractory Period

## 2 System Definition

### 2.1 System Overview

This PACEMAKER System Specification describes the PACEMAKER-specific
programming application and pulse generator (PG). The PACEMAKER system
supports the following needs of patients that require bradycardia pacing support:

- Implantation
- Ambulatory
- Follow-up
- Explantation

The PACEMAKER system:

- Provides dual chamber, rate adaptive bradycardia pacing support
- Provides historical data on device performance
- Provides user diagnostics through brady analysis functions

The bradycardia analysis functions permit the following pacing measurements
and tests to be performed:

- Lead impedance
- Pacing threshold
- P and R wave measurement
- Battery status
- Temporary brady pacing
- Motion sensor trending

### 2.2 System Components

The PACEMAKER system consists of three major components:

- Device (also called the pulse generator or PG)
- Device Controller-Monitor (DCM) and associated software
- Leads

A standard cardiac “donut” magnet is a minor system component.

#### 2.2.1 Device Overview

The device monitors and regulates a patient’s heart rate.
The device detects and provides therapy for bradycardia conditions.
The device provides programmable, single- and dual-chamber, rate-adaptive
pacing, both permanent and temporary.
In adaptive rate modes, an accelerometer is used to measure physical activity
resulting in a sensor indicated rate for pacing the heart.
The device is programmed and interrogated via bi-directional telemetry from
the Device Controller-Monitor (DCM). This allows the physician to change the
operating mode or parameters of the device non-invasively after implantation.
The device provides the following history data:

- Sensor output data
- Atrial and ventricular rate histograms.

The device, in conjunction with the DCM, provides diagnostic features in-
cluding:

- Real time telemetry markers
- EGMs
- P and R wave measurements
- Lead impedance
- Battery status tests

#### 2.2.2 Device Controller-Monitor (DCM) Overview

The Device Controller-Monitor (DCM) is the primary implant, pre-discharge
EP support, and follow-up device for the PACEMAKER system. The DCM
is capable of being used both in the OR, physician’s office, and the EP lab.
The DCM communicates with the PG using a communication protocol and
supporting hardware. The DCM consists of the following:

- A hardware platform
- PACEMAKER application software

The DCM has the following features:

```
1.program and interrogate a PACEMAKER
```

```
2.command delivery of “Pace-Now” pace
```

```
3.acquire and show diagnostics (history) and lead signal measurement in-
formation.
```

```
4.acquire and show sensor history and trending information.
```

```
5.show visible and audible indications of communication between the DCM
and device, including beeping and LED’s for alerting the operator to error
conditions.
```

```
6.acquire and show multi-channel monitoring including surface electrocar-
diogram and telemetered signals (e.g. EGM, annotated event markers)
```

```
7.print reports and strip charts.
```

```
8.monitor battery status.
```

```
9.output to external strip-chart recorders.
```

```
10.receive cursor positioning and button inputs.
```

```
11.manage windows for display of text and graphics.
```

```
12.set the date and time.
```

#### 2.2.3 Lead System Overview

The lead system implanted in the patient allows the device to sense intrinsic ac-
tivity of the heart’s electrical signals and delivers pacing therapy to the patient’s
heart.
The leads are connected to the PG via its header. All IS-1 bipolar leads are
supported.

### 2.3 Indications and Contraindications

The PACEMAKER system is indicated for patients exhibiting chronotropic in-
competence and who would benefit by increased pacing rates concurrent with
physical activity. Generally accepted indications for long-term cardiac pacing
include, but are not limited to, sick sinus syndrome; chronic sinus arrhythmias,
including sinus bradycardia, sinus arrest, and sinoatrial (S-A) block; second-
and third-degree AV block; bradycardia-tachycardia syndrome; bundle branch
block; and carotid sinus syndrome.
Patients who demonstrate hemodynamic improvement from atrioventricular
synchrony should be considered for one of the dual-chamber or atrial pacing
modes. Dual-chamber modes are specifically indicated for treatment of conduc-
tion disorders that require restoration of rate and of atrioventricular synchrony,
including varying degrees of AV block; low cardiac output or congestive heart
failure related to bradycardia; and certain tachyrhythmias.
Use of the PACEMAKER pulse generator in DDDR and VDDR modes may
be contraindicated (1) in patients with chronic atrial tachyrhythmias (atrial
fibrillation or flutter), which may trigger ventricular pacing, or (2) in the pres-
ence of slow retrograde conduction that induces pacemaker-mediated tachycar-
dia (PMT) which cannot be controlled by reprogramming selective parameter
values. In DDDR, DDIR, and AAIR modes, atrial pacing may be ineffective
in the presence of chronic atrial fibrillation or flutter or an atrium that does

not respond to electrical stimulation. In addition, the presence of clinically sig-
nificant conduction disturbances may contraindicate the use of atrial pacing.
Unipolar pacing is contraindicated for patients with an implanted cardioverter
defibrillator (ICD) because it may cause unwanted initiation or inhibition of
ICD therapy.

### 2.4 User Characteristics and Operational Environment

Patients with arrhythmias may be users of portions of the system such as the
magnet.

#### 2.4.1 Hospitals/Physician Users

The PACEMAKER device and leads are implanted by physicians and hospital
staff with varying degrees of experience. Follow-up of the patients is typically
performed by nurses or technicians under the supervision of a following physi-
cian.

#### 2.4.2 Device Usage with Other Equipment

The device functions with the following equipment:

- The ECG monitors.
- The DCM.

The device meets industry standards for electrical safety. The device func-
tions with the following ancillary equipment present in ORs and EP labs which
can be sources of EMI or direct energy interference:

- A fluoroscope.
- Anesthesia machines.
- Patient water blankets.
- Electrocautery devices.
- External defibrillators.
- Blood pressure monitors.
- Pulse oximeters.

### 2.5 System Operational Life Phases

The system’s life cycle is shown below. Each phase in the cycle is described in
more detail following.

```
Pre-Implant
```

##### Æ

##### ≠

##### ©

##### ™

```
Implant
```

##### Æ

##### ≠

##### ©

##### ™

```
Follow-up
```

##### Æ

##### ≠

##### ©

##### ™

```
Ambulatory
```

##### Æ

##### ≠

##### ©

##### ™

```
Explant
```

##### Æ

##### ≠

##### ©

##### ™

```
Disposal
```

##### Æ

##### ≠

##### ©

##### ™

##### - - - - -

```
Nominal
Settings
```

```
Physician
Selected
Settings
```

```
Physician
Selected
Settings
```

```
1 2 3 4 5 6
```

```
Figure 1: PACEMAKER Life Cycle
```

#### 2.5.1 Pre-Implant Phase

```
The system is manufactured using good manufacturing practices as specified
by the FDA and other appropriate regulatory bodies. During manufacturing,
nominal settings for the PG are set.
```

#### 2.5.2 Implant

```
During implant, the PACEMAKER device is placed into the patient. During
implant, the DCM is used to:
```

```
1.Interrogate the system
```

```
2.Review battery status
```

```
3.Test the PACEMAKER in the patient
```

```
4.Setup the appropriate parameters
```

```
5.Program the system before implantation
```

```
6.Evaluate ventricular and atrial lead signal amplitudes, impedances, and
pacing thresholds.
```

```
The procedure to implant a PACEMAKER device and lead system consists
of these steps:
1.Checking status of all equipment to be used during implant
```

```
2.Implanting the lead system
```

```
3.Evaluating lead signals using a pacing stimulus analyzer
```

```
4.Programming the nonimplanted system
```

```
5.Forming the implantation pocket and tunnel the leads
```

```
6.Connecting to the patient leads
```

```
7.Testing the system sensing and pacing efficacy
```

```
8.Implanting the system
```

#### 2.5.3 Predischarge Follow-up

During the predischarge follow-up test, the following procedures may be per-
formed via telemetry using the DCM:

```
1.Interrogating the device and obtaining bradycardia sensing and pacing
data
2.Reprogramming to final pre-discharge value
```

```
3.Printing the follow-up report for the patient’s chart
```

#### 2.5.4 Routine Follow-up

The programming system is capable of performing the following procedures
during the routine follow-up:

```
1.Interrogating the device
2.Checking the battery status
```

```
3.Checking the brady status
```

```
4.Performing P and R wave measurements
```

```
5.Performing pacing threshold and lead impedance tests
6.Reviewing the activity sensor history and rate histograms
```

```
7.Printing a follow-up report
```

```
8.If parameter values are changed during the follow-up visit, the new setting
is verified by viewing the “Session Net Change” report
```

```
9.Clearing the Histograms
```

#### 2.5.5 Ambulatory

The Pacing/Sensing functions will be available in the Ambulatory stage of the
device life cycle.

#### 2.5.6 Explant

Once the device is explanted, it is sanitized and returned to its manufacturer.
A fault analysis is performed if applicable. The state of the device, when it is
explanted, is a function of any fault that may have occurred and/or the state
of the battery at the time of explant.

#### 2.5.7 Disposal

For disposal, the device is sent back to its manufacturer. The device should
not be destroyed by incineration because the device contains batteries that can
explode when subjected to heat.

## 3 System Requirements

All detailed development requirements are defined in this section and the next,
Bradycardia Therapy. Each requirement is defined by a sentence containing the
word shall or by each item in a list of items.
For the Device Controller-Monitor (DCM) only those items that will be sup-
ported as part of the application software development for the PACEMAKER
will be defined.
Programmable ranges and tolerances are provided in Appendix A.

### 3.1 Model Type

The PACEMAKER model type shall support single and dual chamber rate
adaptive pacing.

```
Model Pacemaker
Designation
```

```
Functionality Connector
```

```
DR1 DR DDDR full function
with accelerometer
```

```
Dual-in-line,
3.2 mm (IS-1)
```

```
Table 1: Model Type and Lead Port
```

### 3.2 Device Controller-Monitor (DCM)

#### 3.2.1 DCM User Languages

The application is available in the following languages: English, Danish, Dutch,
French, German, Spanish, Italian, and Swedish.

#### 3.2.2 DCM User Interface

The user interface is capable of the following:

```
1.The user interface shall be capable of utilizing and managing windows for
display of text and graphics.
```

```
2.The user interface shall be capable of processing user positioning and input
buttons.
```

```
3.The user interface shall be capable of displaying all programmable param-
eters for review and modification.
```

```
4.The user interface shall be capable of visually indicating when the DCM
and the device are communicating.
```

```
5.The user interface shall be capable of visually indicating when telemetry
is lost due to the device being out of range.
```

```
6.The user interface shall be capable of visually indicating when telemetry
is lost due to noise.
```

```
7.The user interface shall be capable of visually indicating when a different
PACEMAKER device is approached than was previously interrogated.
```

#### 3.2.3 DCM Utility Functions

```
1.The About function displays the following:
```

- Application model number
- Application software revision number currently in use
- DCM serial number
- Institution name

```
2.The Set Clock function shall set the date and time of the device.
```

```
3.The New Patient function shall allow a new device to be interrogated
without exiting the software application.
```

```
4.The Quit function shall end a telemetry session.
```

#### 3.2.4 Printed Reports

The following parameter and status reports are available at the user’s request:

```
1.A Bradycardia Parameters Report shall be available.
```

```
2.A Temporary Parameters Report shall be available.
```

```
3.An Implant Data Report shall be available.
```

```
4.A Threshold Test Results Report shall be available.
```

```
5.A Measured Data Report shall be available.
```

```
6.A Marker Legend Report shall be available.
```

```
7.A Session Net Change Report shall be available.
```

```
8.A Final Report shall be available. This will consist of the Measured Data,
Threshold Test, Trending, Histograms, Implant Data, and Net Change
reports.
```

The following bradycardia diagnostic reports are available at the user’s re-
quest:

```
1.A Rate Histogram Report shall be available.
```

```
2.A Trending Report shall be available.
```

```
Each report shall contain the following header information:
```

```
1.Institution name
```

```
2.Date and time of report printing
```

```
3.Device model and serial number
```

```
4.DCM serial number
```

```
5.Application model and version number
```

```
6.Report name
```

#### 3.2.5 Strip Chart Recording Support

```
1.The DCM shall be capable of displaying real time and surface ECG data,
which shall be accomplished using the DCM’s internal monitor.
```

```
2.The system shall be capable of displaying up to three Real-Time traces
(2 Telemetered, 1 Surface ECG), along with an annotation for display of
event markers, in a scrollable fashion.
```

```
3.The DCM shall use the DCM’s internal strip chart recorder to provide a
means of printing combinations of real time data.
```

```
4.The DCM shall be capable of printing real time telemetered data and a
surface ECG.
```

```
5.The printer shall be capable of simultaneously printing up to three real-
time traces, along with full annotation for display of event markers.
```

#### 3.2.6 DCM-PG Telemetry

The DCM shall either:

- use an inductive telemetry wand to communicate with the pulse generator,
  maintaining consistent communication over the range of 0 cm to 5 cm
  between the wand and the pulse generator; or,
- use some other medium, such as RF or ultrasound, that is safe and legal
  to use, for maintaining consistent telemetry with an implanted medical
  device.

### 3.3 Lead Support

```
1.The Atrial Bipolar Pace/Sensing lead system type shall be supported.
```

```
2.The Ventricular Bipolar Pace/Sensing lead system type shall be sup-
ported.
```

```
3.The system shall operate normally with atrial pace/sense leads between
100 and 2500 ohms.
```

```
4.The system shall operate normally with the ventricular pace/sense leads
between 100 and 2500 ohms.
```

Note: all pacing amplitudes and pulse widths in this document are specified
using a 750 ohm load.

### 3.4 Pacing Pulse

The device shall output pulses with programmable voltages and widths (atrial
and ventricular) which provide electrical stimulation to the heart for pacing.

#### 3.4.1 Pulse Amplitude

The atrial and ventricular pacing pulse amplitudes shall be independently pro-
grammable.

#### 3.4.2 Pulse Width

The atrial and ventricular pacing pulse width shall be independently programmable.

#### 3.4.3 Rate Sensing

Rate sensing shall be accomplished using bipolar electrodes and sensing circuits.
All rate detection decisions shall be based on the measured cardiac cycle lengths
of the sensed rhythm. Rate shall be evaluated on an interval-by-interval basis.

#### 3.4.4 Sensitivity Adjustment

A means shall be provided for the physician to manually adjust the sensing
threshold of the device for both the ventricular and atrial sense channels.

### 3.5 Bradycardia Operating Modes

The following bradycardia operating modes shall be programmable: Off, DDDR,
VDDR, DDIR, DOOR, VOOR, AOOR, VVIR, AAIR, DDD, VDD, DDI, DOO,
VOO, AOO, VVI, AAI, VVT and AAT.
OVO, OAO, ODO, and OOO shall be available in temporary operation.

Note: sometimes, “X” is used as a “don’t care” to identify a set of modes;
DXXX are the dual-chamber paced modes; OXO are the sensing-only modes;
XXT are the triggered modes.

```
I II III IV (optional)
Category Chambers
Paced
```

```
Chambers
Sensed
```

```
Response To
Sensing
```

```
Rate
Modulation
Letters O–None
A–Atrium
V–Ventricle
D–Dual
```

```
O–None
A–Atrium
V–Ventricle
D–Dual
```

```
O–None
T–Triggered
I–Inhibited
D–Tracked
```

```
R–Rate
Modulation
```

```
Table 2: Bradycardia Operating Modes
```

#### 3.5.1 No Response To Sensing (O)

Pacing without sensing is asynchronous pacing. During asynchronous pacing,
paces shall be delivered without regard to senses

#### 3.5.2 Triggered Response To Sensing (T)

During triggered pacing, a sense in a chamber shall trigger an immediate pace
in that chamber.

#### 3.5.3 Inhibited Response To Sensing (I)

During inhibited pacing, a sense in a chamber shall inhibit a pending pace in
that chamber.

#### 3.5.4 Tracked Response To Sensing (D)

During tracked pacing, an atrial sense shall cause a tracked ventricular pace after
a programmed AV delay, unless a ventricular sense was detected beforehand.

### 3.6 Bradycardia States

The following bradycardia states shall be available: Permanent, Temporary,
Pace-Now, Magnet, and Power-On Reset (POR). Operating states shall be mu-
tually exclusive.

#### 3.6.1 Permanent State

The permanent pacing state is the normal state of operation of the device. The
normal pacing parameters programmed shall be used in the permanent brady
state.

#### 3.6.2 Temporary Bradycardia Pacing

The temporary brady pacing state is independent of other pacing functions.
The temporary brady parameters programmed shall be used in the temporary

brady state. The temporary state shall be capable of being used to temporarily
test various system parameters or provide patient diagnostic testing. Temporary
brady pacing shall be terminated by one of the following: breaking the telemetry
link, a Pace-Now pace, or a DCM command to the device to cancel temporary
pacing.

#### 3.6.3 Pace-Now State

Commanded emergency bradycardia pacing (Pace-Now) shall be available.
The Pace-Now Pace parameter values are as follows:

```
1.The mode Pace-Now pace parameter shall have a value of VVI.
```

```
2.The lower rate limit Pace-Now pace parameter shall have a value of 65
ppm±8 ms.
```

```
3.The amplitude Pace-Now pace parameter shall have a value of 5.0 V±0.
V.
```

```
4.The pulse width Pace-Now pace parameter shall have a value of 1.00 ms
±0.02 ms.
```

```
5.The ventricular refractory Pace-Now pace parameter shall have a value of
320 ms±8 ms.
```

```
6.The ventricular sensitivity shall have a value of 1.5 mV.
```

```
7.The first Pace-Now pacing pulse shall be issued within two cardiac cycles
plus 500 ms from the time of the last user action required to activate the
Pace-Now state.
```

```
8.Once initiated, Pace-Now pacing shall continue until the DCM changes
the device pacing mode.
```

#### 3.6.4 Magnet State

The Magnet State is used during the Magnet Test.

#### 3.6.5 Power-On Reset (POR) State

A Power-on-reset (POR) state shall be entered when the battery voltage drops
so low that PG operation is not predictable. All functions shall be disabled until
the battery voltage exceeds the POR trip voltage. Above this trip voltage, the
PG enters the POR state which is used to power-up the PG system to a known
state and set of parameters.
The POR parameter values are as follows:

```
1.The mode POR pace parameter shall have a value of VVI.
```

```
2.The lower rate limit POR pace parameter shall have a value of 65 ppm
±8 ms.
```

```
3.The amplitude POR pace parameter shall have a value of 5.0 V±0.5 V.
```

```
4.The pulse width POR pace parameter shall have a value of 0.5 ms±0.
ms.
```

```
5.The ventricular refractory POR pace parameter shall have a value of 320
ms±8 ms.
```

```
6.The ventricular sensitivity shall have a value of 1.5 mV.
```

### 3.7 Magnet Test

The magnet can be used to determine the battery status of the device. A
standard cardiac donut magnet shall be detected by the device at a distance of
2.5 cm between the center of the labeled surface of the device and the surface
of the magnet.
When the magnet is in place, the device shall:

```
1.Pace asynchronously with a fixed pacing rate. The device mode shall be
AOO if previous mode was AXXX, VOO if previous mode was VXXX,
DOO if previous mode was DXXX, or OOO if previous mode was OXO
modes.
```

```
2.At BOL the magnet rate shall be 100 ppm. At ERN the magnet rate
shall decrease to 90 ppm. At ERT the magnet rate shall decrease further
to 85 ppm. During post-ERT operation the rate interval may gradually
decrease as the battery voltage continues to decrease.
```

```
3.When the magnet is removed the device shall automatically assume pretest
operation.
```

```
4.The magnet mode shall have the capability to be programmed OFF, so
that it will ignore magnet detection.
```

### 3.8 Implant Data

The device shall be capable of storing the following information in device mem-
ory:

```
1.The device shall be capable of storing the device model and serial number,
and implant date information.
```

```
2.The device shall be capable of storing the lead implant date and polarity
information.
```

```
3.The device shall be capable of storing pacing thresholds and P and R-wave
amplitude information.
```

4.The device shall be capable of storing the pacing lead impedance infor-
mation.

5.The device shall be capable of storing the patient’s indications for pacing.

## 4 Diagnostics

The system provides the following diagnostic tools:

- Measured Data diagnostic tools shall be provided.
- Threshold Test diagnostic tools shall be provided.
- Rate Trending and Histograms diagnostic tools shall be provided.
- Real-time data diagnostic tools shall be provided.

### 4.1 Measured Data

Measured Data tolerances are shown in Appendix B.

### 4.2 P and R Wave Measurements

The device shall allow for DCM-commanded measurement of P and R waves.

### 4.3 Lead Impedance Measurement

Lead impedance measurements works as follows:

```
1.The device shall allow for manual measurement capability.
```

```
2.DCM commanded lead impedance shall be made with the device in the
temporary state.
```

```
3.Lead impedance measurements shall be conducted at a default value of
5.5 V.
```

### 4.4 Battery Status

Battery status information includes the following:

```
1.Monitoring voltage information shall be provided.
```

```
2.Battery Status indicator information shall be provided.
```

```
3.Last interrogation date information shall be provided.
```

```
4.The battery status for the device shall be used to predict the following
battery status levels:
```

```
Battery Status Level Status Functionality
Beginning of Life BOL Fully functional
Elective Replacement Near ERN Fully functional
Elective Replacement Time ERT Non-rate-adaptive single
chamber modes only. Tempo-
rary programming, automatic
threshold testing, measured
data, electrograms, and event
markers disabled.
Elective Replacement Past ERP Same as ERT, except pac-
ing rate gradually decreases as
battery voltage decreases.
```

```
Table 3: Battery Status and Therapy Availability
```

### 4.5 Threshold Test

Auto threshold tests work as follows:

```
1.An automatic pacing threshold test in AAI, VVI, and DDD modes shall
be available on command of the DCM for both pulse width and amplitude
measurements.
```

```
2.The test starts at a user-selectable amplitude or pulse width. After ap-
proximately every fourth cardiac cycle, the DCM automatically steps
down the amplitude or pulse width one setting.
```

```
3.The user is instructed to terminate the test by removing the telemetry
wand or selecting the ”Stop” button when loss of capture is observed.
```

```
4.The last six test results will be displayed (each chamber) on the screen
and printed report.
```

```
5.Programmable DDD/AAI back-up pacing with a programmable rate shall
be available for atrial testing, and programmable DDD/VVI back-up pac-
ing with programmable rate shall be available for ventricular testing.
```

### 4.6 Bradycardia History

To assist adjustment of pacing parameters, bradycardia history is retained in
PGs for viewing with DCM.

#### 4.6.1 Rate Histograms

The operator interface of the system shall be able to display histograms of pacing
rate and intrinsic rate distributions from a histogram recording period.
Histogram data are recorded as follows:

```
1.Distributions shall be recorded for all paced atrial events.
```

```
2.Distributions shall be recorded for all sensed atrial events.
```

```
3.Distributions shall be recorded for all paced ventricular events.
```

```
4.Distributions shall be recorded for all sensed ventricular events.
```

```
5.The number of premature ventricular contractions (PVCs) and atrial tachy-
cardia response episodes shall be recorded and displayed.
```

```
6.The recording period for a rate histogram shall be the time since the rate
histograms were last reset to the present.
```

```
7.The rate histograms shall be resettable (clearing previously recorded data)
via telemetry.
```

```
8.All rate histograms shall be cleared simultaneously.
```

```
9.The intervals associated with the histogrammed events shall begin and
end at the events specified in the following table:
```

```
Histogram Event Beginning Event Ending Event
Sensed Atrial Refractory or non-refractory
atrial sense or atrial pace
```

```
Refractory or non-
refractory atrial sense
Paced Atrial Atrial pace or non-refractory
atrial sense
```

```
Atrial pace
```

```
Sense Ventricular Non-refractory ventricular
sense or ventricular pace
```

```
Non-refractory ventricu-
lar sense
Paced Ventricular Ventricular pace or non-
refractory ventricular sense
```

```
Ventricular pace
```

```
Table 4: Intervals Associated with Histogrammed Events
```

#### 4.6.2 Rate Trending

The system shall be configurable to record and display the following data items
separately or concurrently over a programmable duration and storage method:

```
1.Pacing Rate
```

```
2.Sensor Data
```

#### 4.6.3 Recording Duration and Time Stamp

The recording duration shall be programmed to one of the following options:

```
1.Fixed: Start recording now and stop when available storage is full (time
stamped at beginning).
```

```
2.Continuous: Circular buffer keeping the latest information (time stamped
at end).
```

The recording duration shall be time stamped as indicated above.
The system shall display only the programmable durations that are applica-
ble for the current pacing mode.

#### 4.6.4 Sensor Trending

The system shall provide off-line prediction analysis of sensor indicated rate
with or without intrinsic rate for the synchronized data collected.

### 4.7 Real-time Electrograms

Real-time internal electrograms shall be made available from

```
1.The atrial and ventricular sense/pace leads.
```

```
2.A surface electrogram.
```

The real-time electrogram transmission shall be re-initiated if the telemetry
link was broken during the transmission of electrograms and then reestablished.

#### 4.7.1 Electrogram Viewing

The user shall have the option of viewing the electrograms

```
1.On the screen
```

```
2.Through a printed copy
```

The user shall have the option of selecting which electrograms are viewed
and the resolution utilized.
Internal electrogram (EGM) options provided are the following:

```
1.An atrial internal electrogram option shall be provided.
```

```
2.A ventricular internal electrogram option shall be provided.
```

```
3.An atrial and ventricular internal electrogram option shall be provided.
```

For the surface electrocardiogram (ECG), the user shall have the capability
to select

```
1.The gain utilized (0.5X, 1X, or 2X)
```

```
2.Whether high pass filtering is on
```

```
For the internal electrogram (EGM), the display gain shall
```

```
1.Be selectable (0.5X, 1X, or 2X)
```

```
2.Apply to all channels
```

### 4.8 Real-time Electrogram Event Marker Annotations

The capability shall exist to print and display annotated event marker abbre-
viations listed below on the real-time electrogram. These markers shall be a
combination of intrinsic cardiac and device-related events.

```
1.Each marker shall show time-or-occurrence, accurate to 1 ms, since the
most recent, non-refractory event in that chamber.
```

```
2.At most one atrial marker will occur each 1 ms.
```

```
3.At most one ventricular marker will occur each 1 ms.
```

```
4.At most one augmentation marker will occur each 1 ms.
```

```
Marker Abbreviation Description
AS Atrial Sensed
AP Atrial Paced
AT A-Tachy Sense
VS Ventricular Sensed
VP Ventricular paced
PVC Premature Ventricular Contraction
TN Noise Indication
( ) During Refractory
↑ Rate Smoothing Up
↓ Rate Smoothing Down
-Sr Motion Sensor Rate
-Hy Hysteresis Rate Pace
ATR-Dur ATR Onset Started
ATR-FB ATR Fallback Started
ATR-End ATR Fallback Ended
PVP→ PVARP Extension
```

```
Table 5: Event Marker Annotations
```

#### 4.8.1 Atrial Markers: AS AP AT TN

Atrial markers are generated for events in the atrium.

ASAtrial Sense not faster than URL

APAtrial Pace

ATAtrial Tachycardia, sense faster than URL

TNNoise indication

#### 4.8.2 Ventricular Markers: VS VP PVC TN

Ventricular markers are generated for events in the ventricle.

VSVentricular Sense

VPVentricular Pace

PVCPremature Ventricular Contraction

```
A ventricular sense is deemed to be a premature ventricular contraction
if there has been no atrial event since the previous ventricular event.
```

TNNoise indication

#### 4.8.3 Marker Modifiers: () -Hy -Sr↑ ↓

Atrial or ventricular markers may have modifiers that change their meaning.

()Sense during refractory

-HyHysteresis pace

-SrSensor-rate pace

↑Up-rate smoothing pace

↓Down-rate smoothing pace

#### 4.8.4 Augmentation Markers: ATR-Dur ATR-FB ATR-End PVP→

During atrial tachycardia response (ATR) and PVARP extension, augmentation
markers are generated synchronously with atrial or ventricular markers.

ATR-DurAtrial tachycardia detected, duration started

ATR-FBATR fallback started when tachycardia lasts for duration

ATR-EndATR ended because tachycardia ceased, or fallback period expired

PVP→PVC caused PVARP extension

### 4.9 Faults and Error Handling

#### 4.9.1 Faults

DCM malfunctions shall be indicated.

#### 4.9.2 Errors

Errors indicated are the following:

```
1.Parameter interactive limit errors shall be indicated.
```

```
2.Printer errors shall be indicated.
```

## 5 Bradycardia Therapy

User programmable parameters are provided for controlling the delivery of
patient-tailored, bradycardia therapy. These parameters are described in the
following subsections; which parameters are meaningful with which pacing mode
are listed in Table 6, Programmable Parameters for Bradycardia Therapy Modes.

```
Parameter A
A
T
```

```
V
V
T
```

```
A
O
O
```

```
A
A
I
```

```
V
O
O
```

```
V
V
I
```

```
V
D
D
```

```
D
O
O
```

```
D
D
I
```

```
D
D
D
```

```
A
O
O
R
```

```
A
A
I
R
```

```
V
O
O
R
```

```
V
V
I
R
```

```
V
D
D
R
```

```
D
O
O
R
```

```
D
D
I
R
```

```
D
D
D
R
Lower Rate Limit X X X X X X X X X X X X X X X X X X
Upper Rate Limit X X X X X X X X X X X X X X X X X X
Maximum Sensor Rate X X X X X X X X
Fixed AV Delay X X X X X X X X
Dynamic AV Delay X X X X
Sensed AV Delay Offset X X
Atrial Amplitude X X X X X X X X X X X
Ventricular Amplitude X X X X X X X X X X X X X
Atrial Pulse Width X X X X X X X X X X X
Ventricular Pulse Width X X X X X X X X X X X X X
Atrial Sensitivity X X X X X X X
Ventricular Sensitivity X X X X X X X X X
VRP X X X X X X X X X
ARP X X X X X X X
PVARP X X X X X X X
PVARP Extension X X X X
Hysteresis X X X X X X
Rate Smoothing X X X X X X X X
ATR Duration X X X X
ATR Fallback Mode X X X X
ATR Fallback Time X X X X
Activity Threshold X X X X X X X X
Reaction Time X X X X X X X X
Response Factor X X X X X X X X
Recovery Time X X X X X X X X
```

Table 6: Programmable Parameters for Bradycardia Therapy Modes

### 5.1 Lower Rate Limit (LRL)

The Lower Rate Limit (LRL) is the number of generator pace pulses delivered
per minute (atrium or ventricle) in the absence of

- Sensed intrinsic activity.
- Sensor-controlled pacing at a higher rate.

```
The LRL is affected in the following ways:
1.When Rate Hysteresis is disabled, the LRL shall define the longest allow-
able pacing interval.
```

```
2.In DXX or VXX modes, the LRL interval starts at a ventricular sensed
or paced event.
```

```
3.In AXX modes, the LRL interval starts at an atrial sensed or paced event.
```

### 5.2 Upper Rate Limit (URL)

The Upper Rate Limit (URL) is the maximum rate at which the paced ventric-
ular rate will track sensed atrial events. The URL interval is the minimum time
between a ventricular event and the next ventricular pace.

### 5.3 Atrial-Ventricular (AV) Delay

The AV delay shall be the programmable time period from an atrial event (either
intrinsic or paced) to a ventricular pace.
In atrial tracking modes, ventricular pacing shall occur in the absence of
a sensed ventricular event within the programmed AV delay when the sensed
atrial rate is between the programmed LRL and URL.
AV delay shall either be

```
1.Fixed (absolute time)
```

```
2.Dynamic
```

#### 5.3.1 Paced AV Delay

A paced AV (PAV) delay shall occur when the AV delay is initiated by an atrial
pace.

#### 5.3.2 Sensed AV Delay

A sensed AV (SAV) delay shall occur when the AV delay is initiated by an atrial
sense.

#### 5.3.3 Dynamic AV Delay

If dynamic, the AV delay shall be determined individually for each new cardiac
cycle based on the duration of previous cardiac cycles. The previous cardiac
cycle length is multiplied by a factor stored in device memory to create the
dynamic AV delay.
The AV delay shall vary between

```
1.A programmable maximum paced AV delay
```

```
2.A programmable minimum paced AV delay
```

#### 5.3.4 Sensed AV Delay Offset

The Sensed AV Delay Offset option shall shorten the AV delay following a
tracked atrial sense.
Depending on which option is functioning, the sensed AV delay offset shall
be applied to the following:

```
1.The fixed AV delay
```

```
2.The dynamic AV delay
```

### 5.4 Refractory Periods

To avoid false sensing, refractory periods follow events during which senses in
the affected chamber are ignored. To show that a sense was ignored due to
refractory, its marker is displayed in parentheses.

#### 5.4.1 Ventricular Refractory Period (VRP)

The Ventricular Refractory Period shall be the programmed time interval fol-
lowing a ventricular event during which time ventricular senses shall not inhibit
nor trigger pacing.

#### 5.4.2 Atrial Refractory Period (ARP)

For single chamber atrial modes, the Atrial Refractory Period (ARP) shall be
the programmed time interval following an atrial event during which time atrial
events shall not inhibit nor trigger pacing.

#### 5.4.3 Post Ventricular Atrial Refractory Period (PVARP)

The Post Ventricular Atrial Refractory Period shall be available in modes with
ventricular pacing and atrial sensing. The Post Ventricular Atrial Refractory
Period shall be the programmable time interval following a ventricular event
when an atrial cardiac event shall not 1. Inhibit an atrial pace. 2. Trigger a
ventricular pace.

#### 5.4.4 Extended PVARP

The Extended PVARP works as follows:

```
1.When Extended PVARP is enabled, an occurrence of a premature ventric-
ular contraction (PVC) shall cause the pulse generator to use the Extended
PVARP value for the post-ventricular atrial refractory period following the
PVC.
```

```
2.The PVARP shall always return to its normal programmed value on the
subsequent cardiac cycle regardless of PVC and other events. At most one
PVARP extension shall occur every two cardiac cycles.
```

#### 5.4.5 Refractory During AV Interval

The PG shall also be in refractory to atrial senses during the AV interval. In
this context, refractory means the pacemaker does not track or inhibit based on
the sensed activity.

### 5.5 Noise Response

In the presence of continuous noise the device response shall be asynchronous
pacing.

### 5.6 Atrial Tachycardia Response (ATR)

The Atrial Tachycardia Response prevents long term pacing of a patient at
unacceptably high rates during atrial tachycardia. When Atrial Tachycardia
Response is enabled, the pulse generator shall declare an atrial tachycardia if
the intrinsic atrial rate exceeds the URL for a sufficient amount of time.

#### 5.6.1 Atrial Tachycardia Detection

The atrial tachycardia (AT) detection algorithm determines onset and cessation
of atrial tachycardia.

```
1.AT onset shall be detected when the intervals between atrial senses are
predominately, but not exclusively, faster than URL.
```

```
2.AT cessation shall be detected when the intervals between atrial senses
are mostly, but not exclusively, faster than URL.
```

```
3.The detection period shall be short enough so ATR therapy is not unnec-
essarily delayed nor continued.
```

```
4.The detection period shall be long enough that occasional premature atrial
contractions do not cause unnecessary ATR therapy, nor cease necessary
ATR therapy upon occasional slow beats.
```

#### 5.6.2 ATR Duration

ATR Duration works as follows:

```
1.When atrial tachycardia is detected, the ATR algorithm shall enter an
ATR Duration state.
```

```
2.When in ATR Duration, the PG shall delay a programmed number of
cardiac cycles before entering Fallback.
```

```
3.The Duration delay shall be terminated immediately and Fallback shall
be avoided if, during the Duration delay, the ATR detection algorithm
determines that atrial tachycardia is over.
```

#### 5.6.3 ATR Fallback

If the atrial tachycardia condition exists after the ATR Duration delay is over,
the following shall occur:

```
1.The PG enters a Fallback state and switches to a VVIR Fallback Mode.
```

```
2.The pacing rate is dropped to the lower rate limit. The fallback time is
the total time required to drop the rate to the LRL.
```

```
3.During Fallback, if the ATR detection algorithm determines that atrial
tachycardia is over, the following shall occur:
```

- Fallback is terminated immediately
- The mode is switched back to normal

```
4.ATR-related mode switches shall always be synchronized to a ventricular
paced or sensed event.
```

### 5.7 Rate-Adaptive Pacing

The device shall have the ability to adjust the cardiac cycle in response to
metabolic need as measured from body motion using an accelerometer.

#### 5.7.1 Maximum Sensor Rate (MSR)

The Maximum Sensor Rate is the maximum pacing rate allowed as a result of
sensor control.
The Maximum Sensor Rate shall be

```
1.Required for rate adaptive modes
```

```
2.Independently programmable from the URL
```

#### 5.7.2 Activity Threshold

The activity threshold is the value the accelerometer sensor output shall exceed
before the pacemaker’s rate is affected by activity data.

#### 5.7.3 Response Factor

The accelerometer shall determine the pacing rate that occurs at various levels
of steady state patient activity.
Based on equivalent patient activity:

```
1.The highest response factor setting (16) shall allow the greatest incremen-
tal change in rate.
```

```
2.The lowest response factor setting (1) shall allow a smaller change in rate.
```

#### 5.7.4 Reaction Time

The accelerometer shall determine the rate of increase of the pacing rate. The
reaction time is the time required for an activity to drive the rate from LRL to
MSR.

#### 5.7.5 Recovery Time

The accelerometer shall determine the rate of decrease of the pacing rate. The
recovery time shall be the time required for the rate to fall from MSR to LRL
when activity falls below the activity threshold.

### 5.8 Hysteresis Pacing

When enabled, hysteresis pacing shall result in a longer period following a sensed
event before pacing. This encourages self-pacing during exercise by waiting a
little longer to pace after senses, hoping that another sense will inhibit the pace.
To use hysteresis pacing:

```
1.Hysteresis pacing must be enabled (not Off).
```

```
2.The pacing mode must be inhibiting or tracking.
```

```
3.The current pacing rate must be faster than the Hysteresis Rate Limit
(HRL), which may be slower than the Lower Rate Limit (LRL).
```

```
4.When in AAI mode, a single, non-refractory sensed atrial event shall ac-
tivate hysteresis pacing.
```

```
5.When in an inhibiting or tracking mode with ventricular pacing, a single,
non-refractory sensed ventricular event shall activate hysteresis pacing.
```

### 5.9 Rate Smoothing

Rate Smoothing shall limit the pacing rate change that occurs due to precipitous
changes in the intrinsic rate.
Two programmable rate smoothing parameters shall be available to allow
the cardiac cycle interval change to be a percentage of the previous cardiac cycle
interval:

```
1.Rate Smoothing Up
```

```
2.Rate Smoothing Down
```

The increase in pacing rate shall not exceed the Rate Smoothing Up per-
centage.
The decrease in pacing rate shall not exceed the Rate Smoothing Down
percentage.

## A Programmable Parameters

```
Parameter Programmable Values Incre-
ment
```

```
Nominal Toler-
ance
Mode Off DDD VDD DDI DOO
AOO AAI VOO VVI AAT VVT
DDDR VDDR DDIR DOOR
AOOR AAIR VOOR VVIR
```

```
— DDD —
```

```
Lower Rate Limit 30-50 ppm 5 ppm 60 ppm ±8 ms
50-90 ppm 1 ppm
90-175 ppm 5 ppm
Upper Rate Limit 50-175 ppm 5 ppm 120 ppm ±8 ms
Maximum Sensor
Rate
```

```
50-175 ppm 5 ppm 120 ppm ±4ms
```

```
Fixed AV Delay 70-300 ms 10 ms 150 ms ±8 ms
Dynamic AV Delay Off, On — Off —
Minimum Dynamic
AV Delay
```

```
30-100 ms 10 ms 50 ms
```

```
Sensed AV Delay
Offset
```

```
Off, -10 to -100 ms -10 ms Off ±1 ms
```

```
A or V Pulse Ampli-
tude Regulated
```

```
Off, 0.5-3.2V 0.1V 3.5V ±12%
```

```
3.5-7.0 V 0.5V
A or V Pulse Ampli-
tude Unregulated
```

```
Off, 1.25, 2.5, 3.75, 5.0V — 3.75V —
```

```
A or V Pulse Width 0.05 ms — 0.4 ms 0.2 ms
0.1-1.9 ms 0.1 ms
A or V Sensitivity 0.25, 0.5, 0.75 — A-0.75 mV ±20%
1.0-10 mV 0.5 mV V-2.5 mV
Ventricular Refrac-
tory Period
```

```
150-500 ms 10 ms 320 ms ±8 ms
```

```
Atrial Refractory Pe-
riod
```

```
150-500 ms 10 ms 250 ms ±8 ms
```

```
PVARP 150-500 ms 10 ms 250 ms ±8 ms
PVARP Extension Off, 50-400 ms 50 ms Off ±8 ms
Hysteresis Rate
Limit
```

```
Off or same choices as LRL — Off ±8 ms
```

```
Rate Smoothing Off, 3, 6, 9, 12, 15, 18, 21,
25%
```

```
— Off ±1%
```

```
ATR Mode On, Off — Off —
ATR Duration 10 cardiac cycles — 20 cc ±1 cc
20-80 cc 20 cc
100-2000 cc 100 cc
ATR Fallback Time 1-5 min 1 min 1 min ±1 cc
Ventricular Blanking 30-60 ms 10 ms 40 ms —
Activity Threshold V-Low, Low, Med-Low, Med,
Med-High, High, V-High
```

```
— Med —
```

```
Reaction Time 10-50 sec 10 sec 30 sec ±3 sec
Response Factor 1-16 1 8 —
Recovery Time 2-16 min 1 min 5 min ±30 sec
```

```
Table 7: Programmable Parameters
```

## B Measured Parameters

```
Parameter Increment Tolerance
P and R wave mea-
surements
```

```
0.1 mV ±5% referred to the connector
```

```
Lead Impedance 50 Ω 100 to 500Ω,±greater of 100Ωor 30%
500 to 2000Ω,±25%
2000 to 2500Ω,±30%
Battery Voltage 0.01 V ±2%
```

```
Table 8: Measured Parameters
```
