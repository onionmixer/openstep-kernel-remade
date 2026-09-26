
/* WARNING: Removing unreachable block (ram,0xf00424f4) */
/* WARNING: Removing unreachable block (ram,0xf00424e4) */
/* WARNING: Removing unreachable block (ram,0xf00424e8) */

undefined8 _authkern_create(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x28;
  _kalloc();
  _blkclr(puVar1,0x28);
  puVar1[8] = &PTR__authkern_nextverf_f010d988;
  *puVar1 = 1;
  puVar1[3] = __null_auth;
  puVar1[4] = DAT_f013ac24;
  puVar1[5] = DAT_f013ac28;
  return CONCAT44(param_2,puVar1);
}

