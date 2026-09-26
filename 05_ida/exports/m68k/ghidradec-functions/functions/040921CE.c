
void _set_clock(int param_1,int param_2,uint param_3)

{
  undefined8 uVar1;
  undefined auStack_c [8];
  
  if (param_1 == 0) {
    uVar1 = _clock_value(1);
    dword_40B55B0 = param_3 - (uint)uVar1;
    dword_40B55AC = param_2 - ((uint)(param_3 < (uint)uVar1) + (int)((qword)uVar1 >> 0x20));
    _ns_time_to_timeval(param_2,param_3,auStack_c);
    _rtc_set(auStack_c);
  }
  return;
}
