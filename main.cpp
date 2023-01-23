#include "everything.hpp"
//#include "Gas.hpp"
//#include "Cap.hpp"
//#include "Partition.hpp"
//#include "Holder.hpp"
//#include "Holder_with_cap.hpp"
//#include "Holder_with_partition.hpp"

#include <iostream>
#include <string>
#include <vector>


using std::cin, std::cout, std::endl, std::string, std::vector;


int main() {
    cout << endl;
    cout << "Hello! It is a calculator for Thermodynamics!" << endl;
ContinueToCalculate:
    cout << "Here you can calculate processes for two systems: 2 holders with a partition and a holder with a piston." << endl;
    cout << "Print 1 to choose the former. Print 2 to choose the latter. Next () will be used for choosing variants." << endl;
    string str;
ErrorMain1:
    cin >> str;
    if (str == "1") {
        cout << "Enter volumes of holders" << endl;
        double volume1;
        double volume2;
        cin >> volume1 >> volume2;
        Holder_with_Partition partition_holder = Holder_with_Partition(volume1, volume2);
        partition_holder.work();
    }
    else if (str == "2") {
        cout << "Enter mass of cap" << endl;
        double cap_mass;
        cin >> cap_mass;
        cout << "Enter area of holder" << endl;
        double cap_area;
        cin >> cap_area;
        Cap cap = Cap(cap_mass, cap_area);
        Holder_with_Cap cap_holder = Holder_with_Cap(-1, cap);
        cap_holder.work();
    }
    else {
        cout << "Wrong value. Please, enter a figure" << endl;
        goto ErrorMain1;
    }
    cout << "Do you want to calculate something else? (Y/N)" << endl;
    char c;
ErrorMain2:
    cin >> c;
    if (c == 'Y') {
        goto ContinueToCalculate;
    }
    else if (c == 'N') {
        cout << "Thank you for working with me! Hope to see you soon! Bye!" << endl;
    }
    else {
        cout << "Please choose one option" << endl;
        goto ErrorMain2;
    }
}