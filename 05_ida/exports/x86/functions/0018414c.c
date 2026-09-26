/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18414c. */
int __cdecl sub_18414C(unsigned __int8 a1)
{
  if ( (unsigned __int8)(a1 >> 3) > 0x10u ) /*0x18415b*/
    return 0; /*0x184170*/
  else
    return dword_1E7324[9 * (a1 >> 3)]; /*0x184163*/
}
