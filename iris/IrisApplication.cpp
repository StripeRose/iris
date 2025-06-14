#include "IrisApplication.hpp"

#include <chrono>

bool IrisApplication::HandleStartup()
{
	myWindow = std::make_unique<Atrium::Window>();
	myWindow->SetTitle("Iris Application Window");
	myWindow->SetSize(Atrium::Size(640, 480));

	myWindow->OnClosed.Connect(this, [&](auto) { Exit(); });

	myTarget = std::make_unique<Atrium::RenderTarget>(*myWindow);

	myWindow->Show();

	return true;
}

void IrisApplication::HandleFrameLogic()
{
	static auto startPoint = std::chrono::high_resolution_clock::now();
	const auto millisecondsElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startPoint).count();

	const float secondsElapsed = static_cast<float>(millisecondsElapsed) / 1000.f;

	Atrium::Graphics::ClearColor(
		*myTarget,
		Atrium::Lerp(
			Atrium::Color::Predefined::CornflowerBlue,
			Atrium::Color::Predefined::Orange,
			(Atrium::Sine(secondsElapsed) + 1.f) * 0.5f
		)
	);
}

void IrisApplication::HandleShutdown()
{
	
}

//std::unique_ptr<Atrium::EngineInstance> ourEngineInstance;
//
//std::shared_ptr<Atrium::RenderTexture> ourWindowTarget;
//
//void HandleStart()
//{
//	Atrium::WindowManager::CreationParameters windowParameters;
//	windowParameters.Title = "Test window";
//	windowParameters.Size = { 640, 480 };
//
//	std::shared_ptr<Atrium::Window> window = ourEngineInstance->GetWindowManager().NewWindow(windowParameters);
//	ourWindowTarget = ourEngineInstance->GetGraphicsAPI().GetResourceManager().CreateRenderTextureForWindow(*window);
//	window->Closed.Connect(nullptr, [](Atrium::Window&) { ourWindowTarget.reset(); });
//}
//
//void HandleLoop()
//{
//	if (ourEngineInstance->GetWindowManager().GetWindows().empty())
//	{
//		ourEngineInstance->Stop();
//		return;
//	}
//
//	Atrium::FrameGraphicsContext& frameContext = ourEngineInstance->GetGraphicsAPI().GetCurrentFrameContext();
//	if (ourWindowTarget)
//	{
//		frameContext.ClearColor(ourWindowTarget, Atrium::Color::Predefined::CornflowerBlue);
//	}
//}
//
//void HandleExit()
//{
//	ourWindowTarget.reset();
//}