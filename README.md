# ros2

## install and build
https://docs.ros.org/en/galactic/Installation/Ubuntu-Development-Setup.html

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
4-1. ensure that you do not have `source /opt/ros/${ROS_DISTRO}/setup.bash` in your `.bashrc`
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
(for convenient, add '. `~`/ros2_galactic/install/local_setup.bash' at `~`/.bashrc)

6. try some examples

terminal 1
```
. ~/ros2_galactic/ros2-linux/setup.bash
ros2 run demo_nodes_cpp talker
```

terminal 2
```
. ~/ros2_galactic/ros2-linux/setup.bash
ros2 run demo_nodes_py listener
```