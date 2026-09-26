/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011fb48 */

int FUN_0011fb48(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _if_private(param_1);
  iVar1 = _if_getbuf(*(undefined4 *)(iVar1 + 0xc));
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _nb_shrink_top(iVar1,0xe);
  }
  return iVar1;
}

