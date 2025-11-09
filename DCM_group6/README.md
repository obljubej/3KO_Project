# How to run the DCM

1. Clone the repository
```bash
git clone https://https://github.com/obljubej/3KO_Project
```
2. Navigate to the DCM_group6 directory
```bash
cd 3KO_Project/DCM_group6
```
3. Install uv
```bash
pip install uv
```
4. Create and activate the virtual environment
```bash
uv venv
source .venv/Scripts/activate
```
5. Install the dependencies
```bash
uv sync
```
6. Run the application
```bash
uv run run.py
```