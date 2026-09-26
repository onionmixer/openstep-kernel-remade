/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b1e8 */

void _binval(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  
LAB_0011b1ef:
  puVar2 = (uint *)&_bufhash;
  do {
    for (puVar1 = (uint *)puVar2[1]; puVar1 != puVar2; puVar1 = (uint *)puVar1[1]) {
      if ((puVar1[0x10] == param_1) && ((*puVar1 & 0x10000) == 0)) {
        *puVar1 = *puVar1 | 0x10000;
        FUN_0011b26c(puVar1);
        goto LAB_0011b1ef;
      }
    }
    puVar2 = puVar2 + 3;
    if ((uint *)0x1e893f < puVar2) {
      return;
    }
  } while( true );
}

