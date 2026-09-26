/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18762c. */
int __cdecl PMGetPowerStatus(_DWORD *a1)
{
  int v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-34h] BYREF
  _BYTE v4[2]; // [esp+8h] [ebp-30h] BYREF
  __int16 v5; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 v6; // [esp+10h] [ebp-28h]
  __int16 v7; // [esp+24h] [ebp-14h]
  __int16 v8; // [esp+26h] [ebp-12h]
  char v9; // [esp+2Ch] [ebp-Ch]
  int v10; // [esp+30h] [ebp-8h]
  unsigned __int8 v11; // [esp+35h] [ebp-3h]
  __int16 v12; // [esp+36h] [ebp-2h]

  if ( !dword_1E75B8 ) /*0x18763d*/
    return 65536003; /*0x1876cc*/
  qmemcpy(v4, "\nS", sizeof(v4)); /*0x187647*/
  v7 = 120; /*0x18764b*/
  v8 = 16; /*0x187651*/
  v10 = dword_1E75B4; /*0x18765d*/
  v5 = 1; /*0x187660*/
  bios32((int)v3); /*0x18766a*/
  if ( (v9 & 1) != 0 ) /*0x187673*/
  {
    if ( v4[1] ) /*0x187692*/
      return v4[1] | 0x3E80000; /*0x18769c*/
    else
      return 65536257; /*0x187694*/
  }
  else
  {
    v12 = v5; /*0x18767e*/
    v11 = v6; /*0x187684*/
    *a1 = HIBYTE(v12); /*0x1876a9*/
    a1[1] = (unsigned __int8)v12; /*0x1876af*/
    v2 = -1; /*0x1876b5*/
    if ( v11 != 0xFF ) /*0x1876bd*/
      v2 = v11; /*0x1876bf*/
    a1[2] = v2; /*0x1876c2*/
    return 0; /*0x1876c5*/
  }
}
