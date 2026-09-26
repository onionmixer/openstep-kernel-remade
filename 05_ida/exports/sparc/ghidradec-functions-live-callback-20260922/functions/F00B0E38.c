
/* WARNING: Removing unreachable block (ram,0xf00b0f98) */
/* WARNING: Removing unreachable block (ram,0xf00b0f48) */
/* WARNING: Removing unreachable block (ram,0xf00b0efc) */
/* WARNING: Removing unreachable block (ram,0xf00b0e98) */
/* WARNING: Removing unreachable block (ram,0xf00b0e84) */
/* WARNING: Removing unreachable block (ram,0xf00b0ee4) */
/* WARNING: Removing unreachable block (ram,0xf00b0f74) */
/* WARNING: Removing unreachable block (ram,0xf00b0f58) */
/* WARNING: Removing unreachable block (ram,0xf00b0fb4) */
/* WARNING: Removing unreachable block (ram,0xf00b0e54) */

undefined8 _report_dev(int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined3 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
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
  iVar7 = *(int *)(param_1 + 0x10);
  iVar8 = *(int *)(param_1 + 0x18);
  iVar6 = 0;
  _printf(&aSD_0,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x2c));
  if (0 < iVar7) {
    iVar4 = 0;
    do {
      puVar1 = &aAnd;
      if (iVar6 == 0) {
        puVar1 = (undefined5 *)&aAt;
      }
      iVar6 = iVar6 + 1;
      _printf(puVar1);
      _decode_address(*(undefined4 *)(*(int *)(param_1 + 0x14) + iVar4),
                      *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar4 + 4));
      iVar4 = iVar4 + 0xc;
    } while (iVar6 < iVar7);
  }
  iVar6 = 0;
  if (0 < iVar8) {
    iVar7 = 0;
    do {
      if (iVar6 == 0) {
        puVar2 = (undefined3 *)&asc_F011C5B8;
      }
      else {
        puVar2 = &DAT_f011c5c0;
      }
      _printf(puVar2);
      _printf(&aPriD,*(uint *)(*(int *)(param_1 + 0x1c) + iVar7) & 0xf);
      uVar3 = *(uint *)(*(int *)(param_1 + 0x1c) + iVar7);
      uVar5 = uVar3 & 0xfffffff0;
      if (uVar5 == 0x20) {
        _printf(aOnboard);
        iVar4 = *(int *)(param_1 + 0x1c);
      }
      else if ((int)uVar5 < 0x21) {
        if (uVar5 == 0x10) {
          _printf(&aSoft);
          iVar4 = *(int *)(param_1 + 0x1c);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x1c);
        }
      }
      else if (uVar5 == 0x30) {
        _printf(aSbusLevelD,*(undefined4 *)(_svimap + (uVar3 & 0xf) * 4));
        iVar4 = *(int *)(param_1 + 0x1c);
      }
      else {
        iVar4 = *(int *)(param_1 + 0x1c);
      }
      if (*(int *)(iVar4 + iVar7 + 4) != 0) {
        _printf(aVec0xX);
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 8;
    } while (iVar6 < iVar8);
  }
  _printf(&DAT_f011c610);
  return CONCAT44(param_2,param_1);
}

