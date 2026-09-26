/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011aa80 */

void _biowait(byte *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar3 = _splhigh();
  bVar1 = *param_1;
  while ((bVar1 & 2) == 0) {
    _sleep((uint)param_1);
    bVar1 = *param_1;
  }
  _splx(uVar3);
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar2 = _geterror(param_1);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  }
  return;
}

