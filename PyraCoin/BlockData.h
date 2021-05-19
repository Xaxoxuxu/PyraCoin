#pragma once
#include <string>
#include <sstream>

using std::string;

class BlockData
{
private:
    string sender;
    string receiver;
    double transactionAmount;

public:

    BlockData(string sender, string receiver, double transactionAmount);

    string GetSender() const { return sender; }
    string GetReceiver() const { return receiver; }
    double GetTransactionAmount() const { return transactionAmount; }

    friend std::ostream& operator<<(std::ostream& out, const BlockData& blockData);
};