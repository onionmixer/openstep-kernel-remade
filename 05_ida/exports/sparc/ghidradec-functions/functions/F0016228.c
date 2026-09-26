
/* WARNING: Removing unreachable block (ram,0xf0016388) */
/* WARNING: Removing unreachable block (ram,0xf00163c0) */

undefined8 _soo_ioctl(int param_1,int param_2,uint *param_3)

{
  word wVar2;
  uint uVar1;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar3 = *(int *)(param_1 + 0x18);
  if (param_2 == 0x200073ff) {
    iVar4 = 0;
    *(word *)(iVar3 + 6) = *(word *)(iVar3 + 6) | 0x80;
    goto locret_F00163CC;
  }
  if (param_2 < 0x20007400) {
    if (param_2 == -0x7ffb9982) {
      if (*param_3 == 0) {
        wVar2 = *(word *)(iVar3 + 6) & 0xfeff;
      }
      else {
        wVar2 = *(word *)(iVar3 + 6) | 0x100;
      }
loc_F0016338:
      *(word *)(iVar3 + 6) = wVar2;
      iVar4 = 0;
      goto locret_F00163CC;
    }
    if (param_2 < -0x7ffb9981) {
      if (param_2 == -0x7ffb9983) {
        if (*param_3 == 0) {
          wVar2 = *(word *)(iVar3 + 6) & 0xfdff;
        }
        else {
          wVar2 = *(word *)(iVar3 + 6) | 0x200;
        }
        goto loc_F0016338;
      }
    }
    else if (param_2 == -0x7ffb8cf8) {
      iVar4 = 0;
      *(sword *)(iVar3 + 0x5a) = (sword)*param_3;
      goto locret_F00163CC;
    }
  }
  else {
    if (param_2 == 0x40047307) {
      iVar4 = 0;
      *param_3 = *(word *)(iVar3 + 6) >> 6 & 1;
      goto locret_F00163CC;
    }
    if (param_2 < 0x40047308) {
      if (param_2 == 0x4004667f) {
        uVar1 = (uint)*(word *)(iVar3 + 0x24);
loc_F0016350:
        iVar4 = 0;
        *param_3 = uVar1;
        goto locret_F00163CC;
      }
    }
    else if (param_2 == 0x40047309) {
      uVar1 = (uint)*(sword *)(iVar3 + 0x5a);
      goto loc_F0016350;
    }
  }
  uVar1 = param_2 >> 8 & 0xff;
  if (uVar1 == 0x69) {
    _ifioctl(iVar3,param_2,param_3);
    iVar4 = iVar3;
  }
  else if (uVar1 == 0x72) {
    iVar4 = param_2;
    _rtioctl(param_2,param_3);
  }
  else {
    (**(code **)(*(int *)(iVar3 + 0xc) + 0x1c))(iVar3,0xb,param_2,param_3,0);
    iVar4 = iVar3;
  }
locret_F00163CC:
  return CONCAT44(param_2,iVar4);
}
