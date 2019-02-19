//
//  LinearTester.cpp
//  DataStructures
//
//  Created by Cassat, Stephen on 2/13/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#include "LinearTester.hpp"

void LinearTester :: testVSTL()
{
    Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
    
    crimeTimerSTL.startTimer();
    vector<CrimeData> crimes = FileController :: readCrimeDataToVector("")
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer();
    LinkedList<CrimeData> moreCrimes = fileController :: readDataToList(string filename)
    crimeTimerOOP.stopTimer();
    
    crimeTimerSTL.displayInformation();
    crimeTimerOOP.displayInformation();
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() -crimeTimerSTL.getTimeinMicroseconds() << "microseconds" << endl;
    
    
    musicSTL.startTimer();
    vector<Music> musicList = FileController :: musicDataToList("")
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    LinkedList<Music> musicList = FileController :: musicDataToList("")
    musicOOP.stopTimer
    
    musicSTL.displayInformation();
    musicOOP.displayInformation();
    cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds " << endl;
    
    crimeTimerOOP.resetTimer();
    crimeTimerSTL.resetTimer();
    musicOOP.resetTimer();
    musicSTL.resetTimer();
    
    
}
