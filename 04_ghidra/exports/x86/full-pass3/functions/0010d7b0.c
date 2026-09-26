/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d7b0 */

void _selthreadclear(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_selthreadclear_not_passed_an_add_001dacb4);
  }
  if (*param_1 != 0) {
    _thread_deallocate_interrupt(*param_1);
  }
  *param_1 = 0;
  return;
}

