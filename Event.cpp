#include "Event.h"
#include <sstream>

Event::Event(int id, string name, string date, string venue)
    : id(id), name(name), date(date), venue(venue) {}

int Event::getId() const { return id; }
string Event::getName() const { return name; }
string Event::getDate() const { return date; }
string Event::getVenue() const { return venue; }

void Event::setName(string n) { name = n; }
void Event::setDate(string d) { date = d; }
void Event::setVenue(string v) { venue = v; }

string Event::toString() const {
    stringstream ss;
    ss << id << "," << name << "," << date << "," << venue;
    return ss.str();
}
