/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a7f4. */
void __cdecl zone_collect(_DWORD *a1)
{
  int v1; // edi
  char *v2; // edx
  int v3; // eax
  int v4; // ebx
  unsigned int v5; // eax
  int *v6; // eax
  int v7; // eax
  signed int v8; // ebx
  int v9; // eax
  char *v10; // eax
  char *v11; // eax
  int v12; // edx
  unsigned int v13; // eax
  int *v14; // ebx
  int *v15; // eax
  int v16; // ebx
  signed int v17; // edx
  int *v18; // eax
  int *v19; // eax
  int v20; // eax
  int v21; // ebx
  signed int v22; // edx
  int *i; // eax
  int v24; // edx
  unsigned int v25; // eax
  int v26; // [esp+Ch] [ebp-38h]
  int *v27; // [esp+Ch] [ebp-38h]
  int v28; // [esp+Ch] [ebp-38h]
  int **v29; // [esp+10h] [ebp-34h]
  int ***v30; // [esp+14h] [ebp-30h]
  int **v31; // [esp+18h] [ebp-2Ch]
  unsigned int v32; // [esp+1Ch] [ebp-28h]
  unsigned int v33; // [esp+20h] [ebp-24h]
  char **v34; // [esp+24h] [ebp-20h]
  int v35; // [esp+28h] [ebp-1Ch]
  unsigned int v36; // [esp+2Ch] [ebp-18h]
  int v37; // [esp+30h] [ebp-14h]
  char *v38; // [esp+34h] [ebp-10h]
  char *v39; // [esp+3Ch] [ebp-8h]
  int ***v40; // [esp+40h] [ebp-4h]

  v37 = a1[7]; /*0x16a803*/
  v1 = a1[15]; /*0x16a809*/
  if ( v1 && (_UNKNOWN *)v1 != &_zone_default_space ) /*0x16a81a*/
  {
    v40 = (int ***)(v1 + 8); /*0x16a823*/
    v2 = (char *)a1[4]; /*0x16a82f*/
    if ( v2 ) /*0x16a834*/
    {
      do /*0x16ab1a*/
      {
        a1[5] -= v37; /*0x16a842*/
        v38 = *(char **)v2; /*0x16a847*/
        v29 = *v40; /*0x16a84f*/
        if ( !*v40 ) /*0x16a84f*/
          goto LABEL_9; /*0x16a84f*/
        do /*0x16a86f*/
        {
          if ( (char *)v29 + (int)v29[1] >= v2 ) /*0x16a860*/
            break; /*0x16a860*/
          v40 = (int ***)v29; /*0x16a865*/
          v29 = (int **)*v29; /*0x16a86a*/
        }
        while ( v29 ); /*0x16a86f*/
        if ( v29 && v29 <= (int **)&v2[v37] ) /*0x16a87f*/
        {
          if ( v29 == (int **)&v2[v37] ) /*0x16a8d7*/
          {
            v36 = (unsigned int)v29[1]; /*0x16a8e3*/
            v39 = v2; /*0x16a8e6*/
            *((_DWORD *)v2 + 1) = v37 + v36; /*0x16a8ec*/
            v6 = *v29; /*0x16a8f2*/
            *(_DWORD *)v2 = *v29; /*0x16a8f4*/
            if ( v6 ) /*0x16a8f8*/
              v6[2] = (int)v2; /*0x16a8fa*/
            *((_DWORD *)v2 + 2) = v40; /*0x16a900*/
            *v40 = (int **)v2; /*0x16a903*/
            v7 = *(_DWORD *)(v1 + 16); /*0x16a905*/
            v26 = *(_DWORD *)(v1 + 24); /*0x16a90b*/
            v35 = *((_DWORD *)v2 + 1) >> v7; /*0x16a915*/
            if ( v35 > v26 ) /*0x16a91d*/
              v35 = *(_DWORD *)(v1 + 24); /*0x16a91f*/
            v8 = v36 >> v7; /*0x16a927*/
            if ( v26 < (int)(v36 >> v7) ) /*0x16a92c*/
              v8 = *(_DWORD *)(v1 + 24); /*0x16a92e*/
            v9 = *(_DWORD *)(v1 + 20) + 16 * v8; /*0x16a936*/
            v34 = (char **)(v9 - 16); /*0x16a93c*/
            if ( v35 == v8 ) /*0x16a942*/
            {
              if ( *(int ***)(v9 - 16) == v29 ) /*0x16a9ba*/
                *(_DWORD *)(v9 - 16) = v2; /*0x16a9c0*/
            }
            else
            {
              if ( *(int ***)(v9 - 16) == v29 ) /*0x16a94a*/
              {
                if ( v26 <= v8 ) /*0x16a94f*/
                {
                  v11 = *(char **)v2; /*0x16a970*/
                  if ( *(_DWORD *)v2 ) /*0x16a970*/
                  {
                    do /*0x16a985*/
                    {
                      if ( *((_DWORD *)v11 + 1) >= *(_DWORD *)(v1 + 4) ) /*0x16a97f*/
                        break; /*0x16a97f*/
                      v11 = *(char **)v11; /*0x16a981*/
                    }
                    while ( v11 ); /*0x16a985*/
                  }
                  *v34 = v11; /*0x16a98a*/
                }
                else
                {
                  v10 = *(char **)v2; /*0x16a951*/
                  if ( *(_DWORD *)v2 ) /*0x16a951*/
                  {
                    do /*0x16a964*/
                    {
                      if ( *((_DWORD *)v10 + 1) == v36 ) /*0x16a95e*/
                        break; /*0x16a95e*/
                      v10 = *(char **)v10; /*0x16a960*/
                    }
                    while ( v10 ); /*0x16a964*/
                  }
                  *v34 = v10; /*0x16a969*/
                }
              }
              v12 = 16 * v35 + *(_DWORD *)(v1 + 20); /*0x16a995*/
              v13 = *(_DWORD *)(v12 - 16); /*0x16a997*/
              if ( !v13 || (unsigned int)v39 < v13 ) /*0x16a9a1*/
                *(_DWORD *)(v12 - 16) = v39; /*0x16a9aa*/
            }
          }
          else
          {
            v14 = v29[1]; /*0x16a9cb*/
            if ( (char *)v29 + (_DWORD)v14 == v2 ) /*0x16a9d4*/
            {
              v33 = (unsigned int)v29[1]; /*0x16a9da*/
              v29[1] = (int *)((char *)v14 + v37); /*0x16a9e2*/
              v15 = (int *)((char *)v14 + v37 + (_DWORD)v29); /*0x16a9e5*/
              v27 = v15; /*0x16a9e7*/
              if ( *v29 == v15 ) /*0x16a9ec*/
              {
                v32 = v15[1]; /*0x16a9f5*/
                v16 = *(_DWORD *)(v1 + 24); /*0x16a9fb*/
                v17 = v32 >> *(_DWORD *)(v1 + 16); /*0x16aa02*/
                if ( v17 > v16 ) /*0x16aa06*/
                  v17 = *(_DWORD *)(v1 + 24); /*0x16aa08*/
                v31 = (int **)(*(_DWORD *)(v1 + 20) + 16 * v17 - 16); /*0x16aa15*/
                if ( *v31 == v15 ) /*0x16aa1e*/
                {
                  if ( v17 >= v16 ) /*0x16aa22*/
                  {
                    v18 = (int *)*v15; /*0x16aa43*/
                    if ( *v27 ) /*0x16aa43*/
                    {
                      do /*0x16aa55*/
                      {
                        if ( (unsigned int)v18[1] >= *(_DWORD *)(v1 + 4) ) /*0x16aa4f*/
                          break; /*0x16aa4f*/
                        v18 = (int *)*v18; /*0x16aa51*/
                      }
                      while ( v18 ); /*0x16aa55*/
                    }
                  }
                  else
                  {
                    v18 = (int *)*v15; /*0x16aa24*/
                    if ( *v27 ) /*0x16aa24*/
                    {
                      do /*0x16aa39*/
                      {
                        if ( v18[1] == v32 ) /*0x16aa33*/
                          break; /*0x16aa33*/
                        v18 = (int *)*v18; /*0x16aa35*/
                      }
                      while ( v18 ); /*0x16aa39*/
                    }
                  }
                  *v31 = v18; /*0x16aa5a*/
                }
                v29[1] = (int *)((char *)v29[1] + (*v29)[1]); /*0x16aa64*/
                v19 = (int *)**v29; /*0x16aa69*/
                *v29 = v19; /*0x16aa6b*/
                if ( v19 ) /*0x16aa6f*/
                  v19[2] = (int)v29; /*0x16aa71*/
                --*(_DWORD *)(v1 + 12); /*0x16aa74*/
              }
              v20 = *(_DWORD *)(v1 + 16); /*0x16aa77*/
              v21 = *(_DWORD *)(v1 + 24); /*0x16aa7a*/
              v28 = (unsigned int)v29[1] >> v20; /*0x16aa87*/
              if ( v28 > v21 ) /*0x16aa8c*/
                v28 = *(_DWORD *)(v1 + 24); /*0x16aa8e*/
              v22 = v33 >> v20; /*0x16aa96*/
              if ( (int)(v33 >> v20) > v21 ) /*0x16aa9a*/
                v22 = *(_DWORD *)(v1 + 24); /*0x16aa9c*/
              if ( v28 != v22 ) /*0x16aaa1*/
              {
                v30 = (int ***)(*(_DWORD *)(v1 + 20) + 16 * v22 - 16); /*0x16aaae*/
                if ( *v30 == v29 ) /*0x16aab7*/
                {
                  if ( v22 >= v21 ) /*0x16aabb*/
                  {
                    for ( i = *v29; i; i = (int *)*i ) /*0x16aad7*/
                    {
                      if ( (unsigned int)i[1] >= *(_DWORD *)(v1 + 4) ) /*0x16aae3*/
                        break; /*0x16aae3*/
                    }
                  }
                  else
                  {
                    for ( i = *v29; i; i = (int *)*i ) /*0x16aabd*/
                    {
                      if ( i[1] == v33 ) /*0x16aaca*/
                        break; /*0x16aaca*/
                    }
                  }
                  *v30 = (int **)i; /*0x16aaee*/
                }
                v24 = 16 * v28 + *(_DWORD *)(v1 + 20); /*0x16aaf9*/
                v25 = *(_DWORD *)(v24 - 16); /*0x16aafb*/
                if ( !v25 || (unsigned int)v29 < v25 ) /*0x16ab05*/
                  *(_DWORD *)(v24 - 16) = v29; /*0x16ab0a*/
              }
            }
          }
        }
        else
        {
LABEL_9:
          *((_DWORD *)v2 + 1) = v37; /*0x16a884*/
          *(_DWORD *)v2 = v29; /*0x16a88a*/
          if ( v29 ) /*0x16a88e*/
            v29[2] = (int *)v2; /*0x16a890*/
          *((_DWORD *)v2 + 2) = v40; /*0x16a896*/
          *v40 = (int **)v2; /*0x16a899*/
          ++*(_DWORD *)(v1 + 12); /*0x16a89b*/
          v3 = *((_DWORD *)v2 + 1) >> *(_DWORD *)(v1 + 16); /*0x16a8ab*/
          if ( v3 > *(_DWORD *)(v1 + 24) ) /*0x16a8af*/
            v3 = *(_DWORD *)(v1 + 24); /*0x16a8b1*/
          v4 = 16 * v3 + *(_DWORD *)(v1 + 20); /*0x16a8b9*/
          v5 = *(_DWORD *)(v4 - 16); /*0x16a8bb*/
          if ( !v5 || (unsigned int)v2 < v5 ) /*0x16a8c4*/
            *(_DWORD *)(v4 - 16) = v2; /*0x16a8ca*/
        }
        a1[4] = v38; /*0x16ab13*/
        v2 = v38; /*0x16ab15*/
      }
      while ( v38 ); /*0x16ab1a*/
    }
    a1[3] = 0; /*0x16ab23*/
  }
}
