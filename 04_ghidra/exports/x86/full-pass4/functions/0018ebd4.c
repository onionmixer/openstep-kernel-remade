/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ebd4 */

void _pcb_terminate(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  _fp_terminate(param_1);
  if (*(int *)(iVar1 + 0xec) != 0) {
    _PCdestroy(param_1);
  }
  if (*(int *)(iVar1 + 0x70) != 0) {
    _kfree(*(int *)(iVar1 + 0x70),0xe0);
  }
  if ((*(byte *)(iVar1 + 0xf0) & 4) != 0) {
    _kfree(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc));
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  _zfree(_pcb_zone,iVar1);
  return;
}

