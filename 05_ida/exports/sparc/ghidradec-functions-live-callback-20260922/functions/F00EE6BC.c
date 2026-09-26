
/* WARNING: Removing unreachable block (ram,0xf00ee708) */

undefined8 _NXMapMember(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  iVar5 = param_1[3];
  piVar6 = param_1;
  (**(code **)*param_1)(param_1,param_2);
  uVar2 = ((uint)piVar6 & 0xffff ^ (uint)piVar6 >> 0x10) * 0xfff1 + (int)piVar6;
  urem(uVar2,param_1[2]);
  piVar6 = (int *)(iVar5 + uVar2 * 8);
  if (*(int *)(iVar5 + uVar2 * 8) == -1) {
loc_F00EE824:
    iVar5 = -1;
  }
  else {
    dword_F012F0AC = dword_F012F0AC + 1;
    if (*piVar6 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar6,param_2);
    }
    uVar1 = uVar2;
    if (piVar3 == (int *)0x0) {
      do {
        uVar4 = 0;
        if (uVar1 + 1 < (uint)param_1[2]) {
          uVar4 = uVar1 + 1;
        }
        if (uVar4 == uVar2) goto loc_F00EE824;
        DAT_f012f0b4 = DAT_f012f0b4 + 1;
        piVar6 = (int *)(iVar5 + uVar4 * 8);
        if (*(int *)(iVar5 + uVar4 * 8) == -1) {
          iVar5 = -1;
          goto locret_F00EE828;
        }
        if (*piVar6 == param_2) {
          piVar3 = (int *)0x1;
        }
        else {
          piVar3 = param_1;
          (**(code **)(*param_1 + 4))(param_1,*piVar6,param_2);
        }
        uVar1 = uVar4;
      } while (piVar3 == (int *)0x0);
      *param_3 = piVar6[1];
      iVar5 = *piVar6;
    }
    else {
      *param_3 = piVar6[1];
      dword_F012F0B0 = dword_F012F0B0 + 1;
      iVar5 = *piVar6;
    }
  }
locret_F00EE828:
  return CONCAT44(param_2,iVar5);
}

