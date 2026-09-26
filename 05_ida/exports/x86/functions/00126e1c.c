/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126e1c. */
char __cdecl ip_stripoptions(unsigned int a1, int a2)
{
  size_t v2; // ebx
  char *v3; // esi
  char result; // al

  v2 = 4 * (*(_BYTE *)a1 & 0xF) - 20; /*0x126e2d*/
  v3 = (char *)(a1 + 20); /*0x126e3b*/
  if ( a2 ) /*0x126e40*/
  {
    *(_WORD *)(a2 + 8) = v2; /*0x126e42*/
    *(_DWORD *)(a2 + 4) = 12; /*0x126e46*/
    bcopy(v3, (void *)(a2 + 12), v2); /*0x126e53*/
  }
  bcopy(&v3[v2], v3, *(__int16 *)((a1 & 0xFFFFFF80) + 8) - 20 - v2); /*0x126e6b*/
  *(_WORD *)((a1 & 0xFFFFFF80) + 8) -= v2; /*0x126e77*/
  result = *(_BYTE *)a1 & 0xF0 | 5; /*0x126e82*/
  *(_BYTE *)a1 = result; /*0x126e84*/
  return result; /*0x126e89*/
}
