
undefined4 _copyoutmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == _kernel_pmap) {
    _bcopy(param_2,param_3,param_4);
    uVar1 = 0;
  }
  else if (param_1 == *(int *)(*(int *)(_active_threads + 0xc) + 8)) {
    uVar1 = _copyoutmsg(param_2,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

