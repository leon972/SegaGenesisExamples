/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>

int main()
{
    VDP_drawText("Test Sega Genesis OK!", 10,10);
    
    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
