
/* WARNING: Removing unreachable block (ram,0xf00b9a00) */
/* WARNING: Removing unreachable block (ram,0xf00b9950) */
/* WARNING: Removing unreachable block (ram,0xf00b98b8) */
/* WARNING: Removing unreachable block (ram,0xf00b9938) */
/* WARNING: Removing unreachable block (ram,0xf00b9854) */
/* WARNING: Removing unreachable block (ram,0xf00b97d0) */
/* WARNING: Removing unreachable block (ram,0xf00b97c8) */
/* WARNING: Removing unreachable block (ram,0xf00b97fc) */
/* WARNING: Removing unreachable block (ram,0xf00b990c) */
/* WARNING: Removing unreachable block (ram,0xf00b9880) */
/* WARNING: Removing unreachable block (ram,0xf00b98d8) */
/* WARNING: Removing unreachable block (ram,0xf00b9994) */
/* WARNING: Removing unreachable block (ram,0xf00b99f0) */
/* WARNING: Removing unreachable block (ram,0xf00b97b0) */

undefined8 _zsopen(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined uVar6;
  undefined *puVar5;
  sword sVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  puVar9 = _zs_tty + iVar1;
  if (*(int *)(_zs_tty + iVar1 + 0x34) == 0) {
    iVar10 = 6;
  }
  else {
    _zs_tty[iVar1 + 0x47] = 2;
    *(code **)(_zs_tty + iVar1 + 0x24) = _zsstart;
    iVar8 = *(int *)(_zs_tty + iVar1 + 0x34);
    iVar2 = (*(word *)(_zs_tty + iVar1 + 0x38) & 0x1f) * 0x11c;
    iVar10 = iVar2;
    _splzs();
    *(undefined **)(iVar8 + 0x18) = _zsaline + iVar2;
    _zsopinit(iVar8,_zsops_async);
    _splx(iVar10);
    if (dword_F011FB08 != 0) {
      dword_F011FB08 = 0;
      _timeout(_zspoll,0,_zsticks);
    }
    sVar7 = (sword)param_1;
    if ((sVar7 != _kbddev) || (iVar10 = 0, _kbddevopen == 0)) {
      uVar3 = 0x14;
      if (sVar7 == _kbddev) {
        *(undefined2 *)(_zsaline + iVar2 + 4) = 0x14;
      }
      _spltty();
      uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
      do {
        *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 2;
        if ((uVar4 & 4) == 0) {
          *(undefined2 *)(_zsaline + iVar2 + 0x110) = 0;
          *(undefined2 *)(_zsaline + iVar2 + 0x112) = 0;
          *(undefined2 *)(_zsaline + iVar2 + 8) = 0;
          _ttychars(puVar9);
          iVar10 = (int)sVar7;
          if ((iVar10 == _rconsdev) || (iVar10 == _kbddev)) {
            _zsgetspeed();
            uVar6 = (undefined)iVar10;
            _zs_tty[iVar1 + 0x49] = uVar6;
          }
          else {
            uVar6 = 0xd;
            _zs_tty[iVar1 + 0x49] = 0xd;
          }
          _zs_tty[iVar1 + 0x4a] = uVar6;
          *(undefined4 *)(_zs_tty + iVar1 + 0x3c) = 0xd8;
          _zsparam(puVar9);
        }
        else {
          if (((uVar4 & 0x80) != 0) && (*(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) {
            _splx(uVar3);
            iVar10 = 0x10;
            break;
          }
          if (((param_1 & 0x80) != 0) && ((*(uint *)(_zs_tty + iVar1 + 0x40) & 0x40000000) == 0)) {
            _splx(uVar3);
            iVar10 = 6;
            break;
          }
        }
        _zsmctl(puVar9,0x82,0);
        if ((param_1 & 0x80) != 0) {
          *(uint *)(_zs_tty + iVar1 + 0x40) = *(uint *)(_zs_tty + iVar1 + 0x40) | 0x40000010;
        }
        if (*(char *)((int)&_zssoftCAR + (param_1 & 0x1f)) == '\0') {
          puVar5 = puVar9;
          _zsmctl(puVar9,0,3);
          if (((uint)puVar5 & 8) != 0) {
            uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
            goto loc_F00B99AC;
          }
        }
        else {
          uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
loc_F00B99AC:
          *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 0x10;
        }
        if (((param_2 & 4) != 0) ||
           ((uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40), (uVar4 & 0x10) != 0 &&
            (((uVar4 & 0x40000000) == 0 || ((param_1 & 0x80) != 0)))))) goto loc_F00B9A00;
        *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 2;
        _sleep(iVar1 + -0xfec1160,0x1c);
        uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
      } while( true );
    }
  }
locret_F00B9A38:
  return CONCAT44(param_2,iVar10);
loc_F00B9A00:
  _splx(uVar3);
  iVar10 = (int)sVar7;
  (**(code **)(_linesw + (char)_zs_tty[iVar1 + 0x47] * 0x30))(iVar10,puVar9);
  goto locret_F00B9A38;
}

