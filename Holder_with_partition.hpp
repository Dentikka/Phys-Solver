#pragma once

#include "Gas.hpp"
#include "Partition.hpp"
#include "Holder_with_cap.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class Holder_with_Partition {
protected:
    Holder_with_Cap holders[2];
    Partition partition;
    void balance_isobar(double new_T0, double new_T1);
    void balance_isoterm();
public:
    Holder_with_Partition(double volume_1, double volume_2);
    void work();
    void add_gas(unsigned int holder_num, const Gas& gas);
    Holder throw_partition();
};