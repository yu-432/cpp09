/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:57:46 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/15 21:47:11 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <map>

class BitcoinExchange {
 public:
  BitcoinExchange();
  ~BitcoinExchange();

  bool executeBtc(const std::string& txtPath);

 private:
  BitcoinExchange(const BitcoinExchange& src);
  BitcoinExchange& operator=(const BitcoinExchange& src);

  bool loadCsvAndInsert();
  std::pair<std::string, double> validateCsvLine(const std::string& line);
  bool insertCsv(const std::string& date, float value);

  bool loadTxt(const std::string& txtPath);
  bool validateTxtLine(const std::string& date, float value);
  void printInfo(const std::string& date, float value);

  std::map<std::string, float> _map;
};