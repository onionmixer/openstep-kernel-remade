
/* WARNING: Removing unreachable block (ram,0xf0027ef4) */
/* WARNING: Removing unreachable block (ram,0xf0027e28) */
/* WARNING: Removing unreachable block (ram,0xf0027dec) */
/* WARNING: Removing unreachable block (ram,0xf0027e18) */
/* WARNING: Removing unreachable block (ram,0xf0027e40) */
/* WARNING: Removing unreachable block (ram,0xf0027f04) */
/* WARNING: Removing unreachable block (ram,0xf0027d98) */

undefined8 _getfakedirentries(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar9;
  undefined4 *puVar10;
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
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0) {
    puVar9 = (undefined4 *)0x0;
    goto locret_F0027F24;
  }
  puVar6 = *(undefined4 **)(param_2 + 0x14);
  uVar8 = 0xfffffc00 - *(int *)(param_2 + 8);
  if (puVar6 != (undefined4 *)0x0) {
    uVar5 = 0;
    if (uVar8 != 0) {
      do {
        puVar9 = (undefined4 *)0x0;
        if (iVar4 == 0) goto locret_F0027F24;
        uVar1 = iVar4 + 0x20;
        _strlen();
        *(sword *)((int)register0x00000038 + -0x10a) = (sword)uVar1;
        iVar3 = ((uVar1 & 0xffff) + 4 & 0xfffffffc) + 8;
        uVar1 = uVar5 & 0xfffffc00;
        uVar5 = uVar5 + iVar3;
        if (0x400 < uVar1 + iVar3) {
          uVar5 = uVar1 + 0x400;
        }
        iVar4 = *(int *)(iVar4 + 0x120);
      } while (uVar5 < uVar8);
    }
    puVar9 = (undefined4 *)0x0;
    if (iVar4 == 0) goto locret_F0027F24;
    puVar2 = puVar6;
    _kalloc();
    iVar3 = 0;
    puVar10 = puVar2;
    for (puVar9 = puVar6; iVar7 = 0, puVar9 != (undefined4 *)0x0;
        puVar9 = (undefined4 *)((int)puVar9 - uVar5)) {
      *puVar10 = 0xffffffff;
      iVar7 = iVar4 + 0x20;
      _strlen();
      *(sword *)((int)puVar10 + 6) = (sword)iVar7;
      _strcpy(puVar10 + 2,iVar4 + 0x20);
      iVar4 = *(int *)(iVar4 + 0x120);
      if (iVar4 == 0) {
        *(sword *)(puVar10 + 1) = (sword)(0x400U - iVar3);
        uVar5 = 0x400U - iVar3 & 0xffff;
        iVar7 = (int)puVar9 - uVar5;
        uVar8 = uVar8 + uVar5;
        break;
      }
      uVar5 = iVar4 + 0x20;
      _strlen();
      *(sword *)((int)register0x00000038 + -0x10a) = (sword)uVar5;
      if (((uVar5 & 0xffff) + 4 & 0xfffffffc) + iVar3 + 0x10 +
          (*(word *)((int)puVar10 + 6) + 4 & 0xfffffffc) < 0x401) {
        *(word *)(puVar10 + 1) = (*(word *)((int)puVar10 + 6) + 4 & 0xfffc) + 8;
        iVar3 = iVar3 + 8 + (*(word *)((int)puVar10 + 6) + 4 & 0xfffffffc);
      }
      else {
        *(sword *)(puVar10 + 1) = 0x400 - (sword)iVar3;
        iVar3 = 0;
      }
      uVar5 = (uint)*(word *)(puVar10 + 1);
      uVar8 = uVar8 + uVar5;
      puVar10 = (undefined4 *)((int)puVar10 + uVar5);
    }
    puVar9 = puVar2;
    _uiomove(puVar2,*(int *)(param_2 + 0x14) - iVar7,0,param_2);
    _kfree(puVar2,puVar6);
    if (puVar9 != (undefined4 *)0x0) goto locret_F0027F24;
    *(uint *)(param_2 + 8) = -(uVar8 + 0x400);
  }
  puVar9 = (undefined4 *)0x0;
locret_F0027F24:
  return CONCAT44(param_2,puVar9);
}
