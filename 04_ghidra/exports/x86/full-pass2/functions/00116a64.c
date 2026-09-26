/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116a64 */

void _sbflush(short *param_1)

{
  if ((*(byte *)(param_1 + 10) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_sbflush_001db372);
  }
  while (param_1[2] != 0) {
    _sbdrop(param_1,*param_1);
  }
  if (((*param_1 == 0) && (param_1[2] == 0)) && (*(int *)(param_1 + 6) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_sbflush_2_001db37a);
}

