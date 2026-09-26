/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162058 */

undefined4 FUN_00162058(byte *param_1,uint *param_2,undefined2 *param_3)

{
  if (*param_2 < 0xc) {
    return 0;
  }
  if (DAT_001f66a8 == 0) {
    _kdp = *(undefined2 *)(param_1 + 8);
    DAT_001f66b4 = *(undefined2 *)(param_1 + 10);
    DAT_001f66a8 = 1;
    DAT_001f66a4 = (uint)param_1[1];
  }
  else if (DAT_001f66a4 != param_1[1]) {
    param_1[8] = 1;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    goto LAB_001620c1;
  }
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
LAB_001620c1:
  *param_1 = *param_1 | 0x80;
  param_1[2] = 0xc;
  param_1[3] = 0;
  *param_3 = _kdp;
  *param_2 = (uint)*(ushort *)(param_1 + 2);
  return 1;
}

