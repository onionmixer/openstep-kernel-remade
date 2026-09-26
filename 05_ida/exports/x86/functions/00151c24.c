/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151c24. */
int __cdecl ipc_thread_dequeue(int *a1)
{
  int v1; // edx
  int v2; // ecx
  int v3; // eax

  v1 = *a1; /*0x151c2b*/
  if ( *a1 ) /*0x151c2b*/
  {
    v2 = *(_DWORD *)(v1 + 144); /*0x151c31*/
    if ( v2 == v1 ) /*0x151c39*/
    {
      *a1 = 0; /*0x151c3b*/
    }
    else
    {
      v3 = *(_DWORD *)(v1 + 148); /*0x151c44*/
      *a1 = v2; /*0x151c4a*/
      *(_DWORD *)(v2 + 148) = v3; /*0x151c4c*/
      *(_DWORD *)(v3 + 144) = v2; /*0x151c52*/
      *(_DWORD *)(v1 + 144) = v1; /*0x151c58*/
      *(_DWORD *)(v1 + 148) = v1; /*0x151c5e*/
    }
  }
  return v1; /*0x151c66*/
}
