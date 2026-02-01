#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::vector<int>> hospitals;
std::vector<std::vector<int>> students;

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
                int int1, int2;
                ss >> int1 >> int2;
                std::cout << "Stream: " << int1 << " " << int2 << std::endl;

                lineCounter++;
                if (lineCounter >= dimension) { lineCounter = 0; };
            }
        }

        source.close();
    }
}

void ExportOutputData(std::string fileTarget)
{

}


int main()
{
    std::cout << "Hello, World!" << std::endl;

    ReadInputData("example.in");

    return 0;
}