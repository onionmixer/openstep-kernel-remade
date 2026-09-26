/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b43c */

void _stack_alloc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _allocStack();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_stack_alloc_001dedcd);
  }
  _stack_attach(param_1,iVar1,param_2);
  return;
}

