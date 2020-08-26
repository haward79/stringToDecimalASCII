#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

// Function prototype.
string boolToString(bool);
bool getChoice(string, bool);
short charToAsciiNumber(char, bool, bool);
string stringToAsciiNumbers(string, bool, bool);

int main()
{
    string str = "";
    bool checkInvalidChar = true;
    bool isExtended = false;

    cout << "==== String to decimal ASCII code converter ====\n";
    cout << "=  \n";
    cout << "=  Replace invalid character to --- ? [Y/n] ";

    getline(cin, str);
    checkInvalidChar = getChoice(str, checkInvalidChar);

    cout << "=  Replace invalid character to --- ? " << boolToString(checkInvalidChar) << "\n";
    cout << "=  \n";
    cout << "=  Use extended ASCII set ? [y/N] ";

    getline(cin, str);
    isExtended = getChoice(str, isExtended);

    cout << "=  Use extended ASCII set ? " << boolToString(isExtended) << "\n";
    cout << "=  \n";
    cout << "================================================\n\n";

    while(true)
    {
        cout << "Please input a string : ";
        getline(cin, str);

        if(str != "")
            cout << "Converted : " << stringToAsciiNumbers(str, checkInvalidChar, isExtended) << "\n\n";
        else
        {
            cout << "Exit ...\n\n";
            break;
        }
    }

    return 0;
}

// Function definition.
string boolToString(bool b)
{
    if(b)
        return "true";
    else
        return "false";
}

bool getChoice(string choice, bool defaultValue)
{
    if(defaultValue)
    {
        if(choice.length() > 0 && (choice[0] == 'N' || choice[0] == 'n'))
            return false;
        else
            return true;
    }
    else
    {
        if(choice.length() > 0 && (choice[0] == 'Y' || choice[0] == 'y'))
            return true;
        else
            return false;
    }
}

short charToAsciiNumber(char ch, bool checkInvalidChar, bool isExtended)
{
    short number = (int)ch;

    if(isExtended)
    {
        // Valid value.
        if(number >= 0 && number <= 255)
            return number;

        // Invalid value.
        else
        {
            if(checkInvalidChar)
                return -1;
            else
                return number;
        }
    }
    else
    {
        // Valid value.
        if(number >= 0 && number <= 127)
            return number;
        
        // Invalid value.
        else
        {
            if(checkInvalidChar)
                return -1;
            else
                return number;
        }
    }
}

string stringToAsciiNumbers(string str, bool checkInvalidChar, bool isExtended)
{
    string result = "";
    bool isFirst = true;
    short tmp = 0;

    for(int i=0, countI=str.length(); i<countI; ++i)
    {
        if(!isFirst)
            result += " ";
        else
            isFirst = false;

        tmp = charToAsciiNumber(str[i], checkInvalidChar, isExtended);

        if(tmp != -1)
            result += std::to_string(tmp);
        else
            result += "---";
    }

    return result;
}

