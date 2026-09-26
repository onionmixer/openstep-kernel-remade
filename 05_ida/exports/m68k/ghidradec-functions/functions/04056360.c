
void _kern_server_main(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  word wVar4;
  undefined4 uVar5;
  int iVar6;
  sword sVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  int iStack_44;
  int *apiStack_40 [15];
  
  iStack_44 = _kalloc(0x4d4);
  _bcopy(_kern_serv_proto,apiStack_40,0x3c);
  apiStack_40[0] = &iStack_44;
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x48) = 1;
  }
  _bzero(iStack_44,0x4d4);
  *(undefined4 *)(iStack_44 + 0x4c8) = 0xffffffff;
  uVar5 = _task_self();
  *(undefined4 *)(iStack_44 + 8) = uVar5;
  *(int *)(iStack_44 + 0xc) = _active_threads;
  iVar9 = iStack_44 + 0x34;
  *(int *)(iStack_44 + 0x38) = iVar9;
  *(int *)iVar9 = iVar9;
  piVar3 = (int *)(iStack_44 + 0x3c);
  *(int **)(iStack_44 + 0x40) = piVar3;
  *piVar3 = (int)piVar3;
  iVar9 = iStack_44 + 0x4c0;
  *(int *)(iStack_44 + 0x4c4) = iVar9;
  *(int *)iVar9 = iVar9;
  iVar6 = 0x13;
  iVar8 = 0x17c;
  iVar9 = iStack_44 + 0x130;
  do {
    piVar1 = *(int **)(iStack_44 + 0x40);
    if (piVar1 == piVar3) {
      *piVar3 = iStack_44 + iVar8;
    }
    else {
      piVar1[2] = iStack_44 + iVar8;
    }
    *(int **)(iVar9 + 0x58) = piVar1;
    *(int **)(iVar9 + 0x54) = piVar3;
    *(int *)(iStack_44 + 0x40) = iStack_44 + iVar8;
    iVar8 = iVar8 + -0x10;
    iVar9 = iVar9 + -0x10;
    wVar4 = (word)((uint)iVar6 >> 0x10);
    sVar7 = (sword)iVar6 + -1;
    iVar6 = CONCAT22(wVar4,sVar7);
  } while ((sVar7 != -1) || (iVar6 = (uint)wVar4 * 0x10000 + -1, wVar4 != 0));
  uVar5 = _thread_self(2,&iStack_48);
  iVar9 = _thread_get_special_port_EXTERNAL(uVar5);
  if ((iVar9 != 0) || (iStack_48 == 0)) {
    _printf(aKServerCanTFin);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(int *)(iStack_44 + 0x14) = iStack_48;
  uVar5 = _task_self(&uStack_4c);
  iVar9 = _port_allocate_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAll);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar5 = _thread_self(2,uStack_4c);
  iVar9 = _thread_set_special_port_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTSet);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  uVar5 = _task_self(&uStack_50);
  iVar9 = _port_set_allocate_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAll_0);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(undefined4 *)(iStack_44 + 0x20) = uStack_50;
  uVar5 = _task_self(uStack_50,iStack_48);
  iVar9 = _port_set_add_EXTERNAL(uVar5);
  if (iVar9 != 0) {
    _printf(aKServerCanTAdd);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  iVar9 = _port_allocate_EXTERNAL(*(undefined4 *)(iStack_44 + 8),iStack_44 + 0x1c);
  if (iVar9 == 0) {
    _port_set_add_EXTERNAL
              (*(undefined4 *)(iStack_44 + 8),*(undefined4 *)(iStack_44 + 0x20),
               *(undefined4 *)(iStack_44 + 0x1c));
  }
  else {
    _kern_serv_panic(*(undefined4 *)(iStack_44 + 0x10),aKServerCanTGet);
  }
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    uVar5 = _task_self(2,*(undefined4 *)(iStack_44 + 0x1c));
    _task_set_special_port_EXTERNAL(uVar5);
  }
  _kern_serv_notify(&iStack_44,*(undefined4 *)(iStack_44 + 0x1c),*(undefined4 *)(iStack_44 + 0x10));
  uVar5 = _kern_serv_kernel_task_port();
  *(undefined4 *)(iStack_44 + 0x4cc) = uVar5;
  iVar9 = _kalloc(0x30);
  *(int *)(iStack_44 + 0x44) = iVar9;
  *(undefined4 *)(iStack_44 + 0x48) = 0x30;
loc_40566B0:
  while ((int *)(iStack_44 + 0x34) != *(int **)(iStack_44 + 0x34)) {
    puVar10 = *(undefined4 **)(iStack_44 + 0x34);
    iVar6 = puVar10[2];
    if (iVar6 == iStack_44 + 0x34) {
      *(int *)(iStack_44 + 0x38) = iVar6;
    }
    else {
      *(int *)(iVar6 + 0xc) = iStack_44 + 0x34;
    }
    *(int *)(iStack_44 + 0x34) = iVar6;
    (*(code *)*puVar10)(puVar10[1]);
    puVar2 = *(undefined4 **)(iStack_44 + 0x40);
    if (puVar2 == (undefined4 *)(iStack_44 + 0x3c)) {
      *puVar2 = puVar10;
    }
    else {
      puVar2[2] = puVar10;
    }
    puVar10[3] = puVar2;
    puVar10[2] = iStack_44 + 0x3c;
    *(undefined4 **)(iStack_44 + 0x40) = puVar10;
  }
  while( true ) {
    *(undefined4 *)(iVar9 + 0xc) = uStack_50;
    *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iStack_44 + 0x48);
    iVar6 = _msg_receive(iVar9,0x1500,1000);
    if (iVar6 != -0xcc) break;
    uVar5 = *(undefined4 *)(*(int *)(iStack_44 + 0x44) + 4);
    _kfree(*(int *)(iStack_44 + 0x44),*(undefined4 *)(iStack_44 + 0x48));
    *(undefined4 *)(iStack_44 + 0x48) = uVar5;
    iVar9 = _kalloc(uVar5);
    *(int *)(iStack_44 + 0x44) = iVar9;
  }
  if (-0xcc < iVar6) goto loc_40566F6;
  if (iVar6 != -0xcf) goto loc_4056740;
  goto loc_4056756;
loc_40566F6:
  if (iVar6 != -0xcb) {
    if (iVar6 != 0) {
loc_4056740:
      _kern_serv_panic(*(undefined4 *)(iStack_44 + 0x10),aKernServerMain);
    }
loc_4056756:
    if (*(int *)(iVar9 + 0xc) != *(int *)(iStack_44 + 0x1c)) {
      if (*(int *)(iVar9 + 0x14) - 0x40U < 0xd) {
        for (puVar10 = *(undefined4 **)(iStack_44 + 0x4c0);
            puVar10 != (undefined4 *)(iStack_44 + 0x4c0); puVar10 = (undefined4 *)puVar10[2]) {
          if (puVar10[1] == *(int *)(iVar9 + 0x1c)) {
            *(undefined4 *)(iVar9 + 0x10) = *puVar10;
            _msg_send(iVar9,0,0);
            iVar6 = puVar10[2];
            piVar3 = (int *)puVar10[3];
            if (iVar6 == iStack_44 + 0x4c0) {
              *(int **)(iStack_44 + 0x4c4) = piVar3;
            }
            else {
              *(int **)(iVar6 + 0xc) = piVar3;
            }
            if (piVar3 == (int *)(iStack_44 + 0x4c0)) {
              *piVar3 = iVar6;
            }
            else {
              piVar3[2] = iVar6;
            }
            _kfree(puVar10,0x10);
          }
        }
      }
      *(undefined4 *)(iStack_44 + 4) = *(undefined4 *)(iVar9 + 0xc);
      iVar6 = sub_405691C(iVar9,iStack_44);
      if ((iVar6 == -0x12f) && (*(int *)(iVar9 + 0xc) == iStack_48)) {
        _kern_serv_handler(iVar9,apiStack_40);
      }
      goto loc_40566B0;
    }
    if (*(int *)(iVar9 + 0x14) == 0x41) {
      if (*(code **)(iStack_44 + 0x4b8) == (code *)0x0) {
        if (*(code **)(iStack_44 + 0x4bc) != (code *)0x0) {
          (**(code **)(iStack_44 + 0x4bc))(*(undefined4 *)(iVar9 + 0x1c),0x41);
        }
      }
      else {
        iVar6 = (**(code **)(iStack_44 + 0x4b8))(*(undefined4 *)(iVar9 + 0x1c));
        if (iVar6 != 0) goto loc_40566B0;
      }
      _kern_serv_port_gone(&iStack_44,*(undefined4 *)(iVar9 + 0x1c));
      goto loc_40566B0;
    }
    if (*(code **)(iStack_44 + 0x4bc) != (code *)0x0) {
      (**(code **)(iStack_44 + 0x4bc))(*(undefined4 *)(iVar9 + 0x1c),*(int *)(iVar9 + 0x14));
    }
  }
  goto loc_40566B0;
}
