/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b970 */

void _fssleep(int param_1,uint param_2)

{
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_fssleep_001dda17);
    }
    if (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90)) {
      do {
        _sleep(param_1 + 200);
      } while (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90));
    }
  }
  else if ((*(int *)(param_1 + 0xc4) << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f)) +
           *(int *)(param_1 + 0xcc) <= *(int *)(param_1 + 0x88)) {
    do {
      _sleep(param_1 + 0xcc);
    } while ((*(int *)(param_1 + 0xc4) << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f)) +
             *(int *)(param_1 + 0xcc) <= *(int *)(param_1 + 0x88));
  }
  return;
}

