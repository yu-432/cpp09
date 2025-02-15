/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:10:27 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/15 22:01:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::executeBtc(const std::string& txtPath) {
  if (loadCsvAndInsert()) {
    std::cerr << "Failed load csv file" << std::endl;
    return EXIT_FAILURE;
  }

  std::map<std::string, float>::iterator it = _map.find("2022-03-29");
  std::cout << it->second << std::endl;

  (void)txtPath;
  return EXIT_SUCCESS;
}

bool BitcoinExchange::loadCsvAndInsert() {
  std::ifstream ifs("data.csv");
  if (!ifs) {
    std::cerr << "Error: could not open file.";
    return EXIT_FAILURE;
  }

  std::string line;
  while (std::getline(ifs, line)) {
    if (line == "date,exchange_rate")
      continue;

    std::pair<std::string, double> data = validateCsvLine(line);
    // std::cout << "day = " << data.first << ", price = " << data.second << std::endl;
    _map.insert(data);
    // break;
  }
  return EXIT_SUCCESS;
}

std::pair<std::string, double> BitcoinExchange::validateCsvLine(const std::string& line) {
  // std::cout << "line = " << line << std::endl;
  if (line.length() < 12 || line[4] != '-' || line[7] != '-' ||
      !line.find(',') || line[10] != ',' ||
      (line.find(',') != line.rfind(','))) {
    return std::make_pair("", -1);  // invalid
  }
  
  //値チェック
  
  char *endptr = NULL;
  // std::cout << strtod(line.substr(0, 4).c_str(), &endptr) << endptr << std::endl;//2009-2022 year
  // std::cout << strtod(line.substr(5, 2).c_str(), &endptr) << endptr << std::endl;//1-12 month
  // std::cout << strtod(line.substr(8, 2).c_str(), &endptr) << endptr << std::endl;//1-31 day
  // std::cout << strtod(line.substr(11, line.length() - 10).c_str(), &endptr) << endptr << std::endl;//price

  std::string price_str = line.substr(11);
  double price = strtod(price_str.c_str(), &endptr);
  std::cout << price_str << ", " << price << std::endl;
  return std::make_pair(line.substr(0, 10), price);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { (void)src; };

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
  (void)src;
  return *this;
};
