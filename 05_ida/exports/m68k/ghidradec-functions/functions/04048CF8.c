
void _msg_receive(undefined4 **param_1,uint param_2,undefined4 ***param_3)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuVar4;
  undefined4 ***pppuVar5;
  uint uVar6;
  undefined4 ****ppppuVar7;
  uint uStack_50;
  undefined4 *puStack_4c;
  undefined4 **ppuStack_48;
  undefined4 **ppuStack_44;
  undefined4 **ppuStack_40;
  undefined4 ***pppuStack_3c;
  undefined4 ***pppuStack_38;
  undefined4 *puStack_14;
  undefined4 **ppuStack_10;
  undefined4 **ppuStack_c;
  undefined4 *puStack_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppuVar2 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 8);
  pppuVar3 = (undefined4 ***)param_1[3];
  ppuVar4 = (undefined4 **)param_1[1];
  do {
    pppuStack_38 = &ppuStack_c;
    pppuStack_3c = (undefined4 ***)&puStack_8;
    ppuStack_48 = (undefined4 ***)0x4048d38;
    ppuStack_44 = pppuVar1;
    ppuStack_40 = pppuVar3;
    pppuStack_38 = (undefined4 ***)_ipc_mqueue_copyin();
    if (pppuStack_38 != (undefined4 ***)0x0) {
      ppppuVar7 = &pppuStack_38;
      goto loc_4048E14;
    }
    pppuStack_38 = (undefined4 ***)&puStack_14;
    pppuStack_3c = &ppuStack_10;
    ppuStack_40 = (undefined4 ***)0x0;
    ppuStack_44 = (undefined4 ***)0x0;
    ppuStack_48 = param_3;
    puStack_4c = (undefined4 **)0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      puStack_4c = ppuVar4;
    }
    uStack_50 = param_2 & 0x100;
    pppuVar5 = (undefined4 ***)_ipc_mqueue_receive(puStack_8);
    pppuStack_38 = (undefined4 ***)ppuStack_c;
    pppuStack_3c = (undefined4 ***)0x4048d80;
    _ipc_object_release();
    if (pppuVar5 != (undefined4 ***)0x10004005) break;
    while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
      pppuStack_38 = (undefined4 ***)0x0;
      pppuStack_3c = (undefined4 ***)0x4048d94;
      _thread_halt_self_with_continuation();
    }
  } while ((param_2 & 0x400) == 0);
  if (pppuVar5 == (undefined4 ***)0x0) {
    if (ppuVar4 < ppuStack_10[6]) {
      pppuStack_38 = (undefined4 ***)ppuStack_10;
      pppuStack_3c = (undefined4 ***)0x4048e0e;
      _ipc_kmsg_destroy();
      ppppuVar7 = &pppuStack_3c;
      pppuStack_3c = (undefined4 ***)0x10004004;
    }
    else {
      ppuStack_40 = ppuStack_10;
      ppuStack_44 = (undefined4 **)0x4048de0;
      pppuStack_3c = pppuVar1;
      pppuStack_38 = pppuVar2;
      uVar6 = _ipc_kmsg_copyout_compat();
      ppuStack_44 = (undefined4 **)((int)ppuStack_10[4] + (int)ppuStack_10[6]);
      ppuStack_10[6] = ppuStack_44;
      ppuStack_48 = ppuStack_10;
      puStack_4c = param_1;
      uStack_50 = 0x4048dfe;
      _ipc_kmsg_put_to_kernel();
      ppppuVar7 = (undefined4 ****)&uStack_50;
      uStack_50 = uVar6;
    }
  }
  else {
    if (pppuVar5 == (undefined4 ***)0x10004004) {
      param_1[1] = ppuStack_10;
    }
    ppppuVar7 = &pppuStack_38;
    pppuStack_38 = pppuVar5;
  }
loc_4048E14:
  *(undefined4 *)((int)ppppuVar7 + -4) = 0x4048e1a;
  _msg_return_translate();
  return;
}
