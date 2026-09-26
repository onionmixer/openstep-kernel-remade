/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fdec */

int FUN_0012fdec(int param_1,int *param_2,char *param_3)

{
  byte *pbVar1;
  short *psVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int local_16c;
  int local_168;
  char local_164 [32];
  undefined1 local_144 [4];
  char *local_140;
  undefined1 local_138 [32];
  char local_118 [260];
  undefined1 local_14 [16];
  
  _getfsname(&DAT_001dc5c0,param_3);
  _pn_alloc(local_144);
  pcVar4 = local_140;
  bVar3 = false;
  while( true ) {
    pcVar6 = &DAT_001dc5c5;
    if (*param_3 != '\0') {
      pcVar6 = param_3;
    }
    iVar5 = FUN_001306a8(pcVar6,local_118,local_14,pcVar4);
    if (iVar5 != 0x3c) break;
    if (!bVar3) {
      pcVar6 = &DAT_001dc5ca;
      if (*param_3 != '\0') {
        pcVar6 = param_3;
      }
      _printf(PTR_s_No_bootparam_server_responding_t_001dc5bc,pcVar6);
      bVar3 = true;
    }
  }
  if (iVar5 == 0) {
    if (bVar3) {
      _printf(s_Bootparam_response_received_001dc5f7);
    }
    iVar5 = FUN_001308b0(local_14,local_118,pcVar4,local_138);
    if (iVar5 == 0) {
      iVar5 = FUN_00130d00(&local_168,param_1,local_14,local_138,local_118,0,0xffffffff,0);
      if (iVar5 == 0) {
        iVar5 = _vfs_add(0,param_1,0);
        if (iVar5 == 0) {
          *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x60) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 36000;
          *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x68) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 36000;
          pbVar1 = (byte *)(*(int *)(param_1 + 0x128) + 0x14);
          *pbVar1 = *pbVar1 | 0x20;
          _vfs_unlock(*(undefined4 *)(local_168 + 0x24));
          *param_2 = local_168;
          pcVar6 = _strcpy(param_3,local_118);
          *pcVar6 = ':';
          _strcpy(pcVar6 + 1,pcVar4);
          local_164[0] = '\0';
          _getfsname(s_private_001dc63c,local_164);
          bVar3 = false;
          while( true ) {
            pcVar6 = s_private_001dc644;
            if (local_164[0] != '\0') {
              pcVar6 = local_164;
            }
            iVar5 = FUN_001306a8(pcVar6,local_118,local_14,pcVar4);
            if (iVar5 != 0x3c) break;
            if (!bVar3) {
              pcVar6 = s_private_001dc64c;
              if (local_164[0] != '\0') {
                pcVar6 = local_164;
              }
              _printf(PTR_s_No_bootparam_server_responding_t_001dc5bc,pcVar6);
              bVar3 = true;
            }
          }
          if (iVar5 == 0) {
            if (bVar3) {
              _printf(s_Bootparam_response_received_001dc6a2);
            }
            pcVar6 = _index(pcVar4,0x40);
            if (pcVar6 == (char *)0x0) {
              pcVar6 = s__private_001dc6bf;
            }
            else {
              *pcVar6 = '\0';
              pcVar6 = pcVar6 + 1;
            }
            iVar5 = FUN_001308b0(local_14,local_118,pcVar4,local_138);
            if (iVar5 == 0) {
              iVar5 = (**(code **)(*(int *)(_rootvfs + 4) + 8))(_rootvfs,&_rootdir);
              if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
                _panic(s_nfs_mountroot__can_t_find_root_v_001dc6f3);
              }
              *(undefined4 *)(_active_u + 0x160) = _rootdir;
              psVar2 = (short *)(*(int *)(_active_u + 0x160) + 6);
              *psVar2 = *psVar2 + 1;
              *(undefined4 *)(_active_u + 0x164) = 0;
              iVar5 = _lookupname(pcVar6,1,1,0,&local_16c);
              if ((iVar5 == 0) && (local_16c != 0)) {
                _vn_rele(*(undefined4 *)(_active_u + 0x160));
                _vn_rele(_rootdir);
                _dnlc_purge();
                puVar7 = (undefined4 *)_kalloc(300);
                *puVar7 = 0;
                puVar7[1] = &_nfs_vfsops;
                puVar7[3] = 0;
                puVar7[7] = 0;
                puVar7[0x4a] = 0;
                puVar7[0x48] = 0;
                *(undefined2 *)(puVar7 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
                iVar5 = FUN_00130d00(&local_168,puVar7,local_14,local_138,local_118,0,0xffffffff,0);
                if (iVar5 == 0) {
                  iVar5 = _vfs_add(local_16c,puVar7,0);
                  if (iVar5 == 0) {
                    *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 6000;
                    *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 6000;
                    _strncpy((char *)(param_1 + 0x20),local_140,0xff);
                    _vfs_unlock(*(undefined4 *)(local_168 + 0x24));
                    _nfs_netboot_prealloc(*(undefined4 *)(param_1 + 0x128));
                    _pn_free(local_144);
                    iVar5 = 0;
                  }
                  else {
                    FUN_00130f38(puVar7);
                    _pn_free(local_144);
                    _kfree(puVar7,300);
                  }
                }
                else {
                  _pn_free(local_144);
                  _kfree(puVar7,300);
                }
              }
              else {
                _printf(s_nfs_mountroot__no_place_to_mount_001dc718);
                _vn_rele(*(undefined4 *)(_active_u + 0x160));
                _pn_free(local_144);
              }
            }
            else {
              _pn_free(local_144);
              _printf(s_mount_private__s__s_failed__rpc_s_001dc6c8,local_118,pcVar4,iVar5);
            }
          }
          else {
            if (iVar5 == 0x16) {
              _printf(s_Using__private_from_root_mount_p_001dc654);
              iVar5 = 0;
            }
            else {
              _printf(s_RPC_error_during_bootparam_reque_001dc67a,iVar5);
            }
            _pn_free(local_144);
          }
        }
        else {
          _pn_free(local_144);
        }
      }
      else {
        _pn_free(local_144);
      }
    }
    else {
      _pn_free(local_144);
      _printf(s_mount_root__s__s_failed__rpc_sta_001dc614,local_118,pcVar4,iVar5);
    }
  }
  else {
    _printf(s_RPC_error_during_bootparam_reque_001dc5cf,iVar5);
    _pn_free(local_144);
  }
  return iVar5;
}

