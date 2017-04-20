# easycomTOhamlib
Translates serial port rotor to TCP/IP controlled remote hamlib (rotctld) instance

Problem: I have a SATNOGS. I like orbitron. I do not like gpredict. I want to use WispDDE with my satnogs without resorting to TCP/IP easycom serial tunnels. 

Usage: Install com0com and connect one side to the serial port rotor. The rotor software now thinks that it is controlling an actual piece of hardware. Connect to the virtual serial pair using this program. Connect to the hamlib's rotctld IP/port (default 4533). Observe what would happen if you pushed 'go'. Push 'go'. If panic, push 'stop' which issues an emergency stop command to the rotor and disables 'go'. Use 'once' to send manual commands or single position updates. 

### TODO
- [X] Output data to hamlib over TCP/IP
- [X] Send manual rotor commands to move rotor manually using rotor commands... manually. 
- [X] Readback rotor position from hamlib over TCP/IP
- [ ] Input data from the serial port
- [ ] Error check numbers before sending them (do not allow negative elevation?)
- [ ] Implement polar plot
- [ ] Implement a click-to-point on said polar plot
