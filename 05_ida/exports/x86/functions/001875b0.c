/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1875b0. */
int __cdecl PMGetPowerEvent(_DWORD *a1)
{
  _BYTE v2[5]; // [esp+4h] [ebp-34h] BYREF
  unsigned __int8 v3; // [esp+9h] [ebp-2Fh]
  unsigned __int16 v4; // [esp+Ch] [ebp-2Ch]
  __int16 v5; // [esp+24h] [ebp-14h]
  __int16 v6; // [esp+26h] [ebp-12h]
  char v7; // [esp+2Ch] [ebp-Ch]
  int v8; // [esp+30h] [ebp-8h]
  unsigned __int16 v9; // [esp+36h] [ebp-2h]

  if ( !dword_1E75B8 ) /*0x1875c1*/
    return 65536003; /*0x187620*/
  v3 = 83; /*0x1875c3*/
  v2[4] = 11; /*0x1875c7*/
  v5 = 120; /*0x1875cb*/
  v6 = 16; /*0x1875d1*/
  v8 = dword_1E75B4; /*0x1875dd*/
  bios32((int)v2); /*0x1875e4*/
  if ( (v7 & 1) != 0 ) /*0x1875ed*/
  {
    if ( v3 ) /*0x187602*/
      return v3 | 0x3E80000; /*0x18760c*/
    else
      return 65536257; /*0x187604*/
  }
  else
  {
    v9 = v4; /*0x1875f3*/
    *a1 = v9; /*0x187619*/
    return 0; /*0x18761b*/
  }
}
