/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x131898. */
int __cdecl sub_131898(void *a1)
{
  unsigned int i; // ebx
  int result; // eax
  _DWORD v3[8]; // [esp+4h] [ebp-20h] BYREF

  bcopy(a1, v3, 0x20u); /*0x1318a9*/
  for ( i = 0; i <= 7; ++i ) /*0x1318ae*/
    result = printf("%x ", v3[i]); /*0x1318be*/
  return result; /*0x1318cc*/
}
