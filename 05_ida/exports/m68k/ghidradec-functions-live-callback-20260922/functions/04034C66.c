
void _ifree(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined4 auStack_c [2];
  
  iVar3 = *(int *)(param_1 + 0x4e);
  uVar6 = *(int *)(iVar3 + 0x2c) * *(int *)(iVar3 + 0xb8);
  if (uVar6 < param_2 || uVar6 - param_2 == 0) {
    _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x44),param_2,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aIfreeRange);
  }
  uVar6 = param_2 / *(uint *)(iVar3 + 0xb8);
  iVar7 = _bread(*(undefined4 *)(param_1 + 0x3e),
                 *(int *)(iVar3 + 0xc) +
                 *(int *)(iVar3 + 0x18) * (uVar6 & ~*(uint *)(iVar3 + 0x1c)) +
                 uVar6 * *(int *)(iVar3 + 0xbc) << (*(uint *)(iVar3 + 100) & 0x3f),
                 *(undefined4 *)(iVar3 + 0xa0));
  iVar4 = *(int *)(iVar7 + 0x20);
  if (((*(byte *)(iVar7 + 3) & 4) == 0) && (*(int *)(iVar4 + 0x3d4) == 0x90255)) {
    _getthetime(auStack_c);
    *(undefined4 *)(iVar4 + 8) = auStack_c[0];
    param_2 = param_2 % *(uint *)(iVar3 + 0xb8);
    iVar1 = iVar4 + (param_2 >> 3);
    if (((int)*(char *)(iVar1 + 0x2d4) & 1 << (param_2 & 7)) == 0) {
      _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x44),param_2,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIfreeFreeingFr);
    }
    pbVar5 = (byte *)(iVar1 + 0x2d4);
    *pbVar5 = *pbVar5 & ~('\x01' << (param_2 & 7));
    if (param_2 < *(uint *)(iVar4 + 0x30)) {
      *(uint *)(iVar4 + 0x30) = param_2;
    }
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 1;
    *(int *)(iVar3 + 200) = *(int *)(iVar3 + 200) + 1;
    piVar2 = (int *)(*(int *)(iVar3 + ((int)uVar6 >> (*(uint *)(iVar3 + 0x70) & 0x3f)) * 4 + 0x2d8)
                     + 8 + (uVar6 & ~*(uint *)(iVar3 + 0x6c)) * 0x10);
    *piVar2 = *piVar2 + 1;
    if ((param_3 & 0xf000) == 0x4000) {
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
      *(int *)(iVar3 + 0xc0) = *(int *)(iVar3 + 0xc0) + -1;
      piVar2 = (int *)(*(int *)(iVar3 + ((int)uVar6 >> (*(uint *)(iVar3 + 0x70) & 0x3f)) * 4 + 0x2d8
                               ) + (uVar6 & ~*(uint *)(iVar3 + 0x6c)) * 0x10);
      *piVar2 = *piVar2 + -1;
    }
    *(char *)(iVar3 + 0xd0) = *(char *)(iVar3 + 0xd0) + '\x01';
    _bdwrite(iVar7);
    if (((*(byte *)(iVar3 + 0xd3) & 2) != 0) && (*(int *)(iVar3 + 0x90) < *(int *)(iVar3 + 200))) {
      _wakeup(iVar3 + 200);
      *(byte *)(iVar3 + 0xd3) = *(byte *)(iVar3 + 0xd3) & 0xfd;
    }
  }
  else {
    _brelse(iVar7);
  }
  return;
}

