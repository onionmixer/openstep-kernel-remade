
/* WARNING: Removing unreachable block (ram,0xf00ec204) */
/* WARNING: Removing unreachable block (ram,0xf00ec23c) */

undefined8 __internal_object_copyFromZone(int *param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (void *)*param_1;
    (*(code *)__zoneAlloc)(pvVar1,param_2,param_3);
    _memmove(pvVar1,param_1,param_2 + *(int *)(*param_1 + 0x14));
  }
  return CONCAT44(param_2,pvVar1);
}

