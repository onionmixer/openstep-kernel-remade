
/* WARNING: Removing unreachable block (ram,0xf001f090) */
/* WARNING: Removing unreachable block (ram,0xf001f018) */
/* WARNING: Removing unreachable block (ram,0xf001ef8c) */
/* WARNING: Removing unreachable block (ram,0xf001ee9c) */
/* WARNING: Removing unreachable block (ram,0xf001ee5c) */
/* WARNING: Removing unreachable block (ram,0xf001ee50) */
/* WARNING: Removing unreachable block (ram,0xf001edb8) */
/* WARNING: Removing unreachable block (ram,0xf001eda0) */
/* WARNING: Removing unreachable block (ram,0xf001ed6c) */
/* WARNING: Removing unreachable block (ram,0xf001ec54) */
/* WARNING: Removing unreachable block (ram,0xf001ed98) */
/* WARNING: Removing unreachable block (ram,0xf001eda8) */
/* WARNING: Removing unreachable block (ram,0xf001eddc) */
/* WARNING: Removing unreachable block (ram,0xf001ee08) */
/* WARNING: Removing unreachable block (ram,0xf001ee7c) */
/* WARNING: Removing unreachable block (ram,0xf001eee0) */
/* WARNING: Removing unreachable block (ram,0xf001efdc) */
/* WARNING: Removing unreachable block (ram,0xf001f078) */
/* WARNING: Removing unreachable block (ram,0xf001f0b0) */
/* WARNING: Removing unreachable block (ram,0xf001ec28) */

undefined8 _sosend(uint param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  uint uVar4;
  word wVar6;
  undefined4 *puVar5;
  undefined4 uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar9;
  int iVar10;
  undefined4 unaff_l3;
  uint uVar11;
  undefined4 unaff_l4;
  undefined4 *puVar12;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar13;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  iVar9 = 0;
  uVar11 = 0;
  bVar1 = true;
  if (((*(word *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0) &&
     ((int)(uint)*(word *)(param_1 + 0x3e) < *(int *)(param_3 + 0x14))) {
    uVar11 = 0x28;
    uVar13 = param_2;
locret_F001F0BC:
    return CONCAT44(uVar13,uVar11);
  }
  uVar13 = 0;
  if (((param_4 & 4) != 0) && ((*(word *)(param_1 + 2) & 0x10) == 0)) {
    uVar13 = *(word *)(*(int *)(param_1 + 0xc) + 10) & 1;
  }
  _active_u[0x68] = _active_u[0x68] + 1;
  if (param_5 != 0) {
    iVar9 = (int)*(sword *)(param_5 + 8);
  }
  do {
    wVar6 = *(word *)(param_1 + 0x50);
loc_F001EC34:
    if ((wVar6 & 1) == 0) {
      *(word *)(param_1 + 0x50) = *(word *)(param_1 + 0x50) | 1;
      puVar3 = DAT_f0134800;
      do {
        _splnet();
        wVar6 = *(word *)(param_1 + 6);
        if ((wVar6 & 0x10) != 0) {
          uVar4 = 0x20;
          goto loc_F001ED6C;
        }
        uVar4 = (uint)*(word *)(param_1 + 0x56);
        if (uVar4 != 0) {
          *(undefined2 *)(param_1 + 0x56) = 0;
          goto loc_F001ED6C;
        }
        if ((wVar6 & 2) == 0) {
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0) {
            uVar4 = 0x39;
            goto loc_F001ED6C;
          }
          if (param_2 == 0) {
            uVar4 = 0x27;
            goto loc_F001ED6C;
          }
        }
        iVar10 = 0x400;
        if ((param_4 & 1) == 0) {
          iVar10 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
          iVar8 = (uint)*(word *)(param_1 + 0x42) - (uint)*(word *)(param_1 + 0x40);
          if (iVar8 < iVar10) {
            iVar10 = iVar8;
          }
          if (iVar10 <= iVar9) {
            wVar6 = *(word *)(param_1 + 6);
            goto loc_F001ED28;
          }
          iVar8 = *(int *)(param_3 + 0x14);
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0) {
            if (iVar10 < iVar8 + iVar9) {
              wVar6 = *(word *)(param_1 + 6);
              goto loc_F001ED28;
            }
            iVar8 = *(int *)(param_3 + 0x14);
          }
          if ((((0x3ff < iVar8) && (iVar10 < 0x400)) && (0x3ff < *(word *)(param_1 + 0x3c))) &&
             ((wVar6 & 0x100) == 0)) goto loc_f001ed24;
        }
        _splx(puVar3);
        iVar10 = iVar10 - iVar9;
        if (0 < iVar10) {
          puVar3 = DAT_f0134800;
          puVar12 = (undefined4 *)((int)register0x00000038 + -0xc);
          do {
            _spltty();
            puVar5 = _mfree;
            if (_mfree == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x1;
              _m_more(1,1);
            }
            else {
              if (*(sword *)((int)_mfree + 10) != 0) {
                _panic(&aMget_5);
              }
              *(undefined2 *)((int)puVar5 + 10) = 1;
              word_F0134B0C = word_F0134B0C + -1;
              DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
              _mfree = (undefined4 *)*puVar5;
              puVar5[1] = 0xc;
              *puVar5 = 0;
            }
            _splx(puVar3);
            iVar9 = *(int *)(param_3 + 0x14);
            if ((iVar9 < 0x200) || (iVar10 < 0x400)) {
loc_F001EF40:
              iVar8 = iVar10;
              if (iVar9 < 0x71) {
                if (iVar9 < iVar10) {
                  iVar9 = *(int *)(param_3 + 0x14);
loc_F001EF68:
                  iVar8 = 0x70;
                  if (iVar9 < 0x71) {
                    iVar8 = iVar9;
                  }
                }
              }
              else if (0x70 < iVar10) {
                iVar9 = *(int *)(param_3 + 0x14);
                goto loc_F001EF68;
              }
              iVar10 = iVar10 - iVar8;
            }
            else {
              _spltty();
              if (_mclfree == (int *)0x0) {
                _m_clalloc(1,1,0);
              }
              piVar2 = _mclfree;
              if (_mclfree != (int *)0x0) {
                iVar8 = (int)_mclfree - _mbutl >> 10;
                _mclrefcnt[iVar8] = _mclrefcnt[iVar8] + '\x01';
                DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
                _mclfree = (int *)*_mclfree;
              }
              _splx(iVar9);
              if (piVar2 == (int *)0x0) {
                *(undefined2 *)(puVar5 + 2) = 0x70;
              }
              else {
                puVar5[1] = (int)piVar2 - (int)puVar5;
                *(undefined2 *)(puVar5 + 2) = 0x400;
                *(undefined2 *)(puVar5 + 3) = 1;
              }
              iVar9 = *(int *)(param_3 + 0x14);
              if (*(sword *)(puVar5 + 2) != 0x400) goto loc_F001EF40;
              iVar8 = 0x400;
              if (iVar9 < 0x401) {
                iVar8 = iVar9;
              }
              iVar10 = iVar10 + -0x400;
            }
            uVar11 = (int)puVar5 + puVar5[1];
            _uiomove(uVar11,iVar8,1,param_3);
            *(sword *)(puVar5 + 2) = (sword)iVar8;
            *puVar12 = puVar5;
            if (uVar11 != 0) goto loc_F001F05C;
            puVar3 = *(undefined **)(param_3 + 0x14);
          } while ((0 < (int)puVar3) && (puVar12 = puVar5, 0 < iVar10));
        }
        if (uVar13 != 0) {
          puVar3 = (undefined *)(*(word *)(param_1 + 2) | 0x10);
          *(sword *)(param_1 + 2) = (sword)puVar3;
        }
        _splnet();
        uVar7 = 9;
        if ((param_4 & 1) != 0) {
          uVar7 = 0xe;
        }
        uVar11 = param_1;
        (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))
                  (param_1,uVar7,*(undefined4 *)((int)register0x00000038 + -0xc),param_2,param_5);
        _splx(puVar3);
        param_5 = 0;
        if (uVar13 != 0) {
          *(word *)(param_1 + 2) = *(word *)(param_1 + 2) & 0xffef;
        }
        iVar9 = 0;
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        bVar1 = false;
        if ((uVar11 != 0) || (puVar3 = *(undefined **)(param_3 + 0x14), puVar3 == (undefined *)0x0))
        {
loc_F001F05C:
          wVar6 = *(word *)(param_1 + 0x50);
          goto loc_F001F060;
        }
      } while( true );
    }
    *(word *)(param_1 + 0x50) = wVar6 | 2;
    _sleep(param_1 + 0x50,0x1a);
  } while( true );
loc_f001ed24:
  wVar6 = *(word *)(param_1 + 6);
loc_F001ED28:
  if ((wVar6 & 0x100) != 0) {
    uVar4 = uVar11;
    if (((bVar1) && (uVar4 = 0x23, (*(uint *)(*_active_u + 0x14) & 0x4000) != 0)) &&
       ((*(word *)(param_3 + 0x10) & 0x2000) != 0)) {
      uVar4 = 0xb;
    }
loc_F001ED6C:
    _splx(puVar3);
    wVar6 = *(word *)(param_1 + 0x50);
    uVar11 = uVar4;
loc_F001F060:
    *(word *)(param_1 + 0x50) = wVar6 & 0xfffe;
    if ((wVar6 & 2) != 0) {
      *(word *)(param_1 + 0x50) = wVar6 & 0xfffc;
      _wakeup(param_1 + 0x50);
    }
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      _m_freem();
    }
    if (uVar11 == 0x20) {
      _exception_from_kernel(5,0x10001,0);
    }
    goto locret_F001F0BC;
  }
  wVar6 = *(word *)(param_1 + 0x50);
  *(word *)(param_1 + 0x50) = wVar6 & 0xfffe;
  if ((wVar6 & 2) != 0) {
    *(word *)(param_1 + 0x50) = wVar6 & 0xfffc;
    _wakeup(param_1 + 0x50);
  }
  _sbwait(param_1 + 0x3c);
  _splx(puVar3);
  wVar6 = *(word *)(param_1 + 0x50);
  goto loc_F001EC34;
}

