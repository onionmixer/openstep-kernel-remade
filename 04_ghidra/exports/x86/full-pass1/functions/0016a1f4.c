/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a1f4 */

uint _timer_normalize(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  param_1[2] = param_1[2] + uVar1 / 1000000;
  uVar2 = *param_1;
  *param_1 = uVar2 % 1000000;
  param_1[1] = param_1[1] + uVar1 / 1000000;
  return uVar2 / 1000000;
}

