
/* WARNING: Removing unreachable block (ram,0xf00ec430) */

undefined8 _object_realloc(undefined4 param_1,undefined4 param_2)

{
  (*(code *)__realloc)(param_1,param_2);
  return CONCAT44(param_2,param_1);
}

