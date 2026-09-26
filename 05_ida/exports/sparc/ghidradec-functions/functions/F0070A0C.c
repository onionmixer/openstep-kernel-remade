
/* WARNING: Removing unreachable block (ram,0xf0070b14) */
/* WARNING: Removing unreachable block (ram,0xf0070af4) */
/* WARNING: Removing unreachable block (ram,0xf0070ad0) */
/* WARNING: Removing unreachable block (ram,0xf0070a7c) */
/* WARNING: Removing unreachable block (ram,0xf0070a28) */
/* WARNING: Removing unreachable block (ram,0xf0070a74) */
/* WARNING: Removing unreachable block (ram,0xf0070aa4) */
/* WARNING: Removing unreachable block (ram,0xf0070abc) */
/* WARNING: Removing unreachable block (ram,0xf0070b0c) */
/* WARNING: Removing unreachable block (ram,0xf0070b1c) */
/* WARNING: Removing unreachable block (ram,0xf0070a10) */

undefined8 _kdp_raise_exception(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
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
  uVar1 = param_1;
  _kdp_intr_disbl();
  if (param_4 == 0) {
    _safe_prf(aKdpRaiseExcept);
  }
  if (param_1 != 6) {
    if ((6 < param_1) || (uVar2 = param_1, param_1 == 0)) {
      uVar2 = 0;
    }
    _safe_prf(aSExceptionXXX,*(undefined4 *)(unk_F01101A8 + uVar2 * 4),param_1,param_2,param_3);
  }
  _kdp_flush_cache();
  dword_F013C40C = param_4;
  if (dword_F012FF24 != 0) {
    _kdp_panic(aKdpRaiseExcept_0);
  }
  if (dword_F013C408 == 0) {
    sub_F0070810();
  }
  else {
    sub_F0070944(param_1,param_2,param_3);
  }
  if (dword_F013C408 != 0) {
    DAT_f013c410._0_4_ = 1;
    sub_F00706FC(param_4);
    if (dword_F013C408 == 0) {
      _safe_prf(aRemoteDebugger);
    }
  }
  _kdp_flush_cache();
  _kdp_intr_enbl(uVar1);
  return CONCAT44(param_2,&_kdp);
}
