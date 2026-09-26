/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120aec */

undefined4 _nb_write(int param_1,int param_2,size_t param_3,void *param_4)

{
  undefined4 uVar1;
  
  if ((uint)(int)*(short *)(param_1 + 8) < param_3 + param_2) {
    uVar1 = 0xffffffff;
  }
  else {
    _bcopy(param_4,(void *)(param_1 + *(int *)(param_1 + 4) + param_2),param_3);
    uVar1 = 0;
  }
  return uVar1;
}

