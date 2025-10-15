#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//  Event Class 
class Event {
public:
    string eventName, date, time, venue;

    Event(string n, string d, string t, string v)
        : eventName(n), date(d), time(t), venue(v) {}

    Event() {} // default constructor (for reading from file)

    void display() {
        cout << "\n--- Event Details ---\n";
        cout << "Name : " << eventName << "\n";
        cout << "Date : " << date << "\n";
        cout << "Time : " << time << "\n";
        cout << "Venue: " << venue << "\n";
        cout << "---------------------\n";
    }
};

// EventManager Class 
class EventManager {
private:
    vector<Event> events;
    const string filename = "events.txt";

    int findEvent(string name) {
        for (int i = 0; i < events.size(); ++i)
            if (events[i].eventName == name)
                return i;
        return -1;
    }

public:
    EventManager() { loadFromFile(); }  // Load when program starts
    ~EventManager() { saveToFile(); }   // Save when program ends

    void addEvent() {
        string name, date, time, venue;
        cin.ignore();
        cout << "Event Name: ";
        getline(cin, name);
        cout << "Date (DD-MM-YYYY): ";
        getline(cin, date);
        cout << "Time (e.g. 6:00 PM): ";
        getline(cin, time);
        cout << "Venue: ";
        getline(cin, venue);

        events.push_back(Event(name, date, time, venue));
        cout << "\n✅ Event added successfully!\n";

        saveToFile(); // Auto-save after adding
    }

    void displayAllEvents() {
        if (events.empty()) {
            cout << "\nNo events available.\n";
            return;
        }
        cout << "\n--- All Events ---\n";
        for (int i = 0; i < events.size(); ++i) {
            cout << "\nEvent #" << i + 1;
            events[i].display();
        }
    }

    void searchEvent() {
        if (events.empty()) {
            cout << "\nNo events to search.\n";
            return;
        }
        cin.ignore();
        string name;
        cout << "Enter Event Name to Search: ";
        getline(cin, name);

        int idx = findEvent(name);
        if (idx != -1)
            events[idx].display();
        else
            cout << "\n❌ Event not found.\n";
    }

    void deleteEvent() {
        if (events.empty()) {
            cout << "\nNo events to delete.\n";
            return;
        }
        cin.ignore();
        string name;
        cout << "Enter Event Name to Delete: ";
        getline(cin, name);

        int idx = findEvent(name);
        if (idx != -1) {
            events.erase(events.begin() + idx);
            cout << "\n🗑️ Event deleted successfully!\n";
            saveToFile();
        } else {
            cout << "\n❌ Event not found.\n";
        }
    }

    void updateEvent() {
        if (events.empty()) {
            cout << "\nNo events to update.\n";
            return;
        }
        cin.ignore();
        string name;
        cout << "Enter Event Name to Update: ";
        getline(cin, name);

        int idx = findEvent(name);
        if (idx == -1) {
            cout << "\n❌ Event not found.\n";
            return;
        }

        string newName, newDate, newTime, newVenue;
        cout << "New Event Name: ";
        getline(cin, newName);
        cout << "New Date: ";
        getline(cin, newDate);
        cout << "New Time: ";
        getline(cin, newTime);
        cout << "New Venue: ";
        getline(cin, newVenue);

        events[idx] = Event(newName, newDate, newTime, newVenue);
        cout << "\n✅ Event updated successfully!\n";
        saveToFile();
    }

    //  File Handling 
    void saveToFile() {
        ofstream fout(filename);
        for (auto &e : events)
            fout << e.eventName << "," << e.date << "," << e.time << "," << e.venue << "\n";
        fout.close();
    }

    void loadFromFile() {
        events.clear();
        ifstream fin(filename);
        if (!fin)
            return; // file not found yet, skip

        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string name, date, time, venue;
            getline(ss, name, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, venue, ',');
            if (!name.empty())
                events.push_back(Event(name, date, time, venue));
        }
        fin.close();
    }
};

//  Menu
void showMenu() {
    cout << "\n===== EVENT MANAGER MENU =====\n";
    cout << "1. Add Event\n";
    cout << "2. Display All Events\n";
    cout << "3. Search for an Event\n";
    cout << "4. Update an Event\n";
    cout << "5. Delete an Event\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
    cout << "Enter choice: ";
}

//  Main 
int main() {
    EventManager manager;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: manager.addEvent(); break;
            case 2: manager.displayAllEvents(); break;
            case 3: manager.searchEvent(); break;
            case 4: manager.updateEvent(); break;
            case 5: manager.deleteEvent(); break;
            case 6: cout << "\n💾 Saving and exiting...\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
        system("pause");
    } while (choice != 6);

    return 0;
}


// need to run this command to run the code 
// g++ main.cpp -o EventApp
//  .\EventApp

