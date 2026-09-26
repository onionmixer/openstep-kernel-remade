/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00133130 */

void FUN_00133130(byte *param_1)

{
  short sVar1;
  int iVar2;
  byte *pbVar3;
  
  if (((*param_1 & 1) == 0) &&
     (sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x40) + 0x30) + 0x62), sVar1 != 0)) {
    *(short *)(param_1 + 0x1c) = sVar1;
    *param_1 = *param_1 | 4;
    _biodone(param_1);
    return;
  }
  if ((DAT_001e59ec != 0) && ((param_1[1] & 1) != 0)) {
    if (_async_bufhead == (byte *)0x0) {
      _async_bufhead = param_1;
    }
    else {
      iVar2 = *(int *)(_async_bufhead + 0xc);
      pbVar3 = _async_bufhead;
      while (iVar2 != 0) {
        pbVar3 = *(byte **)(pbVar3 + 0xc);
        iVar2 = *(int *)(pbVar3 + 0xc);
      }
      *(byte **)(pbVar3 + 0xc) = param_1;
    }
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    if (_nfs_wakeup_one_biod != 1) {
      _wakeup(&_async_bufhead);
      return;
    }
    _wakeup_one(&_async_bufhead);
    return;
  }
  FUN_001332c8(param_1);
  return;
}

