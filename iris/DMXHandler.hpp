// Filter "DMX512"

#include "DMXBasics.hpp"
#include "DMXSource.hpp"

#include <memory>
#include <vector>

/**
 * @brief Handles everything related to a particular setup of DMX universes.
 */
class DMXHandler
{
public:
	void AddSource(std::unique_ptr<DMXSource>&& aSource);

	void HandleGUI();
	void HandleGUI_MenuItems();

private:
	std::vector<std::unique_ptr<DMXSource>> myDataSources;

	bool myDisplayDataSourceSettings = false;
};