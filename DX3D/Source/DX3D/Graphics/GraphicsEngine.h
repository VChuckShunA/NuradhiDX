#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>
namespace dx3d
{
	//final keyword prevents further derivation
	class GraphicsEngine final: public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		~GraphicsEngine();

		GraphicsDevice& getGraphicsDevice() const noexcept;

		void render();
	private:
		std::shared_ptr<GraphicsDevice> m_graphicsDevice{};

		DeviceContextPtr m_deviceContext{};
	};
}