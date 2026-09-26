/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001069a8 */

undefined4 _cloneproc(int param_1,undefined4 param_2,undefined2 *param_3)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_10;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x68) + 0x38);
  do {
    _mpid = _mpid + 1;
    while( true ) {
      if (29999 < _mpid) {
        _mpid = 100;
        DAT_001da86c = 0;
      }
      if (_mpid < DAT_001da86c) break;
      bVar4 = false;
      DAT_001da86c = 30000;
      iVar5 = _allproc;
      while( true ) {
        while (iVar5 == 0) {
          if (bVar4) goto LAB_00106a84;
          bVar4 = true;
          iVar5 = _zombproc;
        }
        if (((*(short *)(iVar5 + 0x30) == _mpid) || (*(short *)(iVar5 + 0x2e) == _mpid)) &&
           (_mpid = _mpid + 1, DAT_001da86c <= _mpid)) break;
        iVar6 = (int)*(short *)(iVar5 + 0x30);
        if ((_mpid < iVar6) && (iVar6 < DAT_001da86c)) {
          DAT_001da86c = iVar6;
        }
        iVar6 = (int)*(short *)(iVar5 + 0x2e);
        if ((_mpid < iVar6) && (iVar6 < DAT_001da86c)) {
          DAT_001da86c = iVar6;
        }
        iVar5 = *(int *)(iVar5 + 8);
      }
    }
LAB_00106a84:
    iVar5 = _insert_posix_proc(param_3,_mpid);
    if (iVar5 != 0) {
      iVar5 = _freeproc;
      if (_freeproc == 0) {
        iVar5 = _getproc();
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_no_procs_001da870);
        }
        *(int *)(iVar5 + 8) = _freeproc;
      }
      _freeproc = *(undefined4 *)(iVar5 + 8);
      *(undefined1 *)(iVar5 + 0x13) = 4;
      *(undefined4 *)(iVar5 + 0x60) = 0;
      *(undefined4 *)(iVar5 + 0x5c) = 0;
      *(uint *)(iVar5 + 0x28) =
           CONCAT31((uint3)((uint)*(undefined4 *)(param_1 + 0x28) >> 8) & 0x21080,1);
      *(undefined2 *)(iVar5 + 0x2c) = *(undefined2 *)(param_1 + 0x2c);
      *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | *(uint *)(param_1 + 0x28) & 0x40000000;
      *(byte *)(iVar5 + 0x16) = *(byte *)(iVar5 + 0x16) & 0xfd | *(byte *)(param_1 + 0x16) & 2;
      iVar6 = _get_posix_proc((int)*(short *)(param_1 + 0x30));
      param_3[2] = *(undefined2 *)(iVar6 + 4);
      param_3[3] = *(undefined2 *)(iVar6 + 6);
      param_3[4] = *(undefined2 *)(iVar6 + 8);
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar6 + 0x10);
      *(byte *)(param_3 + 0xc) = *(byte *)(param_3 + 0xc) & 0xfc;
      *(undefined4 *)(param_3 + 10) = 0;
      *(undefined2 *)(iVar5 + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
      *(undefined1 *)(iVar5 + 0x15) = *(undefined1 *)(param_1 + 0x15);
      *(undefined2 *)(iVar5 + 0x30) = *param_3;
      *(undefined2 *)(iVar5 + 0x32) = *(undefined2 *)(param_1 + 0x30);
      *(int *)(iVar5 + 0x44) = param_1;
      *(undefined4 *)(iVar5 + 0x4c) = *(undefined4 *)(param_1 + 0x48);
      if (*(int *)(param_1 + 0x48) != 0) {
        *(int *)(*(int *)(param_1 + 0x48) + 0x50) = iVar5;
      }
      *(undefined4 *)(iVar5 + 0x50) = 0;
      *(undefined4 *)(iVar5 + 0x48) = 0;
      *(int *)(param_1 + 0x48) = iVar5;
      *(undefined1 *)(iVar5 + 0x14) = 0;
      *(undefined1 *)(iVar5 + 0x12) = 0;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(iVar5 + 0x7c) = 0;
      *(undefined4 *)(iVar5 + 0x80) = 0;
      *(undefined2 *)(iVar5 + 0x34) = 0;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      *(undefined1 *)(iVar5 + 0x17) = 0;
      *(byte *)(iVar5 + 0x16) = *(byte *)(iVar5 + 0x16) & 0xfe;
      _pidhash_enter(iVar5);
      if (*(int *)(iVar2 + 0x160) != 0) {
        psVar1 = (short *)(*(int *)(iVar2 + 0x160) + 6);
        *psVar1 = *psVar1 + 1;
      }
      if (*(int *)(iVar2 + 0x164) != 0) {
        psVar1 = (short *)(*(int *)(iVar2 + 0x164) + 6);
        *psVar1 = *psVar1 + 1;
      }
      **(short **)(iVar2 + 0x1c) = **(short **)(iVar2 + 0x1c) + 1;
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x100;
      *(undefined4 *)(iVar5 + 0x70) = 0;
      *(undefined4 *)(iVar5 + 0x74) = 0;
      *(undefined4 *)(iVar5 + 0x78) = 0;
      uVar7 = _procdup(iVar5,param_1);
      for (local_10 = 0; local_10 <= *(int *)(*(int *)(*(int *)(iVar5 + 0x68) + 0x38) + 0x158);
          local_10 = local_10 + 1) {
        iVar2 = *(int *)(*(int *)(*(int *)(iVar5 + 0x68) + 0x38) + 0x150);
        iVar3 = *(int *)(iVar2 + local_10 * 4);
        if (iVar3 != 0) {
          if (iVar3 == -0x10000) {
            *(undefined4 *)(iVar2 + local_10 * 4) = 0;
          }
          else {
            *(short *)(iVar3 + 0xe) = *(short *)(iVar3 + 0xe) + 1;
          }
        }
      }
      _lock_init(*(int *)(*(int *)(iVar5 + 0x68) + 0x38) + 0x20,1);
      _uarea_init(uVar7);
      *(undefined4 *)(param_3 + 6) = *(undefined4 *)(iVar6 + 0xc);
      *(int *)(iVar6 + 0xc) = iVar5;
      *(int *)(iVar5 + 8) = _allproc;
      *(int *)(_allproc + 0xc) = iVar5 + 8;
      *(int **)(iVar5 + 0xc) = &_allproc;
      _allproc = iVar5;
      *(undefined1 *)(iVar5 + 0x13) = 3;
      _spl0();
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffeff;
      return uVar7;
    }
  } while( true );
}

