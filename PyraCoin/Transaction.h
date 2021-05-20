#pragma once
#include <string>
#include <sstream>

using std::string;

class Transaction
{
private:
    string fromAddress;
    string toAddress;
    double amount;

public:
    Transaction(string fromAddress, string toAddress, double amount);

    string GetSender() const { return fromAddress; }
    string GetReceiver() const { return toAddress; }
    double GetTransactionAmount() const { return amount; }

    friend std::ostream& operator<<(std::ostream& out, const Transaction& transaction);
};