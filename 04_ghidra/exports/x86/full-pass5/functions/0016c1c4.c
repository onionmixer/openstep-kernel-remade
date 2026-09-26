/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c1c4 */

void _kern_server_main(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int ***pppiVar6;
  int *local_5c;
  int local_58;
  int local_50;
  undefined4 local_4c;
  int local_48;
  int *local_44;
  int **local_40 [15];
  
  local_44 = (int *)_kalloc(0x4d4);
  puVar5 = &_kern_serv_proto;
  pppiVar6 = local_40;
  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pppiVar6 = (int **)*puVar5;
    puVar5 = puVar5 + 1;
    pppiVar6 = pppiVar6 + 1;
  }
  local_40[0] = &local_44;
  if (_kernel_task != *(int *)(_active_threads + 0xc)) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  }
  _bzero(local_44,0x4d4);
  local_44[0x132] = -1;
  iVar4 = _task_self();
  local_44[2] = iVar4;
  local_44[3] = _active_threads;
  *local_44 = 0;
  local_44[0xe] = (int)(local_44 + 0xd);
  local_44[0xd] = (int)(local_44 + 0xd);
  piVar2 = local_44 + 0xf;
  local_44[0x10] = (int)piVar2;
  local_44[0xf] = (int)piVar2;
  local_44[0x131] = (int)(local_44 + 0x130);
  local_44[0x130] = (int)(local_44 + 0x130);
  local_58 = 0x13;
  iVar4 = 0x17c;
  local_5c = local_44 + 0x4c;
  do {
    piVar1 = (int *)local_44[0x10];
    if (piVar2 == piVar1) {
      local_44[0xf] = iVar4 + (int)local_44;
    }
    else {
      piVar1[2] = iVar4 + (int)local_44;
    }
    local_5c[0x16] = (int)piVar1;
    local_5c[0x15] = (int)piVar2;
    local_44[0x10] = iVar4 + (int)local_44;
    iVar4 = iVar4 + -0x10;
    local_5c = local_5c + -4;
    local_58 = local_58 + -1;
  } while (-1 < local_58);
  uVar3 = _thread_self(2,&local_48);
  iVar4 = _thread_get_special_port_EXTERNAL(uVar3);
  if ((iVar4 != 0) || (local_48 == 0)) {
    _printf(s_k_server__can_t_find_listener_po_001dfd90);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  local_44[5] = local_48;
  uVar3 = _task_self(&local_4c);
  iVar4 = _port_allocate_EXTERNAL(uVar3);
  if (iVar4 != 0) {
    _printf(s_k_server__can_t_allocate_reply_p_001dfdc1);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar3 = _thread_self(2,local_4c);
  iVar4 = _thread_set_special_port_EXTERNAL(uVar3);
  if (iVar4 != 0) {
    _printf(s_k_server__can_t_set_reply_port___001dfdf3);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar3 = _task_self(&local_50);
  iVar4 = _port_set_allocate_EXTERNAL(uVar3);
  if (iVar4 != 0) {
    _printf(s_k_server__can_t_allocate_port_se_001dfe20);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  local_44[8] = local_50;
  uVar3 = _task_self(local_50,local_48);
  iVar4 = _port_set_add_EXTERNAL(uVar3);
  if (iVar4 != 0) {
    _printf(s_k_server__can_t_add_listener_por_001dfe50);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  iVar4 = _port_allocate_EXTERNAL(local_44[2],local_44 + 7);
  if (iVar4 == 0) {
    _port_set_add_EXTERNAL(local_44[2],local_44[8],local_44[7]);
  }
  else {
    _kern_serv_panic(local_44[4],s_k_server__can_t_get_notify_port_001dfe73);
  }
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    uVar3 = _task_self(2,local_44[7]);
    _task_set_special_port_EXTERNAL(uVar3);
  }
  _kern_serv_notify(&local_44,local_44[7],local_44[4]);
  iVar4 = _kern_serv_kernel_task_port();
  local_44[0x133] = iVar4;
  local_58 = _kalloc(0x30);
  local_44[0x11] = local_58;
  local_44[0x12] = 0x30;
LAB_0016c488:
  local_5c = (int *)_splhigh();
  do {
    do {
    } while (*local_44 != 0);
    LOCK();
    iVar4 = *local_44;
    *local_44 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  while ((int *)local_44[0xd] != local_44 + 0xd) {
    puVar5 = (undefined4 *)local_44[0xd];
    piVar2 = (int *)puVar5[2];
    if (local_44 + 0xd == piVar2) {
      local_44[0xe] = (int)piVar2;
    }
    else {
      piVar2[3] = (int)(local_44 + 0xd);
    }
    local_44[0xd] = (int)piVar2;
    LOCK();
    *local_44 = 0;
    UNLOCK();
    _splx(local_5c);
    (*(code *)*puVar5)(puVar5[1]);
    local_5c = (int *)_splhigh();
    do {
      do {
      } while (*local_44 != 0);
      LOCK();
      iVar4 = *local_44;
      *local_44 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    piVar2 = (int *)local_44[0x10];
    if (local_44 + 0xf == piVar2) {
      local_44[0xf] = (int)puVar5;
    }
    else {
      piVar2[2] = (int)puVar5;
    }
    puVar5[3] = piVar2;
    puVar5[2] = local_44 + 0xf;
    local_44[0x10] = (int)puVar5;
  }
  LOCK();
  *local_44 = 0;
  UNLOCK();
  _splx(local_5c);
  while( true ) {
    *(int *)(local_58 + 0xc) = local_50;
    *(int *)(local_58 + 4) = local_44[0x12];
    iVar4 = _msg_receive(local_58,0x1500,1000);
    if (iVar4 != -0xcc) break;
    iVar4 = *(int *)(local_44[0x11] + 4);
    _kfree(local_44[0x11],local_44[0x12]);
    local_44[0x12] = iVar4;
    local_58 = _kalloc(iVar4);
    local_44[0x11] = local_58;
  }
  if (-0xcc < iVar4) goto LAB_0016c584;
  if (iVar4 != -0xcf) goto LAB_0016c5c8;
  goto LAB_0016c5dc;
LAB_0016c584:
  if (iVar4 != -0xcb) {
    if (iVar4 != 0) {
LAB_0016c5c8:
      _kern_serv_panic(local_44[4],s_kern_server_main__received_retur_001dfe93);
    }
LAB_0016c5dc:
    if (*(int *)(local_58 + 0xc) == local_44[7]) {
      if (*(int *)(local_58 + 0x14) != 0x41) {
        if ((code *)local_44[0x12f] != (code *)0x0) {
          (*(code *)local_44[0x12f])(*(undefined4 *)(local_58 + 0x1c),*(int *)(local_58 + 0x14));
        }
        goto LAB_0016c488;
      }
      if ((code *)local_44[0x12e] == (code *)0x0) {
        if ((code *)local_44[0x12f] != (code *)0x0) {
          (*(code *)local_44[0x12f])(*(undefined4 *)(local_58 + 0x1c),0x41);
        }
      }
      else {
        iVar4 = (*(code *)local_44[0x12e])(*(undefined4 *)(local_58 + 0x1c));
        if (iVar4 != 0) goto LAB_0016c488;
      }
      _kern_serv_port_gone(&local_44,*(undefined4 *)(local_58 + 0x1c));
      goto LAB_0016c488;
    }
    if ((*(int *)(local_58 + 0x14) - 0x40U < 0xd) &&
       (local_5c = (int *)local_44[0x130], local_44 + 0x130 != local_5c)) {
      do {
        if (local_5c[1] == *(int *)(local_58 + 0x1c)) {
          *(int *)(local_58 + 0x10) = *local_5c;
          _msg_send(local_58,0,0);
          piVar2 = (int *)local_5c[2];
          piVar1 = (int *)local_5c[3];
          if (local_44 + 0x130 == piVar2) {
            local_44[0x131] = (int)piVar1;
          }
          else {
            piVar2[3] = (int)piVar1;
          }
          if (local_44 + 0x130 == piVar1) {
            local_44[0x130] = (int)piVar2;
          }
          else {
            piVar1[2] = (int)piVar2;
          }
          _kfree(local_5c,0x10);
        }
        local_5c = (int *)local_5c[2];
      } while (local_44 + 0x130 != local_5c);
    }
    local_44[1] = *(int *)(local_58 + 0xc);
    iVar4 = FUN_0016c758(local_58,local_44);
    if ((iVar4 == -0x12f) && (*(int *)(local_58 + 0xc) == local_48)) {
      _kern_serv_handler(local_58,local_40);
    }
  }
  goto LAB_0016c488;
}

