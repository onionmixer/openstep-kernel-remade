/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd7ec */

void FUN_001cd7ec(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_1 + 0x20);
  if (puVar1 != (uint *)&_emptyCache) {
    uVar4 = 0;
    do {
      if ((puVar1[uVar4 + 2] != 0) && (*(code **)(puVar1[uVar4 + 2] + 8) == __objc_msgForward)) {
        iVar2 = _NXDefaultMallocZone();
        uVar3 = _NXDefaultMallocZone(puVar1[uVar4 + 2]);
        (**(code **)(iVar2 + 8))(uVar3);
      }
      puVar1[uVar4 + 2] = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *puVar1);
    puVar1[1] = 0;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
  }
  return;
}

