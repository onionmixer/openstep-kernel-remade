/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015857f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

uint __analysis_fragment_0015857f(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBP;
  undefined4 unaff_EDI;
  int iStack_4;
  
  iStack_4 = *(int *)(unaff_EBP + -0x14);
  uVar1 = _ipc_kmsg_copyin();
  if (uVar1 != 0) {
    iStack_4 = *(int *)(unaff_EBP + -4);
    if (*(int *)(iStack_4 + 8) < 1) {
      iStack_4 = 0x1585ab;
      _ipc_kmsg_free();
      return uVar1;
    }
    _kfree();
    return uVar1;
  }
  do {
    iStack_4 = 0;
    iVar2 = _ipc_mqueue_send();
  } while (iVar2 == 0x10000007);
  if ((*(uint *)(unaff_EBP + 0xc) & 2) != 0) {
    do {
      iStack_4 = unaff_EBP + -8;
      uVar1 = _ipc_mqueue_copyin();
      if (uVar1 != 0) {
        return uVar1;
      }
      iStack_4 = unaff_EBP + -4;
      uVar1 = _ipc_mqueue_receive(*(undefined4 *)(unaff_EBP + -8),0,0xffffffff,0);
      iStack_4 = 0x158628;
      _ipc_object_release();
    } while (uVar1 == 0x10004005);
    if (uVar1 != 0) {
      return uVar1;
    }
    iStack_4 = *(int *)(unaff_EBP + -4);
    *(undefined4 *)(iStack_4 + 0x24) = *(undefined4 *)(unaff_EBP + -0x10);
    if (*(uint *)(unaff_EBP + 0x14) < *(uint *)(iStack_4 + 0x18)) {
      _ipc_kmsg_copyout_dest();
      _ipc_kmsg_put_to_kernel();
      return 0x10004004;
    }
    iStack_4 = *(int *)(unaff_EBP + -0x14);
    uVar1 = _ipc_kmsg_copyout();
    if (uVar1 != 0) {
      if ((uVar1 & 0xffffc3ff) == 0x1000400c) {
        iStack_4 = *(int *)(unaff_EBP + -4);
        piVar3 = &iStack_4;
      }
      else {
        iStack_4 = *(int *)(unaff_EBP + -4);
        _ipc_kmsg_copyout_dest();
        piVar3 = (int *)&stack0xfffffff4;
      }
      *(undefined4 *)((int)piVar3 + -4) = unaff_EDI;
      *(undefined4 *)((int)piVar3 + -8) = 0x1586b2;
      _ipc_kmsg_put_to_kernel();
      return uVar1;
    }
    iStack_4 = *(int *)(unaff_EBP + -4);
    _ipc_kmsg_put_to_kernel();
  }
  return 0;
}

