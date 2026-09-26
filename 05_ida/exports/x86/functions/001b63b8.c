/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b63b8. */
void __cdecl -[IOAudio _interruptOccurred](IOAudio *self, SEL a2)
{
  id v2; // eax
  id v3; // eax
  char v4; // [esp+6h] [ebp-2h] BYREF
  char v5; // [esp+7h] [ebp-1h] BYREF

  v5 = 0; /*0x1b63c2*/
  v4 = 0; /*0x1b63c6*/
  if ( !byte_1E5380 || !dword_1E538C ) /*0x1b63da*/
    -[IOAudio interruptOccurredForInput:forOutput:](self, sel_interruptOccurredForInput_forOutput_, &v5, &v4); /*0x1b63ec*/
  if ( !byte_1E5380 && (v5 || v4) ) /*0x1b6407*/
  {
    -[IOAudio _setLastInterruptTimeStamp:](self, sel__setLastInterruptTimeStamp_, dword_1E8710, dword_1E8714); /*0x1b641f*/
    if ( v5 ) /*0x1b642b*/
    {
      v2 = -[IOAudio _inputChannel](self, sel__inputChannel); /*0x1b6435*/
      -[IOAudio _attemptToStopDMAForChannel:](self, sel__attemptToStopDMAForChannel_, v2); /*0x1b6443*/
    }
    if ( v4 ) /*0x1b644f*/
    {
      v3 = -[IOAudio _outputChannel](self, sel__outputChannel); /*0x1b6459*/
      -[IOAudio _attemptToStopDMAForChannel:](self, sel__attemptToStopDMAForChannel_, v3); /*0x1b6467*/
    }
  }
}
