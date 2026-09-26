/* GHIDRADEC_FUNCTION index=1075 start=0x403e9f2 */

void _ipc_kmsg_copyin_compat_from_kernel(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  bool bVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  char cStack_19;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x20);
  uVar5 = *(undefined4 *)(param_1 + 0x24);
  uVar6 = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_from_kernel(uVar5,0x13);
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_copyin_from_kernel(iVar4,0x14);
  }
  uVar10 = _ipc_object_copyin_type(0x13);
  iVar11 = _ipc_object_copyin_type(0x14);
  *(uint *)(param_1 + 0x14) = iVar11 << 8 | uVar10;
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  *(undefined4 *)(param_1 + 0x1c) = uVar5;
  *(int *)(param_1 + 0x20) = iVar4;
  *(undefined4 *)(param_1 + 0x24) = uVar3;
  *(undefined4 *)(param_1 + 0x28) = uVar6;
  cStack_19 = (char)uVar1;
  if (cStack_19 == '\0') {
    bVar8 = false;
    iVar4 = *(int *)(param_1 + 0x18);
    pbVar16 = (byte *)(param_1 + 0x2c);
    while (pbVar9 = pbVar16, pbVar9 < (byte *)(param_1 + iVar4 + 0x14)) {
      bVar7 = pbVar9[3];
      iVar11 = (uint)bVar7 << 0x1d;
      if (iVar11 < 0) {
        uVar14 = (uint)*(word *)(pbVar9 + 4);
        uVar13 = (uint)*(word *)(pbVar9 + 6);
        uVar10 = *(uint *)(pbVar9 + 8);
        pbVar15 = pbVar9 + 0xc;
      }
      else {
        uVar14 = (uint)*pbVar9;
        uVar13 = (uint)pbVar9[1];
        uVar10 = *(uint *)(pbVar9 + 2) >> 0x14;
        pbVar15 = pbVar9 + 4;
      }
      pbVar9[3] = pbVar9[3] & 0xfe;
      if (iVar11 < 0) {
        *pbVar9 = 0;
        pbVar9[1] = 0;
        *(word *)(pbVar9 + 2) = *(word *)(pbVar9 + 2) & 0xf;
      }
      if ((bVar7 >> 3 & 1) == 0) {
        pbVar16 = pbVar15 + 4;
        pbVar15 = *(byte **)pbVar15;
        bVar8 = true;
      }
      else {
        pbVar16 = pbVar15 + ((uVar13 * uVar10 + 7 >> 3) + 3 & 0xfffffffc);
      }
      if (uVar14 - 5 < 2) {
        iVar12 = _ipc_object_copyin_type(uVar14);
        if (iVar11 < 0) {
          *(sword *)(pbVar9 + 4) = (sword)iVar12;
        }
        else {
          *pbVar9 = (byte)iVar12;
        }
        uVar13 = 0;
        if (uVar10 != 0) {
          do {
            iVar11 = *(int *)pbVar15;
            if ((((iVar11 != 0) && (iVar11 != -1)) &&
                (_ipc_object_copyin_from_kernel(iVar11,uVar14), iVar12 == 0x10)) &&
               (iVar11 = _ipc_port_check_circularity(iVar11,uVar5), iVar11 != 0)) {
              *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
            }
            pbVar15 = pbVar15 + 4;
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar10);
        }
        bVar8 = true;
      }
    }
    if (bVar8) {
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x80;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1076 start=0x403ebb4 */

undefined4 _ipc_kmsg_copyout_compat(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar6;
  int iVar4;
  undefined2 uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  uint uStack_30;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar9 = *(uint *)(param_1 + 0x14);
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x20);
  if (piVar1[1] < 0) {
    _ipc_object_copyout_dest(param_2,piVar1,uVar9 & 0xff,&uStack_20);
  }
  else {
    iVar3 = *piVar1;
    *piVar1 = iVar3 + -1;
    if (iVar3 == 1) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
    uStack_20 = 0;
  }
  if ((iVar2 == 0) || (iVar2 == -1)) {
    uStack_24 = 0;
  }
  else {
    uVar8 = (uVar9 & 0xffff) >> 8;
    iVar3 = _ipc_object_copyout_compat(param_2,iVar2,uVar8,&uStack_24);
    if (iVar3 != 0) {
      _ipc_object_destroy(iVar2,uVar8);
      uStack_24 = 0;
    }
  }
  uStack_1c = CARRY4(uVar9,uVar9) ^ 1;
  uStack_18 = *(undefined4 *)(param_1 + 0x18);
  uStack_14 = *(undefined4 *)(param_1 + 0x24);
  uStack_8 = *(undefined4 *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x14) = uStack_1c;
  *(undefined4 *)(param_1 + 0x18) = uStack_18;
  *(undefined4 *)(param_1 + 0x1c) = uStack_14;
  *(undefined4 *)(param_1 + 0x20) = uStack_20;
  *(undefined4 *)(param_1 + 0x24) = uStack_24;
  *(undefined4 *)(param_1 + 0x28) = uStack_8;
  pbVar11 = (byte *)(param_1 + 0x2c);
  if ((char)uStack_1c == '\0') {
    iVar2 = *(int *)(param_1 + 0x18);
    uStack_10 = uStack_20;
    uStack_c = uStack_24;
    while (pbVar11 < (byte *)(iVar2 + 0x14 + param_1)) {
      bVar6 = pbVar11[3] >> 3;
      iVar3 = (uint)pbVar11[3] << 0x1d;
      if (iVar3 < 0) {
        uVar8 = (uint)*(word *)(pbVar11 + 4);
        uVar9 = (uint)*(word *)(pbVar11 + 6);
        uStack_30 = *(uint *)(pbVar11 + 8);
        pbVar10 = pbVar11 + 0xc;
      }
      else {
        uVar8 = (uint)*pbVar11;
        uVar9 = (uint)pbVar11[1];
        uStack_30 = *(uint *)(pbVar11 + 2) >> 0x14;
        pbVar10 = pbVar11 + 4;
      }
      uVar9 = uVar9 * uStack_30 + 7 >> 3;
      bVar12 = 5 < uVar8 - 0x10;
      if (bVar12) {
loc_403EDEE:
        if ((bVar6 & 1) == 0) {
          iVar3 = *(int *)pbVar10;
          if (uVar9 == 0) goto loc_403EE60;
          if (bVar12) {
            iVar4 = _vm_move(_ipc_soft_map,iVar3,param_3,uVar9,0,&iStack_28);
            _vm_deallocate(_ipc_soft_map,iVar3,uVar9);
            if (iVar4 != 0) goto loc_403EE60;
          }
          else {
            _copyoutmap(param_3,iVar3,iStack_28,uVar9);
            _kfree(iVar3,uVar9);
          }
          goto loc_403EE64;
        }
        pbVar11 = pbVar10 + (uVar9 + 3 & 0xfffffffc);
      }
      else {
        if ((((bVar6 & 1) != 0) || (uVar9 == 0)) ||
           (iVar4 = _vm_allocate(param_3,&iStack_28,uVar9,1), iVar4 == 0)) {
          uVar5 = _ipc_object_copyout_type_compat(uVar8);
          if (iVar3 < 0) {
            *(undefined2 *)(pbVar11 + 4) = uVar5;
          }
          else {
            *pbVar11 = (byte)uVar5;
          }
          pbVar11 = pbVar10;
          if ((bVar6 & 1) == 0) {
            pbVar11 = *(byte **)pbVar10;
          }
          uVar7 = 0;
          if (uStack_30 != 0) {
            do {
              iVar3 = *(int *)pbVar11;
              if ((iVar3 == 0) || (iVar3 == -1)) {
                pbVar11[0] = 0;
                pbVar11[1] = 0;
                pbVar11[2] = 0;
                pbVar11[3] = 0;
              }
              else {
                iVar4 = _ipc_object_copyout_compat(param_2,iVar3,uVar8,pbVar11);
                if (iVar4 != 0) {
                  _ipc_object_destroy(iVar3,uVar8);
                  pbVar11[0] = 0;
                  pbVar11[1] = 0;
                  pbVar11[2] = 0;
                  pbVar11[3] = 0;
                }
              }
              pbVar11 = pbVar11 + 4;
              uVar7 = uVar7 + 1;
            } while (uVar7 < uStack_30);
          }
          goto loc_403EDEE;
        }
        _ipc_kmsg_clean_body(pbVar11,pbVar10);
loc_403EE60:
        iStack_28 = 0;
loc_403EE64:
        pbVar11 = pbVar10 + 4;
        *(int *)pbVar10 = iStack_28;
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1077 start=0x403ee7c */

void _ipc_marequest_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((_ipc_marequest_size == 0) &&
     (_ipc_marequest_size = _ipc_marequest_max >> 8, _ipc_marequest_size < 0x10)) {
    _ipc_marequest_size = 0x10;
  }
  _ipc_marequest_mask = _ipc_marequest_size - 1;
  if ((_ipc_marequest_mask & _ipc_marequest_size) != 0) {
    uVar3 = 1;
    while( true ) {
      _ipc_marequest_mask = uVar3 | _ipc_marequest_mask;
      _ipc_marequest_size = _ipc_marequest_mask + 1;
      if ((_ipc_marequest_mask & _ipc_marequest_size) == 0) break;
      uVar3 = uVar3 * 2;
    }
  }
  puVar2 = (undefined4 *)_kalloc(_ipc_marequest_size << 2);
  uVar1 = _ipc_marequest_size;
  uVar3 = 0;
  _ipc_marequest_table = puVar2;
  if (_ipc_marequest_size != 0) {
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  _ipc_marequest_zone = _zinit(0x10,_ipc_marequest_max << 4,0x10,0,aIpcMsgAccepted);
  _zchange(_ipc_marequest_zone,0,0,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1078 start=0x403ef50 */

undefined4 _ipc_marequest_create(uint param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puStack_c;
  uint uStack_8;
  
  puVar2 = (uint *)_zalloc(_ipc_marequest_zone);
  if (puVar2 == (uint *)0x0) {
    return 0x1000000e;
  }
  if (*(int *)(param_1 + 4) == 0) {
loc_403F046:
    _zfree(_ipc_marequest_zone,puVar2);
    uVar6 = 0x1000000b;
  }
  else {
    iVar3 = _ipc_right_reverse(param_1,param_2,&uStack_8,&puStack_c);
    if (iVar3 == 0) {
      if (param_3 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = _ipc_port_lookup_notify(param_1,param_3);
        if (uVar5 == 0) goto loc_403F046;
      }
      _ipc_space_reference(param_1);
      *puVar2 = param_1;
      puVar2[1] = 0;
      puVar2[2] = uVar5;
    }
    else {
      uVar5 = *puStack_c;
      if ((uVar5 & 0x200000) != 0) {
        _zfree(_ipc_marequest_zone,puVar2);
        return 0x10000006;
      }
      if (param_3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = _ipc_port_lookup_notify(param_1,param_3);
        if (uVar4 == 0) goto loc_403F046;
      }
      *puStack_c = uVar5 | 0x200000;
      _ipc_space_reference(param_1);
      *puVar2 = param_1;
      puVar2[1] = uStack_8;
      puVar2[2] = uVar4;
      puVar1 = (uint *)(_ipc_marequest_table +
                       (_ipc_marequest_mask & (uStack_8 & 0xff) + (uStack_8 >> 8) + (param_1 >> 4))
                       * 4);
      puVar2[3] = *puVar1;
      *puVar1 = (uint)puVar2;
    }
    *param_4 = (int)puVar2;
    uVar6 = 0;
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=1079 start=0x403f07e */

void _ipc_marequest_cancel(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(_ipc_marequest_table +
                   (_ipc_marequest_mask & (param_2 & 0xff) + (param_2 >> 8) + (param_1 >> 4)) * 4);
  while ((puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0 &&
         ((param_1 != *puVar1 || (param_2 != puVar1[1]))))) {
    puVar2 = puVar1 + 3;
  }
  *puVar2 = puVar1[3];
  puVar1[1] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1080 start=0x403f0d8 */

void _ipc_marequest_rename(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(_ipc_marequest_table +
                   (_ipc_marequest_mask & (param_2 & 0xff) + (param_2 >> 8) + (param_1 >> 4)) * 4);
  while ((puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0 &&
         ((param_1 != *puVar1 || (param_2 != puVar1[1]))))) {
    puVar2 = puVar1 + 3;
  }
  *puVar2 = puVar1[3];
  puVar1[1] = param_3;
  puVar2 = (uint *)(_ipc_marequest_table +
                   (_ipc_marequest_mask & (param_3 & 0xff) + (param_3 >> 8) + (param_1 >> 4)) * 4);
  puVar1[3] = *puVar2;
  *puVar2 = (uint)puVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1081 start=0x403f15a */

void _ipc_marequest_destroy(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  uVar1 = *param_1;
  iVar6 = 0;
  uVar5 = param_1[1];
  uVar3 = param_1[2];
  if (uVar5 != 0) {
    puVar7 = (uint *)(_ipc_marequest_table +
                     (_ipc_marequest_mask & (uVar5 & 0xff) + (uVar5 >> 8) + (uVar1 >> 4)) * 4);
    while ((puVar2 = (uint *)*puVar7, puVar2 != (uint *)0x0 &&
           ((uVar1 != *puVar2 || (uVar5 != puVar2[1]))))) {
      puVar7 = puVar2 + 3;
    }
    *puVar7 = puVar2[3];
    if (*(int *)(uVar1 + 4) == 0) {
      uVar5 = 0;
    }
    else {
      iVar4 = _ipc_entry_lookup(uVar1,uVar5);
      *(byte *)(iVar4 + 1) = *(byte *)(iVar4 + 1) & 0xdf;
      if (uVar3 == 0) {
        iVar6 = _ipc_port_copy_send(*(undefined4 *)(uVar1 + 0x3c));
      }
    }
  }
  _ipc_space_release(uVar1);
  _zfree(_ipc_marequest_zone,param_1);
  if (uVar3 == 0) {
    if ((iVar6 != 0) && (iVar6 != -1)) {
      _ipc_notify_msg_accepted_compat(iVar6,uVar5);
    }
  }
  else {
    _ipc_notify_msg_accepted(uVar3,uVar5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1082 start=0x403f228 */

uint _ipc_marequest_info(undefined4 *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (_ipc_marequest_size < param_3) {
    param_3 = _ipc_marequest_size;
  }
  uVar3 = 0;
  piVar4 = _ipc_marequest_table;
  if (param_3 != 0) {
    do {
      iVar2 = 0;
      for (iVar1 = *piVar4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar2 + 1;
      }
      *param_2 = iVar2;
      uVar3 = uVar3 + 1;
      param_2 = param_2 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < param_3);
  }
  *param_1 = _ipc_marequest_max;
  return _ipc_marequest_size;
}
/* GHIDRADEC_FUNCTION index=1083 start=0x403f286 */

void _ipc_mqueue_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1084 start=0x403f298 */

void _ipc_mqueue_move(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_2;
joined_r0x0403f2b4:
  do {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0) {
        return;
      }
      iVar2 = _ipc_kmsg_queue_next(param_2,iVar1);
    } while (param_3 != *(int *)(iVar1 + 0x1c));
    _ipc_kmsg_rmqueue(param_2,iVar1);
    while (iVar3 = _ipc_thread_dequeue(param_1 + 4), iVar3 != 0) {
      _thread_go(iVar3);
      if (*(uint *)(iVar1 + 0x18) <= *(uint *)(iVar3 + 0x98)) {
        *(undefined4 *)(iVar3 + 0x94) = 0;
        *(int *)(iVar3 + 0x98) = iVar1;
        *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(param_3 + 0x30);
        *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 1;
        goto joined_r0x0403f2b4;
      }
      *(undefined4 *)(iVar3 + 0x94) = 0x10004004;
      *(undefined4 *)(iVar3 + 0x98) = *(undefined4 *)(iVar1 + 0x18);
    }
    _ipc_kmsg_enqueue(param_1,iVar1);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1085 start=0x403f33a */

void _ipc_mqueue_changed(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = _ipc_thread_dequeue(param_1 + 4);
    if (iVar1 == 0) break;
    *(undefined4 *)(iVar1 + 0x94) = param_2;
    _thread_go(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1086 start=0x403f378 */

undefined4 _ipc_mqueue_send(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  piVar1 = (int *)param_1[7];
  if (piVar1[2] == _ipc_space_kernel) {
    iVar6 = _ipc_kobject_server(param_1);
    if (iVar6 != 0) {
      _ipc_mqueue_send(iVar6,0x10000,0,0);
    }
    return 0;
  }
  do {
    iVar6 = _active_threads;
    if (-1 < piVar1[1]) {
      iVar6 = *piVar1;
      *piVar1 = iVar6 + -1;
      if (iVar6 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
      }
      param_1[7] = 0;
loc_403F3FC:
      _ipc_kmsg_destroy(param_1);
      return 0;
    }
    if ((((uint)piVar1[0xd] < (uint)piVar1[0xe]) || ((param_2 & 0x10000) != 0)) ||
       (*(char *)((int)param_1 + 0x17) == '\x12')) {
      if ((*(byte *)(param_1 + 5) & 0x40) == 0) {
        piVar1[0xd] = piVar1[0xd] + 1;
        if (piVar1[0xb] == 0) {
          piVar7 = piVar1 + 0xf;
        }
        else {
          piVar7 = (int *)(piVar1[0xb] + 0xc);
        }
        piVar5 = piVar7 + 1;
        while( true ) {
          iVar6 = *piVar5;
          if (iVar6 == 0) {
            iVar6 = *piVar7;
            if (iVar6 != 0) {
              puVar2 = *(undefined4 **)(iVar6 + 4);
              *param_1 = iVar6;
              param_1[1] = (int)puVar2;
              *(int **)(iVar6 + 4) = param_1;
              *puVar2 = param_1;
              return 0;
            }
            *piVar7 = (int)param_1;
            *param_1 = (int)param_1;
            param_1[1] = (int)param_1;
            return 0;
          }
          iVar3 = *(int *)(iVar6 + 0x8c);
          if (iVar6 == iVar3) {
            *piVar5 = 0;
          }
          else {
            iVar4 = *(int *)(iVar6 + 0x90);
            *piVar5 = iVar3;
            *(int *)(iVar3 + 0x90) = iVar4;
            *(int *)(iVar4 + 0x8c) = iVar3;
            *(int *)(iVar6 + 0x8c) = iVar6;
            *(int *)(iVar6 + 0x90) = iVar6;
          }
          if ((uint)param_1[6] <= *(uint *)(iVar6 + 0x98)) break;
          *(undefined4 *)(iVar6 + 0x94) = 0x10004004;
          *(int *)(iVar6 + 0x98) = param_1[6];
          _thread_go(iVar6);
        }
        *(undefined4 *)(iVar6 + 0x94) = 0;
        *(int **)(iVar6 + 0x98) = param_1;
        *(int *)(iVar6 + 0x9c) = piVar1[0xc];
        piVar1[0xc] = piVar1[0xc] + 1;
        if ((param_2 & 0x20000) == 0) {
          _thread_go(iVar6);
          return 0;
        }
        _thread_go_and_switch(param_4,iVar6);
        return 0;
      }
      goto loc_403F3FC;
    }
    if ((param_2 & 0x10) == 0) {
      _thread_will_wait(_active_threads);
    }
    else {
      if (param_3 == 0) {
        return 0x10000004;
      }
      _thread_will_wait_with_timeout(_active_threads,param_3);
    }
    _ipc_thread_enqueue(piVar1 + 0x11,iVar6);
    *(undefined4 *)(iVar6 + 0x94) = 0x10000001;
    _thread_block_with_continuation(0);
    if (*(int *)(iVar6 + 0x94) != 0) {
      _ipc_thread_rmqueue(piVar1 + 0x11,iVar6);
      iVar6 = *(int *)(iVar6 + 0x40);
      if (iVar6 == 1) {
        param_3 = 0;
      }
      else if ((0 < iVar6) && (iVar6 < 4)) {
        return 0x10000007;
      }
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1087 start=0x403f58e */

undefined4 _ipc_mqueue_send_interrupt(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  
  iVar2 = param_1[7];
  if (*(int *)(iVar2 + 4) < 0) {
    if (*(int *)(iVar2 + 0x2c) == 0) {
      piVar8 = (int *)(iVar2 + 0x3c);
    }
    else {
      piVar8 = (int *)(*(int *)(iVar2 + 0x2c) + 0xc);
    }
    piVar6 = piVar8 + 1;
    *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
    while (iVar1 = *piVar6, iVar1 != 0) {
      iVar4 = *(int *)(iVar1 + 0x8c);
      if (iVar1 == iVar4) {
        *piVar6 = 0;
      }
      else {
        iVar5 = *(int *)(iVar1 + 0x90);
        *piVar6 = iVar4;
        *(int *)(iVar4 + 0x90) = iVar5;
        *(int *)(iVar5 + 0x8c) = iVar4;
        *(int *)(iVar1 + 0x8c) = iVar1;
        *(int *)(iVar1 + 0x90) = iVar1;
      }
      if ((uint)param_1[6] <= *(uint *)(iVar1 + 0x98)) {
        *(undefined4 *)(iVar1 + 0x94) = 0;
        *(int **)(iVar1 + 0x98) = param_1;
        *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(iVar2 + 0x30);
        *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + 1;
        _thread_go(iVar1);
        goto loc_403F65C;
      }
      *(undefined4 *)(iVar1 + 0x94) = 0x10004004;
      *(int *)(iVar1 + 0x98) = param_1[6];
      _thread_go(iVar1);
    }
    iVar2 = *piVar8;
    if (iVar2 == 0) {
      *piVar8 = (int)param_1;
      *param_1 = (int)param_1;
      param_1[1] = (int)param_1;
    }
    else {
      puVar3 = *(undefined4 **)(iVar2 + 4);
      *param_1 = iVar2;
      param_1[1] = (int)puVar3;
      *(int **)(iVar2 + 4) = param_1;
      *puVar3 = param_1;
    }
loc_403F65C:
    uVar7 = 0;
  }
  else {
    uVar7 = 0x10000003;
  }
  return uVar7;
}
/* GHIDRADEC_FUNCTION index=1088 start=0x403f668 */

undefined4 _ipc_mqueue_copyin(int param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 4) != 0) &&
     (puVar2 = (uint *)_ipc_entry_lookup(param_1,param_2), puVar2 != (uint *)0x0)) {
    piVar1 = (int *)puVar2[1];
    if ((*puVar2 & 0x20000) == 0) {
      if ((*puVar2 & 0x80000) == 0) {
        return 0x10004002;
      }
      piVar3 = piVar1 + 3;
    }
    else {
      piVar3 = (int *)piVar1[0xb];
      if (piVar3 != (int *)0x0) {
        if (piVar3[1] < 0) {
          return 0x1000400a;
        }
        _ipc_pset_remove(piVar3,piVar1);
        if (*piVar3 == 0) {
          _zfree((&_ipc_object_zones)[*(word *)(piVar3 + 1) & 0x7fff],piVar3);
        }
      }
      piVar3 = piVar1 + 0xf;
    }
    *piVar1 = *piVar1 + 1;
    *param_4 = (uint)piVar1;
    *param_3 = piVar3;
    return 0;
  }
  return 0x10004002;
}
/* GHIDRADEC_FUNCTION index=1089 start=0x403f710 */

undefined4
_ipc_mqueue_receive(int *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                   uint *param_7,undefined4 *param_8)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar5 = _active_threads;
  if (param_5 != 0) goto loc_403F7F2;
  do {
    piVar6 = (int *)*param_1;
    if (piVar6 != (int *)0x0) {
      if (param_3 < (uint)piVar6[6]) {
        *param_7 = piVar6[6];
        return 0x10004004;
      }
      piVar1 = (int *)*piVar6;
      if (piVar6 == piVar1) {
        *param_1 = 0;
      }
      else {
        piVar2 = (int *)piVar6[1];
        *param_1 = (int)piVar1;
        piVar1[1] = (int)piVar2;
        *piVar2 = (int)piVar1;
      }
      iVar5 = piVar6[7];
      uVar4 = *(undefined4 *)(iVar5 + 0x30);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
loc_403F880:
      if (piVar6[3] != 0) {
        _ipc_marequest_destroy(piVar6[3]);
        piVar6[3] = 0;
      }
      if (*(int *)(iVar5 + 4) < 0) {
        iVar3 = *(int *)(iVar5 + 0x34);
        *(int *)(iVar5 + 0x34) = iVar3 + -1;
        iVar7 = *(int *)(iVar5 + 0x44);
        if ((iVar7 != 0) && (iVar3 - 1U < *(uint *)(iVar5 + 0x38))) {
          _ipc_thread_rmqueue((int *)(iVar5 + 0x44),iVar7);
          *(undefined4 *)(iVar7 + 0x94) = 0;
          _thread_go(iVar7);
        }
      }
      *param_7 = (uint)piVar6;
      *param_8 = uVar4;
      return 0;
    }
    if ((param_2 & 0x100) == 0) {
      _thread_will_wait(iVar5);
    }
    else {
      if (param_4 == 0) {
        return 0x10004003;
      }
      _thread_will_wait_with_timeout(iVar5,param_4);
    }
    iVar7 = param_1[1];
    if (iVar7 == 0) {
      param_1[1] = iVar5;
    }
    else {
      iVar3 = *(int *)(iVar7 + 0x90);
      *(int *)(iVar5 + 0x8c) = iVar7;
      *(int *)(iVar5 + 0x90) = iVar3;
      *(int *)(iVar7 + 0x90) = iVar5;
      *(int *)(iVar3 + 0x8c) = iVar5;
    }
    *(undefined4 *)(iVar5 + 0x94) = 0x10004001;
    *(uint *)(iVar5 + 0x98) = param_3;
    iVar7 = param_6;
    if (param_6 == 0) {
      iVar7 = 0;
    }
    _thread_block_with_continuation(iVar7);
loc_403F7F2:
    iVar7 = *(int *)(iVar5 + 0x94);
    if (iVar7 == 0) {
      piVar6 = *(int **)(iVar5 + 0x98);
      uVar4 = *(undefined4 *)(iVar5 + 0x9c);
      iVar5 = piVar6[7];
      goto loc_403F880;
    }
    if (iVar7 == 0x10004004) {
      *param_7 = *(uint *)(iVar5 + 0x98);
loc_403F832:
      return *(undefined4 *)(iVar5 + 0x94);
    }
    if (0x10004004 < iVar7) {
      if ((iVar7 == 0x10004006) || (iVar7 == 0x10004009)) goto loc_403F832;
loc_403F86E:
                    /* WARNING: Subroutine does not return */
      _panic(aIpcMqueueRecei);
    }
    if (iVar7 != 0x10004001) goto loc_403F86E;
    _ipc_thread_rmqueue(param_1 + 1,iVar5);
    iVar7 = *(int *)(iVar5 + 0x40);
    if (iVar7 == 1) {
      param_4 = 0;
    }
    else if ((0 < iVar7) && (iVar7 < 4)) {
      return 0x10004005;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1090 start=0x403f8e6 */

void _ipc_notify_init_port_deleted(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x41;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1091 start=0x403f940 */

void _ipc_notify_init_msg_accepted(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x42;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1092 start=0x403f99a */

void _ipc_notify_init_port_destroyed(undefined4 *param_1)

{
  *param_1 = 0x80000012;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x45;
  *(undefined *)(param_1 + 6) = 0x10;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1093 start=0x403f9f6 */

void _ipc_notify_init_no_senders(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x46;
  *(undefined *)(param_1 + 6) = 2;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1094 start=0x403fa50 */

void _ipc_notify_init_send_once(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x18;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x47;
  return;
}
/* GHIDRADEC_FUNCTION index=1095 start=0x403fa7a */

void _ipc_notify_init_dead_name(undefined4 *param_1)

{
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x48;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  *(word *)((int)param_1 + 0x1a) = *(word *)((int)param_1 + 0x1a) & 0xf | 0x10;
  *(byte *)((int)param_1 + 0x1b) = *(byte *)((int)param_1 + 0x1b) & 0xf8 | 8;
  param_1[7] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1096 start=0x403fad4 */

void _ipc_notify_init(void)

{
  _ipc_notify_init_port_deleted(&_ipc_notify_port_deleted_template);
  _ipc_notify_init_msg_accepted(&_ipc_notify_msg_accepted_template);
  _ipc_notify_init_port_destroyed(&_ipc_notify_port_destroyed_template);
  _ipc_notify_init_no_senders(&_ipc_notify_no_senders_template);
  _ipc_notify_init_send_once(&_ipc_notify_send_once_template);
  _ipc_notify_init_dead_name(&_ipc_notify_dead_name_template);
  return;
}
/* GHIDRADEC_FUNCTION index=1097 start=0x403fb24 */

void _ipc_notify_port_deleted(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedPortDel,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_deleted_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2268;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C226C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2270;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2274;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2278;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C227C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C2280;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1098 start=0x403fbd4 */

void _ipc_notify_msg_accepted(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedMsgAcce,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_msg_accepted_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2228;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C222C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2230;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2234;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2238;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C223C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C2240;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1099 start=0x403fc84 */

void _ipc_notify_port_destroyed(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedPortDes,param_1,param_2);
    _ipc_port_release_sonce(param_1);
    _ipc_port_release_receive(param_2);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_destroyed_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2288;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C228C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2290;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2294;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2298;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C229C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C22A0;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}

