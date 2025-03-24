/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:57:46 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 01:38:53 by yooshima         ###   ########.fr       */
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
    static bool executeBtc(const std::string& txtPath);

  private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& src);
    ~BitcoinExchange();

    static bool loadCsvAndInsert();
    static std::pair<std::string, double> validateCsvLine(const std::string& line);
    static bool loadTxtAndPrint(const std::string& txtPath);
    static bool validateTxtLine(const std::string& date, double value);
    static double getPrice(const std::string& dateStr);

    static std::map<std::string, double> _map;
};