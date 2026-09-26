/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001209ec */

int _nb_alloc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_1 + 4;
    iVar2 = _nb_alloc_wrapper(piVar1 + 1,param_1,FUN_00120b84,piVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    _kfree(piVar1,*piVar1);
  }
  return 0;
}

