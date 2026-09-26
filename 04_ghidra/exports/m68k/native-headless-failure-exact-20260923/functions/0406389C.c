
undefined4 _volioctl(undefined4 param_1,int param_2,short *param_3)

{
  undefined **ppuVar1;
  int *piVar2;
  undefined **ppuVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  if (param_2 == -0x7ffb9bec) {
    iVar5 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),*(undefined4 *)param_3,
                           &DAT_040b06ec);
    if (iVar5 == 0) {
      _lock_write(&DAT_040b4e82);
      ppuVar3 = (undefined **)PTR_LOOP_040b06fc;
      while (ppuVar3 != &PTR_LOOP_040b06fc) {
        ppuVar1 = (undefined **)*ppuVar3;
        piVar2 = (int *)ppuVar3[1];
        piVar4 = piVar2;
        if (ppuVar1 != &PTR_LOOP_040b06fc) {
          ppuVar1[1] = (undefined *)piVar2;
          piVar4 = (int *)PTR_LOOP_040b0700;
        }
        PTR_LOOP_040b0700 = (undefined *)piVar4;
        *piVar2 = (int)ppuVar1;
        if (*(short *)(ppuVar3 + 3) != _rootdev) {
          FUN_04063a24(ppuVar3[2],(int)*(short *)(ppuVar3 + 3),(int)*(short *)((int)ppuVar3 + 0xe),
                       ppuVar3[4],ppuVar3[5],ppuVar3 + 6,ppuVar3 + 0x16,
                       *(undefined4 *)((int)ppuVar3 + 0x5e));
        }
        _kfree(ppuVar3,0x62);
        ppuVar3 = ppuVar1;
      }
      _lock_done(&DAT_040b4e82);
      _port_request_notification(DAT_040b06ec,DAT_040b06f4);
      return 0;
    }
  }
  else if (param_2 < -0x7ffb9beb) {
    if (param_2 == -0x7ffd9be5) {
      _vol_notify_cancel((int)*param_3);
      return 0;
    }
  }
  else if (param_2 == -0x7ffb9bea) {
    iVar5 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),*(undefined4 *)param_3,
                           &_panel_req_port);
    if (iVar5 != 0) {
      uVar6 = 0x16;
    }
    _port_request_notification(_panel_req_port,DAT_040b06f4);
    return uVar6;
  }
  return 0x16;
}

