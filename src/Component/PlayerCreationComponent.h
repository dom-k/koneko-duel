#include "Component.h"
#include "../Player.h"

#ifndef KONEKO_DUEL_PLAYERCREATIONCOMPONENT_H
#define KONEKO_DUEL_PLAYERCREATIONCOMPONENT_H


class PlayerCreationComponent : Component {
public:
    Player createNewPlayer(Player player);

};


#endif //KONEKO_DUEL_PLAYERCREATIONCOMPONENT_H
