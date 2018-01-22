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
 * @package    WavingReDo::WavingReDo
 * @author     AlvaroMartinezR ( 100317213 at alumnos dot uc3m dot es )
 * @date       2018
 * @copyright  http://www.gnu.org/licenses/gpl-2.0.txt
 *             GNU General Public License
 */

#ifndef _ARMARX_XMLUSERCODE_WavingReDo_WavingReDo_REMOTESTATEOFFERER_H
#define _ARMARX_XMLUSERCODE_WavingReDo_WavingReDo_REMOTESTATEOFFERER_H

#include <ArmarXCore/statechart/xmlstates/XMLRemoteStateOfferer.h>
#include "WavingReDoStatechartContext.generated.h"

namespace armarx
{
    namespace WavingReDo
    {
        class WavingReDoRemoteStateOfferer :
            virtual public XMLRemoteStateOfferer < WavingReDoStatechartContext > // Change this statechart context if you need another context (dont forget to change in the constructor as well)
        {
        public:
            WavingReDoRemoteStateOfferer(StatechartGroupXmlReaderPtr reader);

            // inherited from RemoteStateOfferer
            void onInitXMLRemoteStateOfferer();
            void onConnectXMLRemoteStateOfferer();
            void onExitXMLRemoteStateOfferer();

            // static functions for AbstractFactory Method
            static std::string GetName();
            static XMLStateOffererFactoryBasePtr CreateInstance(StatechartGroupXmlReaderPtr reader);
            static SubClassRegistry Registry;


        };
    }
}

#endif
