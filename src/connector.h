//
// Created by reza on 9/4/19.
//

#ifndef TEST1_CONNECTOR_H
#define TEST1_CONNECTOR_H


#include <WString.h>

class connector{

public:
    connector();
public:
    void send_data(String x, char id);

public:
    int resive_data();
public:
    void slush_Wire();
};



#endif //TEST1_CONNECTOR_H
