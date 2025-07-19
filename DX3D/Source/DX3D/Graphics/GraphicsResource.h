#pragma once
#include <DX3D/Core/Common.h>
#include <DX3D/Core/Base.h>

#include <DX3D/Graphics/GraphicLogUtils.h>
#include <d3d11.h>
#include <wrl.h>

namespace dx3d
{
	struct GraphicsResourceDesc
	{
		BaseDesc base;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};
	class GraphicsResource : public Base
	{
		

		explicit GraphicsResource(const GraphicsResourceDesc& desc) :
			Base(desc.base),
			m_device(desc.device),
			m_factory(desc.factory) {

		}
	protected:
	protected:
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};
}