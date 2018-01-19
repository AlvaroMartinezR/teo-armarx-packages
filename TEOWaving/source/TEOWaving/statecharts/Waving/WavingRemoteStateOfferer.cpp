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
 * @package    TEOWaving::Waving::WavingRemoteStateOfferer
 * @author     AlvaroMartinezR ( 100317213 at alumnos dot uc3m dot es )
 * @date       2018
 * @copyright  http://www.gnu.org/licenses/gpl-2.0.txt
 *             GNU General Public License
 */

#include "WavingRemoteStateOfferer.h"

using namespace armarx;
using namespace Waving;

// DO NOT EDIT NEXT LINE
WavingRemoteStateOfferer::SubClassRegistry WavingRemoteStateOfferer::Registry(WavingRemoteStateOfferer::GetName(), &WavingRemoteStateOfferer::CreateInstance);



WavingRemoteStateOfferer::WavingRemoteStateOfferer(StatechartGroupXmlReaderPtr reader) :
    XMLRemoteStateOfferer < WavingStatechartContext > (reader)
{
}

void WavingRemoteStateOfferer::onInitXMLRemoteStateOfferer()
{

}

void WavingRemoteStateOfferer::onConnectXMLRemoteStateOfferer()
{

}

void WavingRemoteStateOfferer::onExitXMLRemoteStateOfferer()
{

}

// DO NOT EDIT NEXT FUNCTION
std::string WavingRemoteStateOfferer::GetName()
{
    return "WavingRemoteStateOfferer";
}

// DO NOT EDIT NEXT FUNCTION
XMLStateOffererFactoryBasePtr WavingRemoteStateOfferer::CreateInstance(StatechartGroupXmlReaderPtr reader)
{
    return XMLStateOffererFactoryBasePtr(new WavingRemoteStateOfferer(reader));
}



