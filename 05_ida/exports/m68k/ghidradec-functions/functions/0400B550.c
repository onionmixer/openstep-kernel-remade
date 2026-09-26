
undefined4 _prf(char *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  uStack_c = 1;
loc_400B580:
  pcVar12 = param_1 + 1;
  iVar6 = (int)*param_1;
  param_1 = pcVar12;
  if (iVar6 == 0x25) {
loc_400b592:
    iVar6 = (int)*param_1;
    if (iVar6 == 0x30) {
      uStack_8 = 0x30;
    }
    iVar10 = 0;
    while (param_1 = param_1 + 1, iVar6 - 0x30U < 10) {
      iVar10 = iVar6 + -0x30 + iVar10 * 10;
      iVar6 = (int)*param_1;
    }
    goto loc_400b5dc;
  }
  if (iVar6 == 0) {
    return uStack_c;
  }
  goto loc_400B576;
loc_400b5dc:
  switch(iVar6) {
  case :
    goto loc_400b8e6;
  :
    goto loc_400B580;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    uVar7 = 0x18;
    do {
      uVar4 = (int)uVar1 >> (uVar7 & 0x3f) & 0xff;
      if (uVar4 != 0) {
        sub_400BDAC(uVar4,param_3,param_4);
      }
      uVar7 = uVar7 - 8;
      param_2 = puVar8;
    } while (-1 < (int)uVar7);
    goto loc_400B580;
  case :
  case :
  case :
    uVar9 = 10;
    break;
  case :
    uStack_c = 0;
    goto loc_400B580;
  case :
  case :
    uVar1 = *param_2;
    puVar15 = param_2 + 2;
    puVar8 = (uint *)param_2[1];
    if (puVar8[1] != 0) goto loc_400BAFA;
    goto loc_400BB0C;
  case :
  case :
    uVar9 = 8;
    break;
  case :
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    param_2 = param_2 + 2;
    puVar8 = (uint *)*puVar8;
    if (iVar6 == 0x52) {
      sub_400BB74(&a0x,param_3,param_4);
      sub_400BBAA(uVar1,0x10,param_3,param_4,0,0);
    }
    bVar5 = false;
    if ((iVar6 != 0x72) && (uVar1 == 0)) goto loc_400B580;
    sub_400BDAC(0x3c,param_3,param_4);
    if (*puVar8 == 0) goto loc_400BABC;
    puVar15 = puVar8 + 4;
    puVar16 = puVar8 + 3;
    puVar17 = puVar8 + 2;
    goto loc_400B9A4;
  case :
  case :
    uVar9 = 0x10;
    break;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    param_2 = param_2 + 2;
    pcVar12 = (char *)*puVar8 + 1;
    sub_400BBAA(uVar1,(int)*(char *)*puVar8,param_3,param_4,0,0);
    iVar6 = 0;
    if (uVar1 != 0) goto loc_400B8A2;
    goto loc_400B580;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    uVar7 = 0x18;
    do {
      uVar4 = (int)uVar1 >> (uVar7 & 0x3f) & 0x7f;
      if (uVar4 != 0) {
        sub_400BDAC(uVar4,param_3,param_4);
      }
      uVar7 = uVar7 - 8;
      param_2 = puVar8;
    } while (-1 < (int)uVar7);
    goto loc_400B580;
  case :
    goto loc_400b592;
  case :
    puVar8 = param_2 + 1;
    pcVar12 = (char *)*param_2;
    cVar3 = *pcVar12;
    while (param_2 = puVar8, cVar3 != 0) {
      pcVar12 = pcVar12 + 1;
      sub_400BDAC((int)cVar3,param_3,param_4);
      cVar3 = *pcVar12;
    }
    goto loc_400B580;
  }
  sub_400BBAA(*param_2,uVar9,param_3,param_4,uStack_8,iVar10);
  param_2 = param_2 + 1;
  goto loc_400B580;
loc_400B8A2:
  while( true ) {
    pcVar11 = pcVar12 + 1;
    iVar10 = (int)*pcVar12;
    if (iVar10 == 0) break;
    if (*pcVar11 < '!') {
      iVar6 = iVar6 + 1;
      if (iVar6 != 1) {
        sub_400BDAC(0x2c,param_3,param_4);
      }
      cVar3 = *pcVar11;
      for (pcVar12 = pcVar12 + 2; 0x20 < *pcVar12; pcVar12 = pcVar12 + 1) {
        sub_400BDAC((int)*pcVar12,param_3,param_4);
      }
      sub_400BBAA((2 << (iVar10 - cVar3 & 0x3fU)) - 1U & (int)uVar1 >> ((int)cVar3 - 1U & 0x3f),8,
                  param_3,param_4,0,0);
    }
    else {
      pcVar12 = pcVar11;
      if ((int)(uVar1 << 0x20 - iVar10) < 0) {
        uVar9 = 0x3c;
        if (iVar6 != 0) {
          uVar9 = 0x2c;
        }
        sub_400BDAC(uVar9,param_3,param_4);
        iVar6 = 1;
        cVar3 = *pcVar11;
        while (0x20 < cVar3) {
          sub_400BDAC((int)cVar3,param_3,param_4);
          pcVar12 = pcVar12 + 1;
          cVar3 = *pcVar12;
        }
      }
      else {
        do {
          pcVar12 = pcVar12 + 1;
        } while (' ' < *pcVar12);
      }
    }
  }
  iVar6 = 0x3e;
  goto loc_400B576;
loc_400B9A4:
  do {
    uVar7 = puVar8[1];
    if ((int)uVar7 < 1) {
      uVar7 = (*puVar8 & uVar1) >> (-uVar7 & 0x3f);
    }
    else {
      uVar7 = (*puVar8 & uVar1) << (uVar7 & 0x3f);
    }
    if (bVar5) {
      if ((*puVar16 != 0) || (*puVar15 != 0)) {
loc_400B9E4:
        sub_400BDAC(0x2c,param_3,param_4);
        goto loc_400B9F8;
      }
      if (*puVar17 != 0) {
        if (uVar7 == 0) goto loc_400B9F8;
        goto loc_400B9E4;
      }
    }
    else {
loc_400B9F8:
      if (*puVar17 != 0) {
        if (((*puVar16 != 0) || (*puVar15 != 0)) || (uVar7 != 0)) {
          sub_400BB74(*puVar17,param_3,param_4);
          bVar5 = true;
        }
        if ((*puVar16 != 0) || (*puVar15 != 0)) {
          sub_400BDAC(0x3d,param_3,param_4);
          bVar5 = true;
        }
      }
    }
    if (*puVar16 == 0) {
loc_400BA6C:
      puVar13 = (uint *)*puVar15;
      if (puVar13 != (uint *)0x0) {
        bVar5 = true;
        if (puVar13[1] != 0) {
          do {
            if (uVar7 == *puVar13) {
              sub_400BB74(puVar13[1],param_3,param_4);
              break;
            }
            puVar14 = puVar13 + 2;
            puVar2 = puVar13 + 3;
            puVar13 = puVar14;
          } while (*puVar2 != 0);
          if (puVar13[1] != 0) goto loc_400BAA4;
        }
        sub_400BB74(&asc_40A6284,param_3,param_4);
      }
    }
    else {
      __printf(param_3,param_4,*puVar16,uVar7);
      bVar5 = true;
      if (*puVar15 != 0) {
        sub_400BDAC(0x3a,param_3,param_4);
        goto loc_400BA6C;
      }
    }
loc_400BAA4:
    puVar15 = puVar15 + 5;
    puVar16 = puVar16 + 5;
    puVar17 = puVar17 + 5;
    puVar8 = puVar8 + 5;
  } while (*puVar8 != 0);
loc_400BABC:
  iVar6 = 0x3e;
loc_400B576:
  sub_400BDAC(iVar6,param_3,param_4);
  goto loc_400B580;
  while (puVar17 = puVar8 + 2, puVar16 = puVar8 + 3, puVar8 = puVar17, *puVar16 != 0) {
loc_400BAFA:
    if (uVar1 == *puVar8) {
      sub_400BB74(puVar8[1],param_3,param_4);
      break;
    }
  }
  if (puVar8[1] == 0) {
loc_400BB0C:
    sub_400BB74(&asc_40A6284,param_3,param_4);
  }
  param_2 = puVar15;
  if ((iVar6 == 0x4e) || (puVar8[1] == 0)) {
    sub_400BDAC(0x3a,param_3,param_4);
    sub_400BBAA(uVar1,10,param_3,param_4,0,0);
  }
  goto loc_400B580;
loc_400b8e6:
  iVar6 = 0x25;
  goto loc_400B576;
}
