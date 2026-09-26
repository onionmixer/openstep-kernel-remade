/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014527c */

undefined4
_rdwri(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,undefined4 param_6,
      int *param_7)

{
  ushort uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  local_24 = param_3;
  local_20 = param_4;
  local_1c = &local_24;
  local_18 = 1;
  local_14 = param_5;
  local_10 = param_6;
  local_8 = param_4;
  if ((param_1 == 1) && (**(int **)(param_2 + 0xc) != 0)) {
    _vnode_uncache(param_2 + 0xc);
  }
  uVar2 = *(uint *)(param_2 + 0x3c);
  if ((*(ushort *)(uVar2 + 100) & 0xf000) == 0x8000) {
    bVar3 = true;
    while ((*(ushort *)(uVar2 + 0x44) & 1) != 0) {
      *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 0x10;
      _sleep(uVar2);
    }
    *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) | 1;
  }
  else {
    bVar3 = false;
  }
  uVar4 = FUN_00143e24(uVar2,&local_1c,param_1,0);
  if ((*(ushort *)(uVar2 + 0x44) & 0x46) != 0) {
    *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(uVar2 + 0x44) & 4) != 0) {
      *(undefined4 *)(uVar2 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(uVar2 + 0x44) & 2) != 0) {
      *(undefined4 *)(uVar2 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(uVar2 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(uVar2 + 0x4c) = 0;
      *(undefined4 *)(uVar2 + 0x84) = _iuniqtime;
    }
    *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) & 0xb9;
  }
  if (bVar3) {
    uVar1 = *(ushort *)(uVar2 + 0x44);
    *(ushort *)(uVar2 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(uVar2 + 0x44) = uVar1 & 0xffee;
      _wakeup(uVar2);
    }
  }
  if (param_7 == (int *)0x0) {
    if (local_8 != 0) {
      uVar4 = 5;
    }
  }
  else {
    *param_7 = local_8;
  }
  return uVar4;
}

