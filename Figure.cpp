#include <iostream>
#include <cassert>
#include <rlutil.h>
#include "Figure.h"

Figure::Figure(Orientation orientation): m_orientation(orientation) {}

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

// yes it is awfull!!!
bool Figure::areCrossedFigures(const Figure& figure1, const Figure& figure2) noexcept {
	
	const auto& points1 = figure1.getPoints();
	const auto& points2 = figure2.getPoints();
	
	int xOffset1 = figure1.getXOffset();
	int yOffset1 = figure1.getYOffset();
	
	int xOffset2 = figure2.getXOffset();
	int yOffset2 = figure2.getYOffset();
	
	for (auto y1 = 0; y1 < points1.size(); ++y1) {
		for (auto x1 = 0; x1 < points1[0].size(); ++x1) {
			for (auto y2 = 0; y2 < points2.size(); ++y2) {
				for (auto x2 = 0; x2 < points2[0].size(); ++x2) {
					if (points1[y1][x1] &&
						points2[y2][x2] &&
						y1 + yOffset1 == y2 + yOffset2 &&
						std::abs(x1 + xOffset1 - (x2 + xOffset2)) <= 1)
							return true;
				}
			}
		}
	}
	return false;
}