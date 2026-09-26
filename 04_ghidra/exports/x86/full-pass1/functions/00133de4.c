/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00133de4 */

undefined4 FUN_00133de4(int *param_1,int param_2,uint param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  short *psVar7;
  uint uVar8;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_10 = 0;
  iVar2 = param_1[0xc];
  if ((((_active_threads == _pageoutThread) && ((*(byte *)(iVar2 + 0x60) & 1) != 0)) &&
      (*(int *)(*(int *)(iVar2 + 0x68) + 0x188) != 0)) ||
     (iVar4 = _rlock_timeout(iVar2,5), iVar4 == 1)) {
    return 2;
  }
  uVar3 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24);
  psVar7 = *(short **)(*param_1 + 0x30);
  if (psVar7 == (short *)0x0) {
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
      _printf(s_NFS_failure_on_pageout__no_crede_001dcbea);
      _runlock(iVar2);
      return 2;
    }
    psVar7 = (short *)_active_u[7];
  }
  *psVar7 = *psVar7 + 1;
  if (*(int *)(iVar2 + 0x70) != 0) {
    _crfree(*(int *)(iVar2 + 0x70));
  }
  *(short **)(iVar2 + 0x70) = psVar7;
  while( true ) {
    uVar6 = param_4 % uVar3;
    uVar8 = param_3;
    if (uVar3 - uVar6 < param_3) {
      uVar8 = uVar3 - uVar6;
    }
    (**(code **)(param_1[7] + 0x50))(param_1,param_4 / uVar3,&local_8,&local_c);
    if (*(short *)(iVar2 + 0x62) != 0) {
      *(int *)(*param_1 + 0x34) = (int)*(short *)(iVar2 + 0x62);
      if (*(short *)(*param_1 + 4) == 0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
          _printf(s__s__d___001dcc12,_active_u + 2,(int)*(short *)(*_active_u + 0x30));
        }
        sVar1 = *(short *)(iVar2 + 0x62);
        if (sVar1 == 0x1c) {
          _printf(s_NFS_write_error_on_pageout__devi_001dcc1b);
          *(undefined2 *)(iVar2 + 0x62) = 0;
        }
        else if (sVar1 == 0x46) {
          _printf(s_NFS_write_error_on_pageout__stal_001dcc44);
        }
        else {
          _printf(s_NFS_write_error__d_on_pageout_001dcc73,(int)sVar1);
        }
      }
      _runlock(iVar2);
      return 2;
    }
    if (local_c < 0) {
      _printf(s_NFS_mapping_error_on_pageout_001dcc92);
      _runlock(iVar2);
      return 2;
    }
    if (uVar3 == uVar8) {
      puVar5 = (uint *)_getblk(local_8,local_c,uVar8);
    }
    else {
      puVar5 = (uint *)_bread(local_8,local_c,uVar3);
    }
    if ((*puVar5 & 4) != 0) break;
    _copy_from_phys(param_2 + local_10,uVar6 + puVar5[8],uVar8);
    param_4 = param_4 + uVar8;
    if (*(uint *)(iVar2 + 0x98) < param_4) {
      *(uint *)(iVar2 + 0x98) = param_4;
    }
    param_3 = param_3 - uVar8;
    local_10 = local_10 + uVar8;
    *(byte *)(iVar2 + 0x60) = *(byte *)(iVar2 + 0x60) | 0x10;
    if (uVar3 == uVar6 + uVar8) {
      *puVar5 = *puVar5 | 0x400000;
      _bawrite(puVar5);
    }
    else {
      _bdwrite(puVar5);
    }
    if ((param_3 == 0) || (uVar8 == 0)) {
      _runlock(iVar2);
      return 0;
    }
  }
  *(int *)(*param_1 + 0x34) = (int)(short)puVar5[7];
  if (*(short *)(*param_1 + 4) == 0) {
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
      _printf(s__s__d___001dccb0,_active_u + 2,(int)*(short *)(*_active_u + 0x30));
    }
    if ((short)puVar5[7] == 0x46) {
      _printf(s_NFS_read_error_on_pageout__stale_001dccb9);
    }
    else {
      _printf(s_NFS_read_error__d_on_pageout_001dcce7,(int)(short)puVar5[7]);
    }
  }
  _brelse(puVar5);
  _runlock(iVar2);
  return 2;
}

