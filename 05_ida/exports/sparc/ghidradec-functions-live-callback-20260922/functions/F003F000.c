
/* WARNING: Removing unreachable block (ram,0xf003f374) */
/* WARNING: Removing unreachable block (ram,0xf003f340) */
/* WARNING: Removing unreachable block (ram,0xf003f2cc) */
/* WARNING: Removing unreachable block (ram,0xf003f190) */
/* WARNING: Removing unreachable block (ram,0xf003f1c0) */
/* WARNING: Removing unreachable block (ram,0xf003f230) */
/* WARNING: Removing unreachable block (ram,0xf003f1e8) */
/* WARNING: Removing unreachable block (ram,0xf003f258) */
/* WARNING: Removing unreachable block (ram,0xf003f148) */
/* WARNING: Removing unreachable block (ram,0xf003f0e8) */
/* WARNING: Removing unreachable block (ram,0xf003f0ac) */
/* WARNING: Removing unreachable block (ram,0xf003f0d0) */
/* WARNING: Removing unreachable block (ram,0xf003f0f8) */
/* WARNING: Removing unreachable block (ram,0xf003f17c) */
/* WARNING: Removing unreachable block (ram,0xf003f1d0) */
/* WARNING: Removing unreachable block (ram,0xf003f26c) */
/* WARNING: Removing unreachable block (ram,0xf003f1b0) */
/* WARNING: Removing unreachable block (ram,0xf003f08c) */
/* WARNING: Removing unreachable block (ram,0xf003f09c) */
/* WARNING: Removing unreachable block (ram,0xf003f334) */
/* WARNING: Removing unreachable block (ram,0xf003f384) */
/* WARNING: Removing unreachable block (ram,0xf003f3cc) */
/* WARNING: Removing unreachable block (ram,0xf003f074) */

undefined8 sub_F003F000(uint *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  word wVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  uint *puVar10;
  undefined4 unaff_l3;
  uint uVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar12;
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
  bVar3 = false;
  if (*(int *)(param_2 + 0x14) == 0) {
    puVar12 = (uint *)0x0;
  }
  else {
    uVar11 = *(int *)(param_2 + 8) + *(int *)(param_2 + 0x14);
    if ((-1 < *(int *)(param_2 + 8)) && (-1 < (int)uVar11)) {
      if (param_3 == 1) {
        if (param_1[10] == 1) {
          if ((uint)_active_u[0x9a] < uVar11) {
            _psignal(*_active_u,0x19);
            puVar12 = (uint *)0x1b;
            goto locret_F003F3D8;
          }
          uVar11 = param_1[0xc];
        }
        else {
          uVar11 = param_1[0xc];
        }
      }
      else {
        uVar11 = param_1[0xc];
      }
      _rlock(uVar11);
      puVar1 = (uint *)(*(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00);
      if ((int)puVar1 < 1) {
        _panic(aRwvpZeroSize);
      }
      iVar9 = *(int *)(param_2 + 8);
      puVar8 = (uint *)0x0;
      do {
        iVar7 = iVar9;
        udiv(iVar9,puVar1);
        urem(iVar9,puVar1);
        puVar10 = *(uint **)(param_2 + 0x14);
        if ((uint *)((int)puVar1 - iVar9) < *(uint **)(param_2 + 0x14)) {
          puVar10 = (uint *)((int)puVar1 - iVar9);
        }
        (**(code **)(param_1[7] + 0x50))
                  (param_1,iVar7,(undefined *)((int)register0x00000038 + -0x4c),
                   (undefined *)((int)register0x00000038 + -0x50));
        puVar6 = puVar1;
        if ((param_1[1] & 0x400000) != 0) {
          _geteblk();
          if (param_3 != 0) goto loc_F003F278;
          puVar12 = param_1;
          sub_F003F5B4(param_1,puVar6[8] + iVar9,*(undefined4 *)(param_2 + 8),puVar10,puVar6 + 10,
                       param_5,(undefined *)((int)register0x00000038 + -0x48));
          if (puVar12 == (uint *)0x0) {
            uVar4 = *puVar6;
            goto loc_F003F27C;
          }
loc_F003F190:
          _brelse(puVar6);
          goto loc_F003F3CC;
        }
        if (param_3 == 0) {
          iVar5 = *(int *)((int)register0x00000038 + -0x4c);
          if (iVar7 < 0) {
            _geteblk();
            _bzero(puVar6[8],puVar6[5]);
            puVar6[10] = 0;
          }
          else {
            _incore(iVar5,*(undefined4 *)((int)register0x00000038 + -0x50));
            if (iVar5 != 0) {
              _nfs_validate_caches(*(undefined4 *)((int)register0x00000038 + -0x4c),param_5,0);
            }
            puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
            if (*(int *)(uVar11 + 100) + 1 != iVar7) goto loc_F003F268;
            (**(code **)(param_1[7] + 0x50))
                      (param_1,*(int *)(uVar11 + 100) + 2,
                       (undefined *)((int)register0x00000038 + -0x4c),
                       (undefined *)((int)register0x00000038 + -0x54));
            puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
            _breada(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1,
                    *(undefined4 *)((int)register0x00000038 + -0x54),puVar1);
          }
        }
        else {
          puVar12 = (uint *)(int)*(sword *)(uVar11 + 0x62);
          if (puVar12 != (uint *)0x0) goto loc_F003F3CC;
          puVar6 = *(uint **)((int)register0x00000038 + -0x4c);
          if (puVar10 == puVar1) {
            _getblk(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1);
          }
          else {
loc_F003F268:
            _bread(puVar6,*(undefined4 *)((int)register0x00000038 + -0x50),puVar1);
          }
        }
loc_F003F278:
        uVar4 = *puVar6;
        puVar12 = puVar8;
loc_F003F27C:
        if ((uVar4 & 4) != 0) {
          puVar12 = puVar6;
          _geterror(puVar6);
          goto loc_F003F190;
        }
        if (param_3 == 0) {
          *(int *)(uVar11 + 100) = iVar7;
          puVar8 = (uint *)(*(int *)(uVar11 + 0x98) - *(int *)(param_2 + 8));
          if ((int)puVar8 < 1) {
            _brelse(puVar6);
            puVar12 = (uint *)0x0;
            goto loc_F003F3CC;
          }
          if ((int)puVar8 < (int)puVar10) {
            bVar3 = true;
            puVar10 = puVar8;
          }
        }
        iVar7 = puVar6[8] + iVar9;
        _uiomove(iVar7,puVar10,param_3,param_2);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar7;
        if (param_3 == 0) {
loc_F003F340:
          _brelse(puVar6);
        }
        else {
          uVar4 = *(uint *)(param_2 + 8);
          if (*(uint *)(uVar11 + 0x98) < uVar4) {
            *(uint *)(uVar11 + 0x98) = uVar4;
            if (*(uint *)(*param_1 + 0x14) < uVar4) {
              *(uint *)(*param_1 + 0x14) = uVar4;
            }
            wVar2 = *(word *)(param_1 + 1);
          }
          else {
            wVar2 = *(word *)(param_1 + 1);
          }
          if ((wVar2 & 0x40) != 0) {
            puVar12 = param_1;
            _nfswrite(param_1,puVar6[8] + iVar9,*(int *)(param_2 + 8) - (int)puVar10,puVar10,param_5
                     );
            goto loc_F003F340;
          }
          *(word *)(uVar11 + 0x60) = *(word *)(uVar11 + 0x60) | 0x10;
          if ((uint *)((int)puVar10 + iVar9) == puVar1) {
            *puVar6 = *puVar6 | 0x80;
            _bawrite();
          }
          else {
            _bdwrite(puVar6);
          }
        }
        if (((*(char *)(dword_F0133DDC + 0x38) != '\0') || (*(int *)(param_2 + 0x14) < 1)) ||
           (bVar3)) goto loc_F003F3BC;
        iVar9 = *(int *)(param_2 + 8);
        puVar8 = puVar12;
      } while( true );
    }
    puVar12 = (uint *)0x16;
  }
  goto locret_F003F3D8;
loc_F003F3BC:
  if (puVar12 == (uint *)0x0) {
    puVar12 = (uint *)(int)*(char *)(dword_F0133DDC + 0x38);
  }
loc_F003F3CC:
  _runlock(uVar11);
locret_F003F3D8:
  return CONCAT44(param_2,puVar12);
}

