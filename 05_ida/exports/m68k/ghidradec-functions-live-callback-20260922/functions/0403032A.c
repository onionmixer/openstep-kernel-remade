
int _xdr_array(int *param_1,int *param_2,uint *param_3,uint param_4,int param_5,code *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  undefined *puVar7;
  
  iVar3 = *param_2;
  iVar5 = 1;
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 == 0) {
    puVar7 = aXdrArraySizeFa;
  }
  else {
    uVar1 = *param_3;
    if ((uVar1 <= param_4) || (*param_1 == 2)) {
      iVar2 = param_5 * uVar1;
      if (iVar3 == 0) {
        if (*param_1 == 1) {
          if (uVar1 == 0) {
            return 1;
          }
          iVar3 = _kalloc(iVar2);
          *param_2 = iVar3;
          _bzero(iVar3,iVar2);
        }
        else if (*param_1 == 2) {
          return 1;
        }
      }
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          bVar6 = iVar5 == 0;
          iVar5 = 0;
          if (bVar6) break;
          iVar5 = (*param_6)(param_1,iVar3,0xffffffff);
          iVar3 = param_5 + iVar3;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      if (*param_1 == 2) {
        _kfree(*param_2,iVar2);
        *param_2 = 0;
        return iVar5;
      }
      return iVar5;
    }
    puVar7 = aXdrArrayBadSiz;
  }
  _printf(puVar7);
  return 0;
}

