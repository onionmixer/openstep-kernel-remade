/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb5d4. */
int __cdecl _NXAudioAddStream(id a1, int a2, int a3, int a4, int a5)
{
  unsigned __int8 v6; // al
  int v7; // edx

  if ( !a1 || !a3 ) /*0x1bb5e5*/
    return 202; /*0x1bb5e7*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a3) ) /*0x1bb5f9*/
    return 200; /*0x1bb605*/
  v6 = (unsigned __int8)objc_msgSend(a1, sel_addStreamTag_user_owner_type_, a4, a2, a3, a5); /*0x1bb621*/
  v7 = 0; /*0x1bb626*/
  if ( !v6 ) /*0x1bb62a*/
    return 5; /*0x1bb62c*/
  return v7; /*0x1bb636*/
}
