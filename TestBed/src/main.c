/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>

int main()
{
   /** VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_loadTileSet(tile1.tileset,2,DMA);
  //  VDP_loadTileSet(light.tileset,3,DMA);
    
    VDP_setPalette(PAL1, eye.palette->data);
    VDP_setPalette(PAL2, tile1.palette->data);
 //   VDP_setPalette(PAL3, light.palette->data);
    VDP_setTileMapXY(BG_B,1,2,2);
      
    //TILE_ATTR_FULL(pal,prio,flipV,flipH,index)
    VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),4,4);
    VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL2,0,FALSE,FALSE,2),5,5);
    
    
    VDP_drawText("Test Sega Genesis OK!", 10,16);

    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),12,12,18,19);
   
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL2,1,FALSE,FALSE,2),0,20,10,1);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL2,1,FALSE,FALSE,2),6,16,10,1);

   // VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL3,0,FALSE,FALSE,3),2,6,2,3);
   // VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL3,0,FALSE,FALSE,3),12,13,2,3);
   // VDP_fillTileMapRectInc(BG_B,TILE_ATTR_FULL(PAL3,0,FALSE,FALSE,3),7,13,2,3);
    VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,3),23,0,4,3);
       */

    SYS_disableInts();

    VDP_loadTileSet(finestra.tileset,10,DMA);    
    VDP_setPalette(PAL1,palme.palette->data);
    VDP_drawImageEx(BG_B, &eye, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), 2, 2, 0,DMA);
    //VDP_loadTileData(eye.tileset->tiles,100,16,DMA);
    VDP_drawImageEx(BG_B, &eye, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), 2, 2, 0,DMA);  
    //VDP_drawImageEx(BG_B, &moon, TILE_ATTR_FULL(PAL1, 0, 0, 0, 30), 2, 2, 0,DMA);  
    VDP_loadBMPTileData(palme.image,30,palme.w/8,palme.h/8,palme.w/8);
    VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,20),20,10,2,3);

    VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,30),0,21,palme.w/8,palme.h/8);

   SYS_enableInts();

    for (int i=0;i<6;i++)
    {         
        VDP_fillTileMapRectInc(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,30),0+i*2,2+i*2,palme.w/8,palme.h/8);         
    }

    VDP_setTileMapXY(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,39),5,5);
    VDP_setTileMapXY(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,39),6,5);
    VDP_setTileMapXY(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,39),7,5);


    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
