// include standard C++ header
#include <chrono>
#include <functional>
#include <memory>
#include <string>

// most common pieces of the ROS 2 system
// ROS Client Library for C++
#include "rclcpp/rclcpp.cpp"

// built-in message type to publish data
#include "std_msgs/mgs/string.cpp"

using namespace std::chrono_literals;  // ?

class MinimalPublisher : public rclcpp::Node {
    public:
        MinimalPublisher() : Node("minimal_publisher"), count_(0) {
            // inside constructor

            // publisher initailized with the string message type
            // topic name is 'topic', required queue size to limit messeage
            publisher_ = this->create_publisher<std::msgs::msg::String>("topic", 10);
            timer_ = this->create_wall_timer(500ms,
            std::bind(&MinimalPublisher::timer_callback, this));  // ?
        }

    private:
        // timer callback function is where the message data is set
        // and the message are actually published.
        void timer_callback() {
            auto message = std_msgs::mgs::String();
            message.data = "Hello, world! " + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publisher(message);  // ?
        }
        rclcpp::TimeBase::SharedPtr timer_;
        rclcpp::Publisher<std::msgs::mgs::String>::SharedPtr publisher_;
        size_t count_;
};

inst main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}