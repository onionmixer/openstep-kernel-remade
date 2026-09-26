
void _microtime(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = _clock_value(0);
  uVar2 = (uint)((qword)uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if ((uVar2 < dword_40AF93C || uVar3 < dword_40AF940 && uVar2 == dword_40AF93C) &&
     (uVar1 = dword_40AF940 - uVar3, uVar2 = (dword_40AF940 < uVar3) + uVar2,
     uVar1 < 999999999 && dword_40AF93C == uVar2 ||
     dword_40AF93C - uVar2 == (uint)(uVar1 < 999999999) && uVar1 == 999999999)) {
    uVar4 = CONCAT44(dword_40AF93C,dword_40AF940);
  }
  dword_40AF93C = (uint)((qword)uVar4 >> 0x20);
  dword_40AF940 = (uint)uVar4;
  _ns_time_to_timeval(uVar4,param_1);
  return;
}

