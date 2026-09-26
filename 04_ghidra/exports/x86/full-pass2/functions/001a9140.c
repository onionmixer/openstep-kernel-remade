/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9140 */

void FUN_001a9140(void)

{
  code *pcVar1;
  undefined4 uVar2;
  thread_act_t thread;
  boolean_t wired;
  
  uVar2 = DAT_001e86f0;
  pcVar1 = DAT_001e86ec;
  _objc_msgSend(DAT_001e86f8,PTR_s_unlock_001f9474);
  wired = 1;
  thread = _current_thread_EXTERNAL();
  _thread_wire(1,thread,wired);
  (*pcVar1)(uVar2);
  _IOExitThread();
  return;
}

