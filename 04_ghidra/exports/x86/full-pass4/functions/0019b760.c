/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019b760 */

undefined4 * _VGAAllocateConsole(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)_IOMalloc(0x20);
  puVar2 = (undefined4 *)_IOMalloc(0x104);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[7] = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      _IOFree(puVar1,0x20);
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = FUN_0019b81c;
      puVar1[1] = FUN_0019ab88;
      puVar1[2] = FUN_0019ae0c;
      puVar1[3] = FUN_0019b340;
      puVar1[4] = FUN_0019b860;
      puVar1[5] = FUN_0019b9c8;
      puVar1[6] = FUN_0019b9e0;
      puVar4 = puVar2;
      for (iVar3 = 0x22; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *param_1;
        param_1 = param_1 + 1;
      }
      puVar2[0x40] = 0;
      puVar2[6] = 0xa0000;
      puVar2[3] = 0x280;
      puVar2[4] = 0x50;
      puVar2[0x31] = puVar2[2] * 0x50 + puVar2[6];
      *puVar2 = 0;
    }
  }
  return puVar1;
}

