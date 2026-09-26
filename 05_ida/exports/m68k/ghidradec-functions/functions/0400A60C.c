
void _setitimer(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  undefined uVar7;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar8;
  undefined auStack_1c [8];
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  if (*puVar2 < 3) {
    uVar3 = puVar2[1];
    if (puVar2[2] != 0) {
      puVar2[1] = puVar2[2];
      _getitimer();
    }
    if (uVar3 != 0) {
      uVar7 = _copyinmsg(uVar3,&uStack_14,0x10);
      *(undefined *)(dword_40B57D4 + 100) = uVar7;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        iVar5 = _itimerfix(&iStack_c);
        if ((iVar5 == 0) && (iVar5 = _itimerfix(&uStack_14), piVar4 = _active_u, iVar5 == 0)) {
          uVar3 = *puVar2;
          if (uVar3 == 0) {
            _getthetime(auStack_1c);
            _untimeout(_realitexpire,iVar1);
            if ((iStack_c != 0) || (iStack_8 != 0)) {
              _timevaladd(&iStack_c,auStack_1c);
              uVar6 = _hzto(&iStack_c);
              _timeout(_realitexpire,iVar1,uVar6);
            }
            *(undefined4 *)(iVar1 + 0x52) = uStack_14;
            *(undefined4 *)(iVar1 + 0x56) = uStack_10;
            *(int *)(iVar1 + 0x5a) = iStack_c;
            *(int *)(iVar1 + 0x5e) = iStack_8;
          }
          else {
            puVar8 = (undefined4 *)((int)_active_u + uVar3 * 0x10 + 0x1fa);
            *(undefined4 *)((int)_active_u + uVar3 * 0x10 + 0x1f6) = uStack_14;
            *puVar8 = uStack_10;
            *(int *)((int)piVar4 + uVar3 * 0x10 + 0x1fe) = iStack_c;
            *(int *)((int)piVar4 + uVar3 * 0x10 + 0x202) = iStack_8;
          }
        }
        else {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
        }
      }
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
