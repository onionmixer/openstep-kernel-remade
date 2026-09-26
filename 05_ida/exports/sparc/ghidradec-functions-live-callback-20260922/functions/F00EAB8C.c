
/* WARNING: Removing unreachable block (ram,0xf00eac98) */
/* WARNING: Removing unreachable block (ram,0xf00eac20) */
/* WARNING: Removing unreachable block (ram,0xf00eabec) */
/* WARNING: Removing unreachable block (ram,0xf00eac10) */
/* WARNING: Removing unreachable block (ram,0xf00eac68) */
/* WARNING: Removing unreachable block (ram,0xf00eaca0) */
/* WARNING: Removing unreachable block (ram,0xf00eaba0) */

undefined8 -[HashTable removeKey:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined5 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar7 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 8);
  sub_F00EA210(iVar2,param_3,*(undefined4 *)(param_1 + 0x10));
  puVar1 = paZone;
  iVar6 = *(int *)(iVar7 + iVar2 * 8);
  *(int *)((int)register0x00000038 + -0x18) = iVar6;
  puVar3 = *(undefined4 **)(iVar7 + iVar2 * 8 + 4);
  *(undefined4 **)((int)register0x00000038 + -0x14) = puVar3;
  iVar6 = iVar6 + -1;
  if (iVar6 != -1) {
    iVar2 = iVar2 * 8;
    do {
      iVar4 = *(int *)(param_1 + 8);
      sub_F00EA2E8(iVar4,param_3,*puVar3);
      if (iVar4 != 0) {
        uVar8 = puVar3[1];
        if (*(int *)((int)register0x00000038 + -0x18) == 1) {
          iVar4 = 0;
        }
        else {
          iVar5 = param_1;
          _objc_msgSend(param_1,puVar1);
          iVar4 = param_1;
          _objc_msgSend(param_1,puVar1);
          (**(code **)(iVar5 + 4))();
        }
        if (*(int *)((int)register0x00000038 + -0x18) + -1 != iVar6) {
          _memmove(iVar4,*(undefined4 *)((int)register0x00000038 + -0x14),
                   ((*(int *)((int)register0x00000038 + -0x18) - iVar6) + -1) * 8);
        }
        if (iVar6 != 0) {
          _memmove(iVar4 + *(int *)((int)register0x00000038 + -0x18) * 8 + iVar6 * -8 + -8,
                   *(int *)((int)register0x00000038 + -0x18) * 8 +
                   *(int *)((int)register0x00000038 + -0x14) + iVar6 * -8);
        }
        _free(*(undefined4 *)((int)register0x00000038 + -0x14));
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        *(int *)(iVar7 + iVar2) = *(int *)(iVar7 + iVar2) + -1;
        *(int *)(iVar7 + iVar2 + 4) = iVar4;
        goto locret_F00EACDC;
      }
      iVar6 = iVar6 + -1;
      puVar3 = puVar3 + 2;
    } while (iVar6 != -1);
  }
  uVar8 = 0;
locret_F00EACDC:
  return CONCAT44(param_2,uVar8);
}

