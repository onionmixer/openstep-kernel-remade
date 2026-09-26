/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19293c. */
void __cdecl unix_syscall_return(int a1)
{
  int v1; // edx
  thread_act_t v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  char v6; // al

  v1 = a1; /*0x192944*/
  v2 = active_threads; /*0x192947*/
  v3 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x192950*/
  if ( v3 ) /*0x192955*/
  {
    v4 = v3 + 132; /*0x192957*/
  }
  else
  {
    v4 = thread_user_state(active_threads); /*0x19296c*/
    v1 = a1; /*0x19296e*/
  }
  v5 = *(_DWORD *)(v2 + 132); /*0x192971*/
  if ( v1 == 28 ) /*0x192979*/
  {
    if ( fspause(0) ) /*0x192989*/
      *(_BYTE *)(dword_1E875C + 105) = 2; /*0x19299a*/
    v1 = *(char *)(v5 + 104); /*0x19299e*/
  }
  v6 = *(_BYTE *)(v5 + 105); /*0x1929a2*/
  if ( v6 == 3 ) /*0x1929a7*/
  {
    if ( v1 ) /*0x1929ab*/
    {
      *(_DWORD *)(v4 + 44) = v1; /*0x1929ad*/
      *(_BYTE *)(v4 + 64) |= 1u; /*0x1929b0*/
    }
    else
    {
      *(_DWORD *)(v4 + 44) = *(_DWORD *)(v5 + 96); /*0x1929bb*/
      *(_DWORD *)(v4 + 36) = *(_DWORD *)(v5 + 100); /*0x1929c1*/
      *(_DWORD *)(v4 + 64) &= ~1u; /*0x1929c4*/
    }
  }
  else if ( v6 == 2 ) /*0x1929ce*/
  {
    *(_DWORD *)(v4 + 56) -= 7; /*0x1929d0*/
  }
  *(_BYTE *)(v5 + 104) = v1; /*0x1929d4*/
  thread_exception_return(); /*0x1929d7*/
}
