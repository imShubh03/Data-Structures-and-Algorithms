#include <iostream>
#include <cmath>
using namespace std;

double calculateAngle(int hour, int minute) {
    // Ensure hour is within 1-12 range
    if (hour < 1 || hour > 12) {
        return -1;
    }

    // Ensure minute is within 0-59 range
    if (minute < 0 || minute > 59) {
        return -1;
    }

    // Calculate the position of the hour hand
    double hourAngle = (hour % 12) * 30 + minute * 0.5;
    
    // Calculate the position of the minute hand
    double minuteAngle = minute * 6;
    
    // Calculate the difference
    double angle = abs(hourAngle - minuteAngle);
    
    // Find the smaller angle
    return min(angle, 360 - angle);
}

int main() {
    int hour, minute;
    cout << "Enter hour (1-12): ";
    cin >> hour;
    cout << "Enter minute (0-59): ";
    cin >> minute;
    
    double angle = calculateAngle(hour, minute);
    if (angle != -1) {
        cout << "The angle between the hour and minute hand is: " << angle << " degrees" << endl;
    }
    
    return 0;
}
