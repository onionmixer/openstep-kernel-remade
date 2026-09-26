/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1af8. */
int __cdecl PCcancelAllTimers(int a1)
{
  int *v1; // eax
  int v2; // edi
  int v3; // esi
  int result; // eax
  int v5; // [esp+Ch] [ebp-4h]

  v1 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a1b07*/
  v5 = 0; /*0x1a1b0d*/
  if ( v1 ) /*0x1a1b16*/
    v5 = *v1; /*0x1a1b1a*/
  v2 = 0; /*0x1a1b1d*/
  v3 = 0; /*0x1a1b1f*/
  do /*0x1a1b51*/
  {
    calloutRemove((int)sub_1A19C8, v5 + v3 + 136); /*0x1a1b34*/
    result = calloutRemove((int)sub_1A19E8, v5 + v3 + 136); /*0x1a1b3f*/
    v3 += 132; /*0x1a1b47*/
    ++v2; /*0x1a1b4d*/
  }
  while ( v2 <= 7 ); /*0x1a1b51*/
  return result; /*0x1a1b56*/
}
