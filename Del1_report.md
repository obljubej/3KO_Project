# Deliverable 1: Documentation Outline

**Group #**  
Fall 2025

---

## 1. Group Members

- Name, MACID, Student Number
- Name, MACID, Student Number
- Name, MACID, Student Number

---

## 2. Part 1

### 2.1 Introduction

[Briefly describe the purpose of the pacemaker system, the goals of this deliverable, and the scope of this part.]

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
