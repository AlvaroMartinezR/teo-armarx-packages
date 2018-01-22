###
### CMakeLists.txt file for WavingReDo Interfaces
###

# Dependencies on interface libraries to other ArmarX Packages must be specified
# in the following variable separated by whitespaces
# set(WavingReDo_INTERFACE_DEPEND ArmarXCore)

# List of slice files to include in the interface library
set(SLICE_FILES
)

# generate the interface library
armarx_interfaces_generate_library(WavingReDo "${WavingReDo_INTERFACE_DEPEND}")
