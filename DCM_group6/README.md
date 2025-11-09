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


# UART Setup:

Without hardware, you will need a virtual UART port to see the output of the pacemaker.

We are using socat, but you might need to use another tool based on the operating system.

If you are using socat, do the following operations:

Goal: We want to see the data your application sends.
- Your Application will send data to one port.
- Our Listener will read data from the other port.

Terminal 1:
```bash
socat -d -d pTY,raw,echo=0 PTY,raw,echo=0
```

Note the two ports it prints. Example: N PTY is /dev/ttys019 (This is Port A) N PTY is /dev/ttys020 (This is Port B)

Terminal 2: Set up the Listener on Port A We will listen to Port A and pipe its output to hexdump.
```bash
socat /dev/ttys014,raw,echo=0 - | hexdump -C
```

Terminal 3: Run the Application on Port B This is the program that will generate the data.
- In config/app_config.json, set serial_port to the other port name from Terminal 1 (e.g., Port B). "serial_port": "/dev/ttys020"
- Run your application:

```bash
uv run run.py # just run the application with the above steps
```

As soon as your application sends data to /dev/ttys020, it will travel through the virtual cable and appear in Terminal 2's hexdump output.

Next click send data button and you should see the output in the second terminal.