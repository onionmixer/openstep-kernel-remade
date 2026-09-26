/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00152708 */

mach_msg_return_t _mach_msg_receive(mach_msg_header_t *param_1)

{
  code *pcVar1;
  mach_msg_size_t *pmVar2;
  int iVar3;
  int iVar4;
  mach_msg_return_t mVar5;
  code **ppcVar6;
  uint uVar7;
  uint in_stack_00000008;
  uint in_stack_0000000c;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  code *pcStack_38;
  mach_msg_header_t *pmStack_34;
  mach_msg_size_t *pmStack_30;
  code *pcStack_2c;
  code *local_18;
  mach_msg_size_t local_14;
  code *local_10;
  undefined4 local_c;
  mach_msg_size_t local_8;
  
  iVar4 = _active_threads;
  pcVar1 = *(code **)(*(int *)(_active_threads + 0xc) + 0x88);
  pmVar2 = *(mach_msg_size_t **)(*(int *)(_active_threads + 0xc) + 0xc);
  pcStack_2c = (code *)&local_c;
  pmStack_30 = &local_8;
  pcStack_38 = pcVar1;
  iVar3 = _ipc_mqueue_copyin();
  if (iVar3 != 0) {
    return iVar3;
  }
  *(mach_msg_header_t **)(iVar4 + 0xc4) = param_1;
  *(uint *)(iVar4 + 200) = in_stack_00000008;
  *(uint *)(iVar4 + 0xcc) = in_stack_0000000c;
  *(undefined4 *)(iVar4 + 0xd0) = in_stack_00000014;
  *(int *)(iVar4 + 0xd4) = in_stack_00000018;
  *(undefined4 *)(iVar4 + 0xd8) = local_c;
  *(mach_msg_size_t *)(iVar4 + 0xdc) = local_8;
  if ((in_stack_00000008 & 0x800) == 0) {
    pcStack_2c = (code *)&local_14;
    pmStack_30 = (mach_msg_size_t *)&local_10;
    pmStack_34 = (mach_msg_header_t *)_mach_msg_receive_continue;
    pcStack_38 = (code *)0x0;
    iVar4 = _ipc_mqueue_receive(local_8,in_stack_00000008 & 0x100,0xffffffff,in_stack_00000014);
    pcStack_2c = (code *)local_c;
    pmStack_30 = (mach_msg_size_t *)0x15282d;
    _ipc_object_release();
    if (iVar4 != 0) {
      return iVar4;
    }
    *(mach_msg_size_t *)(local_10 + 0x24) = local_14;
    if (in_stack_0000000c < *(uint *)(local_10 + 0x18)) {
      pmStack_30 = (mach_msg_size_t *)local_10;
      pmStack_34 = (mach_msg_header_t *)0x152854;
      pcStack_2c = pcVar1;
      _ipc_kmsg_copyout_dest();
      pmStack_34 = (mach_msg_header_t *)0x18;
      pcStack_38 = local_10;
      _ipc_kmsg_put(param_1);
      return 0x10004004;
    }
  }
  else {
    pcStack_2c = (code *)&local_14;
    pmStack_30 = (mach_msg_size_t *)&local_10;
    pmStack_34 = (mach_msg_header_t *)_mach_msg_receive_continue;
    pcStack_38 = (code *)0x0;
    iVar4 = _ipc_mqueue_receive(local_8,in_stack_00000008 & 0x100,in_stack_0000000c,
                                in_stack_00000014);
    pcStack_2c = (code *)local_c;
    pmStack_30 = (mach_msg_size_t *)0x1527c3;
    _ipc_object_release();
    if (iVar4 != 0) {
      if (iVar4 != 0x10004004) {
        return iVar4;
      }
      local_18 = local_10;
      pcStack_2c = (code *)0x4;
      pmStack_30 = &param_1->msgh_size;
      pmStack_34 = (mach_msg_header_t *)&local_18;
      pcStack_38 = (code *)0x1527ea;
      _copyout();
      return 0x10004004;
    }
    *(mach_msg_size_t *)(local_10 + 0x24) = local_14;
  }
  if ((in_stack_00000008 & 0x200) == 0) {
    pcStack_2c = (code *)0x0;
  }
  else {
    if (in_stack_00000018 == 0) {
      uVar7 = 0x10004007;
      goto LAB_001528a9;
    }
    pcStack_2c = (code *)in_stack_00000018;
  }
  pcStack_38 = local_10;
  pmStack_34 = (mach_msg_header_t *)pcVar1;
  pmStack_30 = pmVar2;
  uVar7 = _ipc_kmsg_copyout();
  if (uVar7 == 0) {
    pcStack_2c = (code *)(*(int *)(local_10 + 0x18) + *(int *)(local_10 + 0x10));
    pmStack_30 = (mach_msg_size_t *)local_10;
    pmStack_34 = param_1;
    pcStack_38 = (code *)0x1528f8;
    mVar5 = _ipc_kmsg_put();
    return mVar5;
  }
LAB_001528a9:
  if ((uVar7 & 0xffffc3ff) == 0x1000400c) {
    pcStack_2c = (code *)(*(int *)(local_10 + 0x18) + *(int *)(local_10 + 0x10));
    ppcVar6 = (code **)&pmStack_30;
    pmStack_30 = (mach_msg_size_t *)local_10;
  }
  else {
    pmStack_30 = (mach_msg_size_t *)local_10;
    pmStack_34 = (mach_msg_header_t *)0x1528ce;
    pcStack_2c = pcVar1;
    _ipc_kmsg_copyout_dest();
    pmStack_34 = (mach_msg_header_t *)0x18;
    ppcVar6 = &pcStack_38;
    pcStack_38 = local_10;
  }
  *(mach_msg_header_t **)((int)ppcVar6 + -4) = param_1;
  *(undefined4 *)((int)ppcVar6 + -8) = 0x1528dd;
  _ipc_kmsg_put();
  return uVar7;
}

