/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cedb0 */

void _objc_addClass(int *param_1)

{
  if (param_1[8] == 0) {
    param_1[8] = (int)&_emptyCache;
    param_1[4] = 1;
  }
  if (*(int *)(*param_1 + 0x20) == 0) {
    *(undefined **)(*param_1 + 0x20) = &_emptyCache;
    *(undefined4 *)(*param_1 + 0x10) = 2;
  }
  _NXHashInsert(DAT_001e5600,param_1);
  return;
}

