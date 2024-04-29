#include "SpreadsheetCell.h"

#include <charconv>

SpreadsheetCell::SpreadsheetCell(double initialValue = 0) : m_value{initialValue} {}

SpreadsheetCell::SpreadsheetCell(std::string_view initalValue) {
	m_value = StringToDouble(initalValue);
}

double SpreadsheetCell::GetValue() const {
	return m_value;
}

void SpreadsheetCell::SetValue(double value) {
	m_value = value;
}

std::string SpreadsheetCell::GetString() const {
	return DoubleToString(m_value);
}

void SpreadsheetCell::SetString(std::string_view value) {
	m_value = StringToDouble(value);
}

std::string SpreadsheetCell::DoubleToString(double value) {
	return std::to_string(value);
}

double SpreadsheetCell::StringToDouble(std::string_view value) {
	double number{0};
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}
