#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <winsock2.h> 


#include <string>
#include <cstdlib>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <windows.h>
using namespace std;
void HELP()
{
    string otv = "Привет это Enigma. Я сделаю все чтобы тот кто не должен узнать твою стртегическую информацию \nТвое сообщение шифруется с помощю ключа в виде\n A->B B->A X->Y Y->X S->F F->S (это буква A которая проходит путь шифровки B) - положение комутаторов\n  123XXX (123 это пооложение роторов X это первые буквы шифровки  с роторов)-роторы и их положение.\n чтобы разшифровать вам нужно выставить все в такое же положение как ку отправителя.";
    for (int i = 0; i < otv.length(); i++)
    {
        cout << otv[i];
        Sleep(60);
    }
}
void LOGO()
{
    std::cout << "                                                 -SOKOLOVSKI-" << std::endl;
    std::cout << "                                                   -STUDIO-" << std::endl;
    std::cout << "                                                   -PROJECT-" << std::endl;

    cout << endl;
    cout << endl;

    std::cout << "                        ######  ####      ##   #      ######    ###        ###       #    " << std::endl;
    std::cout << "                        ##      #####     ##  ###    ##         ## ###  ### ##     ## ##   " << std::endl;
    std::cout << "                        ##      ##  ##    ##  ###   ##          ##  ## ##   ##    ##   ##  " << std::endl;
    std::cout << "                        #####   ##   ##   ##  ###  ##   ####    ##    #     ##   #########  " << std::endl;
    std::cout << "                        ##      ##    ##  ##  ###   ##      ##  ##          ##   ##     ## " << std::endl;
    std::cout << "                        ##      ##     ## ##  ###    ##    ##   ##          ##   ##     ## " << std::endl;
    std::cout << "                        ######  ##      ####  ###     #####     ##          ##   ##     ## " << std::endl;
    cout << endl;
    cout << endl;

}
int point_roter_1 = 0;
int point_roter_2 = 0;
int smesh = 0;
int smesh2 = 0;
int smesh3 = 0;
int DEsmesh1 = 0;
int DEsmesh2 = 0;
int DEsmesh3 = 0;
int nachsmesh = 0;
int XYI = 0;


//////////////////////////////////////////////переключение алфавита вперед///////////////////////////////

map<char, char> shiftValues(const std::map<char, char>& inputMap) {
    std::map<char, char> shiftedMap;

    char firstKey = inputMap.begin()->first;
    char lastValue = inputMap.rbegin()->second;

    for (const auto& pair : inputMap) {
        char shiftedValue = pair.second;

        if (pair.first == firstKey) {
            shiftedValue = lastValue;
        }
        else {
            auto prevPair = std::prev(inputMap.find(pair.first));
            shiftedValue = prevPair->second;
        }

        shiftedMap[pair.first] = shiftedValue;
    }

    return shiftedMap;
}
//////////////////////////////////////////////переключение алфавита назад///////////////////////////////
std::map<char, char> DEshiftValues(const std::map<char, char>& inputMap) {
    std::map<char, char> shiftedMap;
    char lastKey = inputMap.rbegin()->first;
    char firstValue = inputMap.begin()->second;

    for (const auto& pair : inputMap) {
        char shiftedValue = pair.second;
        if (pair.first == lastKey) {
            shiftedValue = firstValue;
        }
        else {
            auto nextPair = std::next(inputMap.find(pair.first));
            shiftedValue = nextPair->second;
        }
        shiftedMap[pair.first] = shiftedValue;
    }

    return shiftedMap;
}

/////////////////////////////////////////////////коммутаторы и DEкомутаторы///////////////////////////////////////

class Komutators
{
public:
    void set_pair(pair<char, char> one, pair<char, char> two, pair<char, char> three, pair<char, char> four, pair<char, char> five, pair<char, char> six)
    {
        par[one.first] = one.second;
        par[two.first] = two.second;
        par[three.first] = three.second;
        par[four.first] = four.second;
        par[five.first] = five.second;
        par[six.first] = six.second;
        //{ 'Q', 'W' },


    }
    void DEset_pair(pair<char, char> one, pair<char, char> two, pair<char, char> three, pair<char, char> four, pair<char, char> five, pair<char, char> six)
    {
        DEpar[one.second] = one.first;
        DEpar[two.second] = two.first;
        DEpar[three.second] = three.first;
        DEpar[four.second] = four.first;
        DEpar[five.second] = five.first;
        DEpar[six.second] = six.first;
    }
    char check_kom(char c)
    {

        it = par.find(c);
        if (it != par.end()) return par[c];
        else return c;
    }
    char DEcheck_kom(char c)
    {

        it = DEpar.find(c);
        if (it != DEpar.end())
        {
            return DEpar[c];
        }
        else
        {

            return c;
        }
    }
    //{ 'Q', 'W' },

private:
    map<char, char> par;
    map<char, char> DEpar;
    map<char, char>::iterator it;

};

/////////////////////////////////////////////////ротер1////////////////////////////////////////////


class Rotor1 {
public:
    void set_posirion(int positon, char nach)
    {
        position = positon;
        while (con_rotor1['A'] != nach)
        {
            con_rotor1 = DEshiftValues(con_rotor1);
            if (position == 1) {
                point_roter_1++;
            }
            if (position == 2) {
                point_roter_2++;
            }
        }

    }
    void de_setposition(int positon, char nach)
    {
        nachsmesh++;
        position = positon;
        while (DEcon_rotor1[nach] != 'A')
        {
            DEcon_rotor1 = shiftValues(DEcon_rotor1);
            if (position == 1) {
                point_roter_1--;
            }
            if (position == 2) {
                point_roter_2--;
            }
        }
    }

    void setAlf() {
        con_rotor1['A'] = 'A';
        con_rotor1['B'] = 'B';
        con_rotor1['C'] = 'C';
        con_rotor1['D'] = 'D';
        con_rotor1['E'] = 'E';
        con_rotor1['F'] = 'F';
        con_rotor1['G'] = 'G';
        con_rotor1['H'] = 'H';
        con_rotor1['I'] = 'I';
        con_rotor1['J'] = 'J';
        con_rotor1['K'] = 'K';
        con_rotor1['L'] = 'L';
        con_rotor1['M'] = 'M';
        con_rotor1['N'] = 'N';
        con_rotor1['O'] = 'O';
        con_rotor1['P'] = 'P';
        con_rotor1['Q'] = 'Q';
        con_rotor1['R'] = 'R';
        con_rotor1['S'] = 'S';
        con_rotor1['T'] = 'T';
        con_rotor1['U'] = 'U';
        con_rotor1['V'] = 'V';
        con_rotor1['W'] = 'W';
        con_rotor1['X'] = 'X';
        con_rotor1['Y'] = 'Y';
        con_rotor1['Z'] = 'Z';
        con_rotor1[' '] = ' ';

        DEcon_rotor1['A'] = 'A';
        DEcon_rotor1['B'] = 'B';
        DEcon_rotor1['C'] = 'C';
        DEcon_rotor1['D'] = 'D';
        DEcon_rotor1['E'] = 'E';
        DEcon_rotor1['F'] = 'F';
        DEcon_rotor1['G'] = 'G';
        DEcon_rotor1['H'] = 'H';
        DEcon_rotor1['I'] = 'I';
        DEcon_rotor1['J'] = 'J';
        DEcon_rotor1['K'] = 'K';
        DEcon_rotor1['L'] = 'L';
        DEcon_rotor1['M'] = 'M';
        DEcon_rotor1['N'] = 'N';
        DEcon_rotor1['O'] = 'O';
        DEcon_rotor1['P'] = 'P';
        DEcon_rotor1['Q'] = 'Q';
        DEcon_rotor1['R'] = 'R';
        DEcon_rotor1['S'] = 'S';
        DEcon_rotor1['T'] = 'T';
        DEcon_rotor1['U'] = 'U';
        DEcon_rotor1['V'] = 'V';
        DEcon_rotor1['W'] = 'W';
        DEcon_rotor1['X'] = 'X';
        DEcon_rotor1['Y'] = 'Y';
        DEcon_rotor1['Z'] = 'Z';
        DEcon_rotor1[' '] = ' ';

    }
    char cript(char s)
    {
        if (position == 1) {

            char ans;
            ans = con_rotor1[s];

            if (smesh == 0) {
                con_rotor1 = shiftValues(con_rotor1);
                smesh++;
                point_roter_1++;

            }
            else(smesh = 0);

            return ans;
        }

        else if (position == 2)
        {

            char ans;
            ans = con_rotor1[s];

            if (point_roter_1 == 27)
            {

                if (smesh2 == 0) {
                    con_rotor1 = shiftValues(con_rotor1);
                    smesh++;
                    point_roter_2++;
                    point_roter_1 = 0;
                }
                else(smesh2 = 0);

            }
            return ans;
        }

        else if (position == 3)
        {

            char ans;
            ans = con_rotor1[s];

            if (point_roter_2 == 27)
            {

                if (smesh3 == 0) {
                    con_rotor1 = shiftValues(con_rotor1);
                    smesh++;
                    point_roter_2 = 0;
                }
                else(smesh3 = 0);

            }
            return ans;
        }

    }
    ////////////////////////////////////////////////////////DECRIPT1/////////////////////////////////////  
    char DEcript(char s)
    {
        if (position == 1) {

            if (DEsmesh1 == 1) {

                DEcon_rotor1 = shiftValues(DEcon_rotor1);

                DEsmesh1--;
                point_roter_1--;
            }
            else (DEsmesh1 = 1);
            char ans;
            ans = DEcon_rotor1[s];
            return ans;
        }
        else if (position == 2)
        {
            if (point_roter_1 == 0)
            {
                if (DEsmesh2 == 1) {
                    DEcon_rotor1 = shiftValues(DEcon_rotor1);
                    DEsmesh2--;
                    point_roter_2--;
                    point_roter_1 = 27;
                }
                else (DEsmesh2 = 1);
            }
            char ans;
            ans = DEcon_rotor1[s];
            return ans;
        }
        else if (position == 3)
        {
            if (point_roter_2 == 0 && point_roter_1 == 0)
            {
                if (DEsmesh3 == 1) {
                    DEcon_rotor1 = shiftValues(DEcon_rotor1);
                    DEsmesh3--;
                    point_roter_2 = 27;
                }
                else (DEsmesh3 = 1);
            }
            char ans;
            ans = DEcon_rotor1[s];
            return ans;
        }
    }
    map<char, char> DEcon_rotor1;
private:
    map<char, char> con_rotor1;

    int position;
};
/////////////////////////////////////////////////ротер2////////////////////////////////////////////
class Rotor2
{
public:
    void set_posirion(int positon, char nach)
    {
        position = positon;
        while (con_rotor2['A'] != nach)
        {
            con_rotor2 = DEshiftValues(con_rotor2);
            if (position == 1) {
                point_roter_1++;
            }
            if (position == 2) {
                point_roter_2++;
            }
        }
    }
    void de_setposition(int positon, char nach)
    {

        position = positon;
        while (DEcon_rotor2[nach] != 'A')
        {
            DEcon_rotor2 = shiftValues(DEcon_rotor2);
            if (position == 1) {
                point_roter_1--;
            }
            if (position == 2) {

                point_roter_2--;
            }
        }


    }
    void setAlf()
    {
        con_rotor2['A'] = 'A';
        con_rotor2['B'] = 'B';
        con_rotor2['C'] = 'C';
        con_rotor2['D'] = 'D';
        con_rotor2['E'] = 'E';
        con_rotor2['F'] = 'F';
        con_rotor2['G'] = 'G';
        con_rotor2['H'] = 'H';
        con_rotor2['I'] = 'I';
        con_rotor2['J'] = 'J';
        con_rotor2['K'] = 'K';
        con_rotor2['L'] = 'L';
        con_rotor2['M'] = 'M';
        con_rotor2['N'] = 'N';
        con_rotor2['O'] = 'O';
        con_rotor2['P'] = 'P';
        con_rotor2['Q'] = 'Q';
        con_rotor2['R'] = 'R';
        con_rotor2['S'] = 'S';
        con_rotor2['T'] = 'T';
        con_rotor2['U'] = 'U';
        con_rotor2['V'] = 'V';
        con_rotor2['W'] = 'W';
        con_rotor2['X'] = 'X';
        con_rotor2['Y'] = 'Y';
        con_rotor2['Z'] = 'Z';
        con_rotor2[' '] = ' ';

        DEcon_rotor2['A'] = 'A';
        DEcon_rotor2['B'] = 'B';
        DEcon_rotor2['C'] = 'C';
        DEcon_rotor2['D'] = 'D';
        DEcon_rotor2['E'] = 'E';
        DEcon_rotor2['F'] = 'F';
        DEcon_rotor2['G'] = 'G';
        DEcon_rotor2['H'] = 'H';
        DEcon_rotor2['I'] = 'I';
        DEcon_rotor2['J'] = 'J';
        DEcon_rotor2['K'] = 'K';
        DEcon_rotor2['L'] = 'L';
        DEcon_rotor2['M'] = 'M';
        DEcon_rotor2['N'] = 'N';
        DEcon_rotor2['O'] = 'O';
        DEcon_rotor2['P'] = 'P';
        DEcon_rotor2['Q'] = 'Q';
        DEcon_rotor2['R'] = 'R';
        DEcon_rotor2['S'] = 'S';
        DEcon_rotor2['T'] = 'T';
        DEcon_rotor2['U'] = 'U';
        DEcon_rotor2['V'] = 'V';
        DEcon_rotor2['W'] = 'W';
        DEcon_rotor2['X'] = 'X';
        DEcon_rotor2['Y'] = 'Y';
        DEcon_rotor2['Z'] = 'Z';
        DEcon_rotor2[' '] = ' ';

    }
    char cript(char s)
    {
        if (position == 1) {

            char ans;
            ans = con_rotor2[s];

            if (smesh == 0) {
                con_rotor2 = shiftValues(con_rotor2);
                smesh++;
                point_roter_1++;
            }
            else(smesh = 0);
            return ans;
        }

        else if (position == 2)
        {

            char ans;
            ans = con_rotor2[s];

            if (point_roter_1 == 27)
            {
                if (smesh2 == 0) {
                    con_rotor2 = shiftValues(con_rotor2);
                    smesh++;
                    point_roter_2++;
                    point_roter_1 = 0;
                }
                else(smesh2 = 0);
            }
            return ans;
        }

        else if (position == 3)
        {

            char ans;
            ans = con_rotor2[s];

            if (point_roter_2 == 27)
            {
                if (smesh3 == 0) {
                    con_rotor2 = shiftValues(con_rotor2);
                    smesh++;
                    point_roter_2 = 0;
                }
                else(smesh3 = 0);
            }
            return ans;
        }

    }
    ////////////////////////////////////////////////////////DECRIPT2/////////////////////////////////////  
    char DEcript(char s)
    {

        if (position == 1) {
            if (DEsmesh1 == 1) {
                DEcon_rotor2 = shiftValues(DEcon_rotor2);
                DEsmesh1--;
                if (point_roter_1 != 0)
                    point_roter_1--;
            }
            else (DEsmesh1 = 1);
            char ans;
            ans = DEcon_rotor2[s];
            return ans;
        }

        else if (position == 2)
        {
            if (point_roter_1 == 0)
            {
                if (DEsmesh2 == 1) {
                    DEcon_rotor2 = shiftValues(DEcon_rotor2);
                    DEsmesh2--;
                    point_roter_2--;
                    point_roter_1 = 27;
                }
                else (DEsmesh2 = 1);
            }
            char ans;
            ans = DEcon_rotor2[s];
            return ans;
        }

        else if (position == 3)
        {
            if (point_roter_2 == 0 && point_roter_1 == 0)
            {
                if (DEsmesh3 == 1) {
                    DEcon_rotor2 = shiftValues(DEcon_rotor2);
                    DEsmesh3--;
                    point_roter_2 = 27;
                }
                else (DEsmesh3 = 1);
            }
            char ans;
            ans = DEcon_rotor2[s];
            return ans;
        }

    }
    map<char, char> DEcon_rotor2;
private:
    map<char, char> con_rotor2;

    int position;
};
/////////////////////////////////////////////////ротер3////////////////////////////////////////////
class Rotor3
{
public:
    void set_posirion(int positon, char nach)
    {
        position = positon;
        while (nach != con_rotor3['A'])
        {
            con_rotor3 = DEshiftValues(con_rotor3);
            if (position == 1) {
                point_roter_1++;
            }
            if (position == 2) {
                point_roter_2++;
            }
        }
    }
    void de_setposition(int positon, char nach)
    {
        position = positon;
        while (DEcon_rotor3[nach] != 'A')
        {
            DEcon_rotor3 = shiftValues(DEcon_rotor3);
            if (position == 1) {
                point_roter_1--;
            }
            if (position == 2) {
                point_roter_2--;
            }
        }
    }
    void setAlf()
    {
        con_rotor3['A'] = 'A';
        con_rotor3['B'] = 'B';
        con_rotor3['C'] = 'C';
        con_rotor3['D'] = 'D';
        con_rotor3['E'] = 'E';
        con_rotor3['F'] = 'F';
        con_rotor3['G'] = 'G';
        con_rotor3['H'] = 'H';
        con_rotor3['I'] = 'I';
        con_rotor3['J'] = 'J';
        con_rotor3['K'] = 'K';
        con_rotor3['L'] = 'L';
        con_rotor3['M'] = 'M';
        con_rotor3['N'] = 'N';
        con_rotor3['O'] = 'O';
        con_rotor3['P'] = 'P';
        con_rotor3['Q'] = 'Q';
        con_rotor3['R'] = 'R';
        con_rotor3['S'] = 'S';
        con_rotor3['T'] = 'T';
        con_rotor3['U'] = 'U';
        con_rotor3['V'] = 'V';
        con_rotor3['W'] = 'W';
        con_rotor3['X'] = 'X';
        con_rotor3['Y'] = 'Y';
        con_rotor3['Z'] = 'Z';
        con_rotor3[' '] = ' ';

        DEcon_rotor3['A'] = 'A';
        DEcon_rotor3['B'] = 'B';
        DEcon_rotor3['C'] = 'C';
        DEcon_rotor3['D'] = 'D';
        DEcon_rotor3['E'] = 'E';
        DEcon_rotor3['F'] = 'F';
        DEcon_rotor3['G'] = 'G';
        DEcon_rotor3['H'] = 'H';
        DEcon_rotor3['I'] = 'I';
        DEcon_rotor3['J'] = 'J';
        DEcon_rotor3['K'] = 'K';
        DEcon_rotor3['L'] = 'L';
        DEcon_rotor3['M'] = 'M';
        DEcon_rotor3['N'] = 'N';
        DEcon_rotor3['O'] = 'O';
        DEcon_rotor3['P'] = 'P';
        DEcon_rotor3['Q'] = 'Q';
        DEcon_rotor3['R'] = 'R';
        DEcon_rotor3['S'] = 'S';
        DEcon_rotor3['T'] = 'T';
        DEcon_rotor3['U'] = 'U';
        DEcon_rotor3['V'] = 'V';
        DEcon_rotor3['W'] = 'W';
        DEcon_rotor3['X'] = 'X';
        DEcon_rotor3['Y'] = 'Y';
        DEcon_rotor3['Z'] = 'Z';
        DEcon_rotor3[' '] = ' ';
    }

    char cript(char s)
    {
        if (position == 1) {
            char ans;
            ans = con_rotor3[s];

            if (smesh == 0) {
                con_rotor3 = shiftValues(con_rotor3);
                smesh++;
                point_roter_1++;
            }
            else(smesh = 0);
            return ans;
        }

        else if (position == 2)
        {
            char ans;
            ans = con_rotor3[s];

            if (point_roter_1 == 27)
            {

                if (smesh2 == 0) {
                    con_rotor3 = shiftValues(con_rotor3);
                    smesh++;
                    point_roter_2++;
                    point_roter_1 = 0;
                }
                else(smesh2 = 0);

            }
            return ans;
        }

        else if (position == 3)
        {
            char ans;
            ans = con_rotor3[s];
            if (point_roter_2 == 27)
            {
                if (smesh3 == 0) {
                    con_rotor3 = shiftValues(con_rotor3);
                    smesh++;
                    point_roter_2 = 0;

                }
                else(smesh3 = 0);

            }
            return ans;
        }
    }
    ////////////////////////////////////////////////////////DECRIPT3/////////////////////////////////////  
    char DEcript(char s)
    {
        if (position == 1) {
            if (DEsmesh1 == 1) {
                DEcon_rotor3 = shiftValues(DEcon_rotor3);
                DEsmesh1--;
                point_roter_1--;
            }
            else (DEsmesh1 = 1);

            char ans;
            ans = DEcon_rotor3[s];

            return ans;
        }

        else if (position == 2)
        {
            if (point_roter_1 == 0)
            {
                if (DEsmesh2 == 1) {
                    DEcon_rotor3 = shiftValues(DEcon_rotor3);
                    DEsmesh2--;
                    point_roter_2--;
                    point_roter_1 = 27;
                }
                else (DEsmesh2 = 1);


            }
            char ans;
            ans = DEcon_rotor3[s];

            return ans;
        }

        else if (position == 3)
        {
            if (point_roter_2 == 0 && point_roter_1 == 0)
            {
                if (DEsmesh3 == 1) {
                    DEcon_rotor3 = shiftValues(DEcon_rotor3);
                    DEsmesh3--;
                    point_roter_2 = 27;
                }
                else (DEsmesh3 = 1);
            }
            char ans;
            ans = DEcon_rotor3[s];


            return ans;

        }
    }
    map<char, char> DEcon_rotor3;
private:
    map<char, char> con_rotor3;

    int position;
};
/////////////////////////////////////////////////рефлекторы////////////////////////////////////////
class Reflektor
{
public:
    void setAlf()
    {
        rflektor_in['A'] = 'A';
        rflektor_in['B'] = 'B';
        rflektor_in['C'] = 'C';
        rflektor_in['D'] = 'D';
        rflektor_in['E'] = 'E';
        rflektor_in['F'] = 'F';
        rflektor_in['G'] = 'G';
        rflektor_in['H'] = 'H';
        rflektor_in['I'] = 'I';
        rflektor_in['J'] = 'J';
        rflektor_in['K'] = 'K';
        rflektor_in['L'] = 'L';
        rflektor_in['M'] = 'M';
        rflektor_in['N'] = 'N';
        rflektor_in['O'] = 'O';
        rflektor_in['P'] = 'P';
        rflektor_in['Q'] = 'Q';
        rflektor_in['R'] = 'R';
        rflektor_in['S'] = 'S';
        rflektor_in['T'] = 'T';
        rflektor_in['U'] = 'U';
        rflektor_in['V'] = 'V';
        rflektor_in['W'] = 'W';
        rflektor_in['X'] = 'X';
        rflektor_in['Y'] = 'Y';
        rflektor_in['Z'] = 'Z';
        rflektor_in[' '] = ' ';

        reflektor_out['A'] = 'A';
        reflektor_out['B'] = 'B';
        reflektor_out['C'] = 'C';
        reflektor_out['D'] = 'D';
        reflektor_out['E'] = 'E';
        reflektor_out['F'] = 'F';
        reflektor_out['G'] = 'G';
        reflektor_out['H'] = 'H';
        reflektor_out['I'] = 'I';
        reflektor_out['J'] = 'J';
        reflektor_out['K'] = 'K';
        reflektor_out['L'] = 'L';
        reflektor_out['M'] = 'M';
        reflektor_out['N'] = 'N';
        reflektor_out['O'] = 'O';
        reflektor_out['P'] = 'P';
        reflektor_out['Q'] = 'Q';
        reflektor_out['R'] = 'R';
        reflektor_out['S'] = 'S';
        reflektor_out['T'] = 'T';
        reflektor_out['U'] = 'U';
        reflektor_out['V'] = 'V';
        reflektor_out['W'] = 'W';
        reflektor_out['X'] = 'X';
        reflektor_out['Y'] = 'Y';
        reflektor_out['Z'] = 'Z';
        reflektor_out[' '] = ' ';
    }
    char ref(char c)
    {
        char ans = rflektor_in[c];
        return reflektor_out[ans];
    }
    ///////////////////////////////////////////////////////DEref///////////////////////////////////// 
    char DEref(char c)
    {
        char ans = reflektor_out[c];
        return rflektor_in[ans];
    }
private:
    map<char, char> rflektor_in;
    map<char, char> reflektor_out;
};


class Enigma :Rotor1, Rotor2, Rotor3, Reflektor, Komutators
{
public:
    Komutators komutators;

    void set_rotor(int one, int two, int three, char A, char B, char S) {
        rotor1.setAlf();
        rotor2.setAlf();
        rotor3.setAlf();
        reflector.setAlf();


        rotor1.set_posirion(one, A);
        rotor2.set_posirion(two, B);
        rotor3.set_posirion(three, S);
        rotor_position[0] = one;
        rotor_position[1] = two;
        rotor_position[2] = three;
    }

    void DEset_rotor(int one, int two, int three, char A, char B, char S) {
        rotor1.setAlf();
        rotor2.setAlf();
        rotor3.setAlf();
        reflector.setAlf();

        point_roter_1 = 27;
        point_roter_2 = 27;
        rotor1.de_setposition(one, A);
        rotor2.de_setposition(two, B);
        rotor3.de_setposition(three, S);
        rotor_position[0] = one;
        rotor_position[1] = two;
        rotor_position[2] = three;

    }

    string E_cripto(string msg)
    {                   ///если они стоят в положении 1 2 3
        if (rotor_position[0] == 1 && rotor_position[1] == 2 && rotor_position[2] == 3) {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor1.cript(rotor2.cript(rotor3.cript(reflector.ref(rotor3.cript(rotor2.cript(rotor1.cript(komutators.check_kom(msg[i]))))))));
            }
            return ans;
        }
        ///если они стоят в положении 2 1 3 
        else if (rotor_position[0] == 2 && rotor_position[1] == 1 && rotor_position[2] == 3)
        {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor2.cript(rotor1.cript(rotor3.cript(reflector.ref(rotor3.cript(rotor1.cript(rotor2.cript(komutators.check_kom(msg[i]))))))));
            }
            return ans;
        }
        ///если они стоят в положении 2 3 1 
        else if (rotor_position[0] == 2 && rotor_position[1] == 3 && rotor_position[2] == 1)
        {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor2.cript(rotor3.cript(rotor1.cript(reflector.ref(rotor1.cript(rotor3.cript(rotor2.cript(komutators.check_kom(msg[i]))))))));
            }
            return ans;
        }
        ///если они стоят в положении 3 2 1 
        else if (rotor_position[0] == 3 && rotor_position[1] == 2 && rotor_position[2] == 1)
        {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor3.cript(rotor2.cript(rotor1.cript(reflector.ref(rotor1.cript(rotor2.cript(rotor3.cript(komutators.check_kom(msg[i]))))))));///////////////////
            }
            return ans;
        }
        ///если они стоят в положении 1 3 2 
        else if (rotor_position[0] == 1 && rotor_position[1] == 3 && rotor_position[2] == 2)
        {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor1.cript(rotor3.cript(rotor2.cript(reflector.ref(rotor2.cript(rotor3.cript(rotor1.cript(komutators.check_kom(msg[i]))))))));
            }
            return ans;
        }
        ///если они стоят в положении 3 1 2 
        else if (rotor_position[0] == 3 && rotor_position[1] == 1 && rotor_position[2] == 2)
        {
            string ans;


            for (int i = 0; i < msg.length(); i++)
            {
                ans += rotor3.cript(rotor1.cript(rotor2.cript(reflector.ref(rotor2.cript(rotor1.cript(rotor3.cript(komutators.check_kom(msg[i]))))))));
            }
            return ans;
        }
    }


    string DE_E_cripto(string msg)
    {
        //положение 1 2 3 
        if (rotor_position[0] == 1 && rotor_position[1] == 2 && rotor_position[2] == 3) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();

            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);

                if (point_roter_1 == 0)
                {
                    rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);

                    point_roter_2--;

                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);
                    point_roter_2 = 27;

                }
                fix_rotors--;
            }
            point_roter_1 = 27 - point_roter_1;

            point_roter_2 = 27 - point_roter_2;

            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor1.DEcript(rotor2.DEcript(rotor3.DEcript(reflector.DEref(rotor3.DEcript(rotor2.DEcript((rotor1.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        //положение 2 1 3
        if (rotor_position[0] == 2 && rotor_position[1] == 1 && rotor_position[2] == 3) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();
            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);

                if (point_roter_1 == 0)
                {
                    rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);

                    point_roter_2--;
                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);
                    point_roter_2 = 27;
                }
                fix_rotors--;
            }
            point_roter_1 = 27 - point_roter_1;
            point_roter_2 = 27 - point_roter_2;
            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor2.DEcript(rotor1.DEcript(rotor3.DEcript(reflector.DEref(rotor3.DEcript(rotor1.DEcript((rotor2.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        //положение 2 3 1
        if (rotor_position[0] == 2 && rotor_position[1] == 3 && rotor_position[2] == 1) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();
            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);

                if (point_roter_1 == 0)
                {
                    rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);

                    point_roter_2--;
                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);
                    point_roter_2 = 27;
                }
                fix_rotors--;
            }

            point_roter_1 = 27 - point_roter_1;

            point_roter_2 = 27 - point_roter_2;
            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor2.DEcript(rotor3.DEcript(rotor1.DEcript(reflector.DEref(rotor1.DEcript(rotor3.DEcript((rotor2.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        //положение 3 2 1
        if (rotor_position[0] == 3 && rotor_position[1] == 2 && rotor_position[2] == 1) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();
            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);

                if (point_roter_1 == 0)
                {
                    rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);

                    point_roter_2--;
                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);
                    point_roter_2 = 27;
                }
                fix_rotors--;
            }
            point_roter_1 = 27 - point_roter_1;
            point_roter_2 = 27 - point_roter_2;
            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor3.DEcript(rotor2.DEcript(rotor1.DEcript(reflector.DEref(rotor1.DEcript(rotor2.DEcript((rotor3.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        //положение 1 3 2/////////////////////////////////////////////////////////////////////////////////////////////////////
        if (rotor_position[0] == 1 && rotor_position[1] == 3 && rotor_position[2] == 2) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();
            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);

                if (point_roter_1 == 0)
                {
                    rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);

                    point_roter_2--;
                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);
                    point_roter_2 = 27;
                }
                fix_rotors--;
            }
            point_roter_1 = 27 - point_roter_1;
            point_roter_2 = 27 - point_roter_2;
            //0 24
            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor1.DEcript(rotor3.DEcript(rotor2.DEcript(reflector.DEref(rotor2.DEcript(rotor3.DEcript((rotor1.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        //положение 3 1 2
        if (rotor_position[0] == 3 && rotor_position[1] == 1 && rotor_position[2] == 2) {
            //привести ротоеры к правильному положению
            int fix_rotors = msg.size();
            while (fix_rotors != 0)
            {
                point_roter_1--;
                rotor3.DEcon_rotor3 = DEshiftValues(rotor3.DEcon_rotor3);

                if (point_roter_1 == 0)
                {
                    rotor1.DEcon_rotor1 = DEshiftValues(rotor1.DEcon_rotor1);

                    point_roter_2--;
                    point_roter_1 = 27;
                }
                if (point_roter_2 == 0)
                {
                    rotor2.DEcon_rotor2 = DEshiftValues(rotor2.DEcon_rotor2);
                    point_roter_2 = 27;
                }
                fix_rotors--;
            }
            point_roter_1 = 27 - point_roter_1;
            point_roter_2 = 27 - point_roter_2;
            reverse(msg.begin(), msg.end());
            string ans;
            for (int i = 0; i < msg.length(); i++)
            {
                ans += komutators.DEcheck_kom(rotor3.DEcript(rotor1.DEcript(rotor2.DEcript(reflector.DEref(rotor2.DEcript(rotor1.DEcript((rotor3.DEcript(msg[i])))))))));
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

    }
private:
    Reflektor reflector;
    vector<int> rotor_position{ 1,2,3 };
    Rotor1 rotor1;
    Rotor2 rotor2;
    Rotor3 rotor3;
};


char ipAddress[INET_ADDRSTRLEN];//////////////////////////////////////////////////
void ShowIPAddress() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Не удалось инициализировать Winsock" << std::endl;
        return;
    }

    char hostName[255];
    if (gethostname(hostName, sizeof(hostName)) != 0) {
        std::cout << "Не удалось получить имя хоста" << std::endl;
        WSACleanup();
        return;
    }

    struct addrinfo* result = nullptr;
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(hostName, nullptr, &hints, &result) != 0) {
        std::cout << "Не удалось получить информацию об IP-адресе" << std::endl;
        WSACleanup();
        return;
    }

    struct sockaddr_in* sockAddr = reinterpret_cast<struct sockaddr_in*>(result->ai_addr);

    inet_ntop(AF_INET, &(sockAddr->sin_addr), ipAddress, INET_ADDRSTRLEN);

    std::cout << "IP-адрес компьютера: " << ipAddress << std::endl;

    freeaddrinfo(result);
    WSACleanup();
}
/////////////////показать айпи



DWORD WINAPI clientReceive(LPVOID lpParam) { //Получение данных от сервера
    char buffer[1024] = { 0 };
    SOCKET server = *(SOCKET*)lpParam;
    while (true) {
        if (recv(server, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
            cout << "recv function failed with error: " << WSAGetLastError() << endl;
            return -1;
        }
        if (strcmp(buffer, "exit\n") == 0) {
            cout << "Server disconnected." << endl;
            return 1;
        }
        cout << "Server: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
    }
    return 1;
}

DWORD WINAPI clientSend(LPVOID lpParam) { //Отправка данных на сервер
    char buffer[1024] = { 0 };
    SOCKET server = *(SOCKET*)lpParam;
    while (true) {
        fgets(buffer, 1024, stdin);
        if (send(server, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
            cout << "send failed with error: " << WSAGetLastError() << endl;
            return -1;
        }
        if (strcmp(buffer, "exit") == 0) {
            cout << "Thank you for using the application" << endl;
            break;
        }
    }
    return 1;
}



int main() {
	setlocale(LC_ALL, "Russian");
	ShowIPAddress();
    setlocale(LC_ALL, "Russian");
    LOGO();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        int reshenie;
        cout << "0 help \n1 зашивровать\n2 разшифровать\n3 отправить/принять\n";
        cin >> reshenie;
        Enigma cript;
        Enigma DEcript;
        if (reshenie == 1) {
            char YN;
            cout << "Y - сменить комутационные пары. N - оставить дефолтные пары\n";
            cin >> YN;
            if (YN == 'Y' || YN == 'y')
            {
                char q, w, e, r, t, y, u, i, o, p, a, s;
                cout << "введите первую пару\n";
                cin >> q >> w;
                cout << "введите вторую пару\n";
                cin >> e >> r;
                cout << "введите третью пару\n";
                cin >> t >> y;
                cout << "введите четвертую пару\n";
                cin >> u >> i;
                cout << "введите пятую пару\n";
                cin >> o >> p;
                cout << "введите шестую пару\n";
                cin >> a >> s;
                cript.komutators.set_pair({ q,w }, { e, r }, { t,y }, { u,i }, { o,p }, { a,s });//комутаторы
            }
            else if (YN == 'N' || YN == 'n')
            {
                cript.komutators.set_pair({ 'H','H' }, { 'E', 'E' }, { 'L','L' }, { 'O','O' }, { ' ',' ' }, { '.','.' });//комутаторы
            }
            char YN2;
            cout << "Y - сменить положение ротеров и первые буквы. N - оставить дефолтное положение\n";
            cin >> YN2;
            if (YN2 == 'Y' || YN2 == 'y')
            {
                int one, two, three;
                char l, k, j;
                cout << "введите положение ротеров и первые буквы (по типу 123AAA)";
                cin >> one >> two >> three >> l >> k >> j;
                cript.set_rotor(one, two, three, l, k, j);//положение ротеров и начальных букв
            }
            else if (YN2 == 'N' || YN2 == 'n')
            {
                cript.set_rotor(1, 2, 3, 'A', 'A', 'A');//положение ротеров и начальных букв
            }


            //cript.komutators.set_pair({ 'D','F' }, { 'F', 'D' }, { 'S','A' }, { 'A','S' }, { 'X','G' }, { 'G','X' });//комутаторы............И ТУТ
            //cript.set_rotor(3, 1, 2, 'Q', 'W', 'E');//положение ротеров и начальных букв
            string msg1;
            //312


            cout << "введите сообщение\n";
            string msg;
            cin.ignore(); // очистить входной буфер
            std::getline(std::cin, msg);
            msg1 = cript.E_cripto(msg);


            cout << " ZASHIFROVANNO: " << msg << " -> " << msg1 << endl;

        }
        else if (reshenie == 2) {
            char DYN;
            cout << "Y - сменить комутационные пары. N - оставить дефолтные пары\n";
            cin >> DYN;
            if (DYN == 'Y' || DYN == 'y')
            {
                char q1, w1, e1, r1, t1, y1, u1, i1, o1, p1, a1, s1;
                cout << "введите первую пару\n";
                cin >> q1 >> w1;
                cout << "введите вторую пару\n";
                cin >> e1 >> r1;
                cout << "введите третью пару\n";
                cin >> t1 >> y1;
                cout << "введите четвертую пару\n";
                cin >> u1 >> i1;
                cout << "введите пятую пару\n";
                cin >> o1 >> p1;
                cout << "введите шестую пару\n";
                cin >> a1 >> s1;
                DEcript.komutators.DEset_pair({ q1,w1 }, { e1, r1 }, { t1,y1 }, { u1,i1 }, { o1,p1 }, { a1,s1 });//комутаторы
            }
            else if (DYN == 'N' || DYN == 'n')
            {
                DEcript.komutators.DEset_pair({ 'H','H' }, { 'E', 'E' }, { 'L','L' }, { 'O','O' }, { ' ',' ' }, { '.','.' });//комутаторы
            }

            char DYN1;
            cout << "Y - сменить положение ротеров и первые буквы. N - оставить дефолтное положение\n";
            cin >> DYN1;
            if (DYN1 == 'Y' || DYN1 == 'y')
            {
                int one, two, three;
                char l, k, j;
                cout << "введите положение ротеров и первые буквы (по типу 123AAA)";
                cin >> one >> two >> three >> l >> k >> j;
                DEcript.DEset_rotor(one, two, three, l, k, j);
            }
            else if (DYN1 == 'N' || DYN1 == 'n')
            {
                DEcript.DEset_rotor(1, 2, 3, 'A', 'A', 'A');//положение ротеров и начальных букв
            }

            //DEcript.komutators.DEset_pair({ 'D','F' }, { 'F', 'D' }, { 'S','A' }, { 'A','S' }, { 'X','G' }, { 'G','X' });//комутаторы//////////////МЕНТЯЬ ТУТВ
            //DEcript.DEset_rotor(3, 1, 2, 'Q', 'W', 'E');//положение ротеров и начальных букв

            string msg1;
            cout << "введлите зашифрованное сообщение\n";
            cin.ignore(); // очистить входной буфер
            std::getline(std::cin, msg1);
            cout << "RAZSHIFROVANNO : " << msg1 << " -> ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << DEcript.DE_E_cripto(msg1);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else if (reshenie == 3)
        {
            cout << "введите ip получателя\n";
            cin >> ipAddress;
            WSADATA WSAData;
            SOCKET server;
            SOCKADDR_IN addr;
            WSAStartup(MAKEWORD(2, 0), &WSAData);
            if ((server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
                cout << "Socket creation failed with error: " << WSAGetLastError() << endl;
                return -1;
            };

            addr.sin_addr.s_addr = inet_addr(ipAddress); //коннект к серверу//////////////////////////////////////////////////////////
            addr.sin_family = AF_INET;
            addr.sin_port = htons(5555); //порт
            if (connect(server, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
                cout << "Server connection failed with error: " << WSAGetLastError() << endl;
                return -1;
            };

            cout << "Connected to server!" << endl;
            cout << "Now you can use our live chat application. " << " Enter \"exit\" to disconnect" << endl;

            DWORD tid;
            HANDLE t1 = CreateThread(NULL, 0, clientReceive, &server, 0, &tid);
            if (t1 == NULL) cout << "Thread creation error: " << GetLastError();
            HANDLE t2 = CreateThread(NULL, 0, clientSend, &server, 0, &tid);
            if (t2 == NULL) cout << "Thread creation error: " << GetLastError();

            WaitForSingleObject(t1, INFINITE);
            WaitForSingleObject(t2, INFINITE);
            closesocket(server);
            WSACleanup();
        }
        else if (reshenie == 0)
        {
            HELP();
        }
};
}
