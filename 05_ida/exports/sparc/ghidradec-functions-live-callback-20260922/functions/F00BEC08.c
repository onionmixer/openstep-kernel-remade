
/* WARNING: Removing unreachable block (ram,0xf00becfc) */
/* WARNING: Removing unreachable block (ram,0xf00bed18) */
/* WARNING: Removing unreachable block (ram,0xf00beca0) */
/* WARNING: Removing unreachable block (ram,0xf00bece0) */
/* WARNING: Removing unreachable block (ram,0xf00bed24) */
/* WARNING: Removing unreachable block (ram,0xf00bec94) */

undefined8 sub_F00BEC08(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  puVar2[0xb] = 0x666666;
  puVar2[0xc] = 0xffffff;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0x666666;
  iVar1 = _sparcfbs;
  puVar2[0xf] = 0x999999;
  *puVar2 = *(undefined4 *)(iVar1 + 0x28);
  puVar2[1] = *(undefined4 *)(iVar1 + 0x2c);
  puVar2[0x11] = 0;
  *(undefined *)((int)puVar2 + 0x4a) = 0;
  iVar1 = (int)puVar2 + 2;
  while ((int)puVar2 <= iVar1 + -1) {
    *(undefined *)(iVar1 + 0x47) = 0;
    iVar1 = iVar1 + -1;
  }
  puVar2[0x13] = (int)puVar2 + 0x49;
  if ((param_3 != 0) && (puVar2[2] != 3)) {
    _sparcfbRestoreMode(0);
    sub_F00BE020(puVar2,puVar2[0xb]);
  }
  puVar2[2] = param_2;
  if (param_2 != 2) {
    if (param_2 < 3) {
      if (param_2 == 1) {
        _sparcfbRestoreMode(0);
        sub_F00BE970(puVar2,0x280,0x1e0,param_5,param_4,0);
        goto locret_F00BED2C;
      }
    }
    else if (param_2 == 3) {
      sub_F00BE970(puVar2,0x140,200,param_5,param_4,1);
      goto locret_F00BED2C;
    }
    _panic(DAT_f01209f8);
  }
locret_F00BED2C:
  return CONCAT44(param_2,puVar2);
}

