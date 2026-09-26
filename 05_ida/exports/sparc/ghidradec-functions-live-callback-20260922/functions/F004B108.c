
/* WARNING: Removing unreachable block (ram,0xf004b500) */
/* WARNING: Removing unreachable block (ram,0xf004b468) */
/* WARNING: Removing unreachable block (ram,0xf004b3c8) */
/* WARNING: Removing unreachable block (ram,0xf004b41c) */
/* WARNING: Removing unreachable block (ram,0xf004b35c) */
/* WARNING: Removing unreachable block (ram,0xf004b2b8) */
/* WARNING: Removing unreachable block (ram,0xf004b248) */
/* WARNING: Removing unreachable block (ram,0xf004b160) */
/* WARNING: Removing unreachable block (ram,0xf004b144) */
/* WARNING: Removing unreachable block (ram,0xf004b1e0) */
/* WARNING: Removing unreachable block (ram,0xf004b2a8) */
/* WARNING: Removing unreachable block (ram,0xf004b300) */
/* WARNING: Removing unreachable block (ram,0xf004b378) */
/* WARNING: Removing unreachable block (ram,0xf004b444) */
/* WARNING: Removing unreachable block (ram,0xf004b3d8) */
/* WARNING: Removing unreachable block (ram,0xf004b4ec) */
/* WARNING: Removing unreachable block (ram,0xf004b1a8) */
/* WARNING: Removing unreachable block (ram,0xf004b114) */

undefined8 _dirlook(int param_1,char *param_2,int *param_3)

{
  word wVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  int iVar8;
  int iVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  int iVar11;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar8 = 0;
  uVar7 = 0;
  pcVar2 = param_2;
  _strlen();
  if ((*(word *)(param_1 + 100) & 0xf000) != 0x4000) {
    iVar12 = 0x14;
    goto locret_F004B50C;
  }
  iVar12 = param_1;
  _iaccess(param_1,0x40);
  if (iVar12 != 0) goto locret_F004B50C;
  iVar12 = param_1 + 0xc;
  _dnlc_lookup(iVar12,param_2,0);
  if (iVar12 != 0) {
    iVar11 = *(int *)(iVar12 + 0x30);
    *(sword *)(iVar12 + 6) = *(sword *)(iVar12 + 6) + 1;
    *param_3 = iVar11;
    iVar8 = *param_3;
    wVar1 = *(word *)(iVar11 + 0x44);
    while ((wVar1 & 1) != 0) {
      *(word *)(iVar8 + 0x44) = *(word *)(iVar8 + 0x44) | 0x10;
      _sleep(*param_3,10);
      iVar8 = *param_3;
      wVar1 = *(word *)(*param_3 + 0x44);
    }
    iVar12 = 0;
    *(word *)(iVar8 + 0x44) = *(word *)(iVar8 + 0x44) | 1;
    goto locret_F004B50C;
  }
  wVar1 = *(word *)(param_1 + 0x44);
  while ((wVar1 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 | 0x10;
    _sleep(param_1,10);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  if (*(uint *)(param_1 + 0x70) < *(uint *)(param_1 + 0x4c)) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  uVar5 = *(uint *)(param_1 + 0x4c);
  if (uVar5 == 0) {
    uVar5 = 0;
    iVar11 = 1;
loc_F004B260:
    uVar10 = *(int *)(param_1 + 0x70) + 0x3ffU & 0xfffffc00;
joined_r0xf004b270:
    for (; uVar5 < uVar10; uVar5 = uVar5 + uVar3) {
      if ((uVar5 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48)) == 0) {
        if (iVar8 != 0) {
          _brelse(iVar8);
        }
        iVar8 = param_1;
        _blkatoff(param_1,uVar5,0);
        uVar7 = 0;
        if (iVar8 == 0) goto loc_F004B4A8;
        iVar12 = *(int *)(iVar8 + 0x20);
      }
      else {
        iVar12 = *(int *)(iVar8 + 0x20);
      }
      piVar6 = (int *)(iVar12 + uVar7);
      if ((*(sword *)(piVar6 + 1) == 0) ||
         ((_dirchk != 0 && (iVar12 = param_1, sub_F004CCF8(param_1,piVar6,uVar7,uVar5), iVar12 != 0)
          ))) {
        uVar3 = 0x400 - (uVar7 & 0x3ff);
      }
      else if (*piVar6 == 0) {
        uVar3 = (uint)*(word *)(piVar6 + 1);
      }
      else if ((char *)(uint)*(word *)((int)piVar6 + 6) == pcVar2) {
        if (*param_2 == *(char *)(piVar6 + 2)) {
          pcVar4 = param_2;
          _bcmp(param_2,piVar6 + 2,pcVar2);
          if (pcVar4 == (char *)0x0) {
            iVar12 = *piVar6;
            iVar9 = 0;
            _brelse(iVar8);
            *(uint *)(param_1 + 0x4c) = uVar5;
            if (pcVar2 == (char *)0x2) {
              if (*param_2 != '.') {
                iVar8 = *(int *)(param_1 + 0x48);
                goto loc_F004B3F8;
              }
              if (param_2[1] != '.') {
                iVar8 = *(int *)(param_1 + 0x48);
                goto loc_F004B3F8;
              }
              wVar1 = *(word *)(param_1 + 0x44);
              *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
              if ((wVar1 & 0x10) != 0) {
                *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
                _wakeup(param_1);
              }
              iVar8 = (int)*(sword *)(param_1 + 0x46);
              _iget(iVar8,*(undefined4 *)(param_1 + 0x50),iVar12);
              if (iVar8 == 0) goto loc_F004B4B4;
              *param_3 = iVar8;
            }
            else {
              iVar8 = *(int *)(param_1 + 0x48);
loc_F004B3F8:
              if (iVar8 == iVar12) {
                *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
                iVar8 = param_1;
              }
              else {
                iVar8 = (int)*(sword *)(param_1 + 0x46);
                _iget(iVar8,*(undefined4 *)(param_1 + 0x50),iVar12);
                wVar1 = *(word *)(param_1 + 0x44);
                *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
                if ((wVar1 & 0x10) != 0) {
                  *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
                  _wakeup(param_1);
                }
                if (iVar8 == 0) {
loc_F004B4B4:
                  iVar12 = (int)*(char *)(dword_F0133DDC + 0x38);
                  goto loc_F004B4F4;
                }
              }
              *param_3 = iVar8;
            }
            _dnlc_enter(param_1 + 0xc,param_2,iVar8 + 0xc,0);
            iVar12 = 0;
            goto locret_F004B50C;
          }
          uVar3 = (uint)*(word *)(piVar6 + 1);
        }
        else {
          uVar3 = (uint)*(word *)(piVar6 + 1);
        }
      }
      else {
        uVar3 = (uint)*(word *)(piVar6 + 1);
      }
      uVar7 = uVar7 + uVar3;
    }
    iVar12 = 2;
    iVar9 = iVar8;
    if (iVar11 == 2) {
      iVar11 = 1;
      uVar10 = *(uint *)(param_1 + 0x4c);
      uVar5 = 0;
      goto joined_r0xf004b270;
    }
  }
  else {
    uVar7 = uVar5 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48);
    if ((uVar7 == 0) || (iVar8 = param_1, _blkatoff(param_1,uVar5,0), iVar8 != 0)) {
      iVar11 = 2;
      goto loc_F004B260;
    }
loc_F004B4A8:
    iVar12 = (int)*(char *)(dword_F0133DDC + 0x38);
    iVar9 = iVar8;
  }
  wVar1 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
loc_F004B4F4:
  if (iVar9 != 0) {
    _brelse(iVar9);
  }
locret_F004B50C:
  return CONCAT44(param_2,iVar12);
}

