#pragma once
#include <string>
#include <sstream>

using std::string;

/**
 * \brief TODO: Pass by ref when possibles
 */
class Transaction
{
private:
    string fromAddress;
    string toAddress;
    double amount;

public:
    Transaction(string fromAddress, string toAddress, double amount);

    string GetFromAddress() const { return fromAddress; }
    string GetToAddress() const { return toAddress; }
    double GetTransactionAmount() const { return amount; }

    friend std::ostream& operator<<(std::ostream& out, const Transaction& transaction);
};