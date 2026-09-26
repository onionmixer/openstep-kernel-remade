
uint _mach_msg(undefined4 ***param_1,uint param_2,undefined4 param_3,int **param_4,
              undefined4 param_5)

{
  undefined4 ***pppuVar1;
  int ***pppiVar2;
  int iVar3;
  uint uVar4;
  int ****ppppiVar5;
  undefined4 ***pppuStack_3c;
  int **ppiStack_38;
  int ***pppiStack_34;
  int ***pppiStack_30;
  undefined4 **ppuStack_14;
  undefined4 uStack_10;
  undefined4 **ppuStack_c;
  undefined4 ***pppuStack_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppiVar2 = *(int ****)(*(int *)(_active_threads + 0xc) + 8);
  if ((param_2 & 1) != 0) {
    pppiStack_30 = (int ***)&pppuStack_8;
    pppiStack_34 = (int ***)0x0;
    ppiStack_38 = (int **)param_3;
    pppuStack_3c = param_1;
    iVar3 = _ipc_kmsg_get_from_kernel();
    if (iVar3 != 0) {
      pppiStack_30 = (int ***)aMachMsg;
                    /* WARNING: Subroutine does not return */
      pppiStack_34 = (int ***)0x40489ae;
      _panic();
    }
    pppiStack_30 = (int ***)0x0;
    pppuStack_3c = pppuStack_8;
    ppiStack_38 = (int **)pppuVar1;
    pppiStack_34 = pppiVar2;
    uVar4 = _ipc_kmsg_copyin();
    if (uVar4 != 0) {
      pppiStack_30 = (int ***)pppuStack_8[2];
      if ((int)pppiStack_30 < 1) {
        pppiStack_30 = pppuStack_8;
        pppiStack_34 = (int ***)0x40489da;
        _ipc_kmsg_free();
        return uVar4;
      }
      pppiStack_34 = pppuStack_8;
      ppiStack_38 = (int **)0x40489e8;
      _kfree();
      return uVar4;
    }
    do {
      pppiStack_30 = (int ***)0x0;
      pppiStack_34 = (int ***)0x0;
      ppiStack_38 = (int **)0x0;
      pppuStack_3c = pppuStack_8;
      iVar3 = _ipc_mqueue_send();
    } while (iVar3 == 0x10000007);
  }
  if ((param_2 & 2) != 0) {
    do {
      pppiStack_30 = (int ***)&uStack_10;
      pppiStack_34 = &ppuStack_c;
      ppiStack_38 = (int **)param_5;
      pppuStack_3c = pppuVar1;
      uVar4 = _ipc_mqueue_copyin();
      if (uVar4 != 0) {
        return uVar4;
      }
      pppiStack_30 = &ppuStack_14;
      pppiStack_34 = (int ***)&pppuStack_8;
      ppiStack_38 = (int **)0x0;
      pppuStack_3c = (undefined4 ***)0x0;
      uVar4 = _ipc_mqueue_receive(ppuStack_c,0,0xffffffff,0);
      pppiStack_30 = (int ***)uStack_10;
      pppiStack_34 = (int ***)0x4048a56;
      _ipc_object_release();
    } while (uVar4 == 0x10004005);
    if (uVar4 != 0) {
      return uVar4;
    }
    pppuStack_8[9] = ppuStack_14;
    if (param_4 < pppuStack_8[6]) {
      pppiStack_34 = pppuStack_8;
      ppiStack_38 = (int **)0x4048a88;
      pppiStack_30 = pppuVar1;
      _ipc_kmsg_copyout_dest();
      ppiStack_38 = (int **)0x18;
      pppuStack_3c = pppuStack_8;
      _ipc_kmsg_put_to_kernel(param_1);
      return 0x10004004;
    }
    pppiStack_30 = (int ***)0x0;
    pppuStack_3c = pppuStack_8;
    ppiStack_38 = (int **)pppuVar1;
    pppiStack_34 = pppiVar2;
    uVar4 = _ipc_kmsg_copyout();
    if (uVar4 != 0) {
      if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
        pppiStack_30 = (int ***)((int)pppuStack_8[4] + (int)pppuStack_8[6]);
        ppppiVar5 = &pppiStack_34;
        pppiStack_34 = pppuStack_8;
      }
      else {
        pppiStack_34 = pppuStack_8;
        ppiStack_38 = (int **)0x4048ae0;
        pppiStack_30 = pppuVar1;
        _ipc_kmsg_copyout_dest();
        ppiStack_38 = (int **)0x18;
        ppppiVar5 = &pppuStack_3c;
        pppuStack_3c = pppuStack_8;
      }
      *(undefined4 ****)((int)ppppiVar5 + -4) = param_1;
      *(undefined4 *)((int)ppppiVar5 + -8) = 0x4048af0;
      _ipc_kmsg_put_to_kernel();
      return uVar4;
    }
    pppiStack_30 = (int ***)((int)pppuStack_8[4] + (int)pppuStack_8[6]);
    pppiStack_34 = pppuStack_8;
    ppiStack_38 = (int **)param_1;
    pppuStack_3c = (undefined4 ***)0x4048b0c;
    _ipc_kmsg_put_to_kernel();
  }
  return 0;
}
