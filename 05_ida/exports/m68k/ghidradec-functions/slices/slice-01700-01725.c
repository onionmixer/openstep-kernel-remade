/* GHIDRADEC_FUNCTION index=1700 start=0x4056b28 */

void _kern_serv_wire_range(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_pageable(*(undefined4 *)(_kernel_task + 8),~_page_mask & param_2,
                   ~_page_mask & _page_mask + param_3 + param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1701 start=0x4056b64 */

void _kern_serv_unwire_range(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_pageable(*(undefined4 *)(_kernel_task + 8),~_page_mask & param_2,
                   ~_page_mask & _page_mask + param_3 + param_2,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1702 start=0x4056ba2 */

int _kern_serv_port_proc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (param_2 == *(int *)(iVar1 + 0x4ac)) {
    *(undefined4 *)(iVar1 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (param_2 == *(int *)(iVar3 + 0x18c)) {
      *(undefined4 *)(iVar3 + 0x18c) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (*(int *)(iVar3 + 0x18c) == 0) break;
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar3 = 6;
  if (iVar2 != 0x32) {
    iVar3 = _port_set_add_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20),param_2)
    ;
    if (iVar3 == 0) {
      iVar1 = iVar1 + iVar2 * 0x10;
      *(int *)(iVar1 + 0x18c) = param_2;
      *(undefined4 *)(iVar1 + 400) = param_3;
      *(undefined4 *)(iVar1 + 0x194) = param_4;
      *(undefined4 *)(iVar1 + 0x198) = 0;
      iVar3 = 0;
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1703 start=0x4056c32 */

int _kern_serv_port_serv(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (param_2 == *(int *)(iVar1 + 0x4ac)) {
    *(undefined4 *)(iVar1 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (param_2 == *(int *)(iVar3 + 0x18c)) {
      *(undefined4 *)(iVar3 + 0x18c) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (*(int *)(iVar3 + 0x18c) == 0) break;
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  iVar3 = 6;
  if (iVar2 != 0x32) {
    iVar3 = _port_set_add_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20),param_2)
    ;
    if (iVar3 == 0) {
      iVar1 = iVar1 + iVar2 * 0x10;
      *(int *)(iVar1 + 0x18c) = param_2;
      *(undefined4 *)(iVar1 + 400) = param_3;
      *(undefined4 *)(iVar1 + 0x194) = param_4;
      *(undefined4 *)(iVar1 + 0x198) = 1;
      iVar3 = 0;
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1704 start=0x4056cc4 */

undefined4 _kern_serv_port_death_proc(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x4b8) = param_2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1705 start=0x4056cda */

undefined4 _kern_serv_call_proc(undefined4 param_1,code *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == (code *)0x0) {
    uVar1 = 100;
  }
  else {
    (*param_2)(param_3);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1706 start=0x4056cf6 */

void _kern_serv_shutdown(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x30) != 0) {
    sub_405709E(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    if (*(int *)(iVar3 + 0x18c) != 0) {
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18c));
      *(undefined4 *)(iVar3 + 0x18c) = 0;
      *(undefined4 *)(iVar3 + 400) = 0;
    }
    iVar3 = iVar3 + 0x10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x32);
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x14));
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x1c));
  _port_set_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x20));
  _kfree(*(undefined4 *)(iVar1 + 0x44),*(undefined4 *)(iVar1 + 0x48));
  _kfree(iVar1,0x4d4);
  _thread_terminate(_active_threads);
  do {
    _thread_halt_self();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1707 start=0x4056da6 */

undefined4 _kern_serv_log_level(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x30);
  *(int *)(iVar1 + 0x30) = param_2;
  if (iVar2 == 0) {
    if (param_2 != 0) {
      sub_4057042(iVar1 + 0x24,500);
      return 0;
    }
  }
  else if (param_2 != 0) {
    return 0;
  }
  if (iVar2 != 0) {
    sub_405709E(iVar1 + 0x24);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1708 start=0x4056dec */

undefined4 _kern_serv_get_log(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x30) == 0) {
    _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),param_2);
    uVar4 = 0x65;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x24);
    if (iVar2 == *(int *)(iVar1 + 0x28)) {
      *(undefined4 *)(iVar1 + 0x18) = param_2;
    }
    else {
      uVar3 = ~_page_mask & _page_mask + (*(int *)(iVar1 + 0x28) - iVar2);
      _vm_read_EXTERNAL(*(undefined4 *)(iVar1 + 0x4cc),iVar2,uVar3,&uStack_8,auStack_c);
      _kern_serv_log_data(param_2,uStack_8,*(int *)(iVar1 + 0x28) - *(int *)(iVar1 + 0x24) >> 5);
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),param_2);
      _vm_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),uStack_8,uVar3);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0x24);
    }
    uVar4 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1709 start=0x4056ea2 */

void _kern_serv_log(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  if ((param_2 <= *(int *)(iVar1 + 0x30)) && (*(int *)(iVar1 + 0x24) != 0)) {
    puVar2 = *(undefined4 **)(iVar1 + 0x28);
    *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x20;
    if (*(int *)(iVar1 + 0x28) == *(int *)(iVar1 + 0x2c)) {
      *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + -0x20;
    }
    else {
      *puVar2 = param_3;
      puVar2[1] = param_4;
      puVar2[2] = param_5;
      puVar2[3] = param_6;
      puVar2[4] = param_7;
      puVar2[5] = param_8;
      uVar4 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar4) & 0x80000) != 0) {
        uVar4 = uVar4 + 0x80000;
      }
      puVar2[6] = uVar3 | uVar4;
      puVar2[7] = param_2;
      if (*(int *)(iVar1 + 0x18) != 0) {
        _kern_serv_callout(param_1,sub_4056F98,iVar1);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1710 start=0x40570de */

undefined4 _kern_serv_callout(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *param_1;
  iVar5 = _curipl();
  if ((iVar5 == 0) && (iVar5 = _task_self(), iVar5 == *(int *)(iVar1 + 8))) {
    (*param_2)(param_3);
  }
  else {
    piVar4 = (int *)(iVar1 + 0x3c);
    piVar2 = (int *)*piVar4;
    if (piVar2 == piVar4) {
      return 6;
    }
    piVar3 = (int *)piVar2[2];
    if (piVar3 == piVar4) {
      *(int **)(iVar1 + 0x40) = piVar3;
    }
    else {
      piVar3[3] = (int)piVar4;
    }
    *(int **)(iVar1 + 0x3c) = piVar3;
    *piVar2 = (int)param_2;
    piVar2[1] = param_3;
    piVar4 = *(int **)(iVar1 + 0x38);
    if (piVar4 == (int *)(iVar1 + 0x34)) {
      *piVar4 = (int)piVar2;
    }
    else {
      piVar4[2] = (int)piVar2;
    }
    piVar2[3] = (int)piVar4;
    piVar2[2] = iVar1 + 0x34;
    *(int **)(iVar1 + 0x38) = piVar2;
    _calloutDispatchUnique(sub_405718E,*(undefined4 *)(iVar1 + 0xc));
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1711 start=0x40571aa */

undefined4 _kern_serv_local_port(int *param_1)

{
  return *(undefined4 *)(*param_1 + 4);
}
/* GHIDRADEC_FUNCTION index=1712 start=0x40571bc */

undefined4 _kern_serv_bootstrap_port(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x10);
}
/* GHIDRADEC_FUNCTION index=1713 start=0x40571ce */

undefined4 _kern_serv_notify_port(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x1c);
}
/* GHIDRADEC_FUNCTION index=1714 start=0x40571e0 */

undefined4 _kern_serv_port_set(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x20);
}
/* GHIDRADEC_FUNCTION index=1715 start=0x40571f2 */

int _kern_serv_kernel_task_port(void)

{
  int iStack_8;
  
  _task_reference(_kernel_task);
  iStack_8 = _convert_task_to_port(_kernel_task);
  if (iStack_8 == 0) {
    iStack_8 = 0;
  }
  else {
    _object_copyout(*(undefined4 *)(_active_threads + 0xc),iStack_8,6,&iStack_8);
  }
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1716 start=0x405723c */

void _notify_server_loop(void)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x48) = 1;
  iVar2 = *(int *)(_active_threads + 0xc);
  iVar1 = _port_allocate(*(undefined4 *)(iVar2 + 0x7c),&dword_40B4DDC);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aPortAllocate);
  }
  _get_kern_port(iVar2,dword_40B4DDC,&dword_40B4DE0);
  iVar1 = _task_set_special_port(iVar2,2,dword_40B4DE0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aTaskSetSpecial);
  }
  iVar1 = _port_allocate(*(undefined4 *)(iVar2 + 0x7c),&_pn_register_port);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar1,aPortAllocate);
  }
  _get_kern_port(iVar2,_pn_register_port,&_pn_register_port_k);
  iVar1 = _port_set_allocate(*(undefined4 *)(iVar2 + 0x7c),&dword_40B4DE4);
  if (iVar1 == 0) {
    iVar1 = _port_set_add(*(undefined4 *)(iVar2 + 0x7c),dword_40B4DE4,dword_40B4DDC);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      sub_4057404(iVar1,aPortSetAdd);
    }
    iVar2 = _port_set_add(*(undefined4 *)(iVar2 + 0x7c),dword_40B4DE4,_pn_register_port);
    if (iVar2 == 0) {
      iVar2 = _kalloc(0x2000);
      dword_40B4DEC = &dword_40B4DE8;
      dword_40B4DE8 = &dword_40B4DE8;
      do {
        while( true ) {
          while( true ) {
            *(undefined4 *)(iVar2 + 0xc) = dword_40B4DE4;
            *(undefined4 *)(iVar2 + 4) = 0x2000;
            iVar1 = _msg_receive(iVar2,0,0);
            if (iVar1 == 0) break;
            _printf(aNotifyServerLo,iVar1);
          }
          if (*(int *)(iVar2 + 0xc) != _pn_register_port) break;
          sub_405742C(iVar2);
        }
        if (*(int *)(iVar2 + 0xc) == dword_40B4DDC) {
          sub_4057498(iVar2);
        }
        else {
          _printf(aNotifyServerLo_0);
        }
      } while( true );
    }
                    /* WARNING: Subroutine does not return */
    sub_4057404(iVar2,aPortSetAdd);
  }
                    /* WARNING: Subroutine does not return */
  sub_4057404(iVar1,aPortSetAllocat);
}
/* GHIDRADEC_FUNCTION index=1717 start=0x405759c */

void _port_request_notification(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_30 = dword_40AFF54;
  uStack_2c = dword_40AFF58;
  uStack_28 = dword_40AFF5C;
  uStack_1c = dword_40AFF68;
  uStack_18 = dword_40AFF6C;
  uStack_c = dword_40AFF78;
  uStack_14 = param_1;
  uStack_10 = param_2;
  uStack_24 = 0;
  uStack_20 = _pn_register_port_k;
  uStack_8 = param_1;
  iVar1 = _msg_send_from_kernel(&uStack_30,1,0);
  if (iVar1 != 0) {
    _printf(aPortRequestNot,iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1718 start=0x4057640 */

void _pnotify_start(void)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  _task_create(_kernel_task,0,&uStack_8);
  _task_deallocate(uStack_8);
  _thread_create(uStack_8,&uStack_c);
  _thread_deallocate(uStack_c);
  _thread_start(uStack_c,_notify_server_loop);
  _thread_resume(uStack_c);
  return;
}
/* GHIDRADEC_FUNCTION index=1719 start=0x405769a */

undefined4 _get_kern_port(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    *param_3 = 0;
  }
  else {
    iVar1 = _object_copyin(param_1,param_2,6,0,param_3);
    if (iVar1 == 0) {
      return 4;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1720 start=0x4057d74 */

undefined4 _kern_serv_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined auStack_24 [3];
  undefined uStack_21;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_21 = 1;
  uStack_20 = 0x20;
  uStack_1c = *(undefined4 *)(param_1 + 8);
  uStack_18 = 0;
  uStack_14 = *(undefined4 *)(param_1 + 0x10);
  iStack_10 = *(int *)(param_1 + 0x14) + 100;
  uStack_c = 0x2200018;
  iStack_8 = -0x12f;
  if ((*(int *)(param_1 + 0x14) - 100U < 0xd) &&
     (*(code **)(unk_40ACEE2 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40ACEE2 + *(int *)(param_1 + 0x14) * 4))(param_1,auStack_24,param_2);
    if (iStack_8 == -0x131) {
      uVar1 = 0;
    }
    else {
      uVar1 = _msg_send(auStack_24,CARRY4(~*(uint *)(param_2 + 4),~*(uint *)(param_2 + 4)),
                        *(undefined4 *)(param_2 + 4));
    }
  }
  else {
    uVar1 = 0xfffffed1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1721 start=0x4057e20 */

int _kern_serv_panic(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_128 [3];
  char cStack_125;
  int iStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  undefined auStack_104 [255];
  undefined uStack_5;
  
  iStack_110 = 0xc;
  iStack_10c = 0xc0800;
  uStack_108 = 1;
  _strncpy(auStack_104,param_2,0x100);
  uStack_5 = 0;
  cStack_125 = '\x01';
  iStack_124 = 0x124;
  uStack_120 = 0x100;
  uStack_118 = param_1;
  uStack_11c = _mig_get_reply_port();
  iStack_114 = 200;
  iVar1 = _msg_rpc(auStack_128,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_114 == 300) {
      if (((iStack_124 == 0x20) && (cStack_125 == '\x01')) && (iStack_110 == 0x2200018)) {
        iVar1 = iStack_10c;
        if (iStack_10c == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1722 start=0x4057f06 */

int _kern_serv_section_by_name
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  int iVar1;
  undefined auStack_44 [3];
  char cStack_41;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined auStack_14 [15];
  undefined uStack_5;
  
  iStack_2c = 0xc800018;
  _strncpy(&iStack_28,param_2,0x10);
  uStack_1c = uStack_1c & 0xffffff00;
  uStack_18 = 0xc800018;
  _strncpy(auStack_14,param_3,0x10);
  uStack_5 = 0;
  cStack_41 = '\x01';
  iStack_40 = 0x40;
  uStack_3c = 0x100;
  uStack_34 = param_1;
  uStack_38 = _mig_get_reply_port();
  iStack_30 = 0xc9;
  iVar1 = _msg_rpc(auStack_44,0,0x30,0,0);
  if (iVar1 == 0) {
    if (iStack_30 == 0x12d) {
      if ((((iStack_40 == 0x30) && (cStack_41 == '\x01')) ||
          ((iStack_40 == 0x20 && ((cStack_41 == '\x01' && (iStack_28 != 0)))))) &&
         (iStack_2c == 0x2200018)) {
        if (iStack_28 != 0) {
          return iStack_28;
        }
        if ((iStack_24 == 0x2200018) && (*param_4 = uStack_20, uStack_1c == 0x2200018)) {
          *param_5 = uStack_18;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1723 start=0x4058032 */

void _kern_serv_log_data(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined auStack_2c [3];
  undefined uStack_29;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  uStack_14 = 6;
  uStack_10 = 0x20020;
  uStack_8 = param_2;
  iStack_c = param_3 << 3;
  uStack_29 = 0;
  uStack_28 = 0x28;
  uStack_24 = 0;
  uStack_1c = param_1;
  uStack_20 = 0;
  uStack_18 = 0xca;
  _msg_send(auStack_2c,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1724 start=0x405813c */

bool _exc_server(int param_1,int param_2)

{
  bool bVar1;
  
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x2200018;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  bVar1 = *(int *)(param_1 + 0x14) == 0x960;
  if (bVar1) {
    sub_4058090(param_1,param_2);
  }
  return bVar1;
}

