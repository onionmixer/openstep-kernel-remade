
void __internal_object_reallocFromZone(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    ___objc_error(0,"reallocating nil object",0);
  }
  iVar1 = __objc_getFreedObjectClass();
  if (*param_1 == iVar1) {
                    /* WARNING: Subroutine does not return */
    ___objc_error(param_1,"reallocating freed object",0);
  }
  if (param_2 < *(uint *)(*param_1 + 0x14)) {
    uVar2 = _object_getClassName(param_1,param_2);
                    /* WARNING: Subroutine does not return */
    ___objc_error(param_1,"(%s, %u) requested size too small",uVar2);
  }
  iVar1 = *param_1;
  iVar3 = __objc_getFreedObjectClass();
  *param_1 = iVar3;
  piVar4 = (int *)(*(code *)*param_3)(param_3,param_1,param_2);
  if (piVar4 == (int *)0x0) {
    uVar2 = _object_getClassName(param_1,param_2);
                    /* WARNING: Subroutine does not return */
    ___objc_error(param_1,"failed -- out of memory(%s, %u)",uVar2);
  }
  *piVar4 = iVar1;
  return;
}

