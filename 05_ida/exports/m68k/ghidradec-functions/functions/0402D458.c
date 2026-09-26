
undefined4 _xdr_getrddirres(undefined4 param_1,int param_2)

{
  word *pwVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_c = 0xffffffff;
  iVar2 = _xdr_enum(param_1,(int *)(param_2 + 4));
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 4) != 0) {
      return 1;
    }
    uVar4 = *(uint *)(param_2 + 0xc);
    iVar2 = *(int *)(param_2 + 0x14);
    while (iVar3 = _xdr_bool(param_1,&iStack_8), iVar3 != 0) {
      if (iStack_8 == 0) {
        iVar3 = _xdr_bool(param_1,param_2 + 0x10);
        if (iVar3 == 0) {
          return 0;
        }
        *(int *)(param_2 + 0xc) = iVar2 - *(int *)(param_2 + 0x14);
        *(undefined4 *)(param_2 + 8) = uStack_c;
        return 1;
      }
      if ((int)uVar4 < 6) {
        return 0;
      }
      iVar3 = _xdr_u_long(param_1,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
      pwVar1 = (word *)(iVar2 + 6);
      iVar3 = _xdr_u_short(param_1,pwVar1);
      if (iVar3 == 0) {
        return 0;
      }
      if (uVar4 < (*pwVar1 + 0xc & 0xfffffffc)) {
        return 0;
      }
      iVar3 = _xdr_opaque(param_1,iVar2 + 8,(uint)*pwVar1);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_u_long(param_1,&uStack_c);
      if (iVar3 == 0) {
        return 0;
      }
      *(word *)(iVar2 + 4) = *pwVar1 + 0xc & 0xfffc;
      *(undefined *)(iVar2 + 8 + (uint)*pwVar1) = 0;
      uVar4 = uVar4 - *(word *)(iVar2 + 4);
      if ((int)uVar4 < 0) {
        return 0;
      }
      iVar2 = (uint)*(word *)(iVar2 + 4) + iVar2;
    }
  }
  return 0;
}
