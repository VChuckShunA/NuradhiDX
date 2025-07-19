#pragma once
#include <DX3D/Window/Window.h>

namespace dx3d
{
	class Display final : public Window
	{
	public:
		Display();

		SwapChain& getSwapChain() noexcept;
	private:
		SwapChainPtr m_swapChain{};
	};
}
