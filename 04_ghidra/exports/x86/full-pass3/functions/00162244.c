/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162244 */

undefined4 FUN_00162244(byte *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  
  if (*param_2 < 0x10) {
    uVar1 = 0;
  }
  else {
    if (*(uint *)(param_1 + 0xc) < 0x401) {
      _copywithin(param_1 + 0x10,*(undefined4 *)(param_1 + 8),*(uint *)(param_1 + 0xc));
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
    }
    else {
      param_1[8] = 2;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
    }
    *param_1 = *param_1 | 0x80;
    param_1[2] = 0xc;
    param_1[3] = 0;
    *param_3 = _kdp;
    *param_2 = (uint)*(ushort *)(param_1 + 2);
    uVar1 = 1;
  }
  return uVar1;
}

