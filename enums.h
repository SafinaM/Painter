#pragma once

enum Orientation: uint32_t {
	First_0    = 0,
	Second_90  = 1,
	Third_180  = 2,
	Fourth_270 = 3
};

enum Direction: uint32_t {
	Left  = 0,
	Right = 1,
	Down  = 2,
	Up    = 3,
};

enum BackgroundColor: int {
	BC_DEFAULT    =-1,
	BC_BLACK      = 0,
	BC_BLUE       = 1,
	BC_GREEN      = 2,
	BC_LIGHT_BLUE = 3,
	BC_RED        = 4,
	BC_MAGENTA    = 5,
	BC_YELLOW     = 6,
	BC_GRAY       = 7
};

enum TextColor: int {
	TC_DEFAULT         =-1,
	TC_BLACK           = 0,
	TC_BLUE            = 1,
	TC_GREEN           = 2,
	TC_LIGHT_BLUE      = 3,
	TC_RED             = 4,
	TC_MAGENTA         = 5,
	TC_YELLOW          = 6,
	TC_GRAY            = 7,
	TC_BLACK_BOLD      = 8,
	TC_BLUE_BOLD       = 9,
	TC_GREEN_BOLD      = 10,
	TC_LIGHT_BLUE_BOLD = 11,
	TC_RED_BOLD        = 12,
	TC_MAGENTA_BOLD    = 13,
	TC_YELLOW_BOLD     = 14,
	TC_GRAY_BOLD       = 15
};
