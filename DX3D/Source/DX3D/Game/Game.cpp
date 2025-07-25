#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Core/Logger.h>
dx3d::Game::Game(const GameDesc& gameDesc):
	Base({ *std::make_unique<Logger>(gameDesc.logLevel).release() }),
	m_loggerPtr(&m_logger) 
{
	m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_logger});
	m_display = std::make_unique<Display>(DisplayDesc{ {m_logger, gameDesc.windowSize}, m_graphicsEngine->getRenderSystem() });

	DX3DLogInfo("Game initialized.");
}

dx3d::Game::~Game() 
{
	DX3DLogInfo("Game deallocation started.");
}