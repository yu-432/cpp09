/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:10:27 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/16 22:28:57 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::string strtrim(std::string& str) {
  std::size_t first = str.find_first_not_of(' ');
  if (first == std::string::npos) return "";
  std::size_t end = str.find_last_not_of(' ');
  return str.substr(first, end - first + 1);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { (void)src; };

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
  (void)src;
  return *this;
};

bool BitcoinExchange::executeBtc(const std::string& txtPath) {
  if (loadCsvAndInsert()) {
    std::cerr << "Failed load csv file" << std::endl;
    return EXIT_FAILURE;
  }
  loadTxtAndPrint(txtPath);
  return EXIT_SUCCESS;
}

bool BitcoinExchange::loadCsvAndInsert() {
  std::ifstream ifs("data.csv");
  if (!ifs) {
    std::cerr << "Error: could not open file." << std::endl;
    return EXIT_FAILURE;
  }

  std::string line;
  std::getline(ifs, line);
  if (line != "date,exchange_rate") {
    std::cerr << "Error: invalid file format." << std::endl;
    return EXIT_FAILURE;
  }
  while (std::getline(ifs, line)) {
    std::pair<std::string, double> data = validateCsvLine(line);
    _map.insert(data);
  }
  return EXIT_SUCCESS;
}

std::pair<std::string, double> BitcoinExchange::validateCsvLine(
    const std::string& line) const {
  if (line.length() < 12 || line[4] != '-' || line[7] != '-' ||
      !line.find(',') || line[10] != ',' ||
      (line.find(',') != line.rfind(','))) {
    return std::make_pair("", -1);
  }

  char* endptr = NULL;
  std::string price_str = line.substr(11);
  double price = strtod(price_str.c_str(), &endptr);
  return std::make_pair(line.substr(0, 10), price);
}

bool BitcoinExchange::loadTxtAndPrint(const std::string& txtPath) {
  std::ifstream ifs(txtPath.c_str());
  if (!ifs) {
    std::cerr << "Error: could not open file.";
    return EXIT_FAILURE;
  }

  std::string line;
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    std::stringstream ss(line);
    std::string dateStr, ratioStr;

    std::getline(ss, dateStr, '|');
    std::getline(ss, ratioStr);
    dateStr = strtrim(dateStr);
    ratioStr = strtrim(ratioStr);

    char* endptr = nullptr;
    double ratio = strtod(ratioStr.c_str(), &endptr);
    if (!validateTxtLine(dateStr, ratio)) continue;
    double price = getPrice(dateStr);
    if (price < 0) {
      std::cout << "Error: price not found." << std::endl;
      continue;
    }
    std::cout << dateStr << " => " << ratio << " = " << price * ratio
              << std::endl;
  }
  return EXIT_SUCCESS;
}

bool BitcoinExchange::validateTxtLine(const std::string& dateStr,
                                      double value) const {
  int year, month, day;
  char delimiter;
  std::stringstream ss(dateStr);
  ss >> year >> delimiter >> month >> delimiter >> day;
  if (year < 2009 || 2022 < year || month < 1 || 12 < month || day < 1 ||
      31 < day) {
    std::cout << "Error: bad input => " << dateStr << std::endl;
    return false;
  }
  if (value < 1) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  }
  if (1000 < value) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}

double BitcoinExchange::getPrice(const std::string& dateStr) {
  if ((_map.begin()++)->first > dateStr) return -1;
  std::map<std::string, double>::iterator it = _map.find(dateStr);
  if (it == _map.end()) {
    it = _map.lower_bound(dateStr);
    it--;
  }
  return it->second;
}
