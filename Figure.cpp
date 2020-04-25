#include <iostream>
#include <cassert>
#include <rlutil.h>
#include "Figure.h"

Figure::Figure(Orientation orientation): m_orientation(orientation){}

void Figure::setOrientationTypeAndDirection(Orientation orientation) {
	m_orientation = orientation;
	switch (orientation) {
		case Orientation::First_0:
			m_direction = Direction::Up;
			break;
		case Orientation::Third_180:
			m_direction = Direction::Down;
			break;
		case Orientation::Fourth_270:
			m_direction = Direction::Left;
			break;
		case Orientation::Second_90:
			m_direction = Direction::Right;
			break;
		default:
			break;
	}
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

std::vector<std::vector<uint8_t>> Figure::getPoints() const {
	assert(points.size() != 0);
	return points;
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

Orientation Figure::getOrientation() const noexcept {
	return m_orientation;
}

Direction Figure::getDirection() const noexcept {
	return m_direction;
}

bool Figure::areCrossedFigures(const Figure& figure1, const Figure& figure2) {
	
	const auto& points1 = figure1.getPoints();
	const auto& points2 = figure2.getPoints();
	
	int xOffset1 = figure1.getXOffset();
	int yOffset1 = figure1.getYOffset();
	
	int xOffset2 = figure2.getXOffset();
	int yOffset2 = figure2.getYOffset();
	
	for (auto i = 0; i < points1.size(); ++i) {
		for (auto j = 0; j < points1[0].size(); ++j) {
			// if buffer elements points are busy we cannot do this action
			if (points1[i + xOffset1][j + yOffset1] && points2[i + yOffset2][j + xOffset2]) {
				return true;
			}
		}
	}
	return false;
}