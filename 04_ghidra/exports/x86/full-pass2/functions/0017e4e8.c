/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e4e8 */

void FUN_0017e4e8(void)

{
  FUN_0017e538();
  _probeNativeDevices();
  _probeHardware();
  _probeDirectDevices();
  FUN_0017e58c();
  _objc_msgSend(DAT_001e7314,PTR_s_lock_001f9220);
  _objc_msgSend(DAT_001e7314,PTR_s_unlockWith__001f9224,1);
  _IOExitThread();
  return;
}

