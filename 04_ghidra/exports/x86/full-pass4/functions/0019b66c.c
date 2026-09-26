/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019b66c */

undefined4 * _SVGAAllocateConsole(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  
  uStack_18 = 0x20;
  puStack_1c = (undefined4 *)0x19b67c;
  puVar1 = (undefined4 *)_IOMalloc();
  puStack_1c = (undefined4 *)0x104;
  uStack_20 = 0x19b68b;
  puVar2 = (undefined4 *)_IOMalloc();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[7] = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uStack_18 = 0x20;
      ppuVar4 = &puStack_1c;
      puStack_1c = puVar1;
    }
    else {
      *puVar1 = FUN_0019b81c;
      puVar1[1] = FUN_0019ab88;
      puVar1[2] = FUN_0019ae0c;
      puVar1[3] = FUN_0019b340;
      puVar1[4] = FUN_0019b860;
      puVar1[5] = FUN_0019b9c8;
      puVar1[6] = FUN_0019b9e0;
      puVar5 = puVar2;
      for (iVar3 = 0x22; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *param_1;
        param_1 = param_1 + 1;
      }
      puVar2[0x40] = 1;
      puVar2[2] = 0x200;
      puVar2[6] = 0xa0000;
      puVar2[3] = 0x400;
      puVar2[4] = 0x80;
      uStack_18 = 0x30000;
      puStack_1c = (undefined4 *)0x19b723;
      iVar3 = _IOMalloc();
      puVar2[0x31] = iVar3;
      if (iVar3 != 0) {
        *puVar2 = 0;
        return puVar1;
      }
      uStack_18 = 0x20;
      uStack_20 = 0x19b73b;
      puStack_1c = puVar1;
      _IOFree();
      uStack_20 = 0x104;
      ppuVar4 = &puStack_24;
      puStack_24 = puVar2;
    }
    *(undefined4 *)((int)ppuVar4 + -4) = 0x19b746;
    _IOFree();
  }
  return (undefined4 *)0x0;
}

