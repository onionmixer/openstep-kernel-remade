
/* WARNING: Removing unreachable block (ram,0xf00dd6f8) */
/* WARNING: Removing unreachable block (ram,0xf00dd6a8) */
/* WARNING: Removing unreachable block (ram,0xf00dd64c) */
/* WARNING: Removing unreachable block (ram,0xf00dd6d8) */
/* WARNING: Removing unreachable block (ram,0xf00dd718) */
/* WARNING: Removing unreachable block (ram,0xf00dd634) */

undefined8 -[OutputStream free](int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
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
  if (*(int *)(param_1 + 0xa0) == 0) {
    iVar1 = *(int *)(param_1 + 0x9c);
  }
  else {
    _IOFree(*(int *)(param_1 + 0xa0),0x40);
    iVar1 = *(int *)(param_1 + 0x9c);
  }
  if (iVar1 == 0) {
    piVar2 = *(int **)(param_1 + 0x8c);
  }
  else {
    _IOFree(iVar1,0x40);
    piVar2 = *(int **)(param_1 + 0x8c);
  }
  piVar4 = (int *)(param_1 + 0x8c);
  if (piVar4 == piVar2) {
    iVar1 = *(int *)(param_1 + 0x70);
  }
  else {
    piVar2 = *(int **)(param_1 + 0x8c);
    piVar7 = (int *)piVar2[5];
    while( true ) {
      piVar6 = (int *)piVar2[6];
      piVar5 = piVar4;
      if (piVar4 != piVar7) {
        piVar5 = piVar7 + 5;
      }
      piVar5[1] = (int)piVar6;
      piVar5 = piVar4;
      if (piVar4 != piVar6) {
        piVar5 = piVar6 + 5;
      }
      *piVar5 = (int)piVar7;
      _IOFree(piVar2,0x1c);
      piVar2 = *(int **)(param_1 + 0x8c);
      if (piVar4 == piVar2) break;
      piVar7 = (int *)piVar2[5];
    }
    iVar1 = *(int *)(param_1 + 0x70);
  }
  if (iVar1 != 0) {
    _IOFree(iVar1,_page_size << 3);
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    _IOFree(*(int *)(param_1 + 0x74),_page_size << 2);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01422f8;
  _objc_msgSendSuper(puVar3,paFree);
  return CONCAT44(param_2,puVar3);
}

