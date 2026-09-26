/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12eef4. */
int __cdecl rfscall(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _WORD *a7)
{
  int *v7; // eax
  int *v8; // edi
  int v9; // ebx
  int v10; // ecx
  char v11; // dl
  char *v12; // eax
  char *v13; // eax
  _DWORD *v14; // ebx
  __int16 *v15; // ecx
  unsigned int v16; // edx
  int **v17; // ecx
  int **v18; // edx
  char v19; // dl
  _DWORD *v20; // ebx
  __int16 *v21; // ecx
  unsigned int v22; // edx
  int **v23; // ecx
  int **v24; // edx
  clnt_stat v26; // [esp+Ch] [ebp-24h]
  int v27; // [esp+10h] [ebp-20h]
  int v28; // [esp+14h] [ebp-1Ch]
  _WORD *v29; // [esp+18h] [ebp-18h]
  int v30; // [esp+24h] [ebp-Ch]
  int v31; // [esp+28h] [ebp-8h]

  ++dword_1EEF88; /*0x12eefd*/
  ++dword_1EEF90[a2]; /*0x12ef06*/
  v31 = 0; /*0x12ef0d*/
  v30 = 0; /*0x12ef14*/
  v29 = nullptr; /*0x12ef1b*/
  v28 = *(_DWORD *)(a1 + 44) << word_1DC41C[a2]; /*0x12ef32*/
  v27 = 0; /*0x12ef35*/
LABEL_2:
  v7 = sub_12EA98(a1, (int)a7); /*0x12ef3c*/
  v8 = v7; /*0x12ef49*/
  if ( a2 == 9 ) /*0x12ef52*/
    clntkudp_once(v7, 1); /*0x12ef57*/
  while ( 2 )
  {
    v9 = 0; /*0x12ef60*/
    v26 = (*(int (__cdecl **)(int *, int, int, int, int, _DWORD *, int, int))v8[1])( /*0x12efa7*/
            v8,
            a2,
            a3,
            a4,
            a5,
            a6,
            v28 / 10,
            100000 * (v28 % 10));
    switch ( v26 )
    {
      case RPC_SUCCESS:
      case RPC_CANTENCODEARGS:
      case RPC_CANTDECODERES:
      case RPC_VERSMISMATCH:
      case RPC_AUTHERROR:
      case RPC_PROGVERSMISMATCH:
      case RPC_CANTDECODEARGS:
        goto LABEL_17;
      default:
        if ( v26 != (RPC_FAILED|RPC_CANTDECODERES) ) /*0x12eff0*/
        {
          v9 = *(_BYTE *)(a1 + 20) & 1; /*0x12f022*/
          goto LABEL_9; /*0x12f022*/
        }
        v9 = (*(_BYTE *)(a1 + 20) & 5) == 1; /*0x12f001*/
        if ( (*(_BYTE *)(a1 + 20) & 5) == 1 ) /*0x12f006*/
          continue; /*0x12f006*/
        v30 = 18; /*0x12f00c*/
        v31 = 4; /*0x12f013*/
LABEL_9:
        if ( v9 ) /*0x12f027*/
        {
          v10 = 300; /*0x12f033*/
          if ( 4 * v28 <= 300 ) /*0x12f03e*/
            v10 = 4 * v28; /*0x12f040*/
          v28 = v10; /*0x12f042*/
          v11 = *(_BYTE *)(a1 + 20); /*0x12f048*/
          if ( (v11 & 2) == 0 ) /*0x12f04e*/
          {
            *(_BYTE *)(a1 + 20) = v11 | 2; /*0x12f053*/
            printf("NFS server %s not responding still trying\n", (const char *)(a1 + 52)); /*0x12f062*/
          }
          if ( !v27 && *(_DWORD *)(active_u + 360) ) /*0x12f076*/
          {
            v27 = 1; /*0x12f07f*/
            uprintf("NFS server %s not responding still trying\n", (const char *)(a1 + 52)); /*0x12f092*/
          }
LABEL_17:
          if ( v9 ) /*0x12f09c*/
            continue; /*0x12f09c*/
        }
        clntkudp_once(v8, 0); /*0x12f0a5*/
        if ( v26 )
        {
          ++dword_1EEF8C; /*0x12f0b7*/
          *(_BYTE *)(a1 + 20) |= 8u; /*0x12f0c0*/
          if ( v26 != (RPC_FAILED|RPC_CANTDECODERES) )
          {
            v30 = v26; /*0x12f0d1*/
            v31 = 22; /*0x12f0d4*/
            v12 = clnt_sperrno(v26); /*0x12f0dc*/
            printf("NFS %s failed for server %s: %s\n", (&rfsnames)[a2], (const char *)(a1 + 52), v12);
            if ( *(_DWORD *)(active_u + 360) )
            {
              v13 = clnt_sperrno(v26); /*0x12f11a*/
              uprintf("NFS %s failed for server %s: %s\n", (&rfsnames)[a2], (const char *)(a1 + 52), v13);
            }
          }
          goto LABEL_45; /*0x12f13b*/
        }
        if ( a6 && *a6 == 13 && !v29 && !a7[1] && a7[3] )
        {
          v29 = crdup(a7); /*0x12f18b*/
          a7 = v29; /*0x12f18e*/
          v29[1] = v29[3]; /*0x12f198*/
          v14 = (_DWORD *)*v8; /*0x12f19f*/
          if ( *(_DWORD *)*v8 > 1u )
          {
            printf("authfree: unknown authflavor %d\n", *v14);
          }
          else
          {
            v15 = unixauthtab; /*0x12f1ac*/
            v16 = 8 * MAXCLIENTS + 2027840; /*0x12f1bd*/
            if ( (unsigned int)unixauthtab >= v16 ) /*0x12f1c5*/
            {
LABEL_32:
              (*(void (__cdecl **)(int))(v14[8] + 16))(*v8); /*0x12f1d4*/
            }
            else
            {
              while ( *((_DWORD **)v15 + 1) != v14 ) /*0x12f1cb*/
              {
                v15 += 4; /*0x12f1cd*/
                if ( (unsigned int)v15 >= v16 ) /*0x12f1d2*/
                  goto LABEL_32; /*0x12f1d2*/
              }
              *v15 = 0; /*0x12f1e4*/
            }
          }
          clntkudp_freecred(v8); /*0x12f1fd*/
          *v8 = 0; /*0x12f202*/
          v17 = (int **)&chtable; /*0x12f208*/
          v18 = (int **)((char *)&chtable + 12 * MAXCLIENTS); /*0x12f219*/
          if ( &chtable >= (_UNKNOWN *)v18 ) /*0x12f222*/
          {
LABEL_38:
            (*(void (__cdecl **)(int *))(v8[1] + 16))(v8); /*0x12f234*/
          }
          else
          {
            while ( v17[2] != v8 ) /*0x12f227*/
            {
              v17 += 3; /*0x12f22d*/
              if ( v17 >= v18 ) /*0x12f232*/
                goto LABEL_38; /*0x12f232*/
            }
            v17[1] = nullptr; /*0x12f140*/
          }
          goto LABEL_2; /*0x12f147*/
        }
        v19 = *(_BYTE *)(a1 + 20); /*0x12f24b*/
        if ( (v19 & 1) != 0 ) /*0x12f251*/
        {
          if ( (v19 & 2) != 0 ) /*0x12f256*/
          {
            printf("NFS server %s ok\n", (const char *)(a1 + 52)); /*0x12f263*/
            *(_BYTE *)(a1 + 20) &= ~2u; /*0x12f268*/
          }
          if ( v27 ) /*0x12f273*/
            uprintf("NFS server %s ok\n", (const char *)(a1 + 52)); /*0x12f281*/
        }
        else
        {
          *(_BYTE *)(a1 + 20) = v19 & 0xF7; /*0x12f292*/
        }
LABEL_45:
        v20 = (_DWORD *)*v8; /*0x12f295*/
        if ( *(_DWORD *)*v8 > 1u )
        {
          printf("authfree: unknown authflavor %d\n", *v20);
        }
        else
        {
          v21 = unixauthtab; /*0x12f2a2*/
          v22 = 8 * MAXCLIENTS + 2027840; /*0x12f2b4*/
          if ( (unsigned int)unixauthtab >= v22 ) /*0x12f2bc*/
          {
LABEL_49:
            (*(void (__cdecl **)(int))(v20[8] + 16))(*v8); /*0x12f2cc*/
          }
          else
          {
            while ( *((_DWORD **)v21 + 1) != v20 ) /*0x12f2c3*/
            {
              v21 += 4; /*0x12f2c5*/
              if ( (unsigned int)v21 >= v22 ) /*0x12f2ca*/
                goto LABEL_49; /*0x12f2ca*/
            }
            *v21 = 0; /*0x12f2dc*/
          }
        }
        clntkudp_freecred(v8); /*0x12f301*/
        *v8 = 0; /*0x12f306*/
        v23 = (int **)&chtable; /*0x12f30c*/
        v24 = (int **)((char *)&chtable + 12 * MAXCLIENTS); /*0x12f31d*/
        if ( &chtable >= (_UNKNOWN *)v24 ) /*0x12f326*/
        {
LABEL_56:
          (*(void (__cdecl **)(int *))(v8[1] + 16))(v8); /*0x12f334*/
        }
        else
        {
          while ( v23[2] != v8 ) /*0x12f32b*/
          {
            v23 += 3; /*0x12f32d*/
            if ( v23 >= v24 ) /*0x12f332*/
              goto LABEL_56; /*0x12f332*/
          }
          v23[1] = nullptr; /*0x12f2e4*/
        }
        if ( v29 ) /*0x12f344*/
          crfree(v29); /*0x12f34a*/
        if ( v30 && !v31 )
        {
          printf("rfscall:  re_status %d, re_errno 0\n", v30);
          panic(aRfscall); /*0x12f36f*/
        }
        return v31;
    }
  }
}
