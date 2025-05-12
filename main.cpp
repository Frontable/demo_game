








#include "App.h"

int main(int argc, char* argv[]) {
    
    App app("Test", 100, 100, 1000, 600);
    app.initialize();
    app.run();

    app.shutDown();

   
   
    return 0;
}

