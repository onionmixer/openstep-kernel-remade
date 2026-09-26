
undefined4 _kern_serv_call_proc(undefined4 param_1,code *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == (code *)0x0) {
    uVar1 = 100;
  }
  else {
    (*param_2)(param_3);
    uVar1 = 0;
  }
  return uVar1;
}

