
undefined4 srem(void)

{
  word wVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  word *in_A0;
  int unaff_A6;
  bool bVar12;
  bool bVar13;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 1;
  wVar1 = *in_A0;
  *(word *)(unaff_A6 + -0x3c) = wVar1;
  uVar6 = *(uint *)(in_A0 + 2);
  uVar7 = *(uint *)(in_A0 + 4);
  if ((wVar1 & 0x7fff) == 0) {
    if (uVar6 == 0) {
      iVar8 = (uint)(uVar7 != 0) * LZCOUNT(uVar7);
      uVar6 = uVar7 << iVar8;
      iVar8 = 0x3fde - iVar8;
      uVar7 = 0;
    }
    else {
      iVar9 = (uint)(uVar6 != 0) * LZCOUNT(uVar6);
      iVar8 = 0x3ffe - iVar9;
      uVar6 = uVar7 >> (0x20U - iVar9 & 0x3f) | uVar6 << iVar9;
      uVar7 = uVar7 << iVar9;
    }
  }
  else {
    iVar8 = (wVar1 & 0x7fff) + 0x3ffe;
  }
  wVar1 = in_A0[-6];
  *(word *)(unaff_A6 + -0x38) = wVar1;
  *(word *)(unaff_A6 + -0x34) = (wVar1 ^ *(word *)(unaff_A6 + -0x3c)) & 0x8000;
  uVar3 = *(uint *)(in_A0 + -4);
  uVar4 = *(uint *)(in_A0 + -2);
  if ((wVar1 & 0x7fff) == 0) {
    if (uVar3 == 0) {
      iVar9 = (uint)(uVar4 != 0) * LZCOUNT(uVar4);
      uVar3 = uVar4 << iVar9;
      iVar9 = 0x3fde - iVar9;
      uVar4 = 0;
    }
    else {
      iVar10 = (uint)(uVar3 != 0) * LZCOUNT(uVar3);
      iVar9 = 0x3ffe - iVar10;
      uVar3 = uVar4 >> (0x20U - iVar10 & 0x3f) | uVar3 << iVar10;
      uVar4 = uVar4 << iVar10;
    }
  }
  else {
    iVar9 = (wVar1 & 0x7fff) + 0x3ffe;
  }
  *(int *)(unaff_A6 + -0x54) = iVar8;
  *(int *)(unaff_A6 + -0x50) = iVar9;
  iVar9 = iVar9 - iVar8;
  cVar11 = '\0';
  bVar13 = false;
  if (-1 < iVar9) {
    do {
      bVar13 = false;
      if (cVar11 == '\0') {
        bVar12 = uVar3 < uVar6;
        if ((uVar3 == uVar6) && (bVar12 = uVar4 < uVar7, uVar4 == uVar7)) {
          *(undefined4 *)(unaff_A6 + -0x30) = 0;
          goto loc_40A1EE6;
        }
        if (!bVar12) goto loc_40A1DAC;
      }
      else {
loc_40A1DAC:
        bVar13 = uVar4 < uVar7;
        uVar4 = uVar4 - uVar7;
        uVar3 = uVar3 - (bVar13 + uVar6);
        bVar13 = true;
      }
      if (iVar9 == 0) goto loc_40A1DCE;
      bVar13 = CARRY4(uVar4,uVar4);
      uVar4 = uVar4 * 2;
      uVar5 = uVar3 & 0x80000000;
      uVar3 = uVar3 << 1 | (uint)bVar13;
      cVar11 = -(uVar5 != 0);
      iVar9 = iVar9 + -1;
    } while( true );
  }
  iVar8 = *(int *)(unaff_A6 + -0x50);
  uVar5 = uVar4;
loc_40A1E14:
  if (iVar8 < 0x41fe) {
    *(sword *)(unaff_A6 + -100) = (sword)iVar8;
    *(undefined2 *)(unaff_A6 + -0x62) = 0;
    *(uint *)(unaff_A6 + -0x60) = uVar3;
    *(uint *)(unaff_A6 + -0x5c) = uVar5;
    *(sword *)(unaff_A6 + -0x74) = (sword)*(undefined4 *)(unaff_A6 + -0x54);
    *(undefined2 *)(unaff_A6 + -0x72) = 0;
    *(uint *)(unaff_A6 + -0x70) = uVar6;
    *(uint *)(unaff_A6 + -0x6c) = uVar7;
    *(undefined4 *)(unaff_A6 + -0x30) = 1;
  }
  else {
    *(uint *)(unaff_A6 + -0x60) = uVar3;
    *(uint *)(unaff_A6 + -0x5c) = uVar5;
    iVar8 = iVar8 + -0x3ffe;
    *(sword *)(unaff_A6 + -100) = (sword)iVar8;
    *(undefined2 *)(unaff_A6 + -0x62) = 0;
    iVar9 = *(int *)(unaff_A6 + -0x54) + -0x3ffe;
    *(int *)(unaff_A6 + -0x54) = iVar9;
    *(sword *)(unaff_A6 + -0x74) = (sword)iVar9;
    *(uint *)(unaff_A6 + -0x70) = uVar6;
    *(uint *)(unaff_A6 + -0x6c) = uVar7;
    *(undefined4 *)(unaff_A6 + -0x30) = 0;
  }
  if ((((*(int *)(unaff_A6 + -0x44) != 0) &&
       (iVar9 = *(int *)(unaff_A6 + -0x54) + -1, iVar9 <= iVar8)) && (iVar8 <= iVar9)) &&
     (((uVar3 == uVar6 && (uVar5 == uVar7)) && (bVar13)))) {
    *(word *)(unaff_A6 + -0x38) = *(word *)(unaff_A6 + -0x38) ^ 0x8000;
  }
loc_40A1EE6:
  if (*(int *)(unaff_A6 + -0x30) == 0) {
    return 0;
  }
  uVar2 = t_avoid_unsupp();
  return uVar2;
loc_40A1DCE:
  iVar8 = *(int *)(unaff_A6 + -0x54);
  if (uVar3 == 0) {
    iVar9 = (uint)(uVar4 != 0) * LZCOUNT(uVar4);
    uVar3 = uVar4 << iVar9;
    iVar8 = (iVar8 + -0x20) - iVar9;
    uVar5 = 0;
  }
  else {
    iVar9 = (uint)(uVar3 != 0) * LZCOUNT(uVar3);
    uVar5 = uVar4;
    if ((uVar3 & 0x80000000) == 0) {
      iVar8 = iVar8 - iVar9;
      uVar5 = uVar4 << iVar9;
      uVar3 = uVar4 >> (0x20U - iVar9 & 0x3f) | uVar3 << iVar9;
    }
  }
  goto loc_40A1E14;
}

