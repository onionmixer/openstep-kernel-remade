/* GHIDRADEC_FUNCTION index=2675 start=0x409ca38 */

unkbyte10 t_operr(void)

{
  int unaff_A6;
  unkbyte10 in_FP0;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1002080;
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x20) == 0) {
    return tbyte_409C99A._0_10_;
  }
  *(undefined *)(unaff_A6 + -0x4c) = 0xff;
  return in_FP0;
}
/* GHIDRADEC_FUNCTION index=2676 start=0x409ca5c */

unkbyte10 t_unfl(void)

{
  byte bVar1;
  uint uVar2;
  char *in_A0;
  byte *extraout_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x74) = 0;
  *(undefined4 *)(unaff_A6 + -0x70) = 0;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  if (*in_A0 < '\0') {
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
  if ((*(byte *)(unaff_A6 + -0x7e) & 8) != 0) {
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) | 0x10;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) | 0x80;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  bVar1 = *(byte *)(unaff_A6 + -0x74);
  *(byte *)(unaff_A6 + -0x74) = bVar1 & 0x7f;
  *(char *)(unaff_A6 + -0x72) = -((bVar1 & 0x80) != 0);
  unf_sub();
  uVar2 = *(uint *)(extraout_A0 + 2) >> 0x18;
  *(uint *)(extraout_A0 + 2) = uVar2;
  if (uVar2 != 0) {
    *extraout_A0 = *extraout_A0 | 0x80;
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  return *(unkbyte10 *)extraout_A0;
}
/* GHIDRADEC_FUNCTION index=2677 start=0x409cada */

/* WARNING: Possible PIC construction at 0x0409cb26: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0409cb26) */

byte t_ovfl2(void)

{
  byte bVar1;
  byte bVar2;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1048;
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  bVar2 = *(byte *)(unaff_A6 + -0x7d) & 0xc0;
  bVar1 = *(byte *)(unaff_A6 + -0x7d) & 0xc0;
  if (bVar2 != 0) {
    if (bVar2 == 0x40) {
      if ((*(char *)(unaff_A6 + -0xc4) != '\0') || ((*(uint *)(unaff_A6 + -200) & 0xff) != 0)) {
loc_409CB3C:
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x200;
        bVar2 = func_0x0409cb52();
        return bVar2;
      }
      bVar1 = 0;
    }
    else {
      bVar1 = 0;
      if ((*(uint *)(unaff_A6 + -0xc4) & 0x7ff) != 0) goto loc_409CB3C;
    }
  }
  return bVar1;
}
/* GHIDRADEC_FUNCTION index=2678 start=0x409cb4a */

unkbyte10 t_ovfl(void)

{
  uint uVar1;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1248;
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x10) != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = 0;
    *(undefined4 *)(unaff_A6 + -0x70) = 0;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) & 0xef;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) | 0x80;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  ovf_r_k();
  uVar1 = *(uint *)(unaff_A6 + -0xca) >> 0x18;
  *(uint *)(unaff_A6 + -0xca) = uVar1;
  if (uVar1 != 0) {
    *(byte *)(unaff_A6 + -0xcc) = *(byte *)(unaff_A6 + -0xcc) | 0x80;
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  return *(unkbyte10 *)(unaff_A6 + -0xcc);
}
/* GHIDRADEC_FUNCTION index=2679 start=0x409cba8 */

void t_inx2(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
  return;
}
/* GHIDRADEC_FUNCTION index=2680 start=0x409cbb2 */

void t_frcinx(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
  if ((*(byte *)(unaff_A6 + -0x7a) & 8) != 0) {
    *(byte *)(unaff_A6 + -0x79) = *(byte *)(unaff_A6 + -0x79) | 0x20;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2681 start=0x409cbce */

float10 dst_nan(void)

{
  int unaff_A6;
  float10 in_FP0;
  
  if ((*(byte *)(unaff_A6 + -0xd8) & 0x80) != 0) {
    *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
  }
  if ((*(byte *)(unaff_A6 + -0xd4) & 0x40) != 0) {
    if (((*(byte *)(unaff_A6 + -0xe8) & 0xe0) == 0x60) && ((*(byte *)(unaff_A6 + -200) & 0x40) == 0)
       ) {
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    }
    return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
  }
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x40) != 0) {
    *(byte *)(unaff_A6 + -0xe0) = *(byte *)(unaff_A6 + -0xe0) | 0x60;
    *(undefined *)(unaff_A6 + -0x4c) = 0xff;
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    return in_FP0;
  }
  *(byte *)(unaff_A6 + -0xd4) = *(byte *)(unaff_A6 + -0xd4) | 0x40;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
  return (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
}
/* GHIDRADEC_FUNCTION index=2682 start=0x409cc58 */

float10 src_nan(void)

{
  int unaff_A6;
  float10 in_FP0;
  
  if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
    *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
  }
  if ((*(byte *)(unaff_A6 + -200) & 0x40) != 0) {
    return (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
  }
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x40) != 0) {
    *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
    *(undefined *)(unaff_A6 + -0xe0) = *(undefined *)(unaff_A6 + -0xe0);
    *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x60;
    *(undefined *)(unaff_A6 + -0x4c) = 0xff;
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    return in_FP0;
  }
  *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
  return (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
}
/* GHIDRADEC_FUNCTION index=2683 start=0x409ccc8 */

void t_extdnrm(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
  func_0x0409ccde();
  return;
}
/* GHIDRADEC_FUNCTION index=2684 start=0x409ccd6 */

undefined4 t_resdnrm(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *in_A0;
  byte *extraout_A0;
  byte *pbVar4;
  byte *extraout_A0_00;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
  if ((*(byte *)(unaff_A6 + -0x7e) & 8) != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)in_A0;
    *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(in_A0 + 4);
    *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(in_A0 + 8);
    pbVar4 = (byte *)(unaff_A6 + -0x74);
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 & 0x7f;
    *(char *)(unaff_A6 + -0x72) = -((bVar1 & 0x80) != 0);
    if (*(sword *)pbVar4 != 0) {
      nrm_set();
      pbVar4 = extraout_A0;
    }
    *pbVar4 = *pbVar4 & 0x7f;
    uVar2 = *(uint *)(pbVar4 + 2) >> 0x18;
    *(uint *)(pbVar4 + 2) = uVar2;
    if (uVar2 != 0) {
      *pbVar4 = *pbVar4 | 0x80;
    }
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) | 0x10;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) & 0x7f;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  if (*(uint *)(unaff_A6 + -0x7d) >> 0x1e == 0) {
    uVar3 = 0;
    if ((*in_A0 & 0x80) != 0) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    }
  }
  else {
    bVar1 = *in_A0;
    *in_A0 = bVar1 & 0x7f;
    in_A0[2] = -((bVar1 & 0x80) != 0);
    uVar3 = unf_sub();
    uVar2 = *(uint *)(extraout_A0_00 + 2) >> 0x18;
    *(uint *)(extraout_A0_00 + 2) = uVar2;
    if (uVar2 != 0) {
      *extraout_A0_00 = *extraout_A0_00 | 0x80;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2685 start=0x409cd9a */

void t_avoid_unsupp(void)

{
  uint uVar1;
  byte *extraout_A0;
  byte *extraout_A0_00;
  byte bStack_ec;
  byte bStack_e4;
  byte bStack_e0;
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  if (uStack_c8._1_1_ == '\0') {
    return;
  }
  if ((bStack_e0 & 4) != 0) {
    if ((bStack_e4 & 0x80) != 0) {
      nrm_set();
      *extraout_A0 = *extraout_A0 & 0x7f;
      uVar1 = *(uint *)(extraout_A0 + 2) >> 0x18;
      *(uint *)(extraout_A0 + 2) = uVar1;
      if (uVar1 != 0) {
        *extraout_A0 = *extraout_A0 | 0x80;
      }
      if ((bStack_ec & 0x80) == 0) goto loc_409CE42;
    }
    nrm_set();
    *extraout_A0_00 = *extraout_A0_00 & 0x7f;
    uVar1 = *(uint *)(extraout_A0_00 + 2) >> 0x18;
    *(uint *)(extraout_A0_00 + 2) = uVar1;
    if (uVar1 != 0) {
      *extraout_A0_00 = *extraout_A0_00 | 0x80;
    }
  }
loc_409CE42:
  restoreFPUStateFrame(uStack_c8);
  return;
}
/* GHIDRADEC_FUNCTION index=2686 start=0x409ce7e */

uint res_func(void)

{
  word wVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined uVar5;
  uint in_D0;
  uint uVar6;
  byte bVar7;
  byte *extraout_A0;
  word *extraout_A0_00;
  word *extraout_A0_01;
  word *extraout_A0_02;
  byte *extraout_A0_03;
  word *extraout_A0_04;
  word *pwVar8;
  byte *extraout_A0_05;
  int unaff_A6;
  bool bVar9;
  uint in_FPSR;
  
  *(undefined *)(unaff_A6 + -0x4a) = 0;
  *(undefined *)(unaff_A6 + -0x49) = 0;
  *(undefined *)(unaff_A6 + -0x46) = 0;
  if ((*(char *)(unaff_A6 + -0x48) != '\0') && ((*(byte *)(unaff_A6 + -0xe0) & 0x80) != 0)) {
    bVar7 = *(byte *)(unaff_A6 + -0xd8);
    *(byte *)(unaff_A6 + -0xd8) = bVar7 & 0x7f;
    *(char *)(unaff_A6 + -0xd6) = -((bVar7 & 0x80) != 0);
    in_D0 = nrm_set();
    *extraout_A0 = *extraout_A0 & 0x7f;
    uVar6 = *(uint *)(extraout_A0 + 2) >> 0x18;
    *(uint *)(extraout_A0 + 2) = uVar6;
    if (uVar6 != 0) {
      *extraout_A0 = *extraout_A0 | 0x80;
    }
    *(uint *)(unaff_A6 + -0xe0) = *(uint *)(unaff_A6 + -0xe0) >> 0x1c;
    *(byte *)(unaff_A6 + -0xe0) = *(byte *)(unaff_A6 + -0xe0) | 0x10;
    *(byte *)(unaff_A6 + -0x4a) = *(byte *)(unaff_A6 + -0x4a) | 0xf;
  }
  pwVar8 = (word *)(unaff_A6 + -0xcc);
  if ((*(byte *)(unaff_A6 + -0xe4) & 0x20) != 0) {
    *(undefined *)(unaff_A6 + -0x46) = 0xff;
    if ((*(word *)(unaff_A6 + -0xe4) & 0xc00) != 0xc00) {
                    /* WARNING: Could not recover jumptable at 0x0409dff6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (**(code **)(sub_409DFC6 + ((*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a) * 4))
                        ();
      return uVar6;
    }
                    /* WARNING: Could not recover jumptable at 0x0409e5d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar6 = (**(code **)(&loc_409E590 + (sword)(*(word *)(unaff_A6 + -0xe8) >> 0xd) * 4))();
    return uVar6;
  }
  if ((*(byte *)(unaff_A6 + -0xe8) & 0x80) == 0) {
    if ((*(char *)(unaff_A6 + -0x48) == '\0') &&
       (in_D0 = *(word *)(unaff_A6 + -0xe4) & 0x7f, (*(word *)(unaff_A6 + -0xe4) & 1) == 0)) {
      *(undefined *)(unaff_A6 + -0x46) = 0xff;
      wVar1 = *(word *)(unaff_A6 + -0xe4);
      bVar7 = (byte)wVar1 & 0x3b;
      uVar5 = (undefined)(wVar1 >> 8);
      uVar6 = wVar1 & 0xffffff3b;
      if ((wVar1 & 0x3b) != 0) {
        if (bVar7 == 0x18) {
          uVar6 = (uint)CONCAT11(uVar5,*(byte *)(unaff_A6 + -0xe8));
          if ((*(byte *)(unaff_A6 + -0xe8) & 0x20) != 0) goto loc_409DE58;
          *(byte *)pwVar8 = *(byte *)pwVar8 & 0x7f;
        }
        else {
          if (bVar7 != 0x1a) {
            bVar9 = (*pwVar8 & 0x8000) != 0;
            uVar6 = *pwVar8 & 0xffff7fff;
            *(char *)(unaff_A6 + -0xca) = -bVar9;
            if (bVar9) {
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            }
            if ((sword)uVar6 == 0x7fff) {
              if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
                *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
                return uVar6;
              }
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
              *(undefined4 *)(unaff_A6 + -0xd8) = *(undefined4 *)(unaff_A6 + -0xcc);
              return uVar6;
            }
            if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
            }
            return uVar6;
          }
          uVar6 = (uint)CONCAT11(uVar5,*(byte *)(unaff_A6 + -0xe8));
          if ((*(byte *)(unaff_A6 + -0xe8) & 0x20) != 0) goto loc_409DE58;
          *(byte *)pwVar8 = *(byte *)pwVar8 ^ 0x80;
        }
      }
      uVar6 = CONCAT31((int3)(uVar6 >> 8),*(byte *)(unaff_A6 + -0xe8)) & 0xffffffe0;
      if ((*(byte *)(unaff_A6 + -0xe8) & 0xe0) != 0) goto loc_409DE58;
      if ((*(byte *)(unaff_A6 + -0xe3) & 4) == 0) {
        if ((*(byte *)(unaff_A6 + -0xe3) & 0x40) == 0) {
          uVar6 = *(uint *)(unaff_A6 + -0x7d) >> 0x1e;
          bVar7 = (byte)(*(uint *)(unaff_A6 + -0x7d) >> 0x1e);
          if (bVar7 == 0) goto loc_409D222;
          if (bVar7 != 1) goto loc_409D01C;
        }
        if ((*pwVar8 & 0x7fff) < 0x3f82) {
loc_409D0DA:
          bVar7 = *(byte *)pwVar8;
          *(byte *)pwVar8 = bVar7 & 0x7f;
          *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
          denorm();
          uVar6 = *(uint *)(extraout_A0_03 + 2) >> 0x18;
          *(uint *)(extraout_A0_03 + 2) = uVar6;
          if (uVar6 != 0) {
            *extraout_A0_03 = *extraout_A0_03 | 0x80;
          }
          bVar7 = *extraout_A0_03;
          *extraout_A0_03 = bVar7 & 0x7f;
          extraout_A0_03[2] = -((bVar7 & 0x80) != 0);
          uVar6 = round();
          uVar2 = *(uint *)(extraout_A0_04 + 1) >> 0x18;
          *(uint *)(extraout_A0_04 + 1) = uVar2;
          if (uVar2 != 0) {
            *(byte *)extraout_A0_04 = *(byte *)extraout_A0_04 | 0x80;
          }
          if ((*(byte *)(unaff_A6 + -0x7a) & 2) != 0) {
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x20;
          }
          if ((*(int *)(extraout_A0_04 + 2) == 0) && (*(int *)(extraout_A0_04 + 4) == 0)) {
            uVar6 = *(uint *)(unaff_A6 + -0x80) & 0x30;
            if (0x1f < uVar6) {
              if (uVar6 == 0x20) {
                if ((sword)*extraout_A0_04 < 0) {
                  bVar7 = *(byte *)(unaff_A6 + -0x7d);
joined_r0x0409d1ce:
                  if ((bVar7 & 0x80) == 0) {
                    *(uint *)(extraout_A0_04 + 2) = *(uint *)(extraout_A0_04 + 2) | 0x100;
                  }
                  else {
                    *(uint *)(extraout_A0_04 + 4) = *(uint *)(extraout_A0_04 + 4) | 0x800;
                  }
                  goto loc_409D20A;
                }
              }
              else if (-1 < (sword)*extraout_A0_04) {
                bVar7 = *(byte *)(unaff_A6 + -0x7d);
                goto joined_r0x0409d1ce;
              }
            }
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
            bVar7 = *(byte *)(unaff_A6 + -0xe8) & 0xe0;
            uVar6 = (uint)bVar7;
            if (bVar7 != 0x40) goto loc_409D20A;
          }
          else {
loc_409D20A:
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
          }
          *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)extraout_A0_04;
          *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(extraout_A0_04 + 2);
          *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(extraout_A0_04 + 4);
          pwVar8 = extraout_A0_04;
        }
        else {
          bVar7 = *(byte *)pwVar8;
          *(byte *)pwVar8 = bVar7 & 0x7f;
          *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
          uVar6 = round();
          uVar2 = *(uint *)(extraout_A0_01 + 1) >> 0x18;
          *(uint *)(extraout_A0_01 + 1) = uVar2;
          if (uVar2 != 0) {
            *(byte *)extraout_A0_01 = *(byte *)extraout_A0_01 | 0x80;
          }
          pwVar8 = extraout_A0_01;
          if (0x407e < (*extraout_A0_01 & 0x7fff)) {
loc_409D0CE:
            uVar6 = t_ovfl();
            pwVar8 = extraout_A0_02;
          }
        }
      }
      else {
loc_409D01C:
        if ((*pwVar8 & 0x7fff) < 0x3c02) goto loc_409D0DA;
        bVar7 = *(byte *)pwVar8;
        *(byte *)pwVar8 = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
        uVar6 = round();
        uVar2 = *(uint *)(extraout_A0_00 + 1) >> 0x18;
        *(uint *)(extraout_A0_00 + 1) = uVar2;
        if (uVar2 != 0) {
          *(byte *)extraout_A0_00 = *(byte *)extraout_A0_00 | 0x80;
        }
        pwVar8 = extraout_A0_00;
        if (0x43fe < (*extraout_A0_00 & 0x7fff)) goto loc_409D0CE;
      }
loc_409D222:
      if ((*pwVar8 == 0) || (*pwVar8 == 0x8000)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
      }
      if ((sword)*pwVar8 < 0) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
      }
loc_409DE58:
      if (((*(byte *)(unaff_A6 + -0x7a) & 0x40) != 0) && ((*(byte *)(unaff_A6 + -0x7e) & 0x40) != 0)
         ) {
        *(undefined4 *)(unaff_A6 + -0xd8) = *(undefined4 *)(unaff_A6 + -0xcc);
        if (-1 < *(char *)(unaff_A6 + -0xcc)) {
          return uVar6;
        }
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 3;
        return uVar6;
      }
      *(undefined2 *)(unaff_A6 + -0xec) = 0;
      *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
      bVar7 = *(byte *)(unaff_A6 + -0xe8) & 0xe0;
      if (bVar7 == 0x40) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
        if ((sword)*pwVar8 < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else if (bVar7 == 0x60) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
        *(undefined4 *)(unaff_A6 + -0xd8) = *(undefined4 *)(unaff_A6 + -0xcc);
        if ((sword)*pwVar8 < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else if ((bVar7 == 0x20) &&
              (*(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000,
              (sword)*pwVar8 < 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
      }
      uVar6 = (*(uint *)(unaff_A6 + -0xe4) & 0x3ffffff) >> 0x17;
      bVar7 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 6) >> 0x1d);
      if (3 < bVar7) {
        uVar6 = 1 << (7 - uVar6 & 0x1f);
        fmovem(*(undefined4 *)(unaff_A6 + -0xcc),uVar6);
        return uVar6;
      }
      if (bVar7 == 0) {
        *(undefined4 *)(unaff_A6 + -0xb0) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0xac) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0xa8) = *(undefined4 *)(unaff_A6 + -0xc4);
        return uVar6;
      }
      if (bVar7 != 1) {
        if (bVar7 != 2) {
          *(undefined4 *)(unaff_A6 + -0x8c) = *(undefined4 *)(unaff_A6 + -0xcc);
          *(undefined4 *)(unaff_A6 + -0x88) = *(undefined4 *)(unaff_A6 + -200);
          *(undefined4 *)(unaff_A6 + -0x84) = *(undefined4 *)(unaff_A6 + -0xc4);
          return uVar6;
        }
        *(undefined4 *)(unaff_A6 + -0x98) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0x94) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0x90) = *(undefined4 *)(unaff_A6 + -0xc4);
        return uVar6;
      }
      *(undefined4 *)(unaff_A6 + -0xa4) = *(undefined4 *)(unaff_A6 + -0xcc);
      *(undefined4 *)(unaff_A6 + -0xa0) = *(undefined4 *)(unaff_A6 + -200);
      *(undefined4 *)(unaff_A6 + -0x9c) = *(undefined4 *)(unaff_A6 + -0xc4);
      return uVar6;
    }
  }
  else {
    if ((*(char *)(unaff_A6 + -0x48) == '\0') && ((*(word *)(unaff_A6 + -0xe4) & 1) == 0)) {
      *(undefined *)(unaff_A6 + -0x46) = 0xff;
      *(undefined *)(unaff_A6 + -0x46) = 0xff;
      wVar1 = *(word *)(unaff_A6 + -0xe4);
      bVar7 = (byte)wVar1 & 0x3b;
      uVar6 = wVar1 & 0xffffff3b;
      if ((wVar1 & 0x3b) != 0) {
        if (bVar7 == 0x18) {
          *(byte *)pwVar8 = *(byte *)pwVar8 & 0x7f;
        }
        else {
          if (bVar7 != 0x1a) {
            bVar9 = (*pwVar8 & 0x8000) != 0;
            uVar6 = *pwVar8 & 0xffff7fff;
            *(char *)(unaff_A6 + -0xca) = -bVar9;
            if (bVar9) {
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            }
            if ((sword)uVar6 == 0x7fff) {
              if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
                *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
                return uVar6;
              }
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
              *(undefined4 *)(unaff_A6 + -0xd8) = *(undefined4 *)(unaff_A6 + -0xcc);
              return uVar6;
            }
            if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
            }
            return uVar6;
          }
          *(byte *)pwVar8 = *(byte *)pwVar8 ^ 0x80;
        }
      }
      if ((*(byte *)(unaff_A6 + -0xe3) & 4) == 0) {
        if ((*(byte *)(unaff_A6 + -0xe3) & 0x40) == 0) {
          uVar6 = *(uint *)(unaff_A6 + -0x7d) >> 0x1e;
          bVar7 = (byte)(*(uint *)(unaff_A6 + -0x7d) >> 0x1e);
          if (bVar7 == 0) {
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
            if (*pwVar8 != 0) {
              *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            }
            goto loc_409DE58;
          }
          if (bVar7 != 1) goto loc_409D3B4;
        }
        bVar7 = (byte)((uint)(*(int *)(unaff_A6 + -0x7d) << 2) >> 0x1e);
        if ((sword)*pwVar8 < 0) {
          if (bVar7 == 2) {
            pwVar8[0] = 0xbf81;
            pwVar8[1] = 0;
            *(undefined4 *)(unaff_A6 + -200) = 0x100;
            *(undefined4 *)(unaff_A6 + -0xc4) = 0;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
          }
          else {
            pwVar8[0] = 0xbf81;
            pwVar8[1] = 0;
            *(undefined4 *)(unaff_A6 + -200) = 0;
            *(undefined4 *)(unaff_A6 + -0xc4) = 0;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
          }
        }
        else if (bVar7 == 3) {
          pwVar8[0] = 0x3f81;
          pwVar8[1] = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0x100;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
        }
        else {
          pwVar8[0] = 0x3f81;
          pwVar8[1] = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
        }
      }
      else {
loc_409D3B4:
        bVar7 = (byte)((uint)(*(int *)(unaff_A6 + -0x7d) << 2) >> 0x1e);
        if ((sword)*pwVar8 < 0) {
          if (bVar7 == 2) {
            pwVar8[0] = 0xbc01;
            pwVar8[1] = 0;
            *(undefined4 *)(unaff_A6 + -200) = 0;
            *(undefined4 *)(unaff_A6 + -0xc4) = 0x800;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
          }
          else {
            pwVar8[0] = 0xbc01;
            pwVar8[1] = 0;
            *(undefined4 *)(unaff_A6 + -200) = 0;
            *(undefined4 *)(unaff_A6 + -0xc4) = 0;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
            *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
          }
        }
        else if (bVar7 == 3) {
          pwVar8[0] = 0x3c01;
          pwVar8[1] = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0x800;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
        }
        else {
          pwVar8[0] = 0x3c01;
          pwVar8[1] = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
        }
      }
      goto loc_409DE58;
    }
    bVar7 = *(byte *)pwVar8;
    *(byte *)pwVar8 = bVar7 & 0x7f;
    *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
    in_D0 = nrm_set();
    *extraout_A0_05 = *extraout_A0_05 & 0x7f;
    uVar6 = *(uint *)(extraout_A0_05 + 2) >> 0x18;
    *(uint *)(extraout_A0_05 + 2) = uVar6;
    if (uVar6 != 0) {
      *extraout_A0_05 = *extraout_A0_05 | 0x80;
    }
    *(uint *)(unaff_A6 + -0xe8) = *(uint *)(unaff_A6 + -0xe8) >> 0x1c;
    *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x10;
    *(byte *)(unaff_A6 + -0x4a) = *(byte *)(unaff_A6 + -0x4a) | 0xf0;
  }
  if ((*(char *)(unaff_A6 + -0x4a) == '\0') || (*(char *)(unaff_A6 + -0x48) == '\0'))
  goto loc_409D2C4;
  wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x3b;
  in_D0 = *(word *)(unaff_A6 + -0xe4) & 0xffff003b;
  if (wVar1 == 0x22) {
    if (*(char *)(unaff_A6 + -0x4a) == -1) {
loc_409D2C4:
      *(undefined *)(unaff_A6 + -0x11c) = 0xfe;
      *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
      *(undefined2 *)(unaff_A6 + -0xec) = 0;
      *(undefined *)(unaff_A6 + -0x49) = 0xff;
      return in_D0;
    }
    bVar9 = *(char *)(unaff_A6 + -0x4a) == '\x0f';
    if (bVar9) {
      in_D0 = sub_409D60E();
      if (!bVar9) goto loc_409D2C4;
      in_D0 = ((*(uint *)(unaff_A6 + -0xcc) & 0x7fffffff) >> 0x10) -
              ((*(int *)(unaff_A6 + -0xd8) << 1) >> 0x11);
    }
    else {
      in_D0 = sub_409D618();
      if (!bVar9) goto loc_409D2C4;
      in_D0 = ((*(uint *)(unaff_A6 + -0xd8) & 0x7fffffff) >> 0x10) -
              ((*(int *)(unaff_A6 + -0xcc) << 1) >> 0x11);
    }
    if ((int)in_D0 < 0x8000) goto loc_409D2C4;
    if (((*(word *)(unaff_A6 + -0xd8) ^ *(word *)(unaff_A6 + -0xcc)) & 0x8000) == 0) {
      if (*(char *)(unaff_A6 + -0x4a) == '\x0f') {
        bVar7 = *(byte *)(unaff_A6 + -0xcc);
        *(byte *)(unaff_A6 + -0xcc) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0xca) >> 0x18;
        *(uint *)(unaff_A6 + -0xca) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0xcc) = *(byte *)(unaff_A6 + -0xcc) | 0x80;
        }
        *(undefined4 *)(unaff_A6 + -0x10c) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0x108) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0x104) = *(undefined4 *)(unaff_A6 + -0xc4);
        if (*(sword *)(unaff_A6 + -0xcc) < 1) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else {
        bVar7 = *(byte *)(unaff_A6 + -0xd8);
        *(byte *)(unaff_A6 + -0xd8) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0xd6) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0xd6) >> 0x18;
        *(uint *)(unaff_A6 + -0xd6) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0xd8) = *(byte *)(unaff_A6 + -0xd8) | 0x80;
        }
        *(undefined4 *)(unaff_A6 + -0x10c) = *(undefined4 *)(unaff_A6 + -0xd8);
        *(undefined4 *)(unaff_A6 + -0x108) = *(undefined4 *)(unaff_A6 + -0xd4);
        *(undefined4 *)(unaff_A6 + -0x104) = *(undefined4 *)(unaff_A6 + -0xd0);
        if (*(sword *)(unaff_A6 + -0xd8) < 1) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      if ((*(word *)(unaff_A6 + -0x10c) & 0x7fff) == 0x7fff) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2001048;
        *(undefined4 *)(unaff_A6 + -0x108) = 0;
      }
    }
    else if (*(char *)(unaff_A6 + -0x4a) == '\x0f') {
      *(word *)(unaff_A6 + -0xd8) = *(word *)(unaff_A6 + -0xd8) & 0x8000 | 0x3fff;
      fVar4 = (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
      *(uint *)(unaff_A6 + -0x7c) =
           in_FPSR & 0xf0ffffff | (uint)(fVar4 < FLOAT_UNKNOWN) << 0x1b |
           (uint)(fVar4 == FLOAT_UNKNOWN) << 0x1a | *(uint *)(unaff_A6 + -0x7c);
      *(undefined (*) [12])(unaff_A6 + -0x10c) =
           (undefined  [12])(fVar4 + (float10)*(undefined (*) [12])(unaff_A6 + -0xd8));
      bVar7 = *(byte *)(unaff_A6 + -0x10c);
      *(byte *)(unaff_A6 + -0x10c) = bVar7 & 0x7f;
      *(char *)(unaff_A6 + -0x10a) = -((bVar7 & 0x80) != 0);
      round();
      uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
      *(uint *)(unaff_A6 + -0x10a) = uVar6;
      if (uVar6 != 0) {
        *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
      }
    }
    else {
      *(word *)(unaff_A6 + -0xcc) = *(word *)(unaff_A6 + -0xcc) & 0x8000 | 0x3fff;
      fVar4 = (float10)*(undefined (*) [12])(unaff_A6 + -0xcc);
      *(uint *)(unaff_A6 + -0x7c) =
           in_FPSR & 0xf0ffffff | (uint)(fVar4 < FLOAT_UNKNOWN) << 0x1b |
           (uint)(fVar4 == FLOAT_UNKNOWN) << 0x1a | *(uint *)(unaff_A6 + -0x7c);
      *(undefined (*) [12])(unaff_A6 + -0x10c) =
           (undefined  [12])(fVar4 + (float10)*(undefined (*) [12])(unaff_A6 + -0xd8));
      bVar7 = *(byte *)(unaff_A6 + -0x10c);
      *(byte *)(unaff_A6 + -0x10c) = bVar7 & 0x7f;
      *(char *)(unaff_A6 + -0x10a) = -((bVar7 & 0x80) != 0);
      round();
      uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
      *(uint *)(unaff_A6 + -0x10a) = uVar6;
      if (uVar6 != 0) {
        *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
      }
    }
  }
  else {
    if (wVar1 != 0x28) {
      if (wVar1 == 0x23) {
        if (*(char *)(unaff_A6 + -0x4a) != -1) {
          bVar9 = *(char *)(unaff_A6 + -0x4a) == '\x0f';
          if (bVar9) {
            in_D0 = sub_409D60E();
            if ((!bVar9) ||
               (uVar6 = (*(uint *)(unaff_A6 + -0xcc) & 0x7fffffff) >> 0x10,
               iVar3 = (*(int *)(unaff_A6 + -0xd8) << 1) >> 0x11, in_D0 = iVar3 + uVar6,
               in_D0 != 0 && SCARRY4(iVar3,uVar6) == (int)in_D0 < 0)) goto loc_409D2C4;
          }
          else {
            in_D0 = sub_409D618();
            if ((!bVar9) ||
               (uVar6 = (*(uint *)(unaff_A6 + -0xd8) & 0x7fffffff) >> 0x10,
               iVar3 = (*(int *)(unaff_A6 + -0xcc) << 1) >> 0x11, in_D0 = iVar3 + uVar6,
               in_D0 != 0 && SCARRY4(iVar3,uVar6) == (int)in_D0 < 0)) goto loc_409D2C4;
          }
        }
      }
      else {
        if (wVar1 == 0x38) {
          if (*(char *)(unaff_A6 + -0x4a) != -1) {
            bVar9 = *(char *)(unaff_A6 + -0x4a) == '\x0f';
            if (bVar9) {
              in_D0 = sub_409D60E();
              if (bVar9) {
                in_D0 = ((*(uint *)(unaff_A6 + -0xcc) & 0x7fffffff) >> 0x10) -
                        ((*(int *)(unaff_A6 + -0xd8) << 1) >> 0x11);
                if (0x7fff < (int)in_D0) {
                  if (*(sword *)(unaff_A6 + -0xcc) < 0) {
                    return in_D0;
                  }
loc_409DC84:
                  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
                  return in_D0;
                }
              }
            }
            else {
              in_D0 = sub_409D618();
              if (bVar9) {
                in_D0 = ((*(uint *)(unaff_A6 + -0xd8) & 0x7fffffff) >> 0x10) -
                        ((*(int *)(unaff_A6 + -0xcc) << 1) >> 0x11);
                if (0x7fff < (int)in_D0) {
                  if (-1 < *(sword *)(unaff_A6 + -0xd8)) {
                    return in_D0;
                  }
                  goto loc_409DC84;
                }
              }
            }
          }
          goto loc_409D2C4;
        }
        if (*(char *)(unaff_A6 + -0x4a) == -1) goto loc_409D2C4;
        bVar9 = *(char *)(unaff_A6 + -0x4a) == '\x0f';
        if (!bVar9) {
          in_D0 = sub_409D618();
          if ((!bVar9) ||
             (in_D0 = ((*(uint *)(unaff_A6 + -0xd8) & 0x7fffffff) >> 0x10) -
                      ((*(int *)(unaff_A6 + -0xcc) << 1) >> 0x11), (int)in_D0 < 0x8000))
          goto loc_409D2C4;
          *(undefined *)(unaff_A6 + -0x10a) = 0;
          if (((*(word *)(unaff_A6 + -0xd8) ^ *(word *)(unaff_A6 + -0xcc)) & 0x8000) != 0) {
            *(undefined *)(unaff_A6 + -0x10a) = 0xff;
          }
          *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1048;
          *(undefined2 *)(unaff_A6 + -0xec) = 0;
          ovf_res();
          uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
          *(uint *)(unaff_A6 + -0x10a) = uVar6;
          if (uVar6 != 0) {
            *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
          }
          goto loc_409DDCA;
        }
        in_D0 = sub_409D60E();
        if ((!bVar9) ||
           (in_D0 = ((*(uint *)(unaff_A6 + -0xcc) & 0x7fffffff) >> 0x10) -
                    ((*(int *)(unaff_A6 + -0xd8) << 1) >> 0x11), (int)in_D0 < 0x7fff))
        goto loc_409D2C4;
        *(undefined *)(unaff_A6 + -0x10a) = 0;
        if (((*(word *)(unaff_A6 + -0xd8) ^ *(word *)(unaff_A6 + -0xcc)) & 0x8000) != 0) {
          *(undefined *)(unaff_A6 + -0x10a) = 0xff;
        }
      }
      *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
      *(undefined2 *)(unaff_A6 + -0xec) = 0;
      *(undefined *)(unaff_A6 + -0x10a) = 0;
      if (((*(word *)(unaff_A6 + -0xd8) ^ *(word *)(unaff_A6 + -0xcc)) & 0x8000) != 0) {
        *(undefined *)(unaff_A6 + -0x10a) = 0xff;
      }
      unf_sub();
      uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
      *(uint *)(unaff_A6 + -0x10a) = uVar6;
      if (uVar6 != 0) {
        *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
      }
      goto loc_409DDCA;
    }
    if (*(char *)(unaff_A6 + -0x4a) == -1) goto loc_409D2C4;
    bVar9 = *(char *)(unaff_A6 + -0x4a) == '\x0f';
    if (bVar9) {
      in_D0 = sub_409D60E();
      if (!bVar9) goto loc_409D2C4;
      in_D0 = ((*(uint *)(unaff_A6 + -0xcc) & 0x7fffffff) >> 0x10) -
              ((*(int *)(unaff_A6 + -0xd8) << 1) >> 0x11);
    }
    else {
      in_D0 = sub_409D618();
      if (!bVar9) goto loc_409D2C4;
      in_D0 = ((*(uint *)(unaff_A6 + -0xd8) & 0x7fffffff) >> 0x10) -
              ((*(int *)(unaff_A6 + -0xcc) << 1) >> 0x11);
    }
    if ((int)in_D0 < 0x8000) goto loc_409D2C4;
    if (((*(word *)(unaff_A6 + -0xd8) ^ *(word *)(unaff_A6 + -0xcc)) & 0x8000) == 0) {
      if (*(char *)(unaff_A6 + -0x4a) == '\x0f') {
        *(word *)(unaff_A6 + -0xd8) = *(word *)(unaff_A6 + -0xd8) & 0x8000 | 0x3fff;
        fVar4 = (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
        *(uint *)(unaff_A6 + -0x7c) =
             in_FPSR & 0xf0ffffff | (uint)(fVar4 < FLOAT_UNKNOWN) << 0x1b |
             (uint)(fVar4 == FLOAT_UNKNOWN) << 0x1a | *(uint *)(unaff_A6 + -0x7c);
        *(undefined (*) [12])(unaff_A6 + -0x10c) =
             (undefined  [12])(fVar4 - (float10)*(undefined (*) [12])(unaff_A6 + -0xcc));
        bVar7 = *(byte *)(unaff_A6 + -0x10c);
        *(byte *)(unaff_A6 + -0x10c) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0x10a) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
        *(uint *)(unaff_A6 + -0x10a) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
        }
      }
      else {
        *(word *)(unaff_A6 + -0xcc) = *(word *)(unaff_A6 + -0xcc) & 0x8000 | 0x3fff;
        fVar4 = (float10)*(undefined (*) [12])(unaff_A6 + -0xd8);
        *(uint *)(unaff_A6 + -0x7c) =
             in_FPSR & 0xf0ffffff | (uint)(fVar4 < FLOAT_UNKNOWN) << 0x1b |
             (uint)(fVar4 == FLOAT_UNKNOWN) << 0x1a | *(uint *)(unaff_A6 + -0x7c);
        *(undefined (*) [12])(unaff_A6 + -0x10c) =
             (undefined  [12])(fVar4 - (float10)*(undefined (*) [12])(unaff_A6 + -0xcc));
        bVar7 = *(byte *)(unaff_A6 + -0x10c);
        *(byte *)(unaff_A6 + -0x10c) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0x10a) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
        *(uint *)(unaff_A6 + -0x10a) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
        }
      }
    }
    else {
      if (*(char *)(unaff_A6 + -0x4a) == '\x0f') {
        *(word *)(unaff_A6 + -0xcc) = *(word *)(unaff_A6 + -0xcc) ^ 0x8000;
        if (*(sword *)(unaff_A6 + -0xcc) < 1) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
        bVar7 = *(byte *)(unaff_A6 + -0xcc);
        *(byte *)(unaff_A6 + -0xcc) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0xca) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0xca) >> 0x18;
        *(uint *)(unaff_A6 + -0xca) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0xcc) = *(byte *)(unaff_A6 + -0xcc) | 0x80;
        }
        *(undefined4 *)(unaff_A6 + -0x10c) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0x108) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0x104) = *(undefined4 *)(unaff_A6 + -0xc4);
      }
      else {
        bVar7 = *(byte *)(unaff_A6 + -0xd8);
        *(byte *)(unaff_A6 + -0xd8) = bVar7 & 0x7f;
        *(char *)(unaff_A6 + -0xd6) = -((bVar7 & 0x80) != 0);
        round();
        uVar6 = *(uint *)(unaff_A6 + -0xd6) >> 0x18;
        *(uint *)(unaff_A6 + -0xd6) = uVar6;
        if (uVar6 != 0) {
          *(byte *)(unaff_A6 + -0xd8) = *(byte *)(unaff_A6 + -0xd8) | 0x80;
        }
        *(undefined4 *)(unaff_A6 + -0x10c) = *(undefined4 *)(unaff_A6 + -0xd8);
        *(undefined4 *)(unaff_A6 + -0x108) = *(undefined4 *)(unaff_A6 + -0xd4);
        *(undefined4 *)(unaff_A6 + -0x104) = *(undefined4 *)(unaff_A6 + -0xd0);
        if (*(sword *)(unaff_A6 + -0xd8) < 1) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      if ((*(word *)(unaff_A6 + -0x10c) & 0x7fff) == 0x7fff) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2001048;
        *(undefined4 *)(unaff_A6 + -0x108) = 0;
      }
    }
  }
  if (((*(word *)(unaff_A6 + -0xe4) & 0x40) != 0) ||
     ((byte)((uint)*(undefined4 *)(unaff_A6 + -0x7d) >> 0x1e) != 0)) {
    bVar7 = *(byte *)(unaff_A6 + -0x10c);
    *(byte *)(unaff_A6 + -0x10c) = bVar7 & 0x7f;
    *(char *)(unaff_A6 + -0x10a) = -((bVar7 & 0x80) != 0);
    ovf_res();
    uVar6 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
    *(uint *)(unaff_A6 + -0x10a) = uVar6;
    if (uVar6 != 0) {
      *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
    }
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1248;
  }
loc_409DDCA:
  uVar6 = (*(uint *)(unaff_A6 + -0xe4) & 0x3ffffff) >> 0x17;
  bVar7 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 6) >> 0x1d);
  if (3 < bVar7) {
    uVar6 = 1 << (7 - uVar6 & 0x1f);
    fmovem(*(undefined4 *)(unaff_A6 + -0x10c),uVar6);
    return uVar6;
  }
  if (bVar7 == 0) {
    *(undefined4 *)(unaff_A6 + -0xb0) = *(undefined4 *)(unaff_A6 + -0x10c);
    *(undefined4 *)(unaff_A6 + -0xac) = *(undefined4 *)(unaff_A6 + -0x108);
    *(undefined4 *)(unaff_A6 + -0xa8) = *(undefined4 *)(unaff_A6 + -0x104);
    return uVar6;
  }
  if (bVar7 == 1) {
    *(undefined4 *)(unaff_A6 + -0xa4) = *(undefined4 *)(unaff_A6 + -0x10c);
    *(undefined4 *)(unaff_A6 + -0xa0) = *(undefined4 *)(unaff_A6 + -0x108);
    *(undefined4 *)(unaff_A6 + -0x9c) = *(undefined4 *)(unaff_A6 + -0x104);
    return uVar6;
  }
  if (bVar7 != 2) {
    *(undefined4 *)(unaff_A6 + -0x8c) = *(undefined4 *)(unaff_A6 + -0x10c);
    *(undefined4 *)(unaff_A6 + -0x88) = *(undefined4 *)(unaff_A6 + -0x108);
    *(undefined4 *)(unaff_A6 + -0x84) = *(undefined4 *)(unaff_A6 + -0x104);
    return uVar6;
  }
  *(undefined4 *)(unaff_A6 + -0x98) = *(undefined4 *)(unaff_A6 + -0x10c);
  *(undefined4 *)(unaff_A6 + -0x94) = *(undefined4 *)(unaff_A6 + -0x108);
  *(undefined4 *)(unaff_A6 + -0x90) = *(undefined4 *)(unaff_A6 + -0x104);
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2687 start=0x409e5f2 */

/* WARNING: Control flow encountered bad instruction data */

void p_move(void)

{
  int unaff_A6;
  
  if ((*(word *)(unaff_A6 + -0xe4) & 0x1000) != 0) {
    switch(*(word *)(unaff_A6 + -0xe4) & 0x7f) {
    :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  bindec();
  mem_write();
  *(undefined *)(unaff_A6 + -0x11c) = 0;
  *(uint *)(unaff_A6 + -0xe0) = *(uint *)(unaff_A6 + -0xe0) >> 0x1d;
  return;
}
/* GHIDRADEC_FUNCTION index=2688 start=0x409e6aa */

void round(void)

{
  int unaff_A6;
  undefined8 uVar1;
  
  uVar1 = sub_409E736();
  if ((int)((qword)uVar1 >> 0x20) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0409e89c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&loc_409E882 + (sword)((qword)uVar1 >> 0x10) * 4))();
    return;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
                    /* WARNING: Could not recover jumptable at 0x0409e6d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(sub_409E6D4 + (sword)uVar1 * 4))();
  return;
}
/* GHIDRADEC_FUNCTION index=2689 start=0x409e8a0 */

void nrm_zero(void)

{
  int iVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  word *in_A0;
  
  wVar3 = *in_A0;
  uVar4 = (uint)wVar3;
  if (-1 < (sword)(wVar3 - 0x40)) {
    nrm_set();
    return;
  }
  iVar1 = *(int *)(in_A0 + 2);
  uVar2 = *(uint *)(in_A0 + 4);
  if (iVar1 == 0) {
    if (uVar2 == 0) {
      *in_A0 = 0;
      return;
    }
    if (-1 < (sword)(wVar3 - ((word)(uVar2 != 0) * (sword)LZCOUNT(uVar2) + 0x20))) {
      nrm_set();
      return;
    }
  }
  else if (-1 < (sword)(wVar3 - (word)(iVar1 != 0) * (sword)LZCOUNT(iVar1))) {
    nrm_set();
    return;
  }
  *in_A0 = 0;
  *(uint *)(in_A0 + 2) = uVar2 >> (0x20 - uVar4 & 0x3f) | iVar1 << (uVar4 & 0x3f);
  *(uint *)(in_A0 + 4) = uVar2 << (uVar4 & 0x3f);
  return;
}
/* GHIDRADEC_FUNCTION index=2690 start=0x409e930 */

void nrm_set(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  sword *in_A0;
  
  iVar2 = *(int *)(in_A0 + 2);
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  if (iVar2 != 0) {
    *in_A0 = *in_A0 - (sword)iVar3;
    uVar1 = *(uint *)(in_A0 + 4);
    *(uint *)(in_A0 + 4) = uVar1 << iVar3;
    *(uint *)(in_A0 + 2) = uVar1 >> (0x20U - iVar3 & 0x3f) | *(int *)(in_A0 + 2) << iVar3;
    return;
  }
  iVar2 = *(int *)(in_A0 + 4);
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  *in_A0 = (*in_A0 + -0x20) - (sword)iVar3;
  *(int *)(in_A0 + 2) = iVar2 << iVar3;
  in_A0[4] = 0;
  in_A0[5] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2691 start=0x409e98c */

sword denorm(void)

{
  int in_D0;
  sword sVar1;
  char extraout_D1b;
  sword sVar2;
  char extraout_D1b_00;
  char extraout_D1b_01;
  char cVar3;
  byte *in_A0;
  int unaff_A6;
  
  if ((*in_A0 & 0x40) != 0) {
    *in_A0 = *in_A0 | 0x80;
  }
  if ((char)in_D0 == '\0') {
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b;
  }
  else if (in_D0 == 1) {
    sVar2 = 0x3f81;
    sVar1 = -*(sword *)in_A0 + 0x3f81;
    if (-1 < (sword)(-*(sword *)in_A0 + 0x3f3e)) goto loc_409EA20;
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b_01;
  }
  else {
    sVar2 = 0x3c01;
    sVar1 = -*(sword *)in_A0 + 0x3c01;
    if (-1 < (sword)(-*(sword *)in_A0 + 0x3bbe)) {
loc_409EA20:
      if ((*(int *)(in_A0 + 4) != 0) || (*(int *)(in_A0 + 8) != 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
        sVar1 = 0;
      }
      *(sword *)in_A0 = sVar2;
      in_A0[4] = 0;
      in_A0[5] = 0;
      in_A0[6] = 0;
      in_A0[7] = 0;
      in_A0[8] = 0;
      in_A0[9] = 0;
      in_A0[10] = 0;
      in_A0[0xb] = 0;
      return sVar1;
    }
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b_00;
  }
  if (cVar3 != '\0') {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
  }
  return sVar1;
}
/* GHIDRADEC_FUNCTION index=2692 start=0x409ea68 */

/* WARNING: Removing unreachable block (ram,0x0409eb56) */
/* WARNING: Removing unreachable block (ram,0x0409eaf0) */

sqword dnrm_lp(void)

{
  sword sVar1;
  int in_D0;
  uint uVar2;
  undefined2 uVar3;
  undefined3 uVar4;
  undefined4 in_D1;
  sword sVar8;
  uint uVar6;
  undefined4 uVar7;
  uint *in_A0;
  int unaff_A6;
  int iVar5;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    in_D0 = (*(uint *)(unaff_A6 + -0xe8) & 0x3800000) << 6;
  }
  *(uint *)(unaff_A6 + -0x5c) = in_A0[2];
  *(int *)(unaff_A6 + -0x58) = in_D0;
  sVar8 = (sword)in_D1;
  sVar1 = sVar8 - *(sword *)in_A0;
  uVar3 = (undefined2)((uint)in_D1 >> 0x10);
  iVar5 = CONCAT22(uVar3,sVar1);
  uVar4 = (undefined3)((uint)iVar5 >> 8);
  if (sVar1 == 0 || sVar8 < *(sword *)in_A0) {
    return (qword)CONCAT43(*(undefined4 *)(unaff_A6 + -0x58),uVar4) << 8;
  }
  if (sVar1 < 0x20) {
    *(sword *)in_A0 = sVar8;
    in_A0[1] = (uint)(0 << iVar5) >> 0x20 - (uint)(word)(0x20 - sVar1);
    in_A0[2] = 0;
    uVar2 = 0;
    if ((*(uint *)(unaff_A6 + -0x58) & 0xe0000000) != 0) {
      uVar2 = 0x20000000;
    }
    return (qword)uVar2 << 0x20;
  }
  if (sVar1 < 0x40) {
    *(sword *)in_A0 = sVar8;
    uVar2 = 0;
    in_A0[1] = 0;
    in_A0[2] = (uint)(0 << CONCAT22(uVar3,sVar1 + -0x20)) >>
               0x20 - (uint)(word)(0x20 - (sVar1 + -0x20));
    if ((*(uint *)(unaff_A6 + -0x58) & 0xe0000000) != 0) {
      uVar2 = 0x20000000;
    }
    return (qword)uVar2 << 0x20;
  }
  *(sword *)in_A0 = sVar8;
  if ((sword)*in_A0 < 0) {
    *in_A0 = *in_A0 | 0x80000000;
  }
  if (sVar1 == 0x40) {
    uVar6 = in_A0[1] & 0x3fffffff;
    uVar2 = in_A0[1] & 0xc0000000;
  }
  else {
    if (sVar1 != 0x41) {
      in_A0[1] = 0;
      in_A0[2] = 0;
      return CONCAT44(0x20000000,CONCAT31(uVar4,0xff));
    }
    uVar6 = in_A0[1] & 0x7fffffff;
    uVar2 = (in_A0[1] & 0x80000000) >> 1;
  }
  if (((uVar6 == 0) && (in_A0[2] == 0)) && (*(char *)(unaff_A6 + -0x58) == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar2 = uVar2 | 0x20000000;
    uVar7 = CONCAT31((int3)(uVar6 >> 8),0xff);
  }
  in_A0[1] = 0;
  in_A0[2] = 0;
  return CONCAT44(uVar2,uVar7);
}
/* GHIDRADEC_FUNCTION index=2693 start=0x409ec3c */

void sacosd(void)

{
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2694 start=0x409ec4e */

float10 sacos(void)

{
  undefined (*in_A0) [12];
  float10 fVar1;
  
  fVar1 = (float10)*in_A0;
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    *(float10 *)*in_A0 = SQRT((-fVar1 + (float10)1.0) / ((float10)1.0 + fVar1));
    satan();
    fVar1 = (float10)t_frcinx();
    return fVar1;
  }
  if (ABS(fVar1) - (float10)1.0 != FLOAT_UNKNOWN && FLOAT_UNKNOWN <= ABS(fVar1) - (float10)1.0) {
    fVar1 = (float10)t_operr();
    return fVar1;
  }
  if (CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) < 1) {
    fVar1 = (float10)t_frcinx();
    return fVar1;
  }
  return (float10)0.0;
}
/* GHIDRADEC_FUNCTION index=2695 start=0x409ed06 */

void sasind(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2696 start=0x409ed0c */

void sasin(void)

{
  float10 fVar1;
  undefined (*in_A0) [12];
  
  fVar1 = (float10)*in_A0;
  if ((CONCAT22((sword)((uint)*(undefined4 *)*in_A0 >> 0x10),*(undefined2 *)(*in_A0 + 4)) &
      0x7fffffff) < 0x3fff8000) {
    *(float10 *)*in_A0 = fVar1 / SQRT(((float10)1.0 - fVar1) * ((float10)1.0 + fVar1));
    satan();
    t_frcinx();
    return;
  }
  if (ABS(fVar1) - (float10)1.0 != FLOAT_UNKNOWN && FLOAT_UNKNOWN <= ABS(fVar1) - (float10)1.0) {
    t_operr();
    return;
  }
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2697 start=0x409f660 */

void satand(void)

{
  t_extdnrm();
  return;
}
/* GHIDRADEC_FUNCTION index=2698 start=0x409f666 */

void satan(void)

{
  word wVar1;
  undefined auVar2 [12];
  uint uVar3;
  int iVar4;
  word wVar5;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  auVar2 = *in_A0;
  wVar1 = *(word *)(*in_A0 + 4);
  wVar5 = (word)((uint)*(undefined4 *)*in_A0 >> 0x10);
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(float)auVar2;
  uVar3 = CONCAT22(wVar5,wVar1) & 0x7fffffff;
  if (uVar3 < 0x3ffb8000) {
    if (0x3fd77fff < uVar3) {
      *(undefined2 *)(unaff_A6 + -0x72) = 0;
      t_frcinx();
      return;
    }
    *(undefined2 *)(unaff_A6 + -0x72) = 0;
    t_frcinx();
    return;
  }
  if (uVar3 < 0x40030000) {
    *(undefined2 *)(unaff_A6 + -0x72) = 0;
    *(uint *)(unaff_A6 + -0x70) = *(uint *)(unaff_A6 + -0x70) & 0xf8000000;
    *(uint *)(unaff_A6 + -0x70) = *(uint *)(unaff_A6 + -0x70) | 0x4000000;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    iVar4 = (int)(((int)((wVar5 & 0x7fff) * 0x10000 + -0x3ffb0000) >> 1) + (wVar1 & 0x7800)) >> 7;
    *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(dword_409EE60 + iVar4);
    *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(dword_409EE60 + iVar4 + 4);
    *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(dword_409EE60 + iVar4 + 8);
    *(uint *)(unaff_A6 + -100) =
         *(uint *)(unaff_A6 + -0x74) & 0x80000000 | *(uint *)(unaff_A6 + -100);
    t_frcinx();
    return;
  }
  if (uVar3 < 0x40638001) {
    *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(-1.0 / (float)auVar2);
    if (((*in_A0)[0] & 0x80) != 0) {
      t_frcinx();
      return;
    }
    t_frcinx();
    return;
  }
  if (((*in_A0)[0] & 0x80) != 0) {
    t_frcinx();
    return;
  }
  t_frcinx();
  return;
}
/* GHIDRADEC_FUNCTION index=2699 start=0x409f8e2 */

void satanhd(void)

{
  t_extdnrm();
  return;
}

