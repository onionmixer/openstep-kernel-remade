
/* WARNING: Removing unreachable block (ram,0xf00127f4) */
/* WARNING: Removing unreachable block (ram,0xf0012784) */
/* WARNING: Removing unreachable block (ram,0xf0012744) */
/* WARNING: Removing unreachable block (ram,0xf0012720) */
/* WARNING: Removing unreachable block (ram,0xf0012838) */
/* WARNING: Removing unreachable block (ram,0xf00126b0) */
/* WARNING: Removing unreachable block (ram,0xf001280c) */
/* WARNING: Removing unreachable block (ram,0xf0012840) */
/* WARNING: Removing unreachable block (ram,0xf001273c) */
/* WARNING: Removing unreachable block (ram,0xf0012754) */
/* WARNING: Removing unreachable block (ram,0xf001278c) */
/* WARNING: Removing unreachable block (ram,0xf0012848) */
/* WARNING: Removing unreachable block (ram,0xf0012684) */

undefined8 _sleep(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  iVar4 = *_active_u;
  piVar2 = _active_u;
  _splusclock();
  if (iVar4 != 0) {
    *(byte *)(iVar4 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla_0);
    }
    _thread_block_with_continuation(0);
  }
  else {
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) == 0) {
        uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
        if ((uVar1 != 0) &&
           (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
            ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
          iVar3 = 1;
          _issig();
          if (iVar3 != 0) goto loc_F0012734;
        }
        goto loc_F0012754;
      }
loc_F0012734:
      _clear_wait(_active_threads,2,1);
      _spl0();
      bVar6 = (param_2 & 0x100) == 0;
loc_F0012858:
      uVar5 = 1;
      if (bVar6) {
                    /* WARNING: Subroutine does not return */
        _longjmp(dword_F0133DDC + 0x28);
      }
      goto locret_F0012870;
    }
loc_F0012754:
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(0);
    if (iVar4 != 0) {
      bVar6 = (param_2 & 0x100) == 0;
      if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0012858;
      uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
      if ((uVar1 != 0) &&
         (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
          ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
        iVar4 = 1;
        _issig();
        bVar6 = (param_2 & 0x100) == 0;
        if (iVar4 != 0) goto loc_F0012858;
      }
    }
  }
  _splx(piVar2);
  uVar5 = 0;
locret_F0012870:
  return CONCAT44(param_2,uVar5);
}

