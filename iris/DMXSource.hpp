// Filter "DMX512"

#pragma once

#include "DMXBasics.hpp"

#include <rose-common/Range.hpp>

/**
 * @brief An individual source of DMX data which maps to a particular set of Universes, each containing up to 512 7 bit channels(0-255).
 */
class DMXSource
{
public:
	virtual ~DMXSource() = default;

	/**
	 * @brief Get the range of universes this source handles.
	 * @return The range of universes
	 */
	virtual Atrium::Range<DMXUniverse> GetUniverses() const = 0;

	/**
	 * @brief Get the value of a specific universe and channel.
	 * @param aUniverse The universe to get.
	 * @param aChannel The channel to get.
	 * @return The current value of the requested channel.
	 */
	virtual DMXValue GetValue(DMXUniverse aUniverse, DMXChannel aChannel) = 0;

	/**
	 * @brief Get the value of a specific universe and channel, relative to the first universe this source handles.
	 * @param aUniverse The universe to get.
	 * @param aChannel The channel to get.
	 * @return The current value of the requested channel.
	 */
	DMXValue GetValueRelative(DMXUniverse aRelativeUniverse, DMXChannel aChannel) { return GetValue((*GetUniverses().begin()) + aRelativeUniverse, aChannel); };

	/**
	 * @brief Draw the status and editable controls for this Universe.
	 */
	virtual void HandleGUI() = 0;
};