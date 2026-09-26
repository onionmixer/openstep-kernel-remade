/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143d14 */

undefined4 FUN_00143d14(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if ((param_3 == 1) && (*(int *)*param_1 != 0)) {
    _vnode_uncache(param_1);
  }
  uVar2 = param_1[0xc];
  if ((*(ushort *)(uVar2 + 100) & 0xf000) == 0x8000) {
    bVar3 = true;
    while ((*(ushort *)(uVar2 + 0x44) & 1) != 0) {
      *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 0x10;
      _sleep(uVar2);
    }
    *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) | 1;
    if (((param_4 & 2) != 0) && (param_3 == 1)) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(uVar2 + 0x6c);
    }
  }
  else {
    bVar3 = false;
  }
  uVar4 = FUN_00143e24(uVar2,param_2,param_3,param_4);
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
  return uVar4;
}

