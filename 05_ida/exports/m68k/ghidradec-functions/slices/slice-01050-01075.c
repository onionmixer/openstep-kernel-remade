/* GHIDRADEC_FUNCTION index=1050 start=0x403cc0c */

void _ipc_bootstrap(void)

{
  _ipc_port_timestamp_data = 0;
  _ipc_space_zone = _zinit(0x40,_ipc_space_max << 6,0x40,0,aIpcSpaces);
  _zchange(_ipc_space_zone,0,0,1,0);
  _ipc_tree_entry_zone = _zinit(0x20,_ipc_tree_entry_max << 5,0x20,0,aIpcTreeEntries);
  _zchange(_ipc_tree_entry_zone,0,0,1,0);
  _ipc_object_zones = _zinit(0x48,_ipc_port_max * 0x48,0x48,0,aIpcPorts);
  _zchange(_ipc_object_zones,0,0,1,0);
  dword_40C21D4 = _zinit(0x14,_ipc_pset_max * 0x14,0x14,0,aIpcPortSets);
  _zchange(dword_40C21D4,0,0,1,0);
  _ipc_space_create_special(&_ipc_space_kernel);
  _ipc_space_create_special(&_ipc_space_reply);
  _ipc_table_init();
  _ipc_notify_init();
  _ipc_hash_init();
  _ipc_marequest_init();
  return;
}
/* GHIDRADEC_FUNCTION index=1051 start=0x403cd3c */

void _ipc_init(void)

{
  int iVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  iVar1 = _task_create(0,0,&_ipc_soft_task);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcInit);
  }
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task + 8);
  _ipc_kernel_map = _kmem_suballoc(_kernel_map,auStack_8,auStack_c,_ipc_kernel_map_size,1);
  _ipc_host_init();
  return;
}
/* GHIDRADEC_FUNCTION index=1052 start=0x403cda2 */

void _ipc_kmsg_enqueue(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = (int)param_2;
    *param_2 = (int)param_2;
    param_2[1] = (int)param_2;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 4);
    *param_2 = iVar1;
    param_2[1] = (int)puVar2;
    *(int **)(iVar1 + 4) = param_2;
    *puVar2 = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1053 start=0x403cdd8 */

int * _ipc_kmsg_dequeue(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (piVar1 == piVar2) {
      *param_1 = 0;
    }
    else {
      piVar3 = (int *)piVar1[1];
      *param_1 = (int)piVar2;
      piVar2[1] = (int)piVar3;
      *piVar3 = (int)piVar2;
    }
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=1054 start=0x403ce0e */

void _ipc_kmsg_rmqueue(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_2;
  piVar2 = (int *)param_2[1];
  if (param_2 == piVar1) {
    *param_1 = 0;
  }
  else {
    if (param_2 == (int *)*param_1) {
      *param_1 = (int)piVar1;
    }
    piVar1[1] = (int)piVar2;
    *piVar2 = (int)piVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1055 start=0x403ce44 */

int _ipc_kmsg_queue_next(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == *param_1) {
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1056 start=0x403ce5c */

void _ipc_kmsg_destroy(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(_active_threads + 0xa0);
  iVar1 = *piVar2;
  _ipc_kmsg_enqueue(piVar2,param_1);
  if (iVar1 == 0) {
    while (iVar1 = *piVar2, iVar1 != 0) {
      _ipc_kmsg_clean(iVar1);
      _ipc_kmsg_rmqueue(piVar2,iVar1);
      if (*(int *)(iVar1 + 8) < 1) {
        _ipc_kmsg_free(iVar1);
      }
      else {
        _kfree(iVar1,*(int *)(iVar1 + 8));
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1057 start=0x403cece */

void _ipc_kmsg_clean_body(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar4;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  bool bVar9;
  
  while (param_1 < param_2) {
    bVar4 = param_1[3] >> 3;
    if ((param_1[3] & 4) == 0) {
      uVar7 = (uint)*param_1;
      uVar3 = (uint)param_1[1];
      uVar6 = *(uint *)(param_1 + 2) >> 0x14;
      param_1 = param_1 + 4;
    }
    else {
      uVar7 = (uint)*(word *)(param_1 + 4);
      uVar3 = (uint)*(word *)(param_1 + 6);
      uVar6 = *(uint *)(param_1 + 8);
      param_1 = param_1 + 0xc;
    }
    uVar3 = uVar3 * uVar6 + 7 >> 3;
    bVar9 = 5 < uVar7 - 0x10;
    if (!bVar9) {
      if ((bVar4 & 1) == 0) {
        pbVar8 = *(byte **)param_1;
      }
      else {
        for (pbVar1 = param_1 + uVar6 * 4; pbVar8 = param_1, param_2 < pbVar1; pbVar1 = pbVar1 + -4)
        {
          uVar6 = uVar6 - 1;
        }
      }
      uVar5 = 0;
      if (uVar6 != 0) {
        do {
          iVar2 = *(int *)pbVar8;
          if ((iVar2 != 0) && (iVar2 != -1)) {
            _ipc_object_destroy(iVar2,uVar7);
          }
          pbVar8 = pbVar8 + 4;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar6);
      }
    }
    if ((bVar4 & 1) == 0) {
      if (uVar3 != 0) {
        if (bVar9) {
          _vm_deallocate(_ipc_soft_map,*(int *)param_1,uVar3);
        }
        else {
          _kfree(*(int *)param_1,uVar3);
        }
      }
      param_1 = param_1 + 4;
    }
    else {
      param_1 = param_1 + (uVar3 + 3 & 0xfffffffc);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1058 start=0x403cfea */

void _ipc_kmsg_clean(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) != 0) {
    _ipc_marequest_destroy(*(int *)(param_1 + 0xc));
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,uVar1 & 0xff);
  }
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar1 & 0xffff) >> 8);
  }
  if ((int)uVar1 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1059 start=0x403d066 */

void _ipc_kmsg_clean_partial(int param_1,byte *param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  
  uVar5 = *(uint *)(param_1 + 0x14);
  _ipc_object_destroy(*(undefined4 *)(param_1 + 0x1c),uVar5 & 0xff);
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar5 & 0xffff) >> 8);
  }
  _ipc_kmsg_clean_body(param_1 + 0x2c,param_2);
  if (param_3 != 0) {
    iVar2 = (uint)param_2[3] << 0x1c;
    if ((param_2[3] & 4) == 0) {
      uVar4 = (uint)*param_2;
      uVar3 = (uint)param_2[1];
      uVar5 = *(uint *)(param_2 + 2) >> 0x14;
      param_2 = param_2 + 4;
    }
    else {
      uVar4 = (uint)*(word *)(param_2 + 4);
      uVar3 = (uint)*(word *)(param_2 + 6);
      uVar5 = *(uint *)(param_2 + 8);
      param_2 = param_2 + 0xc;
    }
    uVar5 = uVar3 * uVar5 + 7 >> 3;
    bVar7 = 5 < uVar4 - 0x10;
    if (!bVar7) {
      pbVar6 = param_2;
      if (-1 < iVar2) {
        pbVar6 = *(byte **)param_2;
      }
      uVar3 = 0;
      if (param_4 != 0) {
        do {
          iVar1 = *(int *)pbVar6;
          if ((iVar1 != 0) && (iVar1 != -1)) {
            _ipc_object_destroy(iVar1,uVar4);
          }
          pbVar6 = pbVar6 + 4;
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_4);
      }
    }
    if ((-1 < iVar2) && (uVar5 != 0)) {
      if (bVar7) {
        _vm_deallocate(_ipc_soft_map,*(int *)param_2,uVar5);
      }
      else {
        _kfree(*(int *)param_2,uVar5);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1060 start=0x403d176 */

void _ipc_kmsg_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == -3) {
    _netipc_msg_release(param_1);
  }
  else if (iVar1 != -1) {
    _kfree(param_1,iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1061 start=0x403d1a8 */

undefined4 _ipc_kmsg_get(undefined4 param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _ipc_kmsg_cache;
  if (((param_2 < 0x18) || ((param_2 & 3) != 0)) || (0 < param_3)) {
    return 0x10000008;
  }
  if (param_2 < 0xed) {
    if (_ipc_kmsg_cache != 0) {
      _ipc_kmsg_cache = 0;
      goto loc_403D238;
    }
    iVar1 = _kalloc(0x100);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(undefined4 *)(iVar1 + 8) = 0x100;
  }
  else {
    iVar1 = _kalloc(param_2 + 0x14);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(uint *)(iVar1 + 8) = param_2 + 0x14;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
loc_403D238:
  *(undefined4 *)(iVar1 + 0x10) = 0;
  iVar2 = _copyinmsg(param_1,iVar1 + 0x14,param_3 + param_2);
  if (iVar2 == 0) {
    *(int *)(iVar1 + 0x10) = param_3;
    *(uint *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar3 = 0;
  }
  else {
    if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free(iVar1);
    }
    else {
      _kfree(iVar1,*(int *)(iVar1 + 8));
    }
    uVar3 = 0x10000002;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1062 start=0x403d286 */

undefined4 _ipc_kmsg_get_from_kernel(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _kalloc(param_2 + 0x14);
  if (iVar1 == 0) {
    uVar2 = 0x1000000d;
  }
  else {
    *(int *)(iVar1 + 8) = param_2 + 0x14;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    _bcopy(param_1,iVar1 + 0x14,param_3 + param_2);
    *(int *)(iVar1 + 0x10) = param_3;
    *(int *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1063 start=0x403d2ea */

undefined4 _ipc_kmsg_put(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0x10) = 0;
  iVar1 = _copyoutmsg(param_2 + 0x14,param_1,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x10004008;
  }
  if ((*(int *)(param_2 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
    _ipc_kmsg_cache = param_2;
  }
  else if (*(int *)(param_2 + 8) < 1) {
    _ipc_kmsg_free(param_2);
  }
  else {
    _kfree(param_2,*(int *)(param_2 + 8));
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1064 start=0x403d35c */

void _ipc_kmsg_put_to_kernel(undefined4 param_1,int param_2,undefined4 param_3)

{
  _bcopy(param_2 + 0x14,param_1,param_3);
  if (*(int *)(param_2 + 8) < 1) {
    _ipc_kmsg_free(param_2);
  }
  else {
    _kfree(param_2,*(int *)(param_2 + 8));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1065 start=0x403d39e */

undefined4 _ipc_kmsg_copyin_header(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iStack_20;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  uint uStack_8;
  
  uVar1 = *param_1;
  uVar10 = param_1[2];
  uVar2 = param_1[3];
  if (param_3 == 0) {
    uVar11 = uVar1 & 0xffff;
    if (uVar11 == 0x13) {
      if ((uVar2 == 0) && (*(int *)(param_2 + 4) != 0)) {
        if ((uVar10 >> 8 < *(uint *)(param_2 + 0x10)) &&
           ((puVar8 = (uint *)((uVar10 >> 8) * 0x10 + *(int *)(param_2 + 0xc)),
            (uVar10 << 0x18 | 0x10000) == (*puVar8 & 0xff010000) &&
            (piVar3 = (int *)puVar8[1], piVar3[1] < 0)))) {
          piVar3[6] = piVar3[6] + 1;
          *piVar3 = *piVar3 + 1;
          *param_1 = uVar1 & 0xbfff0000 | 0x11;
          param_1[2] = (uint)piVar3;
          return 0;
        }
      }
    }
    else if (uVar11 < 0x14) {
      if (((uVar11 == 0x12) && (uVar2 == 0)) && (*(int *)(param_2 + 4) != 0)) {
        iVar7 = *(int *)(param_2 + 0xc);
        uVar11 = uVar10 >> 8;
        if (((uVar11 < *(uint *)(param_2 + 0x10)) &&
            (puVar8 = (uint *)(iVar7 + uVar11 * 0x10),
            (uVar10 << 0x18 | 0x40000) == (*puVar8 & 0xff840000))) &&
           ((puVar8[2] == 0 && (uVar12 = puVar8[1], *(int *)(uVar12 + 4) < 0)))) {
          puVar8[2] = *(uint *)(iVar7 + 8);
          *(uint *)(iVar7 + 8) = uVar11;
          *puVar8 = uVar10 << 0x18;
          puVar8[1] = 0;
          *param_1 = uVar1 & 0xbfff0000 | 0x12;
          param_1[2] = uVar12;
          return 0;
        }
      }
    }
    else if ((uVar11 == 0x1513) && (*(int *)(param_2 + 4) != 0)) {
      if ((uVar10 >> 8 < *(uint *)(param_2 + 0x10)) &&
         (puVar8 = (uint *)(*(int *)(param_2 + 0xc) + (uVar10 >> 8) * 0x10),
         (uVar10 << 0x18 | 0x10000) == (*puVar8 & 0xff010000))) {
        piVar3 = (int *)puVar8[1];
        if (((uVar2 >> 8 < *(uint *)(param_2 + 0x10)) &&
            (puVar8 = (uint *)(*(int *)(param_2 + 0xc) + (uVar2 >> 8) * 0x10),
            (uVar2 << 0x18 | 0x20000) == (*puVar8 & 0xff020000))) &&
           (piVar4 = (int *)puVar8[1], piVar3[1] < 0)) {
          piVar3[6] = piVar3[6] + 1;
          *piVar3 = *piVar3 + 1;
          piVar4[7] = piVar4[7] + 1;
          *piVar4 = *piVar4 + 1;
          *param_1 = CONCAT22((sword)((uVar1 & 0xbfffffff) >> 0x10),0x1211);
          param_1[2] = (uint)piVar3;
          param_1[3] = (uint)piVar4;
          return 0;
        }
      }
    }
  }
  uVar11 = uVar1 & 0xff;
  uVar12 = (uVar1 & 0xbfffffff) >> 8 & 0xff;
  iStack_20 = 0;
  if (4 < uVar11 - 0x11) {
    return 0x10000010;
  }
  if (uVar12 == 0) {
    if (uVar2 != 0) {
      return 0x10000010;
    }
  }
  else if (4 < uVar12 - 0x11) {
    return 0x10000010;
  }
  if (*(int *)(param_2 + 4) != 0) {
    if (param_3 != 0) {
      iVar7 = _ipc_entry_lookup(param_2,param_3);
      if ((iVar7 == 0) || ((*(byte *)(iVar7 + 1) & 2) == 0)) {
        return 0x1000000b;
      }
      iStack_20 = *(int *)(iVar7 + 4);
    }
    if (uVar2 == uVar10) {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar2);
      if (puVar8 != (uint *)0x0) {
        iVar7 = _ipc_right_copyin_check(param_2,uVar2,puVar8,uVar12);
        if (iVar7 == 0) {
          return 0x10000009;
        }
        if ((uVar11 != 0x12) && (uVar12 != 0x12)) {
          if ((uVar11 - 0x14 < 2) || (uVar12 - 0x14 < 2)) {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,uVar11,0,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              _ipc_right_copyin(param_2,uVar2,puVar8,uVar12,1,&uStack_10,&iStack_14);
              goto loc_403D950;
            }
          }
          else if ((uVar11 == 0x13) && (uVar12 == 0x13)) {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,0x13,0,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              uStack_10 = _ipc_port_copy_send(uStack_8);
              iStack_14 = 0;
              goto loc_403D950;
            }
          }
          else if ((uVar11 == 0x11) && (uVar12 == 0x11)) {
            iVar7 = _ipc_right_copyin_two(param_2,uVar2,puVar8,&uStack_8,&iStack_c);
            if (iVar7 == 0) {
              if ((*puVar8 & 0x1f0000) == 0) {
                _ipc_entry_dealloc(param_2,uVar2,puVar8);
              }
              uStack_10 = uStack_8;
              iStack_14 = 0;
loc_403D950:
              if ((param_3 != 0) && (iStack_c == iStack_20)) {
                _ipc_port_release_sonce(iStack_c);
                iStack_c = 0;
              }
              if (iStack_c != 0) {
                _ipc_notify_port_deleted(iStack_c,uVar10);
              }
              if (iStack_14 != 0) {
                _ipc_notify_port_deleted(iStack_14,uVar2);
              }
              uVar10 = _ipc_object_copyin_type(uVar11);
              iVar7 = _ipc_object_copyin_type(uVar12);
              *param_1 = uVar10 | iVar7 << 8 | uVar1 & 0xbfff0000;
              param_1[2] = uStack_8;
              param_1[3] = uStack_10;
              return 0;
            }
          }
          else {
            iVar7 = _ipc_right_copyin(param_2,uVar2,puVar8,0x11,0,&uStack_8,&iStack_18);
            if (iVar7 == 0) {
              if ((*puVar8 & 0x1f0000) == 0) {
                _ipc_entry_dealloc(param_2,uVar2,puVar8);
              }
              uStack_10 = _ipc_port_copy_send(uStack_8);
              if (uVar11 == 0x11) {
                iStack_c = iStack_18;
                iStack_14 = 0;
              }
              else {
                iStack_c = 0;
                iStack_14 = iStack_18;
              }
              goto loc_403D950;
            }
          }
        }
      }
    }
    else if ((uVar2 == 0) || (uVar2 == 0xffffffff)) {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar10);
      if ((puVar8 != (uint *)0x0) &&
         (iVar7 = _ipc_right_copyin(param_2,uVar10,puVar8,uVar11,0,&uStack_8,&iStack_c), iVar7 == 0)
         ) {
        if ((*puVar8 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar10,puVar8);
        }
        iStack_14 = 0;
        uStack_10 = uVar2;
        goto loc_403D950;
      }
    }
    else {
      puVar8 = (uint *)_ipc_entry_lookup(param_2,uVar10);
      if (puVar8 != (uint *)0x0) {
        puVar9 = (uint *)_ipc_entry_lookup(param_2,uVar2);
        if (puVar9 == (uint *)0x0) {
          return 0x10000009;
        }
        iVar7 = _ipc_right_copyin_check(param_2,uVar2,puVar9,uVar12);
        if (iVar7 == 0) {
          return 0x10000009;
        }
        iVar7 = _ipc_right_copyin(param_2,uVar10,puVar8,uVar11,0,&uStack_8,&iStack_c);
        if (iVar7 == 0) {
          uVar5 = puVar9[1];
          if (uVar5 != 0) {
            _ipc_object_reference(uVar5);
          }
          iVar7 = _ipc_right_copyin(param_2,uVar2,puVar9,uVar12,1,&uStack_10,&iStack_14);
          if (iVar7 == 0) {
            if ((uVar5 != 0) && (uStack_10 == 0xffffffff)) {
              bVar6 = false;
              if ((-1 < *(int *)(uStack_8 + 4)) &&
                 (*(int *)(uStack_8 + 8) - *(int *)(uVar5 + 8) < 0)) {
                bVar6 = true;
              }
              if (bVar6) {
                _ipc_right_copyin_undo(param_2,uVar10,puVar8,uVar11,uStack_8,iStack_c);
                _ipc_right_copyin_undo(param_2,uVar2,puVar9,uVar12,uStack_10,iStack_14);
                if (iStack_c != 0) {
                  _ipc_notify_dead_name(iStack_c,uVar10);
                }
                _ipc_object_release(uVar5);
                return 0x10000003;
              }
            }
            if ((*puVar9 & 0x1f0000) == 0) {
              _ipc_entry_dealloc(param_2,uVar2,puVar9);
            }
          }
          else {
            uStack_10 = 0xffffffff;
            iStack_14 = 0;
          }
          if ((*puVar8 & 0x1f0000) == 0) {
            _ipc_entry_dealloc(param_2,uVar10,puVar8);
          }
          if (uVar5 != 0) {
            _ipc_object_release(uVar5);
          }
          goto loc_403D950;
        }
      }
    }
  }
  return 0x10000003;
}
/* GHIDRADEC_FUNCTION index=1066 start=0x403d9d2 */

int _ipc_kmsg_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  bool bVar4;
  uint *puVar5;
  int iVar6;
  byte bVar9;
  uint *puVar7;
  int iVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  bool bVar16;
  uint uStack_c;
  uint *puStack_8;
  
  iVar6 = _ipc_kmsg_copyin_header((int *)(param_1 + 0x14),param_2,param_4);
  if (iVar6 == 0) {
    if (*(int *)(param_1 + 0x14) < 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c);
      bVar4 = false;
      puVar3 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar15 = (uint *)(param_1 + 0x2c);
      while (puVar5 = puVar15, puVar5 < puVar3) {
        if ((uint)((int)puVar3 - (int)puVar5) < 4) {
loc_403DA92:
          _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
          return 0x10000008;
        }
        bVar9 = (byte)*puVar5 >> 2;
        if (((bVar9 & 1) != 0) && ((uint)((int)puVar3 - (int)puVar5) < 0xc)) goto loc_403DA92;
        iVar6 = (uint)(byte)*puVar5 << 0x1c;
        uVar10 = ((byte)*puVar5 & 3) >> 1;
        if ((bVar9 & 1) == 0) {
          uVar12 = (uint)*(byte *)puVar5;
          uVar11 = (uint)*(byte *)((int)puVar5 + 1);
          uVar13 = *(uint *)((int)puVar5 + 2) >> 0x14;
          puVar14 = puVar5 + 1;
        }
        else {
          uVar12 = (uint)*(word *)(puVar5 + 1);
          uVar11 = (uint)*(word *)((int)puVar5 + 6);
          uVar13 = puVar5[2];
          puVar14 = puVar5 + 3;
        }
        bVar16 = 5 < uVar12 - 0x10;
        if (((((!bVar16) && (uVar11 != 0x20)) ||
             (((bVar9 & 1) != 0 && ((*puVar5 & 0xfffffff0) != 0)))) || ((*puVar5 & 1) != 0)) ||
           ((uVar10 != 0 && (iVar6 < 0)))) {
          _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
          return 0x1000000f;
        }
        uVar11 = uVar11 * uVar13 + 7 >> 3;
        if (iVar6 < 0) {
          uVar10 = uVar11 + 3 & 0xfffffffc;
          if ((uint)((int)puVar3 - (int)puVar14) < uVar10) goto loc_403DA92;
          puVar15 = (uint *)(uVar10 + (int)puVar14);
          puVar7 = puVar14;
        }
        else {
          if ((uint)((int)puVar3 - (int)puVar14) < 4) goto loc_403DA92;
          uVar1 = *puVar14;
          if (uVar11 == 0) {
            puVar7 = (uint *)0x0;
          }
          else if (bVar16) {
            iVar6 = _vm_move(param_3,uVar1,_ipc_soft_map,uVar11,uVar10,&puStack_8);
            puVar7 = puStack_8;
            if (iVar6 != 0) goto loc_403DBF2;
          }
          else {
            puVar7 = (uint *)_kalloc(uVar11);
            if (puVar7 == (uint *)0x0) {
loc_403DBF2:
              _ipc_kmsg_clean_partial(param_1,puVar5,0,0);
              return 0x1000000c;
            }
            iVar6 = _copyinmap(param_3,uVar1,puVar7,uVar11);
            if ((iVar6 != 0) ||
               ((uVar10 != 0 && (iVar6 = _vm_deallocate(param_3,uVar1,uVar11), iVar6 != 0)))) {
              _kfree(puVar7,uVar11);
              goto loc_403DBF2;
            }
          }
          puVar15 = puVar14 + 1;
          *puVar14 = (uint)puVar7;
          bVar4 = true;
        }
        if (!bVar16) {
          iVar6 = _ipc_object_copyin_type(uVar12);
          if ((bVar9 & 1) == 0) {
            *(char *)puVar5 = (char)iVar6;
          }
          else {
            *(sword *)(puVar5 + 1) = (sword)iVar6;
          }
          uVar10 = 0;
          if (uVar13 != 0) {
            do {
              uVar11 = *puVar7;
              if ((uVar11 != 0) && (uVar11 != 0xffffffff)) {
                iVar8 = _ipc_object_copyin(param_2,uVar11,uVar12,&uStack_c);
                if (iVar8 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar5,1,uVar10);
                  return 0x1000000a;
                }
                if ((iVar6 == 0x10) &&
                   (iVar8 = _ipc_port_check_circularity(uStack_c,uVar2), iVar8 != 0)) {
                  *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
                }
                *puVar7 = uStack_c;
              }
              puVar7 = puVar7 + 1;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar13);
          }
          bVar4 = true;
        }
      }
      if (!bVar4) {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0x7f;
      }
    }
    iVar6 = 0;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=1067 start=0x403dcba */

void _ipc_kmsg_copyin_from_kernel(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  uVar8 = *(uint *)(param_1 + 0x14);
  uVar7 = (uVar8 & 0xffff) >> 8;
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x20);
  _ipc_object_copyin_from_kernel(uVar1,uVar8 & 0xff);
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_copyin_from_kernel(iVar4,uVar7);
  }
  if (uVar8 == 0x80000013) {
    *(undefined4 *)(param_1 + 0x14) = 0x80000011;
  }
  else {
    uVar3 = _ipc_object_copyin_type(uVar8 & 0xff);
    iVar4 = _ipc_object_copyin_type(uVar7);
    uVar8 = iVar4 << 8 | uVar3 | uVar8 & 0xffff0000;
    *(uint *)(param_1 + 0x14) = uVar8;
    if (-1 < (int)uVar8) {
      return;
    }
  }
  iVar4 = *(int *)(param_1 + 0x18);
  pbVar10 = (byte *)(param_1 + 0x2c);
  while (pbVar2 = pbVar10, pbVar2 < (byte *)(param_1 + iVar4 + 0x14)) {
    iVar6 = (uint)pbVar2[3] << 0x1d;
    if (iVar6 < 0) {
      uVar3 = (uint)*(word *)(pbVar2 + 4);
      uVar7 = (uint)*(word *)(pbVar2 + 6);
      uVar8 = *(uint *)(pbVar2 + 8);
      pbVar9 = pbVar2 + 0xc;
    }
    else {
      uVar3 = (uint)*pbVar2;
      uVar7 = (uint)pbVar2[1];
      uVar8 = *(uint *)(pbVar2 + 2) >> 0x14;
      pbVar9 = pbVar2 + 4;
    }
    if ((pbVar2[3] >> 3 & 1) == 0) {
      pbVar10 = pbVar9 + 4;
      pbVar9 = *(byte **)pbVar9;
    }
    else {
      pbVar10 = pbVar9 + ((uVar7 * uVar8 + 7 >> 3) + 3 & 0xfffffffc);
    }
    if (uVar3 - 0x10 < 6) {
      iVar5 = _ipc_object_copyin_type(uVar3);
      if (iVar6 < 0) {
        *(sword *)(pbVar2 + 4) = (sword)iVar5;
      }
      else {
        *pbVar2 = (byte)iVar5;
      }
      uVar7 = 0;
      if (uVar8 != 0) {
        do {
          iVar6 = *(int *)pbVar9;
          if ((((iVar6 != 0) && (iVar6 != -1)) &&
              (_ipc_object_copyin_from_kernel(iVar6,uVar3), iVar5 == 0x10)) &&
             (iVar6 = _ipc_port_check_circularity(iVar6,uVar1), iVar6 != 0)) {
            *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
          }
          pbVar9 = pbVar9 + 4;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1068 start=0x403de48 */

undefined4 _ipc_kmsg_copyout_header(uint *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int *piStack_8;
  
  uVar5 = *param_1;
  piVar1 = (int *)param_1[2];
  if (param_3 == 0) {
    uVar6 = uVar5 & 0xffff;
    uVar2 = (undefined2)(uVar5 >> 0x10);
    if (uVar6 == 0x12) {
      if (piVar1[1] < 0) {
        if (param_2 == piVar1[2]) {
          *piVar1 = *piVar1 + -1;
          piVar1[7] = piVar1[7] + -1;
          uVar5 = piVar1[3];
        }
        else {
          _ipc_notify_send_once(piVar1);
          uVar5 = 0;
        }
        *param_1 = CONCAT22(uVar2,0x1200);
        param_1[3] = uVar5;
        param_1[2] = 0;
        return 0;
      }
    }
    else if (uVar6 < 0x13) {
      if ((uVar6 == 0x11) && (piVar1[1] < 0)) {
        *piVar1 = *piVar1 + -1;
        uVar5 = 0;
        if (param_2 == piVar1[2]) {
          uVar5 = piVar1[3];
        }
        iVar3 = piVar1[6];
        piVar1[6] = iVar3 + -1;
        if ((iVar3 == 1) && (iVar3 = piVar1[8], iVar3 != 0)) {
          piVar1[8] = 0;
          _ipc_notify_no_senders(iVar3,piVar1[5]);
        }
        *param_1 = CONCAT22(uVar2,0x1100);
        param_1[3] = uVar5;
        param_1[2] = 0;
        return 0;
      }
    }
    else if ((((uVar6 == 0x1211) && (uVar6 = param_1[3], uVar6 != 0)) && (uVar6 != 0xffffffff)) &&
            (*(int *)(param_2 + 4) != 0)) {
      iVar3 = *(int *)(param_2 + 0xc);
      iVar4 = *(int *)(iVar3 + 8);
      if (((iVar4 != 0) && (piVar1[1] < 0)) && (*(int *)(uVar6 + 4) < 0)) {
        puVar7 = (uint *)(iVar4 * 0x10 + iVar3);
        *(uint *)(iVar3 + 8) = puVar7[2];
        puVar7[2] = 0;
        uVar5 = *puVar7;
        *puVar7 = uVar5 + 0x1000000 | 0x40001;
        puVar7[1] = uVar6;
        *piVar1 = *piVar1 + -1;
        uVar6 = 0;
        if (param_2 == piVar1[2]) {
          uVar6 = piVar1[3];
        }
        iVar3 = piVar1[6];
        piVar1[6] = iVar3 + -1;
        if ((iVar3 == 1) && (iVar3 = piVar1[8], iVar3 != 0)) {
          piVar1[8] = 0;
          _ipc_notify_no_senders(iVar3,piVar1[5]);
        }
        *param_1 = CONCAT22(uVar2,0x1112);
        param_1[3] = uVar6;
        param_1[2] = uVar5 + 0x1000000 >> 0x18 | iVar4 << 8;
        return 0;
      }
    }
  }
  uVar6 = (uVar5 & 0xffff) >> 8;
  piVar8 = (int *)param_1[3];
  if ((piVar8 == (int *)0x0) || (piVar8 == (int *)0xffffffff)) {
    if (*(int *)(param_2 + 4) == 0) {
      return 0x1000600b;
    }
    piStack_8 = piVar8;
    if ((param_3 != 0) &&
       ((iVar3 = _ipc_entry_lookup(param_2,param_3), iVar3 == 0 || ((*(byte *)(iVar3 + 1) & 2) == 0)
        ))) {
      return 0x10004007;
    }
loc_403E1B4:
    if (piVar1[1] < 0) {
      _ipc_object_copyout_dest(param_2,piVar1,uVar5 & 0xff,&uStack_14);
    }
    else {
      iVar4 = piVar1[2];
      iVar3 = *piVar1;
      *piVar1 = iVar3 + -1;
      if (iVar3 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
      }
      if ((((piVar8 == (int *)0x0) || (piVar8 == (int *)0xffffffff)) || (piVar8[1] < 0)) ||
         (iVar4 - piVar8[2] < 0)) {
        uStack_14 = 0xffffffff;
      }
      else {
        uStack_14 = 0;
      }
    }
    if ((piVar8 != (int *)0x0) && (piVar8 != (int *)0xffffffff)) {
      _ipc_object_release(piVar8);
    }
    *param_1 = uVar6 | (uVar5 & 0xff) << 8 | uVar5 & 0xffff0000;
    param_1[3] = uStack_14;
    param_1[2] = (uint)piStack_8;
    return 0;
  }
loc_403DFFC:
  if (*(int *)(param_2 + 4) == 0) {
    return 0x1000600b;
  }
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = _ipc_port_lookup_notify(param_2,param_3);
    if (iVar3 == 0) {
      return 0x10004007;
    }
  }
  if ((uVar6 == 0x12) ||
     (iVar4 = _ipc_right_reverse(param_2,piVar8,&piStack_8,&iStack_c), iVar4 == 0)) {
    if (-1 < piVar8[1]) {
      iVar4 = *piVar8;
      *piVar8 = iVar4 + -1;
      if (iVar4 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar8 + 1) & 0x7fff],piVar8);
      }
      if (iVar3 != 0) {
        _ipc_port_release_sonce(iVar3);
      }
      piVar8 = (int *)0xffffffff;
      piStack_8 = (int *)0xffffffff;
      goto loc_403E1B4;
    }
    iVar4 = _ipc_entry_get(param_2,&piStack_8,&iStack_c);
    if (iVar4 != 0) {
      if (iVar3 != 0) {
        _ipc_port_release_sonce(iVar3);
      }
      iVar3 = _ipc_entry_grow_table(param_2);
      if (iVar3 != 0) {
        if (iVar3 == 6) {
          return 0x1000480b;
        }
        return 0x1000600b;
      }
      goto loc_403DFFC;
    }
    if (iVar3 != 0) {
      iVar4 = _ipc_port_dnrequest(piVar8,piStack_8,iVar3,&uStack_10);
      if (iVar4 == 0) {
        iVar3 = 0;
        *(int **)(iStack_c + 4) = piVar8;
        *(undefined4 *)(iStack_c + 8) = uStack_10;
        goto loc_403E150;
      }
      _ipc_port_release_sonce(iVar3);
      _ipc_entry_dealloc(param_2,piStack_8,iStack_c);
      if ((piVar8[1] < 0) && (iVar3 = _ipc_port_dngrow(piVar8), iVar3 != 0)) {
        return 0x1000480b;
      }
      goto loc_403DFFC;
    }
    *(int **)(iStack_c + 4) = piVar8;
  }
loc_403E150:
  *piVar8 = *piVar8 + 1;
  _ipc_right_copyout(param_2,piStack_8,iStack_c,uVar6,1,piVar8);
  if (iVar3 != 0) {
    _ipc_port_release_sonce(iVar3);
  }
  goto loc_403E1B4;
}
/* GHIDRADEC_FUNCTION index=1069 start=0x403e25c */

undefined4 _ipc_kmsg_copyout_object(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piStack_8;
  
  if ((param_2 == (int *)0x0) || (param_2 == (int *)0xffffffff)) {
    *param_4 = param_2;
  }
  else if ((((param_3 == 0x11) && (*(int *)(param_1 + 4) != 0)) && (param_2[1] < 0)) &&
          (iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_4,&piStack_8), iVar1 != 0)) {
    param_2[6] = param_2[6] + -1;
    *param_2 = *param_2 + -1;
    if ((sword)(*piStack_8 + 1) != -1) {
      *piStack_8 = *piStack_8 + 1;
    }
  }
  else {
    iVar1 = _ipc_object_copyout(param_1,param_2,param_3,1,param_4);
    if (iVar1 != 0) {
      _ipc_object_destroy(param_2,param_3);
      if (iVar1 != 0x14) {
        *param_4 = 0;
        if (iVar1 != 6) {
          return 0x2000;
        }
        return 0x800;
      }
      *param_4 = 0xffffffff;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1070 start=0x403e316 */

uint _ipc_kmsg_copyout_body(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar5;
  int iVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  undefined4 uStack_8;
  
  uVar9 = 0;
  do {
    while( true ) {
      if (param_2 <= param_1) {
        return uVar9;
      }
      bVar5 = param_1[3] >> 3;
      iVar2 = (uint)param_1[3] << 0x1d;
      if (iVar2 < 0) {
        uVar8 = (uint)*(word *)(param_1 + 4);
        uVar7 = (uint)*(word *)(param_1 + 6);
        uVar10 = *(uint *)(param_1 + 8);
        pbVar12 = param_1 + 0xc;
      }
      else {
        uVar8 = (uint)*param_1;
        uVar7 = (uint)param_1[1];
        uVar10 = *(uint *)(param_1 + 2) >> 0x14;
        pbVar12 = param_1 + 4;
      }
      uVar7 = uVar7 * uVar10 + 7 >> 3;
      bVar13 = 5 < uVar8 - 0x10;
      if (bVar13) break;
      if ((((bVar5 & 1) != 0) || (uVar7 == 0)) ||
         (iVar3 = _vm_allocate(param_4,&uStack_8,uVar7,1), iVar3 == 0)) {
        pbVar11 = pbVar12;
        if ((bVar5 & 1) == 0) {
          pbVar11 = *(byte **)pbVar12;
        }
        uVar6 = 0;
        if (uVar10 != 0) {
          do {
            uVar4 = _ipc_kmsg_copyout_object(param_3,*(undefined4 *)pbVar11,uVar8,pbVar11);
            uVar9 = uVar4 | uVar9;
            pbVar11 = pbVar11 + 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar10);
        }
        break;
      }
      _ipc_kmsg_clean_body(param_1,pbVar12);
loc_403E48C:
      uStack_8 = 0;
      if (iVar2 < 0) {
        param_1[6] = 0;
        param_1[7] = 0;
      }
      else {
        param_1[1] = 0;
      }
      if (iVar3 == 6) {
        uVar9 = uVar9 | 0x400;
      }
      else {
        uVar9 = uVar9 | 0x1000;
      }
loc_403E4B0:
      param_1[3] = param_1[3] | 2;
      param_1 = pbVar12 + 4;
      *(undefined4 *)pbVar12 = uStack_8;
    }
    if ((bVar5 & 1) == 0) {
      uVar1 = *(undefined4 *)pbVar12;
      if (uVar7 == 0) {
        uStack_8 = 0;
      }
      else if (bVar13) {
        iVar3 = _vm_move(_ipc_soft_map,uVar1,param_4,uVar7,0,&uStack_8);
        _vm_deallocate(_ipc_soft_map,uVar1,uVar7);
        if (iVar3 != 0) goto loc_403E48C;
      }
      else {
        _copyoutmap(param_4,uVar1,uStack_8,uVar7);
        _kfree(uVar1,uVar7);
      }
      goto loc_403E4B0;
    }
    param_1[3] = param_1[3] & 0xfd;
    param_1 = pbVar12 + (uVar7 + 3 & 0xfffffffc);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1071 start=0x403e4ce */

uint _ipc_kmsg_copyout(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = _ipc_kmsg_copyout_header(param_1 + 0x14,param_2,param_4);
  if ((uVar2 == 0) && (iVar1 < 0)) {
    uVar3 = _ipc_kmsg_copyout_body
                      (param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar2 = 0;
    if (uVar3 != 0) {
      uVar2 = uVar3 | 0x1000400c;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1072 start=0x403e52c */

uint _ipc_kmsg_copyout_pseudo(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar4 = *(uint *)(param_1 + 0x14);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  uVar2 = _ipc_kmsg_copyout_object(param_2,*(undefined4 *)(param_1 + 0x1c),uVar4 & 0xff,&uStack_8);
  uVar3 = _ipc_kmsg_copyout_object(param_2,uVar1,(uVar4 & 0xffff) >> 8,&uStack_c);
  uVar3 = uVar3 | uVar2;
  *(uint *)(param_1 + 0x14) = uVar4 & 0xbfffffff;
  *(undefined4 *)(param_1 + 0x1c) = uStack_8;
  *(undefined4 *)(param_1 + 0x20) = uStack_c;
  if ((int)uVar4 < 0) {
    uVar4 = _ipc_kmsg_copyout_body
                      (param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar3 = uVar4 | uVar3;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1073 start=0x403e5b6 */

void _ipc_kmsg_copyout_dest(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uStack_8;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  piVar3 = *(int **)(param_1 + 0x1c);
  iVar5 = *(int *)(param_1 + 0x20);
  uVar4 = (uVar2 & 0xffff) >> 8;
  if (piVar3[1] < 0) {
    _ipc_object_copyout_dest(param_2,piVar3,uVar2 & 0xff,&uStack_8);
  }
  else {
    iVar1 = *piVar3;
    *piVar3 = iVar1 + -1;
    if (iVar1 == 1) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar3 + 1) & 0x7fff],piVar3);
    }
    uStack_8 = 0xffffffff;
  }
  if ((iVar5 != 0) && (iVar5 != -1)) {
    _ipc_object_destroy(iVar5,uVar4);
    iVar5 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar4 | (uVar2 & 0xff) << 8 | uVar2 & 0xffff0000;
  *(undefined4 *)(param_1 + 0x20) = uStack_8;
  *(int *)(param_1 + 0x1c) = iVar5;
  if ((int)uVar2 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1074 start=0x403e682 */

undefined4 _ipc_kmsg_copyin_compat(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  bool bVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  uint uStack_48;
  int iStack_34;
  byte *pbStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_1c = *(undefined4 *)(param_1 + 0x14);
  uStack_18 = *(undefined4 *)(param_1 + 0x18);
  uStack_14 = *(undefined4 *)(param_1 + 0x1c);
  iVar8 = *(int *)(param_1 + 0x20);
  uStack_c = *(undefined4 *)(param_1 + 0x24);
  uStack_8 = *(undefined4 *)(param_1 + 0x28);
  iStack_10 = iVar8;
  iVar6 = _ipc_object_copyin_header(param_2,uStack_c,&uStack_20,&uStack_24);
  if (iVar6 == 0) {
    if (iVar8 == 0) {
      uStack_28 = 0;
      iStack_2c = 0;
    }
    else {
      iVar8 = _ipc_object_copyin_header(param_2,iVar8,&uStack_28,&iStack_2c);
      if (iVar8 != 0) {
        _ipc_object_destroy(uStack_20,uStack_24);
        return 0x10000009;
      }
    }
    *(uint *)(param_1 + 0x14) = uStack_24 | iStack_2c << 8;
    *(undefined4 *)(param_1 + 0x18) = uStack_18;
    *(undefined4 *)(param_1 + 0x1c) = uStack_20;
    *(undefined4 *)(param_1 + 0x20) = uStack_28;
    *(undefined4 *)(param_1 + 0x24) = uStack_14;
    *(undefined4 *)(param_1 + 0x28) = uStack_8;
    if ((char)uStack_1c == '\0') {
      bVar4 = false;
      pbVar2 = (byte *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      pbVar14 = (byte *)(param_1 + 0x2c);
      while (pbVar5 = pbVar14, pbVar5 < pbVar2) {
        if ((uint)((int)pbVar2 - (int)pbVar5) < 4) {
loc_403E7EC:
          _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
          return 0x10000008;
        }
        bVar9 = pbVar5[3] >> 2;
        if (((bVar9 & 1) != 0) && ((uint)((int)pbVar2 - (int)pbVar5) < 0xc)) goto loc_403E7EC;
        bVar1 = pbVar5[3];
        uVar3 = (bVar1 & 3) >> 1;
        if ((bVar9 & 1) == 0) {
          uVar11 = (uint)*pbVar5;
          uVar10 = (uint)pbVar5[1];
          uStack_48 = *(uint *)(pbVar5 + 2) >> 0x14;
          pbVar13 = pbVar5 + 4;
        }
        else {
          uVar11 = (uint)*(word *)(pbVar5 + 4);
          uVar10 = (uint)*(word *)(pbVar5 + 6);
          uStack_48 = *(uint *)(pbVar5 + 8);
          pbVar13 = pbVar5 + 0xc;
        }
        bVar15 = 1 < uVar11 - 5;
        if ((!bVar15) && (uVar10 != 0x20)) {
          _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
          return 0x1000000f;
        }
        pbVar5[3] = pbVar5[3] & 0xfe;
        if ((bVar9 & 1) != 0) {
          *pbVar5 = 0;
          pbVar5[1] = 0;
          *(word *)(pbVar5 + 2) = *(word *)(pbVar5 + 2) & 0xf;
        }
        uVar10 = uVar10 * uStack_48 + 7 >> 3;
        if ((int)((uint)bVar1 << 0x1c) < 0) {
          uVar10 = uVar10 + 3 & 0xfffffffc;
          if ((uint)((int)pbVar2 - (int)pbVar13) < uVar10) goto loc_403E7EC;
          pbVar14 = pbVar13 + uVar10;
          pbVar12 = pbVar13;
        }
        else {
          if ((uint)((int)pbVar2 - (int)pbVar13) < 4) goto loc_403E7EC;
          iVar8 = *(int *)pbVar13;
          if (uVar10 == 0) {
            pbVar12 = (byte *)0x0;
          }
          else if (bVar15) {
            iVar8 = _vm_move(param_3,iVar8,_ipc_soft_map,uVar10,uVar3,&pbStack_30);
            pbVar12 = pbStack_30;
            if (iVar8 != 0) goto loc_403E930;
          }
          else {
            pbVar12 = (byte *)_kalloc(uVar10);
            if (pbVar12 == (byte *)0x0) {
loc_403E930:
              _ipc_kmsg_clean_partial(param_1,pbVar5,0,0);
              return 0x1000000c;
            }
            iVar6 = _copyinmap(param_3,iVar8,pbVar12,uVar10);
            if ((iVar6 != 0) ||
               ((uVar3 != 0 && (iVar8 = _vm_deallocate(param_3,iVar8,uVar10), iVar8 != 0)))) {
              _kfree(pbVar12,uVar10);
              goto loc_403E930;
            }
          }
          pbVar14 = pbVar13 + 4;
          *(byte **)pbVar13 = pbVar12;
          bVar4 = true;
        }
        if (!bVar15) {
          iVar8 = _ipc_object_copyin_type(uVar11);
          if ((bVar9 & 1) == 0) {
            *pbVar5 = (byte)iVar8;
          }
          else {
            *(sword *)(pbVar5 + 4) = (sword)iVar8;
          }
          uVar10 = 0;
          if (uStack_48 != 0) {
            do {
              iVar6 = *(int *)pbVar12;
              if ((iVar6 != 0) && (iVar6 != -1)) {
                iVar6 = _ipc_object_copyin_compat(param_2,iVar6,uVar11,uVar3,&iStack_34);
                if (iVar6 != 0) {
                  _ipc_kmsg_clean_partial(param_1,pbVar5,1,uVar10);
                  return 0x1000000a;
                }
                if ((iVar8 == 0x10) &&
                   (iVar6 = _ipc_port_check_circularity(iStack_34,uStack_20), iVar6 != 0)) {
                  *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
                }
                *(int *)pbVar12 = iStack_34;
              }
              pbVar12 = pbVar12 + 4;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uStack_48);
          }
          bVar4 = true;
        }
      }
      if (bVar4) {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x80;
      }
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0x10000003;
  }
  return uVar7;
}

