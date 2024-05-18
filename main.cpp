#include <stdlib.h>
#include <stdio.h>
#include "App.h"

int main()
{
    App app(nullptr);
    app.makeTree();
    return app.startApp();
}
