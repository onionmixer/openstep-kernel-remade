/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001caf74 */

void FUN_001caf74(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  pvVar1 = _malloc(8);
  _free(pvVar1);
  iVar2 = _NXDefaultMallocZone();
  uVar3 = _NXDefaultMallocZone(0x14);
  puVar4 = (undefined4 *)(**(code **)(iVar2 + 4))(uVar3);
  DAT_001e5554 = puVar4;
  *puVar4 = &PTR_FUN_001e5544;
  puVar4[1] = 1;
  puVar4[2] = 1;
  uVar3 = _NXDefaultMallocZone(1,8);
  uVar3 = _NXZoneCalloc(uVar3);
  puVar4 = DAT_001e5554;
  DAT_001e5554[3] = uVar3;
  puVar4[4] = 0;
  *(undefined4 *)puVar4[3] = 1;
  *(undefined ***)(puVar4[3] + 4) = &PTR_FUN_001e5544;
  return;
}

