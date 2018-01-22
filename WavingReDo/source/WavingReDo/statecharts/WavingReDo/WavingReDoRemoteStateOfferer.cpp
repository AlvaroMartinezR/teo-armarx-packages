/*
 * This file is part of ArmarX.
 *
 * ArmarX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ArmarX is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * @package    WavingReDo::WavingReDo::WavingReDoRemoteStateOfferer
 * @author     AlvaroMartinezR ( 100317213 at alumnos dot uc3m dot es )
 * @date       2018
 * @copyright  http://www.gnu.org/licenses/gpl-2.0.txt
 *             GNU General Public License
 */

#include "WavingReDoRemoteStateOfferer.h"

using namespace armarx;
using namespace WavingReDo;

// DO NOT EDIT NEXT LINE
WavingReDoRemoteStateOfferer::SubClassRegistry WavingReDoRemoteStateOfferer::Registry(WavingReDoRemoteStateOfferer::GetName(), &WavingReDoRemoteStateOfferer::CreateInstance);



WavingReDoRemoteStateOfferer::WavingReDoRemoteStateOfferer(StatechartGroupXmlReaderPtr reader) :
    XMLRemoteStateOfferer < WavingReDoStatechartContext > (reader)
{
}

void WavingReDoRemoteStateOfferer::onInitXMLRemoteStateOfferer()
{

}

void WavingReDoRemoteStateOfferer::onConnectXMLRemoteStateOfferer()
{

}

void WavingReDoRemoteStateOfferer::onExitXMLRemoteStateOfferer()
{

}

// DO NOT EDIT NEXT FUNCTION
std::string WavingReDoRemoteStateOfferer::GetName()
{
    return "WavingReDoRemoteStateOfferer";
}

// DO NOT EDIT NEXT FUNCTION
XMLStateOffererFactoryBasePtr WavingReDoRemoteStateOfferer::CreateInstance(StatechartGroupXmlReaderPtr reader)
{
    return XMLStateOffererFactoryBasePtr(new WavingReDoRemoteStateOfferer(reader));
}



