
undefined4 _xdr_reference(int *param_1,int *param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    if (*param_1 == 1) {
      iVar1 = _kalloc(param_3);
      *param_2 = iVar1;
      _bzero(iVar1,param_3);
    }
    else if (*param_1 == 2) {
      return 1;
    }
  }
  uVar2 = (*param_4)(param_1,iVar1,0xffffffff);
  if (*param_1 == 2) {
    _kfree(iVar1,param_3);
    *param_2 = 0;
  }
  return uVar2;
}

