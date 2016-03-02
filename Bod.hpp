/* 
 * File:   Bod.hpp
 * Author: jarda
 *
 * Created on 7. listopad 2015, 8:54
 */

#ifndef BOD_HPP
#define	BOD_HPP

class Bod {
public:
    Bod();
    Bod(float,float);
    /*Bod(const Bod& orig);
    virtual ~Bod();*/
    float getX() const;
    float getY() const;
    bool setX(float);
    bool setY(float);
    bool nakresli() const;
private:
    float x;
    float y;

};

#endif	/* BOD_HPP */

