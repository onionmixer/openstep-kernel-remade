/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142cd0. */
char __cdecl clrblock(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  char v5; // cl

  v3 = *(_DWORD *)(a1 + 56); /*0x142cdd*/
  if ( v3 == 2 ) /*0x142ce3*/
  {
    v4 = a3 >> 2; /*0x142d1a*/
    v5 = 2 * (a3 & 3); /*0x142d24*/
    v3 = 3; /*0x142d26*/
    goto LABEL_10; /*0x142d26*/
  }
  if ( v3 > 2 ) /*0x142ce5*/
  {
    if ( v3 != 4 ) /*0x142cf3*/
    {
      if ( v3 != 8 ) /*0x142cf8*/
        goto LABEL_12; /*0x142cf8*/
      *(_BYTE *)(a3 + a2) = 0; /*0x142cfa*/
      return v3; /*0x142cfe*/
    }
    v4 = a3 >> 1; /*0x142d02*/
    v5 = 4 * (a3 & 1); /*0x142d09*/
    v3 = 15; /*0x142d10*/
LABEL_10:
    LOBYTE(v3) = ~(unsigned __int8)(v3 << v5); /*0x142d2b*/
    *(_BYTE *)(v4 + a2) &= v3; /*0x142d2f*/
    return v3; /*0x142d32*/
  }
  if ( v3 != 1 ) /*0x142cea*/
LABEL_12:
    panic(aClrblock); /*0x142d48*/
  LOBYTE(v3) = __ROL4__(-2, a3 & 7); /*0x142d41*/
  *(_BYTE *)((a3 >> 3) + a2) &= v3; /*0x142d43*/
  return v3; /*0x142d52*/
}
