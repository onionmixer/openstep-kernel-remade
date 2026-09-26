/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019621c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0019621c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((_kmId == 0) || (iVar1 = _kmId, DAT_001e7764 != 0)) {
    iVar1 = _objc_msgSend(param_1,PTR_s_new_001f9468);
  }
  uVar3 = 1;
  if (_DAT_0001114c != 0) {
    uVar3 = 2;
  }
  iVar2 = _objc_msgSend(iVar1,PTR_s_init_fb_mode__001f946c,1,uVar3);
  if (iVar2 == 0) {
    _IOLog(s_kmDevice__continuing_with_bad_km_001e38b4);
    _objc_msgSend(iVar1,PTR_s_free_001f921c);
    _kmId = 0;
  }
  return iVar2 != 0;
}

