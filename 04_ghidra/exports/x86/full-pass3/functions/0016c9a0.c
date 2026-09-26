/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c9a0 */

int _kern_serv_notify(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *param_1;
  if (_kernel_task == *(int *)(_active_threads + 0xc)) {
    iVar2 = _get_kern_port(*(int *)(_active_threads + 0xc),param_3,&local_8);
    if ((iVar2 == 0) &&
       (iVar2 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),param_2,&local_c), iVar2 == 0)
       ) {
      _port_request_notification(local_8,local_c);
      iVar2 = 0;
    }
  }
  else if (*(int *)(iVar2 + 0x1c) == param_2) {
    iVar2 = 0;
  }
  else {
    for (piVar3 = *(int **)(iVar2 + 0x4c0); (int *)(iVar2 + 0x4c0) != piVar3;
        piVar3 = (int *)piVar3[2]) {
      if ((*piVar3 == param_2) && (piVar3[1] == param_3)) {
        return 5;
      }
    }
    piVar3 = (int *)_kalloc(0x10);
    *piVar3 = param_2;
    piVar3[1] = param_3;
    iVar1 = *(int *)(iVar2 + 0x4c4);
    if (iVar2 + 0x4c0 == iVar1) {
      *(int **)(iVar2 + 0x4c0) = piVar3;
    }
    else {
      *(int **)(iVar1 + 8) = piVar3;
    }
    piVar3[3] = iVar1;
    piVar3[2] = iVar2 + 0x4c0;
    *(int **)(iVar2 + 0x4c4) = piVar3;
    iVar2 = 0;
  }
  return iVar2;
}

