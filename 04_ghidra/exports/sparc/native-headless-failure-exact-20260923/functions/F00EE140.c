
/* WARNING: Removing unreachable block (ram,0xf00ee1c8) */
/* WARNING: Removing unreachable block (ram,0xf00ee1f0) */
/* WARNING: Removing unreachable block (ram,0xf00ee140) */
/* WARNING: Removing unreachable block (ram,0xf00ee1dc) */
/* WARNING: Removing unreachable block (ram,0xf00ee1b4) */
/* WARNING: Removing unreachable block (ram,0xf00ee1a0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _NXUniqueString(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1 != (undefined4 *)0x0) {
    DAT_f012f088 = DAT_f012f088 + 1;
    if (DAT_f012f084 == (undefined4 *)0x0) {
      local_18 = __NXStrPrototype;
      local_14 = uRamf00f0a9c;
      local_10 = uRamf00f0aa0;
      local_c = uRamf00f0aa4;
      puVar2 = &local_18;
      _NXCreateHashTable(puVar2,0,0);
      DAT_f012f084 = puVar2;
    }
    puVar2 = DAT_f012f084;
    _NXHashGet(DAT_f012f084,param_1);
    if (puVar2 != (undefined4 *)0x0) goto LAB_f00ee1fc;
    FUN_f00ee030(param_1);
    puVar1 = DAT_f012f084;
    _NXHashInsert(DAT_f012f084,param_1);
    puVar2 = param_1;
    if (puVar1 == (undefined4 *)0x0) goto LAB_f00ee1fc;
    __NXLogError("*** NXUniqueString: invariant broken\n");
  }
  puVar2 = (undefined4 *)0x0;
LAB_f00ee1fc:
  return CONCAT44(param_2,puVar2);
}

