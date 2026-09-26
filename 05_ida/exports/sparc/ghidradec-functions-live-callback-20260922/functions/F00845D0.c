
/* WARNING: Removing unreachable block (ram,0xf0084700) */
/* WARNING: Removing unreachable block (ram,0xf00846c8) */
/* WARNING: Removing unreachable block (ram,0xf0084640) */
/* WARNING: Removing unreachable block (ram,0xf00846f4) */
/* WARNING: Removing unreachable block (ram,0xf008467c) */
/* WARNING: Removing unreachable block (ram,0xf00845dc) */

undefined8
_vm_map_find(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,int param_5,int param_6
            )

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  int iVar5;
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
  uVar4 = *param_4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_6 == 0) {
loc_F00846E4:
    iVar5 = param_1;
    _vm_map_insert(param_1,param_2,param_3,uVar4,uVar4 + param_5);
    _lock_done(param_1);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (uVar4 < uVar2) {
      uVar4 = uVar2;
    }
    if (uVar4 <= *(uint *)(param_1 + 0x18)) {
      if (uVar4 == uVar2) {
        iVar5 = *(int *)(param_1 + 0x40);
        if (iVar5 != param_1 + 0xc) {
          uVar4 = *(uint *)(iVar5 + 0xc);
        }
      }
      else {
        iVar5 = param_1;
        _vm_map_lookup_entry(param_1,uVar4,(undefined *)((int)register0x00000038 + -0xc));
        if (iVar5 != 0) {
          uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0xc);
        }
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      while( true ) {
        uVar2 = uVar4 + param_5;
        if ((*(uint *)(param_1 + 0x18) < uVar2) || (uVar2 < uVar4)) break;
        iVar3 = *(int *)(iVar5 + 4);
        if (iVar3 == param_1 + 0xc) {
          *param_4 = uVar4;
loc_F00846B4:
          do {
            do {
            } while (*(int *)(param_1 + 0x3c) != 0);
            piVar1 = (int *)(param_1 + 0x3c);
            _simple_lock_try();
          } while (piVar1 == (int *)0x0);
          *(int *)(param_1 + 0x38) = iVar5;
          *(undefined4 *)(param_1 + 0x3c) = 0;
          goto loc_F00846E4;
        }
        if (uVar2 <= *(uint *)(iVar3 + 8)) {
          *param_4 = uVar4;
          goto loc_F00846B4;
        }
        uVar4 = *(uint *)(iVar3 + 0xc);
        iVar5 = iVar3;
      }
    }
    _lock_done(param_1);
    iVar5 = 3;
  }
  return CONCAT44(param_2,iVar5);
}

