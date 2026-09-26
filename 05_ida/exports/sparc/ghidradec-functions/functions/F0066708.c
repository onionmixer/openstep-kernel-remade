
/* WARNING: Removing unreachable block (ram,0xf006683c) */
/* WARNING: Removing unreachable block (ram,0xf00667f8) */
/* WARNING: Removing unreachable block (ram,0xf006674c) */
/* WARNING: Removing unreachable block (ram,0xf0066728) */
/* WARNING: Removing unreachable block (ram,0xf006680c) */
/* WARNING: Removing unreachable block (ram,0xf0066834) */
/* WARNING: Removing unreachable block (ram,0xf0066844) */
/* WARNING: Removing unreachable block (ram,0xf006670c) */

undefined8 _thread_go_and_switch(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_2 + 0x20) != 0);
    piVar2 = (int *)(param_2 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_2 + 0x14c) == 0) {
    uVar3 = *(uint *)(param_2 + 0x4c);
  }
  else {
    _reset_timeout(param_2 + 0x118);
    uVar3 = *(uint *)(param_2 + 0x4c);
  }
  switch(uVar3 & 0xf) {
  case :
  case :
  case :
    *(uint *)(param_2 + 0x4c) = uVar3 & 0xfffffffe | 4;
    *(undefined4 *)(param_2 + 0x44) = 0;
    if ((*(int *)(*(int *)(param_2 + 400) + 0x114) < 1) &&
       (*(int *)(param_2 + 400) == *(int *)(_active_threads + 400))) {
      *(undefined4 *)(param_2 + 0x20) = 0;
      _thread_run(param_1,param_2);
      goto loc_F0066844;
    }
    _thread_setrun(param_2,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_2 + 0x4c) = uVar3 & 0xfffffffe;
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  *(undefined4 *)(param_2 + 0x20) = 0;
  if (param_1 != 0) {
    _spl0();
    _call_continuation(param_1);
  }
loc_F0066844:
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
