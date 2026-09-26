/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001588d4 */

void _msg_receive(undefined4 ***param_1,uint param_2,undefined4 ****param_3)

{
  undefined4 ***pppuVar1;
  undefined4 ****ppppuVar2;
  undefined4 ****ppppuVar3;
  undefined4 ***pppuVar4;
  int iVar5;
  undefined4 ***pppuVar6;
  undefined4 ****ppppuVar7;
  undefined4 **ppuStack_44;
  undefined4 ***pppuStack_40;
  undefined4 **ppuStack_3c;
  undefined4 ***pppuStack_38;
  undefined4 ***pppuStack_34;
  undefined4 ***pppuStack_30;
  undefined1 local_14 [4];
  undefined4 ***local_10;
  undefined4 ***local_c;
  undefined4 *local_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x88);
  ppppuVar2 = *(undefined4 *****)(*(int *)(_active_threads + 0xc) + 0xc);
  ppppuVar3 = (undefined4 ****)param_1[3];
  pppuVar4 = (undefined4 ***)param_1[1];
  do {
    pppuStack_30 = &local_c;
    pppuStack_34 = (undefined4 ***)&local_8;
    pppuStack_40 = (undefined4 ****)0x158912;
    ppuStack_3c = pppuVar1;
    pppuStack_38 = ppppuVar3;
    iVar5 = _ipc_mqueue_copyin();
    pppuVar6 = (undefined4 ***)&stack0xffffffd4;
    if (iVar5 != 0) goto LAB_001589ec;
    pppuStack_30 = (undefined4 ***)local_14;
    pppuStack_34 = &local_10;
    pppuStack_38 = (undefined4 ****)0x0;
    ppuStack_3c = (undefined4 ***)0x0;
    pppuStack_40 = param_3;
    ppuStack_44 = (undefined4 ***)0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      ppuStack_44 = pppuVar4;
    }
    iVar5 = _ipc_mqueue_receive(local_8,param_2 & 0x100);
    pppuStack_30 = local_c;
    pppuStack_34 = (undefined4 ***)0x15895d;
    _ipc_object_release();
    if (iVar5 != 0x10004005) break;
    while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
      pppuStack_30 = (undefined4 ****)0x0;
      pppuStack_34 = (undefined4 ***)0x158973;
      _thread_halt_self_with_continuation();
    }
  } while ((param_2 & 0x400) == 0);
  if (iVar5 == 0) {
    if (pppuVar4 < local_10[6]) {
      pppuStack_30 = local_10;
      pppuStack_34 = (undefined4 ***)0x1589be;
      _ipc_kmsg_destroy();
      ppppuVar7 = &pppuStack_34;
      pppuStack_34 = (undefined4 ***)0x10004004;
      goto LAB_001589ed;
    }
    pppuStack_38 = local_10;
    ppuStack_3c = (undefined4 **)0x1589d3;
    pppuStack_34 = pppuVar1;
    pppuStack_30 = ppppuVar2;
    iVar5 = _ipc_kmsg_copyout_compat();
    ppuStack_3c = (undefined4 **)((int)local_10[6] + (int)local_10[4]);
    local_10[6] = ppuStack_3c;
    pppuStack_40 = local_10;
    pppuVar6 = &ppuStack_44;
    ppuStack_44 = param_1;
    _ipc_kmsg_put_to_kernel();
  }
  else {
    pppuVar6 = (undefined4 ***)&stack0xffffffd4;
    if (iVar5 == 0x10004004) {
      param_1[1] = local_10;
      pppuVar6 = (undefined4 ***)&stack0xffffffd4;
    }
  }
LAB_001589ec:
  ppppuVar7 = (undefined4 ****)((int)pppuVar6 + -4);
  *(int *)((int)pppuVar6 + -4) = iVar5;
LAB_001589ed:
  *(undefined4 *)((int)ppppuVar7 + -4) = 0x1589f2;
  _msg_return_translate();
  return;
}

