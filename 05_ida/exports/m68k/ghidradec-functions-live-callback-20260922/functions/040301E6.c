
undefined4 _xdr_union(undefined4 param_1,int *param_2,undefined4 param_3,int *param_4,code *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    _printf(aXdrEnumDscmpFa);
    uVar2 = 0;
  }
  else {
    iVar1 = param_4[1];
    while (iVar1 != 0) {
      if (*param_2 == *param_4) {
        uVar2 = (*(code *)param_4[1])(param_1,param_3,0xffffffff);
        return uVar2;
      }
      iVar1 = param_4[3];
      param_4 = param_4 + 2;
    }
    if (param_5 == (code *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*param_5)(param_1,param_3,0xffffffff);
    }
  }
  return uVar2;
}

