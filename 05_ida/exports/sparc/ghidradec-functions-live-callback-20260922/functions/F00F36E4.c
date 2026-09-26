
/* WARNING: Removing unreachable block (ram,0xf00f3860) */
/* WARNING: Removing unreachable block (ram,0xf00f3840) */
/* WARNING: Removing unreachable block (ram,0xf00f37ec) */
/* WARNING: Removing unreachable block (ram,0xf00f3854) */
/* WARNING: Removing unreachable block (ram,0xf00f3894) */
/* WARNING: Removing unreachable block (ram,0xf00f37ac) */

undefined8 __sel_registerName(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 unaff_l1;
  undefined (*pauVar9) [28];
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
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)0x0;
locret_F00F38E8:
    return CONCAT44(param_2,param_1);
  }
  uVar5 = 0;
  pbVar4 = param_1;
  while( true ) {
    if (*pbVar4 == 0) break;
    uVar5 = uVar5 ^ *pbVar4;
    if (pbVar4[1] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[1] << 8;
    if (pbVar4[2] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[2] << 0x10;
    if (pbVar4[3] == 0) break;
    uVar5 = uVar5 ^ (uint)pbVar4[3] << 0x18;
    pbVar4 = pbVar4 + 4;
  }
  if (off_F012F16C != (undefined (*) [28])0x0) {
    pbVar4 = *(byte **)(*off_F012F16C + 0xc);
    pauVar9 = off_F012F16C;
    while( true ) {
      if ((pbVar4 <= param_1) && (param_1 < *(byte **)(*pauVar9 + 0x10))) goto locret_F00F38E8;
      uVar1 = uVar5;
      urem(uVar5,*(undefined4 *)(*pauVar9 + 4));
      puVar7 = *(undefined4 **)(*(int *)(*pauVar9 + 0x14) + uVar1 * 4);
      if (puVar7 != (undefined4 *)0x0) {
        pbVar4 = (byte *)puVar7[1];
        while( true ) {
          if (*param_1 == *pbVar4) {
            pbVar2 = param_1;
            _strcmp(param_1,pbVar4);
            if (pbVar2 == (byte *)0x0) {
              param_1 = (byte *)puVar7[1];
              goto locret_F00F38E8;
            }
            puVar7 = (undefined4 *)*puVar7;
          }
          else {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) break;
          pbVar4 = (byte *)puVar7[1];
        }
      }
      if (pauVar9 == &unk_F012F150) {
        DAT_f012f158._0_4_ = DAT_f012f158._0_4_ + 1;
        if ((undefined8 *)DAT_f012f158._12_4_ == &unk_F00FA388) {
          DAT_f012f154._0_4_ = 0x335;
          uVar8 = 0xcd4;
          sub_F00F355C();
          DAT_f012f158._12_4_ = uVar8;
          _memset();
          urem(uVar5,DAT_f012f154._0_4_);
          uVar1 = uVar5;
        }
        uVar8 = *(undefined4 *)(DAT_f012f158._12_4_ + uVar1 * 4);
        if ((iRamf012f174 == 0) || (0x27 < iRamf012f178)) {
          iVar3 = 0x140;
          sub_F00F355C();
          iRamf012f178 = 0;
          iRamf012f174 = iVar3;
        }
        iVar3 = iRamf012f178 * 8;
        iVar6 = iVar3 + iRamf012f174;
        iRamf012f178 = iRamf012f178 + 1;
        *(undefined4 *)(iVar3 + iRamf012f174) = uVar8;
        *(byte **)(iVar6 + 4) = param_1;
        *(int *)(DAT_f012f158._12_4_ + uVar1 * 4) = iVar6;
        goto locret_F00F38E8;
      }
      pauVar9 = *(undefined (**) [28])(*pauVar9 + 0x18);
      if (pauVar9 == (undefined (*) [28])0x0) break;
      pbVar4 = *(byte **)(*pauVar9 + 0xc);
    }
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

