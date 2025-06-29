// Filter "DMX512/Sources"

#include "DMXFakeSource.hpp"

#include <Atrium_GUI.hpp>

Atrium::Range<DMXUniverse> DMXFakeSource::GetUniverses() const
{
    return Atrium::Range<DMXUniverse>(0, 1);
}

DMXValue DMXFakeSource::GetValue(DMXUniverse aUniverse, DMXChannel aChannel)
{
    aUniverse; aChannel;
    return DMXValue(0);
}

void DMXFakeSource::HandleGUI()
{
    ImGui::Text("Test");
}
