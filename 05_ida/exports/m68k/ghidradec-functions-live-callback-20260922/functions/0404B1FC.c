
undefined4 _host_set_time(int param_1,code param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = _mtime;
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    _time = param_2;
    dword_40AF7F0 = param_3;
    if (_mtime != (code *)0x0) {
      *(code *)((int)_mtime + 8) = param_2;
      *(undefined4 *)((int)pcVar1 + 4) = dword_40AF7F0;
      *pcVar1 = _time;
    }
    _set_calendar_time_value(_time);
    uVar2 = 0;
  }
  return uVar2;
}

