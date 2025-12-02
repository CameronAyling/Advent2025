#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("safe_data.txt");

    string line;
    int line_length;

    int position = 50;

    int zeroes = 0;

    if(file.is_open())
    {
        while(getline(file, line))
        {
            line_length = line.size();

            bool is_left = line[0] == 'L';

            zeroes -= (position == 0) && is_left;

            for(int i = 1; i < line_length; i++)
            {
                if(line_length - i < 3) 
                {
                    position += (line[i] - '0') * pow(10, line_length - i - 1) * (is_left ? -1 : 1);
                }
                else 
                {
                    zeroes += (line[i] - '0') * pow(10, line_length - i - 3);
                }
            }

            if(position > 99)
            {
                position -= 100;
                zeroes++;
            }
            else if(position < 0)
            {
                zeroes++;
                position += 100;
            }
            else if(position == 0)
            {
                zeroes++;
            }
        }

        file.close();
    }

    cout << zeroes << endl;

    return 0;
}