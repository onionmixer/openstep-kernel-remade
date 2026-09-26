
void _rtc_set_clr(undefined param_1,byte param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = _rtc_read(param_1);
  _rtc_write(param_1,param_3 & param_2 | ~(uint)param_2 & uVar1);
  return;
}
