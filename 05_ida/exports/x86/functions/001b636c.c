/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b636c. */
void __cdecl -[IOAudio _dataPendingOccurred:](IOAudio *self, SEL a2, id a3)
{
  if ( !-[IOAudio isInputActive](self, sel_isInputActive) && !-[IOAudio isOutputActive](self, sel_isOutputActive) ) /*0x1b638f*/
    -[IOAudio _attemptToStartDMAForChannel:channelStatus:](self, sel__attemptToStartDMAForChannel_channelStatus_, a3, 0); /*0x1b63a9*/
}
