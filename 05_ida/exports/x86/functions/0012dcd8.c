/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12dcd8. */
_BOOL4 __cdecl sub_12DCD8(int a1, _DWORD *a2, _WORD *a3)
{
  int v3; // edx
  char *v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  _WORD *v11; // edx
  _WORD *i; // ecx
  int v13; // [esp+Ch] [ebp-14h]
  __int16 v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-4h]

  if ( nfs_portmon ) /*0x12dcee*/
  {
    v3 = a2[7]; /*0x12dcf0*/
    if ( __ROR2__(*(_WORD *)(v3 + 18), 8) > 0x3FFu ) /*0x12dcff*/
    {
      v4 = inet_ntoa((in_addr)(v3 + 20)); /*0x12dd05*/
      printf("NFS request from unprivileged port from %s\n", v4); /*0x12dd10*/
      return 0; /*0x12dd17*/
    }
  }
  v6 = a2[3]; /*0x12dd1c*/
  if ( *(_DWORD *)(a1 + 8) != v6 ) /*0x12dd25*/
    v6 = 0; /*0x12dd27*/
  if ( v6 ) /*0x12dd2b*/
  {
    if ( v6 != 1 ) /*0x12dd30*/
      return 0; /*0x12de12*/
    v13 = a2[6]; /*0x12dd39*/
    if ( *(_DWORD *)(v13 + 8) ) /*0x12dd3c*/
      goto LABEL_18; /*0x12dd40*/
    v7 = a2[7]; /*0x12dd42*/
    v15 = v7 + 16; /*0x12dd48*/
    v8 = 0; /*0x12dd54*/
    if ( *(_DWORD *)(a1 + 12) ) /*0x12dd59*/
    {
      v14 = *(_WORD *)(v7 + 16); /*0x12dd62*/
      v9 = *(_DWORD *)(a1 + 16); /*0x12dd6c*/
      while ( *(_WORD *)v9 != v14 || v14 != 2 || *(_DWORD *)(v15 + 4) != *(_DWORD *)(v9 + 4) ) /*0x12dd74*/
      {
        v9 += 16; /*0x12dd9a*/
        if ( *(_DWORD *)(a1 + 12) <= (unsigned int)++v8 ) /*0x12dda3*/
          goto LABEL_17; /*0x12dda3*/
      }
LABEL_18:
      a3[1] = *(_WORD *)(v13 + 8); /*0x12ddc0*/
      a3[2] = *(_WORD *)(v13 + 12); /*0x12ddd2*/
      v11 = a3 + 5; /*0x12ddd6*/
      for ( i = *(_WORD **)(v13 + 20); v11 < &a3[*(_DWORD *)(v13 + 16) + 5]; ++v11 ) /*0x12ddec*/
      {
        *v11 = *i; /*0x12ddf3*/
        i += 2; /*0x12ddf6*/
      }
      goto LABEL_22; /*0x12de0c*/
    }
  }
LABEL_17:
  a3[1] = *(_WORD *)(a1 + 4); /*0x12dda5*/
  a3[2] = *(_WORD *)(a1 + 4); /*0x12ddb7*/
  v11 = a3 + 5; /*0x12ddbb*/
LABEL_22:
  while ( v11 < a3 + 21 ) /*0x12de19*/
    *v11++ = -1; /*0x12de1c*/
  return a3[1] != 0xFFFF; /*0x12de38*/
}
