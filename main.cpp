/* 
 * File:   main.cpp
 * Author: jarda
 *
 * Created on 7. listopad 2015, 8:52
 */

#include <cstdlib>
#include <iostream>
#include "Bod.hpp"
#include "Primka.hpp"
#include <string>
#include <cmath>

using namespace std;

//převede string na float

float stringToFloat(string cislo)
{
    bool minus = false;
    float vysledek = 0;
    int carka = 0;
    if(cislo[0]=='-')
    {
        cislo.erase(cislo.begin());
        minus = true;
    }
    if((carka = cislo.find_first_of(","))==string::npos)
            carka = 0;
    if (carka == 0) 
    {
        for(int i =0; i < cislo.length();i++)
        {
            vysledek += (cislo[i]-'0')*pow(10,cislo.length()-i-1);
        }
    }
    else
    {
        for(int i =0; i < cislo.length();i++)
        {
            if (i < carka)
                vysledek += (cislo[i]-'0')*pow(10,carka-i-1);
            else if(i>carka)
                vysledek += (cislo[i]-'0')*pow(10,carka-i); //528,43
        }
    }
    //cout << vysledek << endl;
    if(minus) return -vysledek;
    else return vysledek;
}

/**
 * Vykreslí jednotlivé body
 * @param w pole Bodů
 * @param pocet počet bodů v poli
 */

void nakresli(Bod **w,int pocet)
{
    bool mezera = true;
    for(int i=1;i<=48;i++)
    {
        for(int j=1;j<=170;j++)
        {
            for(int k = 0; k<pocet;k++)
            {
                if(j-84==w[k]->getX()&&-(i-23)==w[k]->getY())
                {
                    cout << "X";
                    mezera = false;
                    break;
                }
            }
            if(mezera)
                cout << " ";
            mezera = true;
        }
        cout << endl;
    }
}

/**
 * Rozparsuje string na parametry přímky
 * @param vstup string obsahující rovnici přimky
 * @return vrací pole 3 parametrů přímky
 */
float *primka(string vstup)
{
    int rovnaSe = vstup.find("=");
    int sZnamenko = 0;
    int nZnamenko = 0;
    string neco;
    float *parametry = new float[3];
    for(int i =0; i<3; i++) parametry[i]=0;
    while(nZnamenko!=vstup.length())
    {
        if((nZnamenko = vstup.find_first_of("+-=",sZnamenko))==string::npos)
            nZnamenko = vstup.length();
        neco = vstup.substr(sZnamenko,nZnamenko-sZnamenko);
        if((vstup[sZnamenko-1]!= '-'&&  sZnamenko < rovnaSe)||(vstup[sZnamenko-1]== '-' && sZnamenko >= rovnaSe))
        {
            if(neco.find("x")!=string::npos)
            {
                if(neco.length()==1)
                    neco = "1";
                else
                    neco.erase(neco.end()-1);
                parametry[0] += stringToFloat(neco);
            }
            else if(neco.find("y")!=string::npos)
            {
                if(neco.length()==1)
                    neco = "1";
                else
                    neco.erase(neco.end()-1);
                parametry[1] += stringToFloat(neco);
            }
            else if(neco.find_first_of("0123456789")!=string::npos)
                parametry[2] +=stringToFloat(neco);
        }
        else
        {
            if(neco.find("x")!=string::npos)
            {
                if(neco.length()==1)
                    neco = "1";
                else
                    neco.erase(neco.end()-1);
                parametry[0] += stringToFloat("-" + neco);
            }
            else if(neco.find("y")!=string::npos)
            {
                if(neco.length()==1)
                    neco = "1";
                else
                    neco.erase(neco.end()-1);
                parametry[1] += stringToFloat("-" + neco);
            }
            else if(neco.find_first_of("0123456789")!=string::npos)
                parametry[2] += stringToFloat("-" + neco);

        }
        sZnamenko = nZnamenko+1;
    }
    return parametry;
}

int main(int argc, char** argv) {
    string vstup;
    cin >> vstup;
    if(vstup.find('^')==string::npos)
    {
        float *parametry;
        parametry = primka(vstup);
        Primka moje = Primka(parametry[0],parametry[1],parametry[2]);
        moje.nakresli();
        delete[] parametry;
    }
    Bod mujBod = Bod(20,20);
   // mujBod.nakresli();
    return 0;
}

