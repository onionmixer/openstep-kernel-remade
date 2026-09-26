
void _svc_unregister(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puStack_8;
  
  puVar1 = (undefined4 *)sub_402F42A(param_1,param_2,&puStack_8);
  if (puVar1 != (undefined4 *)0x0) {
    if (puStack_8 == (undefined4 *)0x0) {
      dword_40B3596 = *puVar1;
    }
    else {
      *puStack_8 = *puVar1;
    }
    *puVar1 = 0;
    _kfree(puVar1,0x10);
  }
  return;
}

