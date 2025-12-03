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

    int joltage_sum = 0;

    while(getline(file, line))
    {
        int curr_jolt = 0;

        int highest_jolt = 0;
        int highest_jolt_index = 0;

        for(int i = 0; i < line.size(); i++)
        {
            if(line[i] - '0' > highest_jolt)
            {
                highest_jolt = line[i] - '0';
                highest_jolt_index = i;
            }
        }

        if(highest_jolt_index == line.size() - 1)
        {
            int second_highest_jolt = 0;

            for(int i = 0; i < highest_jolt_index; i++)
            {
                if(line[i] - '0' > second_highest_jolt)
                {
                    second_highest_jolt = line[i] - '0';
                }
            }

            curr_jolt = second_highest_jolt * 10 + highest_jolt;
        }
        else
        {
            int second_highest_jolt = 0;

            for(int i = highest_jolt_index + 1; i < line.size(); i++)
            {
                if(line[i] - '0' > second_highest_jolt)
                {
                    second_highest_jolt = line[i] - '0';
                }
            }

            curr_jolt = highest_jolt * 10 + second_highest_jolt;
        }

        cout << curr_jolt << endl;

        joltage_sum += curr_jolt;
    }

    cout << joltage_sum;

    return 0;
}