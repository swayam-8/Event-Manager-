# Event-Manager-System
Event Management System in C++

This is a simple console-based Event Management System implemented in C++. It allows users to add, display, search, update, and delete events. All event data is persistently stored in a text file so that the information is retained between program runs.

Features

Add Event – Users can add new events with details like name, date, time, and venue.

Display All Events – Shows a list of all stored events with full details.

Search Event – Search for a specific event by name. Returns the event details if found.

Update Event – Update the details of an existing event.

Delete Event – Remove an event from the system.

Persistent Storage – All events are automatically saved to events.txt and loaded when the program starts.

User-Friendly Menu – Simple console menu for easy navigation.

How It Works

The program stores all events in a vector of Event objects.

Searching for an event uses a linear search:

if (events[i].eventName == name)
    return i;


This compares the name of each stored event with the user input and returns the index if a match is found.

The system automatically saves changes (add, update, delete) to a text file to maintain persistence.

When the program starts, it loads all events from the file into memory.

Classes

Event

Stores eventName, date, time, venue.

Provides a display() function to print details.

EventManager

Manages a vector of Event objects.

Handles all operations: add, display, search, update, delete.

Handles file I/O for persistence.

How to Run
g++ main.cpp -o EventApp
./EventApp   # on Linux/Mac
EventApp.exe # on Windows

Example
===== EVENT MANAGER MENU =====
1. Add Event
2. Display All Events
3. Search for an Event
4. Update an Event
5. Delete an Event
6. Exit
==============================
Enter choice: 3
Enter Event Name to Search: Birthday Party

--- Event Details ---
Name : Birthday Party
Date : 20-10-2025
Time : 6:00 PM
Venue: My House
---------------------

Technologies

C++ Standard Library: vector, string, fstream, sstream.

File handling for persistent storage.
