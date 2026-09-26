
/* WARNING: Removing unreachable block (ram,0xf00b9b84) */
/* WARNING: Removing unreachable block (ram,0xf00b9b74) */
/* WARNING: Removing unreachable block (ram,0xf00b9b44) */
/* WARNING: Removing unreachable block (ram,0xf00b9b2c) */
/* WARNING: Removing unreachable block (ram,0xf00b9ae8) */
/* WARNING: Removing unreachable block (ram,0xf00b9ad0) */
/* WARNING: Removing unreachable block (ram,0xf00b9af0) */
/* WARNING: Removing unreachable block (ram,0xf00b9b3c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b5c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b7c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b8c) */
/* WARNING: Removing unreachable block (ram,0xf00b9a60) */

undefined8 _zsclose(uint param_1,undefined4 param_2)

{
  sword sVar2;
  uint uVar1;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
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
  sVar2 = (sword)param_1;
  if (sVar2 != _kbddev) {
    _spltty();
    iVar3 = (param_1 & 0x1f) * 0x88;
    puVar4 = _zs_tty + iVar3;
    (**(code **)(DAT_f010b8d0 + (char)_zs_tty[iVar3 + 0x47] * 0x30))(puVar4);
    param_1 = *(uint *)(_zs_tty + iVar3 + 0x34);
    *(uint *)(_zs_tty + iVar3 + 0x40) = *(uint *)(_zs_tty + iVar3 + 0x40) & 0xbfffffff;
    if ((*(byte *)(param_1 + 0x25) & 0x10) == 0) {
      uVar1 = *(uint *)(_zs_tty + iVar3 + 0x40);
    }
    else {
      _splzs();
      *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) & 0xef;
      _zszwrite(*(undefined4 *)(param_1 + 0x10),5);
      _spltty();
      uVar1 = *(uint *)(_zs_tty + iVar3 + 0x40);
    }
    if ((((uVar1 & 0x206) != 4) && (sVar2 != _rconsdev)) && (sVar2 != _kbddev)) {
      _zsmctl(puVar4,0,0);
      _sleep(_lbolt,0x1d);
    }
    _ttyclose(puVar4);
    if ((*(uint *)(_zs_tty + iVar3 + 0x40) & 6) == 0) {
      _splzs();
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xef;
      _zszwrite(*(undefined4 *)(param_1 + 0x10),1);
      _spltty();
    }
    _wakeup(iVar3 + -0xfec1160);
    _spl0();
  }
  return CONCAT44(param_2,param_1);
}
