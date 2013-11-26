/***************************************************************************
    Video Emulation: OutRun Road Rendering Hardware.
    Based on MAME source code.

    Copyright Aaron Giles.
    All rights reserved.
***************************************************************************/

#ifndef HWROAD_HPP
#define HWROAD_HPP

#include "../globals.hpp"

class HWRoad
{
public:
    HWRoad();
    ~HWRoad();

    void init(const uint8_t*);
    void render_background(uint32_t*);
    void render_foreground(uint32_t*);
    void write16(uint32_t adr, const uint16_t data);
    void write16(uint32_t* adr, const uint16_t data);
    void write32(uint32_t* adr, const uint32_t data);
    uint16_t read_road_control();
    void write_road_control(const uint8_t);

private:
    // Internal screen width and height
    uint16_t s16_width, s16_height;

    uint8_t road_control;
    uint16_t color_offset1;
    uint16_t color_offset2;
    uint16_t color_offset3;
    int32_t x_offset;

    static const uint16_t ROAD_RAM_SIZE = 0x1000;
    static const uint16_t ROM_SIZE      = 0x8000;

    // Decoded road graphics
    uint8_t roads[0x40200];

    // Two halves of RAM
    uint16_t ram[ROAD_RAM_SIZE / 2];
    uint16_t ramBuff[ROAD_RAM_SIZE / 2];

    void decode_road(const uint8_t*);
};

extern HWRoad hwroad;

#endif // HWROAD_HPP
