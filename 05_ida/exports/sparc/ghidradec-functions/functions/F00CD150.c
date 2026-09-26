
/* WARNING: Removing unreachable block (ram,0xf00cd1d4) */
/* WARNING: Removing unreachable block (ram,0xf00cd20c) */
/* WARNING: Removing unreachable block (ram,0xf00cd1b4) */

undefined8 -[IOSCSIController free](int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
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
  if ((*(int **)(param_1 + 0x128) != (int *)0x0) &&
     (piVar1 = (int *)(param_1 + 0x128), piVar1 != *(int **)(param_1 + 0x128))) {
    piVar2 = *(int **)(param_1 + 0x128);
    piVar7 = (int *)piVar2[5];
    while( true ) {
      piVar6 = (int *)piVar2[6];
      piVar5 = piVar1;
      if (piVar1 != piVar7) {
        piVar5 = piVar7 + 5;
      }
      piVar5[1] = (int)piVar6;
      piVar5 = piVar1;
      if (piVar1 != piVar6) {
        piVar5 = piVar6 + 5;
      }
      *piVar5 = (int)piVar7;
      _IOFree(piVar2,0x20);
      piVar2 = *(int **)(param_1 + 0x128);
      if (piVar1 == piVar2) break;
      piVar7 = (int *)piVar2[5];
    }
  }
  iVar3 = param_1;
  _objc_msgSend(param_1,paUnit_0);
  if (iVar3 == dword_F012ECE8 + -1) {
    dword_F012ECE8 = iVar3;
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar4 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142140;
  _objc_msgSendSuper(puVar4,paFree);
  return CONCAT44(param_2,puVar4);
}
