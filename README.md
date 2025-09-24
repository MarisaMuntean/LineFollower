**Purpose**:
This is a line follower robot which I did it for a course at university.

**Hardware used**:
Arduino Uno, L298n motor drive, 2 DC motors  
**Software used**:
Arduino IDE, C++

**Conclusions**:
1. A driver motor for 2 motors is really for 2 engines, not for 4! During this project, I learned that the datasheet should be read before (it is not enough to see only tutorials), otherwise the motors and driver do not work as expected (strange sounds produced by the motors, but also by the driver; the car is stuck at the curves although the sensors detect what it should)
2. When Arduino receives power only from batteries, the Voltage In(Vin) pin must be used. 
3. he change of speed is made with the help of PWM. Instead of sending a constant current (analog), PWM uses a digital signal (which can only be ON or OFF) to "simulate" different power levels. By changing the duration in which the signal is ON relative to the total time of a cycle, you can control how much energy reaches the device. Also, with a higher Duty Cycle, the engine gets more power and spins faster.
4. I learned to use the soldering iron!
