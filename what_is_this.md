# build
colcon: build system (old version: catkin)
ament: build tool(ament_cmake, ament_python)

CMakeList.txt: 
packages.xml: 

## colcon build option
--packages-up-to : 원하는 패키지와 관련된 모든것을 빌드한다. 전체를 다 하는것은 아님.
--event-handlers console_direct+ : 빌드하는 동안 아웃풋을 콘솔에 보여줌.  이거 안쓰면 아웃풋이 log 디렉토리에 떨궈짐.
--symlink-install: It allows to use symlinks instead of copying files to the ROS2 folders during the installation, where possible. Each package in ROS2 must be installed and all the files used by the nodes must be copied into the installation folders.


underlay
overlay
