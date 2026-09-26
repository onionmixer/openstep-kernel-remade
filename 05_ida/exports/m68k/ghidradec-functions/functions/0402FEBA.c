
undefined4 _xdr_short(int *param_1,sword *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = (**(code **)param_1[1])(param_1,&uStack_8);
    if (iVar2 != 0) {
      *param_2 = uStack_8._2_2_;
      return 1;
    }
  }
  else {
    if (iVar2 == 0) {
      uStack_8 = (int)*param_2;
      uVar1 = (**(code **)(param_1[1] + 4))(param_1,&uStack_8);
      return uVar1;
    }
    if (iVar2 == 2) {
      return 1;
    }
  }
  return 0;
}
