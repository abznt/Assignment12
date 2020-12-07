#ifndef ASSIGNMENT12_BETTINGOPTIONS_H
#define ASSIGNMENT12_BETTINGOPTIONS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

class BettingOptions
{
  private:
    std::map<unsigned, std::pair<bool, std::string>> m_options;

  public:
    BettingOptions();
    void reset();
    void open();
    bool isValidOption(unsigned opt);
    [[nodiscard]] std::vector<unsigned> getValidOptions() const;
    friend std::ostream& operator<<(std::ostream& os, const BettingOptions& opt);
};

#endif // ASSIGNMENT12_BETTINGOPTIONS_H
