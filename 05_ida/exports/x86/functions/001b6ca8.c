/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6ca8. */
void __cdecl -[IOAudio _getParameters:values:count:forObject:](
        IOAudio *self,
        SEL a2,
        const int *a3,
        unsigned int *a4,
        unsigned int a5,
        id a6)
{
  unsigned int i; // ebx

  for ( i = 0; i < a5; ++i ) /*0x1b6cb8*/
    a4[i] = -[IOAudio _intValueForParameter:forObject:](self, sel__intValueForParameter_forObject_, a3[i], a6); /*0x1b6cd7*/
}
