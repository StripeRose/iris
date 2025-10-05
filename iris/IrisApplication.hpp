#pragma once

#include <Atrium_AtriumApplication.hpp>
#include <Atrium_RenderTexture.hpp>
#include <Atrium_WindowManagement.hpp>

#if IS_IMGUI_ENABLED
#include <DearImGui.hpp>
#endif

class IrisApplication : public Atrium::AtriumApplication
{
public:
	bool HandleStartup() override;
	void HandleFrameLogic(Atrium::FrameGraphicsContext& aFrameContext) override;
	void HandleShutdown() override;

private:
	std::shared_ptr<Atrium::Window> myWindow;
	std::shared_ptr<Atrium::RenderTexture> myWindowTarget;

	#if IS_IMGUI_ENABLED
	void HandleGUI();
	std::unique_ptr<Atrium::Extension::DearImGuiContext> myImGuiContext;
	#endif
};