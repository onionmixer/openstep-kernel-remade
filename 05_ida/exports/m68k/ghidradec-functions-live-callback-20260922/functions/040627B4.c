
uint _vnode_pager_allocpage(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  _lock_write(param_1 + 0x34);
  if (*(int *)(param_1 + 0x18) == 0) {
    _lock_done(param_1 + 0x34);
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar6 = *(int *)(param_1 + 0x24);
    if (iVar6 < 0) {
      iVar6 = iVar6 + 7;
    }
    iVar6 = iVar6 >> 3;
    while( true ) {
      iVar3 = *(int *)(param_1 + 0x14) + 7;
      if (iVar3 < 0) {
        iVar3 = *(int *)(param_1 + 0x14) + 0xe;
      }
      if (iVar3 >> 3 <= iVar6) goto loc_4062844;
      if (*(char *)(iVar6 + *(int *)(param_1 + 0x10)) != -1) break;
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    do {
      iVar3 = iVar5;
      if (iVar5 < 0) {
        iVar3 = iVar5 + 7;
      }
    } while ((((int)*(char *)(iVar6 + *(int *)(param_1 + 0x10) + (iVar3 >> 3)) &
              1 << (iVar5 + (iVar3 >> 3) * -8 & 0x1fU)) != 0) && (iVar5 = iVar5 + 1, iVar5 < 8));
loc_4062844:
    uVar2 = iVar5 + iVar6 * 8;
    if (*(int *)(param_1 + 0x14) <= (int)uVar2) {
                    /* WARNING: Subroutine does not return */
      _panic(aVnodePagerAllo);
    }
    if (*(int *)(param_1 + 0x20) < (int)uVar2) {
      *(uint *)(param_1 + 0x20) = uVar2;
    }
    uVar4 = uVar2;
    if ((int)uVar2 < 0) {
      uVar4 = uVar2 + 7;
    }
    pbVar1 = (byte *)(*(int *)(param_1 + 0x10) + ((int)uVar4 >> 3));
    *pbVar1 = *pbVar1 | '\x01' << (uVar2 & 7);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    *(uint *)(param_1 + 0x24) = uVar2;
    _lock_done(param_1 + 0x34);
  }
  return uVar2;
}

