
/* WARNING: Removing unreachable block (ram,0xf00920b8) */
/* WARNING: Removing unreachable block (ram,0xf0092074) */

undefined8 _sd_init_idmap(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 unaff_l0;
  word *pwVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  puVar9 = unk_F01123A8;
  puVar5 = _bdevsw;
  pcVar3 = (code *)_bdevsw._0_4_;
  if (_bdevsw < _bdevsw + _nblkdev * 0x18) {
    while (pcVar3 != _sdopen) {
      puVar5 = (undefined *)((int)puVar5 + 0x18);
      if (_bdevsw + _nblkdev * 0x18 <= puVar5) goto loc_F0091FD8;
      pcVar3 = *(code **)puVar5;
    }
    dword_F0131240 = (int)((int)puVar5 + 0xfee3854) * -0x55555555 >> 3;
  }
loc_F0091FD8:
  puVar5 = _cdevsw;
  pcVar3 = (code *)_cdevsw._0_4_;
  if (_cdevsw < _cdevsw + _nchrdev * 0x2c) {
    while (pcVar3 != _sdopen) {
      puVar5 = (undefined *)((int)puVar5 + 0x2c);
      if (_cdevsw + _nchrdev * 0x2c <= puVar5) goto loc_F0092070;
      pcVar3 = *(code **)puVar5;
    }
    dword_F0131244 = (int)((int)puVar5 + 0xfee3610) * -0x45d1745d >> 2;
  }
loc_F0092070:
  _bzero(unk_F0131000,0x240);
  iVar8 = 0;
  pwVar7 = (word *)(unk_F0131000 + 0x22);
  do {
    iVar2 = dword_F0131240;
    puVar4 = (undefined4 *)0x44;
    iVar6 = iVar8 << 3;
    iVar8 = iVar8 + 1;
    wVar1 = (word)iVar6;
    pwVar7[-1] = (word)(dword_F0131244 << 8) | wVar1;
    *pwVar7 = (word)(iVar2 << 8) | wVar1;
    pwVar7 = pwVar7 + 0x12;
    _IOMalloc();
    *(undefined4 **)puVar9 = puVar4;
    *puVar4 = 0;
    puVar9 = (undefined *)((int)puVar9 + 4);
  } while (iVar8 < 0x10);
  return CONCAT44(param_2,param_1);
}

