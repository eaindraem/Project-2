//
//  main.cpp
//  fine.cpp
//
//  Created by Melody Myae on 10/11/23.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
// get inputs
    string identification;
    cout << "Identification: " ;
    getline(cin, identification);

    double amountOverstated;
    cout << "Overstated amount (in millions): ";
    cin >> amountOverstated;
    cin.ignore(100000, '\n');
    
    string location;
    cout << "Location: ";
    getline(cin, location);
    
    
// Calculate for fine
    double fine;

    cout.setf(ios::fixed); //set exactly 3 digits to the right of the decimal point
    cout.precision(3);
    
    //informing the user if invalid input was entered
    if (identification == "")
        cout << "---" << endl << "You must enter a property identification." << endl;
    else if (amountOverstated <= 0)
        cout << "---" << endl << "The overstated amount must be positive." << endl;
    else if (location == "")
        cout << "---" << endl << "You must enter a location." << endl;
    
    // Overstated Amount is first 60 million
    else if (amountOverstated <= 60)
    {
        fine = amountOverstated * 0.1111;
        cout << "---" << endl << "The fine for " << identification << " is $" << fine << " million." << endl;
    }
    
    // Overstatement amount is next 90 mil + location in florida or new york
    else if (amountOverstated <= 150 && (location == "florida" || location == "new york"))
    {
        fine = 60*0.1111 + ((amountOverstated-60)*0.18);
        cout << "---" << endl << "The fine for " << identification << " is $" << fine << " million." << endl;
    }
    
    //Overstated amount is next 90 million
    else if (amountOverstated <= 150)
    {
        fine = 60*0.1111 + ((amountOverstated-60)*0.153);
        cout << "---" << endl << "The fine for " << identification << " is $" << fine << " million." << endl;
    }
    
    //overstated amount exceeds 150 million + location is in florida or new york
    else if (amountOverstated > 150 && (location == "florida" || location == "new york"))
    {
        fine = (60 * 0.1111) + (90 * 0.18) + (amountOverstated-150) * 0.21;
        cout << "---" << endl << "The fine for " << identification << " is $" << fine << " million." << endl;
    }
    
    // overstated amount exceeds 150 million 
    else if (amountOverstated > 150)
    {
        fine = (60 * 0.1111) + (90 * 0.153) + (amountOverstated-150) * 0.21;
        cout << "---" << endl << "The fine for " << identification << " is $" << fine << " million." << endl;
    }
    
    
   
    
    return 0;
    
    
    

        
}
