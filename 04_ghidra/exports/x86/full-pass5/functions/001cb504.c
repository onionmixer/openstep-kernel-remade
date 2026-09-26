/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb504 */

void FUN_001cb504(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined8 local_c;
  
  iVar1 = _NXZoneFromPtr(param_1);
  puVar2 = (undefined4 *)(**(code **)(iVar1 + 4))(iVar1,0x14);
  *puVar2 = *param_1;
  puVar2[1] = param_1[1];
  puVar2[2] = param_1[2];
  puVar2[3] = param_1[3];
  param_1[2] = param_1[2] + param_1[2] + 1;
  param_1[1] = 0;
  uVar3 = _NXZoneCalloc(iVar1,param_1[2],8);
  param_1[3] = uVar3;
  local_c = _NXInitHashState(puVar2);
  while( true ) {
    iVar1 = _NXNextHashState(puVar2,&local_c,&local_10);
    if (iVar1 == 0) break;
    _NXHashInsert(param_1,local_10);
  }
  FUN_001cb174(puVar2,0);
  if (param_1[1] != puVar2[1]) {
    __NXLogError(
                "*** hashtable: count differs after rehashing; probably indicates a broken invariant: there are x and y such as isEqual(x, y) is TRUE but hash(x) != hash (y)\n"
                );
  }
  _free((void *)puVar2[3]);
  _free(puVar2);
  return;
}

