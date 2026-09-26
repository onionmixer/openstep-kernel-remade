/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121ba0. */
int __cdecl rtfree(int a1)
{
  int v1; // eax
  int result; // eax

  if ( !a1 ) /*0x121ba9*/
    panic(aRtfree); /*0x121bb0*/
  --*(_WORD *)(a1 + 38); /*0x121bb8*/
  if ( (*(_DWORD *)(a1 + 36) & 0xFFFF0001) == 0 ) /*0x121bc3*/
  {
    --rttrash; /*0x121bc5*/
    v1 = a1; /*0x121bcb*/
    LOBYTE(v1) = a1 & 0x80; /*0x121bcd*/
    return m_free(v1); /*0x121bd0*/
  }
  return result; /*0x121bd5*/
}
