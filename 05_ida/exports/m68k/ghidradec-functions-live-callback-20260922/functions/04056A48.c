
int _kern_serv_notify(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar2 = *param_1;
  if (*(int *)(_active_threads + 0xc) == _kernel_task) {
    iVar2 = _get_kern_port(*(int *)(_active_threads + 0xc),param_3,&uStack_8);
    if ((iVar2 == 0) &&
       (iVar2 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),param_2,&uStack_c), iVar2 == 0
       )) {
      _port_request_notification(uStack_8,uStack_c);
      iVar2 = 0;
    }
  }
  else if (param_2 == *(int *)(iVar2 + 0x1c)) {
    iVar2 = 0;
  }
  else {
    for (piVar1 = *(int **)(iVar2 + 0x4c0); piVar1 != (int *)(iVar2 + 0x4c0);
        piVar1 = (int *)piVar1[2]) {
      if ((param_2 == *piVar1) && (param_3 == piVar1[1])) {
        return 5;
      }
    }
    piVar3 = (int *)_kalloc(0x10);
    *piVar3 = param_2;
    piVar3[1] = param_3;
    piVar1 = *(int **)(iVar2 + 0x4c4);
    if (piVar1 == (int *)(iVar2 + 0x4c0)) {
      *piVar1 = (int)piVar3;
    }
    else {
      piVar1[2] = (int)piVar3;
    }
    piVar3[3] = (int)piVar1;
    piVar3[2] = iVar2 + 0x4c0;
    *(int **)(iVar2 + 0x4c4) = piVar3;
    iVar2 = 0;
  }
  return iVar2;
}

