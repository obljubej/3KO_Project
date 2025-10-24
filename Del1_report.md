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
[Summarized from provided specification documents. It can be informal or semi-formal.]

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

- **AOO Mode**:
- **VOO Mode**:
- **AAI Mode**:
- **VVI Mode**:

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
