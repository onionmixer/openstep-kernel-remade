/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108a8c. */
int __cdecl getrusage(int a1, rusage *a2)
{
  int *v2; // ebx
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char v7; // dl
  _DWORD v8[2]; // [esp+4h] [ebp-10h] BYREF
  _DWORD v9[2]; // [esp+Ch] [ebp-8h] BYREF

  v2 = *(int **)(dword_1E875C + 36); /*0x108a99*/
  result = *v2; /*0x108a9c*/
  if ( *v2 == -1 ) /*0x108aa1*/
  {
    v6 = active_u + 440; /*0x108afd*/
  }
  else
  {
    if ( result ) /*0x108aa5*/
    {
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x108b04*/
      return result; /*0x108b08*/
    }
    thread_read_times(active_threads, v9, v8); /*0x108ab6*/
    v4 = active_u; /*0x108abb*/
    *(_DWORD *)(active_u + 368) = v9[0]; /*0x108ac3*/
    *(_DWORD *)(v4 + 372) = v9[1]; /*0x108acc*/
    v5 = active_u; /*0x108ad2*/
    *(_DWORD *)(active_u + 376) = v8[0]; /*0x108ada*/
    *(_DWORD *)(v5 + 380) = v8[1]; /*0x108ae3*/
    v6 = active_u + 368; /*0x108aee*/
  }
  v7 = copyout(v6, v2[1], 72); /*0x108b18*/
  result = dword_1E875C; /*0x108b1a*/
  *(_BYTE *)(dword_1E875C + 104) = v7; /*0x108b1f*/
  return result; /*0x108b22*/
}
