
undefined4 _get_kern_port(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    *param_3 = 0;
  }
  else {
    iVar1 = _object_copyin(param_1,param_2,6,0,param_3);
    if (iVar1 == 0) {
      return 4;
    }
  }
  return 0;
}
