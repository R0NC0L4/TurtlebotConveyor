function [data, info] = conveyor_state
%conveyor_state gives an empty data for conveyor_description_pkg/conveyor_state
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'conveyor_description_pkg/conveyor_state';
[data.WheelLr, info.WheelLr] = ros.internal.ros.messages.ros.default_type('single',1);
[data.WheelRr, info.WheelRr] = ros.internal.ros.messages.ros.default_type('single',1);
[data.WheelLf, info.WheelLf] = ros.internal.ros.messages.ros.default_type('single',1);
[data.WheelRf, info.WheelRf] = ros.internal.ros.messages.ros.default_type('single',1);
[data.JointLr, info.JointLr] = ros.internal.ros.messages.ros.default_type('single',1);
[data.JointRr, info.JointRr] = ros.internal.ros.messages.ros.default_type('single',1);
[data.JointLf, info.JointLf] = ros.internal.ros.messages.ros.default_type('single',1);
[data.JointRf, info.JointRf] = ros.internal.ros.messages.ros.default_type('single',1);
info.MessageType = 'conveyor_description_pkg/conveyor_state';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,8);
info.MatPath{1} = 'wheel_lr';
info.MatPath{2} = 'wheel_rr';
info.MatPath{3} = 'wheel_lf';
info.MatPath{4} = 'wheel_rf';
info.MatPath{5} = 'joint_lr';
info.MatPath{6} = 'joint_rr';
info.MatPath{7} = 'joint_lf';
info.MatPath{8} = 'joint_rf';
