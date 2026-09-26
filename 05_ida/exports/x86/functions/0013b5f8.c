/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b5f8. */
int __cdecl sub_13B5F8(int a1, int a2, int a3)
{
  int v3; // ebx
  vm_size_t v4; // eax
  int result; // eax

  v3 = *(_DWORD *)(a1 + 48); /*0x13b603*/
  v4 = page_size * *(_DWORD *)(v3 + 80); /*0x13b609*/
  if ( *(_DWORD *)(a2 + 24) < v4 ) /*0x13b613*/
    *(_DWORD *)(a2 + 24) = v4; /*0x13b615*/
  result = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)(*(_DWORD *)(v3 + 60) + 28) + 24))( /*0x13b627*/
             *(_DWORD *)(v3 + 60),
             a2,
             a3);
  if ( !result ) /*0x13b62b*/
  {
    *(_DWORD *)(**(_DWORD **)(v3 + 60) + 20) = *(_DWORD *)(a2 + 24); /*0x13b635*/
    return 0; /*0x13b638*/
  }
  return result; /*0x13b63d*/
}
