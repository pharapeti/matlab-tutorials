function the_xyz_bus_def_file() 
% THE_XYZ_BUS_DEF_FILE initializes a set of bus objects in the MATLAB base workspace 

% Bus object: slBus1 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'xe';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'ye';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'ze';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

slBus1 = Simulink.Bus;
slBus1.HeaderFile = '';
slBus1.Description = '';
slBus1.DataScope = 'Auto';
slBus1.Alignment = -1;
slBus1.Elements = elems;
clear elems;
assignin('base','slBus1', slBus1);

