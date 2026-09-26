/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c034. */
int __cdecl task_by_unix_pid(int a1, int a2, _DWORD *a3)
{
  int v3; // ebx
  int v4; // eax
  int v5; // eax

  v3 = pfind(a2); /*0x17c049*/
  if ( v3 /*0x17c070*/
    && (v4 = *(_DWORD *)(a1 + 60)) != 0
    && (*(_WORD *)(v3 + 44) == *(_WORD *)(v4 + 44) || suser())
    && *(_BYTE *)(v3 + 19) != 5 )
  {
    if ( *(_DWORD *)(v3 + 104) ) /*0x17c072*/
      task_reference(*(_DWORD *)(v3 + 104)); /*0x17c07a*/
    *a3 = *(_DWORD *)(v3 + 104); /*0x17c085*/
    if ( suser() ) /*0x17c087*/
    {
      v5 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 60); /*0x17c098*/
      if ( v5 ) /*0x17c09d*/
        *(_BYTE *)(v5 + 22) |= 1u; /*0x17c09f*/
    }
    return 0; /*0x17c0a3*/
  }
  else
  {
    *a3 = 0; /*0x17c0a8*/
    return 5; /*0x17c0ae*/
  }
}
