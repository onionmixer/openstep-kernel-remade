/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158534 */

mach_msg_return_t
_mach_msg(mach_msg_header_t *msg,mach_msg_option_t option,mach_msg_size_t send_size,
         mach_msg_size_t rcv_size,mach_port_name_t rcv_name,mach_msg_timeout_t timeout,
         mach_port_name_t notify)

{
  mach_msg_header_t *pmVar1;
  mach_msg_header_t *pmVar2;
  int iVar3;
  uint uVar4;
  mach_msg_header_t **ppmVar5;
  mach_msg_header_t *pmStack_34;
  mach_msg_header_t *pmStack_30;
  mach_msg_header_t *pmStack_2c;
  mach_port_t local_14;
  undefined4 local_c;
  mach_msg_header_t *local_8;
  
  pmVar1 = *(mach_msg_header_t **)(*(int *)(_active_threads + 0xc) + 0x88);
  pmVar2 = *(mach_msg_header_t **)(*(int *)(_active_threads + 0xc) + 0xc);
  if ((option & 1U) != 0) {
    pmStack_2c = (mach_msg_header_t *)0x0;
    pmStack_30 = (mach_msg_header_t *)send_size;
    pmStack_34 = msg;
    iVar3 = _ipc_kmsg_get_from_kernel();
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      pmStack_2c = (mach_msg_header_t *)__analysis_fragment_0015857f;
      _panic(s_mach_msg_001dec61);
    }
    pmStack_34 = local_8;
    pmStack_30 = pmVar1;
    pmStack_2c = pmVar2;
    iVar3 = _ipc_kmsg_copyin();
    if (iVar3 != 0) {
      if ((int)local_8->msgh_remote_port < 1) {
        pmStack_2c = (mach_msg_header_t *)0x1585ab;
        _ipc_kmsg_free();
        return iVar3;
      }
      pmStack_2c = local_8;
      pmStack_30 = (mach_msg_header_t *)0x1585b7;
      _kfree();
      return iVar3;
    }
    do {
      pmStack_2c = (mach_msg_header_t *)0x0;
      pmStack_30 = (mach_msg_header_t *)0x0;
      pmStack_34 = local_8;
      iVar3 = _ipc_mqueue_send();
    } while (iVar3 == 0x10000007);
  }
  if ((option & 2U) != 0) {
    do {
      pmStack_2c = (mach_msg_header_t *)&local_c;
      pmStack_30 = (mach_msg_header_t *)rcv_name;
      pmStack_34 = pmVar1;
      iVar3 = _ipc_mqueue_copyin();
      if (iVar3 != 0) {
        return iVar3;
      }
      pmStack_2c = (mach_msg_header_t *)&local_8;
      pmStack_30 = (mach_msg_header_t *)0x0;
      pmStack_34 = (mach_msg_header_t *)0x0;
      iVar3 = _ipc_mqueue_receive(local_c,0,0xffffffff,0);
      pmStack_2c = (mach_msg_header_t *)0x158628;
      _ipc_object_release();
    } while (iVar3 == 0x10004005);
    if (iVar3 != 0) {
      return iVar3;
    }
    local_8[1].msgh_local_port = local_14;
    if (rcv_size < local_8[1].msgh_bits) {
      pmStack_2c = local_8;
      pmStack_30 = (mach_msg_header_t *)0x158658;
      _ipc_kmsg_copyout_dest();
      pmStack_30 = (mach_msg_header_t *)0x18;
      pmStack_34 = local_8;
      _ipc_kmsg_put_to_kernel(msg);
      return 0x10004004;
    }
    pmStack_34 = local_8;
    pmStack_30 = pmVar1;
    pmStack_2c = pmVar2;
    uVar4 = _ipc_kmsg_copyout();
    if (uVar4 != 0) {
      if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
        ppmVar5 = &pmStack_2c;
        pmStack_2c = local_8;
      }
      else {
        pmStack_2c = local_8;
        pmStack_30 = (mach_msg_header_t *)0x1586a6;
        _ipc_kmsg_copyout_dest();
        pmStack_30 = (mach_msg_header_t *)0x18;
        ppmVar5 = &pmStack_34;
        pmStack_34 = local_8;
      }
      *(mach_msg_header_t **)((int)ppmVar5 + -4) = msg;
      *(undefined4 *)((int)ppmVar5 + -8) = 0x1586b2;
      _ipc_kmsg_put_to_kernel();
      return uVar4;
    }
    pmStack_2c = local_8;
    pmStack_30 = msg;
    pmStack_34 = (mach_msg_header_t *)0x1586c5;
    _ipc_kmsg_put_to_kernel();
  }
  return 0;
}

