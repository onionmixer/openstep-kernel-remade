/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187460. */
int __cdecl PMSetCpuState(int a1)
{
  int v1; // eax
  _BYTE v3[4]; // [esp+0h] [ebp-30h] BYREF
  char v4; // [esp+4h] [ebp-2Ch]
  unsigned __int8 v5; // [esp+5h] [ebp-2Bh]
  __int16 v6; // [esp+20h] [ebp-10h]
  __int16 v7; // [esp+22h] [ebp-Eh]
  char v8; // [esp+28h] [ebp-8h]
  int v9; // [esp+2Ch] [ebp-4h]

  if ( !dword_1E75B8 ) /*0x187470*/
  {
    if ( !a1 ) /*0x1874e2*/
      __halt(); /*0x1874e4*/
    return 0; /*0x1874e2*/
  }
  if ( !a1 ) /*0x187474*/
  {
    v5 = 83; /*0x187480*/
    v4 = 5; /*0x187484*/
LABEL_6:
    v6 = 120; /*0x187488*/
    v7 = 16; /*0x18748e*/
    v9 = dword_1E75B4; /*0x18749a*/
    bios32((int)v3); /*0x1874a1*/
    if ( (v8 & 1) == 0 ) /*0x1874aa*/
      return 65536096; /*0x1874de*/
    if ( v5 ) /*0x1874b2*/
      v1 = v5 | 0x3E80000; /*0x1874c8*/
    else
      v1 = 65536257; /*0x1874b4*/
    goto LABEL_11; /*0x1874b9*/
  }
  if ( a1 == 1 ) /*0x187479*/
  {
    v5 = 83; /*0x1874bc*/
    v4 = 6; /*0x1874c0*/
    goto LABEL_6; /*0x1874c4*/
  }
  v1 = 0; /*0x1874d0*/
LABEL_11:
  if ( !v1 ) /*0x1874d4*/
    return 65536096; /*0x1874d4*/
  return 0; /*0x1874db*/
}
