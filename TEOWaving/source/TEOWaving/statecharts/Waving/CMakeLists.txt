armarx_component_set_name("Waving")

#find_package(MyLib QUIET)
#armarx_build_if(MyLib_FOUND "MyLib not available")
#
# all include_directories must be guarded by if(Xyz_FOUND)
# for multiple libraries write: if(X_FOUND AND Y_FOUND)....
#if(MyLib_FOUND)
#    include_directories(${MyLib_INCLUDE_DIRS})
#endif()

find_package(Eigen3 QUIET)
find_package(Simox QUIET)

#
armarx_build_if(Eigen3_FOUND "Eigen3 not available")
armarx_build_if(Simox_FOUND "Simox-VirtualRobot not available")

#
if (Eigen3_FOUND AND Simox_FOUND)
    include_directories(
        ${Eigen3_INCLUDE_DIR}
        ${Simox_INCLUDE_DIRS}
    )
endif()

set(COMPONENT_LIBS
ArmarXCoreInterfaces RobotAPIInterfaces RobotAPICore ${Simox_LIBRARIES}
    ArmarXCore ArmarXCoreStatechart ArmarXCoreObservers)

# Sources

set(SOURCES
WavingRemoteStateOfferer.cpp
)

set(HEADERS
WavingRemoteStateOfferer.h
Waving.scgxml
)

# adds all existing state headers and sources to CMake
armarx_generate_statechart_cmake_lists()

armarx_add_component("${SOURCES}" "${HEADERS}")
