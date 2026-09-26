
sqword _strcmp(char *param_1,uint *param_2)

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
  uint uVar5;
  undefined4 unaff_i4;
  uint uVar6;
  undefined4 unaff_i5;
  uint uVar7;
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
  while( true ) {
    uVar6 = (uint)param_2 & 3;
    if (((uint)param_1 & 3) == 0) break;
    uVar6 = (uint)*param_1;
    uVar7 = (uint)(char)*(byte *)param_2;
    param_1 = param_1 + 1;
    puVar3 = (uint *)((int)param_2 + 1);
    if (uVar6 != uVar7) goto loc_F00084CC;
    param_2 = puVar3;
    if (uVar6 == 0) goto locret_F0008468;
  }
  if (uVar6 == 0) {
    uVar7 = *param_2;
    puVar3 = param_2;
    while( true ) {
      uVar6 = *(uint *)((int)puVar3 + ((int)param_1 - (int)param_2));
      puVar3 = puVar3 + 1;
      if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
      uVar7 = *puVar3;
    }
  }
  else if (uVar6 == 2) {
    uVar5 = *(word *)param_2 | 0xffff0000;
    puVar3 = (uint *)((int)param_2 + 2);
    iVar2 = (int)param_1 - (int)puVar3;
    uVar4 = (uint)*(word *)param_2;
    do {
      if (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) == 0x81010100) {
        uVar5 = *puVar3;
      }
      else {
        uVar5 = 0;
      }
      uVar6 = *(uint *)((int)puVar3 + iVar2);
      puVar3 = puVar3 + 1;
      uVar7 = uVar5 >> 0x10 | uVar4 << 0x10;
    } while ((uVar6 == uVar7) &&
            (uVar4 = uVar5, ((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) == 0x81010100));
  }
  else {
    uVar4 = *(byte *)param_2 | 0xffffff00;
    puVar3 = (uint *)((int)param_2 + 1);
    uVar7 = (uint)*(byte *)param_2 << 0x18;
    if (uVar6 == 1) {
      wVar1 = *(word *)puVar3;
      uVar4 = (uint)wVar1 | uVar4 << 0x10;
      puVar3 = (uint *)((int)param_2 + 3);
      uVar7 = uVar7 | (uint)wVar1 << 8;
      iVar2 = (int)param_1 - (int)puVar3;
      while( true ) {
        if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) == 0x81010100) {
          uVar4 = *puVar3;
        }
        else {
          uVar4 = 0;
        }
        uVar6 = *(uint *)(iVar2 + (int)puVar3);
        puVar3 = puVar3 + 1;
        uVar7 = uVar4 >> 0x18 | uVar7;
        if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
        uVar7 = uVar4 << 8;
      }
    }
    else {
      iVar2 = (int)param_1 - (int)puVar3;
      while( true ) {
        if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) == 0x81010100) {
          uVar4 = *puVar3;
        }
        else {
          uVar4 = 0;
        }
        uVar6 = *(uint *)(iVar2 + (int)puVar3);
        puVar3 = puVar3 + 1;
        uVar7 = uVar4 >> 8 | uVar7;
        if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
        uVar7 = uVar4 << 0x18;
      }
    }
  }
  iVar2 = ((int)uVar6 >> 0x18) - ((int)uVar7 >> 0x18);
  if (iVar2 == 0) {
    if (((int)uVar6 >> 0x18 & 0xffU) == 0) {
locret_F0008468:
      return ZEXT48(puVar3) << 0x20;
    }
    uVar4 = (int)(uVar6 << 8) >> 0x18;
    iVar2 = uVar4 - ((int)(uVar7 << 8) >> 0x18);
    if (iVar2 == 0) {
      if ((uVar4 & 0xff) == 0) goto locret_F0008468;
      uVar4 = (int)(uVar6 << 0x10) >> 0x18;
      iVar2 = uVar4 - ((int)(uVar7 << 0x10) >> 0x18);
      if (iVar2 == 0) {
        if ((uVar4 & 0xff) == 0) goto locret_F0008468;
loc_F00084CC:
        iVar2 = (int)(char)uVar6 - (int)(char)uVar7;
      }
    }
  }
  return CONCAT44(puVar3,iVar2);
}
