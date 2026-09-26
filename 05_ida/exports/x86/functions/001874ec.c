/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1874ec. */
int __usercall PMSetPowerState@<eax>(int a1@<ebx>, unsigned int a2, int a3)
{
  _BYTE v4[5]; // [esp+10h] [ebp-30h] BYREF
  unsigned __int8 v5; // [esp+15h] [ebp-2Bh]
  __int16 v6; // [esp+18h] [ebp-28h]
  __int16 v7; // [esp+1Ch] [ebp-24h]
  __int16 v8; // [esp+30h] [ebp-10h]
  __int16 v9; // [esp+32h] [ebp-Eh]
  char v10; // [esp+38h] [ebp-8h]
  int v11; // [esp+3Ch] [ebp-4h]

  if ( a2 == 1 ) /*0x1874fe*/
    _io_setDriverPowerState(a1, a3); /*0x187501*/
  if ( !dword_1E75B8 ) /*0x187510*/
    return 65536003; /*0x1875a0*/
  if ( a2 == 1 && (!a3 || a3 == 3) ) /*0x187522*/
    return 65536096; /*0x187524*/
  v5 = 83; /*0x187546*/
  v4[4] = 7; /*0x18754a*/
  v8 = 120; /*0x18754e*/
  v9 = 16; /*0x187554*/
  v11 = dword_1E75B4; /*0x187560*/
  v6 = (a2 >> 8) & 0xFF00 | (unsigned __int8)a2; /*0x18756a*/
  v7 = a3; /*0x18756e*/
  bios32((int)v4); /*0x187576*/
  if ( (v10 & 1) == 0 ) /*0x18757f*/
    return 0; /*0x187581*/
  if ( v5 ) /*0x18758e*/
    return v5 | 0x3E80000; /*0x187598*/
  return 65536257; /*0x1875a8*/
}
