Event Management System in C++

A console-based Event Management System implemented in C++. It allows users to add, view, search, update, and delete events with details like name, date, time, and venue. All data is persistently stored in a text file (events.txt) so information is retained between program runs.

Features

Add Event – Enter new events with full details.

Display Events – View all stored events.

Search Event – Find an event by name.

Update Event – Modify existing event details.

Delete Event – Remove events from the system.

Persistent Storage – Automatically saves and loads events.

User-Friendly Menu – Simple console-based navigation.

How It Works

Events are stored in a vector of Event objects.

Searching uses a linear search:

if (events[i].eventName == name)
    return i;


Changes (add, update, delete) are immediately saved to the file.

On startup, the program loads all events from the file.

How to Run
g++ main.cpp -o EventApp
./EventApp       # Linux/Mac
EventApp.exe     # Windows

Technologies

C++ Standard Library: vector, string, fstream, sstream

File Handling for persistent storage
