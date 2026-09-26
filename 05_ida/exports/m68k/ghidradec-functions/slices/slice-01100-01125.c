/* GHIDRADEC_FUNCTION index=1100 start=0x403fd3c */

void _ipc_notify_no_senders(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedNoSende,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_no_senders_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2248;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C224C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2250;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2254;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2258;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C225C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C2260;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1101 start=0x403fdec */

void _ipc_notify_send_once(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _kalloc(0x2c);
  if (iVar1 == 0) {
    _printf(aDroppedSendOnc,param_1);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x2c;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_send_once_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C22A8;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C22AC;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C22B0;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C22B4;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C22B8;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1102 start=0x403fe7c */

void _ipc_notify_dead_name(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedDeadNam,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_dead_name_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2208;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C220C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2210;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2214;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2218;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C221C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C2220;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1103 start=0x403ff2c */

void _ipc_notify_port_deleted_compat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedPortDel_0,param_1,param_2);
    _ipc_port_release_send(param_1);
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
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1104 start=0x403ffe2 */

void _ipc_notify_msg_accepted_compat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedMsgAcce_0,param_1,param_2);
    _ipc_port_release_send(param_1);
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
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1105 start=0x4040098 */

void _ipc_notify_port_destroyed_compat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedPortDes_0,param_1,param_2);
    _ipc_port_release_send(param_1);
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
    *(undefined4 *)(iVar1 + 0x14) = 0x80000011;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1106 start=0x4040158 */

void _ipc_object_reference(int *param_1)

{
  *param_1 = *param_1 + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1107 start=0x4040166 */

void _ipc_object_release(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[*(word *)(param_1 + 1) & 0x7fff],param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1108 start=0x40401a2 */

int _ipc_object_translate(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint *puStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    if ((1 << (param_3 + 0x10U & 0x3f) & *puStack_8) == 0) {
      iVar1 = 0x11;
    }
    else {
      *param_4 = puStack_8[1];
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1109 start=0x40401e8 */

int _ipc_object_alloc_dead(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint *puStack_8;
  
  iVar1 = _ipc_entry_alloc(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    *puStack_8 = *puStack_8 | 0x100001;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1110 start=0x4040212 */

int _ipc_object_alloc_dead_name(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint *puStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_inuse(param_1,param_2,puStack_8);
    if (iVar1 == 0) {
      *puStack_8 = *puStack_8 | 0x100001;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1111 start=0x4040266 */

int _ipc_object_alloc(undefined4 param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                     undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puStack_8;
  
  puVar1 = (undefined4 *)_zalloc((&_ipc_object_zones)[param_2]);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 6;
  }
  else {
    iVar2 = _ipc_entry_alloc(param_1,param_5,&puStack_8);
    if (iVar2 == 0) {
      *puStack_8 = param_4 | param_3 | *puStack_8;
      puStack_8[1] = (uint)puVar1;
      *puVar1 = 1;
      puVar1[1] = param_2 << 0x10 | 0x80000000;
      *param_6 = puVar1;
      iVar2 = 0;
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],puVar1);
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1112 start=0x40402ee */

int _ipc_object_alloc_name
              (undefined4 param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
              undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puStack_8;
  
  puVar1 = (undefined4 *)_zalloc((&_ipc_object_zones)[param_2]);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 6;
  }
  else {
    iVar2 = _ipc_entry_alloc_name(param_1,param_5,&puStack_8);
    if (iVar2 == 0) {
      iVar2 = _ipc_right_inuse(param_1,param_5,puStack_8);
      if (iVar2 == 0) {
        *puStack_8 = param_4 | param_3 | *puStack_8;
        puStack_8[1] = (uint)puVar1;
        *puVar1 = 1;
        puVar1[1] = param_2 << 0x10 | 0x80000000;
        *param_6 = puVar1;
        iVar2 = 0;
      }
      else {
        _zfree((&_ipc_object_zones)[param_2],puVar1);
        iVar2 = 0xd;
      }
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],puVar1);
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1113 start=0x40403a0 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 _ipc_object_copyin_type(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcObjectCopyi);
  case :
  case :
    uVar1 = 0x10;
    break;
  case :
  case :
  case :
  case :
    uVar1 = 0x11;
    break;
  case :
  case :
    uVar1 = 0x12;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1114 start=0x4040430 */

int _ipc_object_copyin(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iStack_c;
  uint *puStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_copyin(param_1,param_2,puStack_8,param_3,1,param_4,&iStack_c);
    if ((*puStack_8 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_1,param_2,puStack_8);
    }
    if ((iVar1 == 0) && (iStack_c != 0)) {
      _ipc_notify_port_deleted(iStack_c,param_2);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1115 start=0x40404b8 */

void _ipc_object_copyin_from_kernel(int *param_1,undefined4 param_2)

{
  switch(param_2) {
  case :
  case :
    param_1[5] = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    break;
  case :
  case :
    if (param_1[1] < 0) {
      param_1[6] = param_1[6] + 1;
    }
    *param_1 = *param_1 + 1;
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcObjectCopyi_0);
  case :
  case :
    break;
  case :
    *param_1 = *param_1 + 1;
    param_1[5] = param_1[5] + 1;
    param_1[6] = param_1[6] + 1;
    break;
  case :
    *param_1 = *param_1 + 1;
    param_1[7] = param_1[7] + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1116 start=0x404055e */

void _ipc_object_destroy(undefined4 param_1,uint param_2)

{
  if (param_2 == 0x11) {
    _ipc_port_release_send(param_1);
  }
  else if (param_2 < 0x12) {
    if (param_2 == 0x10) {
      _ipc_port_release_receive(param_1);
    }
  }
  else if (param_2 == 0x12) {
    _ipc_notify_send_once(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1117 start=0x40405a8 */

int _ipc_object_copyout(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  int iStack_c;
  undefined4 uStack_8;
  
  while( true ) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,&uStack_8,&iStack_c), iVar1 != 0)) break;
    iVar1 = _ipc_entry_get(param_1,&uStack_8,&iStack_c);
    if (iVar1 == 0) {
      if (-1 < *(int *)(param_2 + 4)) {
        _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
        return 0x14;
      }
      *(int *)(iStack_c + 4) = param_2;
      break;
    }
    iVar1 = _ipc_entry_grow_table(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = _ipc_right_copyout(param_1,uStack_8,iStack_c,param_3,param_4,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  *param_5 = uStack_8;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1118 start=0x4040660 */

int _ipc_object_copyout_name
              (undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined auStack_10 [4];
  int iStack_c;
  uint *puStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_5,&puStack_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_3 == 0x12) ||
     (iVar1 = _ipc_right_reverse(param_1,param_2,&iStack_c,auStack_10), iVar1 == 0)) {
    iVar1 = _ipc_right_inuse(param_1,param_5,puStack_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    if (-1 < *(int *)(param_2 + 4)) {
      _ipc_entry_dealloc(param_1,param_5,puStack_8);
      return 0x14;
    }
    puStack_8[1] = param_2;
  }
  else if (param_5 != iStack_c) {
    if ((*puStack_8 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_1,param_5,puStack_8);
    }
    return 0x15;
  }
  iVar1 = _ipc_right_copyout(param_1,param_5,puStack_8,param_3,param_4,param_2);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1119 start=0x404072e */

void _ipc_object_copyout_dest(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = *param_2;
  *param_2 = iVar1 + -1;
  if (param_3 == 0x11) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = param_2[6];
    param_2[6] = iVar1 + -1;
    if ((iVar1 == 1) && (iVar2 = param_2[8], iVar2 != 0)) {
      param_2[8] = 0;
      iVar3 = param_2[5];
    }
    iVar4 = 0;
    if (param_1 == param_2[2]) {
      iVar4 = param_2[3];
    }
    if (iVar2 != 0) {
      _ipc_notify_no_senders(iVar2,iVar3);
    }
  }
  else {
    if (param_3 != 0x12) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcObjectCopyo);
    }
    if (param_1 == param_2[2]) {
      param_2[7] = param_2[7] + -1;
      iVar4 = param_2[3];
    }
    else {
      *param_2 = iVar1;
      _ipc_notify_send_once(param_2);
    }
  }
  *param_4 = iVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=1120 start=0x40407d6 */

int _ipc_object_rename(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_3,&uStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_inuse(param_1,param_3,uStack_8);
    if (iVar1 == 0) {
      if ((param_3 != param_2) && (iVar1 = _ipc_entry_lookup(param_1,param_2), iVar1 != 0)) {
        iVar1 = _ipc_right_rename(param_1,param_2,iVar1,param_3,uStack_8);
        return iVar1;
      }
      _ipc_entry_dealloc(param_1,param_3,uStack_8);
      iVar1 = 0xf;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1121 start=0x404085c */

undefined4 _ipc_object_copyout_type_compat(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x10) {
    uVar1 = 5;
  }
  else {
    if ((param_1 < 0x10) || (0x12 < param_1)) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcObjectCopyo_0);
    }
    uVar1 = 6;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1122 start=0x404088a */

void _ipc_object_copyin_compat
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
  if (iVar1 == 0) {
    _ipc_right_copyin_compat(param_1,param_2,uStack_8,param_3,param_4,param_5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1123 start=0x40408d6 */

void _ipc_object_copyin_header
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
  if (iVar1 == 0) {
    _ipc_right_copyin_header(param_1,param_2,uStack_8,param_3,param_4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1124 start=0x404091e */

int _ipc_object_copyout_compat(uint param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  do {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,&uStack_8,&iStack_c), iVar1 != 0)) {
loc_4040A06:
      iVar1 = _ipc_right_copyout(param_1,uStack_8,iStack_c,param_3,1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = uStack_8;
      return 0;
    }
    iVar1 = _ipc_entry_get(param_1,&uStack_8,&iStack_c);
    if (iVar1 == 0) {
      if (-1 < *(int *)(param_2 + 4)) {
        _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
        return 0x14;
      }
      iVar1 = _ipc_port_dnrequest(param_2,uStack_8,param_1 | 1,&uStack_10);
      if (iVar1 == 0) {
        _ipc_space_reference(param_1);
        *(int *)(iStack_c + 4) = param_2;
        *(undefined4 *)(iStack_c + 8) = uStack_10;
        *(byte *)(iStack_c + 1) = *(byte *)(iStack_c + 1) | 0x40;
        goto loc_4040A06;
      }
      _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
      iVar1 = _ipc_port_dngrow(param_2);
    }
    else {
      iVar1 = _ipc_entry_grow_table(param_1);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  } while( true );
}

