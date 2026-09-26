
int * _in_addmulti(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined auStack_24 [16];
  undefined2 uStack_14;
  int iStack_10;
  
  iVar3 = _in_ifaddr;
  if (_in_ifaddr != 0) {
    do {
      if (param_2 == *(int *)(iVar3 + 0x20)) break;
      iVar3 = *(int *)(iVar3 + 0x40);
    } while (iVar3 != 0);
    if ((iVar3 != 0) && (piVar4 = *(int **)(iVar3 + 0x44), piVar4 != (int *)0x0)) {
      do {
        if (param_1 == *piVar4) break;
        piVar4 = (int *)piVar4[5];
      } while (piVar4 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        piVar4[3] = piVar4[3] + 1;
        return piVar4;
      }
    }
  }
  iVar3 = _in_ifaddr;
  if (_in_ifaddr != 0) {
    do {
      if (param_2 == *(int *)(iVar3 + 0x20)) break;
      iVar3 = *(int *)(iVar3 + 0x40);
    } while (iVar3 != 0);
    if ((iVar3 != 0) && (iVar1 = _m_getclr(0,0xf), iVar1 != 0)) {
      piVar4 = (int *)(*(int *)(iVar1 + 4) + iVar1);
      *piVar4 = param_1;
      piVar4[1] = param_2;
      piVar4[3] = 1;
      piVar4[2] = iVar3;
      piVar4[5] = *(int *)(iVar3 + 0x44);
      *(int **)(iVar3 + 0x44) = piVar4;
      uStack_14 = 2;
      iStack_10 = param_1;
      if ((*(int *)(param_2 + 0x36) != 0) &&
         (iVar2 = _if_ioctl(param_2,0x80206931,auStack_24), iVar2 == 0)) {
        _igmp_joingroup(piVar4);
        return piVar4;
      }
      *(int *)(iVar3 + 0x44) = piVar4[5];
      _m_free(iVar1);
      return (int *)0x0;
    }
  }
  return (int *)0x0;
}
