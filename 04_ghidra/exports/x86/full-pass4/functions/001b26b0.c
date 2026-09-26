/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b26b0 */

void FUN_001b26b0(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x40 < param_3) {
    param_3 = 0x40;
  }
  if ((*(int *)(param_1 + 0x1c8) != param_3) &&
     (*(int *)(param_1 + 0x1c8) = param_3, *(char *)(param_1 + 0x1d3) == '\x01')) {
    _objc_msgSend(param_1,PTR_s_setBrightness_001f9994);
    return;
  }
  return;
}

