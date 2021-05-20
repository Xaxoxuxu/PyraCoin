#include "Block.h"

Block::Block(const time_t timestamp, std::vector<Transaction> transactions, const string previousHash) :
    timestamp(timestamp), transactions(transactions), previousHash(previousHash), nonce(0), hash(CalculateHash())
{}

string Block::CalculateHash() const
{
    SHA256 sha256;
    std::stringstream ss;

    ss << this->timestamp;

    for (const auto& transaction : this->transactions)
    {
        ss << transaction.GetFromAddress() << transaction.GetToAddress() << transaction.GetTransactionAmount();
    }

    ss << this->nonce;

    return sha256(ss.str());
}

void Block::MineBlock(const uint32_t difficulty)
{
    const string difficultyString(difficulty, '0');
    while (this->hash.substr(0, difficulty) != difficultyString)
    {
        this->nonce++;
        this->hash = CalculateHash();
    }
}

std::ostream& operator<<(std::ostream& out, const Block& block)
{
    out << "Block{timestamp=" << block.timestamp
        << ";transactions count=" << block.transactions.size()
        << ";nonce=" << block.nonce << "}"
        << "\n;hash=" << block.GetHash()
        << "\n;previousHash=" << block.GetPreviousHash();

    return out;
}