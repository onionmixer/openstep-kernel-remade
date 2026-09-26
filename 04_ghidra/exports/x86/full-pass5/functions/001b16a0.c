/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b16a0 */

int FUN_001b16a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (((*(int *)(param_1 + 0x114) == param_3) && (*(char *)(param_1 + 0x1d0) != '\0')) &&
     (*(char *)(param_1 + 0x1d2) != '\0')) {
    *(undefined1 *)(param_1 + 0x1d2) = 0;
    iVar1 = _destroyEventShmem(*(undefined4 *)(param_1 + 0x150),*(undefined4 *)(param_1 + 0x154),
                               *(undefined4 *)(param_1 + 0x160),*(undefined4 *)(param_1 + 0x158),
                               *(undefined4 *)(param_1 + 0x15c));
    if (iVar1 != 0) {
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
      _IOLog("%s: destroyEventShmem fails (%d).\n",uVar2);
    }
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x150) = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    iVar1 = -0x2c1;
  }
  return iVar1;
}

