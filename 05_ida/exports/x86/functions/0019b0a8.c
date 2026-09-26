/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b0a8. */
char __cdecl sub_19B0A8(int *a1, _WORD *a2)
{
  unsigned int v2; // ecx
  unsigned int v3; // ecx

  __outbyte(0x3C4u, 2u); /*0x19b0ba*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b0bb*/
  __outbyte(0x3C5u, 2u); /*0x19b0c7*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b0c8*/
  v2 = HIWORD(*a1); /*0x19b157*/
  *a2 = (unsigned __int8)~(((*a1 & 0xAA) << 6) /*0x19b1df*/
                         | (8 * (*a1 & 8))
                         | *a1 & 0x20
                         | ((unsigned __int8)(*a1 & 0x80) >> 3)
                         | ((*a1 & 0x200u) >> 6)
                         | ((*a1 & 0x800u) >> 9)
                         | ((*a1 & 0x2000u) >> 12)
                         | ((*a1 & 0x8000u) >> 15))
      | ((unsigned __int8)~(((v2 & 0xAA) << 6)
                          | (8 * (v2 & 8))
                          | v2 & 0x20
                          | ((unsigned __int8)(v2 & 0x80) >> 3)
                          | ((unsigned __int16)(v2 & 0x200) >> 6)
                          | ((unsigned __int16)(v2 & 0x800) >> 9)
                          | ((unsigned __int16)(HIWORD(*a1) & 0x2000) >> 12)
                          | (*a1 < 0)) << 8);
  __outbyte(0x3C4u, 2u); /*0x19b1e9*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b1ea*/
  __outbyte(0x3C5u, 1u); /*0x19b1f8*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b1f9*/
  v3 = HIWORD(*a1); /*0x19b287*/
  *a2 = (unsigned __int8)~(((*a1 & 0x55) << 7) /*0x19b314*/
                         | (16 * (*a1 & 4))
                         | (2 * (*a1 & 0x10))
                         | ((unsigned __int8)(*a1 & 0x40) >> 2)
                         | ((*a1 & 0x100u) >> 5)
                         | ((unsigned __int16)(*a1 & 0x400) >> 8)
                         | ((*a1 & 0x1000u) >> 11)
                         | ((*a1 & 0x4000u) >> 14))
      | ((unsigned __int8)~(((v3 & 0x55) << 7)
                          | (16 * (v3 & 4))
                          | (2 * (v3 & 0x10))
                          | ((unsigned __int8)(v3 & 0x40) >> 2)
                          | ((unsigned __int16)(v3 & 0x100) >> 5)
                          | ((unsigned __int16)(v3 & 0x400) >> 8)
                          | ((unsigned __int16)(v3 & 0x1000) >> 11)
                          | ((unsigned __int16)(v3 & 0x4000) >> 14)) << 8);
  __outbyte(0x3C4u, 2u); /*0x19b31e*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b31f*/
  __outbyte(0x3C5u, 0xFu); /*0x19b32d*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b32e*/
  return 15; /*0x19b338*/
}
