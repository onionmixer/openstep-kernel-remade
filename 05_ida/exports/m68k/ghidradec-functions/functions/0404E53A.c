
void _ns_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  _ns_abstimeout(param_1,param_2,sVar1 + CONCAT44(param_3,param_4),param_5);
  return;
}
