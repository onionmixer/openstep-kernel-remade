/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b158 */

void _btrash(uint param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  
LAB_0011b160:
  uVar2 = _splhigh();
  puVar3 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar3[3]; puVar1 != puVar3; puVar1 = (uint *)puVar1[3]) {
      if ((puVar1[0x10] == param_1) || (param_1 == 0)) {
        *puVar1 = *puVar1 & 0xfffffdff | 0x10000;
        FUN_0011b26c(puVar1);
        _splx(uVar2);
        goto LAB_0011b160;
      }
    }
    puVar3 = puVar3 + 0x11;
    if ((uint *)0x1e882b < puVar3) {
      _splx(uVar2);
      return;
    }
  } while( true );
}

