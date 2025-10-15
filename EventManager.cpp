#include "EventManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

EventManager::EventManager() {
    loadFromFile();
}

void EventManager::loadFromFile() {
    ifstream fin(filename);
    if (!fin) return;

    events.clear();
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        int id;
        string name, date, venue;
        string idStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, date, ',');
        getline(ss, venue, ',');

        id = stoi(idStr);
        events.push_back(Event(id, name, date, venue));
    }
    fin.close();
}

void EventManager::saveToFile() {
    ofstream fout(filename);
    for (auto &e : events)
        fout << e.toString() << endl;
    fout.close();
}

void EventManager::addEvent() {
    int id;
    string name, date, venue;
    cout << "Enter Event ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Event Name: ";
    getline(cin, name);
    cout << "Enter Date: ";
    getline(cin, date);
    cout << "Enter Venue: ";
    getline(cin, venue);

    events.push_back(Event(id, name, date, venue));
    saveToFile();
    cout << "✅ Event added and saved successfully!\n";
}

void EventManager::displayAllEvents() const {
    if (events.empty()) {
        cout << "No events found.\n";
        return;
    }
    for (auto &e : events)
        cout << "ID: " << e.getId() << ", Name: " << e.getName()
             << ", Date: " << e.getDate() << ", Venue: " << e.getVenue() << endl;
}

void EventManager::searchEvent() const {
    int id;
    cout << "Enter Event ID to search: ";
    cin >> id;

    for (auto &e : events) {
        if (e.getId() == id) {
            cout << "Found -> " << e.getName() << " | " << e.getDate()
                 << " | " << e.getVenue() << endl;
            return;
        }
    }
    cout << "❌ Event not found.\n";
}

void EventManager::updateEvent() {
    int id;
    cout << "Enter Event ID to update: ";
    cin >> id;
    cin.ignore();

    for (auto &e : events) {
        if (e.getId() == id) {
            string name, date, venue;
            cout << "Enter New Name: ";
            getline(cin, name);
            cout << "Enter New Date: ";
            getline(cin, date);
            cout << "Enter New Venue: ";
            getline(cin, venue);

            e.setName(name);
            e.setDate(date);
            e.setVenue(venue);

            saveToFile();
            cout << "✅ Event updated and saved.\n";
            return;
        }
    }
    cout << "❌ Event not found.\n";
}

void EventManager::deleteEvent() {
    int id;
    cout << "Enter Event ID to delete: ";
    cin >> id;

    for (auto it = events.begin(); it != events.end(); ++it) {
        if (it->getId() == id) {
            events.erase(it);
            saveToFile();
            cout << "🗑️ Event deleted and file updated.\n";
            return;
        }
    }
    cout << "❌ Event not found.\n";
}
