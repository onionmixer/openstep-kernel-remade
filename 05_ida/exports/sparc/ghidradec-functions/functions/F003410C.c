
/* WARNING: Removing unreachable block (ram,0xf0034478) */
/* WARNING: Removing unreachable block (ram,0xf0034380) */
/* WARNING: Removing unreachable block (ram,0xf00341b4) */
/* WARNING: Removing unreachable block (ram,0xf00341a8) */
/* WARNING: Removing unreachable block (ram,0xf003414c) */
/* WARNING: Removing unreachable block (ram,0xf00345d0) */
/* WARNING: Removing unreachable block (ram,0xf0034398) */
/* WARNING: Removing unreachable block (ram,0xf0034648) */
/* WARNING: Removing unreachable block (ram,0xf0034120) */

undefined8 _ip_setmoptions(undefined4 param_1,int *param_2,int param_3)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int *piVar6;
  sword sVar7;
  int *piVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined4 unaff_l3;
  undefined4 uVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar13;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  iVar3 = *param_2;
  uVar12 = 0;
  if (iVar3 == 0) {
    _spltty();
    iVar9 = _mfree;
    bVar14 = _mfree == 0;
    *param_2 = _mfree;
    if (bVar14) {
      iVar9 = 1;
      _m_more(1,0xe);
      *param_2 = iVar9;
    }
    else {
      if (*(sword *)(iVar9 + 10) != 0) {
        _panic(&aMget_10);
      }
      *(undefined2 *)(*param_2 + 10) = 0xe;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b28._0_2_ = DAT_f0134b28._0_2_ + 1;
      _mfree = *(int *)*param_2;
      *(undefined4 *)*param_2 = 0;
      *(undefined4 *)(*param_2 + 4) = 0xc;
    }
    _splx(iVar3);
    iVar3 = *param_2;
    if (iVar3 == 0) {
      uVar12 = 0x37;
      goto locret_F0034658;
    }
    iVar9 = iVar3 + *(int *)(iVar3 + 4);
    *(undefined4 *)(iVar3 + *(int *)(iVar3 + 4)) = 0;
    *(undefined *)(iVar9 + 4) = 1;
    *(undefined *)(iVar9 + 5) = 1;
    *(undefined2 *)(iVar9 + 6) = 0;
  }
  piVar10 = (int *)(*param_2 + *(int *)(*param_2 + 4));
  switch(param_1) {
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 4) {
      iVar3 = *(int *)(param_3 + *(int *)(param_3 + 4));
      if (iVar3 == 0) {
        *piVar10 = 0;
      }
      else {
        iVar9 = 0;
        if (_in_ifaddr != 0) {
          iVar9 = *(int *)(_in_ifaddr + 4);
          iVar13 = _in_ifaddr;
          while ((iVar9 != iVar3 && (iVar13 = *(int *)(iVar13 + 0x40), iVar13 != 0))) {
            iVar9 = *(int *)(iVar13 + 4);
          }
          iVar9 = 0;
          if (iVar13 != 0) {
            iVar9 = *(int *)(iVar13 + 0x20);
          }
        }
        if (iVar9 == 0) {
          uVar12 = 0x31;
        }
        else {
          *piVar10 = iVar9;
        }
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 1) {
      *(undefined *)(piVar10 + 1) = *(undefined *)(param_3 + *(int *)(param_3 + 4));
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 1) {
      bVar1 = *(byte *)(param_3 + *(int *)(param_3 + 4));
      if (bVar1 < 2) {
        *(byte *)((int)piVar10 + 5) = bVar1;
      }
      else {
        uVar12 = 0x16;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 8) {
      iVar3 = *(int *)(param_3 + 4);
      piVar11 = (int *)(param_3 + iVar3);
      if ((*(uint *)(param_3 + iVar3) & 0xf0000000) == 0xe0000000) {
        if (piVar11[1] == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
          *(undefined2 *)((int)register0x00000038 + -0x1c) = 2;
          *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_3 + iVar3);
          _rtalloc((undefined *)((int)register0x00000038 + -0x20));
          if (*(int *)((int)register0x00000038 + -0x20) == 0) {
            uVar12 = 0x31;
            break;
          }
          iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x2c);
          _rtfree();
        }
        else {
          iVar3 = 0;
          if (_in_ifaddr != 0) {
            iVar3 = *(int *)(_in_ifaddr + 4);
            iVar9 = _in_ifaddr;
            while ((iVar3 != piVar11[1] && (iVar9 = *(int *)(iVar9 + 0x40), iVar9 != 0))) {
              iVar3 = *(int *)(iVar9 + 4);
            }
            iVar3 = 0;
            if (iVar9 != 0) {
              iVar3 = *(int *)(iVar9 + 0x20);
            }
          }
        }
        iVar9 = 0;
        if (iVar3 == 0) goto loc_F00345C4;
        iVar13 = -0x14;
        piVar8 = piVar10;
        if (*(word *)((int)piVar10 + 6) != 0) {
          do {
            if ((((int *)piVar8[2])[1] == iVar3) && (*(int *)piVar8[2] == *piVar11)) {
              wVar2 = *(word *)((int)piVar10 + 6);
              goto loc_F003444C;
            }
            iVar9 = iVar9 + 1;
            piVar8 = piVar8 + 1;
          } while (iVar9 < (int)(uint)*(word *)((int)piVar10 + 6));
          wVar2 = *(word *)((int)piVar10 + 6);
loc_F003444C:
          iVar13 = iVar9 + -0x14;
          if (iVar9 < (int)(uint)wVar2) {
            uVar12 = 0x30;
            break;
          }
        }
        puVar4 = (undefined *)((int)register0x00000038 + -0x24);
        if (iVar13 == 0) {
          uVar12 = 0x3b;
        }
        else {
          *(int *)((int)register0x00000038 + -0x24) = *piVar11;
          _in_addmulti(puVar4,iVar3);
          piVar10[iVar9 + 2] = (int)puVar4;
          if (puVar4 == (undefined *)0x0) {
            uVar12 = 0x37;
          }
          else {
            *(sword *)((int)piVar10 + 6) = *(sword *)((int)piVar10 + 6) + 1;
          }
        }
      }
      else {
loc_F00344EC:
        uVar12 = 0x16;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  case :
    if (param_3 == 0) {
      uVar12 = 0x16;
    }
    else if (*(sword *)(param_3 + 8) == 8) {
      piVar11 = (int *)(param_3 + *(int *)(param_3 + 4));
      if ((*(uint *)(param_3 + *(int *)(param_3 + 4)) & 0xf0000000) != 0xe0000000)
      goto loc_F00344EC;
      iVar3 = piVar11[1];
      if (iVar3 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = 0;
        if (_in_ifaddr != 0) {
          iVar9 = *(int *)(_in_ifaddr + 4);
          iVar13 = _in_ifaddr;
          while ((iVar9 != iVar3 && (iVar13 = *(int *)(iVar13 + 0x40), iVar13 != 0))) {
            iVar9 = *(int *)(iVar13 + 4);
          }
          iVar9 = 0;
          if (iVar13 != 0) {
            iVar9 = *(int *)(iVar13 + 0x20);
          }
        }
        if (iVar9 == 0) {
          uVar12 = 0x31;
          break;
        }
      }
      uVar5 = (uint)*(word *)((int)piVar10 + 6);
      iVar13 = 0;
      iVar3 = -uVar5;
      piVar8 = piVar10;
      if (uVar5 != 0) {
        do {
          piVar6 = (int *)piVar8[2];
          if (iVar9 == 0) {
loc_F0034590:
            if (*piVar6 == *piVar11) {
              wVar2 = *(word *)((int)piVar10 + 6);
              goto loc_F00345B8;
            }
          }
          else if (piVar6[1] == iVar9) {
            piVar6 = (int *)piVar8[2];
            goto loc_F0034590;
          }
          iVar13 = iVar13 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar13 < (int)uVar5);
        wVar2 = *(word *)((int)piVar10 + 6);
loc_F00345B8:
        iVar3 = iVar13 - (uint)wVar2;
      }
      if (iVar3 == 0) {
loc_F00345C4:
        uVar12 = 0x31;
      }
      else {
        _in_delmulti(piVar10[iVar13 + 2]);
        iVar13 = iVar13 + 1;
        if (iVar13 < (int)(uint)*(word *)((int)piVar10 + 6)) {
          piVar11 = piVar10 + iVar13;
          do {
            iVar13 = iVar13 + 1;
            piVar11[1] = piVar11[2];
            piVar11 = piVar11 + 1;
          } while (iVar13 < (int)(uint)*(word *)((int)piVar10 + 6));
          sVar7 = *(sword *)((int)piVar10 + 6);
        }
        else {
          sVar7 = *(sword *)((int)piVar10 + 6);
        }
        *(sword *)((int)piVar10 + 6) = sVar7 + -1;
      }
    }
    else {
      uVar12 = 0x16;
    }
    break;
  :
    uVar12 = 0x2d;
  }
  if ((*piVar10 == 0) && (piVar10[1] == 0x1010000)) {
    _m_free(*param_2);
    *param_2 = 0;
  }
locret_F0034658:
  return CONCAT44(param_2,uVar12);
}
