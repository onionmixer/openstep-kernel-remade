/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c7b0. */
int __cdecl intr_change_mode(unsigned int a1, int a2)
{
  __int16 v3; // kr00_2
  __int16 v4; // si

  if ( !eisa_present() || a1 > 0xF || !dword_1E2208[a1] ) /*0x18c7cf*/
    return 0; /*0x18c7d9*/
  v3 = __readeflags(); /*0x18c7e0*/
  _disable(); /*0x18c7e2*/
  if ( a2 ) /*0x18c7f6*/
    v4 = (1 << a1) | word_1E7720; /*0x18c7ff*/
  else
    v4 = __ROL4__(-2, a1) & word_1E7720; /*0x18c80b*/
  if ( word_1E7720 != v4 ) /*0x18c815*/
  {
    word_1E7720 = v4; /*0x18c817*/
    __outbyte(0x4D0u, v4); /*0x18c827*/
    _InterlockedIncrement(dword_1E7618); /*0x18c828*/
    __outbyte(0x4D1u, HIBYTE(v4)); /*0x18c83a*/
    _InterlockedIncrement(dword_1E7618); /*0x18c83b*/
  }
  __readeflags(); /*0x18c842*/
  if ( (v3 & 0x200) != 0 ) /*0x18c846*/
    _enable(); /*0x18c848*/
  else
    _disable(); /*0x18c84c*/
  return 1; /*0x18c855*/
}
