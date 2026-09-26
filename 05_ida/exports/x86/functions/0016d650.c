/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d650. */
int __cdecl kern_serv_handler(_DWORD *a1, int a2)
{
  int v2; // edx
  int (__cdecl *v3)(int, int, int); // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-20h] BYREF
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  int v11; // [esp+24h] [ebp-8h]
  int v12; // [esp+28h] [ebp-4h]

  v5[3] = 1; /*0x16d662*/
  v6 = 32; /*0x16d666*/
  v7 = a1[2]; /*0x16d670*/
  v8 = 0; /*0x16d673*/
  v9 = a1[4]; /*0x16d67d*/
  v10 = a1[5] + 100; /*0x16d686*/
  v11 = 268509186; /*0x16d68f*/
  v12 = -303; /*0x16d692*/
  v2 = a1[5]; /*0x16d699*/
  if ( (unsigned int)(v2 - 100) > 0xC ) /*0x16d6a2*/
    return -303; /*0x16d6a2*/
  v3 = funcs_16D6BB[v2 - 100]; /*0x16d6a4*/
  if ( !v3 ) /*0x16d6ad*/
    return -303; /*0x16d6af*/
  v3((int)a1, (int)v5, a2); /*0x16d6bb*/
  if ( v12 == -305 ) /*0x16d6c7*/
    return 0; /*0x16d6e0*/
  else
    return msg_send(v5, *(_DWORD *)(a2 + 4) >= 0, *(_DWORD *)(a2 + 4)); /*0x16d6d6*/
}
