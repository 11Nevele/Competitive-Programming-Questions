#include <iostream>
#include <random>
using namespace std;
double t = 0;
double millis()
{
    return t;
}
double changeTime()
{
    t += 10 + (rand() % 6) - 3;
    return t;
}

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
        previousError = INT_MAX;
        cumError = 0;
        rateError = 0;
        kp = nkp;
        ki = nki;
        kd = nkd;
    }

    double GetPID(double error)
    {
        currentTime = millis();
        delta = (currentTime - previousTime) / 1000;
        cumError += error * delta;
        rateError = (error - previousError) / delta;
        double out = error * kp + cumError * ki + rateError * kd;
        cout << error << " " << rateError << " " << cumError << endl;
        previousTime = currentTime;
        previousError = error;
        return out;

    }
};

const int ROTATION_ERROR = 2, ROTATION_RATE_ERROR = 5;

double location = 0;

bool CheckRotationFinished(double target, PID turnPID)
{
    bool ucRange = abs(target - location) < ROTATION_ERROR;
    bool rateRange = abs(turnPID.rateError)  < ROTATION_RATE_ERROR;
    return ucRange && rateRange;
}

void drive(double out)
{
    double curTime = t, nextTime = changeTime();
    location += (360 + rand() % 30 - 60) * out * (nextTime - curTime) / 1000;
}
int main()
{
    double target;
    cin >> target;
    PID turnPID(0.02,0.00,0.00);

    double baseRotation = location;
    turnPID.previousError = baseRotation + target - location;
    double st = millis();
    changeTime();
    while(!CheckRotationFinished(baseRotation + target, turnPID))
    {
         double out = turnPID.GetPID(baseRotation + target - location);
         if(out > 1) out = 1;
         else if(out < -1) out = -1;

         drive(out);
         cout << "out: " << out << "\ttime: " << t << "\tlocation: " << location << endl;
    }
}