
undefined4 _IOSetThreadPolicy(void *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 == 2) {
    iVar1 = _min_quantum;
  }
  iVar1 = _thread_policy(param_1,param_2,iVar1);
  if (iVar1 == 4) {
    return 0xfffffd3e;
  }
  if (iVar1 != 5) {
    return 0;
  }
  return 0xfffffd3f;
}

