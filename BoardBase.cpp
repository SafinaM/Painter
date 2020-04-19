#include "BoardBase.h"

#include <assert.h>

BoardBase::BoardBase(uint32_t width, uint32_t height) :
	m_widthBoard(width),
	m_heightBoard(height),
	buffer(m_heightBoard, std::vector<uint8_t>(m_widthBoard, 0)) {
	
	checking();
}

BoardBase::BoardBase(
	uint32_t width,
	uint32_t height,
	const std::vector<std::vector<uint8_t>>& buf) :
	m_widthBoard(width),
	m_heightBoard(height),
	buffer(buf) {
	
	checking();
}
void BoardBase::debugPrint() const {
	for (uint8_t i = 0; i < m_heightBoard; ++i) {
		for (uint8_t j = 0; j < m_widthBoard; ++j) {
			std::cout << +buffer[i][j];
		}
		std::cout << std::endl;
	}
}

// for debug
void BoardBase::setLine(uint32_t numY, uint32_t value) {
	for (uint32_t j = 0; j < m_widthBoard; ++j) {
		buffer[numY][j] = value;
	}
}
void BoardBase::setPoint(uint32_t x, uint32_t y, uint32_t value) {
	buffer[y][x] = value;
}

void BoardBase::checking() {
	assert(m_heightBoard > 0);
	assert(m_widthBoard > 0);
	assert(!buffer.empty());
	assert(!buffer[0].empty());
	assert(m_heightBoard == buffer.size());
	assert(m_widthBoard == buffer[0].size());
}

bool BoardBase::allowMove(Direction direction, const Figure &figure) const {
	const auto& points = figure.getPoints();
	int xOffset = figure.getXOffset();
	int yOffset = figure.getYOffset();
	
	if (direction == Direction::Right) {
		++xOffset;
	} else if (direction == Direction::Left) {
		--xOffset;
	} else if (direction == Direction::Down) {
		++yOffset;
	} else if (direction == Direction::Up) {
		--yOffset;
	} else {
		std::cerr << "User error: unsupported direction type." << std::endl;
	}
	
	if (isCrossedFigureWithWalls(points, xOffset, yOffset))
		return false;
	
	return !isCrossedFigureWithBuffer(points, xOffset, yOffset);
}

void BoardBase::clear() {
	for (uint8_t i = 0; i < m_heightBoard; ++i) {
		for (uint8_t j = 0; j < m_widthBoard; ++j) {
			buffer[i][j] = 0;
		}
		std::cout << std::endl;
	}
}

bool BoardBase::isCrossedFigureWithBuffer(
	const std::vector<std::vector<uint8_t>> &points,
	int xOffset,
	int yOffset) const {
	for (auto i = 0; i < points.size(); ++i) {
		for (auto j = 0; j < points[0].size(); ++j) {
			// if buffer elements points are busy we cannot do this action
			if (points[i][j] && buffer[i + yOffset][j + xOffset]) {
				return true;
			}
		}
	}
	return false;
}

bool BoardBase::isCrossedFigureWithWalls(
	const std::vector<std::vector<uint8_t>> &points,
	int xOffset,
	int yOffset) const {
	
	for (auto i = 0; i < points.size(); ++i) {
		for (auto j = 0; j < points[0].size(); ++j) {
			if (!points[i][j])
				continue;
			if ((j + xOffset >= m_widthBoard) ||
				(j + xOffset < 0) ||
				(i + yOffset >= m_heightBoard)) {
				return true;
			}
		}
	}
	return false;
}

uint32_t BoardBase::getWidth() const noexcept {
	return  m_widthBoard;
}

uint32_t BoardBase::getHeight() const noexcept {
	return  m_heightBoard;
}
