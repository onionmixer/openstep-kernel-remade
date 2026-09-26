/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a280 */

uint _thread_read_times(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  do {
    uVar1 = *(uint *)(param_1 + 0xe0);
  } while (*(int *)(param_1 + 0xe8) != *(int *)(param_1 + 0xe4));
  *param_2 = uVar1 / 1000000 + *(int *)(param_1 + 0xe4);
  param_2[1] = uVar1 % 1000000;
  do {
    uVar1 = *(uint *)(param_1 + 0xf0);
  } while (*(int *)(param_1 + 0xf8) != *(int *)(param_1 + 0xf4));
  *param_3 = *(int *)(param_1 + 0xf4) + uVar1 / 1000000;
  param_3[1] = uVar1 % 1000000;
  return uVar1 / 1000000;
}

