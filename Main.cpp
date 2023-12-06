#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include<cstdlib>

class GameObject{
public:    
    virtual void act(){
        std::cout << "Hej" << std::endl;
    }
    virtual void mightLevelUp(){

    }
};


class Human : public GameObject{
public:
    Human(std::string name):name(name){
    }
    void act() override{
        std::string actions[]={"eats","drinks","burps"};
        int index = rand()%3;
        if(index == 2){
            burpsInARow++;
        }
         else{
            burpsInARow = 0;
         }
         //latest.push_back(actions[index]);
        std::cout << name << " " << actions[index] << std::endl;
    }   
    void mightLevelUp() override{
        if(burpsInARow >= 3) {
            level++;
    }
    }
    std::string name;
private:
    int level = 1;
    unsigned char burpsInARow = 0;
    //std::vector<std::string> latest;
};


class Fly: public GameObject{
public:
    Fly(){

    }
    void act() override{
        std::string actions[]={"flies","lands in the food", "surrar"};
        int index = rand()%3;
        std::cout << "Flugan" << " " << actions[index] << std::endl;
    }   
private:
};



int main(){
    srand((unsigned) time(NULL));
    Human *stefan = new Human("Stefan");
    Human *kerstin = new Human("Kerstin");
    Human *oliver= new Human("Oliver");
    
    
    Fly *fly = new Fly();

    std::vector<GameObject *> gameObjects;
    gameObjects.push_back(stefan);
    gameObjects.push_back(kerstin);
    gameObjects.push_back(oliver);
    gameObjects.push_back(fly);

    //gameObjects[0]->name = "Kalle";

    while(1){
        for(GameObject *gameObj : gameObjects){
            gameObj->act();
            gameObj->mightLevelUp();
        }
    }
}
