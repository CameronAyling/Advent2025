#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    clock_t before = clock();

    ifstream file;
    file.open("gift_data.txt");

    string line;

    uint64_t invalid_sum = 0;

    if(file.is_open())
    {
        getline(file, line);

        bool lower_bound_found = 0;
        uint64_t lower_bound = 0;
        uint64_t higher_bound = 0;

        string curr_id_string;
        string curr_rep_string;

        for(int i = 0; i < line.size() + 1; i++)
        {
            if(line[i] == '-')
            {
                lower_bound_found = true;
            }
            else if(line[i] - '0' < 10 && line[i] - '0' > -1)
            {
                if(!lower_bound_found)
                {
                    lower_bound *= 10;
                    lower_bound += (line[i] - '0');
                }
                else
                {
                    higher_bound *= 10;
                    higher_bound += (line[i] - '0');
                }
            }
            else
            {
                vector<uint64_t> invalid_ids;

                for(uint64_t id = lower_bound; id <= higher_bound; id++)
                {
                    curr_id_string = to_string(id);

                    for(int rep_len = 1; rep_len <= curr_id_string.size() / 2; rep_len++)
                    {
                        int rep_num = curr_id_string.size() % rep_len;
                        if(rep_num != 0)
                        {
                            continue;
                        }

                        curr_rep_string = "";
                        for(int j = 0; j < rep_len; j++)
                        {
                            curr_rep_string.push_back(curr_id_string[j]);
                        }

                        bool valid_id = false;
                        
                        for(int j = 1; j < curr_id_string.size() / rep_len; j++)
                        {
                            for(int k = 0; k < rep_len; k++)
                            {
                                if(curr_rep_string[k] != curr_id_string[j * rep_len + k])
                                {
                                    valid_id = true;
                                    break;
                                }
                            }

                            if(valid_id)
                            {
                                break;
                            }
                        }

                        if(valid_id) continue;

                        bool id_already_found = false;
                        for(int j = 0; j < invalid_ids.size(); j++)
                        {
                            if(id == invalid_ids[j])
                            {
                                id_already_found = true;
                                break;
                            }
                        }

                        if(!id_already_found)
                        {
                            invalid_ids.push_back(id);
                            invalid_sum += id;
                        }
                    }
                }

                lower_bound_found = 0;
                lower_bound = 0;
                higher_bound = 0;
            }
        }

        cout << (clock() - before) / (double)CLOCKS_PER_SEC << endl;

        cout << invalid_sum;

        file.close();
    }

    return 0;
}