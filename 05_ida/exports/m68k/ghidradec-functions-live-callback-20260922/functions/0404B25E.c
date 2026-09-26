
undefined4 _host_adjust_time(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x16;
  }
  else {
    uVar4 = param_3 + param_2 * 1000000;
    iVar2 = (int)_timedelta / 1000000;
    iVar1 = (int)_timedelta % 1000000;
    if (_timedelta == 0) {
      if (_bigadj < uVar4) {
        _tickdelta = _tickadj * 10;
      }
      else {
        _tickdelta = _tickadj;
      }
    }
    if (uVar4 % _tickdelta != 0) {
      uVar4 = _tickdelta * (uVar4 / _tickdelta);
    }
    _timedelta = uVar4;
    *param_4 = iVar2;
    param_4[1] = iVar1;
    uVar3 = 0;
  }
  return uVar3;
}

