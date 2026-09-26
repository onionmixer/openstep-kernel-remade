/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b64cc. */
unsigned __int64 __cdecl -[IOAudio _lastInterruptTimeStamp](IOAudio *self, SEL a2)
{
  return *((_QWORD *)self->_audioPrivate + 1); /*0x1b64e0*/
}
