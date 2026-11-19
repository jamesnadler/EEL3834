#include <iostream>
#include <iomanip> // i included this library to format outputs to 2 decimal places

using namespace std;

struct PackageSummary { // stores information for all entered packages
    double totalWeight;
    double averageWeight;
    double heaviestWeight;
    int overnightCount;
};

class Package {
    private:
        string trackingNumber;
        string destinationCity;
        double weight;
        int priority;
        // these variables can only be accessed by public member functions

    public:
        Package() { // initializing package details with a constructor. sets the variables to default when a new instance is created
            trackingNumber = "UNKNOWN";
            destinationCity = "UNKNOWN";
            weight = 0.0;
            priority = 1;
        }

        void setTrackingNumber(string tracking) {
            trackingNumber = tracking;
        }

        void setDestinationCity(string city) {
            destinationCity = city;
        }

        void setWeight(double packageWeight) {
            weight = packageWeight;
        }

        void setPriority(int packagePriority) {
            priority = packagePriority;
        } // these set functions simply set each variable of the class to the user input

        string getTrackingNumber() const {
            return trackingNumber;
        }

        string getDestinationCity() const {
            return destinationCity;
        }

        double getWeight() const {
            return weight;
        }

        int getPriority() const {
            return priority;
        } // these get functions simply return each specific value when called

        string getPriorityName() const { // determines package delivery priority based on number entered
            if (priority==1) {
                return "Standard";
            }
            else if (priority==2) {
                return "Expedited";
            }
            else if (priority == 3) {
                return "Overnight";
            }
            return "N/A"; // this is what is returned if no condition is satified
        }

        void displayPackage() const { // this member function can be called to display all user-entered info
            cout << "Tracking Number: " << trackingNumber << endl;
            cout << "Destination City: " << destinationCity << endl;
            cout << "Weight: " << fixed << setprecision(2)<< weight << " pounds" << endl;
            cout << "Priority: " << getPriorityName() << endl;
        }
};

// declaring functions

bool isValidWeight(double weight);

bool isValidPriority (int priority);

PackageSummary calculateSummary(const Package packages[], int numberUsed);

void sortPackagesByWeight (Package packages[], int numberUsed);

int searchByTrackingNumber (const Package packages[], int numberUsed, string trackingNumber);

void displayAllPackages (const Package packages[], int numberUsed);

int main() {

    string repeat; // initializing input string for tracker repeat

    cout << "Welcome to the Package Delivery Tracker!" << endl;
    cout << endl;

    do {
        int numberOfPackages;

        while (true) { // loops until a valid number of packages is entered
            cout << "How many packages would you like to enter (1-10): ";
            cin >> numberOfPackages;

            if (numberOfPackages > 0 && numberOfPackages <= 10) {
                break; // ends loop
            }
            else {
                cout << "Invalid number of packages! Please enter a value from 1 to 10." << endl;
            }
        }

        Package packages[10]; // initializing packages[] array

        for (int i = 0; i < numberOfPackages; i++) { // loops a user-specified amount of times, asking for a tracking number, destination city, weight, and priority for each package
            cout << endl;
            cout << "Package " << i+1 << endl;

            string tracking;
            string city;
            double weight;
            int priority;

            cout << "Enter tracking number: ";
            cin >> tracking;
            packages[i].setTrackingNumber(tracking); // gives a tracking number value to the array

            cout << "Enter destination city: ";
            cin >> city;
            packages[i].setDestinationCity(city); // gives a destination city value to the array

            cout << "Enter package weight in pounds: ";
            cin >> weight;

            while (true) { // gives a weight value to the array only if a valid weight is entered. loops otherwise.
                if (isValidWeight(weight) == true) {
                    packages[i].setWeight(weight); 
                    break;
                }
                else {
                    cout << "Invalid weight! Weight must be greater than 0." << endl;
                    cout << "Enter package weight in pounds: ";
                    cin >> weight;
                }
            }

            cout << "Enter delivery priority (1-3): ";
            cin >> priority;

            while (true) { // gives a priority value to the array only if a valid priority is entered. loops otherwise.
                if (isValidPriority(priority) == true) {
                    packages[i].setPriority(priority); 
                    break;
                }
                else {
                    cout << "Invalid priority! Please enter 1, 2, or 3." << endl;
                    cout << "Enter delivery priority (1-3): ";
                    cin >> priority;
                }
            }

        } // this for loop collects the tracking number, destination city, weight, and priority for the user's specified amount of packages

        PackageSummary summary = calculateSummary(packages, numberOfPackages);

        cout << endl;
        cout << "Package Delivery Summary" << endl;
        cout << endl;

        cout << "Number of Packages: " << numberOfPackages << endl;
        cout << "Total Weight: " << fixed << setprecision(2) << summary.totalWeight << " pounds" << endl;
        cout << "Average Weight: " << fixed << setprecision(2) << summary.averageWeight << " pounds" << endl;
        cout << "Heaviest Package: " << fixed << setprecision(2) << summary.heaviestWeight << " pounds" << endl;
        cout << "Overnight Packages: " << summary.overnightCount << endl;
        // complete summary output from the new summary struct instance

        cout << endl;
        cout << "Original Package List" << endl;
        cout << endl;

        displayAllPackages(packages, numberOfPackages);
        // displays all packages in their original order

        cout << "Packages Sorted by Weight" << endl;
        cout << endl;

        sortPackagesByWeight(packages, numberOfPackages);
        displayAllPackages(packages, numberOfPackages);
        // displays all packages, now sorted by weight

        string enteredTrackingNumber;
        cout << "Enter a tracking number to search for: ";
        cin >> enteredTrackingNumber;
        cout << endl;

        int index = searchByTrackingNumber(packages, numberOfPackages, enteredTrackingNumber);

        if (index != -1) {
            cout << "Package Found:" << endl;
            cout << endl;
            packages[index].displayPackage();
        }
        else {
            cout << "Package not found." << endl;
        } // this section asks the user for a tracking number and searches the package[] array for a match

        repeat = "x"; // stores an invalid character in repeat so the validation loop runs each time

        while (repeat != "y" && repeat != "n" && repeat != "Y" && repeat != "N") {
            cout << endl;
            cout << "Would you like to track another set of packages? (y/n): ";
            cin >> repeat;
            
            if (repeat != "y" && repeat != "n" && repeat != "Y" && repeat != "N") {
                cout << "Invalid choice! Please enter y or n." << endl;
            }
        } // continues repeating until y or n is entered

    } while (repeat == "y" || repeat == "Y"); // this do-while loop repeats only if the user enters 'y' or 'Y' for yes


    cout << endl;
    cout << "Goodbye!" << endl;

    return 0;
}

bool isValidWeight(double weight) {  // returns true if weight>0, false if weight<=0
    return weight > 0;
}

bool isValidPriority (int priority) { // returns true if the priority was entered as 1, 2, or 3
    if (priority == 1 || priority == 2 || priority == 3) {
        return true;
    }
    else {
        return false;
    }
}

PackageSummary calculateSummary(const Package packages[], int numberUsed) { // creates a new struct instance called summary, which stores total weight, average weight, heaviest weight, and overnight count
    PackageSummary summary;
    summary.totalWeight = 0;
    summary.averageWeight = 0;
    summary.heaviestWeight = 0;
    summary.overnightCount = 0;
    // initializing new struct
    
    for (int i = 0; i < numberUsed; i++) {
        summary.totalWeight = summary.totalWeight + packages[i].getWeight();
        // adds new package weight to total each loop

        if (packages[i].getWeight() > summary.heaviestWeight) {
            summary.heaviestWeight = packages[i].getWeight();
        } // if the current weight is heavier than the heaviest weight, that becomes the new heaviest weight

        if (packages[i].getPriority() == 3) {
            summary.overnightCount = summary.overnightCount + 1;
        } // if the priority is overnight (3), adds 1 to overnightCount
    }

    summary.averageWeight = summary.totalWeight / numberUsed; // calculating average

    return summary;
}

void sortPackagesByWeight (Package packages[], int numberUsed) { // orders every value in the array packages[] by the weight of each package
    for (int i = 0; i < numberUsed-1; i++) {
        int smallestPackage = i; // assumes current package is the lightest weight
        for (int j = i+1; j < numberUsed; j++) {
            if (packages[j].getWeight() < packages[smallestPackage].getWeight()) {
                smallestPackage = j; // stores index of new lightest package
            }
        }
        Package temp = packages[i];
        packages[i] = packages[smallestPackage];
        packages[smallestPackage] = temp;
        // swaps current package with the lightest remaining package
    }
}

int searchByTrackingNumber (const Package packages[], int numberUsed, string trackingNumber) {
    for (int i = 0; i < numberUsed; i++) { // loops through each package
        if (packages[i].getTrackingNumber() == trackingNumber) {
            return i; // returns the index i, in packages[i], if the tracking number is found
        }
    }
    return -1; // returns -1 if no match is found
}

void displayAllPackages (const Package packages[], int numberUsed) { // loops through each package in the array packages[] and uses the displayPackage() member function to list them
    for (int i = 0; i < numberUsed; i++) {
        packages[i].displayPackage();
        cout << endl;
    }
}