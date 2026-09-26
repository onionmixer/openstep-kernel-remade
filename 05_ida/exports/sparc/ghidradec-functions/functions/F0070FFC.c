
/* WARNING: Removing unreachable block (ram,0xf0071180) */
/* WARNING: Removing unreachable block (ram,0xf00710e0) */
/* WARNING: Removing unreachable block (ram,0xf0071054) */
/* WARNING: Removing unreachable block (ram,0xf0071028) */
/* WARNING: Removing unreachable block (ram,0xf00710a0) */
/* WARNING: Removing unreachable block (ram,0xf0071160) */
/* WARNING: Removing unreachable block (ram,0xf00711ac) */
/* WARNING: Removing unreachable block (ram,0xf0071010) */

undefined8 _thread_wakeup_prim(uint param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  int *piVar7;
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
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = ~param_1;
  }
  .rem(uVar2,0x3b);
  puVar1 = _wait_queue;
  piVar7 = (int *)(_wait_queue + uVar2 * 8);
  _splusclock();
  piVar5 = (int *)(_wait_lock + uVar2 * 4);
  do {
    do {
    } while (*piVar5 != 0);
    piVar4 = piVar5;
    _simple_lock_try();
  } while (piVar4 == (int *)0x0);
  piVar4 = (int *)*piVar7;
  if (piVar7 == piVar4) {
loc_F00711A8:
    *piVar5 = 0;
    _splx(puVar1);
    return CONCAT44(param_2,param_1);
  }
  uVar2 = piVar4[0xf];
  do {
    piVar6 = (int *)*piVar4;
    if (uVar2 == param_1) {
      do {
        do {
        } while (piVar4[8] != 0);
        piVar3 = piVar4 + 8;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(int *)(*piVar4 + 4) = piVar4[1];
      *(int *)piVar4[1] = *piVar4;
      piVar4[0xf] = 0;
      if (piVar4[0x53] == 0) {
        uVar2 = piVar4[0x13];
      }
      else {
        _reset_timeout(piVar4 + 0x46);
        uVar2 = piVar4[0x13];
      }
      switch(uVar2 & 0xf) {
      case :
      case :
      case :
        piVar4[0x13] = uVar2 & 0xfffffffe | 4;
        piVar4[0x11] = param_3;
        _thread_setrun(piVar4,1);
        break;
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      :
        _panic(aThreadWakeup);
        break;
      case :
      case :
      case :
      case :
      case :
        piVar4[0x13] = uVar2 & 0xfffffffe;
        piVar4[0x11] = param_3;
      }
      piVar4[8] = 0;
      if (param_2 != 0) goto loc_F00711A8;
    }
    if (piVar7 == piVar6) goto loc_F00711A8;
    uVar2 = piVar6[0xf];
    piVar4 = piVar6;
  } while( true );
}
