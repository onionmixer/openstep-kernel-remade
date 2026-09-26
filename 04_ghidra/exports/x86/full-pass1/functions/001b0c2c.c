/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0c2c */

undefined4 FUN_001b0c2c(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 == *(int *)(param_1 + 0x134)) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
    if (*(char *)(param_1 + 0x1d0) == '\x01') {
      uVar1 = 0xfffffd2b;
    }
    else {
      *(undefined1 *)(param_1 + 0x1d0) = 1;
      if (*(char *)(param_1 + 0x1d1) == '\0') {
        *(undefined1 *)(param_1 + 0x1d1) = 1;
        *(undefined4 *)(param_1 + 0x1cc) = 0x40;
        *(undefined4 *)(param_1 + 0x1c4) = 0x20;
      }
      _objc_msgSend(param_1,PTR_s_setEventPort__001f9a40,param_4);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  }
  else {
    uVar1 = 0xfffffd3e;
  }
  return uVar1;
}

