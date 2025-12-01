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

    int line_num = 0;

    if(file.is_open())
    {
        while(getline(file, line))
        {
            line_num++;
            line_length = line.size();

            int to_add = 0;

            switch(line[0])
            {
            case 'L':
                for(int i = 1; i < line_length; i++)
                {
                    to_add += (line[i] - '0') * pow(10, line_length - i - 1);
                }

                for(int i = 0; i < to_add; i++)
                {
                    position--;

                    if(position < 0)
                    {
                        position += 100;
                    }

                    if(position == 0)
                    {
                        zeroes++;
                    }
                }
                break;
            case 'R':
                for(int i = 1; i < line_length; i++)
                {
                    to_add += (line[i] - '0') * pow(10, line_length - i - 1);
                }

                for(int i = 0; i < to_add; i++)
                {
                    position++;

                    if(position > 99)
                    {
                        position -= 100;
                    }

                    if(position == 0)
                    {
                        zeroes++;
                    }
                }
                break;
            }

            cout << line_num << '\t' << to_add << '\t' << position << endl;
        }

        file.close();
    }

    cout << zeroes;

    return 0;
}