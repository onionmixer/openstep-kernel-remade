/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c290 */

undefined4 _prf(char *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  undefined4 uVar16;
  uint *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_14 = 1;
  puVar13 = param_2;
switchD_0010c31f_caseD_26:
  param_2 = puVar13;
  cVar1 = *param_1;
  while( true ) {
    iVar7 = (int)cVar1;
    param_1 = param_1 + 1;
    if (iVar7 == 0x25) break;
    if (iVar7 == 0) {
      return local_14;
    }
    FUN_0010cbac(iVar7,param_3,param_4);
    cVar1 = *param_1;
  }
switchD_0010c31f_caseD_6c:
  iVar7 = (int)*param_1;
  if (iVar7 == 0x30) {
    local_10 = 0x30;
  }
  iVar10 = 0;
  while (param_1 = param_1 + 1, iVar7 - 0x30U < 10) {
    iVar10 = iVar7 + -0x30 + iVar10 * 10;
    iVar7 = (int)*param_1;
  }
  puVar13 = param_2;
  switch(iVar7) {
  case 0x25:
    goto switchD_0010c31f_caseD_25;
  default:
    goto switchD_0010c31f_caseD_26;
  case 0x43:
    uVar4 = *param_2;
    iVar7 = 0x18;
    do {
      uVar15 = (int)uVar4 >> ((byte)iVar7 & 0x1f) & 0xff;
      if (uVar15 != 0) {
        FUN_0010cbac(uVar15,param_3,param_4);
      }
      iVar7 = iVar7 + -8;
      puVar13 = param_2 + 1;
    } while (-1 < iVar7);
    goto switchD_0010c31f_caseD_26;
  case 0x44:
  case 100:
  case 0x75:
    local_8 = 10;
    break;
  case 0x4c:
    local_14 = 0;
    goto switchD_0010c31f_caseD_26;
  case 0x4e:
  case 0x6e:
    uVar4 = *param_2;
    puVar8 = (uint *)param_2[1];
    if (puVar8[1] == 0) goto LAB_0010c906;
    goto LAB_0010c8f0;
  case 0x4f:
  case 0x6f:
    local_8 = 8;
    break;
  case 0x52:
  case 0x72:
    uVar4 = *param_2;
    local_18 = (uint *)param_2[1];
    if (iVar7 == 0x52) {
      FUN_0010c974(&DAT_001dac18,param_3,param_4);
      FUN_0010c9a8(uVar4,0x10,param_3,param_4,0,0);
    }
    bVar5 = false;
    if ((iVar7 != 0x72) && (puVar13 = param_2 + 2, uVar4 == 0)) goto switchD_0010c31f_caseD_26;
    FUN_0010cbac(0x3c,param_3,param_4);
    if (*local_18 == 0) goto LAB_0010c8a7;
    puVar13 = local_18 + 4;
    goto LAB_0010c758;
  case 0x58:
  case 0x78:
    local_8 = 0x10;
    break;
  case 0x62:
    uVar4 = *param_2;
    pcVar12 = (char *)param_2[1] + 1;
    FUN_0010c9a8(uVar4,(int)*(char *)param_2[1],param_3,param_4,0,0);
    local_c = 0;
    puVar13 = param_2 + 2;
    if (uVar4 != 0) goto LAB_0010c636;
    goto switchD_0010c31f_caseD_26;
  case 99:
    uVar4 = *param_2;
    iVar7 = 0x18;
    do {
      uVar15 = (int)uVar4 >> ((byte)iVar7 & 0x1f) & 0x7f;
      if (uVar15 != 0) {
        FUN_0010cbac(uVar15,param_3,param_4);
      }
      iVar7 = iVar7 + -8;
      puVar13 = param_2 + 1;
    } while (-1 < iVar7);
    goto switchD_0010c31f_caseD_26;
  case 0x6c:
    goto switchD_0010c31f_caseD_6c;
  case 0x73:
    pcVar12 = (char *)*param_2;
    cVar1 = *pcVar12;
    while (puVar13 = param_2 + 1, cVar1 != 0) {
      pcVar12 = pcVar12 + 1;
      FUN_0010cbac((int)cVar1,param_3,param_4);
      cVar1 = *pcVar12;
    }
    goto switchD_0010c31f_caseD_26;
  }
  FUN_0010c9a8(*param_2,local_8,param_3,param_4,local_10,iVar10);
  puVar13 = param_2 + 1;
  goto switchD_0010c31f_caseD_26;
LAB_0010c636:
  while( true ) {
    cVar1 = *pcVar12;
    pcVar11 = pcVar12 + 1;
    if (cVar1 == 0) break;
    if (*pcVar11 < '!') {
      local_c = local_c + 1;
      if (local_c != 1) {
        FUN_0010cbac(0x2c,param_3,param_4);
      }
      cVar2 = *pcVar11;
      pcVar12 = pcVar12 + 2;
      cVar3 = *pcVar12;
      while (0x20 < cVar3) {
        FUN_0010cbac((int)cVar3,param_3,param_4);
        pcVar12 = pcVar12 + 1;
        cVar3 = *pcVar12;
      }
      FUN_0010c9a8((2 << (cVar1 - cVar2 & 0x1fU)) - 1U & (int)uVar4 >> (cVar2 - 1U & 0x1f),8,param_3
                   ,param_4,0,0);
    }
    else {
      pcVar12 = pcVar11;
      if ((uVar4 >> ((int)cVar1 - 1U & 0x1f) & 1) == 0) {
        do {
          pcVar12 = pcVar12 + 1;
        } while (' ' < *pcVar12);
      }
      else {
        uVar16 = 0x3c;
        if (local_c != 0) {
          uVar16 = 0x2c;
        }
        FUN_0010cbac(uVar16,param_3,param_4);
        local_c = 1;
        cVar1 = *pcVar11;
        while (0x20 < cVar1) {
          FUN_0010cbac((int)cVar1,param_3,param_4);
          pcVar12 = pcVar12 + 1;
          cVar1 = *pcVar12;
        }
      }
    }
  }
  goto LAB_0010c8a7;
LAB_0010c758:
  do {
    bVar6 = (byte)puVar13[-3];
    if ((int)puVar13[-3] < 1) {
      uVar15 = (uVar4 & *local_18) >> (-bVar6 & 0x1f);
    }
    else {
      uVar15 = (uVar4 & *local_18) << (bVar6 & 0x1f);
    }
    if (bVar5) {
      if ((puVar13[-1] != 0) || (*puVar13 != 0)) {
LAB_0010c7ad:
        FUN_0010cbac(0x2c,param_3,param_4);
        goto LAB_0010c7bf;
      }
      if (puVar13[-2] != 0) {
        if (uVar15 == 0) goto LAB_0010c7bf;
        goto LAB_0010c7ad;
      }
    }
    else {
LAB_0010c7bf:
      if (puVar13[-2] != 0) {
        if (((puVar13[-1] != 0) || (*puVar13 != 0)) || (uVar15 != 0)) {
          FUN_0010c974(puVar13[-2],param_3,param_4);
          bVar5 = true;
        }
        if ((puVar13[-1] != 0) || (*puVar13 != 0)) {
          FUN_0010cbac(0x3d,param_3,param_4);
          bVar5 = true;
        }
      }
    }
    if (puVar13[-1] == 0) {
LAB_0010c84a:
      puVar8 = (uint *)*puVar13;
      if (puVar8 != (uint *)0x0) {
        bVar5 = true;
        if (puVar8[1] != 0) {
          do {
            if (*puVar8 == uVar15) {
              FUN_0010c974(puVar8[1],param_3,param_4);
              break;
            }
            puVar9 = puVar8 + 2;
            puVar14 = puVar8 + 3;
            puVar8 = puVar9;
          } while (*puVar14 != 0);
          if (puVar8[1] != 0) goto LAB_0010c88c;
        }
        FUN_0010c974(&DAT_001dac1b,param_3,param_4);
      }
    }
    else {
      __printf(param_3,param_4,puVar13[-1],uVar15);
      bVar5 = true;
      if (*puVar13 != 0) {
        FUN_0010cbac(0x3a,param_3,param_4);
        goto LAB_0010c84a;
      }
    }
LAB_0010c88c:
    puVar13 = puVar13 + 5;
    local_18 = local_18 + 5;
  } while (*local_18 != 0);
LAB_0010c8a7:
  param_2 = param_2 + 2;
  uVar16 = 0x3e;
LAB_0010c8a9:
  FUN_0010cbac(uVar16,param_3,param_4);
  puVar13 = param_2;
  goto switchD_0010c31f_caseD_26;
  while (puVar14 = puVar8 + 2, puVar13 = puVar8 + 3, puVar8 = puVar14, *puVar13 != 0) {
LAB_0010c8f0:
    if (*puVar8 == uVar4) {
      FUN_0010c974(puVar8[1],param_3,param_4);
      break;
    }
  }
  if (puVar8[1] == 0) {
LAB_0010c906:
    FUN_0010c974(&DAT_001dac1f,param_3,param_4);
  }
  puVar13 = param_2 + 2;
  if ((iVar7 == 0x4e) || (puVar8[1] == 0)) {
    FUN_0010cbac(0x3a,param_3,param_4);
    FUN_0010c9a8(uVar4,10,param_3,param_4,0,0);
  }
  goto switchD_0010c31f_caseD_26;
switchD_0010c31f_caseD_25:
  uVar16 = 0x25;
  goto LAB_0010c8a9;
}

