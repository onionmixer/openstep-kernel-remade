
/* WARNING: Removing unreachable block (ram,0xf00845a8) */
/* WARNING: Removing unreachable block (ram,0xf008455c) */
/* WARNING: Removing unreachable block (ram,0xf00844c4) */

undefined8 _vm_map_lookup_entry(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x3c) != 0);
    piVar1 = (int *)(param_1 + 0x3c);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar3 = *(undefined4 **)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xc);
  if (puVar3 == puVar2) {
    puVar3 = *(undefined4 **)(param_1 + 0x10);
  }
  if (puVar3 < puVar2) {
    puVar2 = (undefined4 *)puVar3[1];
    puVar3 = *(undefined4 **)(param_1 + 0x10);
  }
  else {
    bVar5 = true;
    if (puVar3 == puVar2) goto loc_F0084584;
    uVar4 = 1;
    if (param_2 < (uint)puVar3[3]) {
      *param_3 = puVar3;
      goto locret_F00845C8;
    }
  }
  while( true ) {
    bVar5 = puVar3 == puVar2;
loc_F0084584:
    if (bVar5) goto loc_F008458C;
    if (param_2 < (uint)puVar3[3]) break;
    puVar3 = (undefined4 *)puVar3[1];
  }
  if (param_2 < (uint)puVar3[2]) {
loc_F008458C:
    *param_3 = *puVar3;
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
      uVar4 = 0;
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x38) = *param_3;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  else {
    *param_3 = puVar3;
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 **)(param_1 + 0x38) = puVar3;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    uVar4 = 1;
  }
locret_F00845C8:
  return CONCAT44(param_2,uVar4);
}

