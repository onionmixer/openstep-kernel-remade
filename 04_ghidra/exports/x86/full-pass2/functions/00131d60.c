/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131d60 */

int FUN_00131d60(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  _rlock(iVar1);
  FUN_00133824(param_1);
  _runlock(iVar1);
  return (int)*(short *)(iVar1 + 0x62);
}

