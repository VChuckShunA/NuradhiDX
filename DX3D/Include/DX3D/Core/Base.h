#pragma once
#include <DX3D/Core/Common.h>
namespace dx3d {

	class Base
	{
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();
		virtual Logger& getLogger() const noexcept final;
		

	protected:
		//Rule of 5
		//share this behaviour across all the classes in our egnien
		Base(const Base&)=delete;  // no copy‑constructor
		Base(Base&&)=delete; // no move‑constructor
		Base& operator = (const Base&)=delete; // no copy‑assignment
		Base& operator =(Base&&)=delete; // no move‑assignment

	protected:
		Logger& m_logger;
	};

}
