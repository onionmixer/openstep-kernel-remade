/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135378 */

void _clntkudp_realloc(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _bcopy(*(void **)(iVar1 + 0x68),param_2,0x2260);
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  *(void **)(iVar1 + 0x68) = param_2;
  return;
}

