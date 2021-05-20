#include "Transaction.h"

Transaction::Transaction(string fromAddress, string toAddress, double amount) :
fromAddress(fromAddress), toAddress(toAddress), amount(amount)
{}

std::ostream& operator<<(std::ostream& out, const Transaction& transaction)
{
    out << "Transactions{fromAddress=" << transaction.fromAddress
        << ";toAddress=" << transaction.toAddress
        << ";amount=" << transaction.amount << "}";

    return out;
}