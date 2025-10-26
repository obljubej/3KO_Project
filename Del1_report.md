# Deliverable 1: Documentation Outline

**Group #**  
Fall 2025

---

## 1. Group Members

- Justin Shin, shinj37, 400467486
- Raj Pandya, pandyr2, 402425318
- Joshua Obljubek-Thomas, obljubej, 400506256
- Name, MACID, Student Number

---

## 2. Part 1

### 2.1 Introduction

The PACEMAKER system is fundamentally designed to provide dual chamber, rate adaptive bradycardia pacing support. This system consists of a Pulse Generator (PG) device, which monitors and regulates the patient's heart rate to detect and provide therapy for bradycardia conditions, and a Device Controller-Monitor (DCM), which is the primary tool used by physicians for programming, interrogation, and follow-up. The PG device offers programmable, single- and dual-chamber, rate-adaptive pacing, using leads implanted in the patient to sense intrinsic electrical signals and deliver pacing pulses. The system is indicated for use during the implantation, ambulatory, follow-up, and explantation phases of the device's life cycle.<br>

The main objective of Deliverable 1 is to parse the provided documentation to distill the specific information necessary to build a functional pacemaker and DCM. This requires properly identifying the requirements, building a design that satisfies them, implementing the design faithfully (using Simulink for the pacemaker and a language of choice for the DCM), and writing appropriate documentation. Specifically, the scope involves two major parts: implementing real-time software on the hardware platform and documenting the development efforts.<br> 

The scope of this deliverable is divided into Pacemaker Design (Part 1) and DCM Design (Part 2). Part 1 requires implementing Simulink stateflows for four permanent state pacing modes: AOO, VOO, AAI, and VVI. These stateflows must utilize programmable parameters, including pulse characteristics (width and regulated amplitude) and rate characteristics (limits and delays), while applying hardware hiding. Part 2 focuses on implementing the presentation layer (the "front-end") of the DCM user application. This includes developing an interface with a welcome screen, user registration/login capability (up to 10 local users), and interfaces to present all four required pacing modes (AOO, VOO, AAI, VVI) and their corresponding programmable parameters. Importantly, communications between the DCM and the Pacemaker are specifically excluded from the scope of this deliverable.


### 2.2 Requirements

#### Overall System Requirements
The PACEMAKER System requirements define a highly functional device and monitoring application necessary for administering bradycardia therapy. The system's primary objective is to provide dual chamber, rate adaptive bradycardia pacing support. The Pulse Generator (PG) component must monitor and regulate the patient’s heart rate, supporting all programmable bradycardia operating modes listed in the specification and five mutually exclusive operating states (Permanent, Temporary, Pace-Now, Magnet, and Power-On Reset/POR). Pacing pulses delivered by the device must have independently programmable amplitude and width for both atrial and ventricular chambers. The system utilizes bipolar lead systems (Atrial and Ventricular) for sensing and pacing, designed to operate normally when lead impedances are between 100 and 2500 ohms. <br>

The system must also fulfill extensive diagnostic and data reporting requirements. The PG must store critical historical data, including device performance, lead impedance, pacing thresholds, and patient indications. The system provides diagnostic tools for Measured Data, Threshold Tests, Rate Trending, and Histograms. Core bradycardia therapy is governed by numerous programmable parameters, including the Lower Rate Limit (LRL), Upper Rate Limit (URL), Pacing Pulse Characteristics (Amplitude/Width), AV Delay settings, and critical Refractory Periods (VRP, ARP, PVARP). The system also includes rate-adaptive features based on accelerometer input, defined by the Maximum Sensor Rate (MSR), Activity Threshold, and Reaction/Recovery Times. <br>

The Device Controller-Monitor (DCM) acts as the primary interface for programming and interrogation via an inductive telemetry link maintained over a 0 to 5 cm range. The DCM User Interface (UI) must be capable of processing user input buttons, displaying all programmable parameters for modification, and providing visual indicators for telemetry status (communication, out of range, noise, different device approached). Furthermore, the DCM is required to display real-time data, including up to three traces (2 Telemetered, 1 Surface ECG) with time-stamped event marker annotations. The DCM provides essential utility functions (e.g., About, Set Clock, New Patient) and generates mandatory printed reports (e.g., Bradycardia Parameters Report, Implant Data Report).

## Mode-Specific Requirements
### Permanent State Pacing Modes

The following permanent state pacing modes must be implemented using Simulink stateflows. All modes require the use of programmable parameters covering pulse characteristics (amplitude and width) and rate characteristics (limits and delays).

### AOO (Atrial Paced, None Sensed, No Response)

#### Mechanism
Provides Asynchronous Pacing in the Atrium, where paces are delivered without regard to senses.

#### Requirements
- Implementation must utilize the Lower Rate Limit (LRL) and Upper Rate Limit (URL)
- Must use independently programmable Atrial Amplitude and Atrial Pulse Width

### VOO (Ventricular Paced, None Sensed, No Response)

#### Mechanism
Provides Asynchronous Pacing in the Ventricle, where paces are delivered without regard to senses.

#### Requirements
- Implementation must utilize the LRL and URL
- Must use independently programmable Ventricular Amplitude and Ventricular Pulse Width

### AAI (Atrial Paced, Atrial Sensed, Inhibited Response)

#### Mechanism
Provides Inhibited Pacing in the Atrium. An atrial sense (AS) inhibits a pending atrial pace (AP). The LRL interval starts at an atrial sensed or paced event.

#### Requirements
- Implementation must utilize LRL, URL, Atrial Amplitude, Atrial Pulse Width, Atrial Sensitivity
- Requires the Atrial Refractory Period (ARP)

### VVI (Ventricular Paced, Ventricular Sensed, Inhibited Response)

#### Mechanism
Provides Inhibited Pacing in the Ventricle. A ventricular sense (VS) inhibits a pending ventricular pace (VP). The LRL interval starts at a ventricular sensed or paced event.

#### Requirements
- Implementation must utilize LRL, URL, Ventricular Amplitude, Ventricular Pulse Width, Ventricular Sensitivity
- Requires the Ventricular Refractory Period (VRP)

## 2.3 Design

### System Architecture

The pacemaker system is divided into two core subsystems: the **Pacemaker Module** (implemented in Simulink) and the **Device Controller-Monitor (DCM)** application.   The Pacemaker handles real-time signal sensing, pulse generation, and pacing logic, while the DCM provides a graphical interface for clinicians to configure and monitor programmable parameters.  

#### Subsystem Overview
- **Hardware Layer:** Implements hardware hiding through a Simulink Subsystem that abstracts physical pins from the logical model. This ensures portability: hardware mappings can change without altering the internal stateflow logic.  
- **Control Layer (Simulink):** – Implements four stateflow charts for permanent pacing modes (AOO, VOO, AAI, VVI). Each chart defines timing intervals, sense detection, and pace output behavior.  
- **Interface Layer (DCM):** – Desktop GUI that allows user login, parameter input, and mode selection. For Deliverable 1, it functions locally with parameter validation but no communication link to the pacemaker.


#### Programmable Parameters

| **Parameter** | **Variable Name (in Simulink)** | **Range / Values** | **Units** | **Description** |
|----------------|----------------------------------|--------------------|------------|------------------|
| **Pacing Mode** | PACING_MODE | {1=AOO, 2=VOO, 3=AAI, 4=VVI} | — | Selects one of the four permanent pacing modes |
| **Lower Rate Limit** | LOWER_RATE_LIMIT | 30–175 | ppm | Minimum pacing rate (maximum allowable interval between pacing pulses) |
| **Upper Rate Limit** | UPPER_RATE_LIMIT | 50–175 | ppm | Maximum pacing rate limit |
| **Atrial Amplitude** | ATRIAL_AMPLITUDE | 0.1–5.0 | V | Output pulse amplitude for the atrium |
| **Ventricular Amplitude** | VENTRICULAR_AMPLITUDE | 0.1–5.0 | V | Output pulse amplitude for the ventricle |
| **Atrial Pulse Width** |ATRIAL_PULSE_WIDTH | 1–30 | ms | Duration of each atrial pacing pulse |
| **Ventricular Pulse Width** | VENTRICULAR_PULSE_WIDTH | 1–30 | ms | Duration of each ventricular pacing pulse |
| **Atrial Sensitivity** |ATRIAL_SENSITIVITY | 0.25–10 | mV | Minimum atrial signal amplitude that will be detected as an intrinsic beat |
| **Ventricular Sensitivity** | VENTRICULAR_SENSITIVITY | 0.25–10 | mV | Minimum ventricular signal amplitude that will be detected as an intrinsic beat |
| **Atrial Refractory Period** | ARP | 150–500 | ms | Time after an atrial event during which sensing is disabled |
| **Ventricular Refractory Period** | VRP | 150–500 | ms | Time after a ventricular event during which sensing is disabled |
| **Post-Ventricular Atrial Refractory Period** | PVARP | 150–500 | ms | Extension of atrial refractory period following a ventricular event |
| **Hysteresis** | HYSTERESIS | Off | — | Enables a lower pacing rate following sensed events |
| **Rate Smoothing** | RATE_SMOOTHING | Off, 3–25 % | — | Controls gradual pacing rate adjustments to prevent abrupt changes |


#### Hardware Inputs and Outputs

| **Signal** | **Direction** | **Description** |
|-------------|---------------|------------------|
| ATR_CMP_DETECT | Input | Indicates intrinsic atrial depolarization |
| VENT_CMP_DETECT | Input | Indicates intrinsic ventricular depolarization |
| ATR_PACE_CTRL, VENT_PACE_CTRL | Output | Deliver pacing pulses for the atrium and ventricle |
| PACE_CHARGE_CTRL | Output | Controls pacing capacitor charge cycle |
| PACE_GND_CTRL, ATR_GND_CTRL, VENT_GND_CTRL | Output | Provide ground reference for pacing current |
| PACING_REF_PWM, VENT_CMP_REF_PWM | Output | Generate analog PWM pacing waveforms |
| Z_ATR_CTRL, Z_VENT_CTRL | Output | Manage output zeroing and isolation stages |

#### State Machine Design

The Stateflow chart Pacemaker_States governs pacing for all four modes.  
At startup, the **Initial_State** resets all outputs and then branches permanently to one of the mode states based on p_pacing_mode:

<img width="850" height="520" alt="Pacemaker_States Overview" src="https://github.com/user-attachments/assets/d56ac71e-990d-43e2-b23b-66fe8b0674ab" />

| **Mode Code** | **Branch Entered** | **Behavior** |
|----------------|-------------------|---------------|
| 1 | AOO | Asynchronous atrial pacing |
| 2 | VOO | Asynchronous ventricular pacing |
| 3 | AAI | Atrial inhibited pacing |
| 4 | VVI | Ventricular inhibited pacing |

#### **AOO – Atrial Asynchronous Mode**
<img width="750" height="430" alt="AOO State Machine" src="https://github.com/user-attachments/assets/39b64940-520f-4f48-84b1-d0419c8a0965" />

- **Charge_AOO** – represents the interval between pacing pulses. The system waits for after(discharge_time, msec) before firing.  
- **Discharge_AOO** – activates ATR_PACE_CTRL to deliver an atrial pulse for p_atr_pw milliseconds, then returns to charging.  
- Operates purely on timing; sensing inputs are ignored, providing continuous fixed-rate atrial pacing.

#### **VOO – Ventricular Asynchronous Mode**
<img width="750" height="430" alt="VOO State Machine" src="https://github.com/user-attachments/assets/3720a02d-3d91-43c7-98bd-52690579efe2" />

- **Charge_VOO** – waits for after(discharge_time, msec) before triggering a pulse.  
- **Discharge_VOO** – drives VENT_PACE_CTRL and PACE_GND_CTRL for p_vent_pw milliseconds to produce a ventricular pacing pulse, then resets.  
- Like AOO, VOO functions asynchronously but controls the ventricular output instead of the atrial channel.

#### **AAI – Atrial Inhibited Mode**
<img width="750" height="430" alt="AAI State Machine" src="https://github.com/user-attachments/assets/e39f5142-7658-4809-aea6-29dfcc3ddec9" />

- **Charge_AAI** – monitors ATR_CMP_DETECT.  
  - If an intrinsic atrial event occurs, pacing is inhibited.  
  - If none occurs during discharge_time, transitions to Discharge_AAI.  
- **Discharge_AAI** – delivers an atrial pulse (ATR_PACE_CTRL) for p_atr_pw milliseconds.  
- **Initial_AAI** – establishes mode setup before the pacing loop begins.  
- Incorporates p_arp for refractory control.

#### **VVI – Ventricular Inhibited Mode**
<img width="750" height="430" alt="VVI State Machine" src="https://github.com/user-attachments/assets/c798de58-1d3d-4015-a88a-a5cfb73015e9" />

- **Charge_VVI** – monitors VENT_CMP_DETECT.  
  - If intrinsic ventricular activity is detected, pacing is inhibited.  
  - If no activity is detected after discharge_time, transitions to Discharge_VVI.  
- **Discharge_VVI** – enables VENT_PACE_CTRL for p_vent_pw milliseconds, then enters the next cycle.  
- Uses p_vrp to define the ventricular refractory window and prevent false triggers.


#### Simulink Diagram
<img width="2117" height="1136" alt="image" src="https://github.com/user-attachments/assets/ddbcbf9d-96b2-43d0-9da2-cd700a6b000d" />


#### DCM Screenshots
[Screenshots of your DCM, explaining its software structure]


---

## 3. Part 2

### 3.1 Requirements Potential Changes

#### Pacemaker Requirements Changes



#### DCM Requirements Changes
Several DCM requirements will expand significantly in Deliverable 2 to transform the interface from a standalone GUI into a fully integrated system controller. The most substantial change involves implementing serial communication between the DCM and pacemaker, which represents a fundamental architectural shift from the current design. In Deliverable 1, the DCM operates as an isolated presentation layer with local parameter storage and validation. However, Deliverable 2 requires the DCM to actively program the physical pacemaker device over a communication link, transmitting programmable parameters and receiving real-time data. This integration necessitates the implementation of parameter verification mechanisms to ensure that values sent from the DCM match those stored on the pacemaker, thereby guaranteeing data integrity across the system.

The scope of supported pacing modes will also expand considerably. While Deliverable 1 focuses on four basic permanent state pacing modes (AOO, VOO, AAI, and VVI), Deliverable 2 requires support for four additional rate-adaptive modes: AOOR, VOOR, AAIR, and VVIR. These rate-adaptive modes introduce new programmable parameters related to activity sensing, including Maximum Sensor Rate (MSR), Activity Threshold, Reaction Time, and Recovery Time. The DCM interface must be extended to accommodate these additional parameters while maintaining clear organization and usability for the clinician user.

Another major functional addition is the requirement to display real-time electrogram (egram) data received from the pacemaker. The DCM must visualize live cardiac signals for the atrial channel, ventricular channel, or both simultaneously, depending on the selected pacing mode. This represents a significant expansion of the user interface to include time-stamped signal traces with event marker annotations, transforming the DCM from a simple parameter configuration tool into a comprehensive monitoring and diagnostic platform.

Finally, the specifications for programmable parameters have been refined with precisely defined ranges and increments. Pulse Amplitude must now support values from 0.1 to 5.0 V with 0.1 V increments, Pulse Width must range from 1 to 30 ms with 1 ms increments, and Sensitivity must span 0 to 5.0 V with 0.1 V increments. These precise constraints require careful consideration of data type selection to ensure representational accuracy during both storage and transmission. Additionally, documentation requirements now emphasize traceability, requiring clear demonstration of how parameters originate at the DCM interface and are ultimately implemented on the device. The selection of data types for parameter representation and communication must be explicitly justified to ensure both accuracy and reliability throughout the system.

### 3.2 Design Decision Potential Changes

[List design choices that may need revisiting (e.g., choice of libraries, interface design, architecture).]

### 3.3 Module Description

#### Module 1: [Module Name]
- **Purpose**: 
- **Key Functions/Methods**: 
  - Public:
  - Internal:
- **Global/State Variables**: 
- **Interactions with Other Components**: 

#### Module 2: [Module Name]
[Repeat structure as above]

### 3.4 Testing

#### Test Case 1: [Test Name]
1. **Purpose**: 
2. **Input Conditions**: 
3. **Expected Output**: 
4. **Actual Output**: 
5. **Result**: Pass/Fail

#### Test Case 2: [Test Name]
[Repeat structure as above]

#### DCM Testing
- Registration and login
- Parameter input validation
- Mode selection and data storage/retrieval
- [Additional test cases as needed]

### 3.5 GenAI Usage

[Provide a summary of any usage of GenAI in developing the model, DCM or writing this section. If you did not use GenAI tools at all, state that.]

---

## 4. General Notes

- Ensure all items from the Deliverable 1 handout are included
- Use screenshots of Simulink diagrams and DCM interface where appropriate
- Ensure requirements are traceable to design and test cases
- Be concise and clear
- Additional sections may be added as needed

---
