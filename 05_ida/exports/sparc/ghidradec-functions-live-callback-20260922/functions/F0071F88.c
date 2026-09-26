
/* WARNING: Removing unreachable block (ram,0xf0072068) */
/* WARNING: Removing unreachable block (ram,0xf0072048) */

undefined8 _choose_pset_thread(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  if (0 < *(int *)(param_2 + 0x108)) {
    iVar2 = *(int *)(param_2 + 0x104);
    piVar3 = (int *)(param_2 + iVar2 * 8);
    if (-1 < iVar2) {
      while( true ) {
        piVar4 = (int *)*piVar3;
        if (piVar3 != piVar4) break;
        iVar2 = iVar2 + -1;
        piVar3 = piVar3 + -2;
        if (iVar2 < 0) goto loc_F0072044;
      }
      if (piVar4 == piVar3) {
        piVar4 = (int *)0x0;
      }
      else {
        *(int **)(*piVar4 + 4) = piVar3;
        *piVar3 = *piVar4;
      }
      piVar4[2] = 0;
      iVar1 = *(int *)(param_2 + 0x108) + -1;
      *(int *)(param_2 + 0x108) = iVar1;
      if (iVar1 < 1) goto loc_F007202C;
      if ((*(uint *)(param_2 + 0x168) & 2) == 0) {
        *(int *)(param_2 + 0x104) = iVar2;
      }
      else if (piVar3 == (int *)*piVar3) {
        do {
          piVar3 = piVar3 + -2;
          iVar2 = iVar2 + -1;
        } while (piVar3 == (int *)*piVar3);
loc_F007202C:
        *(int *)(param_2 + 0x104) = iVar2;
      }
      else {
        *(int *)(param_2 + 0x104) = iVar2;
      }
      *(undefined4 *)(param_2 + 0x100) = 0;
      goto locret_F0072108;
    }
loc_F0072044:
    _panic(aChoosePsetThre);
  }
  *(undefined4 *)(param_2 + 0x100) = 0;
  do {
    do {
    } while (*(int *)(param_2 + 0x118) != 0);
    piVar3 = (int *)(param_2 + 0x118);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  if (*(int *)(param_1 + 0x114) == 1) {
    bVar5 = param_1 == _master_processor;
    *(undefined4 *)(param_1 + 0x114) = 2;
    if (bVar5) {
      iVar2 = *(int *)(param_2 + 0x110);
      if (param_2 + 0x10c == iVar2) {
        *(int *)(param_2 + 0x10c) = param_1;
      }
      else {
        *(int *)(iVar2 + 0x10c) = param_1;
      }
      *(int *)(param_1 + 0x110) = iVar2;
      *(int *)(param_1 + 0x10c) = param_2 + 0x10c;
      *(int *)(param_2 + 0x110) = param_1;
    }
    else {
      iVar2 = *(int *)(param_2 + 0x10c);
      if (param_2 + 0x10c == iVar2) {
        *(int *)(param_2 + 0x110) = param_1;
      }
      else {
        *(int *)(iVar2 + 0x110) = param_1;
      }
      *(int *)(param_1 + 0x10c) = iVar2;
      *(int *)(param_1 + 0x110) = param_2 + 0x10c;
      *(int *)(param_2 + 0x10c) = param_1;
    }
    *(int *)(param_2 + 0x114) = *(int *)(param_2 + 0x114) + 1;
  }
  *(undefined4 *)(param_2 + 0x118) = 0;
  piVar4 = *(int **)(param_1 + 0x11c);
locret_F0072108:
  return CONCAT44(param_2,piVar4);
}

