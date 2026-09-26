/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185900 */

void _vol_start_thread(void)

{
  int iVar1;
  undefined1 local_8 [4];
  
  iVar1 = _ipc_port_alloc(*(undefined4 *)(_kernel_task + 0x88),local_8,&DAT_001e13f4);
  if (iVar1 != 0) {
    _printf(s_vol_start_thread__port_alloc_ret_001e16ec,iVar1);
    return;
  }
  DAT_001e13f8 = DAT_001e13f4[4];
  LOCK();
  *DAT_001e13f4 = 0;
  UNLOCK();
  _kernel_thread(_kernel_task,FUN_001859dc,0);
  DAT_001e1408 = &PTR_LOOP_001e1404;
  PTR_LOOP_001e1404 = (undefined *)&PTR_LOOP_001e1404;
  DAT_001e140c = 1;
  if (DAT_001e7589 == '\0') {
    _lock_init(&DAT_001e758c,1);
    DAT_001e7589 = '\x01';
  }
  return;
}

