/* 
 * File:   Primka.cpp
 * Author: jarda
 * 
 * Created on 7. listopad 2015, 13:40
 */

#include "Primka.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Primka::Primka() {
    this->a = 1;
    this->b = 1;
    this->c = 1;
}

Primka::Primka(float a, float b, float c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
/*
Primka::Primka(const Primka& orig) {
}

Primka::~Primka() {
}
*/

float Primka::getA() const
{
    return this->a;
}

float Primka::getB() const
{
    return this->b;
}

float Primka::getC() const
{
    return this->c;
}

bool Primka::setA(float a)
{
    this->a = a;
}

bool Primka::setB(float b)
{
    this->b = b;
}

bool Primka::setC(float c)
{
    this->c = c;
}

//vykreslí přímku

bool Primka::nakresli() const
{
    for(int i=1;i<=48;i++)
    {
        for(int j=1;j<=170;j++)
        {
            if(round(this->a*(-(j-84))) == round((-(this->b))*(i-23))+round(this->c))
            {
                cout << "X";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}
