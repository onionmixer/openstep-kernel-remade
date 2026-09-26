/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010df2c */

void _ttstart(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _spltty();
  if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) && (*(code **)(param_1 + 0x24) != (code *)0x0))
  {
    (**(code **)(param_1 + 0x24))(param_1);
  }
  _splx(uVar1);
  return;
}

