
/* WARNING: Removing unreachable block (ram,0xf006a0e4) */
/* WARNING: Removing unreachable block (ram,0xf006a100) */
/* WARNING: Removing unreachable block (ram,0xf006a0a4) */

undefined8 _getsectbynamefromheader(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int *piVar5;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar7;
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
  uVar6 = 0;
  piVar5 = (int *)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar5 == 1) {
        piVar7 = piVar5 + 2;
        _strncmp(piVar7,param_2,0x10);
        if (piVar7 == (int *)0x0) {
          iVar3 = piVar5[0xc];
        }
        else {
          if (*(int *)(param_1 + 0xc) != 1) {
            iVar3 = piVar5[1];
            goto loc_F006A12C;
          }
          iVar3 = piVar5[0xc];
        }
        uVar4 = 0;
        piVar7 = piVar5 + 0xe;
        if (iVar3 != 0) {
          do {
            piVar1 = piVar7;
            _strncmp(piVar7,param_3,0x10);
            if (piVar1 == (int *)0x0) {
              piVar1 = piVar7 + 4;
              _strncmp(piVar1,param_2,0x10);
              if (piVar1 == (int *)0x0) goto locret_F006A144;
              uVar2 = piVar5[0xc];
            }
            else {
              uVar2 = piVar5[0xc];
            }
            uVar4 = uVar4 + 1;
            piVar7 = piVar7 + 0x11;
          } while (uVar4 < uVar2);
        }
        iVar3 = piVar5[1];
      }
      else {
        iVar3 = piVar5[1];
      }
loc_F006A12C:
      uVar6 = uVar6 + 1;
      piVar5 = (int *)((int)piVar5 + iVar3);
    } while (uVar6 < *(uint *)(param_1 + 0x10));
  }
  piVar7 = (int *)0x0;
locret_F006A144:
  return CONCAT44(param_2,piVar7);
}
