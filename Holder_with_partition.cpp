#include "Gas.cpp"
#include "Holder.cpp"
#include "Cap.cpp"
#include "Partition.cpp"
#include "Holder_with_cap.cpp"
#include "Holder_with_partition.hpp"
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>


    void Holder_with_Partition::balance_isobar(double new_T0, double new_T1) {
        if ((holders[0].get_volume() != -1) and (holders[1].get_volume() != -1)) {
            double dV = (new_T0 / holders[0].get_temperature() + new_T1 / holders[1].get_temperature()) *
                holders[0].get_volume() * holders[1].get_volume() /
                (new_T0 / holders[0].get_temperature() * holders[0].get_volume() +
                    new_T1 / holders[1].get_temperature() * holders[1].get_volume());
            double p = new_T0 / holders[0].get_temperature() *
                holders[0].get_volume() / (holders[0].get_volume() + dV) *
                holders[0].get_pressure();
            holders[0].set_pressure(p);
            holders[1].set_pressure(p);
            holders[0].set_volume(holders[0].get_volume() + dV);
            holders[1].set_volume(holders[1].get_volume() - dV);
            holders[0].set_temperature(new_T0);
            holders[1].set_temperature(new_T1);
        }
    }
    void Holder_with_Partition::balance_isoterm() {
        if ((holders[0].get_volume() != -1) and (holders[1].get_volume() != -1)) {
            double p = (holders[0].get_sum_substance_amount() * holders[0].get_temperature() +
                holders[1].get_sum_substance_amount() * holders[1].get_temperature()) * R /
                (holders[0].get_volume() + holders[1].get_volume());
            double dV = (holders[0].get_sum_substance_amount() * holders[0].get_temperature() * holders[0].get_volume() -
                holders[1].get_sum_substance_amount() * holders[1].get_temperature() * holders[1].get_volume()) /
                (holders[0].get_sum_substance_amount() * holders[0].get_temperature() +
                    holders[1].get_sum_substance_amount() * holders[1].get_temperature());
            holders[0].set_pressure(p);
            holders[1].set_pressure(p);
            holders[0].set_volume(holders[0].get_volume() + dV);
            holders[1].set_volume(holders[1].get_volume() - dV);
        }
    }
Holder_with_Partition::Holder_with_Partition(double volume_1, double volume_2) {
        partition = Partition();
        holders[0] = Holder_with_Cap(volume_1, partition);
        Holder_with_Partition::holders[1] = Holder_with_Cap(volume_2, partition);
    }
    void Holder_with_Partition::work() {
    ContinueToWork:
        cout << "In which part would you add gases? 1 or 2?" << endl;
        string garbage;
        unsigned int x;
    Error5:
        cin >> garbage;
        for (char cur_c : garbage) {
            if ((cur_c != 49) and (cur_c != 50)) {
                cout << "Wrong value. Please, enter a figure" << endl;
                goto Error5;
            }
        }
        istringstream(garbage) >> x;
    Continue_to_add:
        cout << "Do you want to add a gas into holder " << x << " ? (Y/N)" << endl;
        char c;
    Error6:
        cin >> c;
        if (c == 'Y') {
            Gas gas;
            gas.set_gas();
            holders[x - 1].add_gas(gas);
            goto Continue_to_add;
        }
        else if (c == 'N') {
            cout << "Your ";
            holders[x - 1].print_holder();
            cout << "Do you want to continue to add gases in some holder? (Y/N)" << endl;
            char d;
        Error7:
            cin >> d;
            if (d == 'Y') {
                goto ContinueToWork;
            }
            else if (d == 'N') {
                cout << "1 ";
                holders[0].print_holder();
                cout << "2 ";
                holders[1].print_holder();
                balance_isoterm();
            CountTemperatures:
                cout << "Enter temperatures of holders" << endl;
                double T1, T2;
                cin >> T1 >> T2;
                balance_isobar(T1, T2);
                cout << "Final holders:" << endl;
                cout << "1 ";
                holders[0].print_holder();
                cout << "2 ";
                holders[1].print_holder();
                cout << "Do you want to calculate for other temperatures? (Y/N)" << endl;
                char e;
            Wrong:
                cin >> e;
                if (c == 'Y') {
                    goto CountTemperatures;
                }
                else if (c == 'N') {

                }
                else {
                    cout << "Please choose one option" << endl;
                    goto Wrong;
                }
            }
            else {
                cout << "Please choose one option" << endl;
                goto Error7;
            }
        }
        else {
            cout << "Please choose one option" << endl;
            goto Error6;
        }

    }
    void Holder_with_Partition::add_gas(unsigned int holder_num, const Gas& gas) {
        (holders[holder_num]).add_gas(gas);
    }
    Holder Holder_with_Partition::throw_partition() {
        vector<Gas> common_gases;
        common_gases.insert(common_gases.end(), (holders[0].get_gases()).begin(), (holders[0].get_gases()).end());
        common_gases.insert(common_gases.end(), (holders[1].get_gases()).begin(), (holders[1].get_gases()).end());
        return Holder(holders[0].get_volume() + holders[1].get_volume(), common_gases);
    }
