#pragma once

// int main function that creates Hazel application for us
// entry point is inside engine, not the Sandbox
#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{

	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized log!");
	int a = 17;
	HZ_INFO("Hello! var={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif