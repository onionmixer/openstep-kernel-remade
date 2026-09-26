
undefined4 _xdr_callmsg(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (*param_1 == 0) {
    if (400 < (uint)param_2[8]) {
      return 0;
    }
    if (400 < (uint)param_2[0xb]) {
      return 0;
    }
    puVar2 = (undefined4 *)
             (**(code **)(param_1[1] + 0x18))
                       (param_1,(param_2[0xb] + 3 & 0xfffffffc) + 0x28 +
                                (param_2[8] + 3 & 0xfffffffc));
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *param_2;
      iVar4 = param_2[1];
      puVar2[1] = iVar4;
      if (iVar4 != 0) {
        return 0;
      }
      puVar2[2] = param_2[2];
      if (param_2[2] != 2) {
        return 0;
      }
      puVar2[3] = param_2[3];
      puVar2[4] = param_2[4];
      puVar2[5] = param_2[5];
      puVar2[6] = param_2[6];
      puVar5 = puVar2 + 8;
      puVar2[7] = param_2[8];
      if (param_2[8] != 0) {
        _bcopy(param_2[7],puVar5,param_2[8]);
        puVar5 = (undefined4 *)((param_2[8] + 3 & 0xfffffffc) + (int)puVar5);
      }
      *puVar5 = param_2[9];
      puVar2 = puVar5 + 2;
      puVar5[1] = param_2[0xb];
      iVar6 = param_2[0xb];
      if (iVar6 == 0) {
        return 1;
      }
      iVar4 = param_2[10];
      goto loc_402EBC4;
    }
  }
  if ((*param_1 != 1) ||
     (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x20),
     puVar2 == (undefined4 *)0x0)) {
    iVar4 = _xdr_u_long(param_1,param_2);
    if (iVar4 != 0) {
      iVar4 = _xdr_enum(param_1,param_2 + 1);
      if ((iVar4 != 0) && (param_2[1] == 0)) {
        iVar4 = _xdr_u_long(param_1,param_2 + 2);
        if (((iVar4 != 0) &&
            (((param_2[2] == 2 && (iVar4 = _xdr_u_long(param_1,param_2 + 3), iVar4 != 0)) &&
             (iVar4 = _xdr_u_long(param_1,param_2 + 4), iVar4 != 0)))) &&
           ((iVar4 = _xdr_u_long(param_1,param_2 + 5), iVar4 != 0 &&
            (iVar4 = _xdr_opaque_auth(param_1,param_2 + 6), iVar4 != 0)))) {
          uVar3 = _xdr_opaque_auth(param_1,param_2 + 9);
          return uVar3;
        }
      }
    }
    return 0;
  }
  *param_2 = *puVar2;
  iVar4 = puVar2[1];
  param_2[1] = iVar4;
  if (iVar4 != 0) {
    return 0;
  }
  param_2[2] = puVar2[2];
  if (param_2[2] != 2) {
    return 0;
  }
  param_2[3] = puVar2[3];
  param_2[4] = puVar2[4];
  param_2[5] = puVar2[5];
  param_2[6] = puVar2[6];
  param_2[8] = puVar2[7];
  uVar1 = param_2[8];
  if (uVar1 != 0) {
    if (400 < uVar1) {
      return 0;
    }
    if (param_2[7] == 0) {
      uVar3 = _kalloc(uVar1);
      param_2[7] = uVar3;
    }
    iVar4 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[8] + 3 & 0xfffffffc);
    if (iVar4 == 0) {
      iVar4 = _xdr_opaque(param_1,param_2[7],param_2[8]);
      if (iVar4 == 0) {
        return 0;
      }
    }
    else {
      _bcopy(iVar4,param_2[7],param_2[8]);
    }
  }
  puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,8);
  if (puVar2 == (undefined4 *)0x0) {
    iVar4 = _xdr_enum(param_1,param_2 + 9);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = _xdr_u_int(param_1,param_2 + 0xb);
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    param_2[9] = *puVar2;
    param_2[0xb] = puVar2[1];
  }
  uVar1 = param_2[0xb];
  if (uVar1 == 0) {
    return 1;
  }
  if (400 < uVar1) {
    return 0;
  }
  if (param_2[10] == 0) {
    uVar3 = _kalloc(uVar1);
    param_2[10] = uVar3;
  }
  iVar4 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[0xb] + 3 & 0xfffffffc);
  if (iVar4 == 0) {
    iVar4 = _xdr_opaque(param_1,param_2[10],param_2[0xb]);
    if (iVar4 == 0) {
      return 0;
    }
    return 1;
  }
  iVar6 = param_2[0xb];
  puVar2 = (undefined4 *)param_2[10];
loc_402EBC4:
  _bcopy(iVar4,puVar2,iVar6);
  return 1;
}

