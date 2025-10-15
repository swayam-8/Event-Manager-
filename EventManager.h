#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"
#include <vector>
using namespace std;

class EventManager {
private:
    vector<Event> events;
    const string filename = "events.txt";

    void loadFromFile();
    void saveToFile();

public:
    EventManager();

    void addEvent();
    void displayAllEvents() const;
    void searchEvent() const;
    void updateEvent();
    void deleteEvent();
};

#endif
