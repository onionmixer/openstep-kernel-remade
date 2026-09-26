/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1439f8. */
int __cdecl sbupdate(int a1)
{
  int result; // eax
  int v2; // ebx
  int i; // edi
  unsigned int v4; // esi
  int v5; // ebx
  char *v6; // [esp+1Ch] [ebp-Ch]
  int v7; // [esp+20h] [ebp-8h]
  _DWORD *v8; // [esp+24h] [ebp-4h]

  v8 = *(_DWORD **)(*(_DWORD *)(a1 + 12) + 32); /*0x143a0a*/
  result = (*(int (__cdecl **)(_DWORD))(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 28) + 128))(*(_DWORD *)(a1 + 8)); /*0x143a20*/
  if ( result >= 0 ) /*0x143a29*/
  {
    v2 = getblk(*(_DWORD *)(a1 + 8), 0x2000 / result, v8[26]); /*0x143a4f*/
    bcopy(v8, *(void **)(v2 + 32), v8[26]); /*0x143a60*/
    byte_swap_superblock(*(_DWORD *)(v2 + 32)); /*0x143a69*/
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 140) = 0; /*0x143a71*/
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 136) = 0; /*0x143a7e*/
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 148) = 0; /*0x143a8b*/
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 144) = 0; /*0x143a98*/
    *(_BYTE *)(*(_DWORD *)(v2 + 32) + 211) = 0; /*0x143aa5*/
    bwrite((int *)v2); /*0x143aad*/
    result = (v8[13] + v8[39] - 1) / v8[13]; /*0x143ac7*/
    v7 = result; /*0x143aca*/
    v6 = (char *)v8[182]; /*0x143ad3*/
    for ( i = 0; v7 > i; i += v8[14] ) /*0x143add*/
    {
      v4 = v8[12]; /*0x143ae3*/
      if ( v8[14] + i > v7 ) /*0x143af0*/
        v4 = v8[13] * (v7 - i); /*0x143af9*/
      v5 = getblk(*(_DWORD *)(a1 + 8), (i + v8[38]) << v8[25], v4); /*0x143b20*/
      bcopy(v6, *(void **)(v5 + 32), v4); /*0x143b2b*/
      byte_swap_ints(*(_DWORD *)(v5 + 32), v4 >> 2); /*0x143b3a*/
      v6 += v4; /*0x143b3f*/
      result = bwrite((int *)v5); /*0x143b46*/
    }
  }
  return result; /*0x143b5c*/
}
