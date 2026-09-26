
/* WARNING: Removing unreachable block (ram,0xf007715c) */
/* WARNING: Removing unreachable block (ram,0xf007707c) */
/* WARNING: Removing unreachable block (ram,0xf007716c) */
/* WARNING: Removing unreachable block (ram,0xf0077058) */

undefined8 _calloutEntryDispatchDelayed(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
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
  piVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 0) {
    *(qword *)(param_1 + 6) = CONCAT44(param_2,param_3);
    param_1[3] = param_1[4];
    piVar4 = dword_F0130F34;
    while (piVar5 = DAT_f0130f38, (int **)piVar4 != &dword_F0130F34) {
      if ((uint)param_1[6] < (uint)piVar4[6]) {
        piVar5 = (int *)piVar4[1];
        break;
      }
      if (piVar4[6] == param_1[6]) {
        if ((uint)param_1[7] < (uint)piVar4[7]) {
          piVar5 = (int *)piVar4[1];
          break;
        }
        iVar3 = param_1[6];
      }
      else {
        iVar3 = param_1[6];
      }
      if (iVar3 == piVar4[6]) {
        if (param_1[7] == piVar4[7]) {
          iVar3 = *piVar4;
          goto loc_F007712C;
        }
        piVar4 = (int *)*piVar4;
      }
      else {
        piVar4 = (int *)*piVar4;
      }
    }
    iVar3 = *piVar5;
    piVar4 = piVar5;
loc_F007712C:
    *param_1 = iVar3;
    param_1[1] = (int)piVar4;
    *(int **)(*piVar4 + 4) = param_1;
    *piVar4 = (int)param_1;
    param_1[8] = 2;
    if (dword_F0130F34 == param_1) {
      sub_F007673C(param_1);
    }
  }
  dword_F0130F20 = 0;
  _splx(piVar1);
  return CONCAT44(piVar1,param_1);
}
