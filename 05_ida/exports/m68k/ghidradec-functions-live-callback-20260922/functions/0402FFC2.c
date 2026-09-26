
undefined4 _xdr_bool(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int iStack_8;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = (**(code **)param_1[1])(param_1,&iStack_8);
    if (iVar2 != 0) {
      *param_2 = -(int)-(iStack_8 != 0);
      return 1;
    }
    puVar3 = aXdrBoolDecodeF;
  }
  else {
    if (iVar2 == 0) {
      iStack_8 = -(int)-(*param_2 != 0);
      uVar1 = (**(code **)(param_1[1] + 4))(param_1,&iStack_8);
      return uVar1;
    }
    if (iVar2 == 2) {
      return 1;
    }
    puVar3 = aXdrBoolBadOpFa;
  }
  _printf(puVar3);
  return 0;
}

