/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b63b8 */

void FUN_001b63b8(undefined4 param_1)

{
  undefined4 uVar1;
  char local_6;
  char local_5;
  
  local_5 = '\0';
  local_6 = '\0';
  if ((DAT_001e5380 == '\0') || (DAT_001e538c == 0)) {
    _objc_msgSend(param_1,PTR_s_interruptOccurredForInput_forOut_001f98ec,&local_5,&local_6);
  }
  if ((DAT_001e5380 == '\0') && ((local_5 != '\0' || (local_6 != '\0')))) {
    _objc_msgSend(param_1,PTR_s__setLastInterruptTimeStamp__001f98e8,DAT_001e8710,DAT_001e8714);
    if (local_5 != '\0') {
      uVar1 = _objc_msgSend(param_1,PTR_s__inputChannel_001f9908);
      _objc_msgSend(param_1,PTR_s__attemptToStopDMAForChannel__001f98e4,uVar1);
    }
    if (local_6 != '\0') {
      uVar1 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900);
      _objc_msgSend(param_1,PTR_s__attemptToStopDMAForChannel__001f98e4,uVar1);
    }
  }
  return;
}

