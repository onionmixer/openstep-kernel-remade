
void _getitimer(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined uVar4;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar3 = *(uint **)(dword_40B57D4 + 0x24);
  if (*puVar3 < 3) {
    uVar1 = *puVar3;
    if (uVar1 == 0) {
      _getthetime(&iStack_1c);
      iVar2 = *_active_u;
      uStack_14 = *(undefined4 *)(iVar2 + 0x52);
      uStack_10 = *(undefined4 *)(iVar2 + 0x56);
      iStack_c = *(int *)(iVar2 + 0x5a);
      iStack_8 = *(int *)(iVar2 + 0x5e);
      if ((iStack_c != 0) || (iStack_8 != 0)) {
        if ((iStack_c < iStack_1c) || ((iStack_1c == iStack_c && (iStack_8 < iStack_18)))) {
          iStack_8 = 0;
          iStack_c = 0;
        }
        else {
          _timevalsub(&iStack_c,&iStack_1c);
        }
      }
    }
    else {
      uStack_14 = *(undefined4 *)((int)_active_u + uVar1 * 0x10 + 0x1f6);
      uStack_10 = *(undefined4 *)((int)_active_u + uVar1 * 0x10 + 0x1fa);
      iStack_c = *(int *)((int)_active_u + uVar1 * 0x10 + 0x1fe);
      iStack_8 = *(int *)((int)_active_u + uVar1 * 0x10 + 0x202);
    }
    uVar4 = _copyoutmsg(&uStack_14,puVar3[1],0x10);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
