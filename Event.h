#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {
private:
    int id;
    string name;
    string date;
    string venue;

public:
    Event() {}
    Event(int id, string name, string date, string venue);

    int getId() const;
    string getName() const;
    string getDate() const;
    string getVenue() const;

    void setName(string n);
    void setDate(string d);
    void setVenue(string v);

    string toString() const;
};

#endif
