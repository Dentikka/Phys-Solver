#pragma once

#include "Cap.hpp"
#include "Holder.hpp"

class Holder_with_Cap : public Holder {
protected:
    Cap cap;
    void balance(double temp);
public:
    Holder_with_Cap();
    Holder_with_Cap(double vol, Cap cap);
    void set_volume(double new_volume);
    void set_pressure(double press);
    void work();
    void count_temperature();
};