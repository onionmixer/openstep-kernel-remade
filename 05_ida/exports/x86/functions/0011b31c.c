/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b31c. */
void __cdecl dnlc_enter(int a1, char *a2, int a3, _WORD *a4)
{
  unsigned int v4; // eax
  size_t v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // edx
  int v9; // [esp+Ch] [ebp-4h]

  if ( doingcache ) /*0x11b32f*/
  {
    v4 = strlen(a2) + 1; /*0x11b340*/
    v5 = v4 - 1; /*0x11b346*/
    if ( (int)(v4 - 1) <= 32 ) /*0x11b34c*/
    {
      v9 = ((_BYTE)a1 + (_BYTE)v5 + a2[v5 - 1] + *a2) & 0x3F; /*0x11b370*/
      if ( sub_11B8DC(a1, a2, v4 - 1, v9, (int)a4) ) /*0x11b381*/
      {
        ++dword_1E9C0C; /*0x11b38f*/
      }
      else
      {
        v6 = dword_1E9BE8; /*0x11b39c*/
        if ( (_UNKNOWN *)dword_1E9BE8 == &nc_lru ) /*0x11b3a8*/
        {
          ++dword_1E9C18; /*0x11b3aa*/
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)(dword_1E9BE8 + 12) + 8) = *(_DWORD *)(dword_1E9BE8 + 8); /*0x11b3be*/
          *(_DWORD *)(*(_DWORD *)(v6 + 8) + 12) = *(_DWORD *)(v6 + 12); /*0x11b3c7*/
          *(_DWORD *)(*(_DWORD *)v6 + 4) = *(_DWORD *)(v6 + 4); /*0x11b3cf*/
          **(_DWORD **)(v6 + 4) = *(_DWORD *)v6; /*0x11b3d7*/
          if ( *(_DWORD *)(v6 + 20) ) /*0x11b3d9*/
          {
            if ( *(_DWORD *)(v6 + 16) ) /*0x11b3df*/
              --dword_1E9C20; /*0x11b3e5*/
            if ( *(_DWORD *)(v6 + 20) ) /*0x11b3eb*/
              vn_rele(*(_DWORD *)(v6 + 20)); /*0x11b3f3*/
          }
          if ( *(_DWORD *)(v6 + 16) ) /*0x11b3fb*/
            vn_rele(*(_DWORD *)(v6 + 16)); /*0x11b403*/
          if ( *(_DWORD *)(v6 + 60) ) /*0x11b40b*/
            crfree(*(_DWORD *)(v6 + 60)); /*0x11b413*/
          if ( *(_BYTE *)(v6 + 68) ) /*0x11b41b*/
            kfree(*(_DWORD *)(v6 + 64), *(__int16 *)(v6 + 70)); /*0x11b42a*/
          *(_DWORD *)(v6 + 20) = a1; /*0x11b432*/
          ++*(_WORD *)(a1 + 6); /*0x11b435*/
          *(_DWORD *)(v6 + 16) = a3; /*0x11b43c*/
          ++*(_WORD *)(a3 + 6); /*0x11b43f*/
          *(_BYTE *)(v6 + 24) = v5; /*0x11b445*/
          bcopy(a2, (void *)(v6 + 25), v5); /*0x11b451*/
          *(_BYTE *)(v6 + 68) = 0; /*0x11b456*/
          *(_WORD *)(v6 + 70) = 0; /*0x11b45a*/
          *(_DWORD *)(v6 + 64) = 0; /*0x11b460*/
          *(_DWORD *)(v6 + 60) = a4; /*0x11b46a*/
          if ( a4 ) /*0x11b46f*/
            ++*a4; /*0x11b471*/
          v7 = dword_1E9BEC; /*0x11b474*/
          v8 = *(_DWORD *)(dword_1E9BEC + 8); /*0x11b479*/
          *(_DWORD *)(dword_1E9BEC + 8) = v6; /*0x11b47c*/
          *(_DWORD *)(v6 + 8) = v8; /*0x11b47f*/
          *(_DWORD *)(v8 + 12) = v6; /*0x11b482*/
          *(_DWORD *)(v6 + 12) = v7; /*0x11b485*/
          *(_DWORD *)v6 = nc_hash[2 * v9]; /*0x11b498*/
          *(_DWORD *)(v6 + 4) = &nc_hash[2 * v9]; /*0x11b4a0*/
          *(_DWORD *)(nc_hash[2 * v9] + 4) = v6; /*0x11b4a9*/
          nc_hash[2 * v9] = v6; /*0x11b4ac*/
          ++dword_1E9C20; /*0x11b4b2*/
          ++dword_1E9C08; /*0x11b4b8*/
        }
      }
    }
    else
    {
      ++dword_1E9C10; /*0x11b34e*/
    }
  }
}
