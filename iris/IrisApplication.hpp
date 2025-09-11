#pragma once

#include <Atrium_AtriumApplication.hpp>
#include <Atrium_GUIHandler.hpp>

class IrisApplication : public Atrium::AtriumApplication
{
public:
	bool HandleStartup() override;
	void HandleFrameLogic(Atrium::FrameGraphicsContext& aFrameContext) override;
	void HandleShutdown() override;

private:
	void HandleGUI();

	std::shared_ptr<Atrium::Window> myWindow;
	std::shared_ptr<Atrium::RenderTexture> myWindowTarget;
	std::unique_ptr<Atrium::GUIHandler> myImGuiHandler;
};