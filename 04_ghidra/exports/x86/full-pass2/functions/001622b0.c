/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001622b0 */

undefined4 FUN_001622b0(byte *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*param_2 < 0x10) {
    uVar2 = 0;
  }
  else {
    *param_1 = *param_1 | 0x80;
    param_1[2] = 0xc;
    param_1[3] = 0;
    uVar1 = *(uint *)(param_1 + 0xc);
    if (uVar1 < 0x401) {
      _copywithin(*(undefined4 *)(param_1 + 8),param_1 + 0xc,uVar1);
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + (short)uVar1;
    }
    else {
      param_1[8] = 2;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
    }
    *param_3 = _kdp;
    *param_2 = (uint)*(ushort *)(param_1 + 2);
    uVar2 = 1;
  }
  return uVar2;
}

