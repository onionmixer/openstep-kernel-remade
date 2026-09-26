/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccedc */

void __class_removeProtocols(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*(undefined4 **)(param_1 + 0x24) == param_2) {
    *(undefined4 *)(param_1 + 0x24) = *param_2;
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    if (puVar2 == param_2) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar1 = *puVar2;
  return;
}

