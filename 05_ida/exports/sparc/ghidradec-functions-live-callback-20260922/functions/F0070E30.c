
/* WARNING: Removing unreachable block (ram,0xf0070fd0) */
/* WARNING: Removing unreachable block (ram,0xf0070eec) */
/* WARNING: Removing unreachable block (ram,0xf0070ea0) */
/* WARNING: Removing unreachable block (ram,0xf0070e50) */
/* WARNING: Removing unreachable block (ram,0xf0070ec8) */
/* WARNING: Removing unreachable block (ram,0xf0070f50) */
/* WARNING: Removing unreachable block (ram,0xf0070fec) */
/* WARNING: Removing unreachable block (ram,0xf0070e34) */

undefined8 _clear_wait(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
    } while (param_1[8] != 0);
    piVar5 = param_1 + 8;
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  if (param_3 == 0) {
    uVar4 = param_1[0xf];
  }
  else {
    if ((param_1[0x13] & 8U) != 0) goto def_F0070F78;
    uVar4 = param_1[0xf];
  }
  bVar6 = uVar4 == 0;
  if (!bVar6) {
    param_1[8] = 0;
    uVar2 = uVar4;
    if ((int)uVar4 < 0) {
      uVar2 = ~uVar4;
    }
    rem(uVar2,0x3b);
    piVar5 = (int *)(_wait_lock + uVar2 * 4);
    do {
      do {
      } while (*piVar5 != 0);
      piVar3 = piVar5;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    do {
      do {
      } while (param_1[8] != 0);
      piVar3 = param_1 + 8;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (param_1[0xf] == uVar4) {
      *(int *)(*param_1 + 4) = param_1[1];
      uVar4 = 0;
      *(int *)param_1[1] = *param_1;
      param_1[0xf] = 0;
    }
    *piVar5 = 0;
    bVar6 = uVar4 == 0;
  }
  if (bVar6) {
    uVar4 = param_1[0x13];
    if (param_1[0x53] != 0) {
      _reset_timeout(param_1 + 0x46);
    }
    switch(uVar4 & 0xf) {
    case :
    case :
    case :
      param_1[0x13] = uVar4 & 0xfffffffe | 4;
      param_1[0x11] = param_2;
      _thread_setrun(param_1,1);
      break;
    case :
    case :
    case :
    case :
    case :
      param_1[0x13] = uVar4 & 0xfffffffe;
      param_1[0x11] = param_2;
    }
  }
def_F0070F78:
  param_1[8] = 0;
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}

