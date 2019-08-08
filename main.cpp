#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    cout<<"Start\n";

    //read file
    cout<<"read file\n";
    ifstream if_in("INPUT.txt");
    if(if_in==0)
    {
        cout<<"ERROR: Could not find INPUT.TXT\n";
        return 1;
    }
    string seq,line;
    while(getline(if_in,line))
    {
        seq.append(line);
    }

    //count and make frame
    cout<<"make frame\n";
    int spaceing=10;
    int space_counter=0;
    int value_counter=1;
    string frame_string;
    for(int i=0;i<(int)seq.size();i++)
    {
        space_counter--;
        if(space_counter<=0)
        {
            stringstream ss;
            ss<<value_counter;
            //if(!frame_string.empty()) frame_string.erase((int)frame_string.length()-(int)(ss.str().length())+1);
            frame_string.append(ss.str());
            space_counter=spaceing;
            value_counter+=spaceing;
            //jump in loop
            for(int j=1;j<int(ss.str().length());j++)
            {
                i++;
                space_counter--;
            }
        }
        else
        {
            frame_string.append("-");
        }
    }

    //print
    cout<<"print file\n";
    ofstream of_out("OUTPUT.txt");
    if(of_out==0)
    {
        cout<<"ERROR: Could not create output file\n";
        return 2;
    }
    of_out<<frame_string<<endl;
    of_out<<seq<<endl;

    cout<<"Done\n";
    return 0;
}
