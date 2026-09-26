/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00154458 */

undefined4
_msg_receive_trap(undefined4 ***param_1,uint param_2,undefined4 ***param_3,undefined4 ****param_4,
                 undefined4 ****param_5)

{
  undefined4 ***pppuVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 ***pppuVar6;
  undefined4 **ppuStack_44;
  undefined4 ***pppuStack_40;
  undefined4 **ppuStack_3c;
  undefined4 ***pppuStack_38;
  undefined4 ***pppuStack_34;
  undefined4 ***pppuStack_30;
  undefined4 ***local_18;
  undefined1 local_14 [4];
  undefined4 ***local_10;
  undefined4 ***local_c;
  undefined4 *local_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x88);
  ppppuVar2 = *(undefined4 *****)(*(int *)(_active_threads + 0xc) + 0xc);
  pppuStack_30 = &local_c;
  pppuStack_34 = (undefined4 ***)&local_8;
  pppuStack_38 = param_4;
  pppuStack_40 = (undefined4 ****)0x154493;
  ppuStack_3c = pppuVar1;
  iVar4 = _ipc_mqueue_copyin();
  iVar3 = _active_threads;
  pppuVar6 = (undefined4 ***)&stack0xffffffd4;
  if (iVar4 == 0) {
    *(undefined4 ****)(_active_threads + 0xc4) = param_1;
    *(uint *)(iVar3 + 200) = param_2;
    *(undefined4 ****)(iVar3 + 0xcc) = param_3;
    *(undefined4 *****)(iVar3 + 0xd0) = param_5;
    *(undefined4 ****)(iVar3 + 0xd8) = local_c;
    *(undefined4 **)(iVar3 + 0xdc) = local_8;
    pppuStack_30 = (undefined4 ***)local_14;
    pppuStack_34 = &local_10;
    pppuStack_38 = (undefined4 ***)_msg_receive_continue;
    ppuStack_3c = (undefined4 ***)0x0;
    pppuStack_40 = param_5;
    ppuStack_44 = (undefined4 ***)0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      ppuStack_44 = param_3;
    }
    iVar4 = _ipc_mqueue_receive(local_8,param_2 & 0x100);
    pppuStack_30 = local_c;
    pppuStack_34 = (undefined4 ***)0x154517;
    _ipc_object_release();
    pppuVar6 = (undefined4 ***)&stack0xffffffd4;
    if (iVar4 == 0) {
      if (param_3 < local_10[6]) {
        pppuStack_30 = local_10;
        pppuStack_34 = (undefined4 ***)0x154552;
        _ipc_kmsg_destroy();
        return 0xffffff34;
      }
      pppuStack_38 = local_10;
      ppuStack_3c = (undefined4 **)0x15456a;
      pppuStack_34 = pppuVar1;
      pppuStack_30 = ppppuVar2;
      _ipc_kmsg_copyout_compat();
      ppuStack_3c = (undefined4 **)((int)local_10[6] + (int)local_10[4]);
      local_10[6] = ppuStack_3c;
      pppuStack_40 = local_10;
      pppuVar6 = &ppuStack_44;
      ppuStack_44 = param_1;
      iVar4 = _ipc_kmsg_put();
    }
    else if (iVar4 == 0x10004004) {
      local_18 = local_10;
      pppuStack_30 = (undefined4 ****)0x4;
      pppuStack_34 = param_1 + 1;
      pppuStack_38 = &local_18;
      ppuStack_3c = (undefined4 ***)0x15453e;
      _copyout();
      pppuVar6 = (undefined4 ***)&stack0xffffffd4;
    }
  }
  *(int *)((int)pppuVar6 + -4) = iVar4;
  *(undefined4 *)((int)pppuVar6 + -8) = 0x154589;
  uVar5 = _msg_return_translate();
  return uVar5;
}

