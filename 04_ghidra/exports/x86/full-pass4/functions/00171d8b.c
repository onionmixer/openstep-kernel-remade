/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171d8b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00171d8b(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  _thread_wakeup_prim(&_ux_exception_port,0);
  LOCK();
  DAT_001e7280 = 0;
  UNLOCK();
  _task_name();
  do {
    while( true ) {
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -4);
      *(undefined4 *)(unaff_EBP + -0x84) = 0x58;
      iVar1 = _msg_receive(unaff_EBP + -0x88,0);
      if (iVar1 != 0) break;
      iVar1 = *(int *)(unaff_EBP + -0x78);
      iVar2 = _exc_server(unaff_EBP + -0x88);
      if (iVar2 != 0) {
        _msg_send(unaff_EBP + -0x30,0);
      }
      if (iVar1 != 0) {
        _port_deallocate_EXTERNAL(DAT_001e7284);
      }
    }
  } while (iVar1 == -0xcc);
                    /* WARNING: Subroutine does not return */
  _panic(s_exception_handler_001e08d0);
}

