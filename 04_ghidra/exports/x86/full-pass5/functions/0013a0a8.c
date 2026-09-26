/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a0a8 */

void FUN_0013a0a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 0x28) != 4) {
                    /* WARNING: Subroutine does not return */
    _panic(s_spec_ioctl_001dd79d);
  }
  (*(code *)(&PTR__cnioctl_001e2f48)[(uint)*(byte *)(*(int *)(param_1 + 0x30) + 0x43) * 0xb])
            ((int)*(short *)(*(int *)(param_1 + 0x30) + 0x42),param_2,param_3,param_4);
  return;
}

