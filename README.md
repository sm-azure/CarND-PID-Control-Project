# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Controller
A PID controller was implemented as described in the course. 

## Reflection
Based on a number of Internet resources, I tried to set the PID control parameters manually. 
* **Kp**: A number of trials were conducted and a value of 0.2 resulted in a stable value. However, with only the Kp value set, the car goes into increasing oscillations and eventually off track. This can be seen in the video [here](https://github.com/sm-azure/CarND-PID-Control-Project/blob/master/videos/p-only.mp4)
* **Kd**: Adding a Kd value to minimize the overshoots resulted in a more stable vehicle trajectory and the car could complete the lap without going off track. This can be seen in the video [here](https://github.com/sm-azure/CarND-PID-Control-Project/blob/master/videos/pd.mp4). I suspect that the vehicle might have minimal or no bias in steering.
* **Ki**: Since the car was able to complete the track with the Ki parameter set to 0, I used the error parameter to check if by introducing the Ki parameter, the error was getting reduced. This was indeed the case and the final selected value of Ki was 0.0025

The following table shows the different parameterv alues tried. The error was computed over the first 2300 iterations. 


| Kp        | Kd       | Ki     | Error      |
| ----------|:--------:| :-----:|-----------:|
| 0.2       | 0.00125  | 4.0    | Off track  |
| 0.4       | 0.00125  | 4.0    | 304.308    |
| 0.4       | 0.00250  | 4.0    | 296.327    |
| 0.4       | 0.00250  | 8.0    | 376.964    |


The manual parameter setting was interesting as it gave a very clear idea of what each parameter was doing. However, yt was also clear that it is very arbitrary and we need an automated way of computing the Kp, Ki and Kd parameters over multiple iterations. 

