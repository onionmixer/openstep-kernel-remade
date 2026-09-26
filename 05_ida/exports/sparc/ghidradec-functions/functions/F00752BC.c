
/* WARNING: Removing unreachable block (ram,0xf007540c) */
/* WARNING: Removing unreachable block (ram,0xf00753b4) */
/* WARNING: Removing unreachable block (ram,0xf0075300) */
/* WARNING: Removing unreachable block (ram,0xf00752e0) */
/* WARNING: Removing unreachable block (ram,0xf007537c) */
/* WARNING: Removing unreachable block (ram,0xf00753d0) */
/* WARNING: Removing unreachable block (ram,0xf0075424) */
/* WARNING: Removing unreachable block (ram,0xf00752d8) */

undefined8 _thread_dowait(undefined *param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
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
  uVar7 = 0;
  puVar1 = _active_threads;
  if (param_1 == _active_threads) {
    puVar1 = aThreadDowait;
    _panic(aThreadDowait);
  }
  iVar6 = 0;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar5 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = (int *)(param_1 + 0x20);
  uVar2 = *(uint *)(param_1 + 0x4c);
  do {
    switch(uVar2 & 0xf) {
    :
def_F007533C:
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(puVar1);
      if (iVar6 != 0) {
        _thread_wakeup_prim(param_1 + 0x48,0,0);
      }
      return CONCAT44(param_2,uVar7);
    case :
      puVar3 = param_1;
      _rem_runq();
      if (puVar3 != (undefined *)0x0) {
        iVar6 = *(int *)(param_1 + 0x48);
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb;
        *(undefined4 *)(param_1 + 0x48) = 0;
        goto def_F007533C;
      }
      *(undefined4 *)(param_1 + 0x48) = 1;
      break;
    case :
    case :
    case :
    case :
      *(undefined4 *)(param_1 + 0x48) = 1;
    }
    _thread_sleep(param_1 + 0x48,piVar5,1);
    do {
      do {
      } while (*piVar5 != 0);
      piVar4 = piVar5;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if (*(int *)(_active_threads + 0x44) == 0) {
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      if (param_2 == 0) {
        uVar7 = 5;
        goto def_F007533C;
      }
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
  } while( true );
}
