
void _microboot(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _clock_value(1);
  _ns_time_to_timeval(uVar1,param_1);
  return;
}
