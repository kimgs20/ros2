## conept of programming
* callback function: 1. 다른 함수의 인자로서 이용되는 함수. 2. 어떤 이벤트에 의해 호출되어지는 함수. https://satisfactoryplace.tistory.com/18 콜백 함수(Callback)의 정확한 의미는 무엇일까?

## concept of ROS2 progrmming
* underlay
* overlay
* prefix

## build
* colcon: build system (old version: catkin)
* ament: build tool(ament_cmake, ament_python)

* CMakeList.txt: 
* packages.xml: 

## colcon build option
* --packages-up-to : 원하는 패키지와 그 종속성 패키지들을 빌드하며 전체 워크스페이스에 대해 하는 것은 아님.
* --symlink-install: saves you from having to rebuild every time you tweak python scripts   
+) It allows to use symlinks instead of copying files to the ROS2 folders during the installation, where possible. Each package in ROS2 must be installed and all the files used by the nodes must be copied into the installation folders.
* --event-handlers console_direct+ : 빌드하는 동안 output을 콘솔에 보여줌. 안쓰면 output이 log dir에 작성됨.
* --packages-select: 빌드를 원하는 패키지만 선택

## Source ROS2 environment
어떻게 설치했느냐에 따라서 환경을 source 하는 명령어가 달라짐. 나 같은 경우에는 ros2.repos에서 src받고 colcon build 했기 때문에 /opt/ros/... 에는 별게 없고 ~/ros2_galactic 에 수 gb의 데이터가 있음.

* **Binary packages** are for general use and provide an already-built install of ROS 2. This is great for people who want to dive in and start using ROS 2 as-is, right away.
* **Building from source** is meant for developers looking to alter or explicitly omit parts of ROS 2’s base. It is also recommended for platforms that don’t support binaries. Building from source also gives you the option to install the absolute latest version of ROS 2.
   
* source /opt/ros/\<ros-distro\>/setup.bash: 이거는 bianry로 설치할 때 터미널에 ros2 환경 source시킴   
* . \~/ros2_<distro>/install/local_setup.bash: ros2.repos에서 src받고 colcon build한 경우에 \~/ros2_\<distro\>/... 에 있는 환경 source시킴
* . install/(local)_setup.bash: 이것은 사용자가 내려받거나 작성한 src를 위해 user workspace에 있는 환경 source시킴

* /opt/ros/... 또는 ~/ros2_galactic/... 을 source 하지 않으면 colcon build 에서 오류 발생

* 정리: ros2 command를 terminal에서 사용하기 위해서는 무.조.건 ~/ros2_<distro>/install/local_setup.bash 를 source 해야함. 어떤 workspace에 있는 binary를 사용 할 건지는 환경 source와 underlay, overlay에 달려있음.
* 또한 사용자 ws에 있는 패키지를 사용하기 위해서는 root ws에서 . install/setup.bash 를 해야함.
* 그래도 헷갈린다면: https://answers.ros.org/question/292566/what-is-the-difference-between-local_setupbash-and-setupbash/