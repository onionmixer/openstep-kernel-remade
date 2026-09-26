/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6c4c. */
char __cdecl -[IOAudio _setParameters:toValues:count:forObject:](
        IOAudio *self,
        SEL a2,
        const int *a3,
        const unsigned int *a4,
        unsigned int a5,
        id a6)
{
  unsigned int i; // ebx
  char v8; // [esp+Ch] [ebp-4h]

  v8 = 1; /*0x1b6c5b*/
  for ( i = 0; i < a5; ++i ) /*0x1b6c63*/
  {
    if ( !-[IOAudio _setParameter:toInt:forObject:](self, sel__setParameter_toInt_forObject_, a3[i], a4[i], a6) ) /*0x1b6c82*/
      v8 = 0; /*0x1b6c8e*/
  }
  return v8; /*0x1b6c9e*/
}
