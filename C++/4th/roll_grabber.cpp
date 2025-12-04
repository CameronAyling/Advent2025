#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("roll_data.txt");

    string line;

    vector<vector<char>> roll_placements;
    int accessible_rolls = 0;
    int last_accessible_rolls = -1;

    while(getline(file, line))
    {
        vector<char> this_row;

        for(int i = 0; i < line.size(); i++)
        {
            this_row.push_back(line[i]);
        }

        roll_placements.push_back(this_row);
    }

    while (last_accessible_rolls != accessible_rolls)
    {
        last_accessible_rolls = accessible_rolls;

        for(int i = 0; i < roll_placements.size(); i++)
        {
            for(int j = 0; j < roll_placements[i].size(); j++)
            {
                if(roll_placements[i][j] == '@')
                {
                    int adjacent_rolls = 0;

                    // Check Upwards
                    if(i > 0)
                    {
                        // Up Left
                        if(j > 0)
                        {
                            if(roll_placements[i - 1][j - 1] == '@')
                            {
                                adjacent_rolls++;
                            }
                        }

                        // Up
                        if(roll_placements[i - 1][j] == '@')
                        {
                            adjacent_rolls++;
                        }

                        // Up Right
                        if(j < roll_placements[i].size() - 1)
                        {
                            if(roll_placements[i - 1][j + 1] == '@')
                            {
                                adjacent_rolls++;
                            }   
                        }
                    }

                    // Left
                    if(j > 0)
                    {
                        if(roll_placements[i][j - 1] == '@')
                        {
                            adjacent_rolls++;
                        }
                    }

                    // Right
                    if(j < roll_placements[i].size() - 1)
                    {
                        if(roll_placements[i][j + 1] == '@')
                        {
                            adjacent_rolls++;
                        }
                    }

                    // Check Downwards
                    if(i < roll_placements.size() - 1)
                    {
                        // Up Left
                        if(j > 0)
                        {
                            if(roll_placements[i + 1][j - 1] == '@')
                            {
                                adjacent_rolls++;
                            }
                        }

                        // Up
                        if(roll_placements[i + 1][j] == '@')
                        {
                            adjacent_rolls++;
                        }

                        // Up Right
                        if(j < roll_placements[i].size() - 1)
                        {
                            if(roll_placements[i + 1][j + 1] == '@')
                            {
                                adjacent_rolls++;
                            }   
                        }
                    }

                    if(adjacent_rolls < 4)
                    {
                        roll_placements[i][j] = '.';
                        accessible_rolls++;
                    }
                }
            }
        }
    }

    cout << accessible_rolls;
}