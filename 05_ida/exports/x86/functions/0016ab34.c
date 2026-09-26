/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ab34. */
__int32 zone_free_space_reclaim()
{
  char *j; // ebx
  vm_size_t v1; // edi
  unsigned int v2; // edx
  int v3; // edx
  signed int v4; // esi
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  int v9; // eax
  int v10; // esi
  unsigned int v11; // eax
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // eax
  signed int v15; // eax
  int v16; // esi
  unsigned int v17; // eax
  char *v18; // eax
  __int32 result; // eax
  char *v20; // ebx
  signed int v21; // [esp+10h] [ebp-20h]
  char **v22; // [esp+14h] [ebp-1Ch]
  char *v23; // [esp+18h] [ebp-18h]
  char *v24; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int *v26; // [esp+24h] [ebp-Ch]
  char *v27; // [esp+28h] [ebp-8h]
  char **v28; // [esp+2Ch] [ebp-4h]

  v27 = nullptr; /*0x16ab3d*/
  v26 = &zone_free_space; /*0x16ab44*/
  for ( i = 1; zone_free_space_count > i; ++i ) /*0x16ab4b*/
  {
    v28 = (char **)(*++v26 + 8); /*0x16ab64*/
    for ( j = *v28; *v28; j = *v28 ) /*0x16ab67*/
    {
      v1 = *((_DWORD *)j + 1); /*0x16ab74*/
      if ( page_size > v1 /*0x16abbc*/
        || (v24 = (char *)(~page_mask & (unsigned int)&j[page_mask]),
            v2 = ~page_mask & (unsigned int)&j[v1],
            v23 = (char *)v2,
            (unsigned int)v24 >= v2)
        || zone_min > (unsigned int)v24
        || zone_max < v2 )
      {
        v28 = (char **)j; /*0x16ad4c*/
      }
      else
      {
        v3 = *v26; /*0x16abc5*/
        v4 = *(_DWORD *)(*v26 + 24); /*0x16abca*/
        v21 = v1 >> *(_DWORD *)(*v26 + 16); /*0x16abd4*/
        if ( v21 > v4 ) /*0x16abd9*/
          v21 = *(_DWORD *)(*v26 + 24); /*0x16abdb*/
        v22 = (char **)(*(_DWORD *)(v3 + 20) + 16 * v21 - 16); /*0x16abea*/
        if ( *v22 == j ) /*0x16abf0*/
        {
          if ( v21 >= v4 ) /*0x16abf5*/
          {
            v6 = *(char **)j; /*0x16ac14*/
            if ( *(_DWORD *)j ) /*0x16ac14*/
            {
              do /*0x16ac29*/
              {
                if ( *((_DWORD *)v6 + 1) >= *(_DWORD *)(v3 + 4) ) /*0x16ac23*/
                  break; /*0x16ac23*/
                v6 = *(char **)v6; /*0x16ac25*/
              }
              while ( v6 ); /*0x16ac29*/
            }
            *v22 = v6; /*0x16ac2e*/
          }
          else
          {
            v5 = *(char **)j; /*0x16abf7*/
            if ( *(_DWORD *)j ) /*0x16abf7*/
            {
              do /*0x16ac09*/
              {
                if ( *((_DWORD *)v5 + 1) == v1 ) /*0x16ac03*/
                  break; /*0x16ac03*/
                v5 = *(char **)v5; /*0x16ac05*/
              }
              while ( v5 ); /*0x16ac09*/
            }
            *v22 = v5; /*0x16ac0e*/
          }
        }
        v7 = &j[*((_DWORD *)j + 1)]; /*0x16ac32*/
        if ( v23 == v7 ) /*0x16ac38*/
        {
          if ( v24 == j ) /*0x16acdf*/
          {
            v18 = *(char **)j; /*0x16ad1c*/
            *v28 = *(char **)j; /*0x16ad21*/
            if ( v18 ) /*0x16ad25*/
              *(_DWORD *)(*(_DWORD *)j + 8) = v28; /*0x16ad29*/
            --*(_DWORD *)(*v26 + 12); /*0x16ad31*/
          }
          else
          {
            *((_DWORD *)j + 1) = v24 - j; /*0x16ace6*/
            v15 = (unsigned int)(v24 - j) >> *(_DWORD *)(*v26 + 16); /*0x16acf9*/
            if ( v15 > *(_DWORD *)(*v26 + 24) ) /*0x16acfd*/
              v15 = *(_DWORD *)(*v26 + 24); /*0x16acff*/
            v16 = 16 * v15 + *(_DWORD *)(*v26 + 20); /*0x16ad08*/
            v17 = *(_DWORD *)(v16 - 16); /*0x16ad0a*/
            if ( !v17 || (unsigned int)j < v17 ) /*0x16ad13*/
              *(_DWORD *)(v16 - 16) = j; /*0x16ad15*/
          }
        }
        else
        {
          *((_DWORD *)v23 + 1) = v7 - v23; /*0x16ac43*/
          v8 = *(char **)j; /*0x16ac46*/
          *(_DWORD *)v23 = *(_DWORD *)j; /*0x16ac48*/
          if ( v8 ) /*0x16ac4c*/
            *((_DWORD *)v8 + 2) = v23; /*0x16ac4e*/
          if ( v24 == j ) /*0x16ac54*/
          {
            *v28 = v23; /*0x16ac59*/
            *((_DWORD *)v23 + 2) = v28; /*0x16ac5b*/
          }
          else
          {
            *((_DWORD *)j + 1) = v24 - j; /*0x16ac65*/
            *(_DWORD *)j = v23; /*0x16ac68*/
            *((_DWORD *)v23 + 2) = j; /*0x16ac6a*/
            ++*(_DWORD *)(*v26 + 12); /*0x16ac72*/
            v9 = *((_DWORD *)j + 1) >> *(_DWORD *)(*v26 + 16); /*0x16ac87*/
            if ( *(_DWORD *)(*v26 + 24) < v9 ) /*0x16ac8c*/
              v9 = *(_DWORD *)(*v26 + 24); /*0x16ac8e*/
            v10 = 16 * v9 + *(_DWORD *)(*v26 + 20); /*0x16ac97*/
            v11 = *(_DWORD *)(v10 - 16); /*0x16ac99*/
            if ( !v11 || (unsigned int)j < v11 ) /*0x16aca2*/
              *(_DWORD *)(v10 - 16) = j; /*0x16aca4*/
          }
          v12 = *((_DWORD *)v23 + 1) >> *(_DWORD *)(*v26 + 16); /*0x16acb9*/
          if ( v12 > *(_DWORD *)(*v26 + 24) ) /*0x16acbd*/
            v12 = *(_DWORD *)(*v26 + 24); /*0x16acbf*/
          v13 = 16 * v12 + *(_DWORD *)(*v26 + 20); /*0x16acc7*/
          v14 = *(_DWORD *)(v13 - 16); /*0x16acc9*/
          if ( !v14 || (unsigned int)v23 < v14 ) /*0x16acd2*/
            *(_DWORD *)(v13 - 16) = v23; /*0x16acd4*/
        }
        *((_DWORD *)v24 + 1) = v23 - v24; /*0x16ad3c*/
        *(_DWORD *)v24 = v27; /*0x16ad42*/
        v27 = v24; /*0x16ad44*/
      }
    }
  }
  for ( result = _InterlockedExchange(&zget_space_lock, 0); ; result = kmem_free(zone_map, v20, *((_DWORD *)v20 + 1)) ) /*0x16ad70*/
  {
    v20 = v27; /*0x16ad91*/
    if ( !v27 ) /*0x16ad96*/
      break; /*0x16ad96*/
    v27 = *(char **)v27; /*0x16ad7a*/
  }
  return result; /*0x16ad9b*/
}
