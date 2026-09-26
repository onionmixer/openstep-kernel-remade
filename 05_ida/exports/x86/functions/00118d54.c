/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118d54. */
__int16 smount()
{
  int v0; // edi
  int *v1; // eax
  __int16 result; // ax
  int v3; // edx
  int v4; // eax
  char v5; // bl
  int v6; // ebx
  char **i; // ebx
  int v8; // esi
  int v9; // eax
  char *j; // ebx
  char *v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // ebx
  __int16 v15; // ax
  int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h] BYREF
  int v19; // [esp+18h] [ebp-10h] BYREF
  _BYTE v20[4]; // [esp+1Ch] [ebp-Ch] BYREF
  char *__s1; // [esp+20h] [ebp-8h]

  v0 = *(_DWORD *)(dword_1E875C + 36); /*0x118d62*/
  v19 = 0; /*0x118d65*/
  v1 = nullptr; /*0x118d70*/
  if ( (*(_BYTE *)(v0 + 8) & 0x10) == 0 ) /*0x118d76*/
    v1 = &v19; /*0x118d78*/
  *(_BYTE *)(dword_1E875C + 104) = lookupname(*(_DWORD *)(v0 + 4), 0, 1, v1, &v18); /*0x118d90*/
  result = dword_1E875C; /*0x118d93*/
  if ( !*(_BYTE *)(dword_1E875C + 104) )
  {
    if ( v18 )
    {
      if ( v19 ) /*0x118db4*/
        vn_rele(v19); /*0x118db7*/
      v3 = v18; /*0x118dbf*/
      if ( (*(_BYTE *)(*(_DWORD *)(v18 + 36) + 12) & 0x20) == 0 )
      {
        dnlc_purge(); /*0x118dcf*/
        if ( *(_WORD *)(v18 + 6) != 1 && (*(_BYTE *)(v0 + 8) & 0x10) == 0 ) /*0x118de2*/
          goto LABEL_14; /*0x118de2*/
        if ( *(_DWORD *)(v18 + 40) != 2 ) /*0x118def*/
        {
          vn_rele(v18); /*0x118df2*/
          result = dword_1E875C; /*0x118df7*/
          *(_BYTE *)(dword_1E875C + 104) = 20; /*0x118dfc*/
          return result; /*0x118e00*/
        }
        if ( (*(_BYTE *)(v18 + 4) & 1) != 0 ) /*0x118e0c*/
        {
          if ( (*(_BYTE *)(v0 + 8) & 0x10) == 0 ) /*0x118e12*/
          {
LABEL_14:
            vn_rele(v18); /*0x118e18*/
            result = dword_1E875C; /*0x118e1e*/
            *(_BYTE *)(dword_1E875C + 104) = 16; /*0x118e23*/
            return result; /*0x118e27*/
          }
        }
        else
        {
          v4 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v18 + 28) + 28))(v18, 128, *(_DWORD *)(active_u + 28)); /*0x118e42*/
          v5 = v4; /*0x118e44*/
          if ( v4 ) /*0x118e4b*/
          {
            vn_rele(v18); /*0x118e51*/
            result = dword_1E875C; /*0x118e56*/
            *(_BYTE *)(dword_1E875C + 104) = v5; /*0x118e5b*/
            return result; /*0x118e5e*/
          }
        }
LABEL_24:
        if ( (*(_BYTE *)(v0 + 8) & 0x14) != 0 )
        {
          *(_BYTE *)(dword_1E875C + 104) = pn_get(*(_DWORD *)v0, 0, v20); /*0x118ed7*/
          if ( !*(_BYTE *)(dword_1E875C + 104) )
          {
            for ( i = &vfssw; vfsNVFS > (char *)i; i += 2 ) /*0x118ef7*/
            {
              if ( *i && !strcmp(__s1, *i) ) /*0x118f07*/
                break; /*0x118f11*/
            }
            if ( vfsNVFS == (char *)i ) /*0x118f24*/
            {
              *(_BYTE *)(dword_1E875C + 104) = 19; /*0x118f2b*/
              vn_rele(v18); /*0x118f33*/
              return pn_free(v20); /*0x118f41*/
            }
            pn_free(v20); /*0x118f4c*/
LABEL_36:
            v17 = 0; /*0x118f84*/
            if ( (*(_BYTE *)(v0 + 8) & 0x10) != 0 )
            {
              v8 = rootvfs; /*0x118f95*/
              if ( !rootvfs ) /*0x118f9d*/
                goto LABEL_43; /*0x118f9d*/
              do /*0x118fbc*/
              {
                if ( *(_DWORD *)(v18 + 36) == v8 && (*(_BYTE *)(v18 + 4) & 1) != 0 && !*(_DWORD *)(v18 + 12) ) /*0x118fb2*/
                  break; /*0x118fb6*/
                v8 = *(_DWORD *)v8; /*0x118fb8*/
              }
              while ( v8 ); /*0x118fbc*/
              if ( !v8 ) /*0x118fc0*/
              {
LABEL_43:
                *(_BYTE *)(dword_1E875C + 104) = 2; /*0x118fc7*/
                return vn_rele(v18); /*0x118fcb*/
              }
              *(_BYTE *)(dword_1E875C + 104) = vfs_lock(v8); /*0x118fdd*/
              if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x118fe8*/
                return vn_rele(v18); /*0x118fec*/
              *(_BYTE *)(dword_1E875C + 104) = pn_get(*(_DWORD *)(v0 + 4), 0, v20); /*0x119008*/
              if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x119013*/
              {
                vn_rele(v18); /*0x11901d*/
                return vfs_unlock(v8); /*0x119028*/
              }
              if ( (*(_BYTE *)(v0 + 8) & 1) != 0 )
              {
                printf("mount: can't remount ro\n");
                *(_BYTE *)(dword_1E875C + 104) = 22; /*0x119045*/
                vfs_unlock(v8); /*0x11904a*/
                vn_rele(v18); /*0x119053*/
                return pn_free(v20); /*0x11905e*/
              }
              v16 = *(_DWORD *)(v8 + 12); /*0x119067*/
              v9 = v16; /*0x11906a*/
              LOBYTE(v9) = v16 & 0xBE | 0x40; /*0x11906e*/
              *(_DWORD *)(v8 + 12) = v9; /*0x119070*/
            }
            else
            {
              v16 = 0; /*0x119078*/
              *(_BYTE *)(dword_1E875C + 104) = pn_get(*(_DWORD *)(v0 + 4), 0, v20); /*0x119095*/
              if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x1190a0*/
                return vn_rele(v18); /*0x1190a4*/
              v8 = kalloc(0x12Cu); /*0x1190b4*/
              *(_DWORD *)v8 = 0; /*0x1190b6*/
              *(_DWORD *)(v8 + 4) = i[1]; /*0x1190bf*/
              *(_DWORD *)(v8 + 12) = 0; /*0x1190c2*/
              *(_DWORD *)(v8 + 28) = 0; /*0x1190c9*/
              *(_DWORD *)(v8 + 296) = 0; /*0x1190d0*/
              *(_DWORD *)(v8 + 288) = 0; /*0x1190da*/
              *(_WORD *)(v8 + 292) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x1190f0*/
              if ( *(__int16 *)(v0 + 8) >= 0 ) /*0x1190ff*/
              {
                strncpy((char *)(v8 + 32), __s1, 0xFFu); /*0x11913d*/
                v12 = v18; /*0x119142*/
                if ( *(_UNKNOWN **)(v18 + 28) == &ufs_vnodeops ) /*0x11914f*/
                {
                  while ( (*(_BYTE *)(*(_DWORD *)(v12 + 48) + 68) & 1) != 0 ) /*0x119173*/
                  {
                    *(_BYTE *)(*(_DWORD *)(v12 + 48) + 68) |= 0x10u; /*0x119157*/
                    sleep(*(_DWORD *)(v12 + 48)); /*0x119161*/
                    v12 = v18; /*0x119169*/
                  }
                  *(_BYTE *)(*(_DWORD *)(v18 + 48) + 68) |= 1u; /*0x11917b*/
                  v17 = 1; /*0x11917f*/
                }
              }
              else
              {
                for ( j = __s1; ; j = v11 + 1 ) /*0x119101*/
                {
                  v11 = index(j, 47); /*0x119109*/
                  if ( !v11 ) /*0x119113*/
                    break; /*0x119113*/
                }
                strncpy((char *)(v8 + 32), j, 0xFFu); /*0x119126*/
              }
              if ( v8 != -32 && !strncmp((const char *)(v8 + 32), _s2, 0xFu) ) /*0x119195*/
                *(_DWORD *)(v8 + 12) |= 0x100u; /*0x1191a1*/
              if ( *(_WORD *)(v8 + 292) ) /*0x1191a8*/
                *(_BYTE *)(v0 + 8) |= 2u; /*0x1191b2*/
              *(_BYTE *)(dword_1E875C + 104) = vfs_add(v18, v8, *(_DWORD *)(v0 + 8)); /*0x1191cb*/
            }
            if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1191d6*/
              *(_BYTE *)(dword_1E875C + 104) = (**(int (__cdecl ***)(int, char *, _DWORD))(v8 + 4))( /*0x1191f3*/
                                                 v8,
                                                 __s1,
                                                 *(_DWORD *)(v0 + 12));
            if ( v17 ) /*0x1191fd*/
            {
              v13 = v18; /*0x1191ff*/
              *(_BYTE *)(*(_DWORD *)(v18 + 48) + 68) &= ~1u; /*0x119205*/
              v14 = *(_DWORD *)(v13 + 48); /*0x119209*/
              v15 = *(_WORD *)(v14 + 68); /*0x11920c*/
              if ( (v15 & 0x10) != 0 ) /*0x119212*/
              {
                LOBYTE(v15) = v15 & 0xEF; /*0x119214*/
                *(_WORD *)(v14 + 68) = v15; /*0x119216*/
                wakeup(*(_DWORD *)(v13 + 48)); /*0x11921e*/
              }
            }
            pn_free(v20); /*0x11922a*/
            if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x119237*/
            {
              if ( (*(_BYTE *)(v0 + 8) & 0x10) != 0 ) /*0x119258*/
              {
                *(_DWORD *)(v8 + 12) = v16; /*0x11925d*/
                vfs_unlock(v8); /*0x119261*/
              }
              else
              {
                vfs_remove(v8); /*0x11926d*/
                kfree(v8, 300); /*0x119278*/
              }
            }
            else
            {
              result = vfs_unlock(v8); /*0x11923e*/
              if ( (*(_BYTE *)(v0 + 8) & 0x10) == 0 ) /*0x11924a*/
                return result; /*0x11924a*/
              *(_DWORD *)(v8 + 12) &= ~0x40u; /*0x11924c*/
            }
          }
        }
        else
        {
          if ( *(_DWORD *)v0 <= 4u ) /*0x118f5d*/
          {
            i = &(&vfssw)[2 * dword_1DB450[*(_DWORD *)v0]]; /*0x118f69*/
            if ( i[1] ) /*0x118f6f*/
              goto LABEL_36; /*0x118f73*/
          }
          *(_BYTE *)(dword_1E875C + 104) = 19; /*0x118f7a*/
        }
        return vn_rele(v18); /*0x119284*/
      }
      goto LABEL_22; /*0x118dc9*/
    }
    v6 = *(_DWORD *)(v0 + 8); /*0x118e64*/
    if ( (v6 & 0x10) == 0 ) /*0x118e6a*/
    {
      v3 = v19; /*0x118e88*/
      if ( (*(_BYTE *)(*(_DWORD *)(v19 + 36) + 12) & 0x20) == 0 ) /*0x118e92*/
      {
        BYTE1(v6) |= 0x80u; /*0x118ea8*/
        *(_DWORD *)(v0 + 8) = v6; /*0x118eab*/
        v18 = v3; /*0x118eae*/
        v19 = 0; /*0x118eb1*/
        goto LABEL_24; /*0x118eb1*/
      }
LABEL_22:
      vn_rele(v3); /*0x118e94*/
      result = dword_1E875C; /*0x118e9a*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x118e9f*/
      return result; /*0x118ea3*/
    }
    if ( v19 ) /*0x118e71*/
      vn_rele(v19); /*0x118e74*/
    result = dword_1E875C; /*0x118e79*/
    *(_BYTE *)(dword_1E875C + 104) = 2; /*0x118e7e*/
  }
  return result; /*0x11928c*/
}
