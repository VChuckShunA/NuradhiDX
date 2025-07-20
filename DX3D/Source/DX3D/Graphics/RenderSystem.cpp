#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>
#include <memory>
using namespace dx3d;

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc): Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT CreateDeviceFlags{};

#ifndef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEBUG_DEVICE;
#endif // !_DEBUG

	
	DX3DGraphicsLogErrorAndThrow(D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_HARDWARE,NULL,CreateDeviceFlags,
		NULL,0, D3D11_SDK_VERSION,
		&m_d3dDevice,&featureLevel, &m_d3dContext),
		"Direct3D11 initialization Failed!");
	
	//check if it supports this interface and retrieve a pointer to it
	DX3DGraphicsLogErrorAndThrow(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		"Query Interface failed to retrieve IDXGDI Device.");


	DX3DGraphicsLogErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"Query Interface failed to retrieve IDXGDI Adapter.");


	DX3DGraphicsLogErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"Query Interface failed to retrieve IDXGDI Factory.");

}

dx3d::RenderSystem::~RenderSystem()
{
}

SwapChainPtr dx3d::RenderSystem::CreateSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicResourceDesc());
}

GraphicsResourceDesc dx3d::RenderSystem::getGraphicResourceDesc() const noexcept
{
	return { {m_logger},shared_from_this(), *m_d3dDevice.Get(),*m_dxgiFactory.Get()};
}
