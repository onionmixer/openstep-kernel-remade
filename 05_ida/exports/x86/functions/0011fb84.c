/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fb84. */
uintptr_t __cdecl SRHash(void *info, int a2)
{
  uintptr_t v2; // edi

  v2 = NXPtrHash(info, *(const void **)a2); /*0x11fb99*/
  return v2 ^ NXPtrHash(info, (const void *)*(unsigned __int16 *)(a2 + 4)); /*0x11fbab*/
}
