/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ca74. */
int __cdecl load_machfile(int a1, int a2, int a3, int a4, char *__b)
{
  char *v5; // esi
  _DWORD *v6; // edi
  int v7; // ebx
  int v8; // ebx
  int v10; // [esp+Ch] [ebp-18h]
  char v11; // [esp+10h] [ebp-14h] BYREF

  v5 = __b; /*0x15ca7d*/
  v6 = *(_DWORD **)(*(_DWORD *)(active_threads + 12) + 12); /*0x15ca88*/
  v7 = v6[9]; /*0x15ca8b*/
  pmap_reference(v7); /*0x15ca8f*/
  v10 = vm_map_create(v7, v6[5], v6[6], v6[8]); /*0x15caa6*/
  if ( !__b ) /*0x15caae*/
    v5 = &v11; /*0x15cab0*/
  memset(v5, 0, 0x14u); /*0x15cab8*/
  *(_DWORD *)v5 = 0; /*0x15cac0*/
  v8 = sub_15CB1C(a1, v10, a2, a3, a4, 0, 0, v5); /*0x15cae4*/
  if ( v8 ) /*0x15caeb*/
  {
    vm_map_deallocate(v10); /*0x15caf1*/
    return v8; /*0x15caf6*/
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12) = v10; /*0x15cb07*/
    vm_map_deallocate(v6); /*0x15cb0b*/
    return 0; /*0x15cb10*/
  }
}
