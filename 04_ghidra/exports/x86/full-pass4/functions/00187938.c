/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187938 */

void FUN_00187938(undefined4 *param_1)

{
  _clock_interrupt(_tick,param_1[1] == 3,param_1[2] == 0);
  _hardclock(*param_1,param_1[2] << 8 | param_1[1]);
  return;
}

