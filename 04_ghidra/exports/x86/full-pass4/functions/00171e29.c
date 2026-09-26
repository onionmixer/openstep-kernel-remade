/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171e29 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00171e29(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  do {
    while( true ) {
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -4);
      *(undefined4 *)(unaff_EBP + -0x84) = 0x58;
      iVar1 = _msg_receive();
      if (iVar1 != 0) break;
      iVar1 = *(int *)(unaff_EBP + -0x78);
      iVar2 = _exc_server();
      if (iVar2 != 0) {
        _msg_send();
      }
      if (iVar1 != 0) {
        _port_deallocate_EXTERNAL(DAT_001e7284);
      }
    }
  } while (iVar1 == -0xcc);
                    /* WARNING: Subroutine does not return */
  _panic(s_exception_handler_001e08d0);
}

