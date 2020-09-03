/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>

int main()
{
   
    SYS_disableInts();

    VDP_drawText("Tile map example", 0,0);

    VDP_setPalette(PAL1,level.palette->data);

     //screen size in tiles
    const u16 screen_w_tiles=VDP_getScreenWidth()/8;
    const u16 screen_h_tiles=VDP_getScreenHeight()/8;

    const u16 w=level.w/8;
    const u16 h=level.h/8;

    const u16 vramIdx=TILE_USERINDEX;

    VDP_loadBMPTileData(level.image,vramIdx,w,h,w);

    for (u16 i=0;i<4;++i)
    {
        VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,vramIdx),0+i*w,screen_h_tiles-h,w,h);
    }    

    SYS_enableInts();

    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
