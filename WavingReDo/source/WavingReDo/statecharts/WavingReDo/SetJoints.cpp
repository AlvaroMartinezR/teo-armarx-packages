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

#include "SetJoints.h"

//#include <ArmarXCore/core/time/TimeUtil.h>
//#include <ArmarXCore/observers/variant/DatafieldRef.h>

using namespace armarx;
using namespace WavingReDo;

// DO NOT EDIT NEXT LINE
SetJoints::SubClassRegistry SetJoints::Registry(SetJoints::GetName(), &SetJoints::CreateInstance);



void SetJoints::onEnter()
{
    // put your user code for the enter-point here
    // execution time should be short (<100ms)
    // get the target joint values
    std::map<std::string, float> jointValueMap = in.getJointTargetPose();
    //build conditions for OnPoseReached
    Term poseReachedConditions;
    const float eps = 0.05f; //This will trigger the OnPoseReached event if the actual pose is very close to the specified pose (+/- 0.05).
    for (const auto & jointNameValue : jointValueMap)
    {
        std::string jointNameDatafield = "Armar3KinematicUnitObserver.jointangles." + jointNameValue.first;
        float jointValue = jointNameValue.second;
        Literal jointValueReached(jointNameDatafield, "inrange",
                                  Literal::createParameterList(jointValue - eps, jointValue + eps));
        poseReachedConditions = poseReachedConditions && jointValueReached;
    }
    installConditionForOnPoseReached(poseReachedConditions);

}

void SetJoints::run()
{
    std::map<std::string, float> jointValueMap = in.getJointTargetPose();
    NameControlModeMap positionControlModeMap;
    //sets to position control mode the joints in the map
    for (const auto & jointNameValue : jointValueMap)
    {
        positionControlModeMap[jointNameValue.first] = ePositionControl;
    }
    KinematicUnitInterfacePrx kinUnit = getKinematicUnit();
    //switch to position control
    kinUnit->switchControlMode(positionControlModeMap);
    // set the angles defined by the joint target pose
    kinUnit->setJointAngles(jointValueMap);
}

void SetJoints::onBreak()
{
    //    // put your user code for the breaking point here
    //    // execution time should be short (<100ms)
}

void SetJoints::onExit()
{
    // put your user code for the exit point here
    // execution time should be short (<100ms)
}


// DO NOT EDIT NEXT FUNCTION
XMLStateFactoryBasePtr SetJoints::CreateInstance(XMLStateConstructorParams stateData)
{
    return XMLStateFactoryBasePtr(new SetJoints(stateData));
}

