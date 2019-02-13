//
//  FileController.hpp
//  DataStructures
//
//  Created by Cassat, Stephen on 2/7/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>

#include "../Resources/CrimeData.hpp"
#include "../Resources/Music.hpp"

#ifndef LinkedListTester_hpp




#endif /* FileController_hpp */

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string filename);
};

vector<CrimeData> FileController :: readCrimeDataToVector(string filename)
{
    std :: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    //If the file exists at that path.
    if(dataFile.is_open())
    {
        //Keepreading until you are at the end of the file
        while(!dataFileof())
        {
            //Grab each line from the CSV separated by the carriage return character.
            getline(dataFile, currentCSVLine, '\r');
            //Exclude header row
            if (rowCount ! = 0)
            {
                //Create a CrimeData instance from the line. Exclude a blank line(usually if opened separately
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimeVector.push_back(row);
                }
            }
            rowCount++
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return crimeVector;
}

vector<Music> FileController :: musicDataToVector(string filename)
{
    vector<Music> musicVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    //If the file exists at that path.
    if (dataFile.is_open())
    {
        //Keep reading until you are at the end of the file.
        while (!dataFile.eof())
        {
            //Grap each liune from the CSV seperated by the carriage return character.
            getLine(dataFle, currentCSVLine, '\r');
            //Exclude header row
            if (rowCount != 0)
            {
                //Create a CrimeData instance from the line. Exclude a blank line
                if(currentCSVLine.length() != 0)
                {
                    Music row(currentCSVLine);
                    musicVector.push_back(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return musicVector;
}

