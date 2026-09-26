
/* WARNING: Removing unreachable block (ram,0xf00eb790) */
/* WARNING: Removing unreachable block (ram,0xf00eb794) */

undefined8 FUN_f00eb790(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_1;
  _NXDefaultMallocZone();
  (*(code *)__zoneAlloc)(param_1,0,uVar1);
  return CONCAT44(param_2,param_1);
}

