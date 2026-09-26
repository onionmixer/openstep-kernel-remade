
/* WARNING: Removing unreachable block (ram,0xf0093784) */
/* WARNING: Removing unreachable block (ram,0xf009381c) */
/* WARNING: Removing unreachable block (ram,0xf009389c) */
/* WARNING: Removing unreachable block (ram,0xf0093884) */
/* WARNING: Removing unreachable block (ram,0xf00936ec) */
/* WARNING: Removing unreachable block (ram,0xf0093868) */
/* WARNING: Removing unreachable block (ram,0xf0093838) */
/* WARNING: Removing unreachable block (ram,0xf0093810) */
/* WARNING: Removing unreachable block (ram,0xf0093768) */

undefined8 _volioctl(undefined4 param_1,undefined **param_2,short *param_3)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  
  iVar5 = 0;
  if (param_2 == (undefined **)0x80046414) {
    iVar3 = *(int *)(_active_threads + 0xc);
    _get_kern_port(iVar3,*(undefined4 *)param_3,&DAT_f0112510);
    if (iVar3 == 0) {
      _lock_write(&DAT_f0131254);
      if ((undefined **)PTR_LOOP_f0112520 != &PTR_LOOP_f0112520) {
        ppuVar6 = (undefined **)PTR_LOOP_f0112520;
        ppuVar7 = *(undefined ***)PTR_LOOP_f0112520;
        while( true ) {
          ppuVar2 = (undefined **)ppuVar6[1];
          ppuVar1 = ppuVar2;
          if (ppuVar7 != &PTR_LOOP_f0112520) {
            ppuVar7[1] = (undefined *)ppuVar2;
            ppuVar1 = (undefined **)PTR_LOOP_f0112524;
          }
          PTR_LOOP_f0112524 = (undefined *)ppuVar1;
          ppuVar1 = ppuVar7;
          if (ppuVar2 != &PTR_LOOP_f0112520) {
            *ppuVar2 = (undefined *)ppuVar7;
            ppuVar1 = (undefined **)PTR_LOOP_f0112520;
          }
          PTR_LOOP_f0112520 = (undefined *)ppuVar1;
          if ((int)*(short *)(ppuVar6 + 3) != (int)_rootdev) {
            FUN_f00938e4(ppuVar6[2],(int)*(short *)(ppuVar6 + 3),(int)*(short *)((int)ppuVar6 + 0xe)
                         ,ppuVar6[4],ppuVar6[5],ppuVar6 + 6,ppuVar6 + 0x16,ppuVar6[0x18]);
          }
          _kfree(ppuVar6,100);
          if (ppuVar7 == &PTR_LOOP_f0112520) break;
          ppuVar6 = ppuVar7;
          ppuVar7 = (undefined **)*ppuVar7;
        }
      }
      param_2 = &PTR_LOOP_f0112520;
      _lock_done(&DAT_f0131254);
    }
    else {
      iVar5 = 0x16;
    }
    uVar4 = DAT_f0112510;
    if (iVar5 != 0) goto LAB_f00938a4;
  }
  else {
    if ((int)param_2 < -0x7ffb9beb) {
      if (param_2 == (undefined **)0x8002641b) {
        _vol_notify_cancel((int)*param_3);
      }
      else {
        iVar5 = 0x16;
      }
      goto LAB_f00938a4;
    }
    if (param_2 != (undefined **)0x80046416) {
      if (param_2 == (undefined **)0x2000641a) {
        DAT_f0131264 = 1;
      }
      else {
        iVar5 = 0x16;
      }
      goto LAB_f00938a4;
    }
    iVar3 = *(int *)(_active_threads + 0xc);
    _get_kern_port(iVar3,*(undefined4 *)param_3,&_panel_req_port);
    uVar4 = _panel_req_port;
    if (iVar3 != 0) {
      iVar5 = 0x16;
    }
  }
  _port_request_notification(uVar4,DAT_f0112518);
LAB_f00938a4:
  return CONCAT44(param_2,iVar5);
}

