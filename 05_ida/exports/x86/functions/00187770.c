/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187770. */
int PMRestoreDefaults()
{
  _BYTE v1[4]; // [esp+0h] [ebp-30h] BYREF
  _BYTE v2[2]; // [esp+4h] [ebp-2Ch] BYREF
  __int16 v3; // [esp+8h] [ebp-28h]
  __int16 v4; // [esp+20h] [ebp-10h]
  __int16 v5; // [esp+22h] [ebp-Eh]
  char v6; // [esp+28h] [ebp-8h]
  int v7; // [esp+2Ch] [ebp-4h]

  if ( !dword_1E75B8 ) /*0x18777d*/
    return 65536003; /*0x1877d8*/
  qmemcpy(v2, "\tS", sizeof(v2)); /*0x187783*/
  v4 = 120; /*0x187787*/
  v5 = 16; /*0x18778d*/
  v7 = dword_1E75B4; /*0x187799*/
  v3 = -1; /*0x18779c*/
  bios32((int)v1); /*0x1877a6*/
  if ( (v6 & 1) == 0 ) /*0x1877af*/
    return 0; /*0x1877b1*/
  if ( v2[1] ) /*0x1877be*/
    return v2[1] | 0x3E80000; /*0x1877cc*/
  return 65536257; /*0x1877b3*/
}
