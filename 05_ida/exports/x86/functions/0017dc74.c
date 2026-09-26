/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17dc74. */
int __cdecl vnode_dealloc(int a1)
{
  int v1; // edx
  int v2; // edx
  unsigned int v3; // edx
  _DWORD *v4; // esi
  signed int v5; // ebx
  unsigned int v6; // ebx
  int v7; // edx
  signed int v8; // edx
  int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // edx
  _DWORD *v12; // esi
  signed int v13; // ebx
  unsigned int v14; // ebx
  int v15; // eax
  signed int v16; // edx
  int v17; // eax
  unsigned int v18; // edx
  int v19; // esi
  unsigned int v20; // ebx
  int v21; // ebx
  int v22; // edi
  int v23; // ebx
  int v24; // eax
  int v25; // ebx
  int v26; // eax
  int *v28; // [esp+Ch] [ebp-60h]
  int *v29; // [esp+Ch] [ebp-60h]
  _DWORD *v30; // [esp+Ch] [ebp-60h]
  unsigned int i; // [esp+18h] [ebp-54h]
  unsigned int v32; // [esp+1Ch] [ebp-50h]
  int v33; // [esp+1Ch] [ebp-50h]
  int v34; // [esp+20h] [ebp-4Ch]
  int j; // [esp+24h] [ebp-48h]
  _BYTE v36[24]; // [esp+2Ch] [ebp-40h] BYREF
  int v37; // [esp+44h] [ebp-28h]

  do /*0x17dc9d*/
  {
    while ( vstruct_lock ) /*0x17dc8b*/
      ; /*0x17dc89*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17dc9d*/
  ++*(_WORD *)(a1 + 14); /*0x17dca2*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17dca8*/
  v1 = *(_DWORD *)(a1 + 20); /*0x17dcae*/
  dword_1E0E58 = 0; /*0x17dcb1*/
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x17dcbf*/
  {
    v34 = *(_DWORD *)(a1 + 4); /*0x17dcc8*/
    v2 = *(_DWORD *)(a1 + 16); /*0x17dccb*/
    if ( (unsigned int)(4 * v2) <= 0x40 ) /*0x17dcd8*/
    {
      v33 = 0; /*0x17de58*/
      if ( v2 > 0 ) /*0x17de62*/
      {
        do /*0x17df63*/
        {
          v11 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v33); /*0x17de71*/
          if ( (_BYTE)v11 ) /*0x17de76*/
          {
            v12 = (_DWORD *)dword_1E7294[(unsigned __int8)v11]; /*0x17de7b*/
            v13 = v11 >> 8; /*0x17de84*/
            lock_write((int)(v12 + 13)); /*0x17de8e*/
            if ( v12[5] <= v13 ) /*0x17de99*/
              panic(aVnodePagerDeal); /*0x17dea0*/
            if ( v12[9] > v13 ) /*0x17deab*/
              v12[9] = v13; /*0x17dead*/
            *(_BYTE *)(v13 / 8 + v12[4]) &= __ROL4__(-2, v13 % 8); /*0x17ded7*/
            ++v12[6]; /*0x17deda*/
            lock_done(v12 + 13); /*0x17dee1*/
          }
          v14 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v33); /*0x17def2*/
          if ( (_BYTE)v14 ) /*0x17def7*/
          {
            v15 = 0; /*0x17def9*/
            if ( dword_1E0E58 <= 0 ) /*0x17df03*/
            {
LABEL_42:
              dword_1E72D4[dword_1E0E58++] = v14; /*0x17df45*/
            }
            else
            {
              v29 = dword_1E72D4; /*0x17df0a*/
              while ( *(_BYTE *)v29 != (_BYTE)v14 ) /*0x17df19*/
              {
                ++v29; /*0x17df3c*/
                if ( ++v15 >= dword_1E0E58 ) /*0x17df43*/
                  goto LABEL_42; /*0x17df43*/
              }
              v16 = (unsigned int)*v29 >> 8; /*0x17df1f*/
              if ( v16 < (int)(v14 >> 8) ) /*0x17df24*/
                v16 = v14 >> 8; /*0x17df26*/
              *v29 = (v16 << 8) | (unsigned __int8)*v29; /*0x17df35*/
            }
          }
          ++v33; /*0x17df57*/
        }
        while ( *(_DWORD *)(a1 + 16) > v33 ); /*0x17df63*/
      }
      v9 = a1; /*0x17df69*/
      v17 = *(_DWORD *)(a1 + 16); /*0x17df6c*/
      if ( v17 <= 0 ) /*0x17df71*/
        goto LABEL_47; /*0x17df71*/
      v10 = 4 * v17; /*0x17df73*/
    }
    else
    {
      v32 = 0; /*0x17dce4*/
      if ( (unsigned int)(v2 - 1) >> 4 != -1 ) /*0x17dcee*/
      {
        do /*0x17de3c*/
        {
          if ( *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v32) ) /*0x17dcfd*/
          {
            for ( i = 0; i <= 0xF; ++i ) /*0x17dd07*/
            {
              v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v32) + 4 * i); /*0x17dd1f*/
              if ( (_BYTE)v3 ) /*0x17dd24*/
              {
                v4 = (_DWORD *)dword_1E7294[(unsigned __int8)v3]; /*0x17dd29*/
                v5 = v3 >> 8; /*0x17dd32*/
                lock_write((int)(v4 + 13)); /*0x17dd3c*/
                if ( v4[5] <= v5 ) /*0x17dd47*/
                  panic(aVnodePagerDeal); /*0x17dd4e*/
                if ( v4[9] > v5 ) /*0x17dd59*/
                  v4[9] = v5; /*0x17dd5b*/
                *(_BYTE *)(v5 / 8 + v4[4]) &= __ROL4__(-2, v5 % 8); /*0x17dd85*/
                ++v4[6]; /*0x17dd88*/
                lock_done(v4 + 13); /*0x17dd8f*/
              }
              v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v32) + 4 * i); /*0x17dda6*/
              if ( (_BYTE)v6 ) /*0x17ddab*/
              {
                v7 = 0; /*0x17ddad*/
                if ( dword_1E0E58 <= 0 ) /*0x17ddb6*/
                {
LABEL_22:
                  dword_1E72D4[dword_1E0E58++] = v6; /*0x17ddf5*/
                }
                else
                {
                  v28 = dword_1E72D4; /*0x17ddbd*/
                  while ( *(_BYTE *)v28 != (_BYTE)v6 ) /*0x17ddc9*/
                  {
                    ++v28; /*0x17ddec*/
                    if ( ++v7 >= dword_1E0E58 ) /*0x17ddf3*/
                      goto LABEL_22; /*0x17ddf3*/
                  }
                  v8 = (unsigned int)*v28 >> 8; /*0x17ddcf*/
                  if ( v8 < (int)(v6 >> 8) ) /*0x17ddd4*/
                    v8 = v6 >> 8; /*0x17ddd6*/
                  *v28 = (v8 << 8) | (unsigned __int8)*v28; /*0x17dde5*/
                }
              }
            }
            kfree(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 4 * v32), 0x40u); /*0x17de23*/
          }
          ++v32; /*0x17de2b*/
        }
        while ( v32 < ((unsigned int)(*(_DWORD *)(a1 + 16) - 1) >> 4) + 1 ); /*0x17de3c*/
      }
      v9 = a1; /*0x17de42*/
      v10 = 4 * ((unsigned int)(*(_DWORD *)(a1 + 16) - 1) >> 4) + 4; /*0x17de4c*/
    }
    kfree(*(_DWORD *)(v9 + 8), v10); /*0x17df7b*/
LABEL_47:
    --*(_DWORD *)(v34 + 12); /*0x17df83*/
    goto LABEL_49; /*0x17df89*/
  }
  *(_BYTE *)(v1 + 4) &= ~2u; /*0x17df8c*/
  **(_DWORD **)v1 = 0; /*0x17df92*/
  vn_rele(v1); /*0x17df99*/
LABEL_49:
  for ( j = 0; dword_1E0E58 > j; ++j )
  {
    v18 = dword_1E72D4[j]; /*0x17dfc3*/
    v19 = dword_1E7294[(unsigned __int8)v18]; /*0x17dfcd*/
    v30 = *(_DWORD **)(v19 + 8); /*0x17dfd7*/
    v20 = v18 >> 8; /*0x17dfdc*/
    if ( *(_DWORD *)(v19 + 32) <= (signed int)(v18 >> 8) && !swapfs_enabled )
    {
      lock_write(v19 + 52); /*0x17dff9*/
      v21 = v20 - 1; /*0x17dffe*/
      if ( v21 >= 0 ) /*0x17e004*/
      {
        while ( 1 ) /*0x17e027*/
        {
          v22 = *(char *)(v21 / 8 + *(_DWORD *)(v19 + 16)); /*0x17e027*/
          if ( _bittest(&v22, v21 % 8) ) /*0x17e02d*/
            break; /*0x17e02d*/
          if ( --v21 < 0 ) /*0x17e030*/
            goto LABEL_55; /*0x17e030*/
        }
        *(_DWORD *)(v19 + 32) = v21; /*0x17e064*/
      }
LABEL_55:
      v23 = *(_DWORD *)(v19 + 32) + 1; /*0x17e032*/
      v24 = *(_DWORD *)(v19 + 28); /*0x17e036*/
      if ( v24 && v23 > v24 && *(_DWORD *)(*v30 + 20) >= (unsigned int)(v23 << page_shift) )
      {
        vattr_null(v36); /*0x17e070*/
        v37 = v23 << page_shift; /*0x17e07e*/
        v25 = *(_DWORD *)(active_u + 28); /*0x17e087*/
        *(_DWORD *)(active_u + 28) = *(_DWORD *)(*v30 + 48); /*0x17e092*/
        v26 = (*(int (__cdecl **)(_DWORD *, _BYTE *, _DWORD))(v30[7] + 24))(v30, v36, *(_DWORD *)(*v30 + 48)); /*0x17e0a6*/
        if ( v26 )
          printf("vnode_deallocpage: error truncating %s, error = %d\n", *(const char **)(v19 + 40), v26);
        *(_DWORD *)(active_u + 28) = v25; /*0x17e0c6*/
      }
      lock_done(v19 + 52); /*0x17e0cd*/
    }
  }
  return zfree(vstruct_zone, a1); /*0x17e0fa*/
}
