#include "Spreadsheet.h"

#include <format>
#include <stdexcept>
#include <utility>

Spreadsheet::Spreadsheet(size_t width, size_t height) : m_width{width}, m_height{height} {
	m_cells = new SpreadsheetCell*[m_width];
	for (size_t i = 0; i < width; ++i)
	{
		m_cells[i] = new SpreadsheetCell[m_height];
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : Spreadsheet{src.m_width, src.m_height} {
	for (size_t row = 0; row < m_width; ++row)
	{
		for (size_t col = 0; col < m_height; ++col)
		{
			m_cells[row][col] = src.m_cells[row][col];
		}
	}
}

Spreadsheet::~Spreadsheet() {
	for (size_t i = 0; i < m_width; ++i)
	{
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;
}

void Spreadsheet::SetCellAt(size_t x, size_t y, const SpreadsheetCell& cell) {
	VerifyCoordinates(x, y);
	m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::GetCellAt(size_t x, size_t y) const {
	VerifyCoordinates(x, y);
	return m_cells[x][y];
}

// Spreadsheet& Spreadsheet::operator=(const Spreadsheet& right) {
// 	// Check for self-assignment
// 	if (this == &right)
// 		return *this;
// 	
// 	// Free the old memory
// 	for (size_t row = 0; row < m_width; ++row)
// 	{
// 		delete[] m_cells[row];
// 	}
// 	delete[] m_cells;
// 	m_cells = nullptr;
// 	
// 	// Allocate new memory
// 	m_width = right.m_width;
// 	m_height = right.m_height;
// 	m_cells = new SpreadsheetCell*[m_width];
// 	for (size_t row = 0; row < m_width; ++row)
// 	{
// 		m_cells[row] = new SpreadsheetCell[m_height];
// 	}
// 	
// 	// Copy the data
// 	for (size_t row = 0; row < m_width; ++row)
// 	{
// 		for (size_t col = 0; col < m_height; ++col)
// 		{
// 			m_cells[row][col] = right.m_cells[row][col];
// 		}
// 	}
// 	return *this;
// }

// all or nothing implementation (copy & swap idiom)
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& right) {
	Spreadsheet temp{right};
	Swap(temp);
	return *this;
}

void Spreadsheet::Swap(Spreadsheet& other) noexcept {
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

bool Spreadsheet::InRange(size_t value, size_t upper) {
	return value < upper;
}

void Spreadsheet::VerifyCoordinates(size_t x, size_t y) const {
	if (!InRange(x, m_width))
	{
		throw std::out_of_range{std::format("x ({}) must be less than width ({}).", x, m_width)};
	}
	if (!InRange(y, m_height))
	{
		throw std::out_of_range{std::format("y ({}) must be less than height ({}).", y, m_height)};
	}
}

void Swap(Spreadsheet& first, Spreadsheet& second) noexcept {
	first.Swap(second);
}
