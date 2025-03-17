#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Argument is missing!!" << endl;
        return 1;
    }
    
    int num_coordinates = atoi(argv[1]);
    if (num_coordinates <= 0) {
        cout << "Please enter positive integer for the number of coordinates.\n";
        return 1;
    }

    srand(time(nullptr));
    Coordinate *list_beginning = nullptr, *list_end = nullptr;
    int id_counter = 0;

    for (int i = 0; i < num_coordinates; ++i) {
        float x = static_cast<float>(rand() % 100);
        float y = static_cast<float>(rand() % 100);
        if (!list_beginning) {
            list_beginning = new Coordinate{x, y, id_counter++, nullptr, nullptr};
            list_end = list_beginning;
        } else {
            add_coordinate(list_end, x, y);
            list_end = list_end->next;   
        }
    }

    cout << "\nForward Display:" << endl;
    forward_display(list_beginning);
    
    cout << "\nBackward Display:" << endl;;
    backward_display(list_end);

    float search_x = 50.0, search_y = 50.0;
    cout << endl;
    cout << "Finding closest coordinate to (";
    cout << search_x << ", ";
    cout << search_y << "):\n";

    closest_to(list_beginning, search_x, search_y);

    int coord_to_delete = 2;
    cout <<endl;
    cout << "Deleting coordinate with ID: " << coord_to_delete << endl;
    
     
    if (list_beginning && list_beginning->coord_id == coord_to_delete) {
        list_beginning = list_beginning->next;
        if (list_beginning) list_beginning->previous = nullptr;
    }

     
    if (list_end && list_end->coord_id == coord_to_delete) {
        list_end = list_end->previous;
        if (list_end) list_end->next = nullptr;
    }

    delete_coordinate(list_beginning, coord_to_delete);
    cout << endl;
    cout << "Updated Forward Display:"<<endl;
    forward_display(list_beginning);

    return 0;
}
