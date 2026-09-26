
undefined4 _km_run_pcode(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint unaff_D5;
  int iVar4;
  int iVar5;
  int unaff_A3;
  int unaff_A4;
  int unaff_A5;
  uint auStack_24 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = (int)byte_40B6964;
loc_4071E9C:
  uVar1 = sub_4071A12(param_1);
  uVar3 = param_1 + 1;
  if ((int)uVar1 < 0) {
    unaff_D5 = sub_4071A12(param_1 + 1);
    uVar3 = param_1 + 2;
  }
  param_1 = uVar3;
  switch(uVar1 >> 0x1a) {
  case :
    goto loc_407225A;
  case :
    uVar3 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    if ((uVar3 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
    goto loc_4071FC8;
  case :
    uVar3 = auStack_24[(uVar1 & 0x7ffff) >> 0x10];
    if ((uVar3 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
    goto loc_4072028;
  case :
    uVar1 = uVar1 & 0x3ffffff;
    do {
      iVar5 = param_1 + 1;
      unaff_D5 = sub_4071A12(param_1);
      param_1 = param_1 + 2;
      uVar3 = sub_4071A12(iVar5);
      if ((uVar3 & 0xff000000) == 0xf0000000) {
        iVar5 = 0x18;
      }
      else {
        iVar5 = 0x1c;
      }
      puVar2 = (uint *)_km_convert_addr(uVar3 | iVar4 << iVar5);
      *puVar2 = unaff_D5;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] + auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0xffffff) >> 0x15] - auStack_24[(uVar1 & 0x7ffff) >> 0x10];
    goto loc_4071E9C;
  case :
    unaff_A4 = 0;
    unaff_A3 = 0;
    unaff_A5 = 0;
    unaff_D5 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    if (unaff_D5 == 0) {
      unaff_A4 = 1;
    }
    else if ((int)unaff_D5 < 1) {
      unaff_A5 = 1;
    }
    else {
      unaff_A3 = 1;
    }
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] & auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] | auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] ^ auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0xffffff) >> 0x15] << ((uVar1 & 0x1fffff) >> 0x10);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         (int)auStack_24[(uVar1 & 0xffffff) >> 0x15] >> ((uVar1 & 0x1fffff) >> 0x10);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    goto loc_407224A;
  case :
    iVar5 = unaff_A3;
    break;
  case :
    iVar5 = unaff_A5;
    break;
  case :
    iVar5 = unaff_A4;
    break;
  case :
    iVar5 = unaff_A3;
    goto joined_r0x04072246;
  case :
    iVar5 = unaff_A5;
    goto joined_r0x04072246;
  case :
    iVar5 = unaff_A4;
joined_r0x04072246:
    if (iVar5 == 0) goto loc_407224A;
  :
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5;
    goto loc_4071E9C;
  case :
    uVar3 = unaff_D5;
    if ((unaff_D5 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
loc_4071FC8:
    puVar2 = (uint *)_km_convert_addr(iVar4 << iVar5 | uVar3);
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = *puVar2;
    goto loc_4071E9C;
  case :
    uVar3 = unaff_D5;
    if ((unaff_D5 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
loc_4072028:
    puVar2 = (uint *)_km_convert_addr(iVar4 << iVar5 | uVar3);
    *puVar2 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] + unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] - unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5 - auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] & unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] | unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5 ^ auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  }
  if (iVar5 != 0) {
loc_407224A:
    param_1 = uVar1 & 0x3ffffff;
  }
  goto loc_4071E9C;
loc_407225A:
  return auStack_24[0];
}

