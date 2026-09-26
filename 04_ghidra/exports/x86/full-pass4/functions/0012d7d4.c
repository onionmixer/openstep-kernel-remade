/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012d7d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0012d7d4(int param_1,int param_2)

{
  uint uVar1;
  in_addr iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  boolean_t bVar6;
  size_t *psVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined **local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined **)0x0;
  local_18 = 0;
  local_1c = 0;
  local_24 = 0;
  __svstat = __svstat + 1;
  local_20 = 0;
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 0x12) {
    if (*(int *)(param_1 + 4) != 2) {
      uVar12 = 2;
      uVar11 = 2;
      uVar10 = *(undefined4 *)(param_1 + 0x1c);
      _svcerr_progvers();
      local_20 = 1;
      iVar2.s_addr = *(int *)(param_1 + 0x1c) + 0x14;
      pcVar3 = _inet_ntoa(iVar2);
      _printf(s_nfs_server__bad_version_number_f_001dc1cd,pcVar3,iVar2.s_addr,uVar10,uVar11,uVar12);
      goto LAB_0012dadf;
    }
    local_14 = &_rfsdisptab + uVar1 * 6;
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    if (_rfssize == 0) {
      local_34 = &_nfs_portmon;
      local_2c = 0;
      do {
        puVar8 = (undefined4 *)((int)&_rfsdisptab + local_2c);
        if (puVar8 < local_34) {
          psVar7 = (size_t *)(&DAT_001dc004 + local_2c);
          do {
            if ((int)_rfssize < (int)psVar7[-2]) {
              _rfssize = psVar7[-2];
            }
            if ((int)_rfssize < (int)*psVar7) {
              _rfssize = *psVar7;
            }
            psVar7 = psVar7 + 6;
            puVar8 = puVar8 + 6;
          } while (puVar8 < local_34);
        }
        local_34 = local_34 + 0x6c;
        local_2c = local_2c + 0x1b0;
      } while ((int)local_34 < 0x1dc1a5);
    }
    if (_rfsfreesp == (undefined4 *)0x0) {
      iVar5 = _kalloc(_rfssize + 4);
      local_c = (undefined4 *)(iVar5 + 4);
    }
    else {
      local_c = _rfsfreesp;
      _rfsfreesp = (undefined4 *)*_rfsfreesp;
    }
    _bzero(local_c,_rfssize);
    iVar4 = (**(code **)(*(int *)(param_2 + 8) + 8))
                      (param_2,(&PTR__xdr_void_001dbff8)[uVar1 * 6],local_c);
    iVar5 = param_2;
    if (iVar4 != 0) {
      if (uVar1 != 0) {
        local_1c = _crget();
        local_18 = *(undefined4 *)(_active_u + 0x1c);
        *(int *)(_active_u + 0x1c) = local_1c;
        local_24 = _findexport(local_c,local_c + 5);
        if ((local_24 != 0) && (iVar4 = FUN_0012dcd8(local_24,param_1,local_1c), iVar4 == 0)) {
          _svcerr_weakauth();
          iVar2.s_addr = *(int *)(param_1 + 0x1c) + 0x14;
          pcVar3 = _inet_ntoa(iVar2);
          pcVar9 = s_nfs_server__weak_authentication__001dc216;
          goto LAB_0012d9ff;
        }
      }
      if (_rfssize == 0) {
        local_34 = &_nfs_portmon;
        local_28 = 0;
        do {
          puVar8 = (undefined4 *)((int)&_rfsdisptab + local_28);
          if (puVar8 < local_34) {
            psVar7 = (size_t *)(&DAT_001dc004 + local_28);
            do {
              if ((int)_rfssize < (int)psVar7[-2]) {
                _rfssize = psVar7[-2];
              }
              if ((int)_rfssize < (int)*psVar7) {
                _rfssize = *psVar7;
              }
              psVar7 = psVar7 + 6;
              puVar8 = puVar8 + 6;
            } while (puVar8 < local_34);
          }
          local_34 = local_34 + 0x6c;
          local_28 = local_28 + 0x1b0;
        } while ((int)local_34 < 0x1dc1a5);
      }
      if (_rfsfreesp == (undefined4 *)0x0) {
        iVar5 = _kalloc(_rfssize + 4);
        local_10 = (undefined4 *)(iVar5 + 4);
      }
      else {
        local_10 = _rfsfreesp;
        _rfsfreesp = (undefined4 *)*_rfsfreesp;
      }
      _bzero(local_10,_rfssize);
      *(int *)(&DAT_001eeea8 + uVar1 * 4) = *(int *)(&DAT_001eeea8 + uVar1 * 4) + 1;
      (*(code *)*local_14)(local_c,local_10,local_24,param_1);
      goto LAB_0012dadf;
    }
    _svcerr_decode();
    iVar2.s_addr = *(int *)(param_1 + 0x1c) + 0x14;
    pcVar3 = _inet_ntoa(iVar2);
    pcVar9 = s_nfs_server__bad_getargs_from__s_001dc1f5;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x1c);
    _svcerr_noproc();
    iVar2.s_addr = *(int *)(param_1 + 0x1c) + 0x14;
    pcVar3 = _inet_ntoa(iVar2);
    pcVar9 = s_nfs_server__bad_proc_number_from_001dc1a8;
  }
LAB_0012d9ff:
  local_20 = 1;
  _printf(pcVar9,pcVar3,iVar2.s_addr,iVar5);
LAB_0012dadf:
  if ((local_14 != (undefined **)0x0) &&
     (iVar5 = (**(code **)(*(int *)(param_2 + 8) + 0x10))(param_2,local_14[1],local_c), iVar5 == 0))
  {
    pcVar3 = _inet_ntoa((in_addr)(*(int *)(param_1 + 0x1c) + 0x14));
    _printf(s_nfs_server__bad_freeargs_from__s_001dc24d,pcVar3);
    local_20 = local_20 + 1;
  }
  if (local_c != (undefined4 *)0x0) {
    *local_c = _rfsfreesp;
    _rfsfreesp = local_c;
  }
  if ((local_20 == 0) && (bVar6 = _svc_sendreply(), bVar6 == 0)) {
    pcVar3 = _inet_ntoa((in_addr)(*(int *)(param_1 + 0x1c) + 0x14));
    _printf(s_nfs_server__bad_sendreply_from___001dc26f,pcVar3);
    local_20 = 1;
  }
  if (local_10 != (undefined4 *)0x0) {
    if ((code *)local_14[5] != FUN_0012ea30) {
      (*(code *)local_14[5])(local_10);
    }
    *local_10 = _rfsfreesp;
    _rfsfreesp = local_10;
  }
  if (local_1c != 0) {
    *(undefined4 *)(_active_u + 0x1c) = local_18;
    _crfree(local_1c);
  }
  _DAT_001eeea4 = _DAT_001eeea4 + local_20;
  return;
}

