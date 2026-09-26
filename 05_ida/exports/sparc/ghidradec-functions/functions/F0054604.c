
/* WARNING: Removing unreachable block (ram,0xf0054640) */

undefined8 _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar5 != 0);
    piVar1 = piVar5;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar3 = piVar5[1];
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0xc);
    if (*(uint *)(iVar3 + 4) != param_2) goto loc_F00546CC;
    if (*(uint *)(iVar3 + 0x14) == param_1) {
      uVar2 = *(undefined4 *)(iVar3 + 0x10);
loc_F00546A0:
      *param_3 = uVar2;
      *param_4 = iVar3;
    }
    else {
      for (iVar3 = *(int *)(iVar3 + 0xc); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        if (*(uint *)(iVar3 + 4) == param_2) {
          if (*(uint *)(iVar3 + 0x14) == param_1) {
            *puVar4 = *(undefined4 *)(iVar3 + 0xc);
            *(int *)(iVar3 + 0xc) = piVar5[1];
            piVar5[1] = iVar3;
            uVar2 = *(undefined4 *)(iVar3 + 0x10);
            goto loc_F00546A0;
          }
          puVar4 = (undefined4 *)(iVar3 + 0xc);
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0xc);
        }
loc_F00546CC:
      }
    }
  }
  *piVar5 = 0;
  return CONCAT44(param_2,(uint)(iVar3 != 0));
}
