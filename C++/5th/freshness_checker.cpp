#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("fresh_data.txt");

    string line;

    vector<pair<uint64_t, uint64_t>> fresh_ranges;

    uint64_t fresh_sum = 0;

    bool check_mode = false;

    int line_num = 0;

    while(getline(file, line))
    {
        line_num++;
        if(line.size() == 0)
        {
            check_mode = true;
        }
        else if(check_mode)
        {
            uint64_t id = 0;

            for(int i = 0; i < line.size(); i++)
            {
                id *= 10;
                id += line[i] - '0';
            }

            for(int i = 0; i < fresh_ranges.size(); i++)
            {
                if(fresh_ranges[i].first <= id && id <= fresh_ranges[i].second)
                {
                    fresh_sum++;
                    break;
                }
            }
        }
        else
        {
            uint64_t curr_bound = 0;

            pair<uint64_t, uint64_t> range;

            bool is_higher_bound = false;

            for(int i = 0; i < line.size(); i++)
            {
                if(line[i] == '-')
                {
                    is_higher_bound = true;
                    range.first = curr_bound;
                    curr_bound = 0;
                }
                else
                {
                    curr_bound *= 10;
                    curr_bound += line[i] - '0';
                }
            }

            range.second = curr_bound;

            fresh_ranges.push_back(range);
        }
    }

    cout << fresh_sum;
}