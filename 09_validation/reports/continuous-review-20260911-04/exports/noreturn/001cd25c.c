
void FUN_001cd25c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _sel_getName(param_2,param_1);
                    /* WARNING: Subroutine does not return */
  ___objc_error(param_1,"message %s sent to freed object=0x%lx",uVar1);
}

