
undefined4 _xdr_bytes(int *param_1,int *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  iVar3 = *param_2;
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 == 0) {
    puVar5 = aXdrBytesSizeFa;
  }
  else {
    uVar1 = *param_3;
    if ((uVar1 <= param_4) || (*param_1 == 2)) {
      iVar2 = *param_1;
      if (iVar2 == 1) {
        if (uVar1 == 0) {
          return 1;
        }
        if (iVar3 == 0) {
          iVar3 = _kalloc(uVar1);
          *param_2 = iVar3;
        }
      }
      else if (iVar2 != 0) {
        if (iVar2 == 2) {
          if (iVar3 == 0) {
            return 1;
          }
          _kfree(iVar3,uVar1);
          *param_2 = 0;
          return 1;
        }
        puVar5 = aXdrBytesBadOpF;
        goto loc_40301B4;
      }
      uVar4 = _xdr_opaque(param_1,iVar3,uVar1);
      return uVar4;
    }
    puVar5 = aXdrBytesBadSiz;
  }
loc_40301B4:
  _printf(puVar5);
  return 0;
}
