
/* WARNING: Removing unreachable block (ram,0xf00eb740) */
/* WARNING: Removing unreachable block (ram,0xf00eb77c) */

undefined8 FUN_f00eb740(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = param_1;
  (*(code *)__alloc)(param_1,0);
  if (1 < *(int *)(*param_1 + 0xc)) {
    _objc_msgSend(piVar1,PTR_s_init_f014102c);
  }
  return CONCAT44(param_2,piVar1);
}

