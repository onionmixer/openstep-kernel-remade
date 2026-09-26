
sqword _strncmp(char *param_1,uint *param_2,int param_3)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  uint *puVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar4;
  undefined4 unaff_i4;
  uint uVar5;
  undefined4 unaff_i5;
  uint uVar6;
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
  if (7 < param_3) {
    do {
      uVar5 = (uint)param_2 & 3;
      puVar3 = param_2;
      if (((uint)param_1 & 3) == 0) {
        if (uVar5 == 0) {
          iVar2 = (int)param_1 - (int)param_2;
          uVar6 = *param_2;
          goto loc_F0008740;
        }
        if (uVar5 == 2) {
          uVar4 = (uint)*(word *)param_2;
          puVar3 = (uint *)((int)param_2 + 2);
          iVar2 = (int)param_1 - (int)puVar3;
          goto loc_F00086B0;
        }
        puVar3 = (uint *)((int)param_2 + 1);
        uVar6 = (uint)*(byte *)param_2 << 0x18;
        if (uVar5 != 1) {
          iVar2 = (int)param_1 - (int)puVar3;
          goto loc_F0008578;
        }
        wVar1 = *(word *)puVar3;
        puVar3 = (uint *)((int)param_2 + 3);
        uVar6 = uVar6 | (uint)wVar1 << 8;
        iVar2 = (int)param_1 - (int)puVar3;
        goto loc_F0008618;
      }
      param_3 = param_3 + -1;
      if (param_3 < 0) break;
      uVar5 = (uint)*param_1;
      uVar6 = (uint)(char)*(byte *)param_2;
      param_1 = param_1 + 1;
      puVar3 = (uint *)((int)param_2 + 1);
      if (uVar5 != uVar6) goto loc_F0008810;
      param_2 = puVar3;
    } while (uVar5 != 0);
    goto locret_F00087AC;
  }
  iVar2 = (int)param_1 - (int)param_2;
  puVar3 = param_2;
loc_F0008830:
  do {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    uVar5 = (uint)(char)*(byte *)((int)puVar3 + iVar2);
    uVar6 = (uint)(char)*(byte *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if (uVar5 != uVar6) goto loc_F0008810;
  } while (uVar5 != 0);
locret_F00087AC:
  return ZEXT48(puVar3) << 0x20;
loc_F0008740:
  if (param_3 + -4 < 0) goto loc_F0008830;
  uVar5 = *(uint *)((int)puVar3 + iVar2);
  puVar3 = puVar3 + 1;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = *puVar3;
  param_3 = param_3 + -4;
  goto loc_F0008740;
  while( true ) {
    uVar5 = *(uint *)((int)puVar3 + iVar2);
    puVar3 = puVar3 + 1;
    uVar6 = uVar4 >> 0x10 | uVar6;
    if ((uVar5 != uVar6) ||
       (param_3 = param_3 + -4, ((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100)) break;
loc_F00086B0:
    uVar6 = uVar4 << 0x10;
    uVar4 = *puVar3;
    if (param_3 < 4) {
      puVar3 = (uint *)((int)puVar3 + -2);
      iVar2 = iVar2 + 2;
      goto loc_F0008830;
    }
  }
loc_F00087B4:
  iVar2 = ((int)uVar5 >> 0x18) - ((int)uVar6 >> 0x18);
  if (iVar2 != 0) {
locret_F0008824:
    return CONCAT44(puVar3,iVar2);
  }
  if (((int)uVar5 >> 0x18 & 0xffU) != 0) {
    uVar4 = (int)(uVar5 << 8) >> 0x18;
    iVar2 = uVar4 - ((int)(uVar6 << 8) >> 0x18);
    if (iVar2 == 0) {
      if ((uVar4 & 0xff) == 0) goto locret_F00087AC;
      uVar4 = (int)(uVar5 << 0x10) >> 0x18;
      iVar2 = uVar4 - ((int)(uVar6 << 0x10) >> 0x18);
      if (iVar2 == 0) {
        if ((uVar4 & 0xff) == 0) goto locret_F00087AC;
loc_F0008810:
        iVar2 = (int)(char)uVar5 - (int)(char)uVar6;
      }
    }
    goto locret_F0008824;
  }
  goto locret_F00087AC;
loc_F0008618:
  uVar4 = *puVar3;
  if (param_3 < 4) goto loc_f0008624;
  uVar5 = *(uint *)(iVar2 + (int)puVar3);
  puVar3 = puVar3 + 1;
  uVar6 = uVar4 >> 0x18 | uVar6;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = uVar4 << 8;
  param_3 = param_3 + -4;
  goto loc_F0008618;
loc_f0008624:
  puVar3 = (uint *)((int)puVar3 + -3);
  iVar2 = iVar2 + 3;
  goto loc_F0008830;
loc_F0008578:
  uVar4 = *puVar3;
  if (param_3 < 4) goto loc_f0008584;
  uVar5 = *(uint *)(iVar2 + (int)puVar3);
  puVar3 = puVar3 + 1;
  uVar6 = uVar4 >> 8 | uVar6;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = uVar4 << 0x18;
  param_3 = param_3 + -4;
  goto loc_F0008578;
loc_f0008584:
  puVar3 = (uint *)((int)puVar3 + -1);
  iVar2 = iVar2 + 1;
  goto loc_F0008830;
}

