
/* WARNING: Removing unreachable block (ram,0xf00a93cc) */
/* WARNING: Removing unreachable block (ram,0xf00a93b0) */
/* WARNING: Removing unreachable block (ram,0xf00a9378) */
/* WARNING: Removing unreachable block (ram,0xf00a9310) */
/* WARNING: Removing unreachable block (ram,0xf00a92d8) */
/* WARNING: Removing unreachable block (ram,0xf00a93c0) */
/* WARNING: Removing unreachable block (ram,0xf00a92c8) */
/* WARNING: Removing unreachable block (ram,0xf00a92e8) */

undefined8 _traceback(uint param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
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
  if ((_panicstr == 0) ||
     (iVar3 = dword_F011BC7C + 1, bVar1 = dword_F011BC7C < 1, dword_F011BC7C = iVar3, bVar1)) {
    if ((param_1 & 7) == 0) {
      _flush_windows();
      uVar4 = (param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f);
      _printf(aBeginTraceback,param_1);
      if ((param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f) == uVar4) {
        uVar2 = *(uint *)(param_1 + 0x38);
        while (param_1 != uVar2) {
          _printf(aCalledFromXFpX,*(undefined4 *)(param_1 + 0x3c),uVar2,
                  *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                  *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                  *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
          param_1 = *(uint *)(param_1 + 0x38);
          if ((param_1 == 0) || ((param_1 - 1) + _page_size >> ((byte)_page_shift & 0x1f) != uVar4))
          goto loc_F00A93B0;
          uVar2 = *(uint *)(param_1 + 0x38);
        }
        _printf(aFpLoopAtX,param_1);
      }
loc_F00A93B0:
      _printf(aEndTraceback);
      _vac_flush(_pmsgbuf,0x1000);
      _us_spin(2000000);
    }
    else {
      _printf(aTracebackMisal,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
