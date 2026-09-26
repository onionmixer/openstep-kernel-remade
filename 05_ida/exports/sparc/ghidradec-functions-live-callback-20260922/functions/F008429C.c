
/* WARNING: Removing unreachable block (ram,0xf008439c) */
/* WARNING: Removing unreachable block (ram,0xf00843cc) */
/* WARNING: Removing unreachable block (ram,0xf00842d8) */

undefined8 _vm_map_insert(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  if (param_4 < *(uint *)(param_1 + 0x14)) {
    uVar5 = 1;
  }
  else if ((*(uint *)(param_1 + 0x18) < param_5) || (param_5 <= param_4)) {
    uVar5 = 1;
  }
  else {
    iVar4 = param_1;
    _vm_map_lookup_entry(param_1,param_4,(undefined *)((int)register0x00000038 + -0xc));
    uVar5 = 3;
    if (iVar4 == 0) {
      iVar4 = *(int *)((int)register0x00000038 + -0xc);
      if (((((param_2 == 0) && (iVar4 != param_1 + 0xc)) && (*(uint *)(iVar4 + 0xc) == param_4)) &&
          (((*(uint *)(iVar4 + 0x18) & 0xa0000000) == 0 && (*(int *)(iVar4 + 0x24) == 1)))) &&
         ((*(int *)(iVar4 + 0x1c) == 3 &&
          ((*(int *)(iVar4 + 0x20) == 7 && (*(sword *)(iVar4 + 0x28) == 0)))))) {
        iVar1 = *(int *)(iVar4 + 0x10);
        _vm_object_coalesce(iVar1,0,*(undefined4 *)(iVar4 + 0x14),0,param_4 - *(int *)(iVar4 + 8),
                            param_5 - param_4);
        uVar5 = 0;
        if (iVar1 != 0) {
          *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (param_5 - *(int *)(iVar4 + 0xc));
          *(uint *)(iVar4 + 0xc) = param_5;
          goto locret_F00844A0;
        }
      }
      piVar2 = (int *)(param_1 + 0xc);
      __vm_map_entry_create();
      piVar2[2] = param_4;
      piVar2[3] = param_5;
      piVar2[4] = param_2;
      piVar2[5] = param_3;
      piVar2[6] = piVar2[6] & 0x5fffffff;
      piVar2[6] = piVar2[6] & 0xedffffff;
      if (*(int *)(param_1 + 0x2c) != 0) {
        piVar2[9] = 1;
        piVar2[7] = 3;
        piVar2[8] = 7;
        *(undefined2 *)(piVar2 + 10) = 0;
      }
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar2 = iVar4;
      piVar3 = *(int **)(iVar4 + 4);
      iVar1 = *piVar2;
      piVar2[1] = (int)piVar3;
      *piVar3 = (int)piVar2;
      *(int **)(iVar1 + 4) = piVar2;
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (piVar2[3] - piVar2[2]);
      if ((*(int *)(param_1 + 0x40) == iVar4) && ((uint)piVar2[2] <= *(uint *)(iVar4 + 0xc))) {
        *(int **)(param_1 + 0x40) = piVar2;
      }
      uVar5 = 0;
    }
  }
locret_F00844A0:
  return CONCAT44(param_2,uVar5);
}

