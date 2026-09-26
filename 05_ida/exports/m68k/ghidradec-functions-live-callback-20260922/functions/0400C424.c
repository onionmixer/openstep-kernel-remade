
void _select(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_c [8];
  
  iVar2 = dword_40B57D4;
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = dword_40B57D4 + 0x7e;
  _bcopy(unk_40ACE76,iVar3,0xd0);
  if (0x100 < *piVar1) {
    *piVar1 = 0x100;
  }
  uVar4 = *piVar1 + 0x1fU >> 5;
  if (piVar1[1] != 0) {
    iVar3 = _copyinmsg(piVar1[1],iVar3,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[2] != 0) {
    iVar3 = _copyinmsg(piVar1[2],iVar2 + 0x9e,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[3] != 0) {
    iVar3 = _copyinmsg(piVar1[3],iVar2 + 0xbe,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[4] != 0) {
    iVar3 = _copyinmsg(piVar1[4],iVar2 + 0x13e,8);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 == 0) {
      iVar3 = _itimerfix(iVar2 + 0x13e);
      if (iVar3 == 0) {
        if ((*(int *)(iVar2 + 0x13e) == 0) && (*(int *)(iVar2 + 0x142) == 0)) {
          *(undefined4 *)(iVar2 + 0x146) = 1;
        }
        else {
          _getthetime(auStack_c);
          _timevaladd(iVar2 + 0x13e,auStack_c);
        }
      }
      else {
        *(undefined4 *)(iVar2 + 0x14a) = 0x16;
      }
    }
  }
loc_400C538:
  _selcont();
  return;
}

