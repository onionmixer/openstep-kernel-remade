/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccb90. */
_DWORD *__cdecl _internal_class_createInstanceFromZone(_DWORD *a1, int a2, int a3)
{
  size_t v3; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // ebx

  if ( !a1 ) /*0x1ccb9e*/
    __objc_error(nullptr, "allocating nil object", 0); /*0x1ccba9*/
  v3 = a1[5] + a2; /*0x1ccbb4*/
  v4 = (_DWORD *)(*(int (__cdecl **)(int, size_t))(a3 + 4))(a3, v3); /*0x1ccbbc*/
  v5 = v4; /*0x1ccbbe*/
  if ( !v4 ) /*0x1ccbc5*/
    __objc_error(a1, "failed -- out of memory(%s, %u)", a1[2]); /*0x1ccbd5*/
  bzero(v4, v3); /*0x1ccbe2*/
  *v5 = a1; /*0x1ccbe7*/
  return v5; /*0x1ccbee*/
}
