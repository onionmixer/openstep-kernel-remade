
void _timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  uVar1 = _ticks_to_ns_time(param_3,0);
  _ns_timeout(param_1,param_2,uVar1);
  return;
}

