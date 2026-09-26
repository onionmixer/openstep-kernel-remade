/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a7d8. */
void __cdecl tcp_notify(int a1)
{
  int v1; // eax
  int v2; // edx

  v1 = *(_DWORD *)(a1 + 28); /*0x12a7df*/
  v2 = *(unsigned __int16 *)(v1 + 86); /*0x12a7e2*/
  if ( *(_WORD *)(v1 + 6) != 4 && (v2 == 65 || v2 == 51 || v2 == 64) ) /*0x12a7fa*/
  {
    *(_WORD *)(*(_DWORD *)(a1 + 28) + 86) = 0; /*0x12a7ff*/
  }
  else
  {
    *(_WORD *)(*(_DWORD *)(a1 + 32) + 106) = v2; /*0x12a80b*/
    wakeup(*(_DWORD *)(a1 + 28) + 84); /*0x12a816*/
    sowakeup(*(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 28) + 36); /*0x12a823*/
    sowakeup(*(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 28) + 60); /*0x12a830*/
  }
}
