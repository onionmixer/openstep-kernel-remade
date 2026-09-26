/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb788. */
int __cdecl _NXAudioGetSndoutOptions(id a1, _DWORD *a2)
{
  id v3; // esi

  if ( !a1 ) /*0x1bb796*/
    return 202; /*0x1bb798*/
  *a2 = 0; /*0x1bb7a4*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb7b7*/
  if ( objc_msgSend(v3, sel__intValueForParameter_forObject_, 5, a1) ) /*0x1bb7c4*/
    *(_BYTE *)a2 |= 1u; /*0x1bb7d0*/
  if ( objc_msgSend(v3, sel__intValueForParameter_forObject_, 3, a1) ) /*0x1bb7de*/
    *(_BYTE *)a2 |= 2u; /*0x1bb7ea*/
  if ( objc_msgSend(v3, sel__intValueForParameter_forObject_, 4, a1) ) /*0x1bb7f8*/
    *(_BYTE *)a2 |= 4u; /*0x1bb804*/
  if ( objc_msgSend(v3, sel__intValueForParameter_forObject_, 6, a1) ) /*0x1bb812*/
    *(_BYTE *)a2 |= 8u; /*0x1bb81e*/
  if ( !objc_msgSend(v3, sel__intValueForParameter_forObject_, 7, a1) ) /*0x1bb82c*/
    *(_BYTE *)a2 |= 0x10u; /*0x1bb835*/
  return 0; /*0x1bb83d*/
}
