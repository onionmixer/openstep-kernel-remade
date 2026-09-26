/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbf34. */
uintptr_t __cdecl sub_1CBF34(void *info, int a2)
{
  uintptr_t v2; // esi
  uintptr_t v3; // edi

  v2 = NXPtrHash(info, *(const void **)a2); /*0x1cbf49*/
  v3 = NXPtrHash(info, *(const void **)(a2 + 4)); /*0x1cbf58*/
  return *(_DWORD *)(a2 + 12) ^ NXPtrHash(info, *(const void **)(a2 + 8)) ^ v3 ^ v2; /*0x1cbf78*/
}
