#include "IrisApplication.hpp"

bool IrisApplication::HandleStartup()
{
	// Todo: Create window.
	// Todo: Create render-target for window.

	return false;
}

void IrisApplication::HandleFrameLogic()
{
	
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