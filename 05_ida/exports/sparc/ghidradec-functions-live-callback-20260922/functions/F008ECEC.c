
/* WARNING: Removing unreachable block (ram,0xf008edb4) */
/* WARNING: Removing unreachable block (ram,0xf008ed8c) */
/* WARNING: Removing unreachable block (ram,0xf008ed34) */
/* WARNING: Removing unreachable block (ram,0xf008ed04) */
/* WARNING: Removing unreachable block (ram,0xf008ed78) */
/* WARNING: Removing unreachable block (ram,0xf008edac) */
/* WARNING: Removing unreachable block (ram,0xf008ed20) */
/* WARNING: Removing unreachable block (ram,0xf008ecf0) */

undefined8 _IOSendInterrupt(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x14);
  _curipl();
  if (param_1 < 0xb) {
    _KernLockAcquire(*(undefined4 *)(iVar2 + 0x30));
    if ((*(uint *)(iVar2 + 0x60) & 0xc0000000) == 0) {
      *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) | 0x80000000;
      _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
      *(undefined4 *)(iVar2 + 0x14) = dword_F0112054;
      *(undefined4 *)(iVar2 + 0x18) = DAT_f0112058._0_4_;
      *(undefined4 *)(iVar2 + 0x1c) = DAT_f0112058._4_4_;
      *(undefined4 *)(iVar2 + 0x20) = DAT_f0112058._8_4_;
      *(undefined4 *)(iVar2 + 0x24) = DAT_f0112058._12_4_;
      *(undefined4 *)(iVar2 + 0x28) = param_3;
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x2c);
      iVar1 = iVar2;
      _ipc_mqueue_send_interrupt();
      if (iVar1 != 0) {
        _KernLockAcquire(*(undefined4 *)(iVar2 + 0x30));
        *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) & 0x7fffffff | 0x40000000;
        _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
        _calloutEntryDispatch(iVar2 + 0x38);
      }
    }
    else {
      _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
    }
  }
  return CONCAT44(param_2,iVar2);
}

