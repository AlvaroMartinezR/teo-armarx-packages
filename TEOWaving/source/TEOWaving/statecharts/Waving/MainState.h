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
 * @package    TEOWaving::Waving
 * @author     AlvaroMartinezR ( 100317213 at alumnos dot uc3m dot es )
 * @date       2018
 * @copyright  http://www.gnu.org/licenses/gpl-2.0.txt
 *             GNU General Public License
 */

#ifndef _ARMARX_XMLUSERCODE_TEOWaving_Waving_MainState_H
#define _ARMARX_XMLUSERCODE_TEOWaving_Waving_MainState_H

#include <TEOWaving/statecharts/Waving/MainState.generated.h>

namespace armarx
{
    namespace Waving
    {
        class MainState :
            public MainStateGeneratedBase < MainState >
        {
        public:
            MainState(const XMLStateConstructorParams& stateData):
                XMLStateTemplate < MainState > (stateData), MainStateGeneratedBase < MainState > (stateData)
            {
            }

            // inherited from StateBase
            void onEnter();
            void run();
            void onBreak();
            void onExit();

            // static functions for AbstractFactory Method
            static XMLStateFactoryBasePtr CreateInstance(XMLStateConstructorParams stateData);
            static SubClassRegistry Registry;

            // DO NOT INSERT ANY CLASS MEMBERS,
            // use stateparameters instead,
            // if classmember are neccessary nonetheless, reset them in onEnter
        };
    }
}

#endif
