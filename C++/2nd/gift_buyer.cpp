#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("gift_data.txt");

    string line;

    uint64_t invalid_sum = 0;

    vector<uint64_t> invalid_ids;

    if(file.is_open())
    {
        getline(file, line);

        bool lower_bound_found = 0;
        uint64_t lower_bound = 0;
        uint64_t higher_bound = 0;

        string curr_id_string;
        string first_half_string;

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
                cout << "Lower Bound: " << lower_bound << endl << "Higher Bound: " << higher_bound << endl;

                for(uint64_t id = lower_bound; id <= higher_bound; id++)
                {
                    curr_id_string = to_string(id);
                    if(curr_id_string.size() % 2 == 1)
                    {
                        continue;
                    }
                    
                    first_half_string = "";

                    for(int j = 0; j < curr_id_string.size(); j++)
                    {
                        first_half_string.push_back(curr_id_string[j]);
                    }

                    bool valid_id = false;

                    for(int j = 0; j < curr_id_string.size() / 2; j++)
                    {
                        if(first_half_string[j] != curr_id_string[curr_id_string.size() / 2 + j])
                        {
                            valid_id = true;
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
                        cout << id << endl;
                    }
                }

                lower_bound_found = 0;
                lower_bound = 0;
                higher_bound = 0;
            }
        }

        cout << invalid_sum;

        file.close();
    }

    return 0;
}