
/* WARNING: Removing unreachable block (ram,0xf0070d88) */
/* WARNING: Removing unreachable block (ram,0xf0070d28) */
/* WARNING: Removing unreachable block (ram,0xf0070d04) */
/* WARNING: Removing unreachable block (ram,0xf0070cfc) */
/* WARNING: Removing unreachable block (ram,0xf0070df0) */
/* WARNING: Removing unreachable block (ram,0xf0070d64) */
/* WARNING: Removing unreachable block (ram,0xf0070e20) */
/* WARNING: Removing unreachable block (ram,0xf0070cf0) */

undefined8 _assert_wait(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
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
  
  puVar1 = _active_threads;
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
  puVar2 = (undefined *)0xf0110000;
  if (_active_threads[0xf] != 0) {
    _printf(aAssertWaitAlre);
    puVar2 = aAssertWait;
    _panic(aAssertWait);
  }
  _splusclock();
  if (param_1 == 0) {
    do {
      do {
      } while (puVar1[8] != 0);
      piVar7 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    if (param_2 == 0) {
      uVar5 = puVar1[0x13] | 9;
    }
    else {
      uVar5 = puVar1[0x13] | 1;
    }
    puVar1[0x13] = uVar5;
    puVar1[8] = 0;
  }
  else {
    uVar5 = param_1;
    if ((int)param_1 < 0) {
      uVar5 = ~param_1;
    }
    .rem(uVar5,0x3b);
    iVar6 = uVar5 * 8;
    piVar7 = (int *)(_wait_lock + uVar5 * 4);
    do {
      do {
      } while (*piVar7 != 0);
      piVar3 = piVar7;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    do {
      do {
      } while (puVar1[8] != 0);
      piVar3 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    *puVar1 = _wait_queue + iVar6;
    puVar4 = *(undefined4 **)(_wait_queue + iVar6 + 4);
    puVar1[1] = puVar4;
    *puVar4 = puVar1;
    *(undefined4 **)(_wait_queue + iVar6 + 4) = puVar1;
    puVar1[0xf] = param_1;
    if (param_2 == 0) {
      uVar5 = puVar1[0x13] | 9;
    }
    else {
      uVar5 = puVar1[0x13] | 1;
    }
    puVar1[0x13] = uVar5;
    puVar1[8] = 0;
    *piVar7 = 0;
  }
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
