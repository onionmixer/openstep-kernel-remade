/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161ea0. */
_DWORD *__cdecl dequeue_head(_DWORD *a1)
{
  _DWORD *v1; // edx

  v1 = (_DWORD *)*a1; /*0x161ea7*/
  if ( (_DWORD *)*a1 == a1 ) /*0x161eab*/
    return nullptr; /*0x161ebc*/
  *(_DWORD *)(*v1 + 4) = a1; /*0x161eaf*/
  *a1 = *v1; /*0x161eb4*/
  return v1; /*0x161ebe*/
}
