
/* WARNING: Removing unreachable block (ram,0xf0019c8c) */
/* WARNING: Removing unreachable block (ram,0xf0019d14) */
/* WARNING: Removing unreachable block (ram,0xf001a068) */
/* WARNING: Removing unreachable block (ram,0xf0019ff4) */
/* WARNING: Removing unreachable block (ram,0xf0019ec0) */
/* WARNING: Removing unreachable block (ram,0xf0019ea0) */
/* WARNING: Removing unreachable block (ram,0xf0019c00) */
/* WARNING: Removing unreachable block (ram,0xf0019e88) */
/* WARNING: Removing unreachable block (ram,0xf0019db8) */
/* WARNING: Removing unreachable block (ram,0xf0019d3c) */
/* WARNING: Removing unreachable block (ram,0xf0019b3c) */
/* WARNING: Removing unreachable block (ram,0xf0019b84) */
/* WARNING: Removing unreachable block (ram,0xf0019da4) */
/* WARNING: Removing unreachable block (ram,0xf0019dc4) */
/* WARNING: Removing unreachable block (ram,0xf0019f28) */
/* WARNING: Removing unreachable block (ram,0xf0019c10) */
/* WARNING: Removing unreachable block (ram,0xf0019eb4) */
/* WARNING: Removing unreachable block (ram,0xf0019fa8) */
/* WARNING: Removing unreachable block (ram,0xf001a01c) */
/* WARNING: Removing unreachable block (ram,0xf001a070) */
/* WARNING: Removing unreachable block (ram,0xf0019f98) */
/* WARNING: Removing unreachable block (ram,0xf0019c9c) */
/* WARNING: Removing unreachable block (ram,0xf0019ab0) */

undefined8 _ttwrite(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  byte *pbVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  byte *pbVar12;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  byte abStack_70 [112];
  
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
  iVar2 = param_1;
  _ttynty();
  pbVar12 = (byte *)0x0;
  bVar1 = *(byte *)(param_1 + 0x4a);
  *(int *)((int)register0x00000038 + -0x74) = param_2[5];
  iVar11 = (int)*(sword *)(_tthiwat + (bVar1 & 0x1f) * 2);
loc_F0019AE0:
  uVar7 = *(uint *)(param_1 + 0x40);
loc_F0019AE4:
  if ((uVar7 & 0x10) == 0) {
    uVar3 = *(uint *)(iVar2 + 0x10);
    while ((uVar3 & 0x8000) == 0) {
      if ((uVar7 & 0x8000) == 0) goto loc_F0019BF8;
      if ((uVar7 & 0x2000) != 0) {
        uVar7 = *(uint *)(*_active_u + 0x14);
        goto loc_F001A054;
      }
      _sleep(param_1,0x1c);
      uVar7 = *(uint *)(param_1 + 0x40);
      if ((uVar7 & 0x10) != 0) break;
      uVar3 = *(uint *)(iVar2 + 0x10);
    }
  }
  iVar9 = *_active_u;
  if ((*(uint *)(iVar9 + 0x14) & 0x4000) == 0) {
    iVar8 = (int)*(sword *)(iVar9 + 0x2e);
    if (iVar8 == *(sword *)(param_1 + 0x44)) {
      iVar9 = param_2[5];
    }
    else if (param_1 == _active_u[0x59]) {
      if ((*(uint *)(param_1 + 0x3c) & 0x400000) == 0) goto loc_F0019CAC;
      if ((*(uint *)(iVar9 + 0x28) & 0x1000) == 0) {
        if ((*(uint *)(iVar9 + 0x20) & 0x200000) == 0) {
          if ((*(uint *)(iVar9 + 0x1c) & 0x200000) == 0) goto loc_F0019C8C;
          iVar9 = param_2[5];
        }
        else {
          iVar9 = param_2[5];
        }
      }
      else {
        iVar9 = param_2[5];
      }
    }
    else {
      iVar9 = param_2[5];
    }
  }
  else {
    iVar4 = (int)*(sword *)(iVar9 + 0x30);
    _get_posix_proc();
    iVar8 = *(int *)(*(int *)(iVar4 + 0x10) + 0xc);
    if (iVar8 == *(sword *)(param_1 + 0x44)) {
loc_F0019CAC:
      iVar9 = param_2[5];
    }
    else if (param_1 == _active_u[0x59]) {
      if ((*(uint *)(param_1 + 0x3c) & 0x400000) == 0) goto loc_F0019CAC;
      if ((*(uint *)(iVar9 + 0x20) & 0x200000) == 0) {
        if ((*(uint *)(iVar9 + 0x1c) & 0x200000) == 0) {
          if (*(int *)(*(int *)(iVar4 + 0x10) + 0x10) == 0) {
loc_F0019BF8:
            pbVar12 = (byte *)0x5;
            goto locret_F001A080;
          }
loc_F0019C8C:
          _gsignal(iVar8,0x16);
          _sleep(_lbolt,0x1c);
          uVar7 = *(uint *)(param_1 + 0x40);
          goto loc_F0019AE4;
        }
        iVar9 = param_2[5];
      }
      else {
        iVar9 = param_2[5];
      }
    }
    else {
      iVar9 = param_2[5];
    }
  }
  if (0 < iVar9) {
    iVar9 = *param_2;
    do {
      iVar9 = *(int *)(iVar9 + 4);
      if (iVar9 == 0) {
        param_2[1] = param_2[1] + -1;
        *param_2 = *param_2 + 8;
        if (param_2[1] < 1) {
          _panic(&aTtwrite);
          iVar9 = param_2[5];
        }
        else {
loc_F0019F88:
          iVar9 = param_2[5];
        }
      }
      else {
        if (100 < iVar9) {
          iVar9 = 100;
        }
        pbVar10 = (byte *)((int)register0x00000038 + -0x70);
        pbVar12 = pbVar10;
        _uiomove(pbVar10,iVar9,1,param_2);
        if (pbVar12 != (byte *)0x0) break;
        uVar7 = *(uint *)(param_1 + 0x18);
        if (iVar11 < (int)uVar7) goto loc_F0019FA8;
        if ((*(uint *)(param_1 + 0x3c) & 0x800000) == 0) {
          if ((*(uint *)(param_1 + 0x3c) & 0x200024) == 4) {
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0) {
              if (iVar9 < 1) {
                iVar9 = param_2[5];
              }
              else {
                bVar1 = *pbVar10;
                while( true ) {
                  iVar8 = (int)(char)bVar1;
                  pbVar10 = pbVar10 + 1;
                  *(undefined *)(param_1 + 0x4b) = 0;
                  _ttyoutput(iVar8,param_1);
                  if (-1 < iVar8) {
                    _ttstart(param_1);
                    _sleep(_lbolt,0x1d);
                    *(undefined *)(param_1 + 0x4b) = 0;
                    goto loc_F0019EC8;
                  }
                  uVar7 = *(uint *)(param_1 + 0x18);
                  iVar9 = iVar9 + -1;
                  if (iVar11 < (int)uVar7) goto loc_F0019FA8;
                  if (iVar9 < 1) break;
                  bVar1 = *pbVar10;
                }
                iVar9 = param_2[5];
              }
              goto loc_F0019F8C;
            }
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          bVar14 = iVar9 == 0;
          bVar13 = iVar9 < 0;
          if ((uVar7 & 0x2200020) == 0) {
            bVar14 = iVar9 == 0;
            bVar13 = iVar9 < 0;
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0) {
              bVar14 = iVar9 == 0;
              bVar13 = iVar9 < 0;
              if ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300) {
                iVar8 = iVar9 + -1;
                pbVar6 = pbVar10;
                if (iVar8 < 0) goto loc_F0019F7C;
                do {
                  iVar8 = iVar8 + -1;
                  *pbVar6 = *pbVar6 & 0x7f;
                  pbVar6 = pbVar6 + 1;
                } while (-1 < iVar8);
                bVar14 = iVar9 == 0;
                bVar13 = iVar9 < 0;
              }
            }
          }
loc_F0019F80:
          if (bVar14 || bVar13) goto loc_F0019F88;
          iVar8 = iVar9;
          if ((*(uint *)(param_1 + 0x3c) & 0x200020) == 0) {
            if ((*(uint *)(iVar2 + 0x10) & 0x10000000) == 0) {
              *(undefined *)(param_1 + 0x4b) = 0;
              goto loc_F0019F20;
            }
            iVar4 = iVar9;
            _scanc(iVar9,pbVar10,_partab,0x3f);
            *(undefined *)(param_1 + 0x4b) = 0;
            iVar8 = iVar9 - iVar4;
            if (iVar9 - iVar4 != 0) goto loc_F0019F20;
            iVar8 = (int)(char)*pbVar10;
            _ttyoutput(iVar8,param_1);
            if (-1 < iVar8) {
              _ttstart(param_1);
              _sleep(_lbolt,0x1d);
loc_F0019EC8:
              if (iVar9 == 0) {
                uVar7 = *(uint *)(param_1 + 0x40);
                goto loc_F0019AE4;
              }
              piVar5 = (int *)*param_2;
loc_F0019ED8:
              *piVar5 = *piVar5 - iVar9;
              *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar9;
              param_2[5] = param_2[5] + iVar9;
              param_2[2] = param_2[2] - iVar9;
              goto loc_F0019AE0;
            }
            pbVar10 = pbVar10 + 1;
            uVar7 = *(uint *)(param_1 + 0x3c);
            iVar9 = iVar9 + -1;
          }
          else {
            *(undefined *)(param_1 + 0x4b) = 0;
loc_F0019F20:
            pbVar6 = pbVar10;
            _b_to_q(pbVar10,iVar8,param_1 + 0x18);
            iVar8 = iVar8 - (int)pbVar6;
            pbVar10 = pbVar10 + iVar8;
            iVar9 = iVar9 - iVar8;
            *(char *)(param_1 + 0x48) = *(char *)(param_1 + 0x48) + (char)iVar8;
            _tk_nout = _tk_nout + iVar8;
            if (0 < (int)pbVar6) {
              _ttstart(param_1);
              _sleep(_lbolt,0x1d);
              piVar5 = (int *)*param_2;
              goto loc_F0019ED8;
            }
            uVar7 = *(uint *)(param_1 + 0x3c);
          }
          if (((uVar7 & 0x800000) != 0) || (uVar7 = *(uint *)(param_1 + 0x18), iVar11 < (int)uVar7))
          goto loc_F0019FA8;
loc_F0019F7C:
          bVar14 = iVar9 == 0;
          bVar13 = iVar9 < 0;
          goto loc_F0019F80;
        }
        iVar9 = param_2[5];
      }
loc_F0019F8C:
      if (iVar9 < 1) break;
      iVar9 = *param_2;
    } while( true );
  }
  _ttstart(param_1);
  goto locret_F001A080;
loc_F0019FA8:
  _spltty();
  if (iVar9 != 0) {
    *(int *)*param_2 = *(int *)*param_2 - iVar9;
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar9;
    param_2[5] = param_2[5] + iVar9;
    param_2[2] = param_2[2] - iVar9;
  }
  _ttstart(param_1);
  if (iVar11 < *(int *)(param_1 + 0x18)) {
    if ((*(uint *)(param_1 + 0x40) & 0x2000) != 0) {
      _splx(uVar7);
      pbVar12 = (byte *)0x0;
      if (param_2[5] == *(int *)((int)register0x00000038 + -0x74)) {
        uVar7 = *(uint *)(*_active_u + 0x14);
loc_F001A054:
        pbVar12 = (byte *)0x23;
        if ((uVar7 & 0x4000) != 0) {
          pbVar12 = (byte *)0xb;
        }
      }
locret_F001A080:
      return CONCAT44(param_2,pbVar12);
    }
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
  }
  _splx(uVar7);
  uVar7 = *(uint *)(param_1 + 0x40);
  goto loc_F0019AE4;
}
