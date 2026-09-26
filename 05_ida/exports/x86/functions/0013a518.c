/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a518. */
int __cdecl spec_realvp(int a1, _DWORD *a2)
{
  int v2; // ebx
  void *v3; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  v2 = a1; /*0x13a520*/
  if ( a1 ) /*0x13a528*/
  {
    v3 = *(void **)(a1 + 28); /*0x13a52a*/
    if ( v3 == &spec_vnodeops || v3 == &fifo_vnodeops ) /*0x13a539*/
      v2 = *(_DWORD *)(*(_DWORD *)(a1 + 48) + 56); /*0x13a53e*/
    if ( v2 && !(*(int (__stdcall **)(int, int *))(*(_DWORD *)(v2 + 28) + 112))(v2, &v5) ) /*0x13a550*/
      v2 = v5; /*0x13a556*/
  }
  *a2 = v2; /*0x13a559*/
  return 0; /*0x13a560*/
}
