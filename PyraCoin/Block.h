#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Sha256.h"
#include "Transaction.h"

using std::string;
using std::time_t;
using std::to_string;

/**
 * \brief TODO: Pass by ref when possibles
 */
class Block
{
private:
    const time_t timestamp;
    std::vector<Transaction> transactions;
    const string previousHash;
    uint64_t nonce;
    string hash;

public:
    Block(time_t timestamp, std::vector<Transaction> transactions, string previousHash);

    string GetHash() const { return hash; }
    string GetPreviousHash() const { return previousHash; }
    std::vector<Transaction> GetTransactions() const { return transactions; }

    string CalculateHash() const;
    void MineBlock(const uint32_t difficulty);
    friend std::ostream& operator<< (std::ostream& out, const Block& block);
};