/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151c70. */
int __cdecl ipc_thread_rmqueue(_DWORD *a1, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // ebx

  result = a2; /*0x151c77*/
  v3 = *(_DWORD *)(a2 + 144); /*0x151c7a*/
  v4 = *(_DWORD *)(a2 + 148); /*0x151c80*/
  if ( v3 == a2 ) /*0x151c88*/
  {
    *a1 = 0; /*0x151c8a*/
  }
  else
  {
    if ( *a1 == a2 ) /*0x151c96*/
      *a1 = v3; /*0x151c98*/
    *(_DWORD *)(v3 + 148) = v4; /*0x151c9a*/
    *(_DWORD *)(v4 + 144) = v3; /*0x151ca0*/
    *(_DWORD *)(a2 + 144) = a2; /*0x151ca6*/
    *(_DWORD *)(a2 + 148) = a2; /*0x151cac*/
  }
  return result; /*0x151cb2*/
}
