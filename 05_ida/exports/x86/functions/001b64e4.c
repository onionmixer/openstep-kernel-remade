/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b64e4. */
void __cdecl -[IOAudio _setOutputStartTime:](IOAudio *self, SEL a2, unsigned __int64 a3)
{
  *(_QWORD *)self->_audioPrivate = a3; /*0x1b64f6*/
}
