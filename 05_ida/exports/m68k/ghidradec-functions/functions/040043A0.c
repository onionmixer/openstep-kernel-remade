
void _fstat(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined uVar4;
  undefined auStack_40 [60];
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  uVar1 = *puVar2;
  if (((uVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + uVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(sword *)(iVar3 + 0xc) == 1) {
      uVar4 = _vno_stat(*(undefined4 *)(iVar3 + 0x16),auStack_40);
    }
    else {
      if (*(sword *)(iVar3 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(&aFstat);
      }
      uVar4 = _soo_stat(*(undefined4 *)(iVar3 + 0x16),auStack_40);
    }
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uVar4 = _copyoutmsg(auStack_40,puVar2[1],0x3c);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}
