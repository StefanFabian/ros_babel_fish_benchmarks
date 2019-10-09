## Benchmarks using Google Benchmark

Results were obtained on Ubuntu 18.04 with ROS Melodic using an i7-6700K and a 128GB Samsung 830 SSD.  

## Requirements

Google Benchmark  
For Ubuntu: `sudo apt install libbenchmark-dev`  
[ros_type_introspection](https://github.com/facontidavide/ros_type_introspection) either from source or `sudo apt install ros-{RELEASE}-ros-type-introspection`

## Results

### Message Look Up
The times for the creation of the description provider and the lookup were obtained separetely.

```
$ sudo cpupower frequency-set --governor performance && rosrun rbf_benchmark message_lookup && sudo cpupower frequency-set --governor powersave
Run on (8 X 4200 MHz CPU s)
2019-10-09 17:45:46
***WARNING*** Library was built as DEBUG. Timings may be affected.
---------------------------------------------------------------------------
Benchmark                                    Time           CPU Iterations
---------------------------------------------------------------------------
IntegratedDescriptionProviderCreate        114 ms        114 ms          6
IntegratedDescriptionProviderLookUp        115 us        115 us       6024
```

### Message Translation
The time it takes to translate a raw received message.
Separated into the initial step of parsing the message definition which has to be done only once and subsequent message parsing.
Results were obtained with ros_type_introspection from [09.10.2019](https://github.com/facontidavide/ros_type_introspection/tree/e47acd24942efda1960294a6c8aa6e105eafbf7d)
and ros_babel_fish from [09.10.2019](https://github.com/StefanFabian/ros_babel_fish/tree/b332c583ba54cb66ca159760a7a11179b3f6d5da). 

```
$ sudo cpupower frequency-set --governor performance && rosrun rbf_benchmark message_translation && sudo cpupower frequency-set --governor powersave
Run on (8 X 4200 MHz CPU s)
2019-10-09 17:23:11
***WARNING*** Library was built as DEBUG. Timings may be affected.
--------------------------------------------------------------------------------------------
Benchmark                                                     Time           CPU Iterations
--------------------------------------------------------------------------------------------
RTI_ParseMessageDefinition<geometry_msgs::Pose>              76 us         76 us       9124
RBF_ParseMessageDefinition<geometry_msgs::Pose>              46 us         46 us      15431

RTI_ParseMessageDefinition<sensor_msgs::JointState>         172 us        172 us       4087
RBF_ParseMessageDefinition<sensor_msgs::JointState>         104 us        104 us       6800

RTI_ParseMessageDefinition<nav_msgs::Odometry>              324 us        324 us       2188
RBF_ParseMessageDefinition<nav_msgs::Odometry>              261 us        261 us       2716

RTI_ParseMessageDefinition<tf::tfMessage>                   217 us        217 us       3113
RBF_ParseMessageDefinition<tf::tfMessage>                   170 us        170 us       4137

RTI_ParseMessageDefinition<sensor_msgs::PointCloud2>        294 us        294 us       2434
RBF_ParseMessageDefinition<sensor_msgs::PointCloud2>        148 us        148 us       4709

RTI_ParseMessageDefinition<sensor_msgs::Image>              185 us        185 us       3714
RBF_ParseMessageDefinition<sensor_msgs::Image>              131 us        131 us       5335

---

RTI_ParseMessage<geometry_msgs::Pose>                       334 ns        334 ns    2078223
RBF_ParseMessage<geometry_msgs::Pose>                       349 ns        349 ns    2044464

RTI_ParseMessage<sensor_msgs::JointState>                   581 ns        581 ns    1215252
RBF_ParseMessage<sensor_msgs::JointState>                   335 ns        335 ns    2009207

RTI_ParseMessage<nav_msgs::Odometry>                       1159 ns       1159 ns     614297
RBF_ParseMessage<nav_msgs::Odometry>                       1009 ns       1009 ns     695203

RTI_ParseMessage<tf::tfMessage>                            1946 ns       1946 ns     353818
RBF_ParseMessage<tf::tfMessage>                            1889 ns       1889 ns     377316

RTI_ParseMessage<sensor_msgs::PointCloud2>                 8827 ns       8826 ns      79320
RBF_ParseMessage<sensor_msgs::PointCloud2>                  586 ns        586 ns    1219825

RTI_ParseMessage<sensor_msgs::Image>                      62604 ns      62604 ns      11197
RBF_ParseMessage<sensor_msgs::Image>                        354 ns        354 ns    2012739
```
