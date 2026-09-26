
int _zsioctl(word param_1,int param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar2 = param_1 & 0x1f;
  iVar1 = uVar2 * 0x86;
  iVar3 = uVar2 * 0x164;
  iVar4 = (**(code **)(DAT_40ae4bc + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))
                    (unk_40B51BC + iVar1,param_2,param_3,param_4);
  if (-1 < iVar4) {
    return iVar4;
  }
  iVar4 = _ttioctl(unk_40B51BC + iVar1,param_2,param_3,param_4);
  if (iVar4 < 0) {
    iVar4 = 0;
    if (param_2 == 0x20007479) {
      uVar7 = 1;
      uVar6 = 4;
      goto loc_408BB3E;
    }
    if (param_2 < 0x2000747a) {
      if (param_2 == -0x7ffb8b93) {
        uVar7 = 0;
      }
      else {
        if (-0x7ffb8b93 < param_2) {
          if (param_2 == -0x7ffb85ff) {
            *(uint *)(DAT_40b53f8 + iVar3) = *param_3;
            *(word *)(DAT_40b53f8 + iVar3 + 10) = *(word *)(DAT_40b53f8 + iVar3 + 10) | 0x80;
            goto loc_408BB90;
          }
          if (param_2 == 0x20007478) {
            uVar7 = 2;
            uVar6 = 4;
            goto loc_408BB3E;
          }
loc_408BB8E:
          iVar4 = 0x19;
          goto loc_408BB90;
        }
        if (param_2 == -0x7ffb8b95) {
          uVar7 = 2;
        }
        else {
          if (param_2 != -0x7ffb8b94) goto loc_408BB8E;
          uVar7 = 1;
        }
      }
      uVar6 = sub_408D24A(*param_3,uVar7);
    }
    else {
      if (param_2 == 0x4004746a) {
        uVar6 = sub_408CF32(uVar2,0,3);
        uVar5 = sub_408D284(uVar6);
        *param_3 = uVar5;
        goto loc_408BB90;
      }
      if (0x4004746a < param_2) {
        if (param_2 == 0x40047a00) {
          *param_3 = *(uint *)(DAT_40b53f8 + iVar3);
          goto loc_408BB90;
        }
        if (param_2 == 0x40047a02) {
          *param_3 = (uint)(dword_40B51B8 == 2);
          goto loc_408BB90;
        }
        goto loc_408BB8E;
      }
      if (param_2 == 0x2000747a) {
        uVar7 = 2;
        uVar6 = 2;
      }
      else {
        if (param_2 != 0x2000747b) goto loc_408BB8E;
        uVar7 = 1;
        uVar6 = 2;
      }
    }
loc_408BB3E:
    sub_408CF32(uVar2,uVar6,uVar7);
    goto loc_408BB90;
  }
  if (param_2 == -0x7ff98bf6) {
loc_408BA72:
    uVar6 = 0;
  }
  else {
    if (param_2 < -0x7ff98bf5) {
      if (param_2 < -0x7ffb8b83) goto loc_408BB90;
      if (param_2 < -0x7ffb8b80) goto loc_408BA72;
      if (param_2 != -0x7ff98bf7) goto loc_408BB90;
    }
    else {
      if (param_2 == -0x7fdb8bec) goto loc_408BA72;
      if ((param_2 < -0x7fdb8bec) || (-0x7fdb8bea < param_2)) goto loc_408BB90;
    }
    uVar6 = 1;
  }
  sub_408BE8E(uVar2,uVar6);
loc_408BB90:
  if (((DAT_40b5423[iVar3] & 1) == 0) && (-1 < (char)unk_40B51BC[iVar1 + 0x3f])) {
    sub_408C552(uVar2);
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    iVar4 = 0;
  }
  return iVar4;
}
