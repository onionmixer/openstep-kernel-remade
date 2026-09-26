/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184bf0 */

undefined4 _volioctl(undefined4 param_1,int param_2,short *param_3)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  if (param_2 == -0x7ffb9bec) {
    iVar5 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),*(undefined4 *)param_3,
                           &DAT_001e13ec);
    if (iVar5 == 0) {
      _lock_write(&DAT_001e758c);
      ppuVar3 = (undefined **)PTR_LOOP_001e13fc;
      while (ppuVar3 != &PTR_LOOP_001e13fc) {
        ppuVar1 = (undefined **)*ppuVar3;
        ppuVar2 = (undefined **)ppuVar3[1];
        ppuVar4 = ppuVar2;
        if (ppuVar1 != &PTR_LOOP_001e13fc) {
          ppuVar1[1] = (undefined *)ppuVar2;
          ppuVar4 = (undefined **)PTR_LOOP_001e1400;
        }
        PTR_LOOP_001e1400 = (undefined *)ppuVar4;
        ppuVar4 = ppuVar1;
        if (ppuVar2 != &PTR_LOOP_001e13fc) {
          *ppuVar2 = (undefined *)ppuVar1;
          ppuVar4 = (undefined **)PTR_LOOP_001e13fc;
        }
        PTR_LOOP_001e13fc = (undefined *)ppuVar4;
        if (_rootdev != *(short *)(ppuVar3 + 3)) {
          FUN_00184d9c(ppuVar3[2],(int)*(short *)(ppuVar3 + 3),(int)*(short *)((int)ppuVar3 + 0xe),
                       ppuVar3[4],ppuVar3[5],ppuVar3 + 6,ppuVar3 + 0x16,ppuVar3[0x18]);
        }
        _kfree(ppuVar3,100);
        ppuVar3 = ppuVar1;
      }
      _lock_done(&DAT_001e758c);
      uVar6 = DAT_001e13ec;
LAB_00184d3b:
      _port_request_notification(uVar6,DAT_001e13f4);
      return uVar7;
    }
  }
  else if (param_2 < -0x7ffb9beb) {
    if (param_2 == -0x7ffd9be5) {
      _vol_notify_cancel((int)*param_3);
      return 0;
    }
  }
  else {
    if (param_2 == -0x7ffb9bea) {
      iVar5 = _get_kern_port(*(undefined4 *)(_active_threads + 0xc),*(undefined4 *)param_3,
                             &_panel_req_port);
      uVar6 = _panel_req_port;
      if (iVar5 != 0) {
        uVar7 = 0x16;
      }
      goto LAB_00184d3b;
    }
    if (param_2 == 0x2000641a) {
      DAT_001e759c = 1;
      return 0;
    }
  }
  return 0x16;
}

