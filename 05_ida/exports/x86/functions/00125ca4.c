/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125ca4. */
int __cdecl icmp_send(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi

  v2 = a1; /*0x125cad*/
  LOBYTE(v2) = a1 & 0x80; /*0x125caf*/
  v3 = 4 * (*(_BYTE *)a1 & 0xF); /*0x125cb9*/
  *(_DWORD *)(v2 + 4) += v3; /*0x125cc1*/
  *(_WORD *)(v2 + 8) -= v3; /*0x125ccb*/
  v4 = v2 + *(_DWORD *)(v2 + 4); /*0x125cd2*/
  *(_WORD *)(v4 + 2) = 0; /*0x125cd4*/
  *(_WORD *)(v4 + 2) = in_cksum(v2, *(__int16 *)(a1 + 2) - v3); /*0x125ce7*/
  *(_DWORD *)(v2 + 4) -= v3; /*0x125cf0*/
  *(_WORD *)(v2 + 8) += v3; /*0x125cfa*/
  return ip_output(v2, a2, 0, 0, 0); /*0x125d11*/
}
