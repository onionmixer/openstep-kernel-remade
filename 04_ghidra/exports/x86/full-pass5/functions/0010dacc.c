/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010dacc */

undefined4 _soo_close(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar1 = _soclose(*(int *)(param_1 + 0x18));
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return uVar1;
}

