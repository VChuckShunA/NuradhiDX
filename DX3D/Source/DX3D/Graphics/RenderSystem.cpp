#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicLogUtils.h>
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

}

dx3d::RenderSystem::~RenderSystem()
{
}
