/* GHIDRADEC_FUNCTION index=2700 start=0x409f8e2 */

void satanhd(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2701 start=0x409f8e8 */

void satanh(void)

{
  undefined (*in_A0) [12];
  float10 fVar1;
  
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    fVar1 = ABS((float10)*in_A0);
    *(float10 *)*in_A0 = (fVar1 + fVar1) / (-fVar1 + (float10)1.0);
    slognp1();
    t_frcinx();
    return;
  }
  if (ABS((float10)*in_A0) - (float10)1.0 != FLOAT_UNKNOWN &&
      FLOAT_UNKNOWN <= ABS((float10)*in_A0) - (float10)1.0) {
    t_operr();
    return;
  }
  t_dz();
  return;
}
/* GHIDRADEC_FUNCTION index=2702 start=0x409f968 */

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
/* GHIDRADEC_FUNCTION index=2703 start=0x409fd86 */

void scoshd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2704 start=0x409fda0 */

void scosh(void)

{
  uint uVar1;
  undefined (*in_A0) [12];
  
  uVar1 = CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
          0x7fffffff;
  if (uVar1 < 0x400cb168) {
    *(float10 *)*in_A0 = ABS((float10)*in_A0);
    setox();
    t_frcinx();
    return;
  }
  if (uVar1 < 0x400cb2b4) {
    *(float10 *)*in_A0 =
         (ABS((float10)*in_A0) - (float10)11354.443964752463) - (float10)8.971359657490228e-13;
    setox();
    t_frcinx();
    return;
  }
  (*in_A0)[0] = (*in_A0)[0] & 0x7f;
  t_ovfl();
  return;
}
/* GHIDRADEC_FUNCTION index=2705 start=0x40a02f8 */

void setoxd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2706 start=0x40a031e */

void setox(void)

{
  int iVar1;
  undefined auVar2 [12];
  uint uVar3;
  sword sVar4;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  uVar3 = *(uint *)*in_A0 & 0x7fff0000;
  if (uVar3 < 0x3fbe0000) {
    t_frcinx();
    return;
  }
  uVar3 = CONCAT22((sword)(uVar3 >> 0x10),*(undefined2 *)(*in_A0 + 4));
  if (uVar3 < 0x400cb167) {
    auVar2 = *in_A0;
    *(undefined4 *)(unaff_A6 + -0x50) = 0;
    *(int *)(unaff_A6 + -0x54) = (int)((float)auVar2 * 92.33248);
    sVar4 = (sword)(*(int *)(unaff_A6 + -0x54) >> 6);
    *(undefined2 *)(unaff_A6 + -0x54) = 0x3fdc;
  }
  else {
    if (0x400cb27c < uVar3) {
      iVar1 = *(int *)*in_A0;
      (*in_A0)[0] = (*in_A0)[0] & 0x7f;
      if (-1 < iVar1) {
        t_ovfl();
        return;
      }
      return;
    }
    auVar2 = *in_A0;
    *(undefined4 *)(unaff_A6 + -0x50) = 1;
    *(int *)(unaff_A6 + -0x54) = (int)((float)auVar2 * 92.33248);
    iVar1 = *(int *)(unaff_A6 + -0x54);
    *(int *)(unaff_A6 + -0x54) = iVar1 >> 6;
    iVar1 = iVar1 >> 7;
    *(int *)(unaff_A6 + -0x54) = *(int *)(unaff_A6 + -0x54) - iVar1;
    *(sword *)(unaff_A6 + -100) = (sword)iVar1 + 0x3fff;
    *(undefined2 *)(unaff_A6 + -0x62) = 0;
    *(undefined4 *)(unaff_A6 + -0x60) = 0x80000000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    sVar4 = (sword)*(undefined4 *)(unaff_A6 + -0x54);
  }
  *(sword *)(unaff_A6 + -0x74) = sVar4 + 0x3fff;
  *(undefined2 *)(unaff_A6 + -0x72) = 0;
  *(undefined4 *)(unaff_A6 + -0x70) = 0x80000000;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2707 start=0x40a04fa */

void setoxm1d(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2708 start=0x40a0500 */

void setoxm1(void)

{
  uint uVar1;
  int iVar2;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  uVar1 = *(uint *)*in_A0 & 0x7fff0000;
  if (0x3ffcffff < uVar1) {
    if (CONCAT22((sword)(uVar1 >> 0x10),*(undefined2 *)(*in_A0 + 4)) < 0x4004c216) {
      *(int *)(unaff_A6 + -0x54) = (int)((float)*in_A0 * 92.33248);
      iVar2 = *(int *)(unaff_A6 + -0x54) >> 6;
      *(int *)(unaff_A6 + -0x54) = iVar2;
      *(sword *)(unaff_A6 + -0x40) = (sword)iVar2 + 0x3fff;
      *(undefined2 *)(unaff_A6 + -0x3e) = 0;
      *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
      *(undefined4 *)(unaff_A6 + -0x38) = 0;
      *(word *)(unaff_A6 + -0x30) = 0x3fffU - (sword)*(undefined4 *)(unaff_A6 + -0x54) | 0x8000;
      *(undefined2 *)(unaff_A6 + -0x2e) = 0;
      *(undefined4 *)(unaff_A6 + -0x2c) = 0x80000000;
      *(undefined4 *)(unaff_A6 + -0x28) = 0;
      t_frcinx();
      return;
    }
    if (0 < *(int *)*in_A0) {
      return;
    }
    t_frcinx();
    return;
  }
  if (0x3fbdffff < uVar1) {
    t_frcinx();
    return;
  }
  if (uVar1 < 0x330000) {
    *(undefined4 *)(unaff_A6 + -0x40) = 0x80010000;
    *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
    *(undefined4 *)(unaff_A6 + -0x38) = 0;
    t_frcinx();
    return;
  }
  *(undefined4 *)(unaff_A6 + -0x40) = 0x80010000;
  *(undefined4 *)(unaff_A6 + -0x3c) = 0x80000000;
  *(undefined4 *)(unaff_A6 + -0x38) = 0;
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2709 start=0x40a07ec */

float10 sgetexp(void)

{
  word *in_A0;
  
  return (float10)(sword)((*in_A0 & 0x7fff) + 0xc001);
}
/* GHIDRADEC_FUNCTION index=2710 start=0x40a07fe */

float10 sgetexpd(void)

{
  byte *in_A0;
  sword *extraout_A0;
  
  *in_A0 = *in_A0 & 0x7f;
  nrm_set();
  return (float10)(*extraout_A0 + -0x3fff);
}
/* GHIDRADEC_FUNCTION index=2711 start=0x40a0818 */

float10 sgetman(void)

{
  undefined (*in_A0) [12];
  
  *(word *)*in_A0 = (*(word *)*in_A0 | 0x7fff) & 0xbfff;
  return (float10)*in_A0;
}
/* GHIDRADEC_FUNCTION index=2712 start=0x40a083c */

void sgetmand(void)

{
  int extraout_A0;
  undefined8 uVar1;
  
  uVar1 = sub_40A0858();
  *(undefined8 *)(extraout_A0 + 4) = uVar1;
  sgetman();
  return;
}
/* GHIDRADEC_FUNCTION index=2713 start=0x40a089c */

void sint(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x54) = (*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c;
  func_0x040a0924();
  return;
}
/* GHIDRADEC_FUNCTION index=2714 start=0x40a08ac */

void sintd(void)

{
  byte *in_A0;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0x7d) & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(unaff_A6 + -0x7d) & 0x10) != 0) {
    if ((*in_A0 & 0x80) == 0) {
      ld_pone();
      t_inx2();
      return;
    }
    ld_mzero();
    t_inx2();
    return;
  }
  if ((*in_A0 & 0x80) != 0) {
    ld_mone();
    t_inx2();
    return;
  }
  ld_pzero();
  t_inx2();
  return;
}
/* GHIDRADEC_FUNCTION index=2715 start=0x40a090c */

void sintrz(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 1;
  func_0x040a0924();
  return;
}
/* GHIDRADEC_FUNCTION index=2716 start=0x40a091a */

float10 sintdo(void)

{
  byte bVar1;
  uint uVar2;
  undefined (*in_A0) [12];
  undefined (*extraout_A0) [12];
  int unaff_A6;
  float10 fVar3;
  
  *(uint *)(unaff_A6 + -0x54) = (*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c;
  bVar1 = (*in_A0)[0];
  (*in_A0)[0] = bVar1 & 0x7f;
  (*in_A0)[2] = -((bVar1 & 0x80) != 0);
  if (0x403e < *(sword *)*in_A0) {
    uVar2 = *(uint *)(*in_A0 + 2) >> 0x18;
    *(uint *)(*in_A0 + 2) = uVar2;
    if (uVar2 != 0) {
      (*in_A0)[0] = (*in_A0)[0] | 0x80;
    }
    return (float10)*in_A0;
  }
  if (0x3ffd < *(sword *)*in_A0) {
    dnrm_lp();
    round();
    nrm_set();
    uVar2 = *(uint *)(*extraout_A0 + 2) >> 0x18;
    *(uint *)(*extraout_A0 + 2) = uVar2;
    if (uVar2 != 0) {
      (*extraout_A0)[0] = (*extraout_A0)[0] | 0x80;
    }
    return (float10)*extraout_A0;
  }
  if ((*(byte *)(unaff_A6 + -0x51) & 2) == 0) {
    if ((*in_A0)[2] == '\0') {
      ld_pzero();
      fVar3 = (float10)t_inx2();
      return fVar3;
    }
    ld_mzero();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  if ((*in_A0)[2] == '\0') {
    if (*(char *)(unaff_A6 + -0x51) != '\x03') {
      ld_pzero();
      fVar3 = (float10)t_inx2();
      return fVar3;
    }
    ld_pone();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  if (*(char *)(unaff_A6 + -0x51) != '\x02') {
    ld_mzero();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  ld_mone();
  fVar3 = (float10)t_inx2();
  return fVar3;
}
/* GHIDRADEC_FUNCTION index=2717 start=0x40a0a5a */

void dz(void)

{
  byte *pbVar1;
  uint auStack_8 [2];
  
  if (_cpu_type == '\0') {
    saveFPUStateFrame(auStack_8[0]);
    if (auStack_8[0]._0_1_ != '\0') {
      pbVar1 = (byte *)((int)auStack_8 + (auStack_8[0] >> 0x10 & 0xff));
      *pbVar1 = *pbVar1 | 8;
    }
    restoreFPUStateFrame(auStack_8[0]);
    std_trap();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2718 start=0x40a0a6a */

void real_dz(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B30F8 = dword_40B30F8 + 1;
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2719 start=0x40a0a86 */

void inex(void)

{
  uint in_FPSR;
  undefined uStack_e0;
  undefined4 uStack_c8;
  
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  saveFPUStateFrame(uStack_c8);
  if (uStack_c8._0_1_ != '@') {
    return;
  }
  if ((uStack_e0 & 4) != 0) {
    if ((in_FPSR & 0x4000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      snan();
      return;
    }
    if ((in_FPSR & 0x1000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      ovfl();
      return;
    }
    if ((in_FPSR & 0x800) != 0) {
      restoreFPUStateFrame(uStack_c8);
      unfl();
      return;
    }
  }
  restoreFPUStateFrame(uStack_c8);
  return;
}
/* GHIDRADEC_FUNCTION index=2720 start=0x40a0b04 */

void real_inex(void)

{
  byte bStack_e0;
  undefined4 uStack_c8;
  
  dword_40B30F4 = dword_40B30F4 + 1;
  saveFPUStateFrame(uStack_c8);
  if ((bStack_e0 & 2) != 0) {
    b1238_fix();
  }
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2721 start=0x40a0b4e */

void ovfl(void)

{
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  fpsp_ovfl();
  return;
}
/* GHIDRADEC_FUNCTION index=2722 start=0x40a0b64 */

void real_ovfl(void)

{
  undefined4 uStack_c8;
  
  dword_40B3100 = dword_40B3100 + 1;
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2723 start=0x40a0b8c */

void unfl(void)

{
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  fpsp_unfl();
  return;
}
/* GHIDRADEC_FUNCTION index=2724 start=0x40a0ba2 */

void real_unfl(void)

{
  undefined4 uStack_c8;
  
  dword_40B30FC = dword_40B30FC + 1;
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2725 start=0x40a0bca */

void snan(void)

{
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  fpsp_snan();
  return;
}
/* GHIDRADEC_FUNCTION index=2726 start=0x40a0be0 */

void real_snan(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B3108 = dword_40B3108 + 1;
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2727 start=0x40a0bfc */

void operr(void)

{
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  fpsp_operr();
  return;
}
/* GHIDRADEC_FUNCTION index=2728 start=0x40a0c12 */

void real_operr(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B3104 = dword_40B3104 + 1;
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2729 start=0x40a0c2e */

void bsun(void)

{
  byte *pbVar1;
  uint auStack_8 [2];
  
  if (_cpu_type == '\0') {
    saveFPUStateFrame(auStack_8[0]);
    if (auStack_8[0]._0_1_ != '\0') {
      pbVar1 = (byte *)((int)auStack_8 + (auStack_8[0] >> 0x10 & 0xff));
      *pbVar1 = *pbVar1 | 8;
    }
    restoreFPUStateFrame(auStack_8[0]);
    std_trap();
    return;
  }
  fpsp_bsun();
  return;
}
/* GHIDRADEC_FUNCTION index=2730 start=0x40a0c6c */

void real_bsun(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B30F0 = dword_40B30F0 + 1;
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2731 start=0x40a0c94 */

void fline(void)

{
  if (_cpu_type == '\0') {
    return;
  }
  fpsp_fline();
  return;
}
/* GHIDRADEC_FUNCTION index=2732 start=0x40a0c9e */

void real_fline(void)

{
  std_trap();
  return;
}
/* GHIDRADEC_FUNCTION index=2733 start=0x40a0caa */

void unsupp(void)

{
  if (_cpu_type == '\0') {
    std_trap();
    return;
  }
  fpsp_unsupp();
  return;
}
/* GHIDRADEC_FUNCTION index=2734 start=0x40a0cc0 */

void real_trace(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2735 start=0x40a0cd2 */

void fpsp_fmt_error(void)

{
                    /* WARNING: Subroutine does not return */
  fpsp_frame_err();
}
/* GHIDRADEC_FUNCTION index=2736 start=0x40a0cd8 */

void mem_write(void)

{
  int in_D0;
  undefined *in_A0;
  undefined *in_A1;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + 4) & 0x20) != 0) {
    do {
      *in_A1 = *in_A0;
      in_D0 = in_D0 + -1;
      in_A0 = in_A0 + 1;
      in_A1 = in_A1 + 1;
    } while (in_D0 != 0);
    return;
  }
  _copyoutmsg();
  return;
}
/* GHIDRADEC_FUNCTION index=2737 start=0x40a0d06 */

void mem_read(void)

{
  int in_D0;
  undefined *in_A0;
  undefined *in_A1;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + 4) & 0x20) != 0) {
    do {
      *in_A1 = *in_A0;
      in_D0 = in_D0 + -1;
      in_A0 = in_A0 + 1;
      in_A1 = in_A1 + 1;
    } while (in_D0 != 0);
    return;
  }
  _copyinmsg();
  return;
}
/* GHIDRADEC_FUNCTION index=2738 start=0x40a0d54 */

int slog10d(void)

{
  int iVar1;
  int *in_A0;
  
  if (-1 < *in_A0) {
    slognd();
    iVar1 = t_frcinx();
    return iVar1;
  }
  return *in_A0;
}
/* GHIDRADEC_FUNCTION index=2739 start=0x40a0d78 */

int slog10(void)

{
  int iVar1;
  int *in_A0;
  
  if (-1 < *in_A0) {
    slogn();
    iVar1 = t_frcinx();
    return iVar1;
  }
  return *in_A0;
}
/* GHIDRADEC_FUNCTION index=2740 start=0x40a0d9c */

int slog2d(void)

{
  int iVar1;
  int *in_A0;
  
  if (-1 < *in_A0) {
    slognd();
    iVar1 = t_frcinx();
    return iVar1;
  }
  return *in_A0;
}
/* GHIDRADEC_FUNCTION index=2741 start=0x40a0dc0 */

void slog2(void)

{
  int *in_A0;
  
  if (*in_A0 < 0) {
    t_operr();
    return;
  }
  if ((in_A0[2] == 0) && ((in_A0[1] & 0x7fffffffU) == 0)) {
    t_frcinx();
    return;
  }
  slogn();
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2742 start=0x40a16c2 */

void slognd(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 0xffffff9c;
  iVar2 = *(int *)(in_A0 + 4);
  uVar1 = *(uint *)(in_A0 + 8);
  if (iVar2 == 0) {
    iVar2 = (uint)(uVar1 != 0) * LZCOUNT(uVar1);
    *(undefined4 *)(unaff_A6 + -0x74) = 0;
    *(uint *)(unaff_A6 + -0x70) = uVar1 << iVar2;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    *(int *)(unaff_A6 + -0x54) = -(iVar2 + 0x20);
    func_0x040a1764();
    return;
  }
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  *(undefined4 *)(unaff_A6 + -0x74) = 0;
  *(uint *)(unaff_A6 + -0x70) = uVar1 >> (0x20U - iVar3 & 0x3f) | iVar2 << iVar3;
  *(uint *)(unaff_A6 + -0x6c) = uVar1 << iVar3;
  *(int *)(unaff_A6 + -0x54) = -iVar3;
  func_0x040a1764();
  return;
}
/* GHIDRADEC_FUNCTION index=2743 start=0x40a1758 */

void slogn(void)

{
  int iVar1;
  undefined auVar2 [12];
  float fVar3;
  sword sVar4;
  undefined (*in_A0) [12];
  int unaff_A6;
  int iVar5;
  
  auVar2 = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  iVar1 = *(int *)*in_A0;
  sVar4 = (sword)((uint)iVar1 >> 0x10);
  iVar5 = CONCAT22(sVar4,*(undefined2 *)(*in_A0 + 4));
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)*in_A0;
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(*in_A0 + 4);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(*in_A0 + 8);
  if (iVar1 < 0) {
    t_operr();
    return;
  }
  if (iVar5 < iRam3ffef07d || iRam3ffef081 < iVar5) {
    *(undefined4 *)(unaff_A6 + -0x74) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -0x70);
    *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) & 0xfe000000;
    *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) | 0x1000000;
    *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    *(undefined (*) [12])(unaff_A6 + -0x40) =
         (undefined  [12])
         ((float10)(*(int *)(unaff_A6 + -0x54) + sVar4 + -0x3fff) * (float10)tbyte_40A0E32);
    t_frcinx();
    return;
  }
  fVar3 = (float)auVar2 - 1.0;
  *(undefined (*) [12])(unaff_A6 + -0x30) =
       (undefined  [12])((fVar3 + fVar3) / ((float)auVar2 + 1.0));
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2744 start=0x40a191c */

void slognp1d(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2745 start=0x40a1922 */

void slognp1(void)

{
  int iVar1;
  undefined auVar2 [12];
  undefined (*in_A0) [12];
  int unaff_A6;
  
  if (ABS((float10)*in_A0) - (float10)tbyte_40A0EB2 == FLOAT_UNKNOWN ||
      ABS((float10)*in_A0) - (float10)tbyte_40A0EB2 < FLOAT_UNKNOWN) {
    t_frcinx();
    return;
  }
  auVar2 = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])((float)auVar2 + 1.0);
  *(undefined2 *)(unaff_A6 + -0x72) = *(undefined2 *)(unaff_A6 + -0x70);
  iVar1 = *(int *)(unaff_A6 + -0x74);
  if (iVar1 < 1) {
    if (-1 < iVar1) {
      t_dz();
      return;
    }
    t_operr();
    return;
  }
  if (iVar1 < iRam3ffe8000 || iRam3ffe8004 < iVar1) {
    return;
  }
  if (iRam3ffef07d <= iVar1 && iVar1 <= iRam3ffef081) {
    func_0x040a189c();
    return;
  }
  *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -0x70);
  *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) & 0xfe000000;
  *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) | 0x1000000;
  if (iVar1 < 0x3fff8000) {
    *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    func_0x040a17f8();
    return;
  }
  *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
  *(undefined4 *)(unaff_A6 + -0x5c) = 0;
  func_0x040a17f8();
  return;
}
/* GHIDRADEC_FUNCTION index=2746 start=0x40a1a9a */

float10 smovcr(void)

{
  byte bVar3;
  uint uVar1;
  int iVar2;
  byte bVar4;
  code *pcVar5;
  float10 *extraout_A0;
  int unaff_A6;
  
  uVar1 = (*(uint *)(unaff_A6 + -0xe4) & 0x7fffff) >> 0x10;
  bVar3 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 9) >> 0x19);
  bVar4 = (byte)((*(uint *)(unaff_A6 + -0x80) << 0x1a) >> 0x1e);
  if (bVar3 == 0) {
    if (bVar4 == 0) {
      pcVar5 = pirn;
    }
    else if (bVar4 == 3) {
      pcVar5 = pirp;
    }
    else {
      pcVar5 = pirzrm;
    }
  }
  else {
    if (bVar3 < 0xb) {
loc_40A1AD6:
      return (float10)0.0;
    }
    if (bVar3 < 0xf) {
      uVar1 = uVar1 - 0xb;
      if (bVar4 == 0) {
        pcVar5 = (code *)&smalrn;
      }
      else if (bVar4 == 3) {
        pcVar5 = (code *)&smalrp;
      }
      else {
        pcVar5 = (code *)&smalrzrm;
      }
      if ('\x02' < (char)uVar1) goto loc_40A1BEA;
    }
    else {
      if ((bVar3 < 0x30) || (0x3f < bVar3)) goto loc_40A1AD6;
      uVar1 = uVar1 - 0x30;
      if (bVar4 == 0) {
        pcVar5 = (code *)&bigrn;
      }
      else if (bVar4 == 3) {
        pcVar5 = (code *)&bigrp;
      }
      else {
        pcVar5 = (code *)&bigrzrm;
      }
      if (('\x01' < (char)uVar1) && ((char)uVar1 < '\b')) goto loc_40A1BEA;
    }
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
loc_40A1BEA:
  iVar2 = uVar1 * 0xc;
  *(uint *)(unaff_A6 + -0x54) = (*(uint *)(unaff_A6 + -0x80) & 0x3f) >> 4;
  if ((*(uint *)(unaff_A6 + -0x80) & 0xff) >> 6 != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(pcVar5 + iVar2);
    *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(pcVar5 + iVar2 + 4);
    *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(pcVar5 + iVar2 + 8);
    *(char *)(unaff_A6 + -0x72) = -((*(byte *)(unaff_A6 + -0x74) & 0x80) != 0);
    round();
    uVar1 = *(uint *)((int)extraout_A0 + 2) >> 0x18;
    *(uint *)((int)extraout_A0 + 2) = uVar1;
    if (uVar1 != 0) {
      *(byte *)extraout_A0 = *(byte *)extraout_A0 | 0x80;
    }
    return *extraout_A0;
  }
  return *(float10 *)(pcVar5 + iVar2);
}
/* GHIDRADEC_FUNCTION index=2747 start=0x40a1c62 */

void smod(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x44) = 0;
  func_0x040a1c78();
  return;
}
/* GHIDRADEC_FUNCTION index=2748 start=0x40a1c70 */

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
/* GHIDRADEC_FUNCTION index=2749 start=0x40a2062 */

void ssind(void)

{
  t_extdnrm();
  return;
}

