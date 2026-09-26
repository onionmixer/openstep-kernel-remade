/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cffc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _nfs_svc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_1c;
  undefined4 local_18;
  
  iVar2 = _getsock(**(undefined4 **)(DAT_001e875c + 0x24));
  if (iVar2 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 0x18);
    iVar2 = _soreserve(uVar1,_nfs_chars,_nfs_chars + 0x20);
    if (iVar2 == 0) {
      iVar2 = _svckudp_create(uVar1,0x801);
      local_18 = 2;
      do {
        _svc_register();
        local_18 = local_18 + 1;
      } while (local_18 < 3);
      iVar3 = _set_label((int *)(DAT_001e875c + 0x28));
      if (iVar3 != 0) {
        __nfsd_count = __nfsd_count + -1;
        if (__nfsd_count == 0) {
          local_18 = 2;
          do {
            _svc_unregister();
            local_18 = local_18 + 1;
          } while (local_18 < 3);
        }
        (**(code **)(*(int *)(iVar2 + 8) + 0x14))(iVar2);
        *(undefined1 *)(DAT_001e875c + 0x68) = 4;
                    /* WARNING: Subroutine does not return */
        _exit(0);
      }
      __nfsd_count = __nfsd_count + 1;
      _svc_run();
    }
    else {
      local_1c = (undefined1)iVar2;
      *(undefined1 *)(DAT_001e875c + 0x68) = local_1c;
    }
  }
  return;
}

