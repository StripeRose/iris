// Filter "DMX512/Sources"

#pragma once

#include "DMXSource.hpp"

class DMXFakeSource final : public DMXSource
{
public:
	Atrium::Range<DMXUniverse> GetUniverses() const override;

	DMXValue GetValue(DMXUniverse aUniverse, DMXChannel aChannel) override;

	void HandleGUI() override;
};