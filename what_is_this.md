# build
*colcon: build system (old version: catkin)
*ament: build tool(ament_cmake, ament_python)

*CMakeList.txt: 
*packages.xml: 

## colcon build option
*--packages-up-to : 원하는 패키지와 그 종속성 패키지들을 빌드하며 전체 워크스페이스에 대해 하는 것은 아님.
*--symlink-install: saves you from having to rebuild every time you tweak python scripts   
+) It allows to use symlinks instead of copying files to the ROS2 folders during the installation, where possible. Each package in ROS2 must be installed and all the files used by the nodes must be copied into the installation folders.
*--event-handlers console_direct+ : 빌드하는 동안 아웃풋을 콘솔에 보여줌.  이거 안쓰면 아웃풋이 log 디렉토리에 떨궈짐.

# concept
*underlay
*overlay
*source /opt/ros/\<ros-distro\>/setup.bash는 왜 하는가?
*. install/local_setup.bash를 하면 무슨 일이 일어나나? 왜 하는가?
