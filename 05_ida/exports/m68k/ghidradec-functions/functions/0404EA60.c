
void _us_abstimeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = _timeval_to_ns_time(param_3);
  _ns_abstimeout(param_1,param_2,uVar1,param_4);
  return;
}
