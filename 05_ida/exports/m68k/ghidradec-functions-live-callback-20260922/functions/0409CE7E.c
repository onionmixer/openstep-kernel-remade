
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

