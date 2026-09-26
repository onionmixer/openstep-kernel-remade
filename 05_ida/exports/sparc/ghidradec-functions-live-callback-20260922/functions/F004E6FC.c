
/* WARNING: Removing unreachable block (ram,0xf004e908) */
/* WARNING: Removing unreachable block (ram,0xf004e848) */
/* WARNING: Removing unreachable block (ram,0xf004ed68) */
/* WARNING: Removing unreachable block (ram,0xf004ed1c) */
/* WARNING: Removing unreachable block (ram,0xf004ec24) */
/* WARNING: Removing unreachable block (ram,0xf004eb70) */
/* WARNING: Removing unreachable block (ram,0xf004eb1c) */
/* WARNING: Removing unreachable block (ram,0xf004ea8c) */
/* WARNING: Removing unreachable block (ram,0xf004ea6c) */
/* WARNING: Removing unreachable block (ram,0xf004ea24) */
/* WARNING: Removing unreachable block (ram,0xf004e968) */
/* WARNING: Removing unreachable block (ram,0xf004e764) */
/* WARNING: Removing unreachable block (ram,0xf004e740) */
/* WARNING: Removing unreachable block (ram,0xf004e944) */
/* WARNING: Removing unreachable block (ram,0xf004e998) */
/* WARNING: Removing unreachable block (ram,0xf004ea40) */
/* WARNING: Removing unreachable block (ram,0xf004ea84) */
/* WARNING: Removing unreachable block (ram,0xf004ea9c) */
/* WARNING: Removing unreachable block (ram,0xf004eb48) */
/* WARNING: Removing unreachable block (ram,0xf004ec08) */
/* WARNING: Removing unreachable block (ram,0xf004ecf8) */
/* WARNING: Removing unreachable block (ram,0xf004ed38) */
/* WARNING: Removing unreachable block (ram,0xf004eda8) */
/* WARNING: Removing unreachable block (ram,0xf004e898) */
/* WARNING: Removing unreachable block (ram,0xf004e7f4) */
/* WARNING: Removing unreachable block (ram,0xf004e734) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _itrunc(uint param_1,uint param_2)

{
  int *piVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  byte bVar8;
  undefined *puVar7;
  undefined4 unaff_l0;
  int iVar9;
  uint *puVar10;
  undefined4 unaff_l1;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  undefined4 unaff_l3;
  int iVar14;
  undefined4 unaff_l4;
  int iVar15;
  undefined4 unaff_l5;
  undefined4 uVar16;
  undefined *puVar17;
  undefined4 unaff_l6;
  undefined *puVar18;
  undefined4 unaff_l7;
  int iVar19;
  undefined4 unaff_i0;
  int iVar20;
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
  int aiStack_74 [11];
  int aiStack_48 [18];
  
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
  *(undefined4 *)((int)register0x00000038 + -0x104) = 0;
  puVar18 = (undefined *)0x0;
  wVar2 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 & 0xffee;
    _wakeup(param_1);
  }
  iVar3 = param_1 + 0xc;
  _mfs_trunc(iVar3,param_2);
  wVar2 = *(word *)(param_1 + 0x44);
  while ((wVar2 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 | 0x10;
    _sleep(param_1,10);
    wVar2 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  if ((*(word *)(param_1 + 100) & 0xf000) == 0xa000) {
    iVar15 = 0xe;
    if ((*(uint *)(param_1 + 200) & 1) == 0) {
      uVar6 = *(uint *)(param_1 + 0x70);
      goto loc_F004E7D8;
    }
    iVar3 = param_1 + 0x38;
    do {
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      iVar15 = iVar15 + -1;
      iVar3 = iVar3 + -4;
    } while (-1 < iVar15);
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x70);
loc_F004E7D8:
    if (param_2 != uVar6) {
      iVar15 = *(int *)(param_1 + 0x50);
      uVar12 = param_2 & ~*(uint *)(iVar15 + 0x48);
      bVar8 = (byte)*(undefined4 *)(iVar15 + 0x50);
      uVar11 = param_2 - 1 >> (bVar8 & 0x1f);
      if (uVar6 < param_2) {
        if (uVar12 == 0) {
          uVar12 = *(uint *)(iVar15 + 0x30);
        }
        uVar6 = param_1;
        _bmap(param_1,uVar11,0,uVar12,(undefined *)((int)register0x00000038 + -0x104));
        if ((*(char *)(dword_F0133DDC + 0x38) == '\0') ||
           (iVar3 = *(int *)((int)register0x00000038 + -0x104), -1 < (int)uVar6)) {
          wVar2 = *(word *)(param_1 + 0x44);
          *(uint *)(param_1 + 0x70) = param_2;
          *(word *)(param_1 + 0x44) = wVar2 | 0x40;
          if ((wVar2 & 0x46 | 0x40) != 0) {
            *(word *)(param_1 + 0x44) = wVar2 | 0x48;
            _microtime(&_iuniqtime);
            if ((*(word *)(param_1 + 0x44) & 4) != 0) {
              *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
            }
            if ((*(word *)(param_1 + 0x44) & 2) != 0) {
              *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
            }
            if ((*(word *)(param_1 + 0x44) & 0x40) == 0) {
              wVar2 = *(word *)(param_1 + 0x44);
            }
            else {
              *(undefined4 *)(param_1 + 0x4c) = 0;
              *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
              wVar2 = *(word *)(param_1 + 0x44);
            }
            *(word *)(param_1 + 0x44) = wVar2 & 0xffb9;
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x104);
        }
        if (iVar3 != 0) {
          _iupdat(param_1,1);
        }
      }
      else {
        uVar6 = (param_2 + *(int *)(iVar15 + 0x30)) - 1 >> (bVar8 & 0x1f);
        *(uint *)((int)register0x00000038 + -0x18) = uVar6 - 0xd;
        iVar9 = (uVar6 - 0xd) - *(int *)(iVar15 + 0x74);
        *(int *)((int)register0x00000038 + -0x14) = iVar9;
        iVar20 = *(int *)(iVar15 + 0x74);
        iVar19 = uVar6 - 1;
        umul(iVar20,iVar20);
        *(int *)((int)register0x00000038 + -0x10) = iVar9 - iVar20;
        iVar20 = param_1 + 0xc;
        (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar20);
        iVar9 = *(int *)(iVar15 + 0x30);
        div(iVar9,iVar20);
        uVar16 = *(undefined4 *)(param_1 + 0x70);
        if (uVar12 == 0) {
          *(uint *)(param_1 + 0x70) = param_2;
        }
        else {
          uVar4 = param_1;
          _bmap(param_1,uVar11,0,uVar12,0);
          iVar20 = (int)*(char *)(dword_F0133DDC + 0x38);
          iVar14 = uVar4 << ((byte)*(undefined4 *)(iVar15 + 100) & 0x1f);
          if ((iVar20 != 0) || (iVar14 < 0)) goto locret_F004EDF4;
          *(uint *)(param_1 + 0x70) = param_2;
          if (((int)uVar11 < 0xc) &&
             (param_2 < uVar11 + 1 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f))) {
            uVar11 = ((param_2 & ~*(uint *)(iVar15 + 0x48)) + *(int *)(iVar15 + 0x34)) - 1 &
                     *(uint *)(iVar15 + 0x4c);
          }
          else {
            uVar11 = *(uint *)(iVar15 + 0x30);
          }
          puVar10 = *(uint **)(param_1 + 0x40);
          if (**(int **)(param_1 + 0xc) != 0) {
            _vnode_uncache(param_1 + 0xc);
          }
          if (iVar3 == 0) {
            _bread(puVar10,iVar14,uVar11);
            if ((*puVar10 & 4) != 0) {
              *(undefined *)(dword_F0133DDC + 0x38) = 5;
              *(undefined4 *)(param_1 + 0x70) = uVar16;
              _brelse(puVar10);
              iVar20 = 5;
              goto locret_F004EDF4;
            }
            _bzero(puVar10[8] + uVar12,uVar11 - uVar12);
            _bdwrite(puVar10);
          }
        }
        _memcpy((undefined *)((int)register0x00000038 + -0x100),param_1,0xe8);
        *(undefined4 *)((int)register0x00000038 + -0x90) = uVar16;
        iVar3 = 2;
        iVar20 = param_1 + 8;
        puVar7 = (undefined *)register0x00000038;
        do {
          if (*(int *)(puVar7 + -0x10) < 0) {
            *(undefined4 *)(iVar20 + 0xbc) = 0;
            *(undefined4 *)(puVar7 + -0x10) = 0xffffffff;
          }
          iVar20 = iVar20 + -4;
          iVar3 = iVar3 + -1;
          puVar7 = puVar7 + -4;
        } while (-1 < iVar3);
        iVar20 = 0xb;
        iVar3 = param_1 + 0x2c;
        if (iVar19 < 0xb) {
          do {
            *(undefined4 *)(iVar3 + 0x8c) = 0;
            iVar20 = iVar20 + -1;
            iVar3 = iVar3 + -4;
          } while (iVar19 < iVar20);
        }
        *(uint *)(param_1 + 0x70) = param_2;
        iVar3 = 2;
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
        _iupdat(param_1,1);
        puVar17 = (undefined *)((int)register0x00000038 + -0x100);
        puVar13 = (undefined *)((int)register0x00000038 + -0xf8);
        puVar7 = (undefined *)register0x00000038;
        do {
          iVar20 = *(int *)(puVar13 + 0xbc);
          if (iVar20 != 0) {
            puVar5 = puVar17;
            _indirtrunc(puVar17,iVar20,*(undefined4 *)(puVar7 + -0x10),iVar3);
            puVar18 = puVar18 + (int)puVar5;
            if (*(int *)(puVar7 + -0x10) < 0) {
              *(undefined4 *)(puVar13 + 0xbc) = 0;
              puVar18 = puVar18 + iVar9;
              _free_block(puVar17,iVar20,*(undefined4 *)(iVar15 + 0x30));
            }
          }
          piVar1 = (int *)(puVar7 + -0x10);
          puVar7 = puVar7 + -4;
          if (-1 < *piVar1) goto loc_F004ED44;
          iVar3 = iVar3 + -1;
          puVar13 = puVar13 + -4;
        } while (-1 < iVar3);
        iVar3 = 0xb;
        if (iVar19 < 0xb) {
          puVar7 = (undefined *)((int)register0x00000038 + -0xd4);
          do {
            iVar20 = *(int *)(puVar7 + 0x8c);
            if (iVar20 != 0) {
              *(undefined4 *)(puVar7 + 0x8c) = 0;
              if ((iVar3 < 0xc) &&
                 (*(uint *)((int)register0x00000038 + -0x90) <
                  (uint)(iVar3 + 1 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)))) {
                uVar12 = ((*(uint *)((int)register0x00000038 + -0x90) & ~*(uint *)(iVar15 + 0x48)) +
                         *(int *)(iVar15 + 0x34)) - 1 & *(uint *)(iVar15 + 0x4c);
              }
              else {
                uVar12 = *(uint *)(iVar15 + 0x30);
              }
              _free_block(puVar17,iVar20,uVar12);
              iVar20 = param_1 + 0xc;
              (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar20);
              udiv(uVar12,iVar20);
              puVar18 = puVar18 + uVar12;
            }
            iVar3 = iVar3 + -1;
            puVar7 = puVar7 + -4;
          } while (iVar19 < iVar3);
        }
        if ((-1 < iVar19) && (iVar3 = *(int *)(puVar17 + iVar19 * 4 + 0x8c), iVar3 != 0)) {
          if (iVar19 < 0xc) {
            if (*(uint *)((int)register0x00000038 + -0x90) <
                uVar6 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)) {
              uVar12 = ((*(uint *)((int)register0x00000038 + -0x90) & ~*(uint *)(iVar15 + 0x48)) +
                       *(int *)(iVar15 + 0x34)) - 1 & *(uint *)(iVar15 + 0x4c);
            }
            else {
              uVar12 = *(uint *)(iVar15 + 0x30);
            }
          }
          else {
            uVar12 = *(uint *)(iVar15 + 0x30);
          }
          *(uint *)((int)register0x00000038 + -0x90) = param_2;
          if ((iVar19 < 0xc) && (param_2 < uVar6 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)))
          {
            uVar6 = ((param_2 & ~*(uint *)(iVar15 + 0x48)) + *(int *)(iVar15 + 0x34)) - 1 &
                    *(uint *)(iVar15 + 0x4c);
          }
          else {
            uVar6 = *(uint *)(iVar15 + 0x30);
          }
          if (uVar6 == 0) {
            _panic(aItruncNewspace);
          }
          if (uVar12 != uVar6) {
            iVar20 = uVar12 - uVar6;
            _free_block(puVar17,iVar3 + (uVar6 >> ((byte)*(undefined4 *)(iVar15 + 0x54) & 0x1f)),
                        iVar20);
            iVar3 = param_1 + 0xc;
            (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar3);
            udiv(iVar20,iVar3);
            puVar18 = puVar18 + iVar20;
          }
        }
loc_F004ED44:
        iVar3 = 0;
        puVar7 = puVar17;
        uVar6 = param_1;
        do {
          if (*(int *)(puVar7 + 0xbc) != *(int *)(uVar6 + 0xbc)) {
            _panic(&aItrunc1);
          }
          uVar6 = uVar6 + 4;
          iVar3 = iVar3 + 1;
          puVar7 = puVar7 + 4;
        } while (iVar3 < 3);
        iVar3 = 0;
        param_2 = param_1;
        do {
          if (*(int *)(puVar17 + 0x8c) != *(int *)(param_2 + 0x8c)) {
            _panic(&aItrunc2);
          }
          param_2 = param_2 + 4;
          iVar3 = iVar3 + 1;
          puVar17 = puVar17 + 4;
        } while (iVar3 < 0xc);
        iVar3 = *(int *)(param_1 + 0xcc) - (int)puVar18;
        *(int *)(param_1 + 0xcc) = iVar3;
        if (iVar3 < 0) {
          *(undefined4 *)(param_1 + 0xcc) = 0;
        }
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x40;
      }
      iVar20 = (int)*(char *)(dword_F0133DDC + 0x38);
      goto locret_F004EDF4;
    }
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  _iupdat(param_1,1);
  iVar20 = 0;
locret_F004EDF4:
  return CONCAT44(param_2,iVar20);
}

