/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001947c4 */

void _configureThread(undefined4 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_00194140(param_1[1]);
  *(undefined1 *)(param_1 + 2) = uVar1;
  _objc_msgSend(*param_1,PTR_s_lock_001f9220);
  _objc_msgSend(*param_1,PTR_s_unlockWith__001f9224,1);
  _IOExitThread();
  return;
}

