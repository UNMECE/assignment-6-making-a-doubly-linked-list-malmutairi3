#include "coordinate.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void add_coordinate(Coordinate *list_end, float x, float y) {
    if (!list_end) return;   

    Coordinate *new_coord = new Coordinate{x, y, list_end->coord_id + 1, nullptr, list_end};
    list_end->next = new_coord;
}

void forward_display(Coordinate *list_beginning) {
    Coordinate *current = list_beginning;
    while (current) {
        cout << "ID: " << current->coord_id << " (" << current->x << ", " << current->y << ")\n";
        current = current->next;
    }
}

void backward_display(Coordinate *list_end) {
    Coordinate *current = list_end;
    while (current) {
        cout << "ID: " << current->coord_id << " (" << current->x << ", " << current->y << ")\n";
        current = current->previous;
    }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate *current = list_beginning;

    while (current) {
        if (current->coord_id == coord_id_to_delete) {
            if (current->previous) current->previous->next = current->next;
            if (current->next) current->next->previous = current->previous;
            delete current;
            return;
        }
        current = current->next;
    }
}

int list_length(Coordinate *list_beginning) {
    int count = 0;
    Coordinate *current = list_beginning;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    if (!list_beginning) return;
    Coordinate *closest = list_beginning;
    float min_distance = sqrt(pow(x - list_beginning->x, 2) + pow(y - list_beginning->y, 2));
    
    Coordinate *current = list_beginning->next;
    while (current) {
        float distance = sqrt(pow(x - current->x, 2) + pow(y - current->y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest = current;
        }
        current = current->next;
    }
    cout << "Closest point: ID " ;
    cout << closest->coord_id;
    cout  << " (" << closest-> x ;
    cout << ", " ;
    cout << closest-> y ;
    cout << ") Distance: ";
    cout << min_distance << endl;
}
