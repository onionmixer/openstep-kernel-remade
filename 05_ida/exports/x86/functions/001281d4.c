/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1281d4. */
int __cdecl ip_mloopback(int a1, int *a2, _WORD *a3)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx

  result = m_copy(a2, 0, 1000000000); /*0x1281e4*/
  v4 = result; /*0x1281e9*/
  if ( result ) /*0x1281f0*/
  {
    v5 = *(_DWORD *)(result + 4) + result; /*0x1281f4*/
    *(_WORD *)(v5 + 2) = __ROR2__(*(_WORD *)(v5 + 2), 8); /*0x1281ff*/
    *(_WORD *)(v5 + 6) = __ROR2__(*(_WORD *)(v5 + 6), 8); /*0x12820b*/
    *(_WORD *)(v5 + 10) = 0; /*0x12820f*/
    *(_WORD *)(v5 + 10) = in_cksum(result, 4 * (*(_BYTE *)v5 & 0xF)); /*0x128224*/
    return looutput(a1, v4, a3); /*0x128231*/
  }
  return result; /*0x128239*/
}
