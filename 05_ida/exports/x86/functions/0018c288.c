/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c288. */
__int16 intr_initialize()
{
  __int16 *v0; // ecx
  int v1; // esi
  int v2; // eax

  _disable(); /*0x18c28d*/
  __outbyte(0x20u, 0x11u); /*0x18c299*/
  _InterlockedIncrement(dword_1E7618); /*0x18c29a*/
  __outbyte(0x21u, 0x40u); /*0x18c2a8*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2a9*/
  __outbyte(0x21u, 4u); /*0x18c2b2*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2b3*/
  __outbyte(0x21u, 1u); /*0x18c2bc*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2bd*/
  __outbyte(0x20u, 0x4Bu); /*0x18c2cb*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2cc*/
  __outbyte(0xA0u, 0x11u); /*0x18c2da*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2db*/
  __outbyte(0xA1u, 0x48u); /*0x18c2e9*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2ea*/
  __outbyte(0xA1u, 2u); /*0x18c2f3*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2f4*/
  __outbyte(0xA1u, 1u); /*0x18c2fd*/
  _InterlockedIncrement(dword_1E7618); /*0x18c2fe*/
  __outbyte(0xA0u, 0x4Bu); /*0x18c30c*/
  _InterlockedIncrement(dword_1E7618); /*0x18c30d*/
  v0 = word_1E76E4; /*0x18c319*/
  v1 = 1; /*0x18c31e*/
  do /*0x18c330*/
  {
    *v0++ = -5; /*0x18c324*/
    v2 = v1++; /*0x18c32a*/
  }
  while ( v2 <= 7 ); /*0x18c330*/
  word_1E771E = 0; /*0x18c332*/
  if ( dword_1E7718 != 7 ) /*0x18c342*/
  {
    if ( word_1E771C != word_1E76F2 ) /*0x18c352*/
    {
      word_1E771C = word_1E76F2; /*0x18c354*/
      __outbyte(0x21u, word_1E76F2); /*0x18c362*/
      _InterlockedIncrement(dword_1E7618); /*0x18c363*/
      LOWORD(v2) = HIBYTE(word_1E76F2); /*0x18c36c*/
      __outbyte(0xA1u, HIBYTE(word_1E76F2)); /*0x18c375*/
      _InterlockedIncrement(dword_1E7618); /*0x18c376*/
    }
    dword_1E7718 = 7; /*0x18c37d*/
  }
  dword_1E7714 = 7; /*0x18c387*/
  _enable(); /*0x18c391*/
  return v2; /*0x18c395*/
}
