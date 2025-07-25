#include <DX3D/All.h>
int main() {
	try {
		dx3d::Game game({ {1280,720},dx3d::Logger::LogLevel::Info });

		game.run();

	}
	catch(const std::runtime_error&) //specific(runtime) exception
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)//generic/abstract exception
	{
		return EXIT_FAILURE;
	}
	catch (...) //all other exceptions
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}