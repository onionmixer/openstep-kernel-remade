/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001620e8 */

undefined4 FUN_001620e8(byte *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  
  if ((*param_2 < 8) || (DAT_001f66a8 == 0)) {
    uVar1 = 0;
  }
  else {
    *param_3 = _kdp;
    DAT_001f66b4 = 0;
    _kdp = 0;
    DAT_001f66a8 = 0;
    DAT_001f66b0 = 0;
    DAT_001f66a4 = 0;
    DAT_001f66b6 = 0;
    *param_1 = *param_1 | 0x80;
    param_1[2] = 8;
    param_1[3] = 0;
    *param_2 = 8;
    uVar1 = 1;
  }
  return uVar1;
}

