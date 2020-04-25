#pragma once

enum struct Orientation: int {
	First_0 = 0,
	Second_90,
	Third_180,
	Fourth_270
};

enum struct Direction: int {
	Left = 0,
	Right,
	Down,
	Up
};

enum struct Action: uint32_t {
	Move = 0,
	ChooseDirection,
	Shoot
};

enum struct FigureType: uint8_t {
	FT_TYPE1 = 0,
	FT_TYPE2,
	FT_TYPE3
};