/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b64a8. */
void __cdecl -[IOAudio _setLastInterruptTimeStamp:](IOAudio *self, SEL a2, unsigned __int64 a3)
{
  _DWORD *audioPrivate; // edx
  int v4; // eax

  audioPrivate = self->_audioPrivate; /*0x1b64ae*/
  v4 = dword_1E8714; /*0x1b64ba*/
  audioPrivate[2] = dword_1E8710; /*0x1b64bf*/
  audioPrivate[3] = v4; /*0x1b64c2*/
}
