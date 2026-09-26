
undefined4 _xdr_string(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uStack_8;
  
  iVar2 = *param_2;
  if (*param_1 == 0) {
loc_4030288:
    uStack_8 = _strlen(iVar2);
  }
  else if (*param_1 == 2) {
    if (iVar2 == 0) {
      return 1;
    }
    goto loc_4030288;
  }
  iVar1 = _xdr_u_int(param_1,&uStack_8);
  if (iVar1 == 0) {
    puVar4 = aXdrStringSizeF;
  }
  else {
    if (uStack_8 <= param_3) {
      iVar1 = *param_1;
      if (iVar1 == 1) {
        if (iVar2 == 0) {
          iVar2 = _kalloc(uStack_8 + 1);
          *param_2 = iVar2;
        }
        *(undefined *)(iVar2 + uStack_8) = 0;
      }
      else if (iVar1 != 0) {
        if (iVar1 == 2) {
          _kfree(iVar2,uStack_8 + 1);
          *param_2 = 0;
          return 1;
        }
        puVar4 = aXdrStringBadOp;
        goto loc_4030318;
      }
      uVar3 = _xdr_opaque(param_1,iVar2,uStack_8);
      return uVar3;
    }
    puVar4 = aXdrStringBadSi;
  }
loc_4030318:
  _printf(puVar4);
  return 0;
}
