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

    uint64_t fresh_ids = 0;

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
            bool sorted = false;
            while(!sorted)
            {
                sorted = true;
                for(int i = 0; i < fresh_ranges.size() - 1; i++)
                {
                    if(fresh_ranges[i].first > fresh_ranges[i + 1].first)
                    {
                        pair<uint64_t, uint64_t> temp = fresh_ranges[i];
                        fresh_ranges[i] = fresh_ranges[i + 1];
                        fresh_ranges[i + 1] = temp;
                        sorted = false;
                    }
                }
            }

            for(int i = 0; i < fresh_ranges.size() - 1; i++)
            {
                if(fresh_ranges[i].first == fresh_ranges[i + 1].first || fresh_ranges[i].second == fresh_ranges[i + 1].second)
                {
                    if(fresh_ranges[i].first > fresh_ranges[i + 1].first)
                    {
                        fresh_ranges.erase(fresh_ranges.begin() + i, fresh_ranges.begin() + 1 + i);
                    }
                    else
                    {
                        fresh_ranges.erase(fresh_ranges.begin() + i + 1, fresh_ranges.begin() + 2 + i);
                    }
                    i--;
                }
            }

            for(int i = 0; i < fresh_ranges.size(); i++)
            {
                cout << fresh_ranges[i].first << '-' << fresh_ranges[i].second << endl; 

                fresh_ids += fresh_ranges[i].second - fresh_ranges[i].first + 1;
            }

            break;
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

            vector<int> affected_ranges;

            for(int i = 0; i < fresh_ranges.size(); i++)
            {
                if(range.first <= fresh_ranges[i].first && fresh_ranges[i].second <= range.second)
                {
                    affected_ranges.push_back(i);
                }
                else
                {
                    if(fresh_ranges[i].first <= range.first && range.first <= fresh_ranges[i].second)
                    {
                        affected_ranges.push_back(i);
                        range.first = fresh_ranges[i].first;
                    }
                    
                    if (fresh_ranges[i].first <= range.second && range.second <= fresh_ranges[i].second)
                    {
                        if(affected_ranges.size() != 0)
                        {
                            if(affected_ranges.back() != i) 
                            {
                                affected_ranges.push_back(i);
                            }
                        }
                        
                        range.second = fresh_ranges[i].second;
                    }
                }
            }

            for(int i = affected_ranges.size() - 1; i >= 0; i--)
            {
                fresh_ranges.erase(fresh_ranges.begin() + affected_ranges[i], fresh_ranges.begin() + affected_ranges[i] + 1);
            }
            fresh_ranges.push_back(range);
        }
    }

    cout << fresh_ids;
}