#pragma once
#include<DX3D/Core/Base.h>
#include<DX3D/Core/Core.h>
#include<DX3D/Core/Logger.h>
namespace dx3d{
class Game: public Base
{
public:
	explicit Game(const GameDesc& gameDesc);
	virtual ~Game() override;

	virtual void run() final; //final: cannot be overriden or inherited

private:
	std::unique_ptr<Logger> m_loggerPtr{};
	std::unique_ptr<GraphicsEngine> m_graphicsEngine{};
	std::unique_ptr<Window> m_display{};
	bool m_isRunning { true };
};
}