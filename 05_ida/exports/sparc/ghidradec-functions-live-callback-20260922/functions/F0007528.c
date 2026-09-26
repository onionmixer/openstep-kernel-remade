
undefined8 _strcpy(uint *param_1,uint *param_2)

{
  word wVar1;
  uint uVar2;
  char cVar4;
  undefined2 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar2 = (uint)param_2 & 3;
  puVar5 = param_1;
  if (uVar2 != 0) {
    if (uVar2 != 2) {
      cVar4 = *(char *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(char *)param_1 = cVar4;
      if (uVar2 == 3) {
        puVar5 = (uint *)((int)param_1 + 1);
        if (cVar4 == '\0') goto locret_F00078C0;
        goto loc_F00075A0;
      }
      puVar5 = (uint *)((int)param_1 + 1);
      if (cVar4 == '\0') goto locret_F00078C0;
    }
    wVar1 = *(word *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)puVar5 = (char)(wVar1 >> 8);
    if (wVar1 >> 8 == 0) goto locret_F00078C0;
    *(char *)((int)puVar5 + 1) = (char)wVar1;
    puVar5 = (uint *)((int)puVar5 + 2);
    if ((wVar1 & 0xff) == 0) goto locret_F00078C0;
  }
loc_F00075A0:
  uVar2 = (uint)puVar5 & 3;
  if (uVar2 == 0) {
    do {
      while( true ) {
        uVar2 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      }
      if ((uVar2 & 0xff000000) == 0) goto loc_F00078C8;
      if ((uVar2 & 0xff0000) == 0) goto loc_F00078D4;
      if ((uVar2 & 0xff00) == 0) goto loc_F00078E4;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
    } while ((uVar2 & 0xff) != 0);
    goto locret_F00078C0;
  }
  if (uVar2 == 2) {
    uVar8 = *param_2;
    param_2 = param_2 + 1;
    if ((uVar8 & 0xff000000) == 0) goto loc_F00078C8;
    uVar2 = uVar8;
    if ((uVar8 & 0xff0000) == 0) {
loc_F00078D4:
      *(sword *)puVar5 = (sword)(uVar2 >> 0x10);
      return CONCAT44(param_2,param_1);
    }
    if ((uVar8 & 0xff00) == 0) {
loc_F00078E4:
      *(sword *)puVar5 = (sword)(uVar2 >> 0x10);
      *(char *)((int)puVar5 + 2) = '\0';
      return CONCAT44(param_2,param_1);
    }
    uVar3 = (undefined2)(uVar8 >> 0x10);
    if ((uVar8 & 0xff) == 0) {
      *(undefined2 *)puVar5 = uVar3;
      *(sword *)((int)puVar5 + 2) = (sword)uVar8;
    }
    else {
      *(undefined2 *)puVar5 = uVar3;
      puVar5 = (uint *)((int)puVar5 + 2);
      do {
        while( true ) {
          uVar7 = uVar8 << 0x10;
          if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
          if ((uVar7 & 0xff0000) == 0) goto loc_F00078F8;
          uVar8 = *param_2;
          param_2 = param_2 + 1;
          uVar6 = uVar8 >> 0x10;
          uVar2 = uVar6 | uVar7;
          if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 1;
        }
        if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
        if ((uVar7 & 0xff0000) == 0) goto loc_F00078D4;
        if ((uVar6 & 0xff00) == 0) goto loc_F00078E4;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      } while ((uVar6 & 0xff) != 0);
    }
    goto locret_F00078C0;
  }
  uVar6 = *param_2;
  param_2 = param_2 + 1;
  bVar9 = (uVar6 & 0xff000000) == 0;
  cVar4 = (char)(uVar6 >> 0x18);
  uVar8 = uVar6;
  if (uVar2 == 3) {
    if (bVar9) goto loc_F00078C8;
    if ((uVar6 & 0xff0000) != 0) {
      if ((uVar6 & 0xff00) != 0) {
        if ((uVar6 & 0xff) != 0) {
          *(char *)puVar5 = cVar4;
          puVar5 = (uint *)((int)puVar5 + 1);
loc_F0007708:
          do {
            uVar7 = uVar6 << 8;
            if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) {
loc_F00078F8:
              *(sword *)puVar5 = (sword)(uVar7 >> 0x10);
              return CONCAT44(param_2,param_1);
            }
            if ((uVar7 & 0xff00) == 0) {
              *(sword *)puVar5 = (sword)(uVar6 >> 8);
              *(char *)((int)puVar5 + 2) = '\0';
              return CONCAT44(param_2,param_1);
            }
            uVar6 = *param_2;
            param_2 = param_2 + 1;
            uVar8 = uVar6 >> 0x18 | uVar7;
            if (((uVar8 + 0x7efefeff ^ uVar8) & 0x81010100) == 0x81010100) {
              *puVar5 = uVar8;
              puVar5 = puVar5 + 1;
              goto loc_F0007708;
            }
            if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) goto loc_F00076AC;
            if ((uVar7 & 0xff00) == 0) goto loc_F00076A4;
            *puVar5 = uVar8;
            puVar5 = puVar5 + 1;
          } while (uVar6 >> 0x18 != 0);
          goto locret_F00078C0;
        }
        goto loc_F00076A0;
      }
      goto loc_F00076A4;
    }
  }
  else {
    if (bVar9) {
loc_F00078C8:
      *(char *)puVar5 = '\0';
      return CONCAT44(param_2,param_1);
    }
    if ((uVar6 & 0xff0000) != 0) {
      if ((uVar6 & 0xff00) != 0) {
        if ((uVar6 & 0xff) != 0) {
          *(char *)puVar5 = cVar4;
          *(sword *)((int)puVar5 + 1) = (sword)(uVar6 >> 8);
          puVar5 = (uint *)((int)puVar5 + 3);
          do {
            while( true ) {
              uVar2 = uVar6 << 0x18;
              if (uVar2 == 0) goto loc_F00078C8;
              uVar6 = *param_2;
              param_2 = param_2 + 1;
              uVar7 = uVar6 >> 8;
              uVar8 = uVar7 | uVar2;
              if (((uVar8 + 0x7efefeff ^ uVar8) & 0x81010100) != 0x81010100) break;
              *puVar5 = uVar8;
              puVar5 = puVar5 + 1;
            }
            if (uVar2 == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) goto loc_F00076AC;
            if ((uVar7 & 0xff00) == 0) goto loc_F00076A4;
            *puVar5 = uVar8;
            puVar5 = puVar5 + 1;
          } while ((uVar7 & 0xff) != 0);
          goto locret_F00078C0;
        }
loc_F00076A0:
        *(char *)((int)puVar5 + 3) = (char)uVar6;
      }
loc_F00076A4:
      *(char *)((int)puVar5 + 2) = (char)(uVar8 >> 8);
    }
  }
loc_F00076AC:
  *(char *)puVar5 = (char)(uVar8 >> 0x18);
  *(char *)((int)puVar5 + 1) = (char)(uVar8 >> 0x10);
locret_F00078C0:
  return CONCAT44(param_2,param_1);
}

