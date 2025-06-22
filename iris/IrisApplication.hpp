#pragma once

#include <Atrium.hpp>

class IrisApplication : public Atrium::AtriumApplication
{
public:
	bool HandleStartup() override;
	void HandleFrameLogic() override;
	void HandleShutdown() override;

private:
	void HandleGUI();

	std::unique_ptr<Atrium::Window> myWindow;
	std::unique_ptr<Atrium::ImGuiHandler> myImGuiHandler;
};