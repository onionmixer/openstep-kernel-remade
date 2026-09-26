/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162444 */

bool FUN_00162444(byte *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  short local_8 [2];
  
  uVar1 = *param_2;
  if (0xf < uVar1) {
    *param_1 = *param_1 | 0x80;
    param_1[2] = 0xc;
    param_1[3] = 0;
    uVar2 = _kdp_machine_read_regs
                      (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_1 + 0xc,
                       local_8);
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + local_8[0];
    *param_3 = _kdp;
    *param_2 = (uint)*(ushort *)(param_1 + 2);
  }
  return 0xf < uVar1;
}

