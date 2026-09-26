/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178ba8. */
__int32 __cdecl _vm_object_allocate(int a1, _DWORD *a2)
{
  int v2; // eax

  qmemcpy(a2, &vm_object_template, 0x58u); /*0x178bc3*/
  a2[1] = a2; /*0x178bc5*/
  *a2 = a2; /*0x178bc8*/
  a2[4] = 0; /*0x178bca*/
  a2[5] = a1; /*0x178bd1*/
  do /*0x178bed*/
  {
    while ( vm_object_list_lock ) /*0x178bdb*/
      ; /*0x178bd9*/
  }
  while ( _InterlockedExchange(&vm_object_list_lock, 1) == 1 ); /*0x178bed*/
  v2 = dword_1F7354; /*0x178bef*/
  if ( (int *)dword_1F7354 == &vm_object_list ) /*0x178bf9*/
    vm_object_list = (int)a2; /*0x178bfb*/
  else
    *(_DWORD *)(dword_1F7354 + 8) = a2; /*0x178c04*/
  a2[3] = v2; /*0x178c07*/
  a2[2] = &vm_object_list; /*0x178c0a*/
  dword_1F7354 = (int)a2; /*0x178c11*/
  ++vm_object_count; /*0x178c17*/
  return _InterlockedExchange(&vm_object_list_lock, 0); /*0x178c28*/
}
