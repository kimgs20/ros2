// include standard C++ header
#include <chrono>
#include <functional>
#include <memory>
#include <string>

// most common pieces of the ROS 2 system
// ROS Client Library for C++
#include "rclcpp/rclcpp.hpp"

// built-in message type to publish data
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;  // ?

// 1. create subcalss of Node 2. uses std::bind() to register a member function.

// node class MinimalPublisher inherited from rclcpp::Node
// 'this' is referring to the node.
class MinimalPublisher : public rclcpp::Node {
    public:
        // public constructor names the node 'minimal_publisher'
        MinimalPublisher() : Node("minimal_publisher"), count_(0) {
            // inside constructor

            // publisher initailized with the string message type
            // topic name is 'topic', required queue size to limit messeage
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

            // uses std::bind() to register a member function as a callback from the timer.
            timer_ = this->create_wall_timer(500ms,
            std::bind(&MinimalPublisher::timer_callback, this));
        }

    private:
        // timer callback function is where the message data is set
        // and the message are actually published.
        void timer_callback() {
            // auto: automatically declaring datatype
            auto message = std_msgs::msg::String();
            message.data = "Hello, world! " + std::to_string(count_++);

            // RCLCPP_INFO macro ensures every published message is printed to the console.
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);  // ?
        }

        // declaration of the timer, publisher, and conuter fields.
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
};

// where the node actually executes.
int main(int argc, char * argv[]) {
    // initializes ROS 2
    rclcpp::init(argc, argv);

    // starts processing data from the node, including callbacks from the timer.
    rclcpp::spin(std::make_shared<MinimalPublisher>());

    rclcpp::shutdown();
    return 0;
}
/* 
debug

1. #include "std_msgs/m'g's/string.hpp"

2. publisher_->publish'er'(message);  // ?

3. auto message = std_msgs::m'gs'::String();

4. this->create_publisher<std'::'msgs::msg::String>

5. rclcpp::Publisher<std'::'msgs::mgs::String>

6. rclcpp::Publisher<std_msgs::m'gs'::String>::

7. rclcpp::Time''Base
 */