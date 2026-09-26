/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a9fc. */
int __cdecl tcp_timers(int a1, int a2)
{
  int v2; // ebx
  __int16 v4; // si
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // cx
  int v7; // edx
  unsigned __int16 v8; // cx
  __int16 v9; // si
  __int16 v10; // dx
  __int16 v12; // [esp+Ch] [ebp-4h]

  v2 = a1; /*0x12aa04*/
  if ( a2 == 1 ) /*0x12aa0d*/
  {
    ++dword_1EED9C; /*0x12ab68*/
    tcp_setpersist((_WORD *)a1); /*0x12ab6f*/
    *(_BYTE *)(a1 + 26) = 1; /*0x12ab74*/
    tcp_output(a1); /*0x12ab79*/
    *(_BYTE *)(a1 + 26) = 0; /*0x12ab7e*/
  }
  else if ( a2 > 1 ) /*0x12aa13*/
  {
    if ( a2 == 2 ) /*0x12aa23*/
    {
      ++dword_1EEDA0; /*0x12ab84*/
      v10 = *(_WORD *)(a1 + 8); /*0x12ab8a*/
      if ( v10 <= 3 ) /*0x12ab92*/
        goto LABEL_31; /*0x12ab92*/
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 32) + 28) + 2) & 8) == 0 || v10 > 5 ) /*0x12aba4*/
      {
        *(_WORD *)(a1 + 14) = tcp_keepidle; /*0x12abea*/
        return v2; /*0x12abee*/
      }
      if ( *(__int16 *)(a1 + 88) >= tcp_maxidle + tcp_keepidle ) /*0x12abb7*/
      {
LABEL_31:
        ++dword_1EEDA8; /*0x12abf0*/
        return tcp_drop(a1, 60); /*0x12abf0*/
      }
      ++dword_1EEDA4; /*0x12abb9*/
      tcp_respond(a1, *(char **)(a1 + 28), 0, *(_DWORD *)(a1 + 64), *(_DWORD *)(a1 + 36) - 1, 0); /*0x12abd1*/
      *(_WORD *)(a1 + 14) = tcp_keepintvl; /*0x12abdc*/
    }
    else if ( a2 == 3 ) /*0x12aa2c*/
    {
      if ( *(_WORD *)(a1 + 8) == 10 || tcp_maxidle < *(__int16 *)(a1 + 88) ) /*0x12aa43*/
        return tcp_close((_DWORD *)a1); /*0x12abfe*/
      *(_WORD *)(a1 + 16) = tcp_keepintvl; /*0x12aa4b*/
    }
  }
  else
  {
    if ( a2 ) /*0x12aa17*/
      return v2; /*0x12aa17*/
    v12 = *(_WORD *)(a1 + 18); /*0x12aa64*/
    *(_WORD *)(a1 + 18) = v12 + 1; /*0x12aa6a*/
    if ( (__int16)(v12 + 1) > 12 ) /*0x12aa78*/
    {
      *(_WORD *)(a1 + 18) = 12; /*0x12aa7a*/
      ++dword_1EED94; /*0x12aa80*/
      return tcp_drop(a1, 60); /*0x12abf9*/
    }
    ++dword_1EED98; /*0x12aa8c*/
    *(_WORD *)(a1 + 20) = tcp_backoff[2 * *(__int16 *)(a1 + 18)] * (*(_WORD *)(a1 + 98) + (*(__int16 *)(a1 + 96) >> 3)); /*0x12aaae*/
    v4 = *(_WORD *)(a1 + 20); /*0x12aab2*/
    v5 = *(_WORD *)(a1 + 100); /*0x12aab9*/
    if ( v4 >= (int)v5 ) /*0x12aac2*/
    {
      if ( v4 > 128 ) /*0x12aad1*/
        *(_WORD *)(a1 + 20) = 128; /*0x12aad3*/
    }
    else
    {
      *(_WORD *)(a1 + 20) = v5; /*0x12aac4*/
    }
    *(_WORD *)(a1 + 10) = *(_WORD *)(a1 + 20); /*0x12aadd*/
    if ( *(__int16 *)(a1 + 18) > 3 ) /*0x12aae6*/
    {
      in_losing(*(_DWORD *)(a1 + 32)); /*0x12aaec*/
      *(_WORD *)(a1 + 98) += *(__int16 *)(a1 + 96) >> 2; /*0x12aaf9*/
      *(_WORD *)(a1 + 96) = 0; /*0x12aafd*/
    }
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 36); /*0x12ab09*/
    *(_WORD *)(a1 + 90) = 0; /*0x12ab0c*/
    v6 = *(_WORD *)(a1 + 60); /*0x12ab12*/
    if ( v6 > *(_WORD *)(a1 + 84) ) /*0x12ab1d*/
      v6 = *(_WORD *)(a1 + 84); /*0x12ab1f*/
    v7 = v6 >> 1; /*0x12ab28*/
    v8 = *(_WORD *)(a1 + 24); /*0x12ab2b*/
    v9 = v7 / v8; /*0x12ab3b*/
    if ( (unsigned int)(v7 / v8) <= 1 ) /*0x12ab40*/
      v9 = 2; /*0x12ab42*/
    *(_WORD *)(a1 + 84) = v8; /*0x12ab47*/
    *(_WORD *)(a1 + 86) = v9 * *(_WORD *)(a1 + 24); /*0x12ab53*/
    *(_WORD *)(a1 + 22) = 0; /*0x12ab57*/
    tcp_output(a1); /*0x12ab5e*/
  }
  return v2; /*0x12ac05*/
}
