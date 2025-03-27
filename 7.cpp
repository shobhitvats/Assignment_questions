#include <iostream>
#include <cstdlib>
using namespace std;

void getSystemSpecs() {
    cout << "Fetching system specifications..." << endl;

    // Get CPU information
    cout << "\nCPU Information:" << endl;
    system("wmic cpu get name"); // Windows command to get CPU name
    system("wmic cpu get numberOfCores"); // Windows command to get number of cores
    system("wmic cpu get maxClockSpeed"); // Windows command to get max clock speed

    // Get RAM information
    cout << "\nRAM Information:" << endl;
    system("wmic memorychip get capacity"); // Windows command to get RAM capacity
    system("wmic memorychip get speed"); // Windows command to get RAM speed

    // Get GPU information
    cout << "\nGPU Information:" << endl;
    system("wmic path win32_videocontroller get name"); // Windows command to get GPU name

    // Get Disk information
    cout << "\nDisk Information:" << endl;
    system("wmic diskdrive get model,size"); // Windows command to get disk model and size

    // Get OS information
    cout << "\nOS Information:" << endl;
    system("wmic os get caption,version"); // Windows command to get OS name and version
}

int main() {
    getSystemSpecs();
    return 0;
}
