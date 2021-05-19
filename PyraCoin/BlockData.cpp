#include "BlockData.h"

BlockData::BlockData(string sender, string receiver, double transactionAmount) :
sender(sender), receiver(receiver), transactionAmount(transactionAmount)
{}

std::ostream& operator<<(std::ostream& out, const BlockData& blockData)
{
    out << "BlockData{sender=" << blockData.sender
        << ";receiver=" << blockData.receiver
        << ";transactionAmount=" << blockData.transactionAmount << "}";

    return out;
}