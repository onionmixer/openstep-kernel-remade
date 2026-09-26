/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ed10 */

void _physstrat(byte *param_1,code *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  (*param_2)(param_1);
  if ((param_1[1] & 0x20) == 0) {
    uVar2 = _splbio();
    bVar1 = *param_1;
    while ((bVar1 & 2) == 0) {
      _sleep((uint)param_1);
      bVar1 = *param_1;
    }
    _splx(uVar2);
  }
  return;
}

