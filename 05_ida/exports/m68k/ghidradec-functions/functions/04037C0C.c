
word _iupdat(int param_1,int param_2)

{
  int iVar1;
  word wVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4e);
  wVar2 = *(word *)(param_1 + 0x42) & 0x4e;
  if (((*(word *)(param_1 + 0x42) & 0x4e) != 0) && (*(char *)(iVar4 + 0xd2) == '\0')) {
    uVar3 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar4 + 0xb8);
    iVar1 = _bread(*(undefined4 *)(param_1 + 0x3e),
                   ((*(uint *)(param_1 + 0x46) % *(uint *)(iVar4 + 0xb8)) / *(uint *)(iVar4 + 0x78)
                   << (*(uint *)(iVar4 + 0x60) & 0x3f)) +
                   *(int *)(iVar4 + 0x10) +
                   *(int *)(iVar4 + 0x18) * (~*(uint *)(iVar4 + 0x1c) & uVar3) +
                   uVar3 * *(int *)(iVar4 + 0xbc) << (*(uint *)(iVar4 + 100) & 0x3f),
                   *(undefined4 *)(iVar4 + 0x30));
    if ((*(byte *)(iVar1 + 3) & 4) == 0) {
      if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
        _microtime(&_iuniqtime);
        if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
          *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
          *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x4a) = 0;
          *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
        }
      }
      wVar2 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar2 & 0xffb1;
      iVar4 = (*(uint *)(param_1 + 0x46) % *(uint *)(iVar4 + 0x78)) * 0x80 + *(int *)(iVar1 + 0x20);
      *(word *)(param_1 + 0x42) = wVar2 & 0xfdb1;
      _bcopy(param_1 + 0x62,iVar4,0x80);
      if (*(sword *)(*(int *)(param_1 + 0x30) + 0x124) != 0) {
        *(undefined2 *)(iVar4 + 4) = *(undefined2 *)(param_1 + 0xe2);
        *(undefined2 *)(iVar4 + 6) = *(undefined2 *)(param_1 + 0xe4);
      }
      if (param_2 == 0) {
        wVar2 = _bdwrite(iVar1);
      }
      else {
        wVar2 = _bwrite(iVar1);
      }
    }
    else {
      wVar2 = _brelse(iVar1);
    }
  }
  return wVar2;
}
