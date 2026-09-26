
/* WARNING: Removing unreachable block (ram,0xf00ea878) */
/* WARNING: Removing unreachable block (ram,0xf00ea834) */

undefined8 -[HashTable isKey:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  iVar3 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 8);
  sub_F00EA210(iVar1,param_3,*(undefined4 *)(param_1 + 0x10));
  iVar2 = *(int *)(iVar3 + iVar1 * 8);
  *(int *)((int)register0x00000038 + -0x18) = iVar2;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar3 + iVar1 * 8 + 4);
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    puVar4 = *(undefined4 **)((int)register0x00000038 + -0x14);
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 == -1) {
        uVar5 = 0;
        goto locret_F00EA8A0;
      }
      iVar1 = *(int *)(param_1 + 8);
      sub_F00EA2E8(iVar1,param_3,*puVar4);
      puVar4 = puVar4 + 2;
    } while (iVar1 == 0);
    uVar5 = 1;
  }
locret_F00EA8A0:
  return CONCAT44(param_2,uVar5);
}

