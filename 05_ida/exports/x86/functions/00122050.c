/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122050. */
int __cdecl rtinit(int *a1, int *a2, int a3, __int16 a4)
{
  _BYTE v5[4]; // [esp+Ch] [ebp-30h] BYREF
  int v6; // [esp+10h] [ebp-2Ch]
  int v7; // [esp+14h] [ebp-28h]
  int v8; // [esp+18h] [ebp-24h]
  int v9; // [esp+1Ch] [ebp-20h]
  int v10; // [esp+20h] [ebp-1Ch]
  int v11; // [esp+24h] [ebp-18h]
  int v12; // [esp+28h] [ebp-14h]
  int v13; // [esp+2Ch] [ebp-10h]
  __int16 v14; // [esp+30h] [ebp-Ch]

  bzero(v5, 0x30u); /*0x122065*/
  v6 = *a1; /*0x12206c*/
  v7 = a1[1]; /*0x122072*/
  v8 = a1[2]; /*0x122078*/
  v9 = a1[3]; /*0x12207e*/
  v10 = *a2; /*0x122083*/
  v11 = a2[1]; /*0x122089*/
  v12 = a2[2]; /*0x12208f*/
  v13 = a2[3]; /*0x122095*/
  v14 = a4; /*0x12209c*/
  return rtrequest(a3, (int)v5); /*0x1220ad*/
}
