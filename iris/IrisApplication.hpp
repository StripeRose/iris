#pragma once

#include "DMXHandler.hpp"

#include <Atrium_AtriumApplication.hpp>
#include <Atrium_GUIHandler.hpp>

class IrisApplication : public Atrium::AtriumApplication
{
public:
	bool HandleStartup() override;
	void HandleFrameLogic(Atrium::Core::FrameGraphicsContext& aFrameContext) override;
	void HandleShutdown() override;

private:
	void HandleGUI();

	DMXHandler myDMXHandler;

	std::shared_ptr<Atrium::Core::Window> myWindow;
	std::shared_ptr<Atrium::Core::RenderTexture> myWindowTarget;
	std::unique_ptr<Atrium::GUIHandler> myImGuiHandler;
};