
void _nfs_svc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined uStack_19;
  uint uStack_18;
  
  iVar2 = _getsock(**(undefined4 **)(dword_40B57D4 + 0x24));
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 0x16);
    iVar2 = _soreserve(uVar1,_nfs_chars,_nfs_chars + 0x20);
    if (iVar2 == 0) {
      iVar2 = _svckudp_create(uVar1,0x801);
      uStack_18 = 2;
      do {
        _svc_register(iVar2,0x186a3,uStack_18,&loc_40282D8,0);
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < 3);
      iVar3 = _setjmp(dword_40B57D4 + 0x28);
      if (iVar3 != 0) {
        iVar3 = _nfsd_count + -1;
        bVar4 = _nfsd_count == 1;
        _nfsd_count = iVar3;
        if (bVar4) {
          uStack_18 = 2;
          do {
            _svc_unregister(0x186a3,uStack_18);
            uStack_18 = uStack_18 + 1;
          } while (uStack_18 < 3);
        }
        (**(code **)(*(int *)(iVar2 + 6) + 0x14))(iVar2);
        *(undefined *)(dword_40B57D4 + 100) = 4;
                    /* WARNING: Subroutine does not return */
        _exit(0);
      }
      _nfsd_count = _nfsd_count + 1;
                    /* WARNING: Subroutine does not return */
      _svc_run(iVar2);
    }
    uStack_19 = (undefined)iVar2;
    *(undefined *)(dword_40B57D4 + 100) = uStack_19;
  }
  return;
}

