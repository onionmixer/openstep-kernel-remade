
/* WARNING: Removing unreachable block (ram,0xf0084dbc) */
/* WARNING: Removing unreachable block (ram,0xf0084d44) */
/* WARNING: Removing unreachable block (ram,0xf0084d6c) */
/* WARNING: Removing unreachable block (ram,0xf0084dd8) */
/* WARNING: Removing unreachable block (ram,0xf0084cfc) */

undefined8 _vm_map_inherit(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (param_4 < 3) {
    if (param_4 < 0) {
      uVar5 = 4;
    }
    else {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      if (param_2 < *(uint *)(param_1 + 0x14)) {
        param_2 = *(uint *)(param_1 + 0x14);
      }
      if (*(uint *)(param_1 + 0x18) < param_3) {
        param_3 = *(uint *)(param_1 + 0x18);
      }
      if (param_3 < param_2) {
        param_2 = param_3;
      }
      iVar1 = param_1;
      _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
      uVar4 = *(uint *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) {
        uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 4);
      }
      else if (*(uint *)(uVar4 + 8) < param_2) {
        __vm_map_clip_start(param_1 + 0xc,uVar4,param_2);
      }
      uVar2 = param_1 + 0xc;
      if (uVar4 != uVar2) {
        uVar3 = *(uint *)(uVar4 + 8);
        while (param_2 = uVar2, uVar3 < param_3) {
          if (param_3 < *(uint *)(uVar4 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,uVar4,param_3);
          }
          *(int *)(uVar4 + 0x24) = param_4;
          uVar4 = *(uint *)(uVar4 + 4);
          if (uVar4 == uVar2) break;
          uVar3 = *(uint *)(uVar4 + 8);
        }
      }
      _lock_done(param_1);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 4;
  }
  return CONCAT44(param_2,uVar5);
}

