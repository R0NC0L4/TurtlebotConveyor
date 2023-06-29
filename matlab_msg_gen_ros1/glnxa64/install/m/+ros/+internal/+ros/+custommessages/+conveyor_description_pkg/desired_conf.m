function [data, info] = desired_conf
%desired_conf gives an empty data for conveyor_description_pkg/desired_conf
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'conveyor_description_pkg/desired_conf';
[data.Velocity, info.Velocity] = ros.internal.ros.messages.ros.default_type('single',1);
[data.AngularVelocity, info.AngularVelocity] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Angle, info.Angle] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Conf, info.Conf] = ros.internal.ros.messages.ros.default_type('int8',1);
info.MessageType = 'conveyor_description_pkg/desired_conf';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'velocity';
info.MatPath{2} = 'angular_velocity';
info.MatPath{3} = 'angle';
info.MatPath{4} = 'conf';
