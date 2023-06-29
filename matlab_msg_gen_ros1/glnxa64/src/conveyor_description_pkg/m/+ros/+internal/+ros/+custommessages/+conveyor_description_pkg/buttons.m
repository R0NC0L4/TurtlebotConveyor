function [data, info] = buttons
%buttons gives an empty data for conveyor_description_pkg/buttons
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'conveyor_description_pkg/buttons';
[data.Angle, info.Angle] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Rb, info.Rb] = ros.internal.ros.messages.ros.default_type('logical',1);
info.MessageType = 'conveyor_description_pkg/buttons';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'angle';
info.MatPath{2} = 'rb';
