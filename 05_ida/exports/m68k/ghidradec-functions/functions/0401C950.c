
int _nb_alloc_wrapper(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _mclgetx(param_3,param_4,param_1,param_2,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}
