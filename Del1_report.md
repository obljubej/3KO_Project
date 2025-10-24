# Deliverable 1: Documentation Outline

**Group #**  
Fall 2025

---

## 1. Group Members

- Justin Shin, shinj37, 400467486
- Name, MACID, Student Number
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

#### Mode-Specific Requirements
- **AOO**: 
- **VOO**: 
- **AAI**: 
- **VVI**: 

### 2.3 Design

[Expand on the design decisions based on the requirements. Be specific about your system design and how the various components relate together.]

#### System Architecture
[Major subsystems, hardware hiding, pin mapping]

#### Programmable Parameters
[Rate limits, amplitudes, pulse widths, refractory periods, etc.]

#### Hardware Inputs and Outputs
[Signals sensed, signals controlled]

#### State Machine Design
[State machine design for each pacing mode with diagrams or tabular method]

The following permanent state pacing modes must be implemented using Simulink stateflows. All modes require the use of programmable parameters covering pulse characteristics (amplitude and width) and rate characteristics (limits and delays)\

• **AOO** (Atrial Paced, None Sensed, No Response):
    ◦ Mechanism: Provides Asynchronous Pacing in the Atrium, where paces are delivered without regard to senses.
    ◦ Requirements: Implementation must utilize the Lower Rate Limit (LRL) and Upper Rate Limit (URL)
. Must use independently programmable Atrial Amplitude and Atrial Pulse Width. <br>

• **VOO** (Ventricular Paced, None Sensed, No Response):
    ◦ Mechanism: Provides Asynchronous Pacing in the Ventricle, where paces are delivered without regard to senses.
    ◦ Requirements: Implementation must utilize the LRL and URL. Must use independently programmable Ventricular Amplitude and Ventricular Pulse Width.<br>
    
• **AAI** (Atrial Paced, Atrial Sensed, Inhibited Response):
    ◦ Mechanism: Provides Inhibited Pacing in the Atrium. An atrial sense (AS) inhibits a pending atrial pace (AP). The LRL interval starts at an atrial sensed or paced event
    ◦ Requirements: Implementation must utilize LRL, URL, Atrial Amplitude, Atrial Pulse Width, Atrial Sensitivity. Requires the Atrial Refractory Period (ARP) <br>
    
• **VVI** (Ventricular Paced, Ventricular Sensed, Inhibited Response):
    ◦ Mechanism: Provides Inhibited Pacing in the Ventricle. A ventricular sense (VS) inhibits a pending ventricular pace (VP). The LRL interval starts at a ventricular sensed or paced event
    ◦ Requirements: Implementation must utilize LRL, URL, Ventricular Amplitude, Ventricular Pulse Width, Ventricular Sensitivity. Requires the Ventricular Refractory Period (VRP).

#### Simulink Diagram
[Insert Simulink diagram screenshot]

#### DCM Screenshots
[Screenshots of your DCM, explaining its software structure]

#### Requirements Traceability
[How design decisions map directly to requirements]

---

## 3. Part 2

### 3.1 Requirements Potential Changes

[Identify which requirements may evolve in the next deliverable (e.g., adding more modes, communication, new parameters).]

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
