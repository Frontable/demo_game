





#include <iostream>
#include "ECS.h"



int main(int argc, char* argv[]) {
    
    
    EntityManager em;
    ComponentManager cm;

    Entity e1 = em.createEntity();
    cm.registerComponent<Position>();

    cm.addComponent(e1, Position{1,1});

    return 0;
}
