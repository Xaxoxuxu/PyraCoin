#include "BlockChain.h"

BlockChain::BlockChain(const uint32_t difficulty) : difficulty(difficulty)
{
	chain.emplace_back(CreateGenesisBlock());
}

Block BlockChain::CreateGenesisBlock()
{
	return Block(1621411042, { "Genesis", "Genesis", 0.0 }, "Genesis");
}

Block BlockChain::GetLastBlock() const
{
	return chain.back();
}

string BlockChain::GetLastBlockHash() const
{
	return GetLastBlock().GetHash();
}

time_t BlockChain::GetCurrentTimeStamp() const
{
	const auto clockNow = std::chrono::system_clock::now();
	const auto currentTimeStamp = std::chrono::duration_cast<std::chrono::seconds>(
		clockNow.time_since_epoch()).count();

	return currentTimeStamp;
}

void BlockChain::CraftNewBlock(const Transaction& transaction)
{
	Block newBlock{ GetCurrentTimeStamp(), transaction, GetLastBlockHash() };
	newBlock.MineBlock(this->difficulty);

	chain.emplace_back(newBlock);
}

bool BlockChain::IsChainValid()
{
	// block 0 is genesis
	for (size_t i = 1; i < chain.size(); i++) 
	{
		const Block currentBlock = chain[i];
		const Block previousBlock = chain[i - 1];

        if (currentBlock.GetHash() != currentBlock.CalculateHash())
        {
			return false;
        }

        if (currentBlock.GetPreviousHash() != previousBlock.CalculateHash())
        {
			return false;
        }
	}

	return true;
}

std::ostream& operator<<(std::ostream& out, const BlockChain& blockChain)
{
	out << "BlockChain (difficulty = " << blockChain.difficulty << "):\n\n";
	for (const auto &block : blockChain.chain)
	{
		out << block << "\n\n";
	}
	out << '\n';

	return out;
}