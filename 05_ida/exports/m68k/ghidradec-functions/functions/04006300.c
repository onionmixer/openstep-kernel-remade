
undefined4 _cloneproc(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  sword *psVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x66) + 0x30);
  do {
    _mpid = _mpid + 1;
    while( true ) {
      if (29999 < _mpid) {
        _mpid = 100;
        dword_40AE232 = 0;
      }
      if (_mpid < dword_40AE232) break;
      bVar4 = false;
      dword_40AE232 = 30000;
      iVar5 = _allproc;
      while( true ) {
        while (iVar5 == 0) {
          if (bVar4) goto loc_40063D2;
          bVar4 = true;
          iVar5 = _zombproc;
        }
        if (((_mpid == *(sword *)(iVar5 + 0x30)) || (_mpid == *(sword *)(iVar5 + 0x2e))) &&
           (iVar6 = _mpid + 1, iVar1 = _mpid + 1, _mpid = iVar6, dword_40AE232 <= iVar1)) break;
        iVar6 = (int)*(sword *)(iVar5 + 0x30);
        if ((_mpid < iVar6) && (iVar6 < dword_40AE232)) {
          dword_40AE232 = iVar6;
        }
        iVar6 = (int)*(sword *)(iVar5 + 0x2e);
        if ((_mpid < iVar6) && (iVar6 < dword_40AE232)) {
          dword_40AE232 = iVar6;
        }
        iVar5 = *(int *)(iVar5 + 8);
      }
    }
loc_40063D2:
    iVar5 = _insert_posix_proc(param_3,_mpid);
    if (iVar5 != 0) {
      iVar5 = _freeproc;
      if (_freeproc == 0) {
        iVar5 = _getproc();
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNoProcs);
        }
        *(int *)(iVar5 + 8) = _freeproc;
      }
      _freeproc = *(undefined4 *)(iVar5 + 8);
      *(undefined *)(iVar5 + 0x13) = 4;
      *(undefined4 *)(iVar5 + 0x5e) = 0;
      *(undefined4 *)(iVar5 + 0x5a) = 0;
      *(uint *)(iVar5 + 0x28) = *(uint *)(param_1 + 0x28) & 0x2108000 | 1;
      *(undefined2 *)(iVar5 + 0x2c) = *(undefined2 *)(param_1 + 0x2c);
      *(uint *)(iVar5 + 0x28) = *(uint *)(param_1 + 0x28) & 0x40000000 | *(uint *)(iVar5 + 0x28);
      *(uint *)(iVar5 + 0x16) =
           *(uint *)(iVar5 + 0x16) & 0xbfffffff |
           ((*(int *)(param_1 + 0x16) << 1) >> 0x1f & 1U) << 0x1e;
      iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(iVar6 + 4);
      *(undefined2 *)(param_3 + 6) = *(undefined2 *)(iVar6 + 6);
      *(undefined2 *)(param_3 + 8) = *(undefined2 *)(iVar6 + 8);
      *(undefined4 *)(param_3 + 0xe) = *(undefined4 *)(iVar6 + 0xe);
      *(byte *)(param_3 + 0x16) = *(byte *)(param_3 + 0x16) & 0x3f;
      *(undefined4 *)(param_3 + 0x12) = 0;
      *(undefined2 *)(iVar5 + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
      *(undefined *)(iVar5 + 0x15) = *(undefined *)(param_1 + 0x15);
      *(undefined2 *)(iVar5 + 0x30) = *(undefined2 *)(param_3 + 2);
      *(undefined2 *)(iVar5 + 0x32) = *(undefined2 *)(param_1 + 0x30);
      *(int *)(iVar5 + 0x42) = param_1;
      *(undefined4 *)(iVar5 + 0x4a) = *(undefined4 *)(param_1 + 0x46);
      if (*(int *)(param_1 + 0x46) != 0) {
        *(int *)(*(int *)(param_1 + 0x46) + 0x4e) = iVar5;
      }
      *(undefined4 *)(iVar5 + 0x4e) = 0;
      *(undefined4 *)(iVar5 + 0x46) = 0;
      *(int *)(param_1 + 0x46) = iVar5;
      *(undefined *)(iVar5 + 0x14) = 0;
      *(undefined *)(iVar5 + 0x12) = 0;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(iVar5 + 0x7a) = 0;
      *(undefined4 *)(iVar5 + 0x7e) = 0;
      *(undefined2 *)(iVar5 + 0x34) = 0;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      *(undefined *)(iVar5 + 0x17) = 0;
      *(byte *)(iVar5 + 0x16) = *(byte *)(iVar5 + 0x16) & 0x7f;
      _pidhash_enter(iVar5);
      if (*(int *)(iVar8 + 0x156) != 0) {
        psVar3 = (sword *)(*(int *)(iVar8 + 0x156) + 6);
        *psVar3 = *psVar3 + 1;
      }
      if (*(int *)(iVar8 + 0x15a) != 0) {
        psVar3 = (sword *)(*(int *)(iVar8 + 0x15a) + 6);
        *psVar3 = *psVar3 + 1;
      }
      **(sword **)(iVar8 + 0x1a) = **(sword **)(iVar8 + 0x1a) + 1;
      *(word *)(param_1 + 0x2a) = *(word *)(param_1 + 0x2a) | 0x100;
      *(undefined4 *)(iVar5 + 0x72) = 0;
      *(undefined4 *)(iVar5 + 0x76) = 0;
      uVar7 = _procdup(iVar5,param_1);
      for (iVar8 = 0; iVar8 <= *(int *)(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x14e);
          iVar8 = iVar8 + 1) {
        iVar1 = *(int *)(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x146);
        iVar2 = *(int *)(iVar1 + iVar8 * 4);
        if (iVar2 != 0) {
          if (iVar2 == -0x10000) {
            *(undefined4 *)(iVar1 + iVar8 * 4) = 0;
          }
          else {
            *(sword *)(iVar2 + 0xe) = *(sword *)(iVar2 + 0xe) + 1;
          }
        }
      }
      _lock_init(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x1e,1);
      _uarea_init(uVar7);
      *(undefined4 *)(param_3 + 10) = *(undefined4 *)(iVar6 + 10);
      *(int *)(iVar6 + 10) = iVar5;
      *(int *)(iVar5 + 8) = _allproc;
      *(int *)(_allproc + 0xc) = iVar5 + 8;
      *(int **)(iVar5 + 0xc) = &_allproc;
      _allproc = iVar5;
      *(undefined *)(iVar5 + 0x13) = 3;
      *(word *)(param_1 + 0x2a) = *(word *)(param_1 + 0x2a) & 0xfeff;
      return uVar7;
    }
  } while( true );
}
