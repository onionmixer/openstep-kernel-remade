
/* WARNING: Removing unreachable block (ram,0xf00775b8) */
/* WARNING: Removing unreachable block (ram,0xf0077598) */
/* WARNING: Removing unreachable block (ram,0xf0077534) */
/* WARNING: Removing unreachable block (ram,0xf0077508) */
/* WARNING: Removing unreachable block (ram,0xf007743c) */
/* WARNING: Removing unreachable block (ram,0xf007751c) */
/* WARNING: Removing unreachable block (ram,0xf0077584) */
/* WARNING: Removing unreachable block (ram,0xf00775b0) */
/* WARNING: Removing unreachable block (ram,0xf00775c0) */
/* WARNING: Removing unreachable block (ram,0xf007741c) */

undefined8 sub_F0077414(undefined4 *param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  code *pcVar6;
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
  
  uVar1 = _active_threads;
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
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (0 < dword_F0130F3C) {
    param_1 = &dword_F0130F2C;
    param_2 = unk_F0130520;
    do {
      if ((int **)dword_F0130F2C == &dword_F0130F2C) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_F0130F2C + 4) = &dword_F0130F2C;
        piVar3 = dword_F0130F2C;
        dword_F0130F2C = (int *)*dword_F0130F2C;
      }
      piVar3[8] = 0;
      pcVar6 = (code *)piVar3[2];
      iVar5 = piVar3[3];
      dword_F0130F3C = dword_F0130F3C + -1;
      piVar4 = piVar3;
      if ((unk_F0130520 <= piVar3) && (piVar3 < &dword_F0130F20)) {
        *piVar3 = (int)&dword_F0130F24;
        piVar3[1] = (int)DAT_f0130f28;
        *DAT_f0130f28 = (int)piVar3;
        piVar4 = (int *)0x0;
        DAT_f0130f28 = piVar3;
      }
      dword_F0130F20 = 0;
      dword_F0130F40 = dword_F0130F40 + 1;
      _spl0();
      (*pcVar6)(iVar5,piVar4);
      _splusclock();
      do {
        do {
        } while (dword_F0130F20 != 0);
        puVar2 = &dword_F0130F20;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
      dword_F0130F40 = dword_F0130F40 + -1;
    } while (0 < dword_F0130F3C);
  }
  if (dword_F0130F44 - dword_F0130F40 < 5) {
    _assert_wait(&dword_F0130F3C,0);
    dword_F0130F20 = 0;
    _thread_block_with_continuation(sub_F0077414);
  }
  dword_F0130F20 = 0;
  dword_F0130F44 = dword_F0130F44 + -1;
  _spl0();
  _thread_terminate(uVar1);
  _thread_halt_self();
  return CONCAT44(param_2,param_1);
}

