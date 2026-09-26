
/* WARNING: Removing unreachable block (ram,0xf001bfc0) */
/* WARNING: Removing unreachable block (ram,0xf001bfb0) */
/* WARNING: Removing unreachable block (ram,0xf001c088) */
/* WARNING: Removing unreachable block (ram,0xf001bf8c) */
/* WARNING: Removing unreachable block (ram,0xf001bfb8) */
/* WARNING: Removing unreachable block (ram,0xf001c170) */
/* WARNING: Removing unreachable block (ram,0xf001bf5c) */
/* WARNING: Removing unreachable block (ram,0xf001c030) */

undefined8 _ptcwrite(uint param_1,int *param_2)

{
  undefined uVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
  undefined *puVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  uint *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined *puVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar6 = (undefined *)0x0;
  iVar10 = (param_1 & 0xff) * 0x10;
  piVar5 = *(int **)(DAT_f012f20c + iVar10);
  iVar4 = 0;
  piVar7 = (int *)*param_2;
  iVar8 = 0;
  puVar9 = *(uint **)(DAT_f012f20c + iVar10 + 4);
  uVar2 = piVar5[0x10];
  do {
    if ((uVar2 & 4) != 0) {
      if ((*puVar9 & 0x20) == 0) {
        iVar10 = param_2[1];
        if (0 < iVar10) {
          do {
            piVar7 = (int *)*param_2;
            if (iVar4 == 0) {
              iVar3 = piVar7[1];
              if (iVar3 != 0) {
                if (100 < iVar3) {
                  iVar3 = 100;
                }
                puVar6 = (undefined *)((int)register0x00000038 + -0x70);
                puVar11 = puVar6;
                _uiomove(puVar6,iVar3,1,param_2);
                if (puVar11 == (undefined *)0x0) {
                  iVar4 = iVar3;
                  if ((piVar5[0x10] & 4U) != 0) goto loc_F001C0CC;
                  puVar11 = (undefined *)0x5;
                }
                goto locret_F001C180;
              }
              param_2[1] = iVar10 + -1;
              *param_2 = *param_2 + 8;
            }
            else {
loc_F001C0CC:
              for (; 0 < iVar4; iVar4 = iVar4 + -1) {
                if ((0x3fd < *piVar5 + piVar5[3]) &&
                   ((0 < piVar5[3] || ((piVar5[0xf] & 0x22U) != 0)))) {
                  _wakeup(piVar5);
                  uVar2 = piVar5[0x10];
                  goto loc_F001C0F4;
                }
                iVar8 = iVar8 + 1;
                uVar1 = *puVar6;
                puVar6 = puVar6 + 1;
                (**(code **)(DAT_f010b8e0 + *(char *)((int)piVar5 + 0x47) * 0x30))(uVar1,piVar5);
              }
              iVar4 = 0;
            }
            iVar10 = param_2[1];
          } while (0 < iVar10);
          puVar11 = (undefined *)0x0;
          goto locret_F001C180;
        }
        goto loc_F001BFC8;
      }
      if (piVar5[3] == 0) {
        iVar8 = param_2[1];
        if (iVar8 < 1) goto loc_F001BFAC;
        iVar10 = piVar5[3];
        break;
      }
      uVar2 = piVar5[0x10];
    }
loc_F001C0F4:
    if ((uVar2 & 0x10) == 0) goto loc_F001C0FC;
    if ((*puVar9 & 4) != 0) goto loc_f001c110;
    _sleep(piVar5 + 1,0x1d);
    uVar2 = piVar5[0x10];
  } while( true );
loc_F001BEEC:
  if (0x3fe < iVar10) goto loc_F001BFAC;
  iVar3 = *(int *)(*param_2 + 4);
  if (iVar3 == 0) {
    param_2[1] = iVar8 + -1;
    *param_2 = *param_2 + 8;
  }
  else {
    if (iVar4 == 0) {
      if (100 < iVar3) {
        iVar3 = 100;
      }
      iVar4 = iVar3;
      if (0x3ff - iVar10 < iVar3) {
        iVar4 = 0x3ff - iVar10;
      }
      puVar6 = (undefined *)((int)register0x00000038 + -0x70);
      puVar11 = puVar6;
      _uiomove(puVar6,iVar4,1,param_2);
      if (puVar11 != (undefined *)0x0) goto locret_F001C180;
      if ((piVar5[0x10] & 4U) == 0) goto loc_F001C0FC;
    }
    if (iVar4 != 0) {
      _b_to_q(puVar6,iVar4,piVar5 + 3);
    }
    iVar4 = 0;
  }
  iVar8 = param_2[1];
  if (iVar8 < 1) goto loc_F001BFAC;
  iVar10 = piVar5[3];
  goto loc_F001BEEC;
loc_F001BFAC:
  _putc(0,piVar5 + 3);
  _ttwakeup(piVar5);
  _wakeup(piVar5 + 3);
  goto loc_F001BFC8;
loc_F001C0FC:
  puVar11 = (undefined *)0x5;
  goto locret_F001C180;
loc_f001c110:
  *piVar7 = *piVar7 - iVar4;
  piVar7[1] = piVar7[1] + iVar4;
  param_2[5] = param_2[5] + iVar4;
  param_2[2] = param_2[2] - iVar4;
  if (iVar8 == 0) {
    puVar11 = (undefined *)0x23;
    if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
      puVar11 = (undefined *)0xb;
    }
    goto locret_F001C180;
  }
loc_F001BFC8:
  puVar11 = (undefined *)0x0;
locret_F001C180:
  return CONCAT44(param_2,puVar11);
}
