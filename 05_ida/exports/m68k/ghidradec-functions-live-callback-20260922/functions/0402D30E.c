
undefined4 _xdr_putrddirres(int *param_1,uint *param_2)

{
  uint uVar1;
  word *pwVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_18;
  uint uStack_14;
  uint uStack_10;
  int *piStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 1;
  uStack_18 = 0;
  if (*param_1 == 0) {
    iVar4 = _xdr_enum(param_1,param_2 + 1);
    if (iVar4 != 0) {
      if (param_2[1] == 0) {
        iVar4 = (**(code **)(param_1[1] + 0x10))(param_1);
        uStack_14 = param_2[2];
        piVar6 = (int *)param_2[5];
        for (uVar1 = param_2[3]; 0 < (int)uVar1; uVar1 = uVar1 - *pwVar2) {
          wVar3 = *(word *)(piVar6 + 1);
          if (wVar3 == 0) {
            return 0;
          }
          if ((uint)wVar3 < *(word *)((int)piVar6 + 6) + 9) {
            return 0;
          }
          uStack_14 = wVar3 + uStack_14;
          if (*piVar6 != 0) {
            piStack_c = piVar6 + 2;
            uStack_10 = (uint)*(word *)((int)piVar6 + 6);
            iVar5 = _xdr_bool(param_1,&uStack_8);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_u_long(param_1,piVar6);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_bytes(param_1,&piStack_c,&uStack_10,0xff);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_u_long(param_1,&uStack_14);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = (**(code **)(param_1[1] + 0x10))(param_1);
            if (*param_2 <= (uint)(iVar5 - iVar4)) {
              param_2[4] = 0;
              break;
            }
          }
          pwVar2 = (word *)(piVar6 + 1);
          piVar6 = (int *)((uint)*pwVar2 + (int)piVar6);
        }
        iVar4 = _xdr_bool(param_1,&uStack_18);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = _xdr_bool(param_1,param_2 + 4);
        if (iVar4 == 0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}

