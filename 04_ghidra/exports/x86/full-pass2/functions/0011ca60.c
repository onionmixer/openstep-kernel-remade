/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ca60 */

undefined4 _pn_combine(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(*(int *)(param_2 + 8) + param_1[2]) < 0x400) {
    _ovbcopy(param_1[1],*param_1 + *(int *)(param_2 + 8),param_1[2]);
    _bcopy(*(void **)(param_2 + 4),(void *)*param_1,*(size_t *)(param_2 + 8));
    param_1[2] = param_1[2] + *(int *)(param_2 + 8);
    param_1[1] = *param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f;
  }
  return uVar1;
}

