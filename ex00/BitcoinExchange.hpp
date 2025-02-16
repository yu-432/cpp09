/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:57:46 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/16 21:13:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
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
  std::pair<std::string, double> validateCsvLine(const std::string& line) const;

  bool loadTxtAndPrint(const std::string& txtPath);
  bool validateTxtLine(const std::string& date, double value) const;
  double getPrice(const std::string& dateStr);

  std::map<std::string, double> _map;
};