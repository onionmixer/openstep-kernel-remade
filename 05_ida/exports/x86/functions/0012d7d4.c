/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12d7d4. */
void __cdecl sub_12D7D4(int a1, SVCXPRT *a2)
{
  char *v2; // eax
  unsigned int v3; // ebx
  signed __int32 *v4; // ecx
  signed __int32 v5; // edx
  _WORD *v6; // eax
  _WORD *v7; // edi
  unsigned int v8; // ebx
  signed __int32 *v9; // ecx
  signed __int32 v10; // edx
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  int (*v14)(); // eax
  char *v15; // [esp-Ch] [ebp-48h]
  char *v16; // [esp-Ch] [ebp-48h]
  char *v17; // [esp-Ch] [ebp-48h]
  int *v18; // [esp+Ch] [ebp-30h]
  int *v19; // [esp+Ch] [ebp-30h]
  int v20; // [esp+14h] [ebp-28h]
  int v21; // [esp+18h] [ebp-24h]
  _DWORD *v22; // [esp+1Ch] [ebp-20h]
  int v23; // [esp+20h] [ebp-1Ch]
  _WORD *v24; // [esp+24h] [ebp-18h]
  int v25; // [esp+28h] [ebp-14h]
  char *v26; // [esp+2Ch] [ebp-10h]
  char *v27; // [esp+30h] [ebp-Ch]
  _WORD *v28; // [esp+34h] [ebp-8h]
  unsigned int v29; // [esp+38h] [ebp-4h]

  v28 = nullptr; /*0x12d7dd*/
  v27 = nullptr; /*0x12d7e4*/
  v26 = nullptr; /*0x12d7eb*/
  v25 = 0; /*0x12d7f2*/
  v24 = nullptr; /*0x12d7f9*/
  v22 = nullptr; /*0x12d800*/
  ++svstat; /*0x12d807*/
  v23 = 0; /*0x12d80d*/
  v29 = *(_DWORD *)(a1 + 8); /*0x12d81a*/
  if ( v29 <= 0x11 )
  {
    if ( *(_DWORD *)(a1 + 4) == 2 )
    {
      v26 = (char *)&rfsdisptab + 24 * v29; /*0x12d899*/
      *(_BYTE *)(dword_1E875C + 104) = 0; /*0x12d8a1*/
      if ( !rfssize ) /*0x12d8ac*/
      {
        v18 = &nfs_portmon; /*0x12d8ae*/
        v20 = 0; /*0x12d8b5*/
        do /*0x12d917*/
        {
          v3 = v20 + 1949684; /*0x12d8bf*/
          if ( (unsigned int)v18 > v20 + 1949684 ) /*0x12d8c8*/
          {
            v4 = (signed __int32 *)(v20 + 1949700); /*0x12d8d0*/
            do /*0x12d900*/
            {
              v5 = rfssize; /*0x12d8d4*/
              if ( (int)rfssize < *(v4 - 2) ) /*0x12d8df*/
                v5 = *(v4 - 2); /*0x12d8e1*/
              rfssize = v5; /*0x12d8e3*/
              if ( v5 < *v4 ) /*0x12d8ed*/
                v5 = *v4; /*0x12d8ef*/
              rfssize = v5; /*0x12d8f1*/
              v4 += 6; /*0x12d8f7*/
              v3 += 24; /*0x12d8fa*/
            }
            while ( (unsigned int)v18 > v3 ); /*0x12d900*/
          }
          v18 += 108; /*0x12d902*/
          v20 += 432; /*0x12d909*/
        }
        while ( (int)v18 <= (int)&nfs_portmon ); /*0x12d917*/
      }
      v6 = (_WORD *)rfsfreesp; /*0x12d919*/
      if ( rfsfreesp ) /*0x12d920*/
        rfsfreesp = *(_DWORD *)rfsfreesp; /*0x12d924*/
      else
        v6 = (_WORD *)(kalloc(rfssize + 4) + 4); /*0x12d93a*/
      v28 = v6; /*0x12d940*/
      v7 = v6; /*0x12d94a*/
      bzero(v6, rfssize); /*0x12d94e*/
      if ( a2->xp_ops->xp_getargs(a2, *((_DWORD *)v26 + 1), v7) )
      {
        if ( v29
          && (v24 = crget(),
              v25 = *(_DWORD *)(active_u + 28),
              *(_DWORD *)(active_u + 28) = v24,
              (v22 = findexport(v28, v28 + 10)) != nullptr)
          && !sub_12DCD8(v22, a1, v24) )
        {
          svcerr_weakauth(a2); /*0x12d9e2*/
          v23 = 1; /*0x12d9e7*/
          v17 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12d9f9*/
          printf("nfs_server: weak authentication, source IP address=%s\n", v17);
        }
        else
        {
          if ( !rfssize ) /*0x12da13*/
          {
            v19 = &nfs_portmon; /*0x12da15*/
            v21 = 0; /*0x12da1c*/
            do /*0x12da7f*/
            {
              v8 = v21 + 1949684; /*0x12da27*/
              if ( (unsigned int)v19 > v21 + 1949684 ) /*0x12da30*/
              {
                v9 = (signed __int32 *)(v21 + 1949700); /*0x12da38*/
                do /*0x12da68*/
                {
                  v10 = rfssize; /*0x12da3c*/
                  if ( (int)rfssize < *(v9 - 2) ) /*0x12da47*/
                    v10 = *(v9 - 2); /*0x12da49*/
                  rfssize = v10; /*0x12da4b*/
                  if ( v10 < *v9 ) /*0x12da55*/
                    v10 = *v9; /*0x12da57*/
                  rfssize = v10; /*0x12da59*/
                  v9 += 6; /*0x12da5f*/
                  v8 += 24; /*0x12da62*/
                }
                while ( (unsigned int)v19 > v8 ); /*0x12da68*/
              }
              v19 += 108; /*0x12da6a*/
              v21 += 432; /*0x12da71*/
            }
            while ( (int)v19 <= (int)&nfs_portmon ); /*0x12da7f*/
          }
          v11 = (char *)rfsfreesp; /*0x12da81*/
          if ( rfsfreesp ) /*0x12da88*/
            rfsfreesp = *(_DWORD *)rfsfreesp; /*0x12da8c*/
          else
            v11 = (char *)(kalloc(rfssize + 4) + 4); /*0x12daa2*/
          v27 = v11; /*0x12daa8*/
          bzero(v11, rfssize); /*0x12dab6*/
          ++dword_1EEEA8[v29]; /*0x12dabe*/
          (*(void (__cdecl **)(_WORD *, char *, _DWORD *, int))v26)(v28, v27, v22, a1); /*0x12dada*/
        }
      }
      else
      {
        svcerr_decode(a2); /*0x12d96f*/
        v23 = 1; /*0x12d974*/
        v16 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12d986*/
        printf("nfs_server: bad getargs from %s\n", v16);
      }
    }
    else
    {
      svcerr_progvers(*(SVCXPRT **)(a1 + 28), 2u, 2u); /*0x12d861*/
      v23 = 1; /*0x12d866*/
      v2 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12d874*/
      printf("nfs_server: bad version number from %s\n", v2);
    }
  }
  else
  {
    svcerr_noproc(*(SVCXPRT **)(a1 + 28)); /*0x12d829*/
    v23 = 1; /*0x12d82e*/
    v15 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12d844*/
    printf("nfs_server: bad proc number from %s\n", v15);
  }
  if ( v26 && !a2->xp_ops->xp_freeargs(a2, *((_DWORD *)v26 + 1), v28) )
  {
    v12 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12db10*/
    printf("nfs_server: bad freeargs from %s\n", v12);
    ++v23; /*0x12db20*/
  }
  if ( v28 ) /*0x12db2a*/
  {
    *(_DWORD *)v28 = rfsfreesp; /*0x12db35*/
    rfsfreesp = (int)v28; /*0x12db37*/
  }
  if ( !v23 && !svc_sendreply(a2, *((xdrproc_t *)v26 + 3), v27) )
  {
    v13 = inet_ntoa((in_addr)(*(_DWORD *)(a1 + 28) + 20)); /*0x12db68*/
    printf("nfs_server: bad sendreply from %s\n", v13);
    v23 = 1; /*0x12db78*/
  }
  if ( v27 ) /*0x12db86*/
  {
    v14 = *((int (**)())v26 + 5); /*0x12db8b*/
    if ( v14 != sub_12EA30 ) /*0x12db93*/
      ((void (__cdecl *)(char *))v14)(v27); /*0x12db99*/
    *(_DWORD *)v27 = rfsfreesp; /*0x12dba7*/
    rfsfreesp = (int)v27; /*0x12dba9*/
  }
  if ( v24 ) /*0x12dbb3*/
  {
    *(_DWORD *)(active_u + 28) = v25; /*0x12dbbd*/
    crfree(v24); /*0x12dbc4*/
  }
  dword_1EEEA4 += v23; /*0x12dbcc*/
}
