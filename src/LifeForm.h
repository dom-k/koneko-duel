#ifndef KONEKO_DUEL_LIFEFORM_H
#define KONEKO_DUEL_LIFEFORM_H


class LifeForm {

protected:
    int healthPoints;
    int attackPoints;
    int level;
    std::string name;

public:

    void takeDamage(int damage);

    int getHealthPoints();

    void setHealthPoints(int healthPoints);

    int getAttackpoints();

    void setAttackPoints(int attackPoints);

    void setLevel(int Level);

    int getLevel();

    void setName(std::string name);

    std::string getName();
};


#endif //KONEKO_DUEL_LIFEFORM_H
