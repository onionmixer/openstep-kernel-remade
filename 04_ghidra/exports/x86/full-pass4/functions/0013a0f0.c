/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a0f0 */

void FUN_0013a0f0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x28) != 4) {
                    /* WARNING: Subroutine does not return */
    _panic(s_spec_select_001dd7a8);
  }
  (*(code *)(&PTR__cnselect_001e2f54)[(uint)*(byte *)(*(int *)(param_1 + 0x30) + 0x43) * 0xb])
            ((int)*(short *)(*(int *)(param_1 + 0x30) + 0x42),param_2);
  return;
}

