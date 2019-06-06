#include "PlayerCreationComponent.h"

void PlayerCreationComponent::run(Player* player) {
    int error = 0;
    std::string name;
    std::string confirm;

    do {
        std::cout << "What's the name of your kitten?" << std::endl;
        std::cin >> name;

        std::cout << "So it's " << name << ", am I right? (y / n)" << std::endl;
        std::cin >> confirm;
        
        if (confirm == "y" || confirm == "Y" || confirm == "yes" || confirm == "Yes") {
            player->setName(name);
            error = 1;
        }
    } while (error == 0);
    
}
