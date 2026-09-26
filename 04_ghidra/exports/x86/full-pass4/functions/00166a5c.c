/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166a5c */

void _stack_privilege(int param_1)

{
  if (_active_threads != param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_stack_privilege_001dfbcc);
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x30) = _active_stacks;
  }
  return;
}

