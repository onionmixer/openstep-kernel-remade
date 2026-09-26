
void _dup2(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (((*puVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar2 = *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4), iVar2 != 0)) &&
     (iVar2 != -0x10000)) {
    if (0xff < puVar1[1]) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
      return;
    }
    *(uint *)(dword_40B57D4 + 0x5c) = puVar1[1];
    if (puVar1[1] == *puVar1) {
      return;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),puVar1[1]);
    if ((iVar2 == *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4)) &&
       (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + puVar1[1] * 4), iVar3 != -0x10000)) {
      if (iVar3 != 0) {
        _vno_lockrelease(iVar3);
        if ((*(byte *)(puVar1[1] + *(int *)(_active_u + 0x14a)) & 2) != 0) {
          _munmapfd(puVar1[1]);
        }
        _closef(*(undefined4 *)(*(int *)(_active_u + 0x146) + puVar1[1] * 4));
        *(undefined *)(dword_40B57D4 + 100) = 0;
      }
      if (iVar2 == *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4)) {
        _dupit(puVar1[1],iVar2,(int)*(char *)(*puVar1 + *(int *)(_active_u + 0x14a)));
        return;
      }
    }
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return;
}
