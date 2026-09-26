/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001525a8 */

mach_msg_return_t _mach_msg_send(mach_msg_header_t *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte in_stack_00000008;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  int local_8;
  
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar3 = _ipc_kmsg_get(param_1);
  if (iVar3 != 0) {
    return iVar3;
  }
  if ((char)in_stack_00000008 < '\0') {
    iVar3 = in_stack_00000014;
    if (in_stack_00000014 == 0) {
      iVar3 = 0x1000000b;
      goto LAB_00152629;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar3 = _ipc_kmsg_copyin(local_8,uVar1,uVar2,iVar3);
  if (iVar3 != 0) {
LAB_00152629:
    if (*(int *)(local_8 + 8) < 1) {
      _ipc_kmsg_free(local_8);
    }
    else {
      _kfree(local_8,*(int *)(local_8 + 8));
    }
    return iVar3;
  }
  if ((in_stack_00000008 & 0x20) == 0) {
    uVar5 = _ipc_mqueue_send(local_8,in_stack_00000008 & 0x10,in_stack_00000010,0);
  }
  else {
    uVar4 = 0;
    if ((in_stack_00000008 & 0x10) != 0) {
      uVar4 = in_stack_00000010;
    }
    uVar5 = _ipc_mqueue_send(local_8,0x10,uVar4,0);
    if (uVar5 == 0x10000004) {
      if (in_stack_00000014 == 0) {
        uVar5 = 0x1000000b;
      }
      else {
        uVar5 = _ipc_marequest_create
                          (uVar1,*(undefined4 *)(local_8 + 0x1c),in_stack_00000014,local_8 + 0xc);
        if (uVar5 == 0) {
          _ipc_mqueue_send(local_8,0x10000,0,0);
          return 0x10000005;
        }
      }
      goto LAB_001526d6;
    }
  }
  if (uVar5 == 0) {
    return 0;
  }
LAB_001526d6:
  uVar6 = _ipc_kmsg_copyout_pseudo(local_8,uVar1,uVar2);
  _ipc_kmsg_put(param_1,local_8,*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
  return uVar5 | uVar6;
}

