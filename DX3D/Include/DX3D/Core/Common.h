#pragma once
#include<DX3D/Core/Core.h>
#include<DX3D/Core/Logger.h>
#include <DX3D/Math/Rect.h>
namespace dx3d
{

	struct BaseDesc {
		Logger& logger;
	};


	struct WindowDesc {
		BaseDesc base;
	};


	struct DisplayDesc
	{
		WindowDesc window;
		Rect size{};
	};


	struct GraphicsEngineDesc {
		BaseDesc base;
	};


	struct RenderSystemDesc {
		BaseDesc base;
	};

	struct SwapChainDesc
	{
		void* winHandle{};
		Rect winSize{};
	};

	enum class ShaderType
	{
		VertexShader = 0,
		PixelShader
	};

	struct ShaderCompileDesc
	{
		const char* shaderSourceName{};
		const void* shaderSourceCode{};
		size_t shaderSourceCodeSize{};
		const char* shaderEntryPoint{};
		ShaderType shaderType{};
	};

	struct ShaderBinaryData
	{
		const void* data{};
		size_t dataSize{};
	};

	/*struct GraphicsPipelineStateDesc
	{
		const ShaderBinary& vs;
		const ShaderBinary& ps;
	};

	struct VertexBufferDesc
	{
		const void* vertexList{};
		ui32 vertexListSize{};
		ui32 vertexSize{};
	};*/
	struct GameDesc {
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};

}