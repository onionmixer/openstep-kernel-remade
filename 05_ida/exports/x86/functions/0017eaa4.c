/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17eaa4. */
unsigned int __cdecl -[KernBusItemResource findFreeItem](KernBusItemResource *self, SEL a2)
{
  unsigned int v2; // eax
  unsigned int count; // edx

  v2 = 0; /*0x17eaae*/
  count = self->_count; /*0x17eab0*/
  if ( count ) /*0x17eab5*/
  {
    do /*0x17eac1*/
    {
      if ( !*((_DWORD *)self->_items + v2) ) /*0x17eab8*/
        break; /*0x17eabc*/
      ++v2; /*0x17eabe*/
    }
    while ( v2 < count ); /*0x17eac1*/
  }
  return self->_base + v2; /*0x17eac6*/
}
