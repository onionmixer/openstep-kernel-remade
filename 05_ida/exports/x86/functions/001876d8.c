/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1876d8. */
int __cdecl PMSetPowerManagement(int a1, int a2)
{
  _BYTE v3[5]; // [esp+0h] [ebp-30h] BYREF
  unsigned __int8 v4; // [esp+5h] [ebp-2Bh]
  __int16 v5; // [esp+8h] [ebp-28h]
  _BOOL2 v6; // [esp+Ch] [ebp-24h]
  __int16 v7; // [esp+20h] [ebp-10h]
  __int16 v8; // [esp+22h] [ebp-Eh]
  char v9; // [esp+28h] [ebp-8h]
  int v10; // [esp+2Ch] [ebp-4h]

  if ( !dword_1E75B8 ) /*0x1876e5*/
    return 65536003; /*0x187764*/
  if ( a1 != 1 ) /*0x1876eb*/
    return 65536009; /*0x187758*/
  v4 = 83; /*0x1876ed*/
  v3[4] = 8; /*0x1876f1*/
  v7 = 120; /*0x1876f5*/
  v8 = 16; /*0x1876fb*/
  v10 = dword_1E75B4; /*0x187707*/
  v6 = a2 != 0; /*0x187717*/
  v5 = -1; /*0x18771b*/
  bios32((int)v3); /*0x187725*/
  if ( (v9 & 1) == 0 ) /*0x18772e*/
    return 0; /*0x187730*/
  if ( v4 ) /*0x18773e*/
    return v4 | 0x3E80000; /*0x18774c*/
  return 65536257; /*0x187732*/
}
