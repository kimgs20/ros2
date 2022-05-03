// include standard C++ header
#include <memory>

// most common pieces of the ROS 2 system
// ROS Client Library for C++
#include "rclcpp/rclcpp.hpp"

// built-in message type to publish data
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
    public:
        // public constructor names the node 'minimal_subscriber'
        MinimalSubscriber() : Node("minimal_subscriber") {
            // constrcutor uses the node's create_subscription class to execute callback.

            // there is no timer because the subscriber simply responds whenever data is
            // published to the 'topic' topic
            subscription_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
        }

    private:
    // topic_callback function receives the string message data pubslished over the topic
    // and simply writes it to the consol using the RCLCPP_INFO macro.
                                //          ?           ?  ?     ?
        void topic_callback(const std_msgs::msg::String & msg) const {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
        }
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}
/* 
debug

1. using 'namespace' std::placeholders::_1;

2. c_st'd'()

3. subscri'b'tion

4. tihs

5. crate

6. 'm'inimalSubscriber() : Node()

7. this->create_subscription<std'::'msgs::msg::String>
 */