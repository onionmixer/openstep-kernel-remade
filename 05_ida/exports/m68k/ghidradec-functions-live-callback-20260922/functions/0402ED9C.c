
undefined4 _xdr_replymsg(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((((*param_1 == 0) && (param_2[2] == 0)) && (param_2[1] == 1)) &&
     (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,param_2[5] + 0x18),
     puVar2 != (undefined4 *)0x0)) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    puVar2[3] = param_2[3];
    puVar5 = puVar2 + 5;
    puVar2[4] = param_2[5];
    if (param_2[5] != 0) {
      _bcopy(param_2[4],puVar5,param_2[5]);
      puVar5 = (undefined4 *)((param_2[5] + 3 & 0xfffffffc) + (int)puVar5);
    }
    *puVar5 = param_2[6];
    if (param_2[6] == 0) {
      uVar4 = (*(code *)param_2[8])(param_1,param_2[7]);
      return uVar4;
    }
    if (param_2[6] != 2) {
      return 1;
    }
    iVar3 = _xdr_u_long(param_1,param_2 + 7);
  }
  else {
    if ((*param_1 != 1) ||
       (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0xc),
       puVar2 == (undefined4 *)0x0)) {
      iVar3 = _xdr_u_long(param_1,param_2);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_enum(param_1,param_2 + 1);
      if (iVar3 == 0) {
        return 0;
      }
      if (param_2[1] != 1) {
        return 0;
      }
      uVar4 = _xdr_union(param_1,param_2 + 2,param_2 + 3,unk_40AF026,0);
      return uVar4;
    }
    *param_2 = *puVar2;
    param_2[1] = puVar2[1];
    if (param_2[1] != 1) {
      return 0;
    }
    param_2[2] = puVar2[2];
    if (param_2[2] != 0) {
      if (param_2[2] != 1) {
        return 0;
      }
      uVar4 = _xdr_rejected_reply(param_1,param_2 + 3);
      return uVar4;
    }
    puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,8);
    if (puVar2 == (undefined4 *)0x0) {
      iVar3 = _xdr_enum(param_1,param_2 + 3);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_u_int(param_1,param_2 + 5);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      param_2[3] = *puVar2;
      param_2[5] = puVar2[1];
    }
    uVar1 = param_2[5];
    if (uVar1 != 0) {
      if (400 < uVar1) {
        return 0;
      }
      if (param_2[4] == 0) {
        uVar4 = _kalloc(uVar1);
        param_2[4] = uVar4;
      }
      iVar3 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[5] + 3 & 0xfffffffc);
      if (iVar3 == 0) {
        iVar3 = _xdr_opaque(param_1,param_2[4],param_2[5]);
        if (iVar3 == 0) {
          return 0;
        }
      }
      else {
        _bcopy(iVar3,param_2[4],param_2[5]);
      }
    }
    iVar3 = _xdr_enum(param_1,param_2 + 6);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_2[6];
    if (iVar3 == 0) {
      uVar4 = (*(code *)param_2[8])(param_1,param_2[7]);
      return uVar4;
    }
    if (iVar3 != 2) {
      return 1;
    }
    iVar3 = _xdr_u_long(param_1,param_2 + 7);
  }
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = _xdr_u_long(param_1,param_2 + 8);
  return uVar4;
}

