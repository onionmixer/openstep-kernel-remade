/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011df54 */

void _vn_rele(int param_1)

{
  short sVar1;
  
  if (*(short *)(param_1 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vn_rele_001db786);
  }
  sVar1 = *(short *)(param_1 + 6);
  *(short *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x4c))(param_1,*(undefined4 *)(_active_u + 0x1c));
  }
  return;
}

