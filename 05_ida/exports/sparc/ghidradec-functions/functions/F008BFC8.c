
/* WARNING: Removing unreachable block (ram,0xf008c190) */
/* WARNING: Removing unreachable block (ram,0xf008c07c) */
/* WARNING: Removing unreachable block (ram,0xf008c048) */
/* WARNING: Removing unreachable block (ram,0xf008c0e0) */
/* WARNING: Removing unreachable block (ram,0xf008c154) */
/* WARNING: Removing unreachable block (ram,0xf008c0f4) */
/* WARNING: Removing unreachable block (ram,0xf008c064) */
/* WARNING: Removing unreachable block (ram,0xf008c124) */
/* WARNING: Removing unreachable block (ram,0xf008c1b0) */
/* WARNING: Removing unreachable block (ram,0xf008bfcc) */

undefined8 _vnode_dealloc(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar8;
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
  puVar1 = param_1;
  _vnode_pager_vget();
  dword_F0111EA8 = 0;
  if (-1 < (int)param_1[3]) {
    *(word *)(puVar1 + 1) = *(word *)(puVar1 + 1) & 0xfffd;
    *(undefined4 *)*puVar1 = 0;
    _vn_rele();
    goto loc_F008C15C;
  }
  iVar4 = param_1[4];
  iVar8 = param_1[1];
  if ((uint)(iVar4 * 4) < 0x41) {
    iVar2 = 0;
    if (iVar4 < 1) {
      iVar4 = param_1[4];
    }
    else {
      iVar4 = param_1[2];
      while( true ) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(iVar4 + iVar2 * 4);
        sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1[2] + iVar2 * 4);
        sub_F008BF14((undefined *)((int)register0x00000038 + -0xc));
        iVar2 = iVar2 + 1;
        if ((int)param_1[4] <= iVar2) break;
        iVar4 = param_1[2];
      }
      iVar4 = param_1[4];
    }
    if (0 < iVar4) {
      uVar3 = param_1[2];
      goto loc_F008C124;
    }
    iVar4 = *(int *)(iVar8 + 0xc);
  }
  else {
    uVar7 = 0;
    if (iVar4 - 1U >> 4 != 0xffffffff) {
      iVar4 = 0;
      do {
        if (*(int *)(param_1[2] + iVar4) == 0) {
          iVar2 = param_1[4];
        }
        else {
          uVar6 = 0;
          iVar2 = param_1[2];
          do {
            iVar5 = uVar6 * 4;
            *(undefined4 *)((int)register0x00000038 + -0xc) =
                 *(undefined4 *)(*(int *)(iVar2 + iVar4) + iVar5);
            sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
            uVar6 = uVar6 + 1;
            *(undefined4 *)((int)register0x00000038 + -0xc) =
                 *(undefined4 *)(*(int *)(param_1[2] + iVar4) + iVar5);
            sub_F008BF14((undefined *)((int)register0x00000038 + -0xc));
            iVar2 = param_1[2];
          } while (uVar6 < 0x10);
          _kfree(*(undefined4 *)(iVar2 + iVar4),0x40);
          iVar2 = param_1[4];
        }
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar7 < (iVar2 - 1U >> 4) + 1);
      iVar4 = param_1[4];
    }
    uVar3 = param_1[2];
    iVar4 = (iVar4 - 1U >> 4) + 1;
loc_F008C124:
    _kfree(uVar3,iVar4 << 2);
    iVar4 = *(int *)(iVar8 + 0xc);
  }
  *(int *)(iVar8 + 0xc) = iVar4 + -1;
loc_F008C15C:
  iVar4 = 0;
  if (0 < dword_F0111EA8) {
    iVar8 = 0;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(unk_F0130FB0 + iVar8);
      _vnode_pager_truncate((undefined *)((int)register0x00000038 + -0xc));
      iVar8 = iVar8 + 4;
    } while (iVar4 < dword_F0111EA8);
  }
  _zfree(_vstruct_zone,param_1);
  return CONCAT44(param_2,param_1);
}
