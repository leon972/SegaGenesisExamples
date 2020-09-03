/**
 * Tileset example.
 * Load a single tile and multi tiles from an image.
 * The tiles are displayed on screen.
 **/
#include <genesis.h>
#include <resources.h>

int main()
{    
    //disable interrupts while working with the VDP
    SYS_disableInts();

    VDP_drawText("Tile sets example.", 0,0);

    //screen size in tiles
    const u16 screen_w_tiles=VDP_getScreenWidth()/8;
    const u16 screen_h_tiles=VDP_getScreenHeight()/8;

    // ---- single tile ------

    //current VRAM index for tile loading
    u16 vramIndex=TILE_USERINDEX;
    u16 singleTileIdx=vramIndex;
    
    VDP_loadTileSet(single_tile.tileset,vramIndex,DMA);
    vramIndex+=single_tile.tileset->numTile; //inc by one 

    //set the palette1 from tile palette
    VDP_setPalette(PAL1, single_tile.palette->data);
    VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL1,0,0,0,singleTileIdx),10,10);

    // ----- load 8 tiles -------

    VDP_loadTileSet(tiles.tileset,vramIndex,DMA);
    u16 tilesIdx=vramIndex;
    vramIndex+=tiles.tileset->numTile; //inc by one 

    VDP_setPalette(PAL2,tiles.palette->data);

    for (int i=0;i<tiles.tileset->numTile;++i)
    {
        VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL2,0,0,0,tilesIdx+i),10+i,12);
    }

    for (u16 i=0;i<screen_w_tiles;++i)
    {
        VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL2,0,0,0,tilesIdx+1),i,screen_h_tiles-5);
        VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL2,0,0,0,tilesIdx+3),i,screen_h_tiles-4);
        VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL2,0,0,0,tilesIdx),i,screen_h_tiles-3);
    }

    //restore interrupts
    SYS_enableInts();

    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
