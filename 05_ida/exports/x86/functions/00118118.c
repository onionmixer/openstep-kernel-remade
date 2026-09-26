/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118118. */
int __cdecl uipc_usrreq(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  size_t v10; // eax
  int v11; // eax
  int *v12; // eax
  int v13; // ebx
  unsigned __int16 *v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int *v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Ch] [ebp-8h] BYREF

  v5 = *(_DWORD *)(a1 + 8); /*0x118127*/
  v23 = 0; /*0x11812a*/
  if ( a2 == 11 ) /*0x118134*/
    return 45; /*0x11813b*/
  if ( a2 != 9 && a5 && *(_WORD *)(a5 + 8) ) /*0x11814e*/
  {
LABEL_6:
    v23 = 45; /*0x118155*/
  }
  else
  {
    if ( v5 || !a2 ) /*0x11816a*/
    {
      switch ( a2 ) /*0x118179*/
      {
        case 0: /*0x118179*/
          if ( v5 ) /*0x1181d2*/
            goto LABEL_36; /*0x1181d2*/
          v23 = unp_attach(a1); /*0x1181de*/
          goto LABEL_73; /*0x1181e1*/
        case 1: /*0x118179*/
          unp_detach(v5); /*0x1181e9*/
          goto LABEL_73; /*0x1181ee*/
        case 2: /*0x118179*/
          v7 = unp_bind(v5, a4); /*0x1181f9*/
          goto LABEL_18; /*0x1181fe*/
        case 3: /*0x118179*/
          if ( !*(_DWORD *)(v5 + 4) ) /*0x118200*/
            break; /*0x118204*/
          goto LABEL_73; /*0x118204*/
        case 4: /*0x118179*/
          v7 = unp_connect(a1, a4); /*0x11821d*/
          goto LABEL_18; /*0x118222*/
        case 5: /*0x118179*/
          v8 = *(_DWORD *)(v5 + 12); /*0x118248*/
          if ( v8 && (v9 = *(_DWORD *)(v8 + 24)) != 0 ) /*0x118254*/
          {
            *(_WORD *)(a4 + 8) = *(_WORD *)(v9 + 8); /*0x11825d*/
            v10 = *(__int16 *)(a4 + 8); /*0x118261*/
LABEL_71:
            bcopy( /*0x1185ad*/
              (const void *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 12) + 24) + 4)
                           + *(_DWORD *)(*(_DWORD *)(v5 + 12) + 24)),
              (void *)(*(_DWORD *)(a4 + 4) + a4),
              v10);
          }
          else
          {
            *(_WORD *)(a4 + 8) = 16; /*0x11826f*/
            v11 = *(_DWORD *)(a4 + 4); /*0x118275*/
            *(_DWORD *)(v11 + a4) = sun_noname; /*0x11827e*/
            *(_DWORD *)(v11 + a4 + 4) = dword_1DB3A8; /*0x118287*/
            *(_DWORD *)(v11 + a4 + 8) = dword_1DB3AC; /*0x118291*/
            *(_DWORD *)(v11 + a4 + 12) = dword_1DB3B0; /*0x11829b*/
          }
          goto LABEL_73; /*0x1185c7*/
        case 6: /*0x118179*/
          goto LABEL_51;
        case 7: /*0x118179*/
          socantsendmore(a1); /*0x1182a5*/
          unp_usrclosed(v5); /*0x1182ab*/
          goto LABEL_73; /*0x1182b3*/
        case 8: /*0x118179*/
          if ( *(_WORD *)a1 != 1 ) /*0x1182bf*/
          {
            if ( *(_WORD *)a1 == 2 ) /*0x1182c5*/
              panic(aUipc1); /*0x1182cc*/
            panic(aUipc2); /*0x118321*/
          }
          v12 = *(int **)(v5 + 12); /*0x1182d4*/
          if ( v12 ) /*0x1182d9*/
          {
            v13 = *v12; /*0x1182df*/
            *(_WORD *)(v13 + 66) += *(_WORD *)(v5 + 32) - *(_WORD *)(a1 + 40); /*0x1182e9*/
            *(_DWORD *)(v5 + 32) = *(unsigned __int16 *)(a1 + 40); /*0x1182f1*/
            *(_WORD *)(v13 + 62) += *(_WORD *)(v5 + 28) - *(_WORD *)(a1 + 36); /*0x1182fc*/
            *(_DWORD *)(v5 + 28) = *(unsigned __int16 *)(a1 + 36); /*0x118304*/
            sowakeup(v13, v13 + 60); /*0x11830c*/
          }
          goto LABEL_73; /*0x118314*/
        case 9: /*0x118179*/
          if ( a5 ) /*0x11832c*/
          {
            v23 = unp_internalize(a5); /*0x118337*/
            if ( v23 ) /*0x11833f*/
              goto LABEL_73; /*0x11833f*/
          }
          if ( *(_WORD *)a1 == 1 ) /*0x11834c*/
          {
            if ( (*(_BYTE *)(a1 + 6) & 0x10) != 0 ) /*0x118430*/
            {
              v23 = 32; /*0x118432*/
            }
            else
            {
              if ( !*(_DWORD *)(v5 + 12) ) /*0x118440*/
                panic(aUipc3); /*0x11844b*/
              v17 = **(_DWORD **)(v5 + 12); /*0x118456*/
              if ( a5 ) /*0x11845c*/
                sbappendrights((unsigned __int16 *)(v17 + 36), (int **)a3, a5); /*0x11846a*/
              else
                sbappend(v17 + 36, a3); /*0x11847c*/
              *(_WORD *)(a1 + 66) -= *(_WORD *)(v17 + 40) - *(_WORD *)(*(_DWORD *)(v5 + 12) + 32); /*0x118491*/
              *(_DWORD *)(*(_DWORD *)(v5 + 12) + 32) = *(unsigned __int16 *)(v17 + 40); /*0x11849c*/
              *(_WORD *)(a1 + 62) -= *(_WORD *)(v17 + 36) - *(_WORD *)(*(_DWORD *)(v5 + 12) + 28); /*0x1184ac*/
              *(_DWORD *)(*(_DWORD *)(v5 + 12) + 28) = *(unsigned __int16 *)(v17 + 36); /*0x1184b7*/
              sowakeup(v17, v17 + 36); /*0x1184bf*/
              a3 = 0; /*0x1184c4*/
            }
            goto LABEL_73; /*0x118439*/
          }
          if ( *(_WORD *)a1 != 2 ) /*0x118356*/
            panic(aUipc4); /*0x1184d9*/
          if ( a4 ) /*0x118360*/
          {
            if ( *(_DWORD *)(v5 + 12) ) /*0x118362*/
            {
LABEL_36:
              v23 = 56; /*0x118368*/
              goto LABEL_73; /*0x11836f*/
            }
            v23 = unp_connect(a1, a4); /*0x11837e*/
            if ( v23 ) /*0x118386*/
              goto LABEL_73; /*0x118386*/
          }
          else if ( !*(_DWORD *)(v5 + 12) ) /*0x118390*/
          {
            v23 = 57; /*0x118396*/
            goto LABEL_73; /*0x11839d*/
          }
          v14 = **(unsigned __int16 ***)(v5 + 12); /*0x1183a7*/
          v15 = *(_DWORD *)(v5 + 24); /*0x1183a9*/
          if ( v15 ) /*0x1183ae*/
            v22 = (int *)(*(_DWORD *)(v15 + 4) + v15); /*0x1183b3*/
          else
            v22 = &sun_noname; /*0x1183b8*/
          v16 = v14[19] - v14[18]; /*0x1183d5*/
          if ( v16 > v14[21] - v14[20] ) /*0x1183d9*/
            v16 = v14[21] - v14[20]; /*0x1183db*/
          if ( v16 > 0 && sbappendaddr(v14 + 18, v22, (int **)a3, a5) ) /*0x1183f1*/
          {
            sowakeup((int)v14, (int)(v14 + 18)); /*0x1183ff*/
            a3 = 0; /*0x118404*/
          }
          else
          {
            v23 = 55; /*0x118410*/
          }
          if ( a4 ) /*0x11841b*/
LABEL_51:
            unp_disconnect(v5); /*0x118421*/
          goto LABEL_73; /*0x118427*/
        case 10: /*0x118179*/
          unp_drop(v5, 53); /*0x1184e3*/
          goto LABEL_73; /*0x1184eb*/
        case 12: /*0x118179*/
          v18 = *(unsigned __int16 *)(a1 + 62); /*0x1184f0*/
          *(_DWORD *)(a3 + 48) = v18; /*0x1184fa*/
          if ( *(_WORD *)a1 == 1 ) /*0x118501*/
          {
            v19 = *(_DWORD *)(v5 + 12); /*0x118503*/
            if ( v19 ) /*0x118508*/
              *(_DWORD *)(a3 + 48) = v18 + *(unsigned __int16 *)(*(_DWORD *)v19 + 36); /*0x118512*/
          }
          *(_WORD *)a3 = -1; /*0x118518*/
          if ( !*(_DWORD *)(v5 + 8) ) /*0x11851d*/
            *(_DWORD *)(v5 + 8) = unp_vno++; /*0x118529*/
          *(_DWORD *)(a3 + 4) = *(_DWORD *)(v5 + 8); /*0x118538*/
          *(_WORD *)(a3 + 8) = 4534; /*0x11853b*/
          *(_WORD *)(a3 + 10) = 1; /*0x118541*/
          *(_WORD *)(a3 + 12) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x118553*/
          *(_WORD *)(a3 + 14) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 4); /*0x118563*/
          *(_DWORD *)(a3 + 20) = *(unsigned __int16 *)(a1 + 36); /*0x11856b*/
          getthetime(&v24); /*0x118572*/
          *(_DWORD *)(a3 + 24) = v24; /*0x11857d*/
          *(_DWORD *)(a3 + 32) = v24; /*0x118583*/
          *(_DWORD *)(a3 + 40) = v24; /*0x118589*/
          return 0; /*0x11858e*/
        case 13: /*0x118179*/
          return 45;
        case 14: /*0x118179*/
          goto LABEL_6;
        case 15: /*0x118179*/
        case 19: /*0x118179*/
          goto LABEL_73;
        case 16: /*0x118179*/
          v20 = *(_DWORD *)(v5 + 12); /*0x118590*/
          if ( !v20 ) /*0x118595*/
            goto LABEL_73; /*0x118595*/
          v21 = *(_DWORD *)(v20 + 24); /*0x118597*/
          if ( !v21 ) /*0x11859c*/
            goto LABEL_73; /*0x11859c*/
          *(_WORD *)(a4 + 8) = *(_WORD *)(v21 + 8); /*0x1185a5*/
          v10 = *(__int16 *)(a4 + 8); /*0x1185a9*/
          goto LABEL_71; /*0x1185a9*/
        case 17: /*0x118179*/
          v7 = unp_connect2(a1, a4); /*0x118229*/
LABEL_18:
          v23 = v7; /*0x11822e*/
          goto LABEL_73; /*0x118234*/
        default:
          panic(aPiusrreq); /*0x1185d1*/
          return result; /*0x1185d1*/
      }
    }
    v23 = 22; /*0x11820a*/
  }
LABEL_73:
  if ( a3 ) /*0x1185dd*/
    m_freem(a3); /*0x1185e3*/
  return v23; /*0x1185ee*/
}
