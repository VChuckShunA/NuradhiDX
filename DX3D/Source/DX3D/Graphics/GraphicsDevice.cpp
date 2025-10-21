#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/GraphicLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>
#include <memory>
using namespace dx3d;

dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc): Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT CreateDeviceFlags{};

#ifndef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEBUG_DEVICE;
#endif // !_DEBUG

	
	DX3DGraphicsLogThrowOnFail(D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_HARDWARE,NULL,CreateDeviceFlags,
		NULL,0, D3D11_SDK_VERSION,
		&m_d3dDevice,&featureLevel, &m_d3dContext),
		"Direct3D11 initialization Failed!");
	
	//check if it supports this interface and retrieve a pointer to it
	DX3DGraphicsLogThrowOnFail(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		"Query Interface failed to retrieve IDXGDI Device.");


	DX3DGraphicsLogThrowOnFail(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"Query Interface failed to retrieve IDXGDI Adapter.");


	DX3DGraphicsLogThrowOnFail(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"Query Interface failed to retrieve IDXGDI Factory.");

}

dx3d::GraphicsDevice::~GraphicsDevice()
{
}

SwapChainPtr dx3d::GraphicsDevice::CreateSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicResourceDesc());
}

DeviceContextPtr dx3d::GraphicsDevice::createDeviceContext()
{
	return std::make_shared<DeviceContext>(getGraphicResourceDesc());
}

GraphicsResourceDesc dx3d::GraphicsDevice::getGraphicResourceDesc() const noexcept
{
	return { {m_logger},shared_from_this(), *m_d3dDevice.Get(),*m_dxgiFactory.Get()};
}
