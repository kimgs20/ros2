# ros2
1. building ROS2 on Ubuntu Linux: download and build from ros2.repos
2. installing ROS2 on Ubuntu Linux: install ROS 2 on Ubuntu Linux from a pre-built binary package

## install and build
https://docs.ros.org/en/galactic/Installation/Ubuntu-Development-Setup.html
\*tip: do not use anaconda virtual env. if colcon build in venv, build will fail due to cannot import some modules.

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

## writing a simple publisher and subscriber (C++ and python)