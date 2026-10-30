#include <iostream>
#include <string>
#include "circular_DLL.h"

int main() {

    DoubleList<std::string>* playlist = nullptr;
    DoubleList<std::string>* currTrack = nullptr;
    std::string title;
    int choice = 0;

    do{
        std::cout << "1 - Play All\n";
        std::cout << "2 - Next Song\n";
        std::cout << "3 - Previous Song\n";
        std::cout << "4 - Add Song\n";
        std::cout << "5 - Remove Song\n";
        std::cout << "6 - Delete Playlist\n";

        std::cout << "0 - Exit\n";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
            case 1:
                cdllTraversal(playlist);
                break;

            case 2:
                next(&currTrack);
                break;

            case 3:
                previous(&currTrack);
                break;

            case 4:
                std::cout << "Enter song title you want to add"<<std::endl;
                std::getline(std::cin, title);
                cdllInsertEnd(title, &playlist);
                if (currTrack == nullptr) {
                    currTrack = playlist;
                }
                std::cout << title <<" has been added"<<std::endl;
                break;

            case 5:
                if (playlist == nullptr) {
                    std::cout << "EMPTY PLAYLIST"<<std::endl;
                    break;

                }
                std::cout << "Enter song title to remove: ";
                std::getline(std::cin, title);
                cdllDeleteNode(title, &playlist);
                std::cout << title <<" has been removed"<<std::endl;

                if (playlist == nullptr) {
                    currTrack = nullptr;
                }
                break;

            case 6:
                std::cout << "DELETING PLAYLIST"<<std::endl;
                cdllDeleteList(&playlist);
                currTrack = nullptr;
                break;

            case 0:
                std::cout << "Exiting..."<<std::endl;
                break;

            default:
                std::cout << "INVALID CHOICE"<<std::endl;
                break;
        }

    } while(choice != 0);


return 0;

}
