#include "BettingOptions.h"
BettingOptions::BettingOptions()
{
    m_options[0] = std::make_pair(false, "check");
    m_options[1] = std::make_pair(false, "open");
    m_options[2] = std::make_pair(false, "fold");
    m_options[3] = std::make_pair(false, "raise");
    m_options.at(0).first = true;
    m_options.at(1).first = true;
}
void BettingOptions::reset()
{
    m_options.at(0).first = true;
    m_options.at(1).first = true;
    m_options.at(2).first = false;
    m_options.at(3).first = false;
}
void BettingOptions::open()
{
    m_options.at(1).first = false;
    m_options.at(2).first = true;
    m_options.at(3).first = true;
}
bool BettingOptions::isValidOption(unsigned int opt)
{
    if (m_options.find(opt) != m_options.end())
    {
        return m_options[opt].first;
    }
    return false;
}

std::vector<unsigned> BettingOptions::getValidOptions() const
{
    std::vector<unsigned> result{};
    for (auto &opt : m_options)
    {
        if (opt.second.first)
        {
            result.emplace_back(opt.first);
        }
    }
    return result;
}
std::ostream &operator<<(std::ostream &os, const BettingOptions &opt)
{
    os << "Options: ";
    for (auto &entry : opt.m_options)
    {
        if (entry.second.first)
        {
            os << "[" << entry.first << "] " << entry.second.second << " ";
        }
    }
    return os;
}
