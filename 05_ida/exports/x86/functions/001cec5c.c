/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cec5c. */
int __cdecl sub_1CEC5C(int a1, int a2)
{
  _BYTE *v2; // edx
  int v3; // ecx
  _BYTE *v4; // edx
  _BYTE *v5; // edx
  int v6; // eax
  _BYTE *v7; // edx

  if ( !a2 ) /*0x1cec64*/
    return 0; /*0x1cecac*/
  v2 = *(_BYTE **)(a2 + 8); /*0x1cec66*/
  v3 = 0; /*0x1cec69*/
  while ( *v2 ) /*0x1cec6c*/
  {
    v3 ^= (unsigned __int8)*v2; /*0x1cec74*/
    v4 = v2 + 1; /*0x1cec76*/
    if ( !*v4 ) /*0x1cec77*/
      break; /*0x1cec77*/
    v3 ^= (unsigned __int8)*v4 << 8; /*0x1cec82*/
    v5 = v4 + 1; /*0x1cec84*/
    if ( !*v5 ) /*0x1cec85*/
      break; /*0x1cec85*/
    v6 = (unsigned __int8)*v5 << 16; /*0x1cec8d*/
    v3 ^= v6; /*0x1cec90*/
    v7 = v5 + 1; /*0x1cec92*/
    if ( !*v7 ) /*0x1cec93*/
      break; /*0x1cec93*/
    LOBYTE(v6) = *v7; /*0x1cec98*/
    v3 ^= v6 << 24; /*0x1cec9d*/
    v2 = v7 + 1; /*0x1cec9f*/
  }
  return v3; /*0x1ceca8*/
}
