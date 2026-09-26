
int _loadaddrs(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_1 < 0x401) {
    iVar2 = *param_1 << 4;
    uVar1 = param_1[1];
    if (iVar2 == 0) {
      param_1[1] = 0;
      iVar3 = 0;
    }
    else {
      uVar4 = _kalloc(iVar2);
      param_1[1] = uVar4;
      iVar3 = _copyinmsg(uVar1,uVar4,iVar2);
      if (iVar3 != 0) {
        _kfree(param_1[1],iVar2);
      }
    }
  }
  else {
    iVar3 = 0x16;
  }
  return iVar3;
}

