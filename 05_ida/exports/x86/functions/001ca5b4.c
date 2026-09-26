/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca5b4. */
_DWORD *__cdecl _internal_object_realloc(int *a1, unsigned int a2)
{
  int (__cdecl **v2)(_DWORD, id, unsigned int); // eax
  int v4; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v2 = (int (__cdecl **)(_DWORD, id, unsigned int))NXZoneFromPtr(a1); /*0x1ca5bc*/
  if ( !v2 ) /*0x1ca5c6*/
    v2 = (int (__cdecl **)(_DWORD, id, unsigned int))NXDefaultMallocZone(v4, savedregs); /*0x1ca5c8*/
  return _internal_object_reallocFromZone(a1, a2, v2); /*0x1ca5d8*/
}
