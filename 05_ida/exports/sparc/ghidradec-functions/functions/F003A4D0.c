
/* WARNING: Removing unreachable block (ram,0xf003a5c8) */
/* WARNING: Removing unreachable block (ram,0xf003a56c) */
/* WARNING: Removing unreachable block (ram,0xf003a518) */
/* WARNING: Removing unreachable block (ram,0xf003a548) */
/* WARNING: Removing unreachable block (ram,0xf003a590) */
/* WARNING: Removing unreachable block (ram,0xf003a620) */
/* WARNING: Removing unreachable block (ram,0xf003a4e4) */

undefined8 _nfs_svc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
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
  undefined uStack_1d;
  uint uStack_1c;
  
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
  iVar1 = **(int **)(dword_F0133DDC + 0x24);
  _getsock();
  if (iVar1 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 9;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x18);
    iVar1 = iVar2;
    _soreserve(iVar2,_nfs_chars,_nfs_chars + 0x20);
    if (iVar1 == 0) {
      _svckudp_create(iVar2,0x801);
      uStack_1c = 2;
      do {
        _svc_register(iVar2,0x186a3,uStack_1c,sub_F003BCD8,0);
        uStack_1c = uStack_1c + 1;
      } while (uStack_1c < 3);
      iVar1 = dword_F0133DDC + 0x28;
      _setjmp();
      if (iVar1 != 0) {
        _nfsd_count = _nfsd_count + -1;
        if (_nfsd_count == 0) {
          uStack_1c = 2;
          do {
            _svc_unregister(0x186a3,uStack_1c);
            uStack_1c = uStack_1c + 1;
          } while (uStack_1c < 3);
        }
        (**(code **)(*(int *)(iVar2 + 8) + 0x14))();
                    /* WARNING: Subroutine does not return */
        *(undefined *)(dword_F0133DDC + 0x38) = 4;
        _exit(0);
      }
      _nfsd_count = _nfsd_count + 1;
      _svc_run(iVar2);
    }
    else {
      uStack_1d = (undefined)iVar1;
      *(undefined *)(dword_F0133DDC + 0x38) = uStack_1d;
    }
  }
  return CONCAT44(param_2,param_1);
}
