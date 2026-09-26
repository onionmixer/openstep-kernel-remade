/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x128240. */
void __cdecl rip_input(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 4) + a1; /*0x128248*/
  word_1DBE3E = *(unsigned __int8 *)(v1 + 9); /*0x128250*/
  dword_1DBE20 = *(_DWORD *)(v1 + 16); /*0x12825a*/
  dword_1DBE30 = *(_DWORD *)(v1 + 12); /*0x128263*/
  raw_input(a1, &ripproto, &ripsrc, &ripdst); /*0x128278*/
}
