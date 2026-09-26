
undefined4 sub_402CD4E(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    puVar1 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
      puVar1[3] = param_2[3];
      puVar1[4] = param_2[4];
      puVar1[5] = param_2[5];
      puVar1[6] = param_2[6];
      puVar1[7] = param_2[7];
      puVar1[8] = param_2[8];
      puVar1[9] = param_2[9];
      puVar1[10] = param_2[10];
      puVar1[0xb] = param_2[0xb];
      puVar1[0xc] = param_2[0xc];
      puVar1[0xd] = param_2[0xd];
      puVar1[0xe] = param_2[0xe];
      puVar1[0xf] = param_2[0xf];
      puVar1[0x10] = param_2[0x10];
      return 1;
    }
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (puVar1 != (undefined4 *)0x0) {
      *param_2 = *puVar1;
      param_2[1] = puVar1[1];
      param_2[2] = puVar1[2];
      param_2[3] = puVar1[3];
      param_2[4] = puVar1[4];
      param_2[5] = puVar1[5];
      param_2[6] = puVar1[6];
      param_2[7] = puVar1[7];
      param_2[8] = puVar1[8];
      param_2[9] = puVar1[9];
      param_2[10] = puVar1[10];
      param_2[0xb] = puVar1[0xb];
      param_2[0xc] = puVar1[0xc];
      param_2[0xd] = puVar1[0xd];
      param_2[0xe] = puVar1[0xe];
      param_2[0xf] = puVar1[0xf];
      param_2[0x10] = puVar1[0x10];
      return 1;
    }
  }
  iVar2 = _xdr_enum(param_1,param_2);
  if (((((iVar2 != 0) && (iVar2 = _xdr_u_long(param_1,param_2 + 1), iVar2 != 0)) &&
       (iVar2 = _xdr_u_long(param_1,param_2 + 2), iVar2 != 0)) &&
      ((((iVar2 = _xdr_u_long(param_1,param_2 + 3), iVar2 != 0 &&
         (iVar2 = _xdr_u_long(param_1,param_2 + 4), iVar2 != 0)) &&
        ((iVar2 = _xdr_u_long(param_1,param_2 + 5), iVar2 != 0 &&
         ((iVar2 = _xdr_u_long(param_1,param_2 + 6), iVar2 != 0 &&
          (iVar2 = _xdr_u_long(param_1,param_2 + 7), iVar2 != 0)))))) &&
       (iVar2 = _xdr_u_long(param_1,param_2 + 8), iVar2 != 0)))) &&
     ((((iVar2 = _xdr_u_long(param_1,param_2 + 9), iVar2 != 0 &&
        (iVar2 = _xdr_u_long(param_1,param_2 + 10), iVar2 != 0)) &&
       (iVar2 = sub_402D624(param_1,param_2 + 0xb), iVar2 != 0)) &&
      ((iVar2 = sub_402D624(param_1,param_2 + 0xd), iVar2 != 0 &&
       (iVar2 = sub_402D624(param_1,param_2 + 0xf), iVar2 != 0)))))) {
    return 1;
  }
  return 0;
}

