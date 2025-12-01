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

    vector<string> data;

    if(file.is_open())
    {
        while(getline(file, line))
        {
            line_length = line.size();

            int to_add = 0;

            switch(line[0])
            {
            case 'L':
                for(int i = 1; i < line_length; i++)
                {
                    to_add -= (line[i] - '0') * pow(10, line_length - i - 1);
                }
                break;
            case 'R':
                for(int i = 1; i < line_length; i++)
                {
                    to_add += (line[i] - '0') * pow(10, line_length - i - 1);
                }
                break;
            }

            position += to_add;

            while(position < 0)
            {
                position += 100;
            }

            while(position > 99)
            {
                position -= 100;
            }

            cout << to_add << '\t' << position << endl;

            if(position == 0)
            {
                zeroes++;
            }
        }

        file.close();
    }

    cout << zeroes;

    return 0;
}