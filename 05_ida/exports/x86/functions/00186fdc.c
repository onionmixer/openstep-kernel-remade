/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186fdc. */
char __cdecl catch_interrupt(int a1)
{
  char result; // al
  int *v2; // eax
  int v3; // ecx
  unsigned int v4; // edx
  _DWORD *v5; // eax

  intr_handler(a1); /*0x186fe5*/
  if ( (*(_BYTE *)(a1 + 66) & 2) != 0 || (result = *(_BYTE *)(a1 + 60) & 3, result == 3) ) /*0x186ffa*/
  {
    v2 = *(int **)(*(_DWORD *)(active_threads + 40) + 236); /*0x187005*/
    v3 = 0; /*0x18700b*/
    if ( v2 ) /*0x18700f*/
      v3 = *v2; /*0x187011*/
    if ( v3 && (v4 = *(_DWORD *)(v3 + 132), v4 <= 7) ) /*0x187020*/
      v5 = (_DWORD *)(v3 + 132 * v4 + 136); /*0x187029*/
    else
      v5 = nullptr; /*0x187034*/
    if ( v5 && (v5[30] || v5[29]) ) /*0x187040*/
    {
      if ( v5[18] ) /*0x187046*/
        PCcallMonitor(active_threads, a1); /*0x18704e*/
    }
    return check_for_ast(a1); /*0x187057*/
  }
  return result; /*0x18705f*/
}
