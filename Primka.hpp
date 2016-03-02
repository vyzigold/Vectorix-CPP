/* 
 * File:   Primka.hpp
 * Author: jarda
 *
 * Created on 7. listopad 2015, 13:40
 */

#ifndef PRIMKA_HPP
#define	PRIMKA_HPP

class Primka {
public:
    Primka();
    Primka(float,float,float);
    float getA() const;
    float getB() const;
    float getC() const;
    bool setA(float);
    bool setB(float);
    bool setC(float);
    bool nakresli() const;
    /*Primka(const Primka& orig);
    virtual ~Primka();*/
private:
    float a;
    float b;
    float c;

};

#endif	/* PRIMKA_HPP */

