/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb328 */

undefined4 * _NXCopyHashTable(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined8 local_c;
  
  local_c = _NXInitHashState(param_1);
  iVar1 = _NXZoneFromPtr(param_1);
  puVar2 = (undefined4 *)(**(code **)(iVar1 + 4))(iVar1,0x14);
  *puVar2 = *param_1;
  puVar2[1] = 0;
  puVar2[4] = param_1[4];
  uVar3 = param_1[2];
  puVar2[2] = uVar3;
  uVar3 = _NXZoneCalloc(iVar1,uVar3,8);
  puVar2[3] = uVar3;
  while( true ) {
    iVar1 = _NXNextHashState(param_1,&local_c,&local_10);
    if (iVar1 == 0) break;
    _NXHashInsert(puVar2,local_10);
  }
  return puVar2;
}

