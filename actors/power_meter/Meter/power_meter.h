/**************************************************************************************************
				Power Meter Image File 

**************************************************************************************************/

/* 
 * This is a custom version of power_meter.h from the iQue source code that works with meter.sou.
 * The way the textures are numbered is a bit odd. 1 is the full meter, and with every other number
 * the meter gets emptier, so the lower the health, the higher the number of the texture.
 */

ALIGNED8 static const u8 power_meter1_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_full.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter1_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_full.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter2_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_7.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter2_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_7.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter3_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_6.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter3_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_6.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter4_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_5.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter4_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_5.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter5_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_4.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter5_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_4.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter6_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_3.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter6_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_3.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter7_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_2.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter7_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_2.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter8_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_1.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter8_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_1.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter9_000_txt[] = {
#include "actors/power_meter/power_meter_left_side_empty.rgba16.inc.c"
};

ALIGNED8 static const u8 power_meter9_001_txt[] = {
#include "actors/power_meter/power_meter_right_side_empty.rgba16.inc.c"
};
