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

Create 3 different terminals and run the following in each one seperately:

Terminal 1:
```bash
socat -d -d pTY,raw,echo=0 PTY,raw,echo=0
```

This will create 2 ports, a listening port and a sending port, now you need to tell the application to use these ports. take note of the port names, it should look something like: /dev/ttys019 and /dev/ttys020, but the number might be different. 

Terminal 2: Use the port name to connect to the virtual port (adjust the port number as needed) use the listening port name
```bash
socat /dev/ttys014,raw,echo=0 - | hexdump -C
```

Terminal 3: Run the application, **UNDER `config/app_config.json`, change the `serial_port` to the recieving port namel**
```bash
uv run run.py # just run the application with the above steps
```

Remember, the ports are different for sending and receiving, so you need to use the correct port name. to see the data

Next click send data button and you should see the output in the second terminal.