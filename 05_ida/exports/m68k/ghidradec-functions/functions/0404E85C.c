
undefined4 _sched_usec_elapsed(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar6 = _clock_value(1);
  iVar4 = (int)((qword)uVar6 >> 0x20);
  uVar5 = (uint)uVar6;
  uVar3 = CONCAT44(dword_40B39BA,dword_40B39BE);
  if (dword_40B39BE == 0 && dword_40B39BA == 0) {
    uVar3 = uVar6;
  }
  dword_40B39BA = (int)((qword)uVar3 >> 0x20);
  dword_40B39BE = (uint)uVar3;
  iVar1 = uVar5 - dword_40B39BE;
  iVar2 = (uint)(uVar5 < dword_40B39BE) + dword_40B39BA;
  dword_40B39BA = iVar4;
  dword_40B39BE = uVar5;
  return (int)(CONCAT44((uint)(iVar4 - iVar2) % 1000,iVar1) / 1000);
}
