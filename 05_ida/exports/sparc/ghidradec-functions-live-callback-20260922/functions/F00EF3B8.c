
/* WARNING: Removing unreachable block (ram,0xf00ef3e4) */

undefined8 sub_F00EF3B8(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
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
  piVar1 = *(int **)(param_1 + 0x18);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      param_1 = *(int *)(param_1 + 4);
    }
    else {
      piVar3 = piVar1;
      iVar4 = 0;
      while (iVar4 < *piVar3) {
        iVar2 = param_2;
        _strcmp(param_2,piVar1[iVar4 * 3 + 1]);
        if (iVar2 == 0) {
          piVar1 = piVar1 + iVar4 * 3 + 1;
          goto locret_F00EF428;
        }
        iVar4 = iVar4 + 1;
        piVar3 = *(int **)(param_1 + 0x18);
      }
      param_1 = *(int *)(param_1 + 4);
    }
    if (param_1 == 0) break;
    piVar1 = *(int **)(param_1 + 0x18);
  }
  piVar1 = (int *)0x0;
locret_F00EF428:
  return CONCAT44(param_2,piVar1);
}

