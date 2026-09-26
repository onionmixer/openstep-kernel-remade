
/* WARNING: Removing unreachable block (ram,0xf00b6060) */
/* WARNING: Removing unreachable block (ram,0xf00b609c) */
/* WARNING: Removing unreachable block (ram,0xf00b5f7c) */
/* WARNING: Removing unreachable block (ram,0xf00b608c) */
/* WARNING: Removing unreachable block (ram,0xf00b6018) */
/* WARNING: Removing unreachable block (ram,0xf00b5f2c) */
/* WARNING: Removing unreachable block (ram,0xf00b5ee4) */

undefined8 _esp_handle_msg_in_done(uint param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar2 = 0;
  iVar4 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  uVar5 = 0;
  iVar3 = *(int *)(param_1 + 0x9c);
  if (*(char *)(param_1 + 0x42) == '\v') {
    uVar2 = (uint)*(byte *)(param_1 + 0x54);
  }
  else {
    if ((*(byte *)(param_1 + 0x44) & 0x20) != 0) {
      _esplog(param_1,3,aPrematureEndOf_0);
      iVar3 = 2;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
      *(undefined *)(param_1 + 0x41) = 0x1a;
      goto locret_F00B6114;
    }
    if (*(char *)(param_1 + 0x5c) == '\0') {
      bVar1 = *(byte *)(iVar3 + 0x1c);
    }
    else {
      if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
        _esplog(param_1,3,_msginperr);
        uVar5 = 9;
        *(byte *)(iVar4 + 0x2a) = *(byte *)(iVar4 + 0x2a) | 4;
        *(undefined *)(iVar3 + 0xc) = 1;
        goto loc_F00B5FD4;
      }
      bVar1 = *(byte *)(iVar3 + 0x1c);
    }
    uVar2 = bVar1 & 0x1f;
    if (uVar2 == 1) {
      if (*(char *)(param_1 + 0x5c) == '\0') {
        uVar2 = (uint)*(byte *)(iVar3 + 8);
        *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
        *(undefined *)(param_1 + 0x41) = 6;
      }
      else {
        bVar1 = *(byte *)(param_1 + 0x5d);
        *(byte *)(param_1 + 0x5d) = bVar1 + 1;
        uVar2 = (uint)*(byte *)(iVar3 + 8);
        *(byte *)(bVar1 + param_1 + 0x54) = *(byte *)(iVar3 + 8);
      }
    }
    else {
      uVar5 = 5;
      *(undefined *)(iVar3 + 0xc) = 1;
      _esplog(param_1,3,aInputMessageBo);
    }
  }
loc_F00B5FD4:
  bVar6 = false;
  if (uVar5 == 0) {
    bVar1 = *(byte *)(param_1 + 0x5c);
    bVar6 = false;
    if (bVar1 != 0) {
      if (*(byte *)(param_1 + 0x5d) < bVar1) {
        *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
        *(undefined *)(param_1 + 0x41) = 6;
      }
      else if (bVar1 == 1) {
        uVar5 = param_1;
        _esp_onebyte_msg();
      }
      else if (bVar1 == 2) {
        if (*(char *)(param_1 + 0x54) == '\x01') {
          if (8 < uVar2 + 2) {
            uVar5 = 7;
            _esplog(param_1,3,off_F011E7F4,1);
            bVar6 = false;
            goto loc_F00B60AC;
          }
          *(char *)(param_1 + 0x5c) = (char)uVar2 + '\x02';
          *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
          *(undefined *)(param_1 + 0x41) = 6;
        }
        else {
          uVar5 = param_1;
          _esp_twobyte_msg();
        }
      }
      else {
        uVar5 = param_1;
        _esp_multibyte_msg();
      }
      bVar6 = (int)uVar5 < 0;
    }
  }
loc_F00B60AC:
  if (bVar6) {
    iVar3 = -uVar5;
    goto locret_F00B6114;
  }
  if (0 < (int)uVar5) {
    if (uVar5 == 1) {
loc_F00B60E8:
      *(char *)(param_1 + 0x4c) = (char)uVar5;
    }
    else {
      if (((uVar5 & 0xf0) == 0) || ((uVar5 & 0x98) == 0x80)) {
        *(undefined *)(param_1 + 0x53) = 1;
        goto loc_F00B60E8;
      }
      *(char *)(param_1 + 0x4c) = (char)uVar5;
    }
    *(undefined *)(iVar3 + 0xc) = 0x1a;
    *(undefined *)(param_1 + 0x5c) = 0;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 6;
  }
  *(undefined *)(iVar3 + 0xc) = 0x12;
  iVar3 = -1;
locret_F00B6114:
  return CONCAT44(param_2,iVar3);
}

