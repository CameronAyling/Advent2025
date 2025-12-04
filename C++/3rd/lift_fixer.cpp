#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("lift_data.txt");

    string line;

    uint64_t joltage_sum = 0;

    while(getline(file, line))
    {
        uint64_t curr_jolt = 0;
        int highest_jolt = 0;
        int highest_jolt_index = -1;

        for(int digits = 0; digits < 12; digits++)
        {
            highest_jolt = 0;

            for(int i = highest_jolt_index + 1; i < line.size() - (11 - digits); i++)
            {
                if(line[i] - '0' > highest_jolt)
                {
                    highest_jolt = line[i] - '0';
                    highest_jolt_index = i;
                }
            }

            curr_jolt *= 10;
            curr_jolt += highest_jolt;
        }

        joltage_sum += curr_jolt;

        cout << curr_jolt << endl;
    }

    cout << joltage_sum;

    return 0;
}