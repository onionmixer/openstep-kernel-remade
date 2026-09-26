/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1795a0. */
__int32 __cdecl vm_object_shadow(int *a1, _DWORD *a2, int a3)
{
  int v3; // edi
  _DWORD *v4; // esi
  __int32 result; // eax

  v3 = *a1; /*0x1795ac*/
  v4 = (_DWORD *)zalloc(vm_object_zone); /*0x1795ba*/
  result = _vm_object_allocate(a3, v4); /*0x1795be*/
  if ( !v4 ) /*0x1795c8*/
    panic(aVmObjectShadow); /*0x1795cf*/
  v4[8] = v3; /*0x1795d4*/
  v4[9] = *a2; /*0x1795dc*/
  *a2 = 0; /*0x1795e2*/
  *a1 = (int)v4; /*0x1795eb*/
  return result; /*0x1795f0*/
}
