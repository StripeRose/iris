// Filter "DMX512"

#include "DMXFakeSource.hpp"
#include "DMXHandler.hpp"

#include <Atrium_GUI.hpp>

void DMXHandler::AddSource(std::unique_ptr<DMXSource>&& aSource)
{
	myDataSources.push_back(std::move(aSource));
}

void DMXHandler::HandleGUI_MenuItems()
{
	if (ImGui::MenuItem("Sources"))
		myDisplayDataSourceSettings = true;
}

void DMXHandler::HandleGUI()
{
	if (myDisplayDataSourceSettings)
	{
		if (ImGui::Begin("DMX sources", &myDisplayDataSourceSettings))
		{
			ImGui::Text("Sources: %u", myDataSources.size());

			auto sourceToRemove = myDataSources.end();

			for (decltype(myDataSources)::iterator it = myDataSources.begin(); it != myDataSources.end(); it++)
			{
				ImGui::PushID(it->get());

				bool keep = true;
				if (ImGui::CollapsingHeader("Source name - Universe: {0 - 0}", &keep, ImGuiTreeNodeFlags_DefaultOpen))
				{
					ImGui::Indent();
					(*it)->HandleGUI();
					ImGui::Unindent();
				}

				if (!keep)
					sourceToRemove = it;

				ImGui::PopID();
			}

			if (sourceToRemove != myDataSources.end())
				myDataSources.erase(sourceToRemove);

			if (ImGui::BeginCombo("##AddSourceSelector", "Add source.."))
			{
				if (ImGui::Selectable("Fake source"))
					myDataSources.push_back(std::make_unique<DMXFakeSource>());

				ImGui::EndCombo();
			}

		}
		ImGui::End();
	}
}
