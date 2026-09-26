/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001621b4 */

bool FUN_001621b4(byte *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  
  uVar1 = *param_2;
  if (7 < uVar1) {
    *param_1 = *param_1 | 0x80;
    param_1[2] = 8;
    param_1[3] = 0;
    DAT_001f66b0 = 1;
    *param_3 = _kdp;
    *param_2 = (uint)*(ushort *)(param_1 + 2);
  }
  return 7 < uVar1;
}

