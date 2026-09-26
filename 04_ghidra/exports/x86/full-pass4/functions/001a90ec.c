/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a90ec */

undefined4 _IOForkThread(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  _objc_msgSend(DAT_001e86f8,PTR_s_lock_001f9220);
  DAT_001e86ec = param_1;
  DAT_001e86f0 = param_2;
  uVar1 = _kernel_thread(_IOTask_kern,FUN_001a9140);
  _thread_priority(uVar1,0x12,0);
  return uVar1;
}

