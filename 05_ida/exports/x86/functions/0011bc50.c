/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11bc50. */
int __cdecl vno_stat(_DWORD *a1, int a2)
{
  int result; // eax
  int v3; // edx
  void *v4; // eax
  int v5; // edx
  _BYTE v6[4]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+Ch] [ebp-3Ch]
  __int16 v8; // [esp+Eh] [ebp-3Ah]
  __int16 v9; // [esp+10h] [ebp-38h]
  __int16 v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+18h] [ebp-30h]
  __int16 v12; // [esp+1Ch] [ebp-2Ch]
  int v13; // [esp+20h] [ebp-28h]
  int v14; // [esp+24h] [ebp-24h]
  int v15; // [esp+28h] [ebp-20h]
  int v16; // [esp+30h] [ebp-18h]
  int v17; // [esp+34h] [ebp-14h]
  int v18; // [esp+38h] [ebp-10h]
  __int16 v19; // [esp+40h] [ebp-8h]
  int v20; // [esp+44h] [ebp-4h]

  result = (*(int (__stdcall **)(_DWORD *, _BYTE *, _DWORD))(a1[7] + 20))(a1, v6, *(_DWORD *)(active_u + 28)); /*0x11bc72*/
  if ( !result ) /*0x11bc76*/
  {
    *(_WORD *)(a2 + 8) = v7; /*0x11bc80*/
    *(_WORD *)(a2 + 12) = v8; /*0x11bc88*/
    *(_WORD *)(a2 + 14) = v9; /*0x11bc90*/
    *(_WORD *)a2 = v10; /*0x11bc98*/
    *(_DWORD *)(a2 + 4) = v11; /*0x11bc9e*/
    *(_WORD *)(a2 + 10) = v12; /*0x11bca5*/
    *(_DWORD *)(a2 + 20) = v13; /*0x11bcac*/
    *(_DWORD *)(a2 + 48) = v14; /*0x11bcb2*/
    *(_DWORD *)(a2 + 24) = v15; /*0x11bcb8*/
    *(_DWORD *)(a2 + 28) = 0; /*0x11bcbb*/
    v3 = a1[5]; /*0x11bcc2*/
    if ( (v3 || a1[6]) && (v3 > v16 || v3 == v16 && a1[6] > v17) ) /*0x11bcde*/
      *(_DWORD *)(a2 + 32) = v3; /*0x11bce0*/
    else
      *(_DWORD *)(a2 + 32) = v16; /*0x11bceb*/
    *(_DWORD *)(a2 + 36) = 0; /*0x11bcee*/
    *(_DWORD *)(a2 + 40) = v18; /*0x11bcf8*/
    *(_DWORD *)(a2 + 44) = 0; /*0x11bcfb*/
    *(_WORD *)(a2 + 16) = v19; /*0x11bd06*/
    *(_DWORD *)(a2 + 52) = v20; /*0x11bd0d*/
    *(_DWORD *)(a2 + 60) = 0; /*0x11bd10*/
    *(_DWORD *)(a2 + 56) = 0; /*0x11bd17*/
    v4 = (void *)a1[7]; /*0x11bd1e*/
    if ( v4 == &ufs_vnodeops ) /*0x11bd26*/
    {
      *(_DWORD *)(a2 + 56) = -17958194; /*0x11bd28*/
      *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1[12] + 208); /*0x11bd38*/
    }
    else if ( v4 == &nfs_vnodeops ) /*0x11bd45*/
    {
      v5 = a1[12]; /*0x11bd47*/
      if ( *(_DWORD *)(v5 + 76) == *(_DWORD *)(a2 + 4) ) /*0x11bd50*/
      {
        *(_DWORD *)(a2 + 56) = -17958194; /*0x11bd52*/
        *(_DWORD *)(a2 + 60) = *(_DWORD *)(v5 + 80); /*0x11bd5c*/
      }
    }
    return 0; /*0x11bd5f*/
  }
  return result; /*0x11bd64*/
}
