
int _ttnread(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if ((*(byte *)((int)piVar1 + 0x3a) & 0x20) != 0) {
    _ttypend(piVar1);
  }
  iVar2 = piVar1[3];
  if (((*(uint *)((int)piVar1 + 0x3a) & 0x22) != 0) &&
     (iVar2 = *piVar1 + iVar2, iVar2 < (int)(uint)*(byte *)((int)param_1 + 0x15))) {
    iVar2 = 0;
  }
  return iVar2;
}

