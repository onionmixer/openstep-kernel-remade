
int _dup(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  uVar1 = *puVar2;
  if ((uVar1 & 0xffffffc0) != 0) {
    *puVar2 = uVar1 & 0x3f;
    iVar4 = _dup2();
    return iVar4;
  }
  iVar4 = 0;
  if (((uVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + uVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    iVar4 = _ufalloc(0);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (iVar3 == *(int *)(*(int *)(_active_u + 0x146) + *puVar2 * 4)) {
      iVar4 = _dupit(iVar4,iVar3,(int)*(char *)(*puVar2 + *(int *)(_active_u + 0x14a)));
      return iVar4;
    }
    *(undefined4 *)(*(int *)(_active_u + 0x146) + iVar4 * 4) = 0;
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return iVar4;
}

