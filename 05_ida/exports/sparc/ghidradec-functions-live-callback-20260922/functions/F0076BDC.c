
/* WARNING: Removing unreachable block (ram,0xf0076d34) */
/* WARNING: Removing unreachable block (ram,0xf0076c18) */
/* WARNING: Removing unreachable block (ram,0xf0076c44) */
/* WARNING: Removing unreachable block (ram,0xf0076d44) */
/* WARNING: Removing unreachable block (ram,0xf0076bf4) */

undefined8 _calloutDispatchDelayed(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar2 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      _panic(aInternalentrya);
    }
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      piVar4 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
      piVar4 = dword_F0130F24;
      dword_F0130F24 = (int *)*dword_F0130F24;
    }
    piVar4[2] = param_1;
    piVar4[3] = param_2;
    piVar4[4] = 0;
    *(qword *)(piVar4 + 6) = CONCAT44(param_3,param_4);
    piVar5 = dword_F0130F34;
    while (piVar6 = DAT_f0130f38, (int **)piVar5 != &dword_F0130F34) {
      if ((uint)piVar4[6] < (uint)piVar5[6]) {
        piVar6 = (int *)piVar5[1];
        break;
      }
      if (piVar5[6] == piVar4[6]) {
        if ((uint)piVar4[7] < (uint)piVar5[7]) {
          piVar6 = (int *)piVar5[1];
          break;
        }
        iVar3 = piVar4[6];
      }
      else {
        iVar3 = piVar4[6];
      }
      if (iVar3 == piVar5[6]) {
        if (piVar4[7] == piVar5[7]) {
          iVar3 = *piVar5;
          goto loc_F0076D04;
        }
        piVar5 = (int *)*piVar5;
      }
      else {
        piVar5 = (int *)*piVar5;
      }
    }
    iVar3 = *piVar6;
    piVar5 = piVar6;
loc_F0076D04:
    *piVar4 = iVar3;
    piVar4[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = piVar4;
    *piVar5 = (int)piVar4;
    piVar4[8] = 2;
    if (dword_F0130F34 == piVar4) {
      sub_F007673C(piVar4);
    }
    dword_F0130F20 = 0;
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}

