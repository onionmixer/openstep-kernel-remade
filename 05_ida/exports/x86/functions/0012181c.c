/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12181c. */
int __cdecl raw_usrreq(int a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // ebx
  int v6; // esi
  int result; // eax
  int v8; // eax

  v5 = *(_BYTE **)(a1 + 8); /*0x12182e*/
  v6 = 0; /*0x121831*/
  if ( a2 == 11 ) /*0x121836*/
    return 45; /*0x121838*/
  if ( a5 && *(_WORD *)(a5 + 8) ) /*0x121848*/
  {
LABEL_5:
    v6 = 45; /*0x12184f*/
  }
  else if ( !v5 && a2 ) /*0x121862*/
  {
LABEL_18:
    v6 = 22; /*0x12191e*/
  }
  else
  {
    switch ( a2 ) /*0x121871*/
    {
      case 0: /*0x121871*/
        if ( *(char *)(a1 + 6) >= 0 ) /*0x1218c7*/
        {
          v6 = 13; /*0x1218c9*/
          break; /*0x1218ce*/
        }
        if ( v5 ) /*0x1218d6*/
          goto LABEL_18; /*0x1218d6*/
        v8 = raw_attach(a1, a4); /*0x1218dd*/
LABEL_20:
        v6 = v8; /*0x121932*/
        break; /*0x121937*/
      case 1: /*0x121871*/
        if ( !v5 ) /*0x1218e6*/
          goto LABEL_29; /*0x1218e6*/
        raw_detach(*(_DWORD *)(a1 + 8)); /*0x1218ed*/
        break; /*0x1218f2*/
      case 2: /*0x121871*/
        if ( (v5[76] & 1) != 0 ) /*0x12191c*/
          goto LABEL_18; /*0x12191c*/
        v8 = raw_bind(a1, a4); /*0x12192d*/
        goto LABEL_20; /*0x12192d*/
      case 3: /*0x121871*/
      case 5: /*0x121871*/
      case 14: /*0x121871*/
      case 17: /*0x121871*/
        goto LABEL_5;
      case 4: /*0x121871*/
        if ( (v5[76] & 2) != 0 ) /*0x1218fc*/
          goto LABEL_26; /*0x1218fc*/
        raw_connaddr((int)v5, a4); /*0x121900*/
        soisconnected(a1); /*0x121909*/
        break; /*0x121911*/
      case 6: /*0x121871*/
        if ( (v5[76] & 2) == 0 ) /*0x121940*/
          goto LABEL_29; /*0x121940*/
        raw_disconnect(*(_DWORD *)(a1 + 8)); /*0x121943*/
        soisdisconnected(a1); /*0x12194c*/
        break; /*0x121954*/
      case 7: /*0x121871*/
        socantsendmore(a1); /*0x121960*/
        break; /*0x121965*/
      case 8: /*0x121871*/
      case 13: /*0x121871*/
        return 45;
      case 9: /*0x121871*/
        if ( a4 ) /*0x12196e*/
        {
          if ( (v5[76] & 2) != 0 ) /*0x121974*/
          {
LABEL_26:
            v6 = 56; /*0x121976*/
            break; /*0x12197b*/
          }
          raw_connaddr((int)v5, a4); /*0x121982*/
        }
        else if ( (v5[76] & 2) == 0 ) /*0x121990*/
        {
LABEL_29:
          v6 = 57; /*0x121992*/
          break; /*0x121997*/
        }
        v6 = (*(int (__cdecl **)(int, int))(*(_DWORD *)(a1 + 12) + 16))(a3, a1); /*0x1219ac*/
        a3 = 0; /*0x1219ae*/
        if ( a4 ) /*0x1219ba*/
          v5[76] &= ~2u; /*0x1219bc*/
        break; /*0x1219c0*/
      case 10: /*0x121871*/
        raw_disconnect(*(_DWORD *)(a1 + 8)); /*0x1219c5*/
        sofree(a1); /*0x1219ce*/
        soisdisconnected(a1); /*0x1219d7*/
        break; /*0x1219df*/
      case 12: /*0x121871*/
        return 0; /*0x1219e6*/
      case 15: /*0x121871*/
        bcopy(v5 + 28, (void *)(*(_DWORD *)(a4 + 4) + a4), 0x10u); /*0x1219f3*/
        goto LABEL_36; /*0x1219f3*/
      case 16: /*0x121871*/
        bcopy(v5 + 12, (void *)(*(_DWORD *)(a4 + 4) + a4), 0x10u); /*0x121a04*/
LABEL_36:
        *(_WORD *)(a4 + 8) = 16; /*0x121a09*/
        break; /*0x121a12*/
      default:
        panic(aRawUsrreq); /*0x121a19*/
        return result; /*0x121a19*/
    }
  }
  if ( a3 ) /*0x121a25*/
    m_freem(a3); /*0x121a2b*/
  return v6; /*0x121a35*/
}
