
undefined8 _vswap_allocate(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar6;
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
  puVar4 = (undefined4 *)0x0;
  iVar6 = 0;
  if (dword_F0130F6C < 2) {
    if (dword_F0130F6C == 1) {
      puVar4 = dword_F0130F64;
    }
  }
  else {
    uVar5 = 0;
    do {
      if ((undefined4 **)dword_F0130F64 != &dword_F0130F64) {
        puVar2 = dword_F0130F64;
        do {
          param_2 = puVar2[2];
          if (((int)uVar5 < 2) && (puVar2[0xb] == 0)) {
            puVar3 = (undefined4 *)*puVar2;
          }
          else {
            if ((uVar5 & 1) == 0) {
              if (*(undefined **)(param_2 + 0x1c) != _ufs_vnodeops) {
                puVar3 = (undefined4 *)*puVar2;
                goto loc_F008BD60;
              }
              iVar1 = puVar2[6];
            }
            else {
              iVar1 = puVar2[6];
            }
            if (iVar6 < iVar1) {
              puVar3 = (undefined4 *)*puVar2;
              puVar4 = puVar2;
              iVar6 = iVar1;
            }
            else {
              puVar3 = (undefined4 *)*puVar2;
            }
          }
loc_F008BD60:
          puVar2 = puVar3;
        } while ((undefined4 **)puVar3 != &dword_F0130F64);
      }
      uVar5 = uVar5 + 1;
    } while ((puVar4 == (undefined4 *)0x0) && ((int)uVar5 < 4));
  }
  return CONCAT44(param_2,puVar4);
}

