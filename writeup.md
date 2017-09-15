## Project 9 - PID Control
### Project Goals
- Create a C++ application to guide a car around the simulator track
- Implement a PID controller and tune parameters to get smoothest possible drive

---

### Controller

The PID controller consists of 3 parts or parameters that can be tuned to change performance: The proportional portion, the integral portion, and the differential.

The proportional part of the controller corrects the steering in proportion to the ground truth. A high proportional parameter will result in a quicker turn towards the ground truth. If no integral or differential parameters were included, the steering angle would oscillate about the ground truth value, but never reach it.

The differential portion of the controller allows the steering to be corrected with less and less magnitude as the vehicle approaches the ground truth value. As such, the addition of this component to the proportional prevents the vehicle from oscillating about the ground truth value. A higher differential parameter value will result in a smoother but slower approach to the ground truth value.

The integral portion of the controller allows compensation for any abnormalities motion model of the vehicle, such as steering drift. This component takes into account the distances from the ground truth value in previous frames of data, and adds them together. The farther the vehicle is from ground truth, the larger the magnitude. The integral tuning parameter is what controls how this accumulated offset impacts the correction of the steering. As such, high integral tuning parameter values will result in much weight being given to this offset, which would cause the car to return to ground truth more quickly.

### Tuning

The P, I, and D parameters for this project were tuned manually by changing them one at a time and observing the impact on the car's performance in the simulator. Ultimately, the values were evaluated based on how much oscillation they introduced to the drive, as well as how the car handled corners, which are expected deviations from a previously linear ground truth. To be a good model, the car must not oscillate too frequently on straight track portions, but must also respond quickly to corners and not drive off the track.

### Future Work

This model could be updated in numerous ways. Per a suggestion in the main file, the speed could be controlled by a PID controller, rather than being held constant. In this way, the throttle could also change relative to the distance from ground truth, and appropriate parameters could be established to ensure that the vehicle does not proceed too quickly around corners, and takes advantages of straight track segments when it is easier to remain closer to ground truth.
