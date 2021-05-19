#include "BlockChain.h"

BlockChain::BlockChain()
{
	chain.emplace_back(CreateGenesisBlock());
}

Block BlockChain::CreateGenesisBlock()
{
	return Block(0, 1621411042, { "Genesis", "Genesis", 0.0 }, "Genesis");
}

Block BlockChain::GetLastBlock() const
{
	return chain.back();
}

string BlockChain::GetLastBlockHash() const
{
	return GetLastBlock().GetHash();
}

uint64_t BlockChain::GetNextIndex() const
{
	return GetLastBlock().GetIndex() + 1;
}

time_t BlockChain::GetCurrentTimeStamp() const
{
	const auto clockNow = std::chrono::system_clock::now();
	const auto currentTimeStamp = std::chrono::duration_cast<std::chrono::seconds>(
		clockNow.time_since_epoch()).count();

	return currentTimeStamp;
}

void BlockChain::CraftNewBlock(const BlockData& newBlockData)
{
	Block newBlock{ GetNextIndex(), GetCurrentTimeStamp(), newBlockData, GetLastBlockHash() };

	chain.emplace_back(newBlock);
}

std::ostream& operator<<(std::ostream& out, const BlockChain& blockChain)
{
	out << "BlockChain:\n\n";
	for (const auto &block : blockChain.chain)
	{
		out << block << "\n\n";
	}
	out << '\n';

	return out;
}