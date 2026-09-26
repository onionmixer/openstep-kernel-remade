
/* WARNING: Removing unreachable block (ram,0xf00ec450) */

undefined8 _object_reallocFromZone(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)__zoneRealloc)(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}

