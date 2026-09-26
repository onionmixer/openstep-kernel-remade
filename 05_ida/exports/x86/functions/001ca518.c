/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca518. */
_DWORD *__cdecl _internal_object_reallocFromZone(
        int *a1,
        unsigned int a2,
        int (__cdecl **a3)(_DWORD, id, unsigned int))
{
  const char *ClassName; // eax
  int v4; // esi
  _DWORD *result; // eax
  const char *v6; // eax

  if ( !a1 ) /*0x1ca526*/
    __objc_error(nullptr, "reallocating nil object", 0); /*0x1ca531*/
  if ( *a1 == _objc_getFreedObjectClass() ) /*0x1ca540*/
    __objc_error(a1, "reallocating freed object", 0); /*0x1ca54a*/
  if ( *(_DWORD *)(*a1 + 20) > a2 ) /*0x1ca557*/
  {
    ClassName = object_getClassName(a1); /*0x1ca55b*/
    __objc_error(a1, "(%s, %u) requested size too small", ClassName); /*0x1ca56a*/
  }
  v4 = *a1; /*0x1ca572*/
  *a1 = _objc_getFreedObjectClass(); /*0x1ca579*/
  result = (_DWORD *)(*a3)(a3, a1, a2); /*0x1ca583*/
  if ( !result ) /*0x1ca58a*/
  {
    v6 = object_getClassName(a1); /*0x1ca58e*/
    __objc_error(a1, "failed -- out of memory(%s, %u)", v6); /*0x1ca59d*/
  }
  *result = v4; /*0x1ca5a8*/
  return result; /*0x1ca5ad*/
}
