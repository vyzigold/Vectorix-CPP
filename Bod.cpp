/* 
 * File:   Bod.cpp
 * Author: jarda
 * 
 * Created on 7. listopad 2015, 8:54
 */

#include "Bod.hpp"
#include <iostream>

using namespace std;

Bod::Bod() {
    this->x=0;
    this->y=0;
}

Bod::Bod(float x, float y) {
    this->x=x;
    this->y=y;
}

/*Bod::Bod(const Bod& orig) {
}

Bod::~Bod() {
}*/

float Bod::getX() const
{
    return this->x;
}

float Bod::getY() const
{
    return this->y;
}

bool Bod::setX(float x)
{
    if(x>-84&&x<84)
        this->x = x;
    else
        return false;
    return true;
}

bool Bod::setY(float y)
{
    if(y>-23&&y<23)
        this->y = y;
    else
        return false;
    return true;
}

//vykreslí jeden bod

bool Bod::nakresli() const
{
    bool nalezeno = false;
    for(int i=1;i<=48;i++)
    {
        for(int j=1;j<=170;j++)
        {
            if(j-84==this->x&&-(i-23)==this->y)
            {
                cout << "X";
                nalezeno = true;
                break;
            }
            else
                cout << " ";
        }
        if(nalezeno)
                break;
        cout << endl;
    }
}

