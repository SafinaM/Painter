#pragma once
#include "PainterImpl.h"
#include <memory>

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

struct Painter {
	~Painter() = default;
	Painter() : m_painter(new PainterImpl) {}

	
	void printColoredText(
		const std::string &text,
		uint32_t x,
		uint32_t y,
		uint32_t color,
		uint32_t textColor);
	bool isScreenSizeChanged() noexcept;
	bool isSizeOk();
	void setXY(uint32_t x, uint32_t y);
	uint32_t getWinWidth();
	uint32_t getWinHeight();
	void drawRectangle(
		uint32_t x,
		uint32_t y,
		uint32_t width,
		uint32_t height,
		char ch = ' ',
		uint32_t color = 0,
		uint32_t textColor = 0) const;
	void drawPoint(uint32_t x, uint32_t y, char ch, uint32_t color, uint32_t textColor = 0) const;
	void clearScreen() const noexcept ;
	void hideCursor() const noexcept;
	void showCursor() const;
	void setScreenSize();
	void drawHead(const std::string &head) noexcept;
	uint32_t xOffsetBoard = 0;
	uint32_t yOffsetBoard = 0;
	
private:
	std::unique_ptr<PainterImpl> m_painter;
};

