
int _fc_specify(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar6;
  int iVar5;
  byte bVar7;
  undefined4 uVar8;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined uStack_54;
  uint uStack_53;
  undefined uStack_4f;
  undefined4 uStack_44;
  
  iVar5 = *param_1;
  _bzero(auStack_5e,0x5a);
  uStack_54 = 3;
  if (param_2 == 2) {
    bVar7 = 0;
    uVar8 = 0;
    if (_machine_type == '\0') {
      _fc_flpctl_bclr(param_1,0x40);
    }
    iVar3 = *(int *)(param_3 + 0x34);
    if (iVar3 < 0x100) {
      iVar2 = iVar3 + 1;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 2;
      }
      iVar2 = iVar2 >> 1;
    }
    else {
      iVar2 = 0;
    }
    uVar4 = CONCAT31((int3)uStack_53,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar2 << 0x19) >> 8);
    uStack_53 = CONCAT13((char)((uint)(*(int *)(param_3 + 0x30) * -0x10000000) >> 0x18),
                         uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (iVar3 < 0x100) {
      iVar2 = iVar3 + 0xf;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 0x1e;
      }
      uVar4 = iVar2 >> 4;
    }
    else {
loc_406D35E:
      uVar4 = 0;
    }
  }
  else if (param_2 < 3) {
    if (param_2 != 1) {
loc_406D36C:
      _printf(aFdBogusDensity,param_2);
      return 4;
    }
    bVar7 = 2;
    uVar8 = 0;
    if (_machine_type == '\0') {
      _fc_flpctl_bset(param_1,0x40);
    }
    iVar3 = *(int *)(param_3 + 0x30) + 1;
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_3 + 0x30) + 2;
    }
    iVar2 = *(int *)(param_3 + 0x34);
    if (iVar2 < 0x200) {
      iVar1 = iVar2 + 3;
      if (iVar1 < 0) {
        iVar1 = iVar2 + 6;
      }
      iVar1 = iVar1 >> 2;
    }
    else {
      iVar1 = 0;
    }
    uVar4 = CONCAT31((int3)uStack_53,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar1 << 0x19) >> 8);
    uStack_53 = CONCAT13((char)((uint)((iVar3 >> 1) * -0x10000000) >> 0x18),uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (0x1ff < iVar3) goto loc_406D35E;
    iVar2 = iVar3 + 0x1f;
    if (iVar2 < 0) {
      iVar2 = iVar3 + 0x3e;
    }
    uVar4 = iVar2 >> 5;
  }
  else {
    if (param_2 != 3) goto loc_406D36C;
    bVar7 = 3;
    uVar8 = 1;
    if (_machine_type == '\0') {
      _fc_flpctl_bset(param_1,0x40);
    }
    iVar3 = 0;
    if (*(int *)(param_3 + 0x34) < 0x80) {
      iVar3 = *(int *)(param_3 + 0x34);
    }
    uVar4 = CONCAT31(uStack_53._1_3_,uStack_4f) & 0x1ffffff;
    uStack_53._1_3_ = (uint3)(uVar4 >> 8) | (uint3)((uint)(iVar3 << 0x19) >> 8);
    uStack_53 = CONCAT13(-(char)(*(int *)(param_3 + 0x30) << 5),uStack_53._1_3_);
    uStack_4f = (undefined)uVar4;
    iVar3 = *(int *)(param_3 + 0x38);
    if (0x7f < iVar3) goto loc_406D35E;
    iVar2 = iVar3 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    uVar4 = iVar2 >> 3;
  }
  uStack_53 = uStack_53 | (uVar4 & 0xf) << 0x18;
  bVar6 = bVar7;
  if (*(int *)(param_3 + 0x40) == 0) {
    bVar6 = bVar7 | 0x1c;
  }
  *(byte *)(iVar5 + 4) = bVar6;
  *(byte *)(iVar5 + 7) = bVar7;
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 3;
  iVar5 = _fc_send_cmd(param_1,auStack_5e);
  if (*(int *)(param_3 + 0x3c) != 0) {
    if (iVar5 != 0) goto loc_406D3D4;
    iVar5 = sub_406D5CE(param_1,1,uVar8);
  }
  if (iVar5 == 0) {
    *(int *)((int)param_1 + 0x25e) = param_2;
    return 0;
  }
loc_406D3D4:
  *(undefined4 *)((int)param_1 + 0x25e) = 0;
  return iVar5;
}

