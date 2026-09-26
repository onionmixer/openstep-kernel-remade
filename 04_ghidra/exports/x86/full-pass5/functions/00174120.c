/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174120 */

undefined4 _copyoutmap(int param_1,void *param_2,void *param_3,size_t param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) == _kernel_pmap) {
    _bcopy(param_2,param_3,param_4);
    uVar1 = 0;
  }
  else if (*(int *)(*(int *)(_active_threads + 0xc) + 0xc) == param_1) {
    uVar1 = _copyout(param_2,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

