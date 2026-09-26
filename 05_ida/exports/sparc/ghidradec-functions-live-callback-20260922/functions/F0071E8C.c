
/* WARNING: Removing unreachable block (ram,0xf0071f60) */
/* WARNING: Removing unreachable block (ram,0xf0071f3c) */
/* WARNING: Removing unreachable block (ram,0xf0071f74) */
/* WARNING: Removing unreachable block (ram,0xf0071eac) */

undefined8 _choose_thread(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
  do {
    do {
    } while (param_1[0x40] != 0);
    piVar2 = param_1 + 0x40;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (0 < param_1[0x42]) {
    iVar1 = param_1[0x41];
    piVar2 = param_1 + iVar1 * 2;
    for (; -1 < iVar1; iVar1 = iVar1 + -1) {
      piVar3 = (int *)*piVar2;
      if (piVar2 != piVar3) {
        if (piVar3 == piVar2) {
          piVar3 = (int *)0x0;
        }
        else {
          *(int **)(*piVar3 + 4) = piVar2;
          *piVar2 = *piVar3;
        }
        piVar3[2] = 0;
        param_1[0x41] = iVar1;
        param_1[0x40] = 0;
        param_1[0x42] = param_1[0x42] + -1;
        param_1 = piVar3;
        goto locret_F0071F80;
      }
      piVar2 = piVar2 + -2;
    }
    _panic(aChooseThread);
  }
  param_1[0x40] = 0;
  iVar1 = param_1[0x4b];
  piVar2 = (int *)(iVar1 + 0x100);
  do {
    do {
    } while (*piVar2 != 0);
    piVar3 = piVar2;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  _choose_pset_thread(param_1,iVar1);
locret_F0071F80:
  return CONCAT44(param_2,param_1);
}

