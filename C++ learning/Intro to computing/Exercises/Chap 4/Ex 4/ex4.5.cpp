#include <iostream>

using namespace std;
int main() {
    int totalWorkHours;
    int startDay;
    cout << "Enter the total work hours for the week (0-120): ";
    cin >> totalWorkHours;
    cout << "Enter the starting day (1=Mon, 2=Tue, ..., 7=Sun): ";
    cin >> startDay;
    if (totalWorkHours < 0 || totalWorkHours > 120) {
        cout << "Invalid total work hours. Please enter a value between 0 and 120." << endl;
        return 1; 
    } else if (startDay < 1 || startDay > 7) {
        cout << "Invalid starting day. Please enter a value between 1 and 7." << endl;
        return 1; 
    }
    int standardHours = 0;
    int maxPossibleHours = 0;
    bool prevDayWasOvertime = false;  
    int startDayIndex = startDay - 1; 

    int currentDayIndex;
    bool isSaturday;
    int dailyStandardLimit;
    int dailyMaxLimit;
    currentDayIndex = (startDayIndex + 0) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit; 
        prevDayWasOvertime = true;
    }
    currentDayIndex = (startDayIndex + 1) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
            prevDayWasOvertime = true;
        } else {
            maxPossibleHours += dailyStandardLimit;
            prevDayWasOvertime = false;
        }
    }
    currentDayIndex = (startDayIndex + 2) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
            prevDayWasOvertime = true;
        } else {
            maxPossibleHours += dailyStandardLimit;
            prevDayWasOvertime = false;
        }
    }
    currentDayIndex = (startDayIndex + 3) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
            prevDayWasOvertime = true;
        } else {
            maxPossibleHours += dailyStandardLimit;
            prevDayWasOvertime = false;
        }
    }
    currentDayIndex = (startDayIndex + 4) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
            prevDayWasOvertime = true;
        } else {
            maxPossibleHours += dailyStandardLimit;
            prevDayWasOvertime = false;
        }
    }
    currentDayIndex = (startDayIndex + 5) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
        prevDayWasOvertime = false;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
            prevDayWasOvertime = true;
        } else {
            maxPossibleHours += dailyStandardLimit;
            prevDayWasOvertime = false;
        }
    }
    currentDayIndex = (startDayIndex + 6) % 7;
    isSaturday = (currentDayIndex == 5);
    if (isSaturday) {
        dailyStandardLimit = 6;
        dailyMaxLimit = 6;
        standardHours += dailyStandardLimit;
        maxPossibleHours += dailyMaxLimit;
    } else {
        dailyStandardLimit = 10;
        dailyMaxLimit = 14;
        standardHours += dailyStandardLimit;
        if (!prevDayWasOvertime) {
            maxPossibleHours += dailyMaxLimit;
        } else {
            maxPossibleHours += dailyStandardLimit;
        }
    }
    bool doable;
    bool needsExtraHours;
    if (totalWorkHours <= maxPossibleHours) {
        doable = true;
    } else {
        doable = false;
    }
    if (totalWorkHours > standardHours) {
        needsExtraHours = true;
    } else {
        needsExtraHours = false;
    }
    cout << "\n--- Schedule Analysis ---" << endl;
    cout << "Total Work Hours Entered: " << totalWorkHours << endl;
    cout << "Standard Work Hours Available: " << standardHours << endl;
    cout << "Maximum Possible Work Hours (No consecutive OT): " << maxPossibleHours << endl;
    if (doable) {
        cout << "The workload is doable" << endl;
        if (needsExtraHours) {
            cout << "Extra hours will be needed." << endl;
        } else {
            cout << "No extra hours are needed." << endl;
        }
    } else {
        cout << "\nResult: The workload is not doable (Exceeds maximum possible hours or violates consecutive OT rule). 😥" << endl;
    }

    return 0;
}