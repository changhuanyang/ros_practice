# ros_practice
ros useful tool practice

------------------------------------------------------------------------------------
ros parameter ref:
http://answers.ros.org/question/43001/setting-parameters-in-a-launch-file-does-not-appear-to-be-working/

<param name="camera_topic_root" value="/camera/image_rect">
<group ns="group_ns">
    <param name="camera_topic_ns" value="/camera/image_rect">
    <node name="node_name" pkg="foo" type="bar" >
        <param name="camera_topic_private" value="/camera/image_rect">
    </node>
</group>


/camera_topic_root
/group_ns/camera_topic_ns
/group_ns/node_name/camera_topic_private


ros::param::get("/camera_topic_root",camera_topic);    // /camera_topic_root
ros::param::get("camera_topic_ns",camera_topic);       // /group_ns/camera_topic_ns
ros::param::get("~camera_topic_private",camera_topic); // /group_ns/node_name/camera_topic_private
------------------------------------------------------------------------------------------------------
