#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

#define pi 3.1415926

int main() {
    float speed_1 = 1.41421;    float angle_1 = atan2f(1, 1);
    float speed_2 = 2.0;        float angle_2 = atan2f(0, 2);
    float speed_3 = 1.41421;    float angle_3 = atan2f(-1, -1);
    float speed_4 = 1.0;        float angle_4 = atan2f(1, 0);

    float speed_average_x = 0; float speed_average_y = 0;

    speed_average_x = speed_1 * cos(angle_1)
                    + speed_2 * cos(angle_2)
                    + speed_3 * cos(angle_3)
                    + speed_4 * cos(angle_4);

    speed_average_y = speed_1 * sin(angle_1)
                    + speed_2 * sin(angle_2)
                    + speed_3 * sin(angle_3)
                    + speed_4 * sin(angle_4);

    cout<< speed_average_x <<endl;
    cout<< speed_average_y <<endl;

    float speed_hat = 0;
    float angle_hat = 0;

    speed_hat = sqrtf(speed_average_x * speed_average_x
                    + speed_average_y * speed_average_y);

    angle_hat = atan2f(speed_average_y, speed_average_x);

    cout<<"speed_hat = "<< speed_hat <<endl;
    cout<<"angle_hat = "<< atan2f(1,2) * 180/pi <<endl;
    cout<<"angle_hat = "<< angle_hat * 180/pi <<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}