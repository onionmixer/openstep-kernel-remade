/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b343c */

void FUN_001b343c(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  uint local_c;
  int local_8;
  
  if ((*(char *)(param_1 + 0x1d2) == '\x01') &&
     (*(undefined4 *)(param_1 + 0x1a8) = *param_3, *(char *)(param_1 + 0x209) == '\0')) {
    _IOGetTimestamp(&local_c);
    uVar1 = local_c >> 0x18 | local_8 << 8;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    _objc_msgSend(param_1,PTR_s__setCursorPosition_atTime__001f99ac,param_3,uVar1);
  }
  return;
}

