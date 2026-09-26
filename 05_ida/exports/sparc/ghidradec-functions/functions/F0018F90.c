
/* WARNING: Removing unreachable block (ram,0xf00193b0) */
/* WARNING: Removing unreachable block (ram,0xf00191ac) */
/* WARNING: Removing unreachable block (ram,0xf001911c) */
/* WARNING: Removing unreachable block (ram,0xf001909c) */
/* WARNING: Removing unreachable block (ram,0xf0018fdc) */
/* WARNING: Removing unreachable block (ram,0xf0019084) */
/* WARNING: Removing unreachable block (ram,0xf00190b8) */
/* WARNING: Removing unreachable block (ram,0xf0019158) */
/* WARNING: Removing unreachable block (ram,0xf00191dc) */
/* WARNING: Removing unreachable block (ram,0xf0019404) */
/* WARNING: Removing unreachable block (ram,0xf0018f94) */

undefined8 _ttyoutput(uint param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  byte bVar5;
  undefined4 unaff_l0;
  char *pcVar6;
  uint uVar7;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  iVar9 = param_2;
  _ttynty();
  uVar8 = *(uint *)(param_2 + 0x3c);
  if (((uVar8 & 0x200020) != 0) || ((*(uint *)(iVar9 + 0x10) & 0x10000000) == 0)) {
    if ((uVar8 & 0x800000) == 0) {
      uVar8 = param_1;
      _putc(param_1,param_2 + 0x18);
      if (uVar8 == 0) {
        param_1 = 0xffffffff;
        _tk_nout = _tk_nout + 1;
      }
    }
    else {
      param_1 = 0xffffffff;
    }
    goto locret_F0019410;
  }
  if ((uVar8 & 0x2000000) == 0) {
    if ((*(uint *)(iVar9 + 0x10) & 0x300) == 0x300) {
      param_1 = param_1 & 0xff;
    }
    else {
      param_1 = param_1 & 0x7f;
    }
  }
  else {
    param_1 = param_1 & 0xff;
  }
  if ((param_1 != 4) || ((uVar8 & 2) != 0)) {
    if ((param_1 == 9) &&
       (((uVar8 & 0xc00) == 0xc00 && ((*(uint *)(param_2 + 0x40) & 0x400000) == 0)))) {
      uVar2 = *(byte *)(param_2 + 0x48) & 7;
      iVar9 = 8 - uVar2;
      if ((uVar8 & 0x800000) == 0) {
        _spltty();
        puVar3 = asc_F010B880;
        _b_to_q(asc_F010B880,iVar9,param_2 + 0x18);
        iVar9 = iVar9 - (int)puVar3;
        _tk_nout = _tk_nout + iVar9;
        _splx(uVar2);
      }
      param_1 = 9;
      *(char *)(param_2 + 0x48) = *(char *)(param_2 + 0x48) + (char)iVar9;
      if (iVar9 != 0) {
        param_1 = 0xffffffff;
      }
      goto locret_F0019410;
    }
    _tk_nout = _tk_nout + 1;
    if ((uVar8 & 4) != 0) {
      pcVar6 = asc_F010B890;
      cVar1 = asc_F010B890[0];
      while (cVar1 != '\0') {
        if (param_1 == (int)pcVar6[1]) {
          iVar4 = 0x5c;
          _ttyoutput(0x5c,param_2);
          if (-1 < iVar4) goto locret_F0019410;
          param_1 = (uint)*pcVar6;
          break;
        }
        cVar1 = pcVar6[2];
        pcVar6 = pcVar6 + 2;
      }
      iVar4 = 0x5c;
      if (param_1 - 0x41 < 0x1a) {
        _ttyoutput(0x5c,param_2);
        if (-1 < iVar4) goto locret_F0019410;
      }
      else if (param_1 - 0x61 < 0x1a) {
        param_1 = param_1 - 0x20;
      }
    }
    if ((param_1 == 10) && (((uVar8 & 0x10) != 0 || ((*(uint *)(iVar9 + 0x10) & 0x20000000) != 0))))
    {
      iVar4 = 0xd;
      _ttyoutput(0xd,param_2);
      if (-1 < iVar4) {
        param_1 = 10;
        goto locret_F0019410;
      }
    }
    if (((uVar8 & 0x800000) == 0) && (uVar2 = param_1, _putc(param_1,param_2 + 0x18), uVar2 != 0))
    goto locret_F0019410;
    uVar7 = 0;
    bVar5 = *(byte *)(param_2 + 0x48);
    uVar2 = (uint)(char)bVar5;
    switch(_partab[param_1] & 0x3f) {
    case :
      bVar5 = bVar5 + 1;
      break;
    case :
      if (0 < (int)uVar2) {
        bVar5 = bVar5 - 1;
        break;
      }
      bVar10 = true;
      goto loc_F00193D4;
    case :
      uVar8 = (int)uVar8 >> 8 & 3;
      if (uVar8 == 1) {
        if (0 < (int)uVar2) {
          uVar7 = (uVar2 >> 4) + 3;
          if (uVar7 < 7) {
            bVar5 = 0;
            break;
          }
          uVar7 = 6;
        }
      }
      else {
        if (uVar8 != 2) {
          bVar5 = 0;
          break;
        }
        uVar7 = _hz * 100 >> 10;
      }
loc_F00193CC:
      bVar5 = 0;
      break;
    case :
      if (((uVar8 & 0xc00) == 0x400) && (uVar7 = 1 - (uVar2 | 0xfffffff8), (int)uVar7 < 5)) {
        uVar7 = 0;
      }
      bVar5 = bVar5 + 8 & 0xf8;
      break;
    case :
      if ((uVar8 & 0x4000) == 0) {
        bVar10 = true;
        goto loc_F00193D4;
      }
      uVar7 = 0x7f;
      break;
    case :
      uVar8 = *(int *)(param_2 + 0x3c) >> 0xc & 3;
      if (uVar8 == 2) {
        uVar7 = _hz * 0xa6 >> 10;
        goto loc_F00193CC;
      }
      if (uVar8 < 3) {
        if (uVar8 == 1) {
          uVar7 = _hz * 0x53 >> 10;
          goto loc_F00193CC;
        }
        bVar5 = 0;
      }
      else {
        if (uVar8 == 3) {
          if (-1 < (int)uVar2) {
            if (8 < (int)uVar2) {
              uVar7 = 0;
              goto loc_F00193CC;
            }
            do {
              _putc(0x7f,param_2 + 0x18);
              uVar2 = uVar2 + 1;
            } while ((int)uVar2 < 9);
          }
          uVar7 = 0;
          goto loc_F00193CC;
        }
        bVar5 = 0;
      }
    }
    bVar10 = uVar7 == 0;
loc_F00193D4:
    *(byte *)(param_2 + 0x48) = bVar5;
    if (!bVar10) {
      param_1 = 0xffffffff;
      if (((*(uint *)(param_2 + 0x3c) & 0x2800000) != 0) ||
         ((*(uint *)(iVar9 + 0x10) & 0x300) == 0x300)) goto locret_F0019410;
      _putc(uVar7 | 0x80,param_2 + 0x18);
    }
  }
  param_1 = 0xffffffff;
locret_F0019410:
  return CONCAT44(param_2,param_1);
}
