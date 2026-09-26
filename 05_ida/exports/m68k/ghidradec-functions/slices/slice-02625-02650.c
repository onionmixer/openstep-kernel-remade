/* GHIDRADEC_FUNCTION index=2625 start=0x409aa92 */

undefined8 __umoddi3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uStack_2c;
  undefined auStack_24 [8];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = param_1;
  uStack_8 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  __bdiv(&uStack_14,&uStack_1c,auStack_24,&uStack_2c,0x10,8);
  return uStack_2c;
}
/* GHIDRADEC_FUNCTION index=2626 start=0x409aaf6 */

void _pagemove(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_3 % _page_size != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aPagemove);
  }
  uVar1 = *(undefined4 *)(_kernel_map + 0x20);
  for (; 0 < (int)param_3; param_3 = param_3 - _m68k_page_size) {
    while (puVar2 = (undefined4 *)_pmap_pte(uVar1,param_1), (int)puVar2 < 0) {
      _pmap_expand_kernel(param_1,puVar2);
    }
    while (puVar3 = (undefined4 *)_pmap_pte(uVar1,param_2), (int)puVar3 < 0) {
      _pmap_expand_kernel(param_2,puVar3);
    }
    *puVar3 = *puVar2;
    *puVar2 = 0;
    _pflush_user();
    _pflush_user();
    param_1 = _m68k_page_size + param_1;
    param_2 = _m68k_page_size + param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2627 start=0x409ac0c */

float10 bindec(void)

{
  sword sVar1;
  int in_D0;
  word wVar3;
  uint uVar2;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined (*in_A0) [12];
  int unaff_A6;
  float10 fVar7;
  float10 fVar8;
  
  *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)*in_A0;
  *(undefined *)(unaff_A6 + -0x4b) = 0;
  if ((*(word *)(unaff_A6 + -0xe8) & 0xe000) != 0) {
    wVar3 = *(word *)*in_A0 & 0x7fff;
    uVar2 = *(uint *)(*in_A0 + 4);
    iVar4 = *(int *)(*in_A0 + 8);
    do {
      wVar3 = wVar3 - 1;
      bVar6 = iVar4 < 0;
      iVar4 = iVar4 << 1;
      uVar2 = uVar2 << 1 | (uint)bVar6;
    } while (-1 < (int)uVar2);
    if ((sword)wVar3 < 1) {
      *(undefined *)(unaff_A6 + -0x4b) = 0xff;
    }
    *(word *)*in_A0 = wVar3 & 0x7fff;
    *(uint *)(*in_A0 + 4) = uVar2;
    *(int *)(*in_A0 + 8) = iVar4;
  }
  *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)*in_A0;
  *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(*in_A0 + 4);
  *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(*in_A0 + 8);
  *(uint *)(unaff_A6 + -100) = *(uint *)(unaff_A6 + -100) & 0x7fffffff;
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    sVar1 = *(sword *)(unaff_A6 + -100);
    *(undefined2 *)(unaff_A6 + -100) = 0x3fff;
    fVar8 = (float10)*(undefined (*) [12])(unaff_A6 + -100);
    fVar7 = (fVar8 + (float10)(sVar1 + -0x3fff)) - (float10)1.0;
    if (fVar8 == FLOAT_UNKNOWN || FLOAT_UNKNOWN <= fVar8) {
      iVar4 = (int)(fVar7 * (float10)tbyte_409AB9C);
    }
    else {
      iVar4 = (int)(fVar7 * (float10)tbyte_409ABAC);
    }
  }
  else {
    iVar4 = -0x1345;
  }
  iVar5 = in_D0;
  if (in_D0 < 1) {
    iVar5 = (iVar4 - in_D0) + 1;
  }
  if (iVar5 < 1) {
    iVar5 = 1;
  }
  else if ((0x11 < iVar5) && (iVar5 = 0x11, 0 < in_D0)) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2080;
  }
  if ((in_D0 < 1) && (iVar4 <= in_D0)) {
    iVar4 = in_D0;
  }
  uVar2 = (iVar4 + 1) - iVar5;
  bVar6 = false;
  if ((int)uVar2 < 0) {
    bVar6 = true;
    if ((int)uVar2 < -0x132b) {
      uVar2 = uVar2 + 0x18;
    }
    uVar2 = -uVar2;
  }
  do {
    uVar2 = uVar2 >> 1;
  } while (uVar2 != 0);
  if (bVar6) {
    return ABS((float10)*in_A0);
  }
  fVar8 = (float10)func_0x0409ae78();
  return fVar8;
}
/* GHIDRADEC_FUNCTION index=2628 start=0x409ae10 */

/* WARNING: Removing unreachable block (ram,0x0409af82) */

unkbyte10 sc_mul(void)

{
  undefined (*pauVar1) [12];
  uint uVar2;
  float fVar3;
  undefined4 *puVar4;
  uint uVar5;
  word wVar6;
  undefined4 in_D1;
  sword unaff_D2w;
  sword sVar8;
  int iVar7;
  uint unaff_D4;
  undefined4 unaff_D5;
  int unaff_D6;
  int unaff_D7;
  undefined4 *in_A0;
  int in_A1;
  int iVar9;
  int extraout_A1;
  int unaff_A6;
  uint in_FPSR;
  float10 in_FP0;
  float10 fVar10;
  unkbyte10 Var11;
  unkint10 Var12;
  float10 in_FP1;
  float10 fVar13;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    if (unaff_D2w != 0) {
      in_FP0 = in_FP0 * (float10)*(undefined (*) [12])(in_A1 + 0x24) *
               (float10)*(undefined (*) [12])(in_A1 + 0x30);
    }
    fVar10 = in_FP0 * in_FP1;
  }
  else {
    uStack_10 = in_A0[2];
    uStack_14 = in_A0[1];
    uStack_18 = *in_A0;
    sVar8 = 0x12;
    puVar4 = &uStack_18;
    do {
      register0x0000003c = (BADSPACEBASE *)puVar4;
      *(undefined4 *)((int)register0x0000003c + -4) = 0;
      sVar8 = sVar8 + -1;
      puVar4 = (undefined4 *)((int)register0x0000003c + -4);
    } while (sVar8 != -1);
    *(undefined *)((int)register0x0000003c + -4) = *(undefined *)(unaff_A6 + -0x45);
    *(undefined *)((int)register0x0000003c + -3) = 0x60;
    *(undefined *)((int)register0x0000003c + 0x40) = 0x10;
    *(undefined2 *)((int)register0x0000003c + 0x3c) = 0x23;
    *(undefined *)((int)register0x0000003c + 4) = 0xfe;
    restoreFPUStateFrame(*(undefined4 *)((int)register0x0000003c + -4));
    fVar10 = in_FP0 * (float10)*(undefined (*) [12])(in_A1 + 0x24) *
             (float10)*(undefined (*) [12])(in_A1 + 0x30);
  }
  *(undefined (*) [12])(unaff_A6 + -100) = (undefined  [12])fVar10;
  if ((in_FPSR & 0x200) != 0) {
    *(uint *)(unaff_A6 + -0x5c) = *(uint *)(unaff_A6 + -0x5c) | 1;
    fVar10 = (float10)*(undefined (*) [12])(unaff_A6 + -100);
  }
  *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0x80);
  *(uint *)(unaff_A6 + -0x80) = *(uint *)(unaff_A6 + -0x80) & 0x30;
  *(int *)((int)register0x0000003c + -4) = in_A1;
  *(undefined4 **)((int)register0x0000003c + -8) = in_A0;
  *(undefined4 *)((int)register0x0000003c + -0xc) = in_D1;
  *(uint *)((int)register0x0000003c + -0x10) = in_FPSR;
  *(undefined4 *)((int)register0x0000003c + -0x14) = *(undefined4 *)(unaff_A6 + -0x54);
  *(undefined4 *)((int)register0x0000003c + -0x18) = *(undefined4 *)(unaff_A6 + -0x50);
  pauVar1 = (undefined (*) [12])(unaff_A6 + -100);
  *pauVar1 = (undefined  [12])fVar10;
  if (*(int *)(unaff_A6 + -0x50) < 0) {
    *(uint *)*pauVar1 = *(uint *)*pauVar1 | 0x80000000;
  }
  *(undefined4 *)((int)register0x0000003c + -0x1c) = *(undefined4 *)(unaff_A6 + -0x7c);
  *(undefined4 *)((int)register0x0000003c + -0x20) = 0x409aeda;
  fVar10 = (float10)sintdo();
  *(undefined *)(unaff_A6 + -0x7c) = *(undefined *)((int)register0x0000003c + -0x1c);
  *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)((int)register0x0000003c + -0x18);
  *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)((int)register0x0000003c + -0x14);
  iVar9 = *(int *)((int)register0x0000003c + -4);
  *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(unaff_A6 + -0x50);
  *(undefined4 *)(unaff_A6 + -0x80) = *(undefined4 *)(unaff_A6 + -0x54);
  if ((sword)((uint)unaff_D5 >> 0x10) == 0) {
    fVar13 = (float10)1.0;
    uVar5 = unaff_D4 - 1;
    iVar7 = 0;
    do {
      uVar2 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar2 != 0) {
        fVar13 = fVar13 * (float10)*(undefined (*) [12])(iVar9 + iVar7);
      }
      iVar7 = iVar7 + 0xc;
    } while (uVar5 != 0);
    if ((*(char *)(unaff_A6 + -0x4b) == '\0') &&
       (ABS(fVar10) - fVar13 != FLOAT_UNKNOWN && ABS(fVar10) - fVar13 < FLOAT_UNKNOWN)) {
      Var11 = func_0x0409ace6();
      return Var11;
    }
    fVar10 = ABS(fVar10);
    fVar13 = fVar13 * (float10)10.0;
    if (FLOAT_UNKNOWN <= fVar10 - fVar13 || fVar10 - fVar13 == FLOAT_UNKNOWN) {
      Var11 = func_0x0409ace6();
      return Var11;
    }
  }
  else {
    fVar13 = (float10)1.0;
    iVar7 = 0;
    do {
      uVar5 = unaff_D4 & 1;
      unaff_D4 = unaff_D4 >> 1;
      if (uVar5 != 0) {
        fVar13 = fVar13 * (float10)*(undefined (*) [12])(iVar9 + iVar7);
      }
      iVar7 = iVar7 + 0xc;
    } while (unaff_D4 != 0);
    fVar10 = ABS(fVar10);
    if (fVar10 - fVar13 == FLOAT_UNKNOWN) {
      fVar10 = fVar10 / (float10)10.0;
      unaff_D6 = unaff_D6 + 1;
      fVar13 = fVar13 * (float10)10.0;
    }
  }
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(fVar10 / fVar13);
  *(undefined4 *)(unaff_A6 + -0x70) = 0;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  uVar5 = *(uint *)*(undefined (*) [12])(unaff_A6 + -0x74);
  uVar5 = uVar5 << 0x10 | uVar5 >> 0x10;
  if ((uVar5 != 0) && (iVar9 = uVar5 - 0x3ffd, iVar9 < 1)) {
    uVar5 = -iVar9;
    do {
      wVar6 = (sword)uVar5 - 1;
      uVar5 = (uint)wVar6;
    } while (wVar6 != 0xffff);
  }
  *(undefined4 *)((int)register0x0000003c + -4) = 0x409b060;
  Var12 = binstr();
  if (*(char *)(unaff_A6 + -0x4b) == '\0') {
    if (Var12 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = ABS((float)unaff_D6);
    }
  }
  else if (Var12 == 0) {
    if (unaff_D7 < 0) {
      fVar3 = ABS((float)unaff_D6);
    }
    else {
      fVar3 = 4933.0;
    }
  }
  else {
    fVar3 = ABS((float)unaff_D6);
  }
  *(undefined (*) [12])(unaff_A6 + -100) =
       (undefined  [12])(fVar3 / (float)*(undefined (*) [12])(extraout_A1 + 0x18));
  if (*(sword *)(unaff_A6 + -100) != 0) {
    sVar8 = -(*(sword *)(unaff_A6 + -100) + -0x3ffd);
    do {
      sVar8 = sVar8 + -1;
    } while (sVar8 != -1);
  }
  *(undefined4 *)((int)register0x0000003c + -4) = 0x409b10c;
  binstr();
  uVar5 = *(uint *)(unaff_A6 + -0x54);
  *(uint *)(unaff_A6 + -0x74) =
       *(uint *)(unaff_A6 + -0x74) & 0xf000ffff | (uVar5 >> 0xc & 0xfff) << 0x10;
  *(uint *)(unaff_A6 + -0x74) =
       *(uint *)(unaff_A6 + -0x74) & 0xffff0fff | (uVar5 >> 0x18 & 0xf) << 0xc;
  if ((char)(uVar5 >> 0x18) != '\0') {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2080;
  }
  iVar9 = 0;
  *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) & 0xf;
  if (*(int *)(unaff_A6 + -0x50) < 0) {
    iVar9 = 2;
  }
  if (unaff_D6 < 0) {
    iVar9 = iVar9 + 1;
  }
  *(uint *)(unaff_A6 + -0x74) = *(uint *)(unaff_A6 + -0x74) & 0x3fffffff | iVar9 << 0x1e;
  return *(unkbyte10 *)register0x0000003c;
}
/* GHIDRADEC_FUNCTION index=2629 start=0x409b168 */

undefined8 binstr(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  int in_D0;
  uint uVar6;
  undefined4 in_D1;
  sword sVar8;
  uint unaff_D2;
  uint unaff_D3;
  sword sVar9;
  char *in_A0;
  bool bVar10;
  word wVar7;
  
  bVar4 = true;
  uVar6 = in_D0 - 1;
  sVar9 = 0;
  do {
    while( true ) {
      uVar3 = unaff_D3 >> 0x1d;
      bVar1 = (int)unaff_D3 < 0;
      uVar2 = unaff_D2 & 0x80000000;
      uVar5 = unaff_D2 >> 0x1d;
      bVar10 = CARRY4(unaff_D3 * 2,unaff_D3 * 8);
      unaff_D3 = unaff_D3 * 10;
      unaff_D2 = (unaff_D2 << 1 | (uint)bVar1) + (uVar3 | unaff_D2 << 3) + (uint)bVar10;
      sVar8 = (word)uVar5 + (word)(uVar2 != 0) + (word)bVar10;
      if (!bVar4) break;
      sVar9 = sVar8 + sVar9 * 0x10;
      *in_A0 = (char)sVar9;
      bVar4 = false;
      wVar7 = (sword)uVar6 - 1;
      uVar6 = (uint)wVar7;
      in_A0 = in_A0 + 1;
      if (wVar7 == 0xffff) goto loc_409B1C6;
    }
    bVar4 = true;
    wVar7 = (sword)uVar6 - 1;
    uVar6 = (uint)wVar7;
    sVar9 = sVar8;
  } while (wVar7 != 0xffff);
  *in_A0 = (char)sVar8 * '\x10';
loc_409B1C6:
  return CONCAT44(in_D0,in_D1);
}
/* GHIDRADEC_FUNCTION index=2630 start=0x409b1cc */

void b1238_fix(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  byte bVar4;
  sword sVar3;
  byte bVar5;
  int unaff_A6;
  undefined *puVar6;
  undefined *puVar7;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  undefined4 in_stack_00000000;
  undefined4 auStack_c [3];
  
  if ((param_1._0_1_ == '@') && ((*(byte *)(unaff_A6 + -0x11c) & 0xfe) != 0)) {
    if ((*(word *)(unaff_A6 + -0xe4) & 0xe000) == 0) {
      bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xf0) << 6) >> 0x1d);
      if ((bVar5 == (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d)) ||
         (bVar4 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 6) >> 0x1d), bVar5 == bVar4)) {
        fmovem(*(undefined4 *)(unaff_A6 + -0xcc),
               1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a) & 0x1f));
        *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x48000000;
        if ((*(byte *)(unaff_A6 + -0xcc) & 0x40) == 0) {
          *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x10;
        }
        else {
          *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) & 0xef;
        }
      }
      else {
        bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xf4) << 6) >> 0x1d);
        if ((bVar5 == bVar4) || (bVar5 == (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d)))
        {
          *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0xe8);
          *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)(unaff_A6 + -0xe4);
          *(undefined4 *)(unaff_A6 + -0x44) = *(undefined4 *)(unaff_A6 + -0xe0);
          *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0xe0000000;
          *(undefined *)(unaff_A6 + -0x11c) = 0;
          restoreFPUStateFrame(param_1);
          saveFPUStateFrame(param_1);
          if (param_1._0_2_ == 0x4060) {
            fpsp_fmt_error();
            return;
          }
          uVar1 = (*(uint *)(unaff_A6 + -0xf4) & 0x3ffffff) >> 0x17;
          if (uVar1 < 4) {
            if (uVar1 == 3) {
              *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
            }
            else if (uVar1 == 0) {
              *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
            }
            else if (uVar1 == 1) {
              *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
            }
            else {
              *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
            }
          }
          sVar3 = 0x16;
          puVar2 = &param_1;
          do {
            puVar6 = (undefined *)puVar2;
            *(undefined4 *)(puVar6 + -4) = 0;
            sVar3 = sVar3 + -1;
            puVar2 = (undefined4 *)(puVar6 + -4);
          } while (sVar3 != -1);
          *(undefined4 *)(puVar6 + -8) = 0x40600000;
          *(undefined4 *)(unaff_A6 + -0xe8) = *(undefined4 *)(unaff_A6 + -0x54);
          *(undefined4 *)(unaff_A6 + -0xe4) = *(undefined4 *)(unaff_A6 + -0x50);
          *(undefined4 *)(unaff_A6 + -0xe0) = *(undefined4 *)(unaff_A6 + -0x44);
          *(undefined *)(unaff_A6 + -0x11c) = 6;
          *(undefined4 *)(puVar6 + -0xc) = in_stack_00000000;
          fmovem(*(undefined4 *)(unaff_A6 + -0xcc),
                 1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a) & 0x1f));
          *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x48000000;
          if ((*(byte *)(unaff_A6 + -0xcc) & 0x40) == 0) {
            *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x10;
          }
          else {
            *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) & 0xef;
          }
        }
      }
    }
    else if ((*(word *)(unaff_A6 + -0xe4) & 0xfc00) == 0x4400) {
      bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 6) >> 0x1d);
      if ((byte)((uint)(*(int *)(unaff_A6 + -0xf0) << 6) >> 0x1d) != bVar5) {
        if ((byte)((uint)(*(int *)(unaff_A6 + -0xf4) << 6) >> 0x1d) != bVar5) {
          return;
        }
        *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0xe8);
        *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)(unaff_A6 + -0xe4);
        *(undefined4 *)(unaff_A6 + -0x44) = *(undefined4 *)(unaff_A6 + -0xe0);
        *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0xe0000000;
        *(undefined *)(unaff_A6 + -0x11c) = 0;
        *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(unaff_A6 + -0xc4);
        restoreFPUStateFrame(param_1);
        saveFPUStateFrame(param_1);
        if (param_1._0_2_ == 0x4060) {
          fpsp_fmt_error();
          return;
        }
        uVar1 = (*(uint *)(unaff_A6 + -0xf4) & 0x3ffffff) >> 0x17;
        if (uVar1 < 4) {
          if (uVar1 == 3) {
            *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
          }
          else if (uVar1 == 0) {
            *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
          }
          else if (uVar1 == 1) {
            *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
          }
          else {
            *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
          }
        }
        sVar3 = 0x16;
        puVar2 = &param_1;
        do {
          puVar7 = (undefined *)puVar2;
          *(undefined4 *)(puVar7 + -4) = 0;
          sVar3 = sVar3 + -1;
          puVar2 = (undefined4 *)(puVar7 + -4);
        } while (sVar3 != -1);
        *(undefined4 *)(puVar7 + -8) = 0x40600000;
        *(undefined4 *)(unaff_A6 + -0xe8) = *(undefined4 *)(unaff_A6 + -0x54);
        *(undefined4 *)(unaff_A6 + -0xe4) = *(undefined4 *)(unaff_A6 + -0x50);
        *(undefined4 *)(unaff_A6 + -0xe0) = *(undefined4 *)(unaff_A6 + -0x44);
        *(undefined *)(unaff_A6 + -0x11c) = 6;
        *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)(unaff_A6 + -100);
        *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0x60);
        *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0x5c);
        *(undefined4 *)(puVar7 + -0xc) = in_stack_00000000;
      }
      *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x54000000;
      if (*(sword *)(unaff_A6 + -0xcc) == 0x407f) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0x43ff;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == -0x3f81) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0xc3ff;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == 0x3f80) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0x3c00;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == -0x4080) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0xbc00;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2631 start=0x409b50a */

void decbin(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2632 start=0x409b516 */

void calc_e(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  sword sVar4;
  uint uVar5;
  int unaff_A6;
  
  sVar4 = 2;
  uVar5 = 4;
  puVar1 = (uint *)(unaff_A6 + -0x74);
  *puVar1 = *(uint *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  iVar2 = 0;
  do {
    iVar2 = ((*puVar1 << uVar5) >> 0x1c) + iVar2 * 10;
    uVar5 = (uint)(byte)((char)uVar5 + 4);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  if ((*puVar1 & 0x40000000) != 0) {
    iVar2 = -iVar2;
  }
  iVar3 = iVar2 + -0x10;
  if (iVar2 < 0x10) {
    iVar3 = -iVar3;
    *puVar1 = *puVar1 | 0x40000000;
  }
  *(int *)(unaff_A6 + -0x54) = iVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2633 start=0x409b570 */

float10 calc_m(void)

{
  int iVar1;
  sword sVar2;
  uint uVar3;
  byte *in_A0;
  float10 fVar4;
  
  iVar1 = 1;
  fVar4 = (float10)0.0 + (float10)(byte)((uint)(*(int *)in_A0 << 0x1c) >> 0x1c);
  do {
    uVar3 = 0;
    sVar2 = 7;
    do {
      fVar4 = fVar4 * (float10)10.0 +
              (float10)(byte)((uint)(*(int *)(in_A0 + iVar1 * 4) << uVar3) >> 0x1c);
      uVar3 = (uint)(byte)((char)uVar3 + 4);
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  if ((*in_A0 & 0x80) != 0) {
    fVar4 = -fVar4;
  }
  return fVar4;
}
/* GHIDRADEC_FUNCTION index=2634 start=0x409b5bc */

void ap_st_z(void)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  uint *in_A0;
  int unaff_A6;
  
  if (*(int *)(unaff_A6 + -0x54) < 0x1c) {
    return;
  }
  if ((*in_A0 & 0x40000000) != 0) {
    return;
  }
  iVar1 = 0;
  if ((*in_A0 & 0xf) == 0) {
    iVar1 = 1;
    uVar4 = in_A0[1];
    if (uVar4 == 0) {
      iVar1 = 9;
      uVar4 = in_A0[2];
    }
    iVar3 = 0;
    sVar2 = 7;
    do {
      if ((uVar4 << iVar3) >> 0x1c != 0) break;
      iVar3 = iVar3 + 4;
      iVar1 = iVar1 + 1;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  if (*(int *)(unaff_A6 + -0x54) < iVar1) {
    *in_A0 = *in_A0 | 0x40000000;
  }
  do {
    iVar1 = iVar1 >> 1;
  } while (iVar1 != 0);
  pwrten();
  return;
}
/* GHIDRADEC_FUNCTION index=2635 start=0x409b666 */

float10 ap_st_n(void)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  uint uVar4;
  uint *in_A0;
  int unaff_A6;
  float10 in_FP0;
  float10 fVar5;
  
  uVar1 = 0;
  uVar4 = in_A0[2];
  if (uVar4 == 0) {
    uVar1 = 8;
    uVar4 = in_A0[1];
  }
  iVar3 = 0x1c;
  sVar2 = 7;
  do {
    if ((uVar4 << iVar3) >> 0x1c != 0) break;
    iVar3 = iVar3 + -4;
    uVar1 = uVar1 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  if (*(int *)(unaff_A6 + -0x54) <= (int)uVar1) {
    *in_A0 = *in_A0 & 0xbfffffff;
  }
  iVar3 = 0;
  fVar5 = (float10)1.0;
  do {
    uVar4 = uVar1 & 1;
    uVar1 = (int)uVar1 >> 1;
    if (uVar4 != 0) {
      fVar5 = fVar5 * (float10)*(undefined (*) [12])(ptenrn + iVar3);
    }
    iVar3 = iVar3 + 0xc;
  } while (uVar1 != 0);
  return in_FP0 / fVar5;
}
/* GHIDRADEC_FUNCTION index=2636 start=0x409b6e2 */

void pwrten(void)

{
  int in_D1;
  uint *in_A0;
  
  if (in_D1 < 0) {
    in_D1 = -in_D1;
    *in_A0 = *in_A0 | 0x40000000;
  }
  do {
    in_D1 = in_D1 >> 1;
  } while (in_D1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=2637 start=0x409b76c */

uint norm(void)

{
  int unaff_A6;
  uint in_FPSR;
  
  if ((in_FPSR & 0x200) != 0) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x108;
  }
  return in_FPSR & 0xfffffdff;
}
/* GHIDRADEC_FUNCTION index=2638 start=0x409b810 */

void do_func(void)

{
  word wVar1;
  int unaff_A6;
  
  *(undefined *)(unaff_A6 + -0x46) = 0;
  if (*(uint *)(unaff_A6 + -0xe4) >> 0x1a == 0x17) {
    smovcr();
    return;
  }
  wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x7f;
  if (wVar1 < 0x38) {
                    /* WARNING: Could not recover jumptable at 0x0409b86c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(tblpre + (sword)((word)((uint)*(undefined4 *)(unaff_A6 + -0xe8) >> 0x1d) +
                                 wVar1 * 8) * 4))();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2639 start=0x409b86e */

void serror(void)

{
  int unaff_A6;
  
  *(undefined *)(unaff_A6 + -0x4c) = 0xff;
  return;
}
/* GHIDRADEC_FUNCTION index=2640 start=0x409b874 */

void snzrinx(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pzero();
    t_inx2();
    return;
  }
  ld_mzero();
  t_inx2();
  return;
}
/* GHIDRADEC_FUNCTION index=2641 start=0x409b898 */

void szero(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pzero();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2642 start=0x409b8aa */

void sinf(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pinf();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2643 start=0x409b8bc */

void sone(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pone();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2644 start=0x409b8ce */

void spi_2(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_ppi2();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2645 start=0x409b8e0 */

void szr_inf(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pinf();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2646 start=0x409b8f2 */

void sopr_inf(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pinf();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2647 start=0x409b904 */

/* WARNING: Removing unreachable block (ram,0x0409b91c) */

void sslognp1(void)

{
  float10 *in_A0;
  
  if (*in_A0 - (float10)-1 == FLOAT_UNKNOWN || *in_A0 - (float10)-1 < FLOAT_UNKNOWN) {
    t_operr();
    return;
  }
  slognp1();
  return;
}
/* GHIDRADEC_FUNCTION index=2648 start=0x409b930 */

void setoxm1i(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) == 0) {
    ld_pinf();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2649 start=0x409b942 */

float10 sslogn(void)

{
  byte *in_A0;
  float10 in_FP0;
  
  if ((*in_A0 & 0x80) != 0) {
    return in_FP0;
  }
  if (((*(sword *)in_A0 == 0x3fff) && (*(int *)(in_A0 + 4) == -0x80000000)) &&
     (*(int *)(in_A0 + 8) == 0)) {
    return (float10)tbyte_409B7BC;
  }
  return in_FP0;
}

