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

enum struct Action: uint32_t {
	Move = 0,
	Shoot,
	ChooseDirection
};

enum struct OpponentMode: uint32_t {
	Random = 0,
	User,
	ChooseDirection,
};