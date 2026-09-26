/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010372c */

void _ticks_to_timeval(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1 % _hz;
  *param_2 = param_1 / _hz;
  param_2[1] = iVar1 * _tick;
  return;
}

