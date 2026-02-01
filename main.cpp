#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::vector<int>> hospitalVec;
std::vector<std::vector<int>> studentVec;

// PSUEDOCODE BASED ON CHAPTER-1-2026.pptx SLIDES FROM CLASS FILES SECTION
// Pass a student in and determine which hospital should take them based on the algorithm.
// Return the student, making the necessary changes within the algorithm as the while-loop completes.
/*Student AssignReject()
{
    // While a hospital is free and has not been matched/assigned to every applicant
    while ()
    {
        // Choose the hospital h
        // first = first applicant on h's list who is yet to be assigned


        if () // If first is free
        {
            // Assign h and first

        }
        else if () // If first prefers h to their current assignment h'
        {
            // Assign first and h, and h' has a free slot
        }
        else
        {
            // First rejects h
        }
    }
}*/

void ReadInputData(std::string fileSource)
{
    // Citation for methodology followed: https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/

    // Retrieve the data from the file
    std::ifstream source(fileSource);

    if (!source.is_open())
    {
        std::cout << "Unsuccessful in opening file." << std::endl;
    }
    else
    {

        std::string currLine;
        int dimension = -1;
        bool isFirst = true;
        int lineCounter = 0;
        bool hospitalStudentSwitch = false; // false - hospital ; true - student

        // Parse the data line-by-line, using the formatting specified in the description
        while (getline(source, currLine))
        {
            std::cout << currLine << std::endl;

            if (isFirst)
            {
                // The number represents dimensions of later lines
                dimension = std::stoi(currLine);
                isFirst = false;
                std::cout << dimension << std::endl;
            }
            else
            {
                // The line represents either data for hospitals or students; hospitals come first, followed by students
                // Citation: https://stackoverflow.com/questions/216068/parsing-integers-from-a-line
                std::stringstream ss(currLine);

                std::vector<int> rowToAdd;

                for (int i = 0; i < dimension; i++)
                {
                    int val;
                    ss >> val;

                    std::cout << "Stream: " << val << std::endl;
                    rowToAdd.push_back(val);
                }

                // Citation for emplacing values into 2D Vector: https://www.geeksforgeeks.org/cpp/how-to-insert-elements-into-2d-vector-in-cpp/
                if (hospitalStudentSwitch == false)
                {
                    std::cout << "false" << std::endl;
                    //hospitalVec[lineCounter].push_back(rowToAdd);
                    hospitalVec.emplace(hospitalVec.begin() + lineCounter, rowToAdd);
                }
                else if (hospitalStudentSwitch == true)
                {
                    std::cout << "true" << std::endl;
                    //studentVec[lineCounter].push_back(rowToAdd);
                    studentVec.emplace(studentVec.begin() + lineCounter, rowToAdd);
                }
                else
                {
                    std::cout << "???" << std::endl;
                }

                //int int1, int2, int3;
                //ss >> int1 >> int2;
                //std::cout << "Stream: " << int1 << " " << int2 << std::endl;

                lineCounter++;
                if (lineCounter >= dimension) { lineCounter = 0; hospitalStudentSwitch = true; };
            }
        }

        source.close();
    }
}

void WriteOutputData(std::string fileTarget)
{
    std::ofstream target(fileTarget);
    int dimension = hospitalVec.size();

    // Write the dimension
    std::string rowString = "";
    rowString += std::to_string(dimension);

    rowString += '\n';
    target << rowString;
    std::cout << rowString;

    // Write the data for hospital
    for (int i = 0; i < dimension; i++)
    {
        rowString = "";

        bool isFirst = true;
        for (int j = 0; j < dimension; j++)
        {
            if (!isFirst) { rowString += " "; }
            else { isFirst = false; }
            rowString += std::to_string(hospitalVec[i][j]);
            //std::cout << "i: " << i << ", j: " << j << ", " << hospitalVec[i][j] << std::endl;
        }
        rowString += '\n';

        target << rowString;
        std::cout << rowString;
    }

    // Write the data for student
    for (int i = 0; i < dimension; i++)
    {
        rowString = "";

        bool isFirst = true;
        for (int j = 0; j < dimension; j++)
        {
            if (!isFirst) { rowString += " "; }
            else { isFirst = false; }
            rowString += std::to_string(studentVec[i][j]);
        }
        rowString += '\n';

        target << rowString;
        std::cout << rowString;
    }

    target.close();
}


int main()
{
    // Test
    //std::cout << "Hello, World!" << std::endl;

    // Read Data
    ReadInputData("example.in");

    // Perform Gale-Shapley


    // Output Data
    WriteOutputData("example.out");

    return 0;
}