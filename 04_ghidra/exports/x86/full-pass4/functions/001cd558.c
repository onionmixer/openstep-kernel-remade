/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd558 */

void __cache_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = _NXDefaultMallocZone();
  uVar2 = _NXDefaultMallocZone(0x18);
  puVar3 = (undefined4 *)(**(code **)(iVar1 + 4))(uVar2);
  iVar1 = 0;
  do {
    puVar3[iVar1 + 2] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  puVar3[1] = 0;
  *puVar3 = 3;
  *(undefined4 **)(param_1 + 0x20) = puVar3;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
  if (DAT_001e55a8 != 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffbf;
  }
  return;
}

