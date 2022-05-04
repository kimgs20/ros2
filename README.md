# ros2
1. building ROS2 on Ubuntu Linux: download and build from ros2.repos
2. installing ROS2 on Ubuntu Linux: install ROS 2 on Ubuntu Linux from a pre-built binary package

## install and build
https://docs.ros.org/en/galactic/Installation/Ubuntu-Development-Setup.html
* tip: do not use anaconda virtual env. if colcon build in venv, build will fail due to cannot import some modules.

1. system setup   
1-1. set locale   
```
locale  # check for UTF-8
sudo apt update && sudo apt install locales
...
```

1-2. add the ROS2 apt repository   
```
sudo apt update && sudo apt install curl gnupg lsb-release
...
```

1-3. install development tools and ROS tools   
```
sudo apt update && sudo apt install -y \
  build-essential \
...
```

2. get ROS2 code
create a workspace and clone all repos:
```
mkdir -p ~/ros2_galactic/src
cd ~/ros2_galactic
wget https://.../ros2.repos
vcs import src `<` ros2.repos
```

3. install dependencies using rosdep
```
sudo rosdep init
rosdep update
...
```

4. build the code in workspace   
ensure that you do not have `source /opt/ros/${ROS_DISTRO}/setup.bash` in your `.bashrc`
```
cd ~/ros2_galactic/
colcon build --symlink-install
```
build start!!   
terminal will print   
`Summary: 331 packages finished [xmin xxs]`

5. environment setup
Set up your environment by sourcing the following file.
```
. ~/ros2_galactic/install/local_setup.bash
```
(for convenient, add '. \~/ros2_galactic/install/local_setup.bash' at \~/.bashrc)

6. try some examples

terminal 1
```
. ~/ros2_galactic/install/local_setup.bash
ros2 run demo_nodes_cpp talker
```

terminal 2
```
. ~/ros2_galactic/install/local_setup.bash
ros2 run demo_nodes_py listener
```

## creating a workspace
1. source ROS2 environment
```
source /opt/ros/galactic/setup.bash
```
for convenient, `echo "source /opt/ros/<ros-distro>/setup.bash" >> ~/.bashrc`

2. create a new directory
```
mkdir -p ~/${dir_name}_ws/src
cd ~/${dir_name}_ws/src
```

3. clone a sample repo
in src directory,
```
git clone https://github.com/ros/ros_tutorials.git -b galactic-devel
```
`turtlesim` package will be use for this tutorial.

4. resolve dependencies

```
cd .. (move to the upper dir of src e.g. ${dir_name}_ws)
rosdep install -i --from-path src --rosdistro galactic -y
```
rosdep command will make `/opt/ros/galactic/...` and resolve dependencies
consol will return   
`#All required rosdeps installed successfully`

5. build the workspace with colcon
at directoty ${dir_name}_ws, use this command
```
colcon build
```
then you will see that colcon has created new directories
`build install log src`
The `install` directory is where your workspace’s setup files are, which you can use to source your overlay.

6. source the overlay
before sourcing overlay, open a new terminal to avoid complex issues.
```
source /opt/ros/galactic/setup.bash
cd ~/${dir_name}_ws
. install/local_setup.bash
```
now you can run `turtlesim` package from the overlay
```
ros2 run turtlesim turtlesim_node
```

7. modify the overlay
modify `turtle_frame.cpp` in `.../src/turtlesim` change the value `"TurtleSim"` to `"MyTurtleSim"` at line 52, and save the file. and return to first terminal where you ran `colcon build` eariler and run it again. and run `ros2 run turtlesim turtlesim_node` at the second terminal where overlay is sourced. then you will see the title bar on the turtlesim windows now says `"MyTurtleSim"`.

## create first ROS2 package
### C++
1. navigate to `${dir_name}_ws/src` and run the package creation command:
```
ros2 pkg create --build-type ament_cmake cpp_pubsub_tuto
```
navigate to ${dir_name}_ws/src/cpp_pubsub_tuto/src

2. write the publisher node
2-1. write new file `publisher_member_function.cpp`.
```
#include <chrono>
#include ...
...
    return 0;
}
```
2-2. add dependencies   
open `package.xml` and add the lines:
```
<depend>rclcpp</depend>
<depend>std_msgs</depend>
```
   
2-3. CMakeLists.txt   
open `CMakeLists.txt` and add the lines below `find_package(ament_cmake REQUIRED)`:
```
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
```
and add the executable and name it `talker` so you can run your node using `ros2 run`:
```
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
```
add `install(TARGETS...)` so `ros2 run` can find your executable:
```
install(TARGETS
    talker
    DESTINATION lib/${PROJECT_NAME})
```
   
3. write the subscriber node
3-1. 

3-2. you don't need to edit `package.xml`

3-3. CMakeLists.txt
add the executable and target for the subscriber node
```
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})
```

4. build and run
run `rosdep` in the root of your workspace (`${dir_name}_ws`) to check for missing dependencies before building:
```
rosdep install -i --from-path src --rosdistro galactic -y
```

in the root(`${dir_name}_ws`), build your new packages:
```
colcon build --packages-select cpp_pubsub_tuto
```

open a new terminal, naviagte to `${dir_name}_ws`, and source the setup files
```
. install/setup.bash
```

### Python
1. navigate to `${dir_name}_ws/src` and run the package creation command:
```
ros2 pkg create --build-type ament_python py_pubsub_tuto
```

2. write the publisher node
2-1. write new file `${dir_name}_ws/src/py_pubsub_tuto/py_pubsub_tuto/publisher_member_function.py`.
```
import rclpy
from ...
...
if __name__ == '__main__':
    main()
```

2-2. add dependencies   
navigate one level back to the `${dir_name}_ws/src/py_subpub_tuto` directory, where `setup.py`, `setup.cfg` and `<license>` tags. and add the dependencies at `package.xml`:
```
<exec_depend>rclpy</exec_depend>
<exec_depend>std_msgs</exec_depend>
```

2-3. add entry point   
open the `setup.py` file and match maintainer, maintainer_email, description and license fields to your `package.xml`.   
add the follwing line within the `console_scripts` brackets of the `entry_points` fields:
```
entry_points={
        'console_scripts': [
                'talker = py_pubsub_tuto.publisher_member_function:main'
        ],
},
```

2-4. check setup.cfg   
contents of the `setup.cfg` file should be correctly populated automatically.
```
[develop]
script_dir=$base/lib/py_pubsub_tuto
[install]
install_scripts=$base/lib/py_pubsub_tuto
```
* typo in document: script-dir, install-script

3. write subscriber node
3-1. write new file `${dir_name}_ws/src/py_pubsub_tuto/py_pubsub_tuto/subscriber_member_function.py`
```
import rclpy
from ...
...
if __name__ == '__main_':
    main()
```

3-2. add an entry point
```
entry_points={
        'console_scripts': [
                'talker = py_pubsub_tuto.publisher_member_function:main',
                'listener = py_pubsub_tuto.subscriber_member_function:main',
        ],
},
```
4. build and run
python packages of ROS 2 are need to be build!   
in the root of your workspace to check for missing dependencies before building:
```
rosdep install -i --from-path src --rosdistro galactic -y
```

build your new packge:
```
colcon build --packages-select py_pubsub_tuto
```

source the setup file:
```
. install/setup.py
```

run the talker node:
```
ros2 run py_pubsub_tuto talker
```
(command name was set in setup.py)   
   
run the listner node:
```
ros2 run py_pubsub_tuto listner
```