
void _usec_delay(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = _Cpudelay == 0;
  iVar3 = _Cpudelay;
  do {
    do {
      bVar2 = !bVar4;
      bVar4 = iVar3 + -1 == 0;
      iVar3 = iVar3 + -1;
    } while (bVar2);
    iVar1 = param_1 + -1;
    bVar2 = 0 < param_1;
    bVar4 = _Cpudelay == 0;
    param_1 = iVar1;
    iVar3 = _Cpudelay;
  } while (iVar1 != 0 && bVar2);
  return;
}
