#include <iostream>
#include <cassert>
#include <rlutil.h>
#include "Figure.h"

void Figure::setOrientationType(Orientation orientation) {
	m_orientation = orientation;
}

std::vector<std::vector<uint8_t>> Figure::getPoints() const {
	assert(points.size() != 0);
	return points;
}

void Figure::move(Direction direction) noexcept {
	if (direction == Direction::Right) {
		++m_offsetX;
	} else if (direction == Direction::Left) {
		--m_offsetX;
	} else if (direction == Direction::Down) {
		++m_offsetY;
	} else if (direction == Direction::Up) {
		--m_offsetY;
	} else {
		std::cerr << "do not have such direction" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Figure::setXY(int x, int y) noexcept {
	m_offsetX = x;
	m_offsetY = y;
}

int Figure::getXOffset() const noexcept {
	return m_offsetX;
}

int Figure::getYOffset() const noexcept {
	return m_offsetY;
}

uint32_t Figure::getColor() const noexcept {
	return m_Color;
}

void Figure::setColor(const uint32_t color) noexcept {
	m_Color = color;
}
