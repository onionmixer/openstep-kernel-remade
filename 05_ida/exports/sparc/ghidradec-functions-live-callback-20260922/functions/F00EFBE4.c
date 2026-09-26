
/* WARNING: Removing unreachable block (ram,0xf00efcc0) */
/* WARNING: Removing unreachable block (ram,0xf00efcb8) */
/* WARNING: Removing unreachable block (ram,0xf00efcf4) */
/* WARNING: Removing unreachable block (ram,0xf00efc18) */

undefined8 _class_respondsToMethod(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  if (param_2 == (int *)0x0) {
    uVar6 = 0;
  }
  else {
    piVar1 = param_2;
    do {
      uVar6 = (uint)piVar1 & **(uint **)(param_1 + 0x20);
      piVar1 = (int *)(uVar6 * 4);
      piVar3 = (int *)(*(uint **)(param_1 + 0x20) + 2)[uVar6];
      if (piVar3 == (int *)0x0) {
        piVar3 = *(int **)(param_1 + 0x1c);
        iVar5 = param_1;
        while( true ) {
          if (piVar3 == (int *)0x0) {
            iVar5 = *(int *)(iVar5 + 4);
          }
          else {
            iVar4 = piVar3[1];
            while( true ) {
              piVar2 = piVar3 + 2;
              while (iVar4 = iVar4 + -1, -1 < iVar4) {
                piVar1 = (int *)*piVar2;
                if (param_2 == piVar1) {
                  sub_F00F00E4(param_1);
                  uVar6 = 1;
                  goto locret_F00EFD00;
                }
                piVar2 = piVar2 + 3;
              }
              piVar3 = (int *)*piVar3;
              if (piVar3 == (int *)0x0) break;
              iVar4 = piVar3[1];
            }
            iVar5 = *(int *)(iVar5 + 4);
          }
          if (iVar5 == 0) break;
          piVar3 = *(int **)(iVar5 + 0x1c);
        }
        _NXDefaultMallocZone();
        piVar3 = piVar1;
        _NXDefaultMallocZone();
        (*(code *)piVar1[1])();
        *piVar3 = (int)param_2;
        piVar3[1] = (int)&asc_F00FA528;
        piVar3[2] = (int)__objc_msgForward;
        sub_F00F00E4(param_1);
        uVar6 = 0;
        goto locret_F00EFD00;
      }
      piVar1 = (int *)(uVar6 + 1);
    } while ((int *)*piVar3 != param_2);
    uVar6 = (uint)((code *)piVar3[2] != __objc_msgForward);
  }
locret_F00EFD00:
  return CONCAT44(param_2,uVar6);
}

