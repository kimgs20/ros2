import rclpy
from rclpy.node import Node

from std_msgs.msg import String


# inherits from Node
class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')  # node name

        # queue size is a required quality of service seeting that limits the amount of
        # queued messages if a subscriber is not receiving them fast enough.
        self.publisher_ = self.create_publisher(String, 'topic', 10)  # topic name, queue size: 10
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1


def main(args=None):
    # 1. rclpy library is initialized.
    # 2. node is created.
    # 3. it "spins" the node so its callbacks are called.

    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()