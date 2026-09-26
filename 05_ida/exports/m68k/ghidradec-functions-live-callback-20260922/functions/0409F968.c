
float10 sscale(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 in_D0;
  uint uVar4;
  int iVar5;
  word wVar7;
  uint uVar6;
  uint uVar8;
  int iVar9;
  int unaff_A6;
  float10 fVar10;
  
  *(char *)(unaff_A6 + -0x54) = -((sword)*(word *)(unaff_A6 + -0xd8) < 0);
  uVar6 = *(word *)(unaff_A6 + -0xd8) & 0x7fff;
  uVar4 = CONCAT22((sword)((uint)in_D0 >> 0x10),*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
  if ((int)uVar4 < (int)sRam00003fff || (int)sRam00004001 < (int)uVar4) {
    if ((*(word *)(unaff_A6 + -0xcc) & 0x7fff) < 0x400c) {
      if ((*(byte *)(unaff_A6 + -0xe0) & 0xe0) != 0) {
        *(undefined *)(unaff_A6 + -0x4c) = 0xff;
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
        fVar10 = (float10)t_resdnrm();
        return fVar10;
      }
      return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
    }
    if (*(char *)(unaff_A6 + -0x54) != '\0') {
      uVar6 = uVar6 | 0x8000;
    }
    *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0xd4);
    *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0xd0);
    if (-1 < *(sword *)(unaff_A6 + -0xcc)) {
      *(sword *)(unaff_A6 + -0xcc) = (sword)uVar6;
      fVar10 = (float10)t_ovfl2();
      return fVar10;
    }
    *(sword *)(unaff_A6 + -0xcc) = (sword)uVar6;
    fVar10 = (float10)t_unfl();
    return fVar10;
  }
  iVar5 = (int)*(undefined (*) [12])(unaff_A6 + -0xcc);
  if (*(sword *)(unaff_A6 + -0xcc) < 0) {
    uVar4 = iVar5 + uVar6;
    wVar7 = (word)uVar4;
    if (uVar4 != 0) {
      if (SCARRY4(iVar5,uVar6) == (int)uVar4 < 0) {
        if (*(char *)(unaff_A6 + -0x54) != '\0') {
          wVar7 = wVar7 | 0x8000;
        }
        *(word *)(unaff_A6 + -0xd8) = wVar7;
        return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
      }
      if (-0x41 < (sword)wVar7) {
        uVar4 = uVar4 & 0xffff;
        uVar6 = *(uint *)(unaff_A6 + -0xd4);
        uVar8 = *(uint *)(unaff_A6 + -0xd0);
        *(undefined4 *)(unaff_A6 + -0x50) = 0;
        do {
          wVar7 = (sword)uVar4 + 1;
          uVar4 = (uint)wVar7;
          uVar2 = uVar6 & 1;
          uVar6 = uVar6 >> 1;
          uVar3 = uVar8 & 1;
          uVar8 = (uint)(uVar2 != 0) << 0x1f | uVar8 >> 1;
          if (uVar3 != 0) {
            *(undefined *)(unaff_A6 + -0x50) = 0xff;
          }
        } while ((sword)wVar7 < 0);
        if (*(char *)(unaff_A6 + -0x50) != '\0') {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x828;
        }
        *(undefined2 *)(unaff_A6 + -0xd8) = 0;
        if (*(char *)(unaff_A6 + -0x54) != '\0') {
          *(word *)(unaff_A6 + -0xd8) = *(word *)(unaff_A6 + -0xd8) | 0x8000;
        }
        *(uint *)(unaff_A6 + -0xd4) = uVar6;
        *(uint *)(unaff_A6 + -0xd0) = uVar8;
        if ((uVar6 != 0) || (*(int *)(unaff_A6 + -0xd0) != 0)) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
          if (*(char *)(unaff_A6 + -0x54) != '\0') {
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
          }
          goto loc_409FBA6;
        }
        if ((*(byte *)(unaff_A6 + -0x7d) & 0x20) == 0) {
loc_409FB98:
          return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
        }
        if ((*(byte *)(unaff_A6 + -0x7d) & 0x10) == 0) {
          if (*(char *)(unaff_A6 + -0x54) == '\0') goto loc_409FB98;
          *(undefined4 *)(unaff_A6 + -0xd0) = 1;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
        else {
          if (*(char *)(unaff_A6 + -0x54) != '\0') goto loc_409FB98;
          *(undefined4 *)(unaff_A6 + -0xd0) = 1;
        }
        goto loc_409FBA6;
      }
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x828;
      if ((*(byte *)(unaff_A6 + -0x7d) & 0x20) != 0) {
        if ((*(byte *)(unaff_A6 + -0x7d) & 0x10) == 0) {
          if (*(char *)(unaff_A6 + -0x54) != '\0') {
            *(undefined2 *)(unaff_A6 + -0xd8) = 0x8000;
            *(undefined4 *)(unaff_A6 + -0xd4) = 0;
            *(undefined4 *)(unaff_A6 + -0xd0) = 1;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            goto loc_409FBA6;
          }
        }
        else if (*(char *)(unaff_A6 + -0x54) == '\0') {
          *(undefined4 *)(unaff_A6 + -0xd8) = 0;
          *(undefined4 *)(unaff_A6 + -0xd4) = 0;
          *(undefined4 *)(unaff_A6 + -0xd0) = 1;
loc_409FBA6:
          *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)(unaff_A6 + -0xd8);
          *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0xd4);
          *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0xd0);
          fVar10 = (float10)t_resdnrm();
          return fVar10;
        }
      }
      if (*(char *)(unaff_A6 + -0x54) < '\0') {
        *(undefined4 *)(unaff_A6 + -0x74) = 0;
        *(undefined4 *)(unaff_A6 + -0x70) = 0;
        *(undefined4 *)(unaff_A6 + -0x6c) = 0;
        return (float10)-0.0;
      }
      *(undefined4 *)(unaff_A6 + -0x74) = 0;
      *(undefined4 *)(unaff_A6 + -0x70) = 0;
      *(undefined4 *)(unaff_A6 + -0x6c) = 0;
      return (float10)0.0;
    }
  }
  else {
    if ((sword)uVar6 == 0) {
      wVar7 = *(word *)(unaff_A6 + -0xd8);
      uVar6 = *(uint *)(unaff_A6 + -0xd4);
      iVar9 = *(int *)(unaff_A6 + -0xd0);
      while( true ) {
        if ((int)uVar6 < 0) {
          wVar7 = (sword)iVar5 + wVar7;
          if (*(char *)(unaff_A6 + -0x54) != '\0') {
            wVar7 = wVar7 | 0x8000;
          }
          *(word *)(unaff_A6 + -0xd8) = wVar7;
          *(uint *)(unaff_A6 + -0xd4) = uVar6;
          *(int *)(unaff_A6 + -0xd0) = iVar9;
          return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
        }
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar1 = iVar9 < 0;
        iVar9 = iVar9 << 1;
        uVar6 = uVar6 << 1 | (uint)bVar1;
      }
      if (*(char *)(unaff_A6 + -0x54) != '\0') {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        wVar7 = wVar7 | 0x8000;
      }
      *(word *)(unaff_A6 + -0xcc) = wVar7;
      *(uint *)(unaff_A6 + -200) = uVar6;
      *(int *)(unaff_A6 + -0xc4) = iVar9;
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
      fVar10 = (float10)t_resdnrm();
      return fVar10;
    }
    uVar4 = iVar5 + uVar6;
    if (uVar4 != 0) {
      if ((int)uVar4 < 0x7fff) {
        if (*(char *)(unaff_A6 + -0x54) != '\0') {
          uVar4 = (uint)(word)((word)uVar4 | 0x8000);
        }
        *(sword *)(unaff_A6 + -0xd8) = (sword)uVar4;
        return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
      }
      *(undefined2 *)(unaff_A6 + -0xcc) = *(undefined2 *)(unaff_A6 + -0xd8);
      *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0xd4);
      *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0xd0);
      fVar10 = (float10)t_ovfl2();
      return fVar10;
    }
  }
  wVar7 = (sword)iVar5 + (sword)uVar6;
  if (*(char *)(unaff_A6 + -0x54) != '\0') {
    wVar7 = wVar7 | 0x8000;
  }
  if (-1 < *(int *)(unaff_A6 + -0xd4)) {
    *(word *)(unaff_A6 + -0xcc) = wVar7;
    *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0xd4);
    *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0xd0);
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 3;
    fVar10 = (float10)t_resdnrm();
    return fVar10;
  }
  *(word *)(unaff_A6 + -0xd8) = wVar7;
  return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
}

