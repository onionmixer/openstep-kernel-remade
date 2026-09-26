
/* WARNING: Removing unreachable block (ram,0xf00ee270) */
/* WARNING: Removing unreachable block (ram,0xf00ee204) */
/* WARNING: Removing unreachable block (ram,0xf00ee25c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _NXUniqueStringNoCopy(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  DAT_f012f088 = DAT_f012f088 + 1;
  if (DAT_f012f084 == (undefined4 *)0x0) {
    local_18 = __NXStrPrototype;
    local_14 = uRamf00f0a9c;
    local_10 = uRamf00f0aa0;
    local_c = uRamf00f0aa4;
    puVar1 = &local_18;
    _NXCreateHashTable(puVar1,0,0);
    DAT_f012f084 = puVar1;
  }
  puVar1 = DAT_f012f084;
  _NXHashInsertIfAbsent(DAT_f012f084,param_1);
  return CONCAT44(param_2,puVar1);
}

