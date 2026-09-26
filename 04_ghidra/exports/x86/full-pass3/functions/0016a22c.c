/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a22c */

uint _timer_read(uint *param_1,int *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
  } while (param_1[2] != param_1[1]);
  *param_2 = uVar1 / 1000000 + param_1[1];
  param_2[1] = uVar1 % 1000000;
  return uVar1 / 1000000;
}

