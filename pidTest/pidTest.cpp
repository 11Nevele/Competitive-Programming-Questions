#include <iostream>

double const ROTATION_ERROR = 1, ROTATION_RATE_ERROR = 1; //degree
class PID 
{
public:
    double currentTime, previousTime, delta;
    double previousError;
    double cumError;
    double rateError;
    double kp, ki, kd;
    PID(double nkp, double nki, double nkd)
    {
        currentTime = 0;
        previousTime = 0;
        delta = 0;
        previousError = 0;
        cumError = 0;
        rateError = 0;
        kp = nkp;
        ki = nki;
        kd = nkd;
    }

    double GetPID(double error, double time)
    {
        currentTime = time;
        delta = (currentTime - previousTime) / 1000;
        cumError += error * delta;
        rateError = (error - previousError) / delta;
        double out = error * kp + cumError * ki + rateError * kd;
        previousTime = currentTime;
        previousError = error;
        return out;

    }
};
bool CheckRotationFinished(double error, PID turnPID)
{
    bool ucRange = abs(error) < ROTATION_ERROR;
    bool rateRange = abs(turnPID.rateError) * turnPID.delta < ROTATION_RATE_ERROR;
    //print(2, "%f", turnPID.rateError);
    return ucRange && rateRange;
}
int main()
{
    double error, time = 0;
    std::cin >> error;

    PID pid(0.01, 0.000, 0.00);
    pid.GetPID(error, time);
    while (!CheckRotationFinished(error,pid))
    {
        time += 10;
        double out = pid.GetPID(error, time);
        if (out > 1)
            out = 1;
        else if (out < -1)
            out = -1;
        error -= out * 300 * 0.01;
        std::cout << error << "\n";
    }
    
}
