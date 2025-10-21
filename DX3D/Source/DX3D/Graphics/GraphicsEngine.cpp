#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc):Base(desc.base)
{
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext=device.createDeviceContext();
}



dx3d::GraphicsEngine::~GraphicsEngine()
{
}

GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice() const noexcept
{
	return *m_graphicsDevice;
}

void dx3d::GraphicsEngine::render()
{
	auto& context = m_deviceContext;
	context.
}
