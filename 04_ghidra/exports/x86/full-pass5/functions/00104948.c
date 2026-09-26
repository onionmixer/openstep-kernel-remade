/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104948 */

void _closef(int param_1)

{
  short sVar1;
  
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 0xe);
    if (sVar1 < 2) {
      if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(s_fp_not_one_001da669);
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        (**(code **)(*(int *)(param_1 + 0x14) + 0xc))(param_1);
      }
      _crfree(*(undefined4 *)(param_1 + 0x20));
      if (*(short *)(param_1 + 0xe) != 1) {
                    /* WARNING: Subroutine does not return */
        _panic(s_fp_not_one2_001da675);
      }
      *(undefined2 *)(param_1 + 0xe) = 0;
      _free_file(param_1);
    }
    else {
      *(short *)(param_1 + 0xe) = sVar1 + -1;
    }
  }
  return;
}

