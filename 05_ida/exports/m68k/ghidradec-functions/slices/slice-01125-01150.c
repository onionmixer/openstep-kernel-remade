/* GHIDRADEC_FUNCTION index=1125 start=0x4040a30 */

int _ipc_object_copyout_name_compat(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_14;
  undefined auStack_10 [4];
  undefined auStack_c [4];
  int iStack_8;
  
  while( true ) {
    iVar1 = _ipc_entry_alloc_name(param_1,param_4,&iStack_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = _ipc_right_inuse(param_1,param_4,iStack_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,auStack_c,auStack_10), iVar1 != 0)) {
      _ipc_entry_dealloc(param_1,param_4,iStack_8);
      return 0x15;
    }
    if (-1 < *(int *)(param_2 + 4)) {
      _ipc_entry_dealloc(param_1,param_4,iStack_8);
      return 0x14;
    }
    iVar1 = _ipc_port_dnrequest(param_2,param_4,param_1 | 1,&uStack_14);
    if (iVar1 == 0) break;
    _ipc_entry_dealloc(param_1,param_4,iStack_8);
    iVar1 = _ipc_port_dngrow(param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  _ipc_space_reference(param_1);
  *(int *)(iStack_8 + 4) = param_2;
  *(undefined4 *)(iStack_8 + 8) = uStack_14;
  *(byte *)(iStack_8 + 1) = *(byte *)(iStack_8 + 1) | 0x40;
  iVar1 = _ipc_right_copyout(param_1,param_4,iStack_8,param_3,1,param_2);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1126 start=0x4040b40 */

int _ipc_port_timestamp(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_timestamp_data;
  _ipc_port_timestamp_data = _ipc_port_timestamp_data + 1;
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1127 start=0x4040b54 */

undefined4 _ipc_port_dnrequest(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar3 = *(int **)(param_1 + 0x28);
  if ((piVar3 == (int *)0x0) || (iVar2 = *piVar3, iVar2 == 0)) {
    uVar4 = 3;
  }
  else {
    piVar1 = piVar3 + iVar2 * 2;
    *piVar3 = *piVar1;
    piVar1[1] = param_2;
    *piVar1 = param_3;
    *param_4 = iVar2;
    uVar4 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1128 start=0x4040b8e */

undefined4 _ipc_port_dngrow(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = (uint *)param_1[10];
  puVar6 = _ipc_table_dnrequests;
  if (puVar8 != (uint *)0x0) {
    puVar6 = (uint *)(puVar8[1] + 4);
  }
  *param_1 = *param_1 + 1;
  if ((*puVar6 == 0) || (puVar3 = (uint *)_ipc_table_alloc(*puVar6 << 3), puVar3 == (uint *)0x0)) {
    _ipc_object_release(param_1);
    return 6;
  }
  *param_1 = *param_1 + -1;
  if (((param_1[1] < 0) && (puVar8 == (uint *)param_1[10])) &&
     ((puVar8 == (uint *)0x0 || (puVar6 == (uint *)(puVar8[1] + 4))))) {
    puVar5 = (uint *)0x0;
    if (puVar8 == (uint *)0x0) {
      uVar4 = 1;
      uVar7 = 0;
    }
    else {
      puVar5 = (uint *)puVar8[1];
      uVar4 = *puVar5;
      uVar7 = *puVar8;
      _bcopy(puVar8 + 2,puVar3 + 2,uVar4 * 8 + -8);
    }
    uVar1 = *puVar6;
    while (uVar2 = uVar4, uVar2 < uVar1) {
      (puVar3 + uVar2 * 2)[1] = 0;
      puVar3[uVar2 * 2] = uVar7;
      uVar7 = uVar2;
      uVar4 = uVar2 + 1;
    }
    *puVar3 = uVar7;
    puVar3[1] = (uint)puVar6;
    param_1[10] = (int)puVar3;
    if (puVar8 == (uint *)0x0) {
      return 0;
    }
  }
  else {
    puVar5 = puVar6;
    puVar8 = puVar3;
    if (*param_1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(param_1 + 1) & 0x7fff],param_1);
    }
  }
  _ipc_table_free(*puVar5 << 3,puVar8);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1129 start=0x4040c94 */

int _ipc_port_dncancel(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x28);
  piVar1 = piVar3 + param_3 * 2;
  iVar2 = *piVar1;
  piVar1[1] = 0;
  *piVar1 = *piVar3;
  *piVar3 = param_3;
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1130 start=0x4040cb6 */

void _ipc_port_pdrequest(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *param_3 = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1131 start=0x4040cd2 */

void _ipc_port_nsrequest(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  if (((*(int *)(param_1 + 0x18) == 0) && (param_2 <= *(uint *)(param_1 + 0x14))) && (param_3 != 0))
  {
    *(undefined4 *)(param_1 + 0x20) = 0;
    _ipc_notify_no_senders(param_3,*(uint *)(param_1 + 0x14));
  }
  else {
    *(int *)(param_1 + 0x20) = param_3;
  }
  *param_4 = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1132 start=0x4040d20 */

void _ipc_port_set_qlimit(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x38);
  if (uVar1 < param_2) {
    uVar3 = 0;
    if (param_2 != uVar1) {
      do {
        iVar2 = _ipc_thread_dequeue(param_1 + 0x44);
        if (iVar2 == 0) break;
        *(undefined4 *)(iVar2 + 0x94) = 0;
        _thread_go(iVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2 - uVar1);
    }
  }
  *(uint *)(param_1 + 0x38) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1133 start=0x4040d76 */

int * _ipc_port_lock_mqueue(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      return piVar1 + 3;
    }
    _ipc_pset_remove(piVar1,param_1);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  return (int *)(param_1 + 0x3c);
}
/* GHIDRADEC_FUNCTION index=1134 start=0x4040dd2 */

void _ipc_port_set_seqno(int param_1,undefined4 param_2)

{
  _ipc_port_lock_mqueue(param_1);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1135 start=0x4040dfa */

void _ipc_port_clear_receiver(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 == (int *)0x0) {
    _ipc_mqueue_changed(param_1 + 0x3c,0x10004009);
  }
  else {
    _ipc_pset_remove(piVar1,param_1);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1136 start=0x4040e60 */

void _ipc_port_init(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 5;
  _ipc_mqueue_init(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x44) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1137 start=0x4040eb6 */

int _ipc_port_alloc(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _ipc_object_alloc(param_1,0,0x20000,0,&uStack_8,&uStack_c);
  if (iVar1 == 0) {
    _ipc_port_init(uStack_c,param_1,uStack_8);
    *param_2 = uStack_8;
    *param_3 = uStack_c;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1138 start=0x4040f10 */

int _ipc_port_alloc_name(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_object_alloc_name(param_1,0,0x20000,0,param_2,&uStack_8);
  if (iVar1 == 0) {
    _ipc_port_init(uStack_8,param_1,param_2);
    *param_3 = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1139 start=0x4040f62 */

void _ipc_port_delete_compat(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_2,param_3,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 4) == param_1) {
      iVar1 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x3c));
      _ipc_right_destroy(param_2,param_3,iStack_8);
    }
    else {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_notify_port_deleted_compat(iVar1,param_3);
    }
  }
  _ipc_space_release(param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1140 start=0x4040fe0 */

void _ipc_port_destroy(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined *puVar10;
  uint uStack_24;
  uint *puVar11;
  
  puVar10 = &stack0xffffffe0;
  uVar2 = *(uint *)(param_1 + 0x24);
  if (uVar2 == 0) goto loc_4041058;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if ((uVar2 & 1) == 0) {
    uStack_24 = uVar2;
    iVar7 = _ipc_port_check_circularity(param_1);
    if (iVar7 == 0) {
      uStack_24 = param_1;
      _ipc_notify_port_destroyed(uVar2);
      return;
    }
    puVar11 = &uStack_24;
    uStack_24 = uVar2;
    _ipc_port_release_sonce();
  }
  else {
    uVar2 = uVar2 & 0xfffffffe;
    uStack_24 = uVar2;
    iVar7 = _ipc_port_check_circularity(param_1);
    if (iVar7 == 0) {
      uStack_24 = param_1;
      _ipc_notify_port_destroyed_compat(uVar2);
      return;
    }
    puVar11 = &uStack_24;
    uStack_24 = uVar2;
    _ipc_port_release_send();
  }
  while( true ) {
    puVar10 = (undefined *)((int)puVar11 + 4);
loc_4041058:
    *(uint *)(puVar10 + -4) = param_1 + 0x44;
    *(undefined4 *)(puVar10 + -8) = 0x4041062;
    iVar7 = _ipc_thread_dequeue();
    if (iVar7 == 0) break;
    *(undefined4 *)(iVar7 + 0x94) = 0;
    puVar11 = (uint *)(puVar10 + -4);
    *(int *)(puVar10 + -4) = iVar7;
    *(undefined4 *)(puVar10 + -8) = 0x4041076;
    _thread_go();
  }
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0x7f;
  *(undefined4 *)(puVar10 + -4) = 0x4041084;
  uVar8 = _ipc_port_timestamp();
  *(undefined4 *)(param_1 + 8) = uVar8;
  if (*(int *)(param_1 + 0x20) != 0) {
    *(int *)(puVar10 + -4) = *(int *)(param_1 + 0x20);
    *(undefined4 *)(puVar10 + -8) = 0x4041096;
    _ipc_notify_send_once();
  }
  while( true ) {
    *(uint *)(puVar10 + -4) = param_1 + 0x3c;
    *(undefined4 *)(puVar10 + -8) = 0x40410a4;
    iVar7 = _ipc_kmsg_dequeue();
    if (iVar7 == 0) break;
    *(uint *)(puVar10 + -4) = param_1;
    *(undefined4 *)(puVar10 + -8) = 0x40410b4;
    _ipc_object_release();
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    *(int *)(puVar10 + -8) = iVar7;
    *(undefined4 *)(puVar10 + -0xc) = 0x40410c0;
    _ipc_kmsg_destroy();
  }
  puVar3 = *(uint **)(param_1 + 0x28);
  if (puVar3 != (uint *)0x0) {
    puVar4 = (uint *)puVar3[1];
    uVar2 = *puVar4;
    uVar9 = 1;
    puVar6 = puVar3;
    if (1 < uVar2) {
      do {
        uVar5 = puVar6[3];
        if (uVar5 != 0) {
          uVar1 = puVar6[2];
          if ((uVar1 & 1) == 0) {
            *(uint *)(puVar10 + -4) = uVar5;
            *(uint *)(puVar10 + -8) = uVar1;
            *(undefined4 *)(puVar10 + -0xc) = 0x404110a;
            _ipc_notify_dead_name();
          }
          else {
            *(uint *)(puVar10 + -4) = uVar5;
            *(uint *)(puVar10 + -8) = uVar1 & 0xfffffffe;
            *(uint *)(puVar10 + -0xc) = param_1;
            *(undefined4 *)(puVar10 + -0x10) = 0x40410fa;
            _ipc_port_delete_compat();
          }
        }
        uVar9 = uVar9 + 1;
        puVar6 = puVar6 + 2;
      } while (uVar9 < uVar2);
    }
    *(uint **)(puVar10 + -4) = puVar3;
    *(uint *)(puVar10 + -8) = *puVar4 << 3;
    *(undefined4 *)(puVar10 + -0xc) = 0x4041122;
    _ipc_table_free();
  }
  if (*(sword *)(param_1 + 6) != 0) {
    *(uint *)(puVar10 + -4) = param_1;
    *(undefined4 *)(puVar10 + -8) = 0x4041132;
    _ipc_kobject_destroy();
  }
  *(uint *)(puVar10 + -4) = param_1;
  *(undefined4 *)(puVar10 + -8) = 0x404113c;
  _ipc_object_release();
  return;
}
/* GHIDRADEC_FUNCTION index=1141 start=0x4041146 */

undefined4 _ipc_port_check_circularity(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_2 == param_1) {
loc_4041192:
    uVar2 = 1;
  }
  else {
    piVar3 = param_2;
    if (((param_2[1] < 0) && (param_2[3] == 0)) && (piVar1 = param_2, param_2[2] != 0)) {
      do {
        piVar3 = piVar1;
        if ((-1 < piVar3[1]) || (piVar3[3] != 0)) break;
        piVar1 = (int *)piVar3[2];
      } while ((int *)piVar3[2] != (int *)0x0);
      if (piVar3 == param_1) {
        for (; param_2 != (int *)0x0; param_2 = (int *)param_2[2]) {
        }
        goto loc_4041192;
      }
    }
    *param_2 = *param_2 + 1;
    param_1[2] = (int)param_2;
    for (; piVar3 != param_1; param_1 = (int *)param_1[2]) {
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1142 start=0x40411b2 */

int * _ipc_port_lookup_notify(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = _ipc_entry_lookup(param_1,param_2);
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 1) & 2) == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 4);
    *piVar2 = *piVar2 + 1;
    piVar2[7] = piVar2[7] + 1;
  }
  return piVar2;
}
/* GHIDRADEC_FUNCTION index=1143 start=0x40411e6 */

int * _ipc_port_make_send(int *param_1)

{
  param_1[5] = param_1[5] + 1;
  param_1[6] = param_1[6] + 1;
  *param_1 = *param_1 + 1;
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1144 start=0x40411fe */

int * _ipc_port_copy_send(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    if (param_1[1] < 0) {
      *param_1 = *param_1 + 1;
      param_1[6] = param_1[6] + 1;
    }
    else {
      param_1 = (int *)0xffffffff;
    }
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1145 start=0x404122a */

int _ipc_port_copyout_send(int param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  if ((param_1 == 0) || (param_1 == -1)) {
    iStack_8 = param_1;
  }
  else {
    iVar1 = _ipc_object_copyout(param_2,param_1,0x11,1,&iStack_8);
    if (iVar1 != 0) {
      _ipc_port_release_send(param_1);
      if (iVar1 == 0x14) {
        iStack_8 = -1;
      }
      else {
        iStack_8 = 0;
      }
    }
  }
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1146 start=0x404128e */

void _ipc_port_release_send(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (param_1[1] < 0) {
    iVar1 = param_1[6];
    param_1[6] = iVar1 + -1;
    if (iVar1 == 1) {
      iVar2 = param_1[8];
      if (iVar2 == 0) {
        return;
      }
      param_1[8] = 0;
      iVar3 = param_1[5];
    }
    if (iVar2 != 0) {
      _ipc_notify_no_senders(iVar2,iVar3);
    }
  }
  else if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[(param_1[1] & 0x7fffffffU) >> 0x10],param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1147 start=0x4041302 */

int * _ipc_port_make_sonce(int *param_1)

{
  param_1[7] = param_1[7] + 1;
  *param_1 = *param_1 + 1;
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1148 start=0x4041316 */

void _ipc_port_release_sonce(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (param_1[1] < 0) {
    param_1[7] = param_1[7] + -1;
  }
  else if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[(param_1[1] & 0x7fffffffU) >> 0x10],param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1149 start=0x4041358 */

void _ipc_port_release_receive(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _ipc_port_destroy(param_1);
  if (iVar1 != 0) {
    _ipc_object_release(iVar1);
  }
  return;
}

