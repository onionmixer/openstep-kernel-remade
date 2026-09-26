
/* WARNING: Removing unreachable block (ram,0xf0050e50) */
/* WARNING: Removing unreachable block (ram,0xf0050df0) */
/* WARNING: Removing unreachable block (ram,0xf0050db0) */
/* WARNING: Removing unreachable block (ram,0xf0050d4c) */
/* WARNING: Removing unreachable block (ram,0xf0050d18) */
/* WARNING: Removing unreachable block (ram,0xf0050cf8) */
/* WARNING: Removing unreachable block (ram,0xf0050cb0) */
/* WARNING: Removing unreachable block (ram,0xf0050c90) */
/* WARNING: Removing unreachable block (ram,0xf0050c30) */
/* WARNING: Removing unreachable block (ram,0xf0050bec) */
/* WARNING: Removing unreachable block (ram,0xf0050bf4) */
/* WARNING: Removing unreachable block (ram,0xf0050b10) */
/* WARNING: Removing unreachable block (ram,0xf0050af0) */
/* WARNING: Removing unreachable block (ram,0xf0050a50) */
/* WARNING: Removing unreachable block (ram,0xf00509e8) */
/* WARNING: Removing unreachable block (ram,0xf0050950) */
/* WARNING: Removing unreachable block (ram,0xf0050940) */
/* WARNING: Removing unreachable block (ram,0xf0050960) */
/* WARNING: Removing unreachable block (ram,0xf0050a44) */
/* WARNING: Removing unreachable block (ram,0xf0050ad8) */
/* WARNING: Removing unreachable block (ram,0xf0050b64) */
/* WARNING: Removing unreachable block (ram,0xf0050b4c) */
/* WARNING: Removing unreachable block (ram,0xf0050c24) */
/* WARNING: Removing unreachable block (ram,0xf0050c70) */
/* WARNING: Removing unreachable block (ram,0xf0050dc4) */
/* WARNING: Removing unreachable block (ram,0xf0050ccc) */
/* WARNING: Removing unreachable block (ram,0xf0050d10) */
/* WARNING: Removing unreachable block (ram,0xf0050d44) */
/* WARNING: Removing unreachable block (ram,0xf0050d98) */
/* WARNING: Removing unreachable block (ram,0xf0050b94) */
/* WARNING: Removing unreachable block (ram,0xf0050e04) */
/* WARNING: Removing unreachable block (ram,0xf0050898) */
/* WARNING: Removing unreachable block (ram,0xf0050c00) */

undefined8 sub_F0050874(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  sword sVar3;
  bool bVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  undefined *puVar8;
  undefined uVar10;
  int iVar9;
  undefined4 uVar11;
  undefined4 unaff_l0;
  int iVar12;
  int iVar13;
  undefined4 unaff_l1;
  uint uVar14;
  int iVar15;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int *piVar16;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar17;
  undefined4 unaff_i1;
  int iVar18;
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
  piVar16 = (int *)0x0;
  iVar18 = 0;
  if (dword_F010F0BC == 0) {
    _ihinit();
    dword_F010F0BC = 1;
  }
  uVar11 = 3;
  if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
    uVar11 = 1;
  }
  piVar17 = param_1;
  (*(code *)**(undefined4 **)(*param_1 + 0x1c))(param_1,uVar11,*(undefined4 *)(_active_u + 0x1c));
  iVar7 = iVar18;
  if (piVar17 != (int *)0x0) goto locret_F0050E58;
  iVar5 = *param_1;
  bVar4 = true;
  (**(code **)(*(int *)(iVar5 + 0x1c) + 0x80))();
  uVar11 = 3;
  if (iVar5 == 0) {
    if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
      uVar11 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))
              (*param_1,uVar11,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*param_1);
    piVar17 = (int *)0xf;
    goto locret_F0050E58;
  }
  uVar11 = 0x2000;
  .udiv(0x2000,iVar5);
  puVar6 = (uint *)*param_1;
  _bread(puVar6,uVar11,0x2000);
  if ((*puVar6 & 4) != 0) goto loc_F0050DD0;
  piVar16 = _mounttab;
  if (_mounttab == (int *)0x0) {
    iVar7 = *param_1;
  }
  else {
    iVar7 = _mounttab[3];
    while( true ) {
      if (iVar7 == 0) {
        piVar16 = (int *)piVar16[8];
      }
      else {
        if (*(sword *)(*param_1 + 0x2c) == *(sword *)(piVar16 + 1)) {
          uVar14 = *(uint *)(param_3 + 0xc);
          if ((uVar14 & 0x40) != 0) goto loc_F0050AFC;
          piVar16 = (int *)0x0;
          piVar17 = (int *)0x10;
          bVar4 = false;
          iVar7 = iVar18;
          goto loc_F0050DD0;
        }
        piVar16 = (int *)piVar16[8];
      }
      if (piVar16 == (int *)0x0) break;
      iVar7 = piVar16[3];
    }
    iVar7 = *param_1;
  }
  _vol_notify_cancel((int)*(sword *)(iVar7 + 0x2c));
  if ((*(uint *)(param_3 + 0xc) & 0x40) == 0) {
    if (_mounttab == (int *)0x0) {
loc_F0050A44:
      piVar16 = (int *)0x24;
      _kalloc();
      _bzero();
      if (piVar16 == (int *)0x0) {
        piVar17 = (int *)0x18;
        iVar7 = iVar18;
        goto loc_F0050DD0;
      }
      piVar16[8] = (int)_mounttab;
      _mounttab = piVar16;
      *(int **)(param_3 + 0x128) = piVar16;
    }
    else {
      iVar7 = _mounttab[3];
      piVar16 = _mounttab;
      while (iVar7 != 0) {
        piVar16 = (int *)piVar16[8];
        if (piVar16 == (int *)0x0) goto loc_F0050A44;
        iVar7 = piVar16[3];
      }
      *(int **)(param_3 + 0x128) = piVar16;
    }
    *piVar16 = param_3;
    piVar16[3] = (int)puVar6;
    *(undefined2 *)(piVar16 + 1) = 0xffff;
    piVar16[2] = *param_1;
    uVar14 = puVar6[8];
    if (*(int *)(uVar14 + 0x55c) == 0x11954) {
      if ((int)*(uint *)(uVar14 + 0x30) < 0x2001) {
        if (*(uint *)(uVar14 + 0x30) < 0x564) {
          piVar17 = (int *)0x16;
          iVar7 = iVar18;
        }
        else {
          iVar7 = *(int *)(uVar14 + 0x68);
          _geteblk();
          piVar16[3] = iVar7;
          _bcopy(puVar6[8],*(undefined4 *)(iVar7 + 0x20),*(undefined4 *)(uVar14 + 0x68));
          uVar14 = *(uint *)(param_3 + 0xc);
loc_F0050AFC:
          if ((uVar14 & 1) == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0;
            _bwrite(puVar6);
            if (*(char *)(dword_F0133DDC + 0x38) == '\x1e') {
              *(undefined *)(dword_F0133DDC + 0x38) = 0;
              if (*param_1 == _rootvp) {
                _panic(aRootDeviceIsPh);
                uVar14 = *(uint *)(param_3 + 0xc);
              }
              else {
                uVar14 = *(uint *)(param_3 + 0xc);
              }
              *(uint *)(param_3 + 0xc) = uVar14 | 1;
              goto loc_F0050B6C;
            }
            uVar14 = *(uint *)(param_3 + 0xc);
          }
          else {
            _brelse(puVar6);
loc_F0050B6C:
            uVar14 = *(uint *)(param_3 + 0xc);
          }
          puVar6 = (uint *)0x0;
          iVar18 = *(int *)(iVar7 + 0x20);
          if ((uVar14 & 1) == 0) {
            uVar10 = 3;
            if (*(char *)(iVar18 + 0xd1) == '\x01') {
              uVar10 = 2;
            }
            *(undefined *)(iVar18 + 0xd1) = uVar10;
            *(undefined *)(iVar18 + 0xd0) = 1;
            *(undefined *)(iVar18 + 0xd2) = 0;
            if ((*(uint *)(param_3 + 0xc) & 0x40) != 0) {
              *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
              _sbupdate(piVar16);
              piVar17 = (int *)0x0;
              goto locret_F0050E58;
            }
          }
          else {
            if ((uVar14 & 0x40) != 0) {
              puVar8 = aMountfsCanTRem;
              goto loc_F0050B94;
            }
            *(undefined *)(iVar18 + 0xd0) = 0;
            *(undefined *)(iVar18 + 0xd2) = 1;
          }
          *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar18 + 0x30);
          iVar12 = *(int *)(iVar18 + 0x9c);
          iVar5 = iVar12 + -1 + *(int *)(iVar18 + 0x34);
          .div();
          _kalloc();
          iVar13 = 0;
          if (iVar12 != 0) {
            if (iVar5 < 1) {
              cVar1 = *(char *)(iVar18 + 0xd2);
            }
            else {
              iVar9 = *(int *)(iVar18 + 0x38);
              do {
                iVar15 = *(int *)(iVar18 + 0x30);
                if (iVar5 < iVar13 + iVar9) {
                  iVar15 = iVar5 - iVar13;
                  .umul(iVar15,*(undefined4 *)(iVar18 + 0x34));
                }
                puVar6 = (uint *)piVar16[2];
                _bread(puVar6,*(int *)(iVar18 + 0x98) + iVar13 <<
                              ((byte)*(undefined4 *)(iVar18 + 100) & 0x1f),iVar15);
                if ((*puVar6 & 4) != 0) {
                  _kfree(iVar12,*(undefined4 *)(iVar18 + 0x9c));
                  goto loc_F0050DD0;
                }
                _bcopy(puVar6[8],iVar12,iVar15);
                *(int *)((iVar13 >> ((byte)*(undefined4 *)(iVar18 + 0x60) & 0x1f)) * 4 + iVar18 +
                        0x2d8) = iVar12;
                _brelse(puVar6);
                iVar9 = *(int *)(iVar18 + 0x38);
                iVar13 = iVar13 + iVar9;
                iVar12 = iVar12 + iVar15;
              } while (iVar13 < iVar5);
              cVar1 = *(char *)(iVar18 + 0xd2);
            }
            if (cVar1 == '\0') {
              _sbupdate(piVar16);
              bVar2 = *(byte *)(iVar18 + 0xd3);
            }
            else {
              bVar2 = *(byte *)(iVar18 + 0xd3);
            }
            iVar5 = *(int *)(iVar18 + 0x28);
            *(byte *)(iVar18 + 0xd3) = bVar2 & 0xfc;
            .umul(iVar5,*(undefined4 *)(iVar18 + 0x3c));
            .div();
            *(int *)(iVar18 + 0x8c) = iVar5;
            *(int *)(iVar18 + 0x88) = iVar5;
            if (iVar5 < 0x65) {
              iVar5 = iVar5 << 1;
            }
            else {
              iVar5 = iVar5 + 100;
            }
            *(int *)(iVar18 + 0x88) = iVar5;
            iVar5 = *(int *)(iVar18 + 0x2c);
            .umul(iVar5,*(undefined4 *)(iVar18 + 0xb8));
            .div();
            *(int *)(iVar18 + 0x94) = iVar5;
            if (0x32 < iVar5) {
              *(undefined4 *)(iVar18 + 0x94) = 0x32;
            }
            *(undefined4 *)(iVar18 + 0x90) = *(undefined4 *)(iVar18 + 0x94);
            sVar3 = *(sword *)(piVar16[2] + 0x2c);
            *(sword *)(piVar16 + 1) = sVar3;
            *(int *)(param_3 + 0x14) = (int)sVar3;
            *(undefined4 *)(param_3 + 0x18) = 0;
            _copystr(param_2,iVar18 + 0xd4,0x1ff,(undefined *)((int)register0x00000038 + -0x4c));
            _bzero(iVar18 + *(int *)((int)register0x00000038 + -0x4c) + 0xd4,
                   0x200 - *(int *)((int)register0x00000038 + -0x4c));
            piVar17 = (int *)0x0;
            goto locret_F0050E58;
          }
          piVar17 = (int *)0xc;
        }
      }
      else {
        piVar17 = (int *)0x16;
        iVar7 = iVar18;
      }
    }
    else {
      piVar17 = (int *)0x16;
      iVar7 = iVar18;
    }
  }
  else {
    *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
    puVar8 = aMountfsIllegal;
    iVar7 = iVar18;
loc_F0050B94:
    _printf(puVar8);
    piVar17 = (int *)0x16;
  }
loc_F0050DD0:
  if (piVar17 == (int *)0x0) {
    piVar17 = (int *)0x5;
  }
  if (piVar16 != (int *)0x0) {
    piVar16[3] = 0;
  }
  if (iVar7 != 0) {
    _brelse(iVar7);
  }
  if (puVar6 != (uint *)0x0) {
    _brelse(puVar6);
  }
  uVar11 = 3;
  if (bVar4) {
    if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
      uVar11 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))
              (*param_1,uVar11,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*param_1);
  }
locret_F0050E58:
  return CONCAT44(iVar7,piVar17);
}
