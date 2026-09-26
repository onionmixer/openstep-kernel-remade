/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ddd0 */

void _ttywait(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _spltty();
  while ((*(int *)(param_1 + 0x18) != 0 || ((*(uint *)(param_1 + 0x40) & 0x2000020) != 0))) {
    if ((*(byte *)(param_1 + 0x40) & 0x10) == 0) {
      iVar2 = _ttynty(param_1);
      if (-1 < *(short *)(iVar2 + 0x10)) break;
    }
    (**(code **)(param_1 + 0x24))(param_1);
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) | 0x40;
    _sleep(param_1 + 0x18);
  }
  _splx(uVar1);
  return;
}

