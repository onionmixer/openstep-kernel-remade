/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccc14. */
_DWORD *__cdecl _internal_class_createInstance(_DWORD *a1, int a2)
{
  int v2; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v2 = NXDefaultMallocZone(v4, v5); /*0x1ccc1f*/
  return _internal_class_createInstanceFromZone(a1, a2, v2); /*0x1ccc2f*/
}
